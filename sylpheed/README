README sylpheed


TRINITY ICONS
=============

To enable Trinity-like icons, add PKGMK_SYLPHEED="+TRINITY+" to your
/etc/pkgmk.conf.


URGENT WINDOW NOTIFY (requires xdotool)
=======================================

Since the notifications in the Sylpheed are pretty ugly, and the current build
is not patched for libnotify support, Tile-WM-Users can use the standard tag
notifications:

	Configuration
	`-- Common preferences
	    `-- [v] Execute command when new messages arrive

		xdotool search --name "Sylpheed 3.7.0" set_window --urgency 1

See xdotool(1) or wmctrl(1).


End of file.
