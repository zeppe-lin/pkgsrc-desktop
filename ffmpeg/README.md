README ffmpeg

---


REQUIREMENTS
============

This package builds FFmpeg with support for a wide range of codecs,
formats, and hardware acceleration.  Feature selection is governed by
three sources:

Required dependencies
---------------------

Packages listed in the `Pkgfile` `Depends on:` field are installed
before build and always enabled.  These form the baseline feature set.

Optional features
-----------------

Additional packages are listed in `ffmpeg.enabled`.  If present at
build time, they are enabled via `--enable-*` flags.  Each entry
follows this format:

    description
    pkgname: --enable-flag(s)

Explicitly disabled features
----------------------------

Packages listed in `ffmpeg.disabled` are always disabled via
`--disable-*`, regardless of presence.  This avoids unwanted
dependencies or licensing issues.  Each entry follows the same format:

    description
    pkgname: --disable-flag(s)

To customize the build, edit `ffmpeg.enabled` and `ffmpeg.disabled`
directly.


CAUTION
=======

Enabling `fdk-aac` or `openssl` triggers `--enable-nonfree`, which
makes the resulting binary non-redistributable under GPL terms.  Use
with care if packaging for redistribution.


REFERENCES
==========

* https://ffmpeg.org/documentation.html
* https://trac.ffmpeg.org/wiki/CompilationGuide


---

End of file.
