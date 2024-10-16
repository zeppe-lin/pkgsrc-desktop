README qemu


KVM
===

If you don't have kvm compiled into the kernel, make sure you have the kernel
module loaded before running kvm.  The easiest way to ensure that the kernel
module is loaded is to load it on boot.  For AMD CPUs the module is called
'kvm-amd'.  For Intel CPUs the module is called 'kvm-intel'.  Please review
/etc/rc.modules for how to load these.

Make sure your user is in the 'kvm' group.  Just run the following command and
re-login:

	sudo usermod -aG kvm <USER>

For brand new installs, the default permissions on /dev/kvm might not let you
access it.  You can tell udev to reset ownership/perms:

	sudo udevadm trigger -c add /dev/kvm


SHARE THE DIRECTORY
===================

To share /mnt directory (for example), execute qemu with the following
options:

	-virtfs local,path=/mnt,mount_tag=host0,security_model=none,id=host0

where /mnt is your host mountpoint.

On quest machine add the following line to /etc/fstab:

	host0 /mnt 9p trans=virtio,access=any,version=9p2000.L 0 0

NOTE! Your current host's uid:gid on quest may be different.


USB PASSTHROUGH
===============

Execute qemu with the following options:

	-device usb-ehci,id=ehci \
	-device usb-host,bus=ehci.0,hostbus=1,hostaddr=18

where hostbus and hostaddr is your device's corresponding values.  To obtain
them use lsusb(8).


CLIPBOARD SUPPORT
=================

To enable clipboard support between host and guest, firstly install
qemu-vdagent on guest operating system:

	sudo apt install qemu-vdagent

Next, start qemu with the following options:

	qemu-system-x86_64 [ ... ] \
	-chardev qemu-vdagent,id=ch1,name=vdagent,clipboard=on \
	-device virtio-serial-pci \
	-device virtserialport,chardev=ch1,id=ch1,name=com.redhat.spice.0


End of file.
