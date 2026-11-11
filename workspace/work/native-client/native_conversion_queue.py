"""Group proven symbol identities by real owner class into a conversion queue.

Input: identity-closure.json.  Read-only; generates no source.  Each row is a
function address whose mangled name (owner, signature, calling convention) is
bound by compiled real-header evidence.  State per row:

  existing-native        a textual native-class definition exists
  existing-emitted-exact a supplied native-class proof object emits the exact symbol body
  existing-emitted-address-exact an exact native source body occupies this target address,
                               but its supplied symbol has not yet been reconciled with this
                               closure symbol
  existing-header-exact  a real native header inline was independently emitted and exact
  convert        name proven, no exact native body yet, mined packet exists
  name-only      name proven, no native body and no mined packet
"""
import argparse
import ctypes
import json
import re
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MINED = ROOT / 'src' / '2008-06'
HEADERS = ROOT / 'rebuild' / '2008-06' / 'native-headers'
CLASSES = ROOT / 'rebuild' / '2008-06' / 'native-classes'
_undname = ctypes.windll.dbghelp.UnDecorateSymbolName


def undecorate(symbol, flags=0):
    buffer = ctypes.create_string_buffer(4096)
    return buffer.value.decode('latin-1') if _undname(symbol.encode('latin-1'), buffer, 4096, flags) else symbol


def owner(symbol):
    """Qualified scope of a C++ member/function name; '' for C symbols and globals."""
    name = undecorate(symbol, 0x1000)  # UNDNAME_NAME_ONLY
    if name == symbol:
        return ''
    depth, cut = 0, -1
    for i, ch in enumerate(name):
        depth += ch == '<'
        depth -= ch == '>'
        if depth == 0 and name.startswith('::', i):
            cut = i
    return name[:cut] if cut > 0 else ''


def native_definition_index():
    """Existing source definitions only; closure body identity is not integration."""
    definitions = defaultdict(list)
    # Build once.  The old per-symbol, per-file regex made a closure refresh
    # quadratic (32k symbols x 700+ sources).
    # Return types such as ``const String&`` contain spaces, and nested
    # members have more than one qualifier.  Index the final owner qualifier
    # rather than treating those already-defined native methods as convert
    # candidates.  This stays line-anchored and scans native .cpp only.
    pattern = re.compile(
        r'^[ \t]*(?:[^;{}()\n]*?[ \t]+)?((?:[A-Za-z_]\w*::)+)([~A-Za-z_]\w*)\s*\(', re.M)

    def compiled_text(text):
        """Do not report explicitly pending bodies as native providers."""
        kept, pending = [], 0
        for line in text.splitlines(True):
            if re.match(r'\s*#\s*ifdef\s+NATIVE_.*_PENDING\b', line):
                pending += 1
                continue
            if pending and re.match(r'\s*#\s*endif\b', line):
                pending -= 1
                continue
            if not pending:
                kept.append(line)
        return ''.join(kept)

    for path in CLASSES.glob('*.cpp'):
        relative = str(path.relative_to(ROOT)).replace('\\', '/')
        for match in pattern.finditer(compiled_text(path.read_text(errors='replace'))):
            leaf = match.group(1).rstrip(':').rsplit('::', 1)[-1]
            definitions[(leaf, match.group(2))].append(relative)

    def find(symbol):
        scope = owner(symbol)
        if not scope:
            return []
        name = undecorate(symbol, 0x1000)
        if '::' not in name:
            return []
        method = name.rsplit('::', 1)[1].split('(', 1)[0]
        return definitions.get((scope.rsplit('::', 1)[-1], method), [])
    return find


def header_inline_index(header_text):
    """Index only actual inline definitions; declarations never count as bodies."""
    indexed = defaultdict(list)
    pattern = re.compile(
        r'\bvirtual\s+(?:[^;{}()]+?)\s+([~A-Za-z_]\w*)\s*\([^{}()]*\)\s*'
        r'(?:const\s*)?\{', re.M)
    for path, text in header_text.items():
        for class_match in re.finditer(r'\bclass\s+(?:[A-Za-z_]\w*\s+)*?([A-Za-z_]\w*)\b[^{};]*\{', text):
            depth, end = 1, class_match.end()
            while depth and end < len(text):
                depth += text[end] == '{'
                depth -= text[end] == '}'
                end += 1
            if depth:
                continue
            for match in pattern.finditer(text, class_match.end(), end):
                indexed[(class_match.group(1), match.group(1))].append(path)

    def find(symbol):
        scope = owner(symbol)
        if not scope:
            return []
        name = undecorate(symbol, 0x1000)
        if '::' not in name:
            return []
        return indexed.get((scope.rsplit('::', 1)[-1], name.rsplit('::', 1)[1].split('(', 1)[0]), [])
    return find


def exact_symbols_from_ledgers(paths):
    """Only accept native-bulk receipts; synthetic probe code itself proves nothing."""
    exact = set()
    for path in paths:
        ledger = json.loads(path.read_text())
        for receipt in ledger.values():
            for row in receipt.get('harvest_rows', []):
                if row.get('status') == 'inactive_exact':
                    exact.add(row['symbol'])
    return exact


def exact_addresses_from_ledgers(paths):
    """Exact native source addresses, kept distinct from decorated-symbol identity.

    A virtual override can have a real source symbol while an older closure labels
    the same address as an inherited base member.  Do not silently call that a
    symbol proof: surface it as its own queue state so the converter neither
    retransplants an already-native body nor invents an alias.
    """
    exact = set()
    for path in paths:
        ledger = json.loads(path.read_text())
        for receipt in ledger.values():
            for row in receipt.get('harvest_rows', []):
                if row.get('status') == 'inactive_exact' and row.get('addr'):
                    exact.add(row['addr'].lower())
    return exact


def namespace_matches(header_text, scope):
    """Reject same short class names from a different namespace/provider."""
    if '::' not in scope:
        return True
    namespace = scope.rsplit('::', 1)[0]
    return all(re.search(r'\bnamespace\s+' + re.escape(part) + r'\b', header_text)
               for part in namespace.split('::'))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--inline-proof', type=Path, action='append', default=[],
                    help='native-bulk ledger proving header inline body emission')
    ap.add_argument('--emitted-proof', type=Path, action='append', default=[],
                    help='native-bulk ledger from an existing native-class source batch')
    args = ap.parse_args()
    closure = json.loads(args.closure.read_text())
    header_text = {str(p.relative_to(ROOT)).replace('\\', '/'): p.read_text(errors='replace')
                   for p in HEADERS.rglob('*.h')}
    declared = defaultdict(list)
    for path, text in header_text.items():
        for name in set(re.findall(r'\b(?:class|struct)\s+(?:\w+\s+)?([A-Za-z_]\w*)\s*(?:[:{]|$)', text, re.M)):
            declared[name].append(path)
    classes = defaultdict(list)
    native_definition = native_definition_index()
    header_inline = header_inline_index(header_text)
    inline_exact = exact_symbols_from_ledgers(args.inline_proof)
    emitted_exact = exact_symbols_from_ledgers(args.emitted_proof)
    emitted_addresses = exact_addresses_from_ledgers(args.emitted_proof)
    for row in closure['bindings']:
        if not row['function_start']:
            continue
        scope = owner(row['symbol'])
        leaf = re.sub(r'<.*', '', scope).split('::')[-1]
        matching_headers = [path for path in declared.get(leaf, [])
                            if namespace_matches(header_text[path], scope)]
        mined = (MINED / (row['addr'] + '.cpp')).is_file()
        providers = native_definition(row['symbol'])
        inline_providers = header_inline(row['symbol']) if row['symbol'] in inline_exact else []
        # A closure body_exact row proves an object body, possibly a real donor
        # object.  It does not prove that body lives in native-classes.
        state = ('existing-native' if providers else 'existing-emitted-exact' if row['symbol'] in emitted_exact
                 else 'existing-emitted-address-exact' if row['addr'].lower() in emitted_addresses
                 else 'existing-header-exact' if inline_providers
                 else 'convert' if mined else 'name-only')
        classes[scope].append({'addr': row['addr'], 'symbol': row['symbol'],
                               'declaration': undecorate(row['symbol']), 'state': state,
                               'identity_body_exact': row['body_exact'], 'native_providers': providers,
                               'header_inline_providers': inline_providers,
                               'emitted_proof': row['symbol'] in emitted_exact,
                               'emitted_address_proof': row['addr'].lower() in emitted_addresses,
                               'headers': matching_headers, 'evidence': row['evidence'], 'votes': row['votes']})
    out_classes = []
    for scope, rows in classes.items():
        leaf = re.sub(r'<.*', '', scope).split('::')[-1]
        headers = sorted({header for row in rows for header in row['headers']})
        out_classes.append({'owner': scope, 'template': '<' in scope,
                            'headers': headers,
                            'counts': dict(Counter(r['state'] for r in rows)),
                            'methods': sorted(rows, key=lambda r: r['addr'])})
    out_classes.sort(key=lambda c: -c['counts'].get('convert', 0))
    total = Counter(r['state'] for c in out_classes for r in c['methods'])
    out = {'scope': 'identity-proven conversion queue; no source generated, no layout/link/runtime proof',
           'summary': {'owners': len(out_classes), **total,
                       'convert_with_unique_header': sum(c['counts'].get('convert', 0) for c in out_classes
                                                         if len(c['headers']) == 1),
                       'convert_template_owner': sum(c['counts'].get('convert', 0) for c in out_classes
                                                     if c['template'])},
           'classes': out_classes}
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))
    for c in out_classes[:25]:
        print(c['counts'].get('convert', 0), c['owner'][:90], c['headers'][:1])


if __name__ == '__main__':
    main()
