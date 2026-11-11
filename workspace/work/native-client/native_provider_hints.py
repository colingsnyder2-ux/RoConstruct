"""Map compiler-missing type names to existing native declaration providers."""
import argparse
import json
import re
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
MISSING = re.compile(r"(?:error C2065: '([^']+)'|undefined (?:class|struct) '([^']+)')")


def index_headers():
    index = defaultdict(list)
    for path in HEADERS.rglob('*.h'):
        text = path.read_text(errors='replace')
        for name in set(re.findall(r'\b(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?(?:\w+\s+)?([A-Za-z_]\w*)\s*(?:[:{])', text)):
            index[name].append(str(path.relative_to(ROOT)).replace('\\', '/'))
    return index


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--log', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    names = []
    for left, right in MISSING.findall(args.log.read_text(errors='replace')):
        name = left or right
        # C2065 also cascades to local variable names.  Header providers only
        # make sense for C++ type/namespace spelling.
        if name and name[0].isupper() and name not in names:
            names.append(name)
    index = index_headers()
    rows = []
    for name in names:
        providers = sorted(index.get(name.rsplit('::', 1)[-1], []))
        rows.append({'name': name, 'providers': providers,
                     'status': 'unique' if len(providers) == 1 else
                               'ambiguous' if providers else 'missing'})
    out = {'scope': 'compiler-name provider candidates only; no include or layout decision',
           'summary': {state: sum(row['status'] == state for row in rows)
                       for state in ('unique', 'ambiguous', 'missing')}, 'rows': rows}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))


if __name__ == '__main__':
    main()
