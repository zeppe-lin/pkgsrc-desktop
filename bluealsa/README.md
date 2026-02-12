README for bluealsa

---

CONFIGURATION
=============

`bluealsa` installs a D-Bus policy file at
`/usr/share/dbus-1/system.d/bluealsa.conf`.

By default, only root can own the service, and only members of the
`audio` group can exchange messages with it.

To run BlueAlsa as a regular user, ensure your account is in the
`audio` group:

```sh
# as root
useradd -aG audio <username>

# as regular user
newgrp audio
```

Reload udev and D-Bus rules if needed:

```sh
# as root
/etc/rc.d/udevd reload
/etc/rc.d/dbus restart
```

---

FURTHER READING
===============

- Wiki: <https://github.com/arkq/bluez-alsa/wiki/>

---

End of file.
