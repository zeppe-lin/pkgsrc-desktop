#!/usr/bin/env perl
# genratpoison-re.pl -- generate ratpoison repl

use strict;
use warnings;

#my $ACTIONS_C = "../src/actions.c";
my $ACTIONS_C = $ARGV[0];

my @commands = ();
my %settings = ();

my $fh;
open ($fh, "$ACTIONS_C")
    or die "$0: can't open actions.c file: $!\n";

while (<$fh>) {
    if (m!/\*\@begin vars !) {
        while (<$fh>) {
            last if m!/\*\@end vars !;

            if (/\s*add_set_var\s*\(\"([^\"]+)\",\s*[^\"]+,\s*([0-9]+),\s*.*?\);$/) {
                my ($name, $numargs) = ($1, $2);

                $settings{$name}++;
            }
        }
    }
    elsif (m!/\*\@begin \(tag.*! || m!\*\@begin commands !) {
        while (<$fh>) {
            last if m!/\*\@end !;

            if (/\s*add_command\s*\(\"([^\"]+)\",\s*[^\"]+,\s*([0-9]+),\s*[0-9]+,\s*([0-9]+)/) {
                my ($name, $numargs, $optargs) = ($1, $2, $3);

                # skip the arguments
                <$fh> for 0 .. $numargs - 1;

                push @commands, $name;
            }
        }
    }
}

while (my $line = <DATA>) {
    if ($line =~ m/^our \@COMMANDS = \(\);$/) {
        print 'our @COMMANDS = qw(' . "\n";
        print "    $_\n" for @commands;
        print ");\n";
    }
    elsif ($line =~ m/^our %VARIABLE = \(\);$/) {
        print 'our %VARIABLE = (' . "\n";
        print "    $_ => 1,\n" for keys %settings;
        print ");\n";
    }
    else {
        print "$line";
    }
}

__DATA__
#!/usr/bin/env perl
# ratpoison repl
# based on Magnus Woldrich's sdorfehsctrl
# distributed under the same Perl license

package Ratpoison::REPL;

use strict;
use warnings;
#use autodie qw(:all);
use utf8;
use open qw(:std :utf8);
use IPC::Cmd qw(run);
use Term::ReadLine;
use Term::ANSIColor qw(:constants);
use Carp;

our $VERSION   = '0.1';
our $RATPOISON = $ENV{RATPOISON} // 'ratpoison';

###
our @COMMANDS = ();
our %VARIABLE = ();
###

sub new {
    my ($class, %args) = @_;
    my $self = bless({}, $class);

    # default values
    $self->{keymap} = $args{keymap} // '';
    $self->{prompt} = $args{prompt} // BOLD GREEN.'ratpoison-re.pl'.RESET.'> ';

    # sanity check
    croak "Invalid keymap argument '$self->{keymap}': must be vi or emacs\n"
        if $self->{keymap} && $self->{keymap} !~ /^(?:vi|emacs)$/;

    my $term = Term::ReadLine->new('ratpoison-re.pl');

    my $attr = $term->Attribs;
    $attr->{completion_function} = sub {
        my ($word, $buffer, $start) = @_;

        #return split(/\n/, process_command('windows %t'))
        #    if $buffer =~ m/^windows\b/;

        return keys %VARIABLE
            if $buffer =~ m/^set\b/;

        return @COMMANDS;
    };

    $attr->{autolist} = 0;
    $attr->{maxcomplete} = 0;

    $term->set_keymap($self->{keymap}) if $self->{keymap};
    $term->ding;

    $self->{term} = $term;

    return $self;
}

sub run_forever {
    my $self   = shift;

    my $term   = $self->{term};
    my $prompt = $self->{prompt};

    while (1) {
        my $line = $term->readline($prompt);
        next unless defined $line;

        print process_command($line);
        $term->addhistory($line) if $line =~ /\S/;
    }
}

sub process_command {
    my $command = join ' ', @_;

    # command or variable?
    $command = exists $VARIABLE{$command} ? "set $command" : $command;

    my $buffer;
    eval {
        scalar run(
            command => "$RATPOISON -c '$command'",
            verbose => $ENV{DEBUG} || 0,
            buffer  => \$buffer,
            # XXX make timeout configurable?
            timeout => 20,
        );
    };
    return $@ ? '' : $buffer ? $buffer : '';
}

######################################################################

package main;

use File::Basename;
use Getopt::Long qw(:config gnu_compat);

our $PROGRAM = basename $0;

sub print_version {
    print "$PROGRAM $VERSION\n";
}

sub print_help {
    print <<EOF;
Usage: $PROGRAM [-e emacs|vi] [-p prompt]
       $PROGRAM [-hv]
REPL shell for ratpoison with tabcompletion for commands and settings.

Mandatory arguments to long options are mandatory for short options too.
  -e, --edit=mode      use vi/emacs-style command line editing interface
  -p, --prompt=string  use string as an interactive prompt
  -v, --version        print version and exit
  -h, --help           print help and exit
EOF
}

sub main {
    GetOptions(
        "e|edit=s"   => \my $opt_editmode,
        "p|prompt=s" => \my $opt_prompt,
        "v|version"  => \my $opt_version,
        "h|help"     => \my $opt_help,
        ) or die "$PROGRAM: error in command line arguments\n";

    print_version() and exit if $opt_version;
    print_help()    and exit if $opt_help;

    my $repl = Ratpoison::REPL->new(
        keymap => $opt_editmode,
        prompt => $opt_prompt,
    );
    $repl->run_forever();
}

main() if not caller();
1;

=pod

=head1 NAME

ratpoison-re.pl - repl shell for ratpoison

=head1 SYNOPSIS

=over

=item B<ratpoison-re.pl> [-e emacs|vi] [-p prompt]

=item B<ratpoison-re.pl> [-hv]

=back

=head1 DESCRIPTION

B<ratpoison-re.pl> is a REPL shell for L<ratpoison(1)> with
tabcompletion for commands and settings.

=head1 OPTIONS

Mandatory arguments to long options are mandatory for short options too.

=over 8

=item B<-e>, B<--edit>=I<mode>

Set L<readline(3)> editing mode.
Available arguments are: I<emacs> and I<vi>.

=item B<-p>, B<--prompt>=I<string>

Set an interactive prompt.

=item B<-v>, B<--version>

Print version and exit.

=item B<-h>, B<--help>

Print help and exit.

=back

=head1 ENVIRONMENT

The following environment variables affect the execution of
B<ratpoison-re.pl>:

=over 8

=item RATPOISON

Specify if you installed ratpoison in a non-standard path.

=back

=head1 AUTHORS

Based on B<sdorfehsctrl> of Magnus Woldrich <L<< m@japh.se >>>.
Reworked for L<ratpoison> by Alexandr Savca <L<< alexandr.savca89@gmail.com >>.

=head1 LICENSE

This program is free software; you may redistribute and/or modify it
under the same terms as Perl itself.

=cut

# End of file.
