#!/usr/bin/env python3
import sys
sys.path.append(".")

from ZhConversion import *
from valid_hanzi import *

def convert(s, d, n):
    out = ""
    end = len(s)
    begin = 0
    while begin < end:
        for i in range(min(n, end - begin), 0, -1):
            t = s[begin:begin+i]
            t = d.get(t, t if i == 1 else None)
            if t:
                break
        out = out + t
        begin += i
    return out

def filter_more(records, n):
    han = [k_v1 for k_v1 in records if len(k_v1[0]) <= n]
    hand = dict(han)
    hanm = [k_v2 for k_v2 in records if convert(k_v2[0], hand, n) != k_v2[1]]
    return hanm + han

def filter_func(args):
    k, v = args
    # length is not equal or length > 6
    if len(k) != len(v) or len(k) > 6:
        return False
    # k includes invalid hanzi
    if not all(c in valid_hanzi for c in k):
        return False
    # v includes invalid hanzi
    if not all(c in valid_hanzi for c in v):
        return False

    # # check chars in k and v
    # for c1, c2 in zip(k, v):
    #     if c1 == c2:
    #         continue
    #     if c2 not in S_2_T.get(c1, []):
    #         return False
    return True

def get_records():
    records = list(zh2Hant.items())

    records = list(filter(filter_func, records))

    maxlen = max([len(k_v[0]) for k_v in records])
    for i in range(1,  maxlen - 1):
        records = filter_more(records, i)
    records = [(k_v3[0].encode("utf8"), k_v3[1].encode("utf8")) for k_v3 in records]
    records.sort()
    return maxlen, records

def main():
    print("static const char *simp_to_trad[][2] = {")
    maxlen, records = get_records()
    for s, ts in records:
        print('    { "%s", "%s" },' % (s, ts))
    print("};")
    print('#define SIMP_TO_TRAD_MAX_LEN (%d)' % maxlen)

if __name__ == "__main__":
    main()
