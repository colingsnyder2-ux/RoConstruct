"""Deterministic Ogre converter runner; no LLM.

Examples:
  python work/native-client/ogre/run_all.py --batch 20 --offset 40
  python work/native-client/ogre/run_all.py --all
"""
import argparse
import collections
import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path


HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
from roc import match  # noqa: E402


def roots(prefixes):
    funcs = match._functions('2008-06')
    src = ROOT / 'src/2008-06'
    return [addr for addr, row in funcs.items()
            if row.get('kind') == 'code' and row.get('unit', '').startswith(prefixes)
            and (src / (addr + '.cpp')).is_file()]


def packet_state(addr):
    path = ROOT / 'src/2008-06' / (addr + '.cpp')
    if not path.is_file():
        return 'no-source'
    text = path.read_text(errors='replace')
    grade = re.search(r'^// from server:\s*(\d+)%', text, re.M)
    if grade and int(grade.group(1)) < 100:
        return 'unmined'
    if '// roc-lib:' in text and not any(line.strip() and not line.lstrip().startswith(('#', '//'))
                                         for line in text.splitlines()):
        return 'vendor-only'
    return 'mined-body'


def size_bucket(size):
    for limit in (32, 64, 128, 256, 512, 1024, 2048, 4096):
        if size <= limit:
            return limit
    return 8192


def leaf_causes(batch_root, all_roots, funcs):
    latest = {}
    for path in sorted(batch_root.glob('*/link/ogre_convert.json'), key=lambda p: p.stat().st_mtime_ns):
        for addr, row in json.loads(path.read_text()).items():
            latest[addr] = row
    impact = collections.defaultdict(set)
    details = {}
    for root in all_roots:
        if root not in latest or latest[root]['status'] == 'renamed':
            continue
        pending, visited = [root], set()
        while pending:
            addr = pending.pop()
            if addr in visited:
                continue
            visited.add(addr)
            row = latest.get(addr, {})
            if row.get('status') == 'renamed':
                continue
            deps = row.get('missing', [])
            if deps:
                pending.extend(deps)
                continue
            impact[addr].add(root)
            details[addr] = {'status': row.get('status', packet_state(addr)), 'why': row.get('why')}
        # Report cycles rather than silently losing an entire blocked closure.
        if not any(root in owners for owners in impact.values()):
            key = 'cycle:' + min(visited)
            impact[key].add(root)
            details[key] = {'status': 'dependency-cycle', 'members': sorted(visited)}
    rows = [dict(address=addr, blocked_roots=len(owners),
                 blocked_root_bytes=sum(funcs.get(a, {}).get('size', 0) for a in owners),
                 **details[addr]) for addr, owners in impact.items()]
    rows.sort(key=lambda r: (-r['blocked_root_bytes'], r['address']))
    return {'scope': 'converter closure impact, not linked bytes; overlapping leaf impacts must not be summed',
            'leaf_causes': rows}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--batch', type=int, default=0)
    ap.add_argument('--offset', type=int, default=0)
    ap.add_argument('--next', action='store_true', help='first unreported source-backed roots')
    ap.add_argument('--repair', action='store_true', help='highest-fan-in mined missing callees')
    ap.add_argument('--large', action='store_true', help='prioritize largest untried mined bodies')
    ap.add_argument('--adaptive', action='store_true', help='rank body size by observed exact rate')
    ap.add_argument('--linear', action='store_true', help='address-order queue, disables adaptive ranking')
    ap.add_argument('--vendor', action='store_true', help='exact-prove roc-lib vendor source packets')
    ap.add_argument('--all', action='store_true')
    ap.add_argument('--refresh-names', action='store_true')
    ap.add_argument('--summary', action='store_true')
    ap.add_argument('--leaf-causes', action='store_true', help='rank terminal causes by blocked root bytes')
    ap.add_argument('--scope', default='Ogre::,RBX::RenderNew,RBX::ViewNew',
                    help='comma-separated unit prefixes; each scope owns batches/cache')
    args = ap.parse_args()
    if args.batch < 0 or args.offset < 0 or (not args.leaf_causes and not args.summary and not args.all and not args.batch):
        ap.error('use --batch positive-size, --all, or --summary')
    if args.refresh_names:
        import ogre_names
        ogre_names.main()
    prefixes = tuple(x for x in args.scope.split(',') if x)
    if not prefixes:
        ap.error('--scope needs one prefix')
    scope_tag = '-'.join(x.replace(':', '').replace('/', '_') for x in prefixes)
    batch_root = HERE / 'batches' / scope_tag
    all_roots = roots(prefixes)
    vendor_mode = args.vendor
    if args.leaf_causes:
        print(json.dumps(leaf_causes(batch_root, all_roots, match._functions('2008-06')), sort_keys=True))
        return
    if args.summary:
        counts = {}
        completed = set()
        missing = collections.Counter()
        for path in batch_root.glob('*/link/ogre_convert.json'):
            report = json.loads(path.read_text())
            saved = path.parents[1] / 'roots.json'
            selected = json.loads(saved.read_text()) if saved.is_file() else \
                [addr for addr in all_roots if report.get(addr, {}).get('scope')]
            for addr in selected:
                if addr in report and addr not in completed:
                    counts[report[addr]['status']] = counts.get(report[addr]['status'], 0) + 1
                    missing.update(report[addr].get('missing', []))
                    completed.add(addr)
        top_missing = missing.most_common(12)
        byte_rows = []
        for metric in batch_root.glob('*/metrics.json'):
            byte_rows.append(json.loads(metric.read_text()))
        exact_bytes = sum(row.get('new_exact_bytes', row['exact_bytes']) for row in byte_rows)
        elapsed = sum(row['seconds'] for row in byte_rows)
        print(json.dumps({'source_backed_roots': len(all_roots), 'attempted_roots': len(completed),
                          'root_status': counts, 'unattempted_roots': len(all_roots) - len(completed),
                          'top_missing': [(addr, count, packet_state(addr)) for addr, count in top_missing],
                          'new_exact_bytes': exact_bytes,
                          'new_exact_bytes_per_hour': round(exact_bytes * 3600 / elapsed, 2) if elapsed else 0}, sort_keys=True))
        return
    # One batch at a time: two runners that select before either reports pick the same
    # roots and write the same batch dir.  The OS drops the lock if this process dies.
    import msvcrt
    batch_root.mkdir(parents=True, exist_ok=True)
    lock = open(batch_root / 'run_all.lock', 'w')
    while True:
        try:
            msvcrt.locking(lock.fileno(), msvcrt.LK_NBLCK, 1)
            break
        except OSError:
            time.sleep(2)
    if args.all:
        selected, offset = all_roots, 0
        stem = None
    elif args.repair:
        callers = collections.defaultdict(set)
        exact = set()
        for report in batch_root.glob('*/link/ogre_convert.json'):
            rows = json.loads(report.read_text())
            exact.update(addr for addr, row in rows.items() if row.get('status') == 'renamed')
            for caller, row in rows.items():
                for addr in row.get('missing', []):
                    callers[addr].add(caller)
        funcs = match._functions('2008-06')
        candidates = [addr for addr in callers if addr not in exact and addr in funcs
                      and packet_state(addr) in (('mined-body', 'vendor-only') if vendor_mode else ('mined-body',))]
        candidates.sort(key=lambda addr: (-funcs[addr]['size'] * len(callers[addr] - exact), addr))
        selected = candidates[:args.batch]
        offset = 0
        stem = 'repair-' + (selected[0] if selected else 'empty')
    elif args.next:
        seen = set()
        for report in batch_root.glob('*/link/ogre_convert.json'):
            saved = report.parents[1] / 'roots.json'
            seen.update(json.loads(saved.read_text()) if saved.is_file() else
                        (addr for addr, row in json.loads(report.read_text()).items() if row.get('scope')))
        wanted = 'vendor-only' if vendor_mode else 'mined-body'
        candidates = [addr for addr in all_roots
                      if addr not in seen and packet_state(addr) == wanted]
        if not candidates and not vendor_mode:
            vendor_mode = True
            candidates = [addr for addr in all_roots
                          if addr not in seen and packet_state(addr) == 'vendor-only']
        adaptive = args.adaptive or (args.next and not args.linear)
        if adaptive:
            history = collections.defaultdict(lambda: [0, 0])
            for report in batch_root.glob('*/link/ogre_convert.json'):
                for addr, row in json.loads(report.read_text()).items():
                    if row.get('scope') and addr in all_roots:
                        bucket = size_bucket(len(match.target('2008-06', addr)[0]))
                        history[bucket][0] += 1
                        history[bucket][1] += row['status'] == 'renamed'
            def score(addr):
                size = len(match.target('2008-06', addr)[0])
                tried, exact = history[size_bucket(size)]
                return size * (exact + 1) / (tried + 2)
            candidates.sort(key=score, reverse=True)
        elif args.large:
            candidates.sort(key=lambda addr: len(match.target('2008-06', addr)[0]), reverse=True)
        selected = candidates[:args.batch]
        offset = all_roots.index(selected[0]) if selected else args.offset
        stem = (('adaptive-' if adaptive else 'large-') + selected[0]) \
            if (adaptive or args.large) and selected else None
    else:
        selected, offset = all_roots[args.offset:args.offset + args.batch], args.offset
        stem = None
    if not selected:
        print('no source-backed roots in requested batch')
        return
    env = os.environ.copy()
    env['ROC_SCOPE'] = args.scope
    env['OGRE_CACHE'] = str(HERE / 'cache' / scope_tag)
    if vendor_mode:
        env['OGRE_VENDOR_SOURCE'] = '1'
    already = set()
    for old in batch_root.glob('*/link/ogre_convert.json'):
        already.update(addr for addr, row in json.loads(old.read_text()).items() if row['status'] == 'renamed')
    if not args.all:
        stem = stem or 'batch-%05d-%05d' % (offset, offset + len(selected))
        original_stem = stem
        retry = 1
        while (batch_root / stem).exists():
            stem = '%s-r%03d' % (original_stem, retry)
            retry += 1
        env['OGRE_OUT'] = str(batch_root / stem / 'renamed')
        env['OGRE_LINK'] = str(batch_root / stem / 'link')
        link = Path(env['OGRE_LINK'])
    else:
        link = HERE / 'link'
    started = time.perf_counter()
    run = subprocess.run([sys.executable, str(HERE / 'ogre_convert.py'), *selected],
                         cwd=ROOT, env=env, text=True, stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT)
    if run.returncode:
        raise SystemExit(run.stdout[-4000:])
    report = json.loads((link / 'ogre_convert.json').read_text())
    (link.parent / 'roots.json').write_text(json.dumps(selected, indent=1) + '\n')
    rootset = set(selected)
    root_counts = {}
    helper_counts = {}
    for addr, row in report.items():
        counts = root_counts if addr in rootset else helper_counts
        status = row['status']
        counts[status] = counts.get(status, 0) + 1
    exact = [addr for addr, row in report.items() if row['status'] == 'renamed']
    new_exact = [addr for addr in exact if addr not in already]
    root_exact = [addr for addr in exact if addr in rootset]
    root_bytes = sum(len(match.target('2008-06', addr)[0]) for addr in root_exact)
    helper_bytes = sum(len(match.target('2008-06', addr)[0]) for addr in exact if addr not in rootset)
    proved_name_bytes = sum(len(match.target('2008-06', addr)[0]) for addr in exact
                            if not report[addr].get('name_source', '').endswith('placeholder'))
    data = json.loads((link / 'data-metrics.json').read_text()) if (link / 'data-metrics.json').is_file() else {}
    metrics = {'roots': len(selected), 'root_exact': len(root_exact), 'helper_exact': len(exact) - len(root_exact),
               'root_bytes': root_bytes, 'helper_bytes': helper_bytes, 'exact_bytes': root_bytes + helper_bytes,
               'linked_code_bytes': 0, 'linked_data_bytes': 0,
               'proved_name_bytes': proved_name_bytes, 'placeholder_name_bytes': root_bytes + helper_bytes - proved_name_bytes,
               'native_source_bytes': 0, 'converter_object_bytes': root_bytes + helper_bytes,
               'data_definition_bytes': data.get('bytes', 0), 'data_definition_status': data.get('status'),
               'renames_applied': len(exact), 'unresolved_symbols': None, 'duplicate_symbols': None,
               'seconds': round(time.perf_counter() - started, 6), 'vendor_lane': vendor_mode}
    metrics['new_exact_addresses'] = len(new_exact)
    metrics['new_exact_bytes'] = sum(len(match.target('2008-06', addr)[0]) for addr in new_exact)
    new_roots = [addr for addr in root_exact if addr not in already]
    metrics['new_root_bytes'] = sum(len(match.target('2008-06', addr)[0]) for addr in new_roots)
    metrics['new_helper_bytes'] = metrics['new_exact_bytes'] - metrics['new_root_bytes']
    metrics['exact_bytes_per_hour'] = round(metrics['exact_bytes'] * 3600 / metrics['seconds'], 2) if metrics['seconds'] else 0
    metrics['new_exact_bytes_per_hour'] = round(metrics['new_exact_bytes'] * 3600 / metrics['seconds'], 2) if metrics['seconds'] else 0
    (link.parent / 'metrics.json').write_text(json.dumps(metrics, indent=1) + '\n')
    with (HERE / 'bytes-per-hour.jsonl').open('a') as log:
        log.write(json.dumps(metrics, sort_keys=True) + '\n')
    print(json.dumps({'roots': len(selected), 'root_status': root_counts,
                      'helper_status': helper_counts, 'metrics': metrics, 'output': str(link)}, sort_keys=True))


if __name__ == '__main__':
    main()
