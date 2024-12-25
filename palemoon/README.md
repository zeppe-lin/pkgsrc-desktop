README palemoon

---


RUN AS DIFFERENT USER
=====================

Add a new user and change its default gtk theme if needed:

```sh
sudo useradd -G video,audio -U -m palemoon
xhost +SI:localuser:palemoon
sudo -u palemoon -H lxappearance
```

Use this wrapper as palemoon launcher:

```sh
#!/bin/sh
xhost +SI:localuser:palemoon
sudo -u palemoon -H /usr/bin/palemoon --new-tab "$@"
```

To run this wrapper without asking the password, add

```
user ALL=(palemoon) NOPASSWD: /usr/bin/palemoon *
```

into `/etc/sudoers.d/99_palemoon`.


---

End of file.
