README for gtk-theme-gruvbox

---

NOTES
=====

Qt5ct Configuration: Gruvbox Scrollbars
---------------------------------------

This package installs a custom Qt5ct stylesheet tweak to match GTK
Gruvbox scrollbar styling.

**Installation Path**: `/usr/share/qt5ct/qss/scrollbar-gruvbox.qss`

**Method 1: Enable via GUI**

1. Open **Qt5 Configuration Tool** (`qt5ct`).
2. Navigate to the **Style Sheets** tab.
3. Check the box next to `scrollbar-gruvbox.qss`.
4. Click **Apply**, then **OK**.

**Method 2: Enable via Configuration File**

To enable headlessly or via automation, update
`~/.config/qt5ct/qt5ct.ini` directly under the `[Interface]` section:

```ini
[Interface]
stylesheets=/usr/share/qt5ct/qss/scrollbar-gruvbox.qss
```

**Note:** If multiple stylesheets are active, append the path
separated by a comma:

```ini
stylesheets=/path/to/first.qss, /usr/share/qt5ct/qss/scrollbar-gruvbox.qss
```

Ensure `QT_QPA_PLATFORMTHEME=qt5ct` is exported in your environment
profile.

---

End of file.
