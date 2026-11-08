"""Inventory unresolved MSVC symbols and provider candidates; never build or run clients.

Object definitions prove symbol presence only. Text matches are search leads, not
definitions. Neither establishes source freshness, link selection, ABI or gates.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[3]
BASE = ROOT / 'rebuild/2008-06'
sys.path.insert(0, str(ROOT))
from roc import libs, rebuild


def parse_errors(text):
    rows = {}
    for line in text.splitlines():
        hit = re.search(r'^(.*?)\s*:\s*error LNK(?:2001|2019): unresolved external symbol (.*?) (?:\(([^\s]+)\))(?= referenced|\s*$)', line)
        if hit:
            obj, display, symbol = hit.groups()
        else:
            hit = re.search(r'^(.*?)\s*:\s*error LNK(?:2001|2019): unresolved external symbol (\S+)(?= referenced|\s*$)', line)
            if not hit:
                continue
            obj, symbol = hit.groups()
            display = symbol
        row = rows.setdefault(symbol, {'symbol': symbol, 'display': display.strip('"'), 'requesters': []})
        if obj not in row['requesters']:
            row['requesters'].append(obj)
    return list(rows.values())


def source_terms(display):
    # Qualified member names distinguish bodies from generic class mentions.
    return set(re.findall(r'([A-Za-z_]\w*)(?:<[^()]*?>)?::(~?[A-Za-z_]\w*)\s*(?:<[^()]*>)?\(', display))


def inventory(log, object_dirs, source_dirs):
    raw = log.read_bytes()
    rows = parse_errors(raw.decode('utf-8-sig', errors='replace'))
    wanted = {row['symbol'] for row in rows}
    encoded = {symbol: symbol.encode('ascii') for symbol in wanted}
    providers = {symbol: [] for symbol in wanted}
    errors = []
    libraries = sorted({p for folder in object_dirs for p in folder.rglob('*.lib')})
    library_providers = {symbol: [] for symbol in wanted}
    objects = sorted({p for folder in object_dirs for p in folder.rglob('*.obj')})
    for path in objects:
        try:
            data = path.read_bytes()
            candidates = {symbol for symbol, name in encoded.items() if name in data}
            if not candidates:
                continue
            definitions = {name for name, defined in rebuild.coff_externals(data).items() if defined}
        except (OSError, ValueError, IndexError, struct.error) as error:
            errors.append({'path': str(path), 'error': str(error)})
            continue
        for symbol in candidates.intersection(definitions):
            providers[symbol].append({'path': str(path), 'sha256': hashlib.sha256(data).hexdigest()})
    for path in libraries:
        try:
            library_hash = hashlib.sha256(path.read_bytes()).hexdigest()
            for member, data in libs.archive_members(path):
                candidates = {symbol for symbol, name in encoded.items() if name in data}
                if not candidates:
                    continue
                if data.startswith(b'\x00\x00\xff\xff'):
                    errors.append({'path': str(path), 'member': member, 'error': 'unsupported short import object'})
                    continue
                try:
                    definitions = {name for name, defined in rebuild.coff_externals(data).items() if defined}
                except (ValueError, IndexError, struct.error) as error:
                    errors.append({'path': str(path), 'member': member, 'error': str(error)})
                    continue
                for symbol in candidates.intersection(definitions):
                    library_providers[symbol].append({'path': str(path), 'member': member, 'sha256': library_hash,
                                                      'member_sha256': hashlib.sha256(data).hexdigest()})
        except (OSError, ValueError, libs.match.CompileError) as error:
            errors.append({'path': str(path), 'error': str(error)})
    # Index row patterns by class token, then scan each source line once.
    # Keep the original row/path/line order and exact-symbol priority.
    sources = sorted({p for folder in source_dirs for p in folder.rglob('*') if p.suffix in ('.cpp', '.h')})
    by_class, patterns, leads = {}, [], [[] for _ in rows]
    for i, row in enumerate(rows):
        terms = source_terms(row['display'])
        patterns.append([re.compile(r'\b' + re.escape(cls) + r'\s*(?:<[^;]*?>)?\s*::\s*' + re.escape(method) + r'\s*(?:<.*>)?\(') for cls, method in terms])
        for cls, method in terms:
            by_class.setdefault(cls, set()).add(i)
    bare_symbols = [(i, row['symbol']) for i, row in enumerate(rows) if '?' not in row['symbol']]
    for path in sources:
        for number, line in enumerate(path.read_text(encoding='utf-8-sig', errors='replace').splitlines(), 1):
            candidates = set()
            for token in re.findall(r'[A-Za-z_]\w*', line):
                candidates.update(by_class.get(token, ()))
            if '?' in line:
                candidates.update(i for i, row in enumerate(rows) if row['symbol'] in line)
            candidates.update(i for i, symbol in bare_symbols if symbol in line)
            for i in candidates:
                row = rows[i]
                exact = row['symbol'] in line
                if exact or any(pattern.search(line) for pattern in patterns[i]):
                    leads[i].append({'path': str(path), 'line': number,
                                     'evidence': 'symbol_text' if exact else 'qualified_member_text',
                                     'text': line.strip()[:240]})
    for i, row in enumerate(rows):
        row['object_definitions'] = providers[row['symbol']]
        row['library_definitions'] = library_providers[row['symbol']]
        row['source_leads'] = leads[i]
        row['status'] = 'object_definition_found' if row['object_definitions'] else 'library_definition_found' if row['library_definitions'] else 'source_lead_only' if leads[i] else 'no_provider_found'
        row['next_action'] = {
            'object_definition_found': 'Check source freshness, compile profile and link inclusion; do not auto-add object.',
            'library_definition_found': 'Check archive member selection, source freshness and ABI; do not auto-add library.',
            'source_lead_only': 'Inspect source lead; distinguish body from declaration/reference, then verify native compile.',
            'no_provider_found': 'Recover provider or expand scan scope; no definition found in scanned inputs.'
        }[row['status']]
    rows.sort(key=lambda row: (-len(row['requesters']), row['status'], row['symbol']))
    return {'scope': __doc__, 'log': str(log), 'log_sha256': hashlib.sha256(raw).hexdigest(),
            'object_dirs': [str(p) for p in object_dirs], 'source_dirs': [str(p) for p in source_dirs],
            'objects_scanned': len(objects), 'libraries_scanned': len(libraries), 'sources_scanned': len(sources), 'scan_errors': errors,
            'counts': dict(Counter(row['status'] for row in rows)), 'queue': rows}


def default_source_dirs(base):
    folders = [base / name for name in ('native-classes', 'native-headers', 'native-world', 'tests')]
    folders += [base / project / kind for project in ('App', 'Base', 'Network', 'Rendering', 'WindowsClient', 'Studio', 'Unclassified') for kind in ('src', 'include')]
    return [path for path in folders if path.is_dir()]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--log', type=Path, default=BASE / 'out/p6/native-doc-link.log')
    parser.add_argument('--object-dir', type=Path, action='append', help='repeatable object/library search directory; defaults to out/p6 and out/native-layouts')
    parser.add_argument('--source-dir', type=Path, action='append', help='repeatable; defaults to organized and legacy native source, headers and tests')
    parser.add_argument('--output', type=Path, default=ROOT / 'work/2008-06/shared-layouts/native-provider-queue.json')
    args = parser.parse_args()
    folders = args.object_dir or [BASE / 'out/p6', BASE / 'out/native-layouts']
    sources = args.source_dir or default_source_dirs(BASE)
    for path in [args.log, *folders, *sources]:
        if not path.exists():
            parser.error('missing input: ' + str(path))
    result = inventory(args.log.resolve(), [p.resolve() for p in folders], [p.resolve() for p in sources])
    if not result['queue']:
        parser.error('no supported unresolved-symbol lines found; check log format/link status')
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    print(f"{len(result['queue'])} blockers | {result['objects_scanned']} objects | {result['libraries_scanned']} libraries | {result['sources_scanned']} sources")
    print(result['counts'])
    for row in result['queue'][:12]:
        print(f"{len(row['requesters']):2} requesters | {row['status']} | {row['display']}")
    print(f"Scan errors: {len(result['scan_errors'])}; report: {args.output.resolve()}")


if __name__ == '__main__':
    main()
