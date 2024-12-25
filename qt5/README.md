README qt5

---


POST-INSTALL
============

After updating qt5 you may get the following error when launching qt5
applications:

    "Can't mix incompatible Qt library (5.15.x) with this library (5.15.y)"

Just rebuild `qt5-styleplugins`.


THEME CUSTOMIZATION
===================

Qt5 can be forced to follow the theme of GTK-3.0.  Add the following line to
your profile:

```sh
export QT_QPA_PLATFORMTHEME=gtk3
```

You may also wish to set the widget style:

```sh
export QT_STYLE_OVERRIDE=windows
```


---

End of file.
