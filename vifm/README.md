README for vifm

---

MIME TYPES
==========

To register `vifm` as default application for opening folders, run:

```sh
gio mime inode/directory vifm.desktop
```

---

FUSE FILESYSTEMS
================

SSHFS
-----

1. Install `sshfs-fuse` package.

2. Register an extension that will be used for connections over SSH.
   The format is:

   ```
   :filetype extensions
    \ FUSE_MOUNT|some_mount_command using %PARAM and %DESTINATION_DIR
   ```

   A sample line in `~/.vifm/vifmrc` might look like this:

   ```
   :filetype *.ssh FUSE_MOUNT2|sshfs %PARAM %DESTINATION_DIR
   ```

   `%PARAM` and `%DESTINATION_DIR` are filled in by Vifm at runtime.

   `%PARAM` value is filled from the first line of file (whole line).

   You can also add `%CLEAR` to clear screen before running FUSE
   program.

3. Create a file with ssh extension that contains connection
   parameters in the 1st line.  A sample 1st line could be:

   ```
   user@127.0.0.1:/
   ```

MTPFS
-----

1. Install `android-file-transfer` package.

2. Register an extension that will be used for connections over MTPFS.
   A sample line in `~/.vifm/vifmrc` might look like this:

   ```
   :filetype *.mtp FUSE_MOUNT2|aft-mtp-mount -D %PARAM %DESTINATION_DIR
   ```

3. Get your MTP device ID via `lsusb(8)`:

   ```sh
   lsusb
   ```

4. Create a file with mtp extension that contains connection
   parameters in the 1st line.  A sample 1st line could be:

   ```
   22d9:2764
   ```

---

End of file.
