# vim:set noet ts=4:
#
# libpyzy - The Chinese PinYin and Bopomofo conversion library.
#
# Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
#
# This library is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation; either version 2.1 of the
# License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA

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
# 

libpyzy=libpyzy-1.0.la

libpyzyincludedir = $(includedir)/pyzy-@PYZY_API_VERSION@
libpyzyinclude_HEADERS = \
	PyZyConst.h \
	PyZyInputContext.h \
	PyZyVariant.h \
	$(NULL)

lib_LTLIBRARIES = $(libpyzy)

libpyzy_built_c_sources = \
	$(NULL)
libpyzy_built_h_sources = \
	PyZyBopomofoKeyboard.h \
	PyZyPinyinParserTable.h \
	PyZySimpTradConverterTable.h \
	$(NULL)
libpyzy_c_sources = \
	PyZyBopomofoContext.cc \
	PyZyDatabase.cc \
	PyZyDoublePinyinContext.cc \
	PyZyDynamicSpecialPhrase.cc \
	PyZyFullPinyinContext.cc \
	PyZyInputContext.cc \
	PyZyPhoneticContext.cc \
	PyZyPhraseEditor.cc \
	PyZyPinyinContext.cc \
	PyZyPinyinParser.cc \
	PyZySimpTradConverter.cc \
	PyZySpecialPhraseTable.cc \
	PyZyVariant.cc \
	$(NULL)
#	PyZyTest.cc 
libpyzy_h_sources = \
	PyZyBopomofo.h \
	PyZyBopomofoContext.h \
	PyZyConfig.h \
	PyZyConst.h \
	PyZyDatabase.h \
	PyZyDoublePinyinContext.h \
	PyZyDoublePinyinTable.h \
	PyZyDynamicSpecialPhrase.h \
	PyZyFullPinyinContext.h \
	PyZyInputContext.h \
	PyZyPhoneticContext.h \
	PyZyPhrase.h \
	PyZyPhraseArray.h \
	PyZyPhraseEditor.h \
	PyZyPinyinArray.h \
	PyZyPinyinContext.h \
	PyZyPinyinParser.h \
	PyZySimpTradConverter.h \
	PyZySpecialPhrase.h \
	PyZySpecialPhraseTable.h \
	PyZyString.h \
	PyZyTypes.h \
	PyZyUtil.h \
	PyZyVariant.h \
	$(NULL)

libpyzy_1_0_la_SOURCES = \
	$(libpyzy_c_sources) \
	$(libpyzy_h_sources) \
	$(libpyzy_built_c_sources) \
	$(libpyzy_built_h_sources) \
	$(NULL)

libpyzy_1_0_la_LDFLAGS = \
	-no-undefined \
	-version-info @LT_VERSION_INFO@ \
	$(NULL)

libpyzy_1_0_la_CXXFLAGS = \
	@GLIB2_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	@OPENCC_CFLAGS@ \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	$(NULL)

if HAVE_BOOST
libpyzy_1_0_la_CXXFLAGS += \
	@BOOST_CPPFLAGS@ \
	$(NULL)
else
libpyzy_1_0_la_CXXFLAGS += \
	-std=c++0x \
	$(NULL)
endif

libpyzy_1_0_la_LIBADD = \
	@GLIB2_LIBS@ \
	@SQLITE_LIBS@ \
	@OPENCC_LIBS@ \
	$(NULL)
#	-lgtest

if HAVE_LIBUUID
libpyzy_1_0_la_CXXFLAGS += $(LIBUUID_CFLAGS)
libpyzy_1_0_la_LIBADD += $(LIBUUID_LIBS)
endif

BUILT_SOURCES = \
	$(libpyzy_built_c_sources) \
	$(libpyzy_built_h_sources) \
	$(NULL)

pkgdata_DATA = \
	phrases.txt \
	$(NULL)

EXTRA_DIST = \
	phrases.txt \
	$(NULL)

CLEANFILES = \
	ZhConversion.* \
	$(NULL)

PyZyBopomofoKeyboard.h:
	$(AM_V_GEN) \
	$(PYTHON) $(top_srcdir)/scripts/genbopomofokeyboard.py > $@ || \
		( $(RM) $@; exit 1 )

PyZyPinyinParserTable.h:
	$(AM_V_GEN) \
	$(PYTHON) $(top_srcdir)/scripts/genpytable.py > $@ || \
		( $(RM) $@; exit 1 )

PyZySimpTradConverterTable.h:
	$(AM_V_GEN) \
	$(PYTHON) $(top_srcdir)/scripts/update-simptrad-table.py > $@ || \
		( $(RM) $@; exit 1 )

update-simptrad-table:
	$(RM) ZhConversion.php ZhConversion.py PyZySimpTradConverterTable.h
	$(MAKE) ZhConversion.php
	$(MAKE) ZhConversion.py
	$(MAKE) PyZySimpTradConverterTable.h

ZhConversion.php:
	$(AM_V_GEN) \
	svn cat http://svn.wikimedia.org/svnroot/mediawiki/trunk/phase3/includes/ZhConversion.php > $@ || \
		( $(RM) $@; exit 1 )

ZhConversion.py: ZhConversion.php
	$(AM_V_GEN) \
	php $(top_srcdir)/scripts/php_2_py.php > $@ || \
		( $(RM) $@; exit 1 )

