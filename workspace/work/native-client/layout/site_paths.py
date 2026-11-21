"""docs/source-paths.json: the site's Source files map, a best guess of the original source tree.

Paths come from every reference we hold (source_tree_sources.py): 2007 server PDB list (p), iOS Dec 2013 debug map (i),
Android Jun 2014 asserts (a), OpenRBX Dec 2007 decompilation (o), the 2008 exe's own strings (e), 2016 leak listing (l).
A path is kept when a 2007/2008-era source saw it (p, o, e) or two later sources agree (i, a, l); vendored library
folders are left out and shown as their own 'libraries/' groups from library-files.json.

row = [path, status, bytes, exported file or '', tags, tiers, alternates, completion %]
status 'a' authentic: a single native file exported at exactly this path, object-identical to the live source.
       'i' inferred: some native source is exported for it, but not as a proven single file (inferred path, merged unit,
           or a header, whose content is a native analog with no object proof of its own).
       'm' missing: no native source exported for this path.
       'g' library file matched: an exe function is byte-identical to code built from this upstream file.
       'u' library file with no match.
bytes: code bytes tied to the path by census/address evidence (library rows: matched bytes); 0 when none.

Run (after source_tree_sources.py and site_libs.py):  python work/native-client/layout/site_paths.py
"""
import collections
import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
ROOT = HERE.parents[2]
LAYOUT = ROOT / 'rebuild/2008-06/layout'
PREFIX = 'rebuild/2008-06/layout/'
HEADERS = ('.h', '.hpp', '.inl')
SOURCES = ('.cpp', '.cc', '.c', '.mm', '.m')
INCLUDE_LIBRARIES = False   # library files are upstream code, not Roblox's tree: they are not drawn on the map
VENDORED = ('client/boost', 'client/rendering/mesa', 'client/rendering/sdl', 'client/rendering/ogre-', 'client/rendering/ogresdk',
            'client/rendering/g3d/zlib', 'client/rendering/g3d/png', 'client/rendering/g3d/ijg', 'client/app/lua', 'client/app/zlib',
            'client/rendering/zlib')


def keep(path, tags):
    if path.startswith(VENDORED):
        return False
    if path.rsplit('/', 1)[-1].startswith('roc_'):      # our own mining outputs
        return False
    # real-build evidence only: the 2007 PDB, the 2008 exe, or two of the 2013/2014/2016 sources. OpenRBX is a decompiler's
    # arrangement and does not make a path count by itself.
    return 'p' in tags or 'e' in tags or sum(t in tags for t in 'ial') >= 2


def branch_case():
    """{casefolded path under the layout folder: the name the file really has on the pushed branch}."""
    listing = subprocess.run(['git', 'ls-tree', '-r', '--name-only', 'refs/remotes/origin/layout/2008-06', '--', PREFIX],
                             cwd=ROOT, capture_output=True, text=True, encoding='utf-8').stdout.splitlines()
    return {p[len(PREFIX):].casefold(): p[len(PREFIX):] for p in listing if p.startswith(PREFIX)}


def exported():
    receipt = json.loads((LAYOUT / 'receipt.json').read_text(encoding='utf-8'))
    real = branch_case()                                   # GitHub is case-sensitive; the export ran on Windows
    authentic, inferred = {}, {}               # casefolded original path -> exported file relative to the layout folder
    for export, row in receipt['per_file'].items():
        rel = export.removeprefix(PREFIX)
        if row['status'] in ('dropped', 'unverified'):
            continue
        if row.get('path') == 'inferred' or rel.startswith('inferred/'):          # old receipts used an inferred/ folder
            inferred[rel.removeprefix('inferred/').casefold()] = rel
        elif row['status'].endswith('-identical'):
            authentic[rel.casefold()] = rel
        else:
            inferred[rel.casefold()] = rel
    for export in receipt['merged_units']:
        rel = export.removeprefix(PREFIX)
        inferred[rel.removeprefix('inferred/').casefold()] = rel
    for path in LAYOUT.rglob('*'):
        if path.is_file() and path.suffix.lower() in HEADERS:
            rel = path.relative_to(LAYOUT).as_posix()
            inferred[rel.removeprefix('inferred/').casefold()] = rel
    authentic = {k: real.get(v.casefold(), v) for k, v in authentic.items()}
    inferred = {k: real.get(v.casefold(), v) for k, v in inferred.items()}
    return authentic, inferred


def tied_bytes():
    sizes = {}
    with open(ROOT / 'work/2008-06/functions.jsonl', encoding='utf-8') as lines:
        for line in lines:
            row = json.loads(line)
            if row.get('kind') == 'code':
                sizes[row['addr'].lower()] = row['size']
    tied = {}
    rows = json.loads((HERE / 'source-layout-map.json').read_text(encoding='utf-8'))
    for row in rows.values():
        evidence = row.get('candidate_address_evidence')
        if isinstance(evidence, dict):
            for path, addrs in evidence.items():
                tied.setdefault(path.casefold(), set()).update(a.lower() for a in addrs)
    return {key: sum(sizes.get(a, 0) for a in addrs) for key, addrs in tied.items()}


def native_status():
    """Integration data as published on the site (gh-pages), so completion matches what visitors see; else the local copy."""
    text = subprocess.run(['git', 'show', 'origin/gh-pages:integration.json'], cwd=ROOT, capture_output=True, text=True).stdout
    if not text.strip():
        path = ROOT / 'docs/integration.json'
        text = path.read_text(encoding='utf-8') if path.exists() else '{}'
    data = json.loads(text)
    return set(data.get('native', [])), {a for a, v in data.get('inactive', {}).items() if v[1]}


def completion():
    """{path: percent of the code guessed to be in this file that has native exact code (integrated or receipt-exact inactive)}."""
    path = ROOT / 'docs/function-map.json'
    if not path.exists():
        return {}
    data = json.loads(path.read_text(encoding='utf-8'))
    integrated, inactive_exact = native_status()
    done, total = {}, {}
    for addr, size, index, _tier in data['functions']:
        if index >= 0:
            f = data['files'][index]
            total[f] = total.get(f, 0) + size
            a = '%08x' % addr
            if a in integrated or a in inactive_exact:
                done[f] = done.get(f, 0) + size
    return {f: round(100 * done.get(f, 0) / t) for f, t in total.items() if t}


def function_bytes():
    """{path: {tier: bytes}} and the unassigned total, from docs/function-map.json (function_map.py)."""
    path = ROOT / 'docs/function-map.json'
    if not path.exists():
        return {}, 0, 0
    data = json.loads(path.read_text(encoding='utf-8'))
    out, loose, n = {}, 0, 0
    function_bytes.contested = data.get('contested', {})
    for _addr, size, index, tier in data['functions']:
        if index < 0:
            loose += size
            n += 1
        else:
            by = out.setdefault(data['files'][index], {})
            by[tier] = by.get(tier, 0) + size
    return out, loose, n


def build():
    import source_tree_sources
    tagged, union = source_tree_sources.build()
    for line in (ROOT / 'work/native-client/webservice-pdb-source-paths.txt').read_text(encoding='utf-8').splitlines():
        other = line.strip().replace('\\', '/')          # PDB paths outside Client/ (Microsoft CRT/ATL, rbxgs): kept as listed
        if other and not other.lower().startswith('client') and other.lower().endswith(source_tree_sources.EXT):
            union[other.lower()] += 'p'
    authentic, inferred = exported()
    size = tied_bytes()
    fmap, loose, loose_n = function_bytes()
    percent = completion()
    for path in fmap:                      # files that only the function map names
        if not path.startswith('libraries/') and path not in union and path.endswith(SOURCES):
            union[path] = 'f'
    # One file listed at two folders: the exe strings, then the 2007 PDB, then our own export, then the closest later
    # build decide; the others are kept as 'also listed at'. Only when no real source lists the file name twice itself.
    per_source = {t: collections.Counter(q.rsplit('/', 1)[-1] for q in tagged[t]) for t in 'pial'}
    groups = collections.defaultdict(list)
    for path, tags in union.items():
        if (keep(path, tags) or tags == 'f' or path in fmap or path.casefold() in authentic or path.casefold() in inferred) and path.endswith(SOURCES + HEADERS):
            groups[path.rsplit('/', 1)[-1]].append(path)

    def rank(path):
        tags, key = union[path], path.casefold()
        return (0 if 'e' in tags else 1 if 'p' in tags else 2 if key in authentic or key in inferred else 3 if 'i' in tags
                else 4 if 'a' in tags else 5 if 'l' in tags else 6, len(path), path)
    also, drop = {}, set()
    for base, paths in groups.items():
        if len(paths) > 1 and all(per_source[t][base] <= 1 for t in 'pial'):
            ordered = sorted(paths, key=rank)
            also[ordered[0]] = [(q, ''.join(sorted(set(union[q])))) for q in ordered[1:]]
            drop.update(ordered[1:])
    out = []
    for path, tags in sorted(union.items()):
        if path in drop or (not keep(path, tags) and tags != 'f' and path not in fmap
                            and path.casefold() not in authentic and path.casefold() not in inferred):
            continue
        key = path.casefold()
        status = 'a' if key in authentic else 'i' if key in inferred else 'm'
        by = fmap.get(path, {})
        out.append([path, status, sum(by.values()) or size.get(key, 0), authentic.get(key) or inferred.get(key) or '',
                    ''.join(sorted(set(tags))), ','.join('%s:%d' % kv for kv in sorted(by.items())),
                    ';'.join(['%s|%d' % kv for kv in function_bytes.contested.get(path, {}).items()]
                             + ['%s|%s' % kv for kv in also.get(path, [])]), percent.get(path)])
    # libraries: upstream files of the libraries in the exe, matched by bytes (site_libs.py)
    libs = json.loads((ROOT / 'docs/library-files.json').read_text(encoding='utf-8'))['libs'] if (ROOT / 'docs/library-files.json').exists() else []
    for lib in libs if INCLUDE_LIBRARIES else []:
        for rel, status, nbytes, nfuncs in lib['files']:
            out.append(['libraries/%s/%s' % (lib['name'], rel), 'g' if status != 'n' else 'u', nbytes, '', status, '', ''])
    # A missing path that none of our functions connect to says nothing about the 2008 exe: it is not drawn. (Many are
    # compiler headers from the PDB, 2013+ only files, and RCCService/server code.)
    hidden = sum(1 for r in out if r[1] == 'm' and not r[2])
    out = [r for r in out if not (r[1] == 'm' and not r[2])]
    if loose:
        out.append(['unassigned/%d functions with no file guess' % loose_n, 'x', loose, '', '', '', '', None])
    for r in out:                                       # template machinery has no file of its own: outside the organized percentage
        if r[0] == 'client/templates/machinery.cpp':
            r[1] = 'x'
    summary = {s: sum(1 for r in out if r[1] == s) for s in 'aimgux'}
    own = [r for r in out if not r[0].startswith('libraries/')]
    source = [r for r in own if r[0].endswith(SOURCES)]
    summary_source = {s: sum(1 for r in source if r[1] == s) for s in 'aim'}
    summary_own = {s: sum(1 for r in own if r[1] == s) for s in 'aim'}
    commit = subprocess.run(['git', 'rev-parse', '--short', 'layout/2008-06'], cwd=ROOT, capture_output=True, text=True).stdout.strip()
    return {'note': 'best-guess original source tree; see site_paths.py for the evidence tags and status codes',
            'commit': commit, 'paths': out, 'hidden_unconnected': hidden, 'summary': summary, 'summary_own': summary_own, 'summary_source': summary_source,
            'tag_names': {'p': '2007 server PDB', 'i': 'iOS Dec 2013 debug map', 'a': 'Android Jun 2014 asserts',
                          'o': 'OpenRBX (decompiler arrangement, weak)', 'e': '2008 exe strings', 'l': '2016 source leak listing',
                          'f': 'function map guess'},
            'tier_names': {'L': 'library bytes match', 'P': 'name in the 2007 PDB or PDB census', 'I': 'iOS 2013 same-named function', 'O': 'OpenRBX (weak)', 'C': 'class rule (weak)', 'S': 'same class as most of its functions (about 97% right on held-out checks)', 'U': 'same RTTI class as most of its functions (about 90% right on held-out checks)', 'D': 'uses data that only this file uses (about 85% right on held-out checks)', 'F': 'static initializer using a global that one placed function of this file uses (94% right on held-out checks)', 'J': 'between two functions of its own class that are in this file (96% right on held-out checks)', 'Z': 'library class named like one upstream library file (a library placement, not a Roblox path)', 'Y': 'class name matches a file name in the builds we hold (about 63% right; the weakest placement)', 'W': 'same RTTI class, counting weak placements too (a guess about a guess)', 'V': 'same RTTI class, split across files; one file holds most of it (weaker than U)', 'Q': 'property initializer, with its get/set accessors (18 of 18 right on held-out checks)', 'H': 'same instruction pattern and size as its neighbours in this file (about 97% right on held-out checks)', 'G': 'named by similarity to the iOS/Android Ghidra exports', 'T': 'template of a class in this file', 'B': 'tiny stub right after a function of this file', 'E': 'file-name string in the 2008 exe', 'K': 'only called from this file (about 70% right on held-out checks)', 'm': 'class defined in exactly one file of the 2016 leak or the iOS build, and that file is nearby (about 63% right)', 'A': 'last resort: the nearest placed function by address (about 76% right in general, less for these leftovers)', 'M': 'same class and method defined in this file in the 2016 leak', 'N': 'native piece path', 'R': 'between two functions of this file'}}


if __name__ == '__main__':
    data = build()
    target = ROOT / 'docs/source-paths.json'
    target.write_text(json.dumps(data, separators=(',', ':')), encoding='utf-8')
    print('all', data['summary'], '| Roblox tree', data['summary_own'], '| .c/.cpp', data['summary_source'], 'wrote', target)
