

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = octetos_cobani

octetos_cobani_SOURCES = main.cc contexts.cc core.cc

octetos_cobani_LDFLAGS = 

octetos_cobani_LDADD = 

octetos_cobani_LDADD = $(SDL_LIBS) $(OCTETOS_CORE_LIBS)

octetos_cobani_CXXFLAGS = $(SDL_CFLAGS) $(OCTETOS_CFLAGS) -DCOBANI_DEBUG -DLINUX_DEBIAN

