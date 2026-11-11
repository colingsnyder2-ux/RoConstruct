"""Conservative owner/header gate for deterministic native-class recovery.

RTTI vptr stores establish only an observed dynamic type.  This tool joins those
stores to existing class files, then rejects candidates whose only available
header declares itself an inactive layout candidate.  It creates no source and
never promotes a mined stand-in to an ABI declaration.
"""
import argparse
import json
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
LAYOUT_MARKER = re.compile(r'\b(?:inactive|candidate|pending)\b.{0,48}\blayout\b|\blayout\b.{0,48}\b(?:inactive|candidate|pending)\b', re.I)


def read(path):
    return (ROOT / path).read_text(errors='replace')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('inputs', nargs='+', type=Path)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    seen = set()
    rows = []
    for path in args.inputs:
        report = json.loads(path.read_text())
        for item in report.get('owners', []):
            if not item.get('routable') or not item.get('unit_confirms_owner'):
                continue
            for owner in item['owner_candidates']:
                key = (item['addr'], owner['class'])
                if key in seen or not owner['headers'] or not owner['native_sources']:
                    continue
                seen.add(key)
                headers = sorted(set(owner['headers']))
                sources = sorted(set(owner['native_sources']))
                marked = [header for header in headers if LAYOUT_MARKER.search(read(header))]
                rows.append({
                    'addr': item['addr'], 'unit': item['unit'], 'class': owner['class'],
                    'headers': headers, 'native_sources': sources,
                    'vtable_stores': item['vtable_stores'],
                    'status': 'blocked-layout-unproven' if marked else 'compile-gate-candidate',
                    'reason': ('existing header declares inactive/candidate/pending layout: ' + ', '.join(marked)
                               if marked else 'RTTI owner and existing header/source only; requires isolated compile and byte/data/call proof'),
                })
    rows.sort(key=lambda row: (row['status'], row['class'], row['addr']))
    candidates = [row for row in rows if row['status'] == 'compile-gate-candidate']
    blocked = [row for row in rows if row['status'] != 'compile-gate-candidate']
    out = {'summary': {'rtti_owner_evidence': len(rows),
                       'compile_gate_candidates': len(candidates),
                       'blocked_layout_unproven': len(blocked),
                       'source_generated': 0,
                       'headers_generated': 0,
                       'byte_proved': 0,
                       'linked': 0,
                       'runtime_gated': 0},
           'compile_gate_candidates': candidates,
           'blocked': blocked}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print('compile-gate-candidates', len(out['compile_gate_candidates']), 'blocked-layout', len(out['blocked']))


if __name__ == '__main__':
    main()
