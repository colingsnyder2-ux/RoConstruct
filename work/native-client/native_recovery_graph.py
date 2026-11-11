"""Emit deterministic recovery decision DAG from queue and native-bulk receipts.

No owner, signature, field or dependency is inferred.  Every edge is copied
from queue state, a byte/reference receipt, or its rejected-reference list.
The JSON ``next`` table is stable input for an automated scheduler; DOT is a
small human view of same evidence.
"""
import argparse
import json
from collections import Counter, defaultdict
from pathlib import Path


def graph_id(kind, value):
    return kind + ':' + value.replace(':', '_').replace('?', '_').replace('$', '_')


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--queue', type=Path, required=True)
    ap.add_argument('--ledger', type=Path, action='append', default=[])
    ap.add_argument('--owner-prefix', action='append', default=[])
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--dot', type=Path)
    args = ap.parse_args()
    queue = json.loads(args.queue.read_text())
    rows = []
    for cls in queue['classes']:
        if args.owner_prefix and not any(cls['owner'].startswith(prefix) for prefix in args.owner_prefix):
            continue
        for row in cls['methods']:
            row = dict(row)
            row['owner'] = cls['owner']
            rows.append(row)
    proof, rejected, refs = {}, defaultdict(list), defaultdict(list)
    for path in args.ledger:
        data = json.loads(path.read_text())
        for receipt in data.values():
            for row in receipt.get('harvest_rows', []):
                address = row.get('addr', '').lower()
                if row.get('status') == 'inactive_exact' and address:
                    proof[address] = {'symbol': row['symbol'], 'ledger': str(path),
                                      'references': row.get('references', [])}
                    refs[address].extend(row.get('references', []))
                for failure in row.get('rejections', []):
                    rejected[failure.get('addr', '').lower()].extend(failure.get('errors', []))
    nodes, edges, next_rows = [], [], []
    for row in sorted(rows, key=lambda item: item['addr']):
        address = row['addr'].lower()
        target = graph_id('target', address)
        owner = graph_id('owner', row['owner'])
        nodes.extend([{'id': target, 'kind': 'target', 'address': address, 'symbol': row['symbol'],
                       'queue_state': row['state']}, {'id': owner, 'kind': 'owner', 'owner': row['owner']}])
        edges.append({'from': owner, 'to': target, 'kind': 'owns'})
        if address in proof:
            receipt = graph_id('proof', address)
            nodes.append({'id': receipt, 'kind': 'byte-reference-proof', 'ledger': proof[address]['ledger'],
                          'symbol': proof[address]['symbol']})
            edges.append({'from': target, 'to': receipt, 'kind': 'proved'})
            action = 'native-provider-next-gate' if row['state'] == 'existing-native' else 'identity-reconcile'
            for ref in refs[address]:
                if ref.get('requires_provider'):
                    dep = graph_id('dependency', ref['address'])
                    nodes.append({'id': dep, 'kind': 'required-provider', 'address': ref['address'],
                                  'symbol': ref['symbol']})
                    edges.append({'from': receipt, 'to': dep, 'kind': 'requires-provider'})
        elif rejected[address]:
            action = 'repair-reference-identity'
            for error in sorted(set(rejected[address])):
                fail = graph_id('blocked', address + ':' + error)
                nodes.append({'id': fail, 'kind': 'blocked', 'reason': error})
                edges.append({'from': target, 'to': fail, 'kind': 'blocked-by'})
        elif row['state'] == 'convert' and len(row.get('headers', [])) == 1:
            action = 'probe-real-header-source'
        elif row['state'] == 'convert':
            action = 'block-header-or-layout'
        elif row['state'] == 'name-only':
            action = 'block-no-safe-source'
        else:
            action = 'reprove-or-reconcile'
        next_rows.append({'address': address, 'owner': row['owner'], 'symbol': row['symbol'],
                          'queue_state': row['state'], 'action': action})
    unique = {node['id']: node for node in nodes}
    summary = Counter(row['action'] for row in next_rows)
    out = {'scope': 'queue/receipt evidence graph only; no generated source, layout, link or runtime claim',
           'summary': {'targets': len(next_rows), 'nodes': len(unique), 'edges': len(edges), 'next': dict(summary)},
           'nodes': list(unique.values()), 'edges': edges, 'next': next_rows}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    if args.dot:
        lines = ['digraph native_recovery {', 'rankdir=LR;']
        for node in unique.values():
            label = node.get('address', node.get('owner', node.get('reason', node['id'])))
            lines.append('"%s" [label="%s"];' % (node['id'], label.replace('"', "'")))
        lines.extend('"%s" -> "%s" [label="%s"];' % (edge['from'], edge['to'], edge['kind']) for edge in edges)
        lines.append('}')
        args.dot.write_text('\n'.join(lines) + '\n')
    print(json.dumps(out['summary']))


if __name__ == '__main__':
    main()
