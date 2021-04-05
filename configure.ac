
AC_INIT(octetos-cobani, 0.1.0-alpha, azael.devel@gmail.com)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CXX








LT_INIT



PKG_CHECK_MODULES(OCTETOS_CORE,octetos-core)

PKG_CHECK_MODULES(OCTETOS_MATH,octetos-math)

PKG_CHECK_MODULES(SDL,[sdl2 SDL2_ttf])

dnl PKG_CHECK_MODULES(OPENGL,opengl)


AC_OUTPUT([
Makefile
src/Makefile
])
