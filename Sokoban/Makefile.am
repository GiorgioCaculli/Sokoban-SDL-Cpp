include $(top_srcdir)/common.mk

ACLOCAL_AMFLAGS = -I m4 --install

SUBDIRS = src

bin_PROGRAMS = sokoban

sokoban_SOURCES = src/main.cpp src/main.hpp

sokoban_CPPFLAGS = $(BOOST_CPPFLAGS)

sokoban_LDADD = src/core/libcore.a
sokoban_LDADD += $(SDL2_LIBS)
sokoban_LDADD += $(SDL2_GFX_LIBS)
sokoban_LDADD += $(SDL2_Image_LIBS)
sokoban_LDADD += $(SDL2_Mixer_LIBS)
sokoban_LDADD += $(SDL2_Net_LIBS)
sokoban_LDADD += $(SDL2_TTF_LIBS)
sokoban_LDADD += $(BOOST_LDFLAGS)
sokoban_LDADD += $(BOOST_DATE_TIME_LIB)
sokoban_LDADD += $(BOOST_FILESYSTEM_LIB)
sokoban_LDADD += $(BOOST_LOCALE_LIB)
sokoban_LDADD += $(BOOST_LOG_LIB)
sokoban_LDADD += $(BOOST_LOG_SETUP_LIB)
sokoban_LDADD += $(BOOST_SYSTEM_LIB)
sokoban_LDADD += $(BOOST_THREAD_LIB)
