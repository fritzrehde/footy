SHELL = /bin/sh
INSTALL_PROGRAM = /usr/bin/install
prefix = /usr/local

# ifdef check allows the user to pass custom dirs as per the README
# The directory to install footy in.
ifdef INSTALL_DIR
	bindir = $(INSTALL_DIR)
else
	bindir = $(prefix)/bin
endif

install: installdirs
	$(INSTALL_PROGRAM) footy $(DESTDIR)$(bindir)/footy

uninstall:
	rm -f $(DESTDIR)$(bindir)/footy

installdirs:
	mkdir -p $(DESTDIR)$(bindir)
