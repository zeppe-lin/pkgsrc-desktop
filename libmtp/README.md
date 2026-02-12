README for libmtp

---

POST-INSTALL
============

`libmtp` installs `/etc/udev/rules.d/69-libmtp.rules`.
Reload udev rules after installation:

```sh
# as root
udevadm control --reload-rules # or
/etc/rc.d/udevd reload
```

---

NOTES
=====

Run MTP as a Regular User
-------------------------

1. Create the `plugdev` group and add your user:

```sh
# as root
getent group plugdev >/dev/null || groupadd -r plugdev
usermod -aG plugdev <username>

# as user
newgrp plugdev
```

2. Find your device's `VendorId:ProductId` with `lsusb`.

3. Add a rule to `/etc/udev/rules.d/70-libmtp.rules`:

```sh
# one line
SUBSYSTEM=="usb", ATTR{idVendor}=="...", ATTR{idProduct}=="...", \
  MODE="0666", GROUP="plugdev"
```

4. Reload udev rules, as described in **POST-INSTALL**.

---

End of file.
