"""Route strong donor-string names to real headers and source candidates.

Every row remains unproven until a native compile and target-byte check succeeds.
"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
SOURCE_ROOTS = [ROOT / 'tools/rbxgs', ROOT / 'tools/openrbx', ROOT / 'tools/libs']
LIB = re.compile(r'^// roc-lib: (\S+) (.+)$', re.M)


def files_with(pattern, roots):
    command = ['rg', '-l', '--glob', '*.cpp', '--glob', '*.cc', pattern, *map(str, roots)]
    found = subprocess.run(command, capture_output=True, text=True)
    return [Path(line) for line in found.stdout.splitlines() if line]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--donors', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    donors = json.loads(args.donors.read_text())['functions']
    from roc import libs
    headers = list((ROOT / 'rebuild/2008-06/native-headers').rglob('*.h'))
    rows, blocked = [], []
    for donor in donors:
        if donor.get('verdict') != 'new' or donor.get('shared_unique_strings', 0) < 2:
            continue
        candidate = donor['candidate']
        if '<' in candidate or '::' not in candidate:
            blocked.append({'address': donor['address'], 'candidate': candidate, 'reason': 'template-or-nonmember'})
            continue
        owner, method = candidate.rsplit('::', 1)
        short_owner = owner.rsplit('::', 1)[-1]
        real_headers = [path.relative_to(ROOT).as_posix() for path in headers
                        if re.search(r'\b(?:class|struct)\s+' + re.escape(short_owner) + r'\s*(?::[^;{]*)?\{',
                                     path.read_text(errors='replace'))]
        if len(real_headers) != 1:
            blocked.append({'address': donor['address'], 'candidate': candidate, 'reason': 'header-count', 'headers': real_headers})
            continue
        packet = ROOT / 'src/2008-06' / (donor['address'] + '.cpp')
        wrapper = LIB.search(packet.read_text(errors='replace')) if packet.is_file() else None
        spec = libs.RECIPES.get(wrapper.group(1)) if wrapper else None
        wrapped_source = (libs.LIBS / spec['src'] / wrapper.group(2)).resolve() if spec else None
        sources = ([wrapped_source] if wrapped_source and wrapped_source.is_file() else
                   files_with(r'\b' + re.escape(short_owner) + r'::' + re.escape(method) + r'\s*\(', SOURCE_ROOTS))
        if len(sources) != 1:
            blocked.append({'address': donor['address'], 'candidate': candidate, 'reason': 'source-count',
                            'header': real_headers[0], 'sources': [str(path.relative_to(ROOT)) for path in sources]})
            continue
        source_text = sources[0].read_text(errors='replace')
        if not re.search(r'\b' + re.escape(short_owner) + r'::' + re.escape(method) + r'\s*\(', source_text):
            blocked.append({'address': donor['address'], 'candidate': candidate, 'reason': 'packet-source-lacks-definition',
                            'header': real_headers[0], 'source': str(sources[0].relative_to(ROOT))})
            continue
        unsafe_layout = ('Layout2008' in source_text and 'reinterpret_cast' in source_text) or 'reinterpret_cast<char*>' in source_text or bool(
            re.search(r'\*\s*\(\s*\w+\s*\*\s*\)\s*\(\s*\(\s*char\s*\*\s*\)', source_text))
        if unsafe_layout:
            blocked.append({'address': donor['address'], 'candidate': candidate, 'reason': 'unsafe-standin-layout',
                            'header': real_headers[0], 'source': str(sources[0].relative_to(ROOT))})
            continue
        rows.append({'address': donor['address'], 'candidate': candidate,
                     'shared_unique_strings': donor['shared_unique_strings'],
                     'header': real_headers[0], 'source': str(sources[0].relative_to(ROOT))})
    report = {'scope': 'donor names are candidate evidence only; no source generated',
              'summary': {'compile_candidates': len(rows), 'blocked': len(blocked)},
              'candidates': rows, 'blocked': blocked}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=1) + '\n')
    print(json.dumps(report['summary']))


if __name__ == '__main__':
    main()
