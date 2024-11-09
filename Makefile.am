if BUILD_MICROPY
    MICROPY_DIR = micropython-1.12
endif
SUBDIRS =       $(MICROPY_DIR) src check intl po doc examples
## SUBDIRS = 	micropython-1.12 src check intl po doc examples
DIST_SUBDIRS = 	micropython-1.12 src check intl po doc examples
EXTRA_DIST = giac_fltk_changes fltk-1.3.8-source.tar.bz2 path.h.in setup inst TROUBLES Init.scm compte INSTALACION LEAME.WIN LEAME.ipaq giac.specs giac.specs32 fltk.1.1.changes README.MACOSX changeversion mkosx mkosx10 mkosx3  win2unix.cc addu.cc xcas*.nsi xcas.desktop xcas.metainfo.xml xcas.xpm xcas.applications README.visualcpp java.README win win64  LISEZMOI.numworks icons/* README.hevea2mml README.itex2MML

# Rule to build tar-bzipped distribution package
$(PACKAGE)-$(VERSION).tar.gz: dist

## FIXME: installing autoconf-generated config.h is just PLAIN WRONG.

install-exec-hook:
	cp config.h $(DESTDIR)$(includedir)/giac
	./mkinstalldirs $(DESTDIR)$(prefix)/share/
	./mkinstalldirs $(DESTDIR)$(prefix)/share/pixmaps
	cp xcas.xpm $(DESTDIR)$(prefix)/share/pixmaps/xcas.xpm
	./mkinstalldirs $(DESTDIR)$(prefix)/share/applications
	cp xcas.desktop $(DESTDIR)$(prefix)/share/applications/xcas.desktop
	./mkinstalldirs $(DESTDIR)$(prefix)/share/metainfo
	cp xcas.metainfo.xml $(DESTDIR)$(prefix)/share/metainfo/
	./mkinstalldirs $(DESTDIR)$(prefix)/share/application-registry
	cp xcas.applications $(DESTDIR)$(prefix)/share/application-registry/xcas.applications
	./mkinstalldirs $(DESTDIR)$(prefix)/share/icons/
	./mkinstalldirs $(DESTDIR)$(prefix)/share/icons/hicolor
	for SIZE in 256 128 64 32 16; do ./mkinstalldirs $(DESTDIR)$(prefix)/share/icons/hicolor/$${SIZE}x$${SIZE} && ./mkinstalldirs $(DESTDIR)$(prefix)/share/icons/hicolor/$${SIZE}x$${SIZE}/apps && cp icons/xcas_$${SIZE}.png $(DESTDIR)$(prefix)/share/icons/hicolor/$${SIZE}x$${SIZE}/apps/xcas.png; done
	for SIZE in 256 128 64 32 16; do ./mkinstalldirs $(DESTDIR)$(prefix)/share/icons/hicolor/$${SIZE}x$${SIZE}/mimetypes && cp icons/x-xcas_$${SIZE}.png $(DESTDIR)$(prefix)/share/icons/hicolor/$${SIZE}x$${SIZE}/mimetypes/application-x-xcas.png;  done

ACLOCAL_AMFLAGS = -I m4

