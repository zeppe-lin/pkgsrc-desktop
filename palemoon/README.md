README for palemoon

---

NOTES
=====

Run as Different User
---------------------

1. Create a dedicated user and adjust its GTK theme if needed:

```sh
# as root
useradd -G video,audio -U -m palemoon

# as user
xhost +SI:localuser:palemoon
sudo -u palemoon -H lxappearance
```

2. Use this wrapper script as the launcher:

```sh
#!/bin/sh
xhost +SI:localuser:palemoon
sudo -u palemoon -H /usr/bin/palemoon --new-tab "$@"
```

3. To run the wrapper without password prompts, add to
   `/etc/sudoers.d/99_palemoon`:

```
user ALL=(palemoon) NOPASSWD: /usr/bin/palemoon *
```

---

End of file.
