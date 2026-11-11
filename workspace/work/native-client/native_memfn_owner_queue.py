"""Queue unbound member-pointer targets as owner/signature evidence only."""
import argparse
import json
import re
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--memfn', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--inventory', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    bound = {row['addr'].lower() for row in json.loads(args.closure.read_text())['bindings']}
    headers = json.loads(args.inventory.read_text())['header_classes']
    rows = []
    for row in json.loads(args.memfn.read_text())['functions']:
        address, owner = row['address'].lower(), row.get('owner')
        if address in bound:
            continue
        leaf = owner.rsplit('::', 1)[-1] if owner else ''
        candidates = sorted(set(headers.get(leaf, []))) if leaf else []
        packet = ROOT / 'src/2008-06' / (address + '.cpp')
        if not owner:
            status, reason = 'blocked-no-owner', 'function pointer has no member owner'
        elif not row.get('consistent') or len(row.get('signatures', [])) != 1:
            status, reason = 'blocked-ambiguous-signature', 'member-pointer evidence is not one consistent signature'
        elif not packet.is_file():
            status, reason = 'blocked-no-packet', 'mined packet absent'
        elif not candidates:
            status, reason = 'blocked-no-real-header', 'owner has no native header'
        elif len(candidates) != 1:
            status, reason = 'blocked-ambiguous-header', 'owner has multiple native headers'
        else:
            status, reason = 'owner-signature-candidate', 'owner and signature proven; method name remains unproven'
        rows.append({'addr': address, 'owner': owner, 'signatures': row.get('signatures', []),
                     'headers': candidates, 'evidence': row.get('evidence', []),
                     'status': status, 'reason': reason})
    rows.sort(key=lambda row: (row['status'], row['owner'] or '', row['addr']))
    summary = dict(Counter(row['status'] for row in rows))
    out = {'scope': 'unbound member-pointer owner/signature evidence; no generated names, declarations, source, or promotion',
           'summary': summary, 'rows': rows}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(summary))


if __name__ == '__main__':
    main()
