SUBDIRS = 	en es el local pt zh de
DIST_SUBDIRS = 	en es el local pt zh de
XCASHTML = xcasfr.html xcasen.html *.css *.js logo.png giac.tex giacfr.tex test.tex testfr.tex test.html testfr.html algolycee.html graphtheory-user_manual.pdf *.sty simple.html *tableau* magnets html2canvas.js jspdf.umd.min.js khicasnw.html epsilon.dfu apps.tar recovery nws*.html nws.js numworks.js shakeys
EXTRA_DIST = aide_cas README index.html $(XCASHTML) dxcas/* castex.tex tortue.tex 50-numworks-calculator.rules  # private nwscert.cc -> shakeys

dist_pkgdata_DATA = aide_cas
dist_doc_DATA = README index.html


install-exec-hook: testfr.html algoseconde.html
	$(install_sh) -d $(DESTDIR)$(prefix)/share/giac/doc/dxcas
	for dd in $(XCASHTML); do \
	  $(INSTALL_DATA) $(top_srcdir)/doc/$$dd $(DESTDIR)$(prefix)/share/giac/doc/ ; \
	done
	$(INSTALL_DATA) $(top_srcdir)/doc/dxcas/* $(DESTDIR)$(prefix)/share/giac/doc/dxcas
	$(INSTALL_DATA) $(top_srcdir)/doc/index.html $(DESTDIR)$(prefix)/share/giac/doc/
	$(INSTALL_DATA) $(top_srcdir)/doc/README $(DESTDIR)$(prefix)/share/giac/doc/
	ln -sf ../aide_cas $(DESTDIR)$(prefix)/share/giac/doc/aide_cas
#	cp -f epsilon.dfu apps.tar recovery $(DESTDIR)$(prefix)/share/giac/doc/
	cp -f 50-numworks-calculator.rules $(DESTDIR)$(prefix)/share/giac/doc/
#	cp -f shakeys $(DESTDIR)$(prefix)/share/giac/doc/
#	ln -sf $(DESTDIR)$(prefix)/share/giac/doc/en/cascmd_en $(DESTDIR)$(prefix)/share/giac/doc/local/cascmd_local
#	ln -sf $(DESTDIR)$(prefix)/share/giac/doc/en/casinter $(DESTDIR)$(prefix)/share/giac/doc/local/casinter
#	ln -sf $(DESTDIR)$(prefix)/share/giac/doc/en/keywords $(DESTDIR)$(prefix)/share/giac/doc/local/keywords
#	ln -sf $(DESTDIR)$(prefix)/share/giac/doc/en/xcasex $(DESTDIR)$(prefix)/share/giac/doc/local/xcasex
#	ln -sf $(DESTDIR)$(prefix)/share/giac/doc/en/xcasmenu $(DESTDIR)$(prefix)/share/giac/doc/local/xcasmenu

testfr.html:
	hevea -fix testfr

algoseconde.html:
#	hevea -fix algoseconde
	echo '<p>Unfortunately, this file <a href="https://xcas.univ-grenoble-alpes.fr/forum/viewtopic.php?f=4&t=1813">cannot yet be built</a> in Debian. See <a href="https://www-fourier.ujf-grenoble.fr/~parisse/algoseconde.html">here</a> for an on-line version, though it may be for a newer version than what'\''s installed in this package.</p>' > "$@"
