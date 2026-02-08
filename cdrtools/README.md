README for cdrtools

---

REQUIREMENTS
============

Kernel Configuration
--------------------

Ensure the kernel supports the filesystems necessary for reading and
writing ISO disks:

```
File systems  --->
  CD-ROM/DVD Filesystems  --->
    <*> ISO 9660 CDROM file system support
    [*]   Microsoft Joliet CDROM extensions
    [*]   Transparent decompression extension
    <*> UDF file system support
```

Kernel Module
-------------

`cdrecord` may require SCSI support for SATA DVD-RW drives.

Load manually:

```sh
# as root
/sbin/modprobe sg
```

Load automatically at boot:

- Declarative: add `sg` to `/etc/modules-load.d/sg.conf`
- Imperative: add `/sbin/modprobe sg` to `/etc/rc.modules`

---

End of file.
