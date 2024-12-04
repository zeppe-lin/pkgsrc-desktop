ifeq (${WITH_GTK},3)
SRC = gpicview-gtk3.pod
else
SRC = gpicview-gtk2.pod
endif

all: gpicview.1

gpicview.1: ${SRC}
	pod2man -r "gpicview ${VERSION}" -c "" -n gpicview -s 1 $< > $@

install: all
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	cp -f gpicview.1 ${DESTDIR}${MANPREFIX}/man1/

clean:
	rm gpicview.1
