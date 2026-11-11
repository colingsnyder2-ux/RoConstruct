"""Read-only inventory for deterministic native class recovery.

It never promotes mined ownership into a header declaration.  It only records
explicit C++ qualifiers already present in native or mined source, so the next
recovery stage can select an existing class family without duplicating it.
"""
import argparse
import json
import re
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
NATIVE = ROOT / 'rebuild' / '2008-06' / 'native-classes'
HEADERS = ROOT / 'rebuild' / '2008-06' / 'native-headers'
MINED = ROOT / 'src' / '2008-06'
QUALIFIED = re.compile(r'\b(?:(?:[A-Za-z_]\w*)::)*([A-Za-z_]\w*)::[~A-Za-z_]\w*\s*\(')
METHOD_DEF = re.compile(r'(?m)^\s*(?:[\w:<>,~*&]+\s+)+(?:(?:[A-Za-z_]\w*)::)*([A-Za-z_]\w*)::[~A-Za-z_]\w*\s*\([^;{}]*\)\s*(?:const\s*)?\{')
UNIT = re.compile(r'^// roc 2008-06 ([0-9a-f]{8})\s+unit:\s*(.*?)\s+size:', re.M)
CLASS = re.compile(r'\bclass\s+([A-Za-z_]\w*)\b')
TYPE_DECL = re.compile(r'(?m)^\s*(?:struct|class)\s+([A-Za-z_]\w*)\b')
NATIVE_INCLUDE = re.compile(r'(?m)^\s*#include\s+["<][^">]*(?:native-headers|v8datamodel|ViewNew|RenderLib|Network)')


def names(path):
    return sorted(set(METHOD_DEF.findall(path.read_text(errors='replace'))))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    native = defaultdict(list)
    for path in NATIVE.rglob('*.cpp'):
        for name in names(path):
            native[name].append(str(path.relative_to(ROOT)).replace('\\', '/'))
    headers = defaultdict(list)
    for path in HEADERS.rglob('*'):
        if path.is_file() and path.suffix in ('.h', '.hpp'):
            for name in CLASS.findall(path.read_text(errors='replace')):
                headers[name].append(str(path.relative_to(ROOT)).replace('\\', '/'))
    units = []
    for path in MINED.glob('*.cpp'):
        text = path.read_text(errors='replace')
        hit = UNIT.search(text)
        if not hit:
            continue
        owners = names(path)
        declared = sorted(set(TYPE_DECL.findall(text)))
        units.append({'addr': hit.group(1), 'unit': hit.group(2),
                      'qualified_candidates': owners,
                      'local_type_declarations': declared,
                      'local_owner_declarations': sorted(set(owners) & set(declared)),
                      'has_native_header_include': bool(NATIVE_INCLUDE.search(text)),
                      'mined_body': (not re.search(r'^// roc-lib:', text, re.M) or
                                     any(line.strip() and not line.lstrip().startswith(('#', '//'))
                                         for line in re.sub(r'^// roc-lib:.*\n', '', text, flags=re.M).splitlines()))})
    groups = defaultdict(list)
    known = set(native) | set(headers)
    blocked = []
    for unit in units:
        if not unit['mined_body']:
            blocked.append({'addr': unit['addr'], 'reason': 'vendor replay-only packet'})
            continue
        owners = sorted(set(unit['qualified_candidates']) & known)
        if not owners:
            blocked.append({'addr': unit['addr'], 'reason': 'no existing native/header owner in explicit source qualifier'})
            continue
        for owner in owners:
            groups[owner].append(unit['addr'])
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps({'native_methods': native, 'header_classes': headers,
                                       'mined_units': units,
                                       'candidate_groups': {k: sorted(set(v)) for k, v in groups.items()},
                                       'blocked': blocked},
                                 indent=1, sort_keys=True) + '\n')
    print('native-class-owners', len(native), 'header-class-names', len(headers),
          'mined-units', len(units), 'candidate-groups', len(groups), 'blocked', len(blocked))


if __name__ == '__main__':
    main()
