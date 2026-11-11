"""Plan headerless fieldless methods backed by one real local provider header.

This never emits a header.  It admits only a source/header pair already in
tools/rbxgs, rejects generated `roc_*` helpers, and leaves the compiler plus
byte/layout/reference gates to decide every candidate.
"""
import argparse
import hashlib
import json
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
SOURCE_ROOTS = [ROOT / 'tools/rbxgs', ROOT / 'tools/openrbx', ROOT / 'work/upstream/OpenRBX', ROOT / 'tools/libs']
INCLUDE = re.compile(r'^\s*#include\s+"([^"]+)"', re.M)
ROC_FLAGS = re.compile(r'^// roc-flags:\s*(.*)$', re.M)
ROC_LIB = re.compile(r'^// roc-lib:\s*(\S+)\s+(.+)$', re.M)
INDEX_CACHE = ROOT / 'work/native-client/phase2-source-index-v2.json'


def complete_owner(header, owner):
    text = header.read_text(errors='replace')
    short = owner.rsplit('::', 1)[-1]
    return bool(re.search(r'\b(?:class|struct)\b[^;{]*\b' + re.escape(short) + r'\b[^;{]*\{', text, re.S))


def source_index():
    """One source scan, not one ripgrep process per candidate."""
    files = sorted(path for root in SOURCE_ROOTS if root.is_dir() for path in root.rglob('*.cpp')
                   if not path.name.startswith('roc_'))
    stamp = [[str(path.relative_to(ROOT)).replace('\\', '/'), path.stat().st_size, path.stat().st_mtime_ns]
             for path in files]
    try:
        cached = json.loads(INDEX_CACHE.read_text())
        if cached.get('stamp') == stamp:
            return defaultdict(set, {(owner, method): {ROOT / value for value in paths}
                                     for owner, method, paths in cached['entries']})
    except (OSError, json.JSONDecodeError, KeyError):
        pass
    index = defaultdict(set)
    pattern = re.compile(r'\b([A-Za-z_]\w*)::([~A-Za-z_]\w*)\s*\(')
    for path in files:
        for owner, method in pattern.findall(path.read_text(errors='replace')):
            index[(owner, method)].add(path.resolve())
    INDEX_CACHE.write_text(json.dumps({'stamp': stamp,
                                       'entries': [[owner, method, sorted(str(path.relative_to(ROOT)).replace('\\', '/')
                                                                            for path in paths)]
                                                   for (owner, method), paths in sorted(index.items())]}, indent=1) + '\n')
    return index


def source_for(index, owner, method):
    files = index.get((owner.rsplit('::', 1)[-1], method), set())
    if len(files) == 1:
        return next(iter(files))
    # Vendor mirrors are common.  Identical text is one donor hypothesis,
    # not an ambiguity; divergent bodies remain blocked for proof to decide.
    groups = defaultdict(list)
    for path in files:
        groups[hashlib.sha256(path.read_bytes()).digest()].append(path)
    if len(groups) != 1:
        return None
    return sorted(next(iter(groups.values())), key=lambda path: str(path))[0]


def header_for(source, owner):
    headers, seen = [], set()
    def visit(path, depth):
        path = path.resolve()
        if depth > 8 or path in seen or not path.is_file():
            return
        seen.add(path)
        text = path.read_text(errors='replace')
        if complete_owner(path, owner):
            headers.append(path)
        for name in INCLUDE.findall(text):
            child = (path.parent / name).resolve()
            if child.is_file():
                visit(child, depth + 1)
    visit(source, 0)
    headers = sorted(set(headers))
    return headers[0] if len(headers) == 1 else None


def packet_flags(address, fallback_recipe=''):
    """Use target packet's proven compile profile; never guess a provider flag."""
    packet = ROOT / 'src/2008-06' / (address + '.cpp')
    if not packet.is_file():
        return ''
    text = packet.read_text(errors='replace')
    match = ROC_FLAGS.search(text)
    flags = match.group(1).strip() if match else ''
    lib = ROC_LIB.search(text)
    if not lib and not fallback_recipe:
        return flags
    from roc import libs
    recipe = lib.group(1) if lib else fallback_recipe
    # Some old packets name XTP's broad source recipe while server replay used
    # its library prelude.  This is a bounded profile candidate only; later
    # byte proof decides every body.
    if recipe == 'xtp-11.2.2':
        recipe = 'xtp-11.2.2-lib'
    spec = libs.RECIPES.get(recipe)
    if not spec:
        return flags
    extras = []
    for value in spec.get('include', []):
        path = (libs.LIBS / value).resolve()
        if path.is_dir():
            extras.append('/I' + str(path))
    for value in spec.get('defines', '').split():
        if re.fullmatch(r'[A-Za-z_]\w*(?:=.*)?', value):
            extras.append('/D' + value)
    for value in spec.get('preinclude', []):
        for root in [libs.LIBS / item for item in spec.get('include', [])]:
            header = root / value
            if header.is_file():
                extras.append('/FI' + str(header.resolve()))
                break
    return ' '.join([flags, *extras]).strip()


def packet_source(address):
    """A packet recipe names its donor unit more strongly than text search."""
    packet = ROOT / 'src/2008-06' / (address + '.cpp')
    if not packet.is_file():
        return None
    match = ROC_LIB.search(packet.read_text(errors='replace'))
    if not match:
        return None
    from roc import libs
    recipe, relative = match.groups()
    spec = libs.RECIPES.get(recipe)
    if not spec:
        return None
    source = (libs.LIBS / spec['src'] / relative).resolve()
    if recipe in {'openrbx-raknet', 'rbxgs-raknet'}:
        candidate = ROOT / 'tools/rbxgs/Client/Network/raknet30/Source' / relative
        if candidate.is_file():
            source = candidate.resolve()
    return source if source.is_file() and not source.name.startswith('roc_') else None


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--queue', type=Path, required=True)
    ap.add_argument('--limit', type=int, default=20)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    queue = json.loads(args.queue.read_text())['rows']
    index = source_index()
    groups, blocked = defaultdict(list), []
    for row in queue:
        if row['headers'] or row['native_definition_sources']:
            continue
        if row.get('thunk_target'):
            continue
        if row['kind'] == 'fieldless-thiscall' and row['fieldless'] != 'fieldless':
            continue
        owner = row['owner']
        if not owner or owner.startswith('`') or '::`' in owner:
            continue
        decoded = row['symbol']
        method = decoded.split('@', 1)[0].lstrip('?').lstrip('~')
        # MSVC constructor/destructor tokens cannot be inferred safely here.
        if decoded.startswith('??'):
            continue
        source = packet_source(row['address']) or source_for(index, owner, method)
        if not source:
            blocked.append({'addr': row['address'], 'reason': 'no unique real rbxgs source', 'owner': owner})
            continue
        header = header_for(source, owner)
        if not header:
            blocked.append({'addr': row['address'], 'reason': 'no unique real provider header', 'owner': owner,
                            'source': str(source.relative_to(ROOT))})
            continue
        fallback = 'xtp-11.2.2-lib' if 'tools\\libs\\xtp-11.2.2\\' in str(source).lower() else ''
        groups[(owner, source, header, packet_flags(row['address'], fallback))].append(row)
    plans = []
    for (owner, source, header, roc_flags), rows in sorted(groups.items(), key=lambda item: (item[0][0], str(item[0][1]), item[0][3])):
        # Phase-2 approval: every planned member must be fieldless/static.
        if any(row['kind'] == 'fieldless-thiscall' and row['fieldless'] != 'fieldless' for row in rows):
            continue
        unique = {row['address']: row for row in rows}
        ordered = [unique[key] for key in sorted(unique, key=lambda key: (unique[key]['size'], key))]
        for offset in range(0, len(ordered), args.limit):
            selected = ordered[offset:offset + args.limit]
            plans.append({'owner': owner, 'headers': [str(header.relative_to(ROOT)).replace('\\', '/')],
                          'source': str(source), 'namespace': '::'.join(owner.split('::')[:-1]),
                          'roc_cl': 21022, 'roc_flags': roc_flags,
                          'destination': 'rebuild/2008-06/native-classes/' + owner.rsplit('::', 1)[-1] + '.cpp',
                          'probe_records': [row['address'] + '=' + owner.rsplit('::', 1)[-1] + '::' + row['symbol'].split('@', 1)[0].lstrip('?') for row in selected],
                          'rows': [{'addr': row['address'], 'symbol': row['symbol'],
                                    'marker': owner.rsplit('::', 1)[-1] + '::' + row['symbol'].split('@', 1)[0].lstrip('?')}
                                   for row in selected]})
    out = {'scope': 'Phase-2 declaration-free vendor-provider candidates; no header/source emitted',
           'summary': {'plans': len(plans), 'methods': sum(len(plan['rows']) for plan in plans),
                       'blocked': len(blocked)}, 'plans': plans, 'blocked': blocked}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))


if __name__ == '__main__':
    main()
