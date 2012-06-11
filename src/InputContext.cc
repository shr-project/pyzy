/* vim:set et ts=4 sts=4:
 *
 * libpyzy - The Chinese PinYin and Bopomofo conversion library.
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of the
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */
#include "PhoneticContext.h"

#include <glib.h>
#include <string>

#include "BopomofoContext.h"
#include "Database.h"
#include "DoublePinyinContext.h"
#include "FullPinyinContext.h"

namespace PyZy {

void
InputContext::init ()
{
    const std::string cache_dir =
        g_build_filename (g_get_user_cache_dir (), "pyzy", NULL);
    const std::string config_dir =
        g_build_filename (g_get_user_config_dir (), "pyzy", NULL);
    init (cache_dir, config_dir);
}
void
InputContext::init (const std::string & user_cache_dir,
                    const std::string & user_config_dir)
{
    if (user_cache_dir.empty ()) {
        g_error ("Error: user_cache_dir should not be empty");
    }
    if (user_config_dir.empty ()) {
        g_error ("Error: user_config_dir should not be empty");
    }

    Database::init (user_cache_dir);
    SpecialPhraseTable::init (user_config_dir);
}

void
InputContext::finalize ()
{
    Database::finalize ();
}

InputContext *
InputContext::create (InputContext::InputType type,
                      InputContext::Observer * observer) {
    switch (type) {
    case FULL_PINYIN:
        return new FullPinyinContext (observer);
    case DOUBLE_PINYIN:
        return new DoublePinyinContext (observer);
    case BOPOMOFO:
        return new BopomofoContext (observer);
    default:
        g_warning ("unknown context type.\n");
        return NULL;
    }
}

}  // namespace PyZy
