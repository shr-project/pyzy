#!/usr/bin/env python3
from pydict import *
from id import *
from valid_hanzi import *
import sys
from functools import cmp_to_key

def get_sheng_yun(pinyin):
    if pinyin == None:
        return None, None
    if pinyin == "ng":
        return "", "en"
    for i in range(2, 0, -1):
        t = pinyin[:i]
        if t in SHENGMU_DICT:
            return t, pinyin[len(t):]
    return "", pinyin

def read_phrases(filename):
    buf = open(filename, 'r+b').read()
    buf = str(buf, "utf16")
    buf = buf.strip()
    for l in buf.split('\n'):
        hanzi, freq, flag, pinyin = l.split(' ', 3)
        freq = float(freq)
        pinyin = pinyin.split()
        if any([c not in valid_hanzi for c in hanzi]):
            continue
        yield hanzi, freq, pinyin

def create_db(filename):
    # import sqlite3
    # con = sqlite3.connect("main.db")
    # con.execute ("PRAGMA synchronous = NORMAL;")
    # con.execute ("PRAGMA temp_store = MEMORY;")
    # con.execute ("PRAGMA default_cache_size = 5000;")
    print("PRAGMA synchronous = NORMAL;")
    print("PRAGMA temp_store = MEMORY;")
    print("PRAGMA default_cache_size = 5000;")


    sql = "CREATE TABLE py_phrase_%d (phrase TEXT, freq INTEGER, %s);"
    for i in range(0, 16):
        column = []
        for j in range(0, i + 1):
            column.append ("s%d INTEGER" % j)
            column.append ("y%d INTEGER" % j)
        print(sql % (i, ",".join(column)))
        # con.execute(sql % (i, column))
        # con.commit()

    records = list(read_phrases(filename))
    records.sort (key = cmp_to_key (lambda a, b: 1 if a[1] > b[1] else -1))
    records_new = []
    i = 0
    max_freq = 0.0
    for hanzi, freq, pinyin in records:
        if max_freq / freq <  1 - 0.001:
            max_freq = freq
            i = i + 1
        records_new.append((hanzi, i, pinyin))
    records_new.reverse()
    
    print("BEGIN;")
    insert_sql = "INSERT INTO py_phrase_%d VALUES (%s);"
    for hanzi, freq, pinyin in records_new:
        columns = []
        for py in pinyin:
            s, y = get_sheng_yun(py)
            s, y = pinyin_id[s], pinyin_id[y]
            columns.append(s)
            columns.append(y)
        values = "'%s', %d, %s" % (hanzi.encode("utf8"), freq, ",".join(map(str,columns)))
            
        sql = insert_sql % (len(hanzi) - 1, values)
        print(sql)
    print("COMMIT;")
    print("VACUUM;")

def main():
    create_db(sys.argv[1])
 
if __name__ == "__main__":
    main()
