MAN1 = aft-mtp-cli.1 aft-mtp-mount.1 android-file-transfer.1

all: ${MAN1}

%: %.pod
	pod2man -r "android-file-transfer ${VERSION}" -c "" \
		-n $(basename $@) -s $(subst .,,$(suffix $@)) $< > $@

install: all
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	cp -f ${MAN1} ${DESTDIR}${MANPREFIX}/man1/

uninstall:
	cd ${DESTDIR}${MANPREFIX}/man1 && rm -f ${MAN1}

clean:
	rm -f ${MAN1}

.PHONY: all install uninstall clean
