README trinity-extra-theme

---


CONFIGURATION
=============

dircolors
---------

```sh
cp /usr/share/trinity/dircolors ~/.dircolors
```
also, add the following lines to your .bashrc:

```sh
if [ -r ~/.dircolors ]; then
    eval "$(dircolors -b ~/.dircolors)"
else
    eval "$(dircolors -b)"
fi
alias ls='ls --color=auto'
```

dunst
-----

```sh
mkdir -p ~/.config/dunst
cp /usr/share/trinity/dunst ~/.config/dunst/dunstrc
killall dunst
```

gitk
----

```sh
mkdir -p ~/.config/git
cp /usr/share/trinity/gitk ~/.config/git/gitk
```

... and restart gitk.

hexchat
-------

```sh
mkdir -p ~/.config/hexchat
cp /usr/share/trinity/hexchat ~/.config/hexchat/colors.conf
```

... and restart hexchat.

vifm
----

```sh
mkdir -p ~/.vifm/colors
cp /usr/share/trinity/vifm ~/.vifm/colors/trinity.vifm
```

... and add ":colorscheme trinity" to ~/.vifm/vifmrc

vim
---

```sh
mkdir -p ~/.vim/colors
cp /usr/share/trinity/vim ~/.vim/colors/trinity.vim
```

... and add ":colorscheme trinity" to ~/.vimrc

xresources
----------

Add the following line to ~/Xresources:

```
#include "/usr/share/trinity/xresources"
```

... and add the following line to ~/.xinitrc for persistent setting:

```sh
[ -f ~/.Xresources ] && xrdb -merge ~/.Xresources
```

zathura
-------

```sh
cp /usr/share/trinity/zathurarc ~/.config/zathura/zathurarc
```

---

End of file.
