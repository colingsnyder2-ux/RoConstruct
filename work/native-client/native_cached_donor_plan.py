"""Make a promotable plan from one cached, real VS2008 donor object.

The object supplies exact bytes and decorated symbols.  A fieldless/static
queue row supplies target ownership plus its sole real native header.  This
tool only writes a plan: native_autorecover recompiles the source and repeats
all ordinary byte/reference/provider/layout gates before any source write.
"""
import argparse
import ctypes
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match
from roc.native_bulk import Targets

UNDNAME_NAME_ONLY = 0x1000
undname = ctypes.windll.dbghelp.UnDecorateSymbolName


def undecorate(symbol):
    buf = ctypes.create_string_buffer(4096)
    return buf.value.decode('latin1') if undname(symbol.encode('latin1'), buf, len(buf), UNDNAME_NAME_ONLY) else ''


def method_marker(symbol):
    name = undecorate(symbol)
    if '::' not in name:
        return ''
    return name.rsplit('::', 1)[0].rsplit('::', 1)[-1] + '::' + name.rsplit('::', 1)[1].split('(', 1)[0]


def exact_symbols(obj):
    targets, out = Targets('2008-06'), {}
    raw = obj.read_bytes()
    for symbol, body, relocs in match.coff_functions(raw):
        for addr in targets.candidates(body, relocs):
            try:
                target, original = targets.body(addr)
            except (KeyError, ValueError, SystemExit):
                continue
            if len(target) == len(body) and set(original) <= set(relocs) and match.exact_match(target, original, body, relocs):
                out.setdefault(symbol, set()).add(addr.lower())
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--queue', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--object', type=Path, required=True)
    ap.add_argument('--source', type=Path, required=True)
    ap.add_argument('--header', required=True)
    ap.add_argument('--destination', required=True)
    ap.add_argument('--flags', required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    header = args.header.replace('\\', '/')
    queue = json.loads(args.queue.read_text())['rows']
    closure = {row['symbol']: row for row in json.loads(args.closure.read_text())['bindings']}
    exact = exact_symbols(args.object.resolve())
    selected, blocked = [], []
    text = args.source.resolve().read_text(errors='replace')
    for row in sorted(queue, key=lambda value: value['address']):
        symbol, addr = row['symbol'], row['address'].lower()
        if addr not in exact.get(symbol, ()):
            continue
        if closure.get(symbol, {}).get('addr', '').lower() != addr or not closure[symbol].get('body_exact'):
            blocked.append({'addr': addr, 'symbol': symbol, 'reason': 'closure does not independently bind exact body'})
            continue
        if row.get('native_definition_sources'):
            blocked.append({'addr': addr, 'symbol': symbol, 'reason': 'native provider already exists'})
            continue
        if row.get('kind') != 'static-or-free' and row.get('fieldless') != 'fieldless':
            blocked.append({'addr': addr, 'symbol': symbol, 'reason': 'member touches fields'})
            continue
        if row.get('headers') != [header]:
            blocked.append({'addr': addr, 'symbol': symbol, 'reason': 'not one selected native header'})
            continue
        marker = method_marker(symbol)
        if not marker or not re.search(r'\b' + re.escape(marker) + r'\s*\(', text):
            blocked.append({'addr': addr, 'symbol': symbol, 'reason': 'real source marker absent'})
            continue
        selected.append({'addr': addr, 'symbol': symbol, 'marker': marker,
                         'header': header, 'namespace': '', 'roc_cl': 21022, 'roc_flags': args.flags,
                         'evidence': 'cached real VS2008 object exact + closure unique binding'})
    owner = selected[0]['marker'].rsplit('::', 1)[0] if selected else ''
    plan = {'scope': __doc__.splitlines()[0], 'source_object': str(args.object),
            'summary': {'exact_object_symbols': sum(len(v) for v in exact.values()),
                        'selected': len(selected), 'blocked': len(blocked)}, 'plans': [], 'blocked': blocked}
    if selected:
        plan['plans'] = [{'owner': owner, 'headers': [header], 'source': str(args.source).replace('\\', '/'),
                          'namespace': '', 'roc_cl': 21022, 'roc_flags': args.flags,
                          'destination': args.destination.replace('\\', '/'),
                          'probe_records': [row['addr'] + '=' + row['marker'] + '#0' for row in selected],
                          'rows': selected}]
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(plan, indent=1) + '\n')
    print(json.dumps(plan['summary']))


if __name__ == '__main__':
    main()
