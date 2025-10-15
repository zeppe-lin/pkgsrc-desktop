README bluez

---


KERNEL CONFIGURATION
====================

For Mesh
--------

The `linux` package ships with all required cryptographic options
enabled for Bluetooth Mesh support.

If you're building a custom kernel and Mesh cryptography fails, ensure
the following options are enabled in your `.config`:

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


---

End of file.
