"""Name unnamed 2008 functions by similarity to the Ghidra exports of the iOS 2013 and Android 2014 builds.

Features of a 2008 function: the string literals it uses and the qualified names of the functions it calls (taken
from the 2008 functions whose names are already known). A Ghidra function matches when it shares those strings and
callee names. The best candidate wins only with a clear margin. The result is a ranked guess for the NAME (and,
through the iOS debug map, the file); it is checked here against 2008 functions whose name is known (held out).

Writes name-guesses.json: {addr: [qualified name, score, source, files]}.
Run (after ghidra_index.py):  python work/native-client/layout/name_match.py
"""
import collections
import json
import math
import re
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
ROOT = HERE.parents[2]
MIN_SCORE = 0.5


def strip_templates(text):
    out, depth = [], 0
    for ch in text:
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth = max(depth - 1, 0)
        elif depth == 0:
            out.append(ch)
    return ''.join(out)


def ghidra_key(name):
    parts = [p for p in strip_templates(name).split('::') if p]
    if len(parts) >= 2 and parts[-1] == parts[-2]:
        parts[-1] = '<init>'
    elif len(parts) >= 2 and parts[-1] == '~' + parts[-2]:
        parts[-1] = '<fini>'
    return tuple(parts)


class Exe:
    """Reads constants out of the 2008 exe: a data reference that points at a float or double literal."""

    def __init__(self):
        import file_strings
        self.data = file_strings.EXE.read_bytes()
        self.sections = [s for s in file_strings.sections(self.data)[1] if s[0] != '.text']

    def at(self, va, size):
        for _name, base, vsize, raw, rsize in self.sections:
            if base <= va and va + size <= base + min(vsize, rsize):
                return self.data[raw + va - base:raw + va - base + size]
        return None

    def floats(self, refs):
        out = set()
        for ref in refs:
            try:
                va = int(ref, 16)
            except (TypeError, ValueError):
                continue
            for fmt, size in (('<f', 4), ('<d', 8)):
                raw = self.at(va, size)
                if raw:
                    v = abs(struct.unpack(fmt, raw)[0])
                    if math.isfinite(v) and 1e-6 < v < 1e9:
                        text = '%.5g' % v
                        digits = text.replace('.', '').replace('e', '').replace('-', '').replace('+', '').lstrip('0')
                        if len(digits) >= 4:                 # round numbers (0.5, 100) say nothing
                            out.add(text)
        return out


def load():
    import layout_ios
    gi = json.loads((HERE / 'ghidra-index.json').read_text(encoding='utf-8'))
    records = []
    for tag, rows in gi.items():
        for r in rows:
            key = ghidra_key(r['n'])
            if len(key) >= 2:
                calls = {ghidra_key(c) for c in r['c']}
                records.append((key, tag, set(r['s']), {c for c in calls if len(c) >= 2}, set(r.get('f', []))))
    # (the 2016 leak's string literals were tried as extra records: more noise than signal, held-out accuracy fell)
    funcs = {}
    for line in open(ROOT / 'work/2008-06/functions.jsonl', encoding='utf-8'):
        row = json.loads(line)
        if row.get('kind') == 'code':
            funcs[row['addr'].lower()] = row
    names = {a: (e or {}).get('name') or '' for a, e in json.loads((HERE / 'function-files.json').read_text(encoding='utf-8')).items()}
    known = {}
    for addr, n in names.items():
        k = layout_ios.msvc(n) if n.startswith('?') else None
        if k and addr in funcs:
            known[addr] = k
    return layout_ios, records, funcs, known


def build_index(records):
    by_string, by_call, by_float = collections.defaultdict(set), collections.defaultdict(set), collections.defaultdict(set)
    for i, (_k, _t, strings, calls, floats) in enumerate(records):
        for f in floats:
            by_float[f].add(i)
        for s in strings:
            by_string[s].add(i)
        for c in calls:
            by_call[c].add(i)
    return by_string, by_call, by_float


def features(row, known, exe=None):
    strings = {s for s in row.get('strings', []) if len(s) >= 4}
    calls = {known[t.lower()] for t in row.get('call_targets', []) if t.lower() in known}
    floats = exe.floats(row.get('data_refs', [])) if exe else set()
    return strings, {c for c in calls if len(c) >= 2}, floats


def best(strings, calls, floats, records, by_string, by_call, by_float, hide=None):
    score = collections.Counter()
    for f in floats:
        owners = by_float.get(f, ())
        if 0 < len(owners) <= 30:
            for i in owners:
                score[i] += 1.5 / len(owners) ** 0.5
    for s in strings:
        owners = by_string.get(s, ())
        if 0 < len(owners) <= 6:
            for i in owners:
                score[i] += 3.0 / len(owners) ** 0.5
    for c in calls:
        owners = by_call.get(c, ())
        if 0 < len(owners) <= 40:
            for i in owners:
                score[i] += 2.0 / len(owners) ** 0.5
    if not score:
        return None
    total = 3.0 * len(strings) + 2.0 * len(calls) + 1.5 * len(floats)
    by_name = collections.defaultdict(float)
    for i, v in score.items():
        key = records[i][0]
        if key != hide:
            by_name[key] = max(by_name[key], v)
    if not by_name:
        return None
    ranked = sorted(by_name.items(), key=lambda kv: -kv[1])
    top, top_v = ranked[0]
    second = ranked[1][1] if len(ranked) > 1 else 0
    if second and second > 0.8 * top_v:
        return None
    return top, round(top_v / max(total, 1.0), 2), top_v


def main():
    layout_ios, records, funcs, known = load()
    by_string, by_call, by_float = build_index(records)
    exe = Exe()
    print('ghidra functions', len(records), '| 2008 functions with a known name', len(known))
    # held out: how often is the guess the real name?
    bands = collections.defaultdict(lambda: [0, 0])
    ios_index = layout_ios.index()
    file_ok = [0, 0]
    for addr, real in known.items():
        strings, calls, floats = features(funcs[addr], {a: k for a, k in known.items() if a != addr}, exe)
        if len(strings) + len(calls) + len(floats) < 2:
            continue
        got = best(strings, calls, floats, records, by_string, by_call, by_float)
        if got and got[1] >= MIN_SCORE:
            band = '0.5-0.7' if got[1] < 0.7 else '0.7-0.9' if got[1] < 0.9 else '0.9+'
            bands[band][1] += 1
            pf, rf = set(ios_index.get(got[0], ())), set(ios_index.get(real, ()))
            if len(pf) == 1 and len(rf) == 1:                      # same file by the iOS debug map, even if the name is wrong
                file_ok[1] += 1
                file_ok[0] += pf == rf
            bands[band][0] += got[0] == real or got[0][-2:] == real[-2:] and got[0][-2] == real[-2]
    for band in sorted(bands):
        ok, n = bands[band]
        print('  held-out score %s: right name (or same class and method) in %d of %d (%.0f%%)' % (band, ok, n, 100 * ok / max(n, 1)))
    print('  held-out, whether the guessed name lands in the same iOS file as the real one: %d of %d (%.0f%%)' % (
        file_ok[0], file_ok[1], 100 * file_ok[0] / max(file_ok[1], 1)))
    # guess for the functions with no name
    ios = layout_ios.index()
    lp = HERE / 'leak-index.json'
    leak_files = json.loads(lp.read_text(encoding='utf-8'))['files'] if lp.exists() else {}
    out = {}
    for rounds in range(2):                                   # a second pass can use names the first pass found
        grown = dict(known)
        for a, v in out.items():
            grown[a] = tuple(v[0].split('::'))
        for addr, row in funcs.items():
            if addr in known or (addr in out and rounds == 0):
                continue
            strings, calls, floats = features(row, grown, exe)
            if len(strings) + len(calls) + len(floats) < 2 and not any(len(s) >= 8 for s in strings):
                continue
            got = best(strings, calls, floats, records, by_string, by_call, by_float)
            if got and got[1] >= MIN_SCORE:
                files = sorted(ios.get(got[0], {})) or sorted(leak_files.get('::'.join(got[0][-2:]), []))
                out[addr] = ['::'.join(got[0]), got[1], round(got[2], 1), files[:3]]
    (HERE / 'name-guesses.json').write_text(json.dumps(out, separators=(',', ':')), encoding='utf-8')
    print('unnamed functions given a name guess:', len(out), '| with a unique iOS file:', sum(1 for v in out.values() if len(v[3]) == 1))


if __name__ == '__main__':
    main()
