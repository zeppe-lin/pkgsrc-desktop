README password-store-otp

---


NOTES
=====

Time Sync
---------

Time-based OTPs rely on the system clock.  Ensure your host's time is accurate,
or OTP validation will fail.  You can synchronize your clock using `chrony`:

    sudo pkgman install --deps --group chrony
    sudo /etc/rc.d/chronyd start


---

End of file.
