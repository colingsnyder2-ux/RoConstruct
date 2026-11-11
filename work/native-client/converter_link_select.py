"""Select audited converter objects for linkprobe; compilation success is not selection proof."""
import argparse
import hashlib
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
OGRE = HERE / 'ogre'
sys.path[:0] = [str(ROOT), str(HERE), str(OGRE)]
from roc import fingerprint, match
from roc import rebuild
import ogre_convert as conv


def load_symcheck():
    namespace = {}
    text = (ROOT / 'work/rbxgs-rebase/symcheck.py').read_text()
    exec(text.split('\nobjs = ', 1)[0], namespace)
    return namespace['symbols']


def reports(scope):
    root = OGRE / 'batches' if scope == 'all' else OGRE / 'batches' / scope
    newest = {}
    for report_path in root.glob('*/*/link/ogre_convert.json' if scope == 'all' else '*/link/ogre_convert.json'):
        try:
            rows = json.loads(report_path.read_text())
        except ValueError:
            continue
        for addr, row in rows.items():
            if row.get('status') != 'renamed':
                continue
            obj = report_path.parents[1] / 'renamed' / (addr + '.obj')
            if obj.is_file() and (addr not in newest or obj.stat().st_mtime_ns > newest[addr][0].stat().st_mtime_ns):
                newest[addr] = (obj, row)
    return newest


def typed_data(symbols, output, mode):
    """Compile every currently unresolved, already typed data definition once."""
    registry = conv.load_registry()
    names = {r['name']: a for a, r in registry.items() if not r.get('placeholder') and r['kind'] == 'data'}
    # Never overwrite selected scalar provider while trialing broader data.
    if mode == 'scalars':
        folder = HERE / 'link' / 'typed-scalars'
    else:
        # A selected receipt owns its object forever; a later batch must never
        # silently replace it with a different set of definitions.
        folder = HERE / 'link' / ('typed-data' if mode == 'link' else 'typed-data-coverage') / output.stem
    folder.mkdir(parents=True, exist_ok=True)
    definitions, bindings = [], []
    for symbol in sorted(symbols):
        addr = names.get(symbol)
        # Class/table/array types stay parked. data_def accepts only independently
        # typed scalars, printable const strings, and null pointers/zero-fill data.
        if not addr or (mode == 'scalars' and not conv.re.search(r'@@[23](?:C|D|E|F|G|H|I|J|K|M|N|_N|_J|_K)[AB]$', symbol)):
            continue
        definition = conv.data_def(int(addr, 16), symbol)
        if definition:
            definitions.append(definition)
            bindings.append({'symbol': symbol, 'address': addr, 'kind': 'data',
                             'bytes': conv.DATA_SIZES[int(addr, 16)]})
    if not definitions:
        output.write_text(json.dumps({'selected': [], 'reason': 'no proved scalar candidates'}, indent=1))
        return
    source, obj = folder / 'scalars.cpp', folder / 'scalars.obj'
    source.write_text('// Typed data definitions; each value independently re-proved against original.\n' + '\n'.join(definitions) + '\n')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', ['/nologo', '/c', '/O2', '/GS-', '/Fo' + str(obj), str(source)], folder)
    if code:
        raise RuntimeError(log[-3000:])
    raw = obj.read_bytes()
    for row in bindings:
        if not conv.data_proved(raw, '_roc_data_' + row['address'], int(row['address'], 16), row['bytes']):
            raise RuntimeError('typed scalar proof failed: ' + row['address'])
    mapping = {i: next(r['symbol'] for r in bindings if name == '_roc_data_' + r['address'])
               for i, name, sec, cls, val in conv.r1.symtab(raw)[0]
               if any(name == '_roc_data_' + r['address'] for r in bindings)}
    raw = conv.r1.rename(raw, mapping)
    for row in bindings:
        if not conv.data_proved(raw, row['symbol'], int(row['address'], 16), row['bytes']):
            raise RuntimeError('renamed scalar proof failed: ' + row['address'])
    obj.write_bytes(raw)
    section_bytes = {'.data': 0, '.rdata': 0}
    for row in bindings:
        section = conv.data_section(int(row['address'], 16))[0]
        if section in section_bytes:
            section_bytes[section] += row['bytes']
    receipt = {'selected': [{'source': 'typed-' + mode, 'object': obj.relative_to(ROOT).as_posix(), 'symbols': bindings}],
               'proved_data_bytes': sum(r['bytes'] for r in bindings),
               'covered_bytes_by_section': section_bytes,
               'scope': 'typed scalar source, exact data, no relocations' if mode == 'scalars' else 'typed data source, exact bytes or zero-filled BSS',
               'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
               'object_sha256': hashlib.sha256(raw).hexdigest(),
               'registry_sha256': hashlib.sha256((ROOT / 'work/2008-06/identity-registry.json').read_bytes()).hexdigest()}
    output.write_text(json.dumps(receipt, indent=1) + '\n')
    print(json.dumps({'typed_symbols': len(bindings), 'data_bytes': receipt['proved_data_bytes']}))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--scope', default='RBX', help='batch scope tag, or all for cross-subsystem provider audit')
    ap.add_argument('--output', type=Path, default=HERE / 'link' / 'selected-converter.json')
    ap.add_argument('--unresolved', type=Path, default=HERE / 'link' / 'probe.json')
    ap.add_argument('--limit', type=int, default=20)
    ap.add_argument('--typed-scalars', action='store_true')
    ap.add_argument('--typed-data', action='store_true', help='include supported strings and null/zero-fill pointers')
    ap.add_argument('--all-typed-data', action='store_true', help='unlinked coverage batch for every supported named data row')
    args = ap.parse_args()
    if args.limit < 1:
        ap.error('--limit must be positive')
    symbols = load_symcheck()
    conv.TARGET = fingerprint.Target('2008-06')
    conv.TARGET.index = {}
    conv.BASE, conv.IMAGE = match._image('2008-06')
    funcs = match._functions('2008-06')
    unresolved = set(json.loads(args.unresolved.read_text()).get('unresolved', [])) if args.unresolved.is_file() else set()
    if sum((args.typed_scalars, args.typed_data, args.all_typed_data)) > 1:
        ap.error('choose one typed-data mode')
    if args.typed_scalars or args.typed_data or args.all_typed_data:
        if args.all_typed_data:
            registry = conv.load_registry()
            symbols = {row['name'] for row in registry.values() if not row.get('placeholder') and row['kind'] == 'data'}
            mode = 'coverage'
        else:
            symbols = unresolved
            mode = 'scalars' if args.typed_scalars else 'link'
        typed_data(symbols, args.output, mode)
        return
    policy_cache = {}
    selected, rejected, used_symbols = [], [], set()
    rows = reports(args.scope)
    ranked = sorted(rows, key=lambda addr: (-funcs.get(addr, {}).get('size', 0), addr))
    for addr in ranked:
        if len(selected) >= args.limit:
            break
        obj, row = rows[addr]
        source = ROOT / 'src/2008-06' / (addr + '.cpp')
        if not source.is_file() or addr not in funcs:
            rejected.append({'address': addr, 'reason': 'source-or-target-missing'})
            continue
        text = source.read_text(errors='replace')
        if text not in policy_cache:
            policy_cache[text] = conv.effective_source_policy(text)
        policy = policy_cache[text]
        if policy:
            rejected.append({'address': addr, 'reason': 'source-policy', 'why': policy})
            continue
        symbol = row.get('symbol')
        if symbol not in unresolved:
            rejected.append({'address': addr, 'reason': 'not-currently-unresolved', 'symbol': symbol})
            continue
        extent = row.get('extent') or {}
        size = extent.get('new', funcs[addr]['size'])
        hit = conv.output_body(obj.read_bytes(), symbol, size) if symbol else None
        if not hit or conv.proof_same(addr, hit[0], hit[1]) is None:
            rejected.append({'address': addr, 'reason': 'body-reproof-failed'})
            continue
        defs = {name for name, kind in symbols(obj.read_bytes()).items() if kind != 'undef'}
        extra = sorted(defs - {symbol})
        if extra:
            rejected.append({'address': addr, 'reason': 'extra-defined-symbols', 'symbols': extra[:8]})
            continue
        if symbol in used_symbols:
            rejected.append({'address': addr, 'reason': 'duplicate-provider-symbol', 'symbol': symbol})
            continue
        used_symbols.add(symbol)
        selected.append({'source': 'converter:' + addr,
                         'object': str(obj.relative_to(ROOT)).replace('\\', '/'),
                         'symbols': [{'symbol': symbol, 'address': addr}],
                         'code_bytes': funcs[addr]['size']})
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps({'selected': selected, 'rejected': rejected,
                                       'scope': 'reproved target body + source policy + single defined symbol'}, indent=1) + '\n')
    print(json.dumps({'selected': len(selected), 'code_bytes': sum(x['code_bytes'] for x in selected),
                      'rejected': len(rejected)}))


if __name__ == '__main__':
    main()
