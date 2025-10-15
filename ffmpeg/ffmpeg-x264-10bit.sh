#!/bin/sh
exec env LD_LIBRARY_PATH=/usr/lib/libx264-10bit ffmpeg "$@"
