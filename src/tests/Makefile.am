# vim:set noet ts=4:
#
# ibus-pinyin - The Chinese PinYin engine for IBus
#
# Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

# @MAINTAINER_MODE_FALSE@skip_gentable=test -f $@ ||

# AM_CFLAGS = \
# 	@IBUS_CFLAGS@ \
# 	@SQLITE_CFLAGS@ \
# 	-DPKGDATADIR=\"$(pkgdatadir)\" \
# 	$(NULL)
# AM_CXXFLAGS = $(AM_CFLAGS)
# AM_LDADD = \
# 	@IBUS_LIBS@ \
# 	@SQLITE_LIBS@ \
# 	$(NULL)

DEPS = $(top_builddir)/src/libpyzy-@PYZY_API_VERSION@.la

INCLUDES =                  \
        -g                  \
        @GLIB2_CFLAGS@      \
        @SQLITE_CFLAGS@     \
        @OPENCC_CFLAGS@     \
        -I$(top_srcdir)/src \
        $(NULL)

prog_ldadd =                \
        @GLIB2_LIBS@        \
        @SQLITE_LIBS@       \
        @OPENCC_LIBS@       \
        $(top_builddir)/src/libpyzy-@PYZY_API_VERSION@.la       \
        $(NULL)

noinst_PROGRAMS = $(TESTS)
TESTS =                   \
        basic             \
        $(NULL)

basic_SOURCES = basic.cc
basic_LDADD = $(prog_ldadd)
