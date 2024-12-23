README bluez

---


KERNEL CONFIGURATION (for Mesh)
===============================

The Mesh daemon uses kernel provided crypto utilities to perform security
functions required of Bluetooth Mesh. Many standard distributions currently
enable all required crypto features, but a few notable distributions do not.

If Mesh Cryptography is not working, the following configuration options may
need to be enabled, and the kernel rebuilt.

1. A minimum of kernel version 4.9 or later is required.

2. The kernel must at a minimum have the following .config options turned on:

    CONFIG_CRYPTO_USER
    CONFIG_CRYPTO_USER_API
    CONFIG_CRYPTO_USER_API_AEAD
    CONFIG_CRYPTO_USER_API_HASH
    CONFIG_CRYPTO_USER_API_SKCIPHER
    CONFIG_CRYPTO_AES
    CONFIG_CRYPTO_CCM
    CONFIG_CRYPTO_AEAD
    CONFIG_CRYPTO_CMAC


---

End of file.
