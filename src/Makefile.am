

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = cobani

cobani_SOURCES = main.cc contexts.cc core.cc
cobani_LDFLAGS = 
cobani_LDADD = 
cobani_LDADD = $(SDL_LIBS) $(OCTETOS_CORE_LIBS)
cobani_CXXFLAGS = $(SDL_CFLAGS) $(OCTETOS_CFLAGS) -DCOBANI_DEBUG -DLINUX_DEBIAN

