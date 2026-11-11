"""Gate mined bodies using deterministic closure-bound real symbol identities."""
import argparse
import json
import re
from pathlib import Path
from native_conversion_queue import undecorate


ROOT = Path(__file__).resolve().parents[2]
METHOD = re.compile(r'\b([A-Za-z_]\w*)::([~A-Za-z_]\w*)\s*\(')
DECL_METHOD = re.compile(r'\b([A-Za-z_]\w*)::([~A-Za-z_]\w*)\s*\(')
LIBRARY_MEMBER = re.compile(r'^// library .*\(function \?([A-Za-z_]\w*)@([A-Za-z_]\w*)@@', re.M)


def declared_members(header, owner):
    text = (ROOT / header).read_text(errors='replace')
    return set(re.findall(r'\b([~A-Za-z_]\w*)\s*\(', text))


def defines_owner(header, owner):
    """Selected header must contain a complete owner, not only a forward decl."""
    text = (ROOT / header).read_text(errors='replace')
    short = owner.rsplit('::', 1)[-1]
    # Export/deprecation macros may sit between `class` and its actual name
    # (`class RAK_DLL_EXPORT RakPeer`).  Stop at a semicolon so a forward
    # declaration cannot bleed into a later class body.
    return bool(re.search(r'\b(?:class|struct)\b[^;{]*\b' + re.escape(short) + r'\b[^;{]*\{', text, re.S))


def virtual_address_alias(header, addr):
    """Real header's annotated virtual slot already owns this target address."""
    for line in (ROOT / header).read_text(errors='replace').splitlines():
        if addr.lower() in line.lower() and re.search(r'\bvirtual\b', line):
            match = re.search(r'\b([~A-Za-z_]\w*)\s*\(', line)
            if match:
                return match.group(1)
    return None


def native_method_providers():
    providers = set()
    for path in (ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp'):
        text = path.read_text(errors='replace')
        providers.update(METHOD.findall(text))
    return providers


def direct_bases(header, owner):
    """Named direct bases from the selected real header, selection evidence only."""
    text = (ROOT / header).read_text(errors='replace')
    short = owner.rsplit('::', 1)[-1]
    match = re.search(r'\b(?:class|struct)\b[^;{]*\b' + re.escape(short) + r'\b[^;{]*:\s*([^\{;]+)\{', text, re.S)
    if not match:
        return set()
    return set(re.findall(r'\b(?:public|protected|private)\s+(?:[A-Za-z_]\w*::)*([A-Za-z_]\w*)', match.group(1)))


def symbol_method_owner(symbol):
    match = DECL_METHOD.search(undecorate(symbol))
    return match.groups() if match else None


def bound_methods(queue):
    rows = []
    for group in queue['classes']:
        for method in group['methods']:
            if method['state'] != 'convert':
                continue
            match = DECL_METHOD.search(method['declaration'])
            if not match:
                continue
            owner, name = match.groups()
            rows.append({'addr': method['addr'], 'symbol': method['symbol'],
                         'declaration': method['declaration'], 'owner': owner, 'method': name,
                         'headers': group['headers'], 'votes': method['votes'],
                         'evidence': method['evidence']})
    return rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--inventory', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--queue', type=Path, required=True)
    ap.add_argument('--memfn', type=Path)
    ap.add_argument('--eh-types', type=Path)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    inv = json.loads(args.inventory.read_text())
    closure = json.loads(args.closure.read_text())
    queue = json.loads(args.queue.read_text())
    memfn = {row['address']: row for row in json.loads(args.memfn.read_text()).get('functions', [])} if args.memfn else {}
    eh_types = {row['function']: row for row in json.loads(args.eh_types.read_text()).get('functions', [])} if args.eh_types else {}
    bound = {row['addr']: row for row in closure['bindings']}
    aliases = {}
    for binding in closure['bindings']:
        decoded = symbol_method_owner(binding['symbol'])
        if decoded:
            aliases.setdefault(binding['addr'], []).append(decoded)
    units = {row['addr']: row for row in inv['mined_units']}
    providers = native_method_providers()
    rows = []
    for method in bound_methods(queue):
        addr = method['addr']
        unit = units.get(addr)
        if not unit or not (ROOT / 'src/2008-06' / (addr + '.cpp')).is_file() or addr not in bound:
            continue
        owner_headers = sorted(set(method['headers']))
        known = set().union(*(declared_members(path, method['owner']) for path in owner_headers)) if owner_headers else set()
        complete = defines_owner(owner_headers[0], method['owner']) if len(owner_headers) == 1 else False
        bases = direct_bases(owner_headers[0], method['owner']) if len(owner_headers) == 1 else set()
        packet = (ROOT / 'src/2008-06' / (addr + '.cpp')).read_text(errors='replace')
        packet_base = LIBRARY_MEMBER.search(packet)
        inherited = any(name == method['method'] and owner in bases for owner, name in aliases.get(addr, [])) or \
            bool(packet_base and packet_base.group(1) == method['method'] and packet_base.group(2) in bases)
        address_alias = virtual_address_alias(owner_headers[0], addr) if len(owner_headers) == 1 else None
        if inherited:
            status, reason = 'blocked-inherited-alias', 'same target is a proven direct-base virtual; no derived override declaration'
        elif address_alias and address_alias != method['method']:
            status, reason = 'blocked-header-address-alias', \
                'single real header already declares this virtual target address as ' + address_alias
        elif (method['owner'], method['method']) in providers:
            status, reason = 'profile-sweep', 'native class source defines real member; compile profile/body must be byte-proved'
        elif not owner_headers:
            status, reason = 'blocked-no-real-header', 'closure-bound method has no real native header'
        elif len(owner_headers) != 1:
            status, reason = 'blocked-ambiguous-header', 'closure-bound owner has multiple candidate headers'
        elif not complete:
            status, reason = 'blocked-incomplete-class', 'selected header declares member but does not define owner layout'
        elif method['method'] not in known:
            status, reason = 'blocked-header-declaration', 'single real header does not declare closure-bound member name'
        else:
            status, reason = 'convert-ready', 'closure-bound symbol, one real declaring header, no native member body'
        row = dict(method, unit=unit['unit'], headers=owner_headers, status=status, reason=reason,
                         calling_convention=re.search(r'__(?:thiscall|cdecl|stdcall|fastcall)', method['declaration']).group(0)
                         if re.search(r'__(?:thiscall|cdecl|stdcall|fastcall)', method['declaration']) else None)
        if addr in memfn and memfn[addr].get('consistent'):
            row['memfn_evidence'] = {'owner': memfn[addr].get('owner'),
                                     'signatures': memfn[addr].get('signatures', []),
                                     'const': all(item.get('const') for item in memfn[addr].get('evidence', []))}
        if addr in eh_types:
            row['eh_local_types'] = eh_types[addr].get('local_destructors', [])
            row['eh_catch_types'] = eh_types[addr].get('catch_types', [])
        rows.append(row)
    rows.sort(key=lambda row: (row['status'], row['owner'], row['addr'], row['method']))
    out = {'scope': 'closure-bound symbol identity only; source/header promotion still needs real-type compile proof',
           'closure': str(args.closure), 'queue': str(args.queue),
           'summary': {status: sum(row['status'] == status for row in rows)
                       for status in sorted(set(row['status'] for row in rows))},
           'rows': rows}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print('methods', len(rows), 'convert-ready', out['summary'].get('convert-ready', 0),
          'profile-sweep', out['summary'].get('profile-sweep', 0))


if __name__ == '__main__':
    main()
