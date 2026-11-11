"""Small-first deterministic mined-to-native queue with no layout assumptions."""
import argparse
import ctypes
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT))
from roc.native_bulk import Targets
MINED = ROOT / 'src/2008-06'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
undname = ctypes.windll.dbghelp.UnDecorateSymbolName


def scope(symbol):
    out = ctypes.create_string_buffer(4096)
    if not undname(symbol.encode('latin1'), out, len(out), 0x1000):
        return ''
    name = out.value.decode('latin1')
    depth, cut = 0, -1
    for i, char in enumerate(name):
        depth += char == '<'
        depth -= char == '>'
        if depth == 0 and name.startswith('::', i):
            cut = i
    return name[:cut] if cut > 0 else ''


def static_or_free(symbol):
    # MSVC global/static member conventions.  Non-mangled C names are free too.
    return not symbol.startswith('?') or '@@Y' in symbol or '@@S' in symbol


def demangled(symbol):
    out = ctypes.create_string_buffer(4096)
    if not undname(symbol.encode('latin1'), out, len(out), 0x1000):
        return ''
    return out.value.decode('latin1')


def native_definitions():
    """Conservative source-definition index; calls alone never count as bodies."""
    text = {path: path.read_text(errors='replace') for path in CLASSES.rglob('*.cpp')}

    def namespace_free_definition(value, namespaces, method):
        """True only for a top-level free function in the exact namespace."""
        stack, pending = [], None
        bare = re.compile(r'^\s*(?:[\w:<>,~*&]+\s+)?' + re.escape(method) + r'\s*\(')
        for raw_line in value.splitlines():
            line = raw_line.split('//', 1)[0]
            if stack == namespaces and bare.search(line):
                return True
            for token in re.finditer(r'\bnamespace\s+([A-Za-z_]\w*)|[{}]', line):
                if token.group(1):
                    pending = token.group(1)
                elif token.group() == '{':
                    stack.append(pending)
                    pending = None
                elif stack:
                    stack.pop()
        return False

    def find(symbol):
        name = demangled(symbol)
        if '::' not in name or name.startswith('operator '):
            return []
        owner, method = name.rsplit('::', 1)
        # Definition lines begin with the qualified name; this intentionally
        # misses unusual syntax rather than mistaking a call for a body.
        # A method in nested namespaces is normally written with its class
        # qualifier only (`namespace RBX { Foo::method(...) }`).  Both forms
        # are definitions, while a bare method remains deliberately excluded.
        spellings = (owner + '::' + method, owner.rsplit('::', 1)[-1] + '::' + method)
        pattern = re.compile(r'^\s*(?:[\w:<>,~*&]+\s+)?(?:' + '|'.join(map(re.escape, spellings)) + r')\s*\(', re.M)
        direct = [str(path.relative_to(ROOT)).replace('\\', '/') for path, value in text.items() if pattern.search(value)]
        if direct or not static_or_free(symbol):
            return direct
        namespaces = owner.split('::')
        return [str(path.relative_to(ROOT)).replace('\\', '/') for path, value in text.items()
                if namespace_free_definition(value, namespaces, method)]
    return find


def native_exact():
    found = set()
    for report in HERE.glob('codex-native-recovery-report-v*.json'):
        for addr in json.loads(report.read_text()).get('byte_proved', {}).get('symbols', {}):
            found.add(addr.lower())
    for receipt in HERE.glob('claude-template-applied/*/applied*.json'):
        row = json.loads(receipt.read_text())
        if row.get('applied'):
            found.update(addr.lower() for addr in row.get('addresses', []))
    for receipt in HERE.glob('claude-profile-applied/*/applied.json'):
        row = json.loads(receipt.read_text())
        if row.get('applied'):
            found.update(addr.lower() for addr in row.get('addresses', []))
    for receipt in HERE.glob('contentprovider-native-provider/body-proof.json'):
        found.update(addr.lower() for addr in json.loads(receipt.read_text()).get('new_unique_addresses', []))
    # Phase-1 batch receipts contain named, reference-audited proof.  They must
    # be excluded on later queue passes just like promotion receipts.
    for receipt in HERE.glob('fieldless-phase*/bulk/manifest.json'):
        for family in json.loads(receipt.read_text()).get('families', []):
            for row in family.get('symbols', []):
                if row.get('status') == 'inactive_exact' and row.get('addr'):
                    found.add(row['addr'].lower())
    # Automatic promotion writes durable receipts under out/.  Destination
    # reproof, not isolated donor exactness, is the native-source criterion.
    for receipt in (ROOT / 'out').glob('native-autorecover*/result.json'):
        try:
            rows = json.loads(receipt.read_text()).get('rows', [])
        except (OSError, json.JSONDecodeError):
            continue
        for row in rows:
            proof = row.get('detail', {}).get('destination_reproof', {})
            if proof.get('passed'):
                found.update(addr.lower() for addr, status in proof.get('status', {}).items()
                             if status == 'inactive_exact')
    return found


def header_index():
    index = defaultdict(list)
    for path in HEADERS.rglob('*.h'):
        for name in set(re.findall(r'\b(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?(?:\w+\s+)?([A-Za-z_]\w*)\s*(?:[:{]|$)', path.read_text(errors='replace'), re.M)):
            index[name].append(str(path.relative_to(ROOT)).replace('\\', '/'))
    return index


def bucket(size):
    return '<=16' if size <= 16 else '17-64' if size <= 64 else '65-256' if size <= 256 else '>256'


def rel32_thunk(address, body):
    """A five-byte jump owns no recoverable C++ body; recover its callee."""
    if len(body) != 5 or body[0] != 0xe9:
        return ''
    return '%08x' % ((int(address, 16) + 5 + int.from_bytes(body[1:], 'little', signed=True)) & 0xffffffff)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--fieldless', type=Path, default=HERE / 'claude-fieldless.json')
    ap.add_argument('--closure', type=Path, default=HERE / 'claude-identity-closure.json')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    closure = {r['addr'].lower(): r for r in json.loads(args.closure.read_text())['bindings'] if r.get('function_start')}
    classified = {r['address'].lower(): r for r in json.loads(args.fieldless.read_text())['functions']}
    exact, headers, rows, definition_sources = native_exact(), header_index(), [], native_definitions()
    targets = Targets('2008-06')
    # Closure supplies all static/free candidates; fieldless evidence gates thiscall.
    for addr, binding in closure.items():
        packet = MINED / (addr + '.cpp')
        if not packet.is_file() or addr in exact:
            continue
        symbol = binding['symbol']
        field = classified.get(addr)
        free = static_or_free(symbol)
        if not free and (not field or field.get('verdict') != 'fieldless'):
            continue
        # Bound mangled symbol is primary owner evidence.  Fieldless scanner's
        # owner is only a fallback (it can inherit an ICF-folded sibling name).
        owner = scope(symbol) or (field.get('owner') if field else '')
        leaf = re.sub(r'<.*', '', owner).split('::')[-1]
        size = field.get('size') if field else None
        if size is None:
            try:
                target, _ = targets.body(addr)
            except (KeyError, ValueError):
                continue
            size = len(target)
        else:
            try:
                target, _ = targets.body(addr)
            except (KeyError, ValueError):
                continue
        thunk_target = rel32_thunk(addr, target)
        rows.append({'address': addr, 'symbol': symbol, 'owner': owner, 'size': size,
                     'bucket': bucket(size), 'kind': 'static-or-free' if free else 'fieldless-thiscall',
                     'fieldless': field.get('verdict') if field else None,
                     'thunk_target': thunk_target,
                     'headers': sorted(headers.get(leaf, [])),
                     'native_definition_sources': definition_sources(symbol),
                     'packet': str(packet.relative_to(ROOT)).replace('\\', '/')})
    rows.sort(key=lambda r: (r['size'], r['owner'], r['address']))
    by_owner, by_bucket = Counter(r['owner'] for r in rows), Counter(r['bucket'] for r in rows)
    out = {'scope': 'closure-bound mined packets; fieldless members plus static/free only; no source edits',
           'summary': {'queued': len(rows), 'attempted': 0, 'generated': 0, 'byte_proved': 0,
                       'reverted': {}, 'linked': 0, 'runtime_gated': 0,
                       'tiny_<=16': sum(r['size'] <= 16 for r in rows),
                       'rel32_thunks': sum(bool(r['thunk_target']) for r in rows),
                       'by_bucket': dict(by_bucket), 'owners': len(by_owner),
                       'with_header': sum(bool(r['headers']) for r in rows),
                       'without_header': sum(not r['headers'] for r in rows),
                       'already_native_defined': sum(bool(r['native_definition_sources']) for r in rows),
                       'needs_native_body': sum(not r['native_definition_sources'] for r in rows)},
           'by_owner': [{'owner': owner, 'functions': count} for owner, count in by_owner.most_common()],
           'rows': rows}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))


if __name__ == '__main__':
    main()
