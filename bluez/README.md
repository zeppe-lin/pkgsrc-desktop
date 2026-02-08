README for bluez

---

REQUIREMENTS
============

Kernel Configuration
--------------------

**Bluetooth Mesh** requires cryptographic options in the kernel.
If Mesh cryptography fails, ensure the following are enabled:

- **Minimum kernel version**:
  - 4.9 or later

- **Required options**:
  - `CONFIG_CRYPTO_USER`
  - `CONFIG_CRYPTO_USER_API`
  - `CONFIG_CRYPTO_USER_API_AEAD`
  - `CONFIG_CRYPTO_USER_API_HASH`
  - `CONFIG_CRYPTO_USER_API_SKCIPHER`
  - `CONFIG_CRYPTO_AES`
  - `CONFIG_CRYPTO_CCM`
  - `CONFIG_CRYPTO_AEAD`
  - `CONFIG_CRYPTO_CMAC`

Kernel Module
-------------

BlueZ uses the **btusb** kernel module for Bluetooth USB devices.

To ensure reliable initialization, especially after "warm boots"
(reboots from another OS) or system suspend, this package installs a
default configuration:

`/lib/modprobe.d/btusb.conf`

This file contains `options btusb reset=1`.  This forces the
controller to perform a full power cycle upon driver load, which is
necessary for many integrated chips to correctly load their firmware.
This resolves common initialization issues on hardware where adapters
may otherwise fail to appear or connect.

**Potential Side Effects:**
On specific USB controllers, this reset command may cause temporary
instability on the entire USB bus, potentially disconnecting other
devices (like mice or keyboards) for a fraction of a second during
boot.

**Administrator Override:**
If you experience USB bus resets or prefer a faster boot sequence
without hardware cycling, shadow this setting by creating:

`/etc/modprobe.d/btusb.conf`

Inside, set `options btusb reset=0` or leave it empty to use kernel
defaults.  Files in `/etc/modprobe.d/` strictly override those in
`/lib/modprobe.d/`.

---

End of file.
