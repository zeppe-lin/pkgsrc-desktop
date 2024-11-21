README sylpheed

---


TRINITY ICONS
=============

To enable trinity-like icons, add the following line to your `/etc/pkgmk.conf`:

    PKGMK_SYLPHEED="+trinityicons"


URGENT WINDOW NOTIFICATION
==========================
**Requires xdotool!**

Since the notifications in the Sylpheed are pretty ugly, and the current build
is not patched for `libnotify` support, the users of tiling window managers can
use the standard tag notifications:

    Configuration
    `-- Common preferences
        `-- [x] Execute command when new messages arrive:
            xdotool search --name "Sylpheed 3.7.0" set_window --urgency 1

See xdotool(1) or wmctrl(1).


---

End of file.
