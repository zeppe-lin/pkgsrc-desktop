README for libmtp

---

POST-INSTALL
============

`libmtp` installs `/lib/udev/rules.d/69-libmtp.rules`.
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

**1. Create the `plugdev` group and add your user:**

```sh
# as root
getent group plugdev >/dev/null || groupadd -r plugdev
usermod -aG plugdev <username>

# as user
newgrp plugdev
```

**2. Identify your device's IDs:**

Run `lsusb` to find `VendorId:ProductId` pair.

**3. Add a custom udev rule:**

System packages install rules into `/lib/udev/rules.d/`.
Local overrides and custom rules should go into
`/etc/udev/rules.d/`.
Create `/etc/udev/rules.d/70-mtp-local.rules` (or another
descriptive name) with:

```sh
# as one line
SUBSYSTEM=="usb", ATTR{idVendor}=="...", ATTR{idProduct}=="...", \
MODE="0666", GROUP="plugdev"
```

**Note:** Avoid naming your local file `libmtp.rules`, to prevent
confusion with the system-installed
`/lib/udev/rules.d/69-libmtp.rules`.  Use a distinct name like
`70-mtp-local.rules` or `99-mtp-overrides.rules`.

**4. Reload udev rules:**

Follow steps in **POST-INSTALL** to reload.

---

End of file.
