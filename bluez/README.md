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

---

End of file.
