README qt5

---


POST-INSTALL
============

After updating `qt5`, you might encounter this error when launching
applications:

`Can't mix incompatible Qt library (5.15.x) with this library (5.15.y)`

Rebuild `qt5-styleplugins` to resolve the issue.


THEME CUSTOMIZATION
===================

To make `qt5` follow the GTK-3.0 theme, add this to your profile:

    export QT_QPA_PLATFORMTHEME=gtk3

For widget styling, you can also set:

    export QT_STYLE_OVERRIDE=windows


---

End of file.
