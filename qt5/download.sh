#!/bin/sh -
# Download qt5 patch.
#
# Thanks to "Beyond Linux From Scratch":
# https://www.linuxfromscratch.org/blfs/view/svn/x/qt5.html

. ./Pkgfile
curl -LO https://www.linuxfromscratch.org/patches/blfs/svn/qt-everywhere-opensource-src-$version-kf5-1.patch

# End of file.
