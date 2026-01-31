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

`cdrecord` may require SCSI support for SATA DVD-RW drives:

```sh
# Generic SCSI support for SATA DVD-RW
sg
```

To auto-load, add the module name to a file such as:

```
/etc/modules-load.d/cdrtools.conf
```

This package does not install a default config, since requirements
vary by machine.

---

End of file.
