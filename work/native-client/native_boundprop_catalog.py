"""Derive bounded real-header BoundProp probe candidates from one mined unit."""
import argparse
import json
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
UNIT = re.compile(r'unit:\s*(.+?)\s+size:', re.I)
PROP = re.compile(r'Reflection::BoundProp<\s*([^,>]+)\s*,\s*(\d+)\s*>')
CLASS_REF = re.compile(r'&?([A-Za-z_]\w*)::')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--addr', required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    addr = args.addr.lower().replace('0x', '').zfill(8)
    packet = (ROOT / 'src/2008-06' / (addr + '.cpp')).read_text(errors='replace')
    unit = UNIT.search(packet)
    if not unit or 'BoundPropGetSet' not in unit.group(1):
        raise SystemExit('packet is not a BoundPropGetSet candidate')
    prefix = unit.group(1).split('::?$BoundPropGetSet', 1)[0].split('::')[-1]
    owner = prefix[1:] if prefix.startswith('V') else prefix
    headers = ROOT / 'rebuild/2008-06/native-headers'
    alias_evidence = None
    if not re.match(r'^[A-Za-z_]\w*$', owner):
        token = re.search(r'\$1\?(s[A-Za-z_]\w*)', unit.group(1))
        aliases = []
        if token:
            for path in headers.rglob('*.h'):
                text = path.read_text(errors='replace')
                for value_type, alias in re.findall(r'\btypedef\s+Value<\s*([^,>]+)\s*,\s*' +
                                                    re.escape(token.group(1)) + r'\s*>\s*([A-Za-z_]\w*)\s*;', text):
                    aliases.append((path, alias, value_type))
        if len(aliases) != 1:
            result = {'addr': addr, 'mined_unit': unit.group(1), 'owner_token': prefix,
                      'status': 'blocked-template-owner-alias',
                      'reason': 'mangled template owner needs one real typedef/RTTI identity before class selection',
                      'candidates': []}
            args.output.parent.mkdir(parents=True, exist_ok=True)
            args.output.write_text(json.dumps(result, indent=1) + '\n', encoding='utf-8')
            print('owner-alias-blocked', prefix, 'output', args.output)
            return
        alias_header, owner, value_type = aliases[0]
        alias_evidence = {'header': alias_header.relative_to(headers).as_posix(),
                          'typedef_value_type': value_type, 'typedef_alias': owner}
    header_paths = ([alias_header] if alias_evidence else
                    [p for p in headers.rglob('*.h')
                     if re.search(r'\bclass\s+' + re.escape(owner) + r'\b', p.read_text(errors='replace'))])
    rows = []
    for source in (ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp'):
        source_text = source.read_text(errors='replace')
        included = set(re.findall(r'^\s*#\s*include\s+"([^"]+)"', source_text, re.M))
        source_headers = [header for header in header_paths
                          if header.relative_to(headers).as_posix() in included] or header_paths
        for line in source_text.splitlines():
            prop = PROP.search(line)
            if not prop or owner not in CLASS_REF.findall(line):
                continue
            prop_type, unknown = prop.groups()
            for header in source_headers:
                rows.append({'include': header.relative_to(headers).as_posix(),
                             'class': 'RBX::' + owner, 'prop_type': prop_type,
                             'unknown': int(unknown),
                             'native_source': source.relative_to(ROOT).as_posix()})
    rows = sorted({tuple(sorted(row.items())) for row in rows})
    rows = [dict(row) for row in rows]
    result = {'addr': addr, 'mined_unit': unit.group(1), 'owner_token': prefix,
              'owner': owner, 'candidates': rows,
              'scope': 'deterministic proposal only; compiler byte/data probe decides ownership'}
    if alias_evidence:
        result['alias_evidence'] = alias_evidence
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=1) + '\n', encoding='utf-8')
    print('owner', owner, 'candidates', len(rows), 'output', args.output)


if __name__ == '__main__':
    main()
