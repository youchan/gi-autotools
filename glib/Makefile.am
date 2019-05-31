CLEANFILES =

AM_CPPFLAGS =                                     \
         -I$(top_builddir)                        \
         -I$(top_srcdir)                          \
         $(GLIB_CFLAGS)

AM_CFLAGS = $(GLIB_CFLAGS)

lib_LTLIBRARIES = libhello.la

libhello_la_LIBADD = $(GLIB_LIBS)

libhello_la_SOURCES = hello.cpp hello.hpp

-include $(INTROSPECTION_MAKEFILE)

INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ARGS =
INTROSPECTION_COMPILER_ARGS =

if HAVE_INTROSPECTION
Hello-1.0.gir: libhello.la

Hello_1_0_gir_PACKAGES =
Hello_1_0_gir_EXPORT_PACKAGES = hello
Hello_1_0_gir_INCLUDES = GObject-2.0
Hello_1_0_gir_CFLAGS = $(AM_CPPFLAGS) $(AM_CFLAGS)
Hello_1_0_gir_LIBS = libhello.la ../src/libgreeting.la
Hello_1_0_gir_FILES = $(libhello_la_SOURCES)
Hello_1_0_gir_SCANNERFLAGS =                      \
        --identifier-prefix=Hello                 \
        --symbol-prefix=hello
INTROSPECTION_GIRS += Hello-1.0.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES +=                                      \
        $(gir_DATA)                                \
        $(typelib_DATA)
endif
