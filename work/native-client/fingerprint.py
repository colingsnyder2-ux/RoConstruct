"""Fingerprint pass: which known upstream source function was an unnamed exe function ported from?

Exe side (from the disassembly): rare immediates (cmp ecx, 0xf0 -> 240), float/double constants loaded from
.rdata, string literals, and the leaf names of imported functions/data (rgmain.dll ?PI@Math@Ogre -> PI).
Source side, per function body in a corpus of library sources: integer/float/string literals (file #define
numbers expanded) and identifiers. IDF-weighted overlap ranks candidates. This is triage evidence for a port,
never identity or byte proof.

Corpus: every extracted library under tools/libs plus work/native-client/fingerprint-corpus (fetched upstream
files; sources.json there records url + sha256). The parsed index is cached by file size/mtime.

  python work/native-client/fingerprint.py [ADDR ...] [--min-size 64] [--top 3]
      -> work/native-client/fingerprint-matches.json   (default targets: Ogre-scope roots without a native proof)
  python work/native-client/fingerprint.py --self-test
"""
import argparse
import collections
import json
import math
import pickle
import re
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE / 'ogre'))

CORPUS_DIRS = [p for p in (ROOT / 'tools/libs').iterdir() if p.is_dir() and p.name != '_dl'] + [HERE / 'fingerprint-corpus']
INDEX = HERE / 'fingerprint-corpus-index.pickle'
OUT = HERE / 'fingerprint-matches.json'
EXTS = {'.c', '.cpp', '.cc', '.cxx', '.inl'}
SMALL = 16                       # |int| <= 16 is everywhere: no evidence

COMMENT = re.compile(r'//[^\n]*|/\*.*?\*/', re.S)
STRING = re.compile(r'"((?:\\.|[^"\\\n])*)"')
NUMBER = re.compile(r'(?<![\w.])(0[xX][0-9a-fA-F]+|\d+\.\d*(?:[eE][-+]?\d+)?|\.\d+(?:[eE][-+]?\d+)?|\d+[eE][-+]?\d+|\d+)[uUlLfF]*(?![\w.])')
IDENT = re.compile(r'\b[A-Za-z_]\w*\b')
DEFINE = re.compile(r'^\s*#\s*define\s+(\w+)\s+\(?\s*([-+]?[\d.]+(?:[eE][-+]?\d+)?|0[xX][0-9a-fA-F]+)[uUlLfF]*\s*\)?\s*$', re.M)
OPENER = re.compile(r'\)\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?(?::[^;{}]*)?$')
CONTROL = {'if', 'for', 'while', 'switch', 'catch', 'return', 'sizeof', 'defined', 'else', 'do'}


def number_token(text):
    if text.lower().startswith('0x'):
        v = int(text.rstrip('uUlL'), 16)
        return None if v <= SMALL else 'i:%d' % v
    t = text.rstrip('uUlLfF')
    if re.fullmatch(r'\d+', t):
        v = int(t)
        return None if v <= SMALL else 'i:%d' % v
    v = float(t)
    if v == int(v) and abs(v) <= SMALL:
        return None
    return float_token(v)


def float_token(v):
    if not math.isfinite(v) or v == 0:
        return None
    v = struct.unpack('<f', struct.pack('<f', v))[0] if abs(v) < 3.4e38 else v
    return 'f:%.5g' % v


def functions(text):
    """-> [(name, start_line, end_line, body)] for every function definition (brace-matched, comments stripped)."""
    code = COMMENT.sub(lambda m: re.sub(r'[^\n]', ' ', m.group(0)), text)
    blank = STRING.sub(lambda m: '"' + ' ' * len(m.group(1)) + '"', code)
    out, i = [], 0
    while True:
        i = blank.find('{', i)
        if i < 0:
            return out
        head = blank[max(0, i - 400):i]
        if OPENER.search(head):
            close = head.rfind(')')
            depth, j = 0, close
            while j >= 0:                                   # find the matching '('
                depth += {')': 1, '(': -1}.get(head[j], 0)
                if depth == 0:
                    break
                j -= 1
            name = re.search(r'([~\w:]+)\s*$', head[:j]) if j > 0 else None
            if name and name.group(1).split('::')[-1] not in CONTROL:
                depth, k = 0, i
                while k < len(blank):
                    depth += {'{': 1, '}': -1}.get(blank[k], 0)
                    if depth == 0:
                        break
                    k += 1
                start = text.count('\n', 0, i - len(head) + j) + 1
                out.append((name.group(1), start, text.count('\n', 0, k) + 1, code[i - len(head) + j - len(name.group(1)):k + 1]))
                i = k + 1
                continue
        i += 1


def source_tokens(body, defines):
    toks = set()
    for s in STRING.findall(body):
        if len(s) >= 3:
            toks.add('s:' + s)
    nostr = STRING.sub('""', body)
    for name, sign, k in re.findall(r'\b([A-Za-z_]\w*)\s*([-+])\s*(\d+)\b', nostr):    # CACHE_SIZE-1 -> 239
        t = number_token(defines[name]) if name in defines else None
        if t and t.startswith('i:'):
            v = int(t[2:]) + (int(k) if sign == '+' else -int(k))
            if v > SMALL:
                toks.add('i:%d' % v)
    for n in NUMBER.findall(nostr):
        t = number_token(n)
        if t:
            toks.add(t)
    for ident in IDENT.findall(nostr):
        if ident in defines:
            t = number_token(defines[ident])
            if t:
                toks.add(t)
        if len(ident) >= 2:
            toks.add('n:' + ident)
    return toks


def build_index():
    cache = pickle.loads(INDEX.read_bytes()) if INDEX.is_file() else {}
    files, fresh = {}, 0
    for top in CORPUS_DIRS:
        if not top.is_dir():
            continue
        for path in top.rglob('*'):
            if path.suffix.lower() not in EXTS or path.name.startswith('roc_') or not path.is_file():   # roc_*: our own analogs
                continue
            key, st = str(path), path.stat()
            stamp = (st.st_size, st.st_mtime_ns)
            if key in cache and cache[key][0] == stamp:
                files[key] = cache[key]
                continue
            text = path.read_text(errors='replace')
            defines = dict(DEFINE.findall(text))
            rows = [(name, a, b, sorted(source_tokens(body, defines))) for name, a, b, body in functions(text)]
            files[key] = (stamp, rows)
            fresh += 1
    if fresh or len(files) != len(cache):
        INDEX.write_bytes(pickle.dumps(files))
    return files


def leaf_name(imported):
    name = imported.split('!', 1)[-1]
    if name.startswith('??') or name.startswith('#'):
        return None
    return name.lstrip('?_').split('@')[0] or None


def exe_tokens(addr, ctx):
    from capstone import CS_ARCH_X86, CS_MODE_32, Cs
    from roc import match
    base, image, imports, text_end = ctx
    code = match.target('2008-06', addr)[0]
    cs = Cs(CS_ARCH_X86, CS_MODE_32)
    cs.detail = True
    toks = set()
    for ins in cs.disasm(bytes(code), int(addr, 16)):
        for op in ins.operands:
            if op.type == 2:                                   # immediate
                v = op.imm & 0xffffffff
                if base <= v < base + len(image):
                    s = c_string(image, v - base)
                    if s:
                        toks.add('s:' + s)
                elif SMALL < (v if v < 0x80000000 else 0x100000000 - v) < 0x100000:
                    toks.add('i:%d' % (v if v < 0x80000000 else v - 0x100000000))
            elif op.type == 3 and not op.mem.base and not op.mem.index:   # [absolute]
                v = op.mem.disp & 0xffffffff
                if v in imports:
                    leaf = leaf_name(imports[v])
                    if leaf:
                        toks.add('n:' + leaf)
                elif text_end <= v < base + len(image) - 8 and ins.mnemonic.startswith('f'):
                    raw = struct.unpack_from('<d' if op.size == 8 else '<f', image, v - base)[0]
                    t = float_token(raw)
                    if t and not (raw == int(raw) and abs(raw) <= SMALL):
                        toks.add(t)
    return toks


def c_string(image, off):
    end = image.find(b'\0', off, off + 200)
    raw = image[off:end] if end > off else b''
    return raw.decode('latin-1') if len(raw) >= 3 and all(32 <= c < 127 for c in raw) else None


def context():
    import pefile
    from roc import match, standins
    base, image = match._image('2008-06')
    pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
    text = next(s for s in pe.sections if s.Name.rstrip(b'\0') == b'.text')
    return base, image, standins._imports('2008-06'), base + text.VirtualAddress + text.Misc_VirtualSize


def rank(targets, files, top):
    df = collections.Counter()
    postings = collections.defaultdict(list)
    funcs = []
    for path, (_, rows) in files.items():
        for name, a, b, toks in rows:
            fid = len(funcs)
            funcs.append((path, name, a, b))
            for t in toks:
                df[t] += 1
                postings[t].append(fid)
    n = max(len(funcs), 1)
    idf = lambda t: math.log(n / (1 + df[t]))
    # Candidate weight: its literal tokens only (a body names hundreds of identifiers the exe never shows).
    cand = [0.0] * len(funcs)
    for t, fids in postings.items():
        if t[0] != 'n':
            for fid in fids:
                cand[fid] += idf(t)
    # Exe-side frequency: a token in many targets (inlined refcount Interlocked*, a common size) is weak evidence.
    tdf = collections.Counter(t for toks in targets.values() for t in toks)
    big = len(targets) >= 20
    base_idf = idf
    idf = lambda t: base_idf(t) * (min(1.0, math.log(len(targets) / tdf[t]) / math.log(20)) if big and tdf[t] else 1.0)
    out = {}
    for addr, toks in targets.items():
        known = [t for t in toks if df[t]]
        weight = sum(idf(t) for t in known) or 1
        score = collections.defaultdict(float)
        shared = collections.defaultdict(list)
        for t in known:
            if df[t] > max(n // 50, 1):                                # too common to vote
                continue
            for fid in postings[t]:
                score[fid] += idf(t)
                shared[fid].append(t)
        # Cosine-style: a long literal table (XTP colour metrics, JPEG Huffman tables) must not win on volume.
        cos = {f: s / math.sqrt(weight * (cand[f] + sum(idf(t) for t in shared[f] if t[0] == 'n') or 1))
               for f, s in score.items()}
        best = sorted((f for f in cos if sum(map(strong, shared[f])) >= 2), key=lambda f: -cos[f])[:top]
        out[addr] = [{'file': rel(funcs[f][0]), 'function': funcs[f][1],
                      'lines': [funcs[f][2], funcs[f][3]], 'score': round(cos[f], 3),
                      'confidence': confidence(shared[f]),
                      'shared': sorted(shared[f], key=lambda t: -idf(t))[:8]}
                     for f in best if sum(map(strong, shared[f])) >= 2]
    return out


def strong(token):
    """Strings, floats, names, and ints above 64 (smaller ones are mostly sizes/offsets)."""
    return not (token.startswith('i:') and abs(int(token[2:])) <= 64)


def confidence(shared):
    """high: a shared string or 3+ strong tokens; low: two (e.g. only an inlined Interlocked pair)."""
    return 'high' if any(t.startswith('s:') for t in shared) or sum(map(strong, shared)) >= 3 else 'low'


def rel(path):
    try:
        return Path(path).relative_to(ROOT).as_posix()
    except ValueError:
        return str(path)


def body_of(match_row):
    """The source text of one ranked match (for LLM packets)."""
    lines = (ROOT / match_row['file']).read_text(errors='replace').splitlines()
    a, b = match_row['lines']
    return '\n'.join(lines[a - 1:b])


def lookup(addr, min_score=0.5):
    """Best stored fingerprint match for addr with its body, or None."""
    if not OUT.is_file():
        return None
    rows = json.loads(OUT.read_text()).get('matches', {}).get(addr.lower(), [])
    if rows and rows[0]['score'] >= min_score and rows[0].get('confidence') == 'high':
        return dict(rows[0], body=body_of(rows[0]))
    return None


def default_targets(min_size):
    import run_all
    from roc import match
    roots = run_all.roots(('Ogre::', 'RBX::RenderNew', 'RBX::ViewNew'))
    exact = set()
    census = sorted(HERE.glob('ogre-native-full-census-loop*/manifest.json'), key=lambda p: p.stat().st_mtime)
    if census:
        for family in json.loads(census[-1].read_text())['families']:
            for row in family['symbols']:
                if row.get('status') == 'inactive_exact':
                    exact.update(row.get('candidates') or [])
    fs = match._functions('2008-06')
    return [a for a in roots if a not in exact and fs.get(a, {}).get('size', 0) >= min_size]


def self_test():
    src = '#define CACHE_SIZE 240\nvoid gluSphere(int slices)\n{\n  if (slices >= CACHE_SIZE) slices = CACHE_SIZE-1;\n  x = 2.5f * PI; puts("hello");\n  if (y) { z(); }\n}\n'
    (name, a, b, body), = functions(src)
    assert (name, a, b) == ('gluSphere', 2, 7), (name, a, b)
    toks = source_tokens(body, dict(DEFINE.findall(src)))
    assert {'i:240', 'i:239', 'f:2.5', 's:hello', 'n:PI'} <= toks, toks
    files = {'x': ((0, 0), [('gluSphere', 2, 7, sorted(toks)), ('other', 1, 1, ['i:99', 'n:foo'])])}
    got = rank({'00000001': {'i:240', 'n:PI', 'f:2.5'}}, files, 2)
    assert got['00000001'][0]['function'] == 'gluSphere', got
    print('self-test ok')


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('addrs', nargs='*')
    ap.add_argument('--min-size', type=int, default=64)
    ap.add_argument('--top', type=int, default=3)
    ap.add_argument('--self-test', action='store_true')
    args = ap.parse_args()
    if args.self_test:
        return self_test()
    files = build_index()
    ctx = context()
    addrs = [a.lower() for a in args.addrs] or default_targets(args.min_size)
    targets = {a: exe_tokens(a, ctx) for a in addrs}
    matches = rank(targets, files, args.top)
    OUT.write_text(json.dumps({'scope': __doc__.splitlines()[0], 'corpus_functions': sum(len(r) for _, r in files.values()),
                               'matches': matches}, indent=1) + '\n')
    hits = sorted(((m[0]['score'], a, m[0]) for a, m in matches.items() if m and m[0]['confidence'] == 'high'), reverse=True)
    print('%d targets, %d with a high-confidence candidate (%d low)' % (
        len(addrs), len(hits), sum(1 for m in matches.values() if m) - len(hits)))
    for score, a, m in hits[:25]:
        print('%s %.2f %s:%d %s %s' % (a, score, m['file'], m['lines'][0], m['function'], ' '.join(m['shared'][:4])))


if __name__ == '__main__':
    main()
