README for ffmpeg

---

REQUIREMENTS
============

Optional Packages
-----------------

Feature selection is controlled by three lists:

- **Required dependencies**
  Packages listed in the `Pkgfile` `Depends on:` field.  Always
  installed and enabled.  Baseline feature set.

- **Optional features**
  Packages listed in `ffmpeg.enabled`.  If present at build time, they
  are enabled via `--enable-*`.  Format:

  ```
  description
  pkgname: --enable-flag(s)
  ```

- **Disabled features**
  Packages listed in `ffmpeg.disabled`.  Always disabled via
  `--disable-*`, regardless of presence.  Format:

  ```
  description
  pkgname: --disable-flag(s)
  ```

To customize the build, edit `ffmpeg.enabled` and `ffmpeg.disabled`.

---

NOTES
=====

Enabling `fdk-aac` or `openssl` triggers `--enable-nonfree`, which
makes the resulting binary non-redistributable under GPL terms.
Use with care if packaging for redistribution.

---

FURTHER READING
===============

- https://ffmpeg.org/documentation.html
- https://trac.ffmpeg.org/wiki/CompilationGuide

---

End of file.
