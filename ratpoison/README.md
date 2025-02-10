README ratpoison

---


USE FLAGS
=========

Define `PKGMK_RATPOISON_USE` variable in `/etc/pkgmk.conf` with the following
flags to enable or disable the build-time features:

- [+-]debug:   build with extra debugging messages
- [+-]xft:     use Xft library (requires xorg-libxft)
- [+-]xkb:     build XKB support for keyboard input (requires xorg-xkb)
- [+-]xrandr:  build with Xrandr support
- [+-]history: link with libhistory (only used for ! expansion)

Example:

```sh
PKGMK_RATPOISON_USE="-debug +xft +xkb -xrandr +history"
```

The defaults are the same as in example above.


---

End of file.
