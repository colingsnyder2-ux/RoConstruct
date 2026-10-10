"""Read-only shared-MFC replay with frozen targets and normal verification.

Run: py -3.12 -m benchmarks.shared_mfc_verify --limit 10
Results describe this frozen run, not historical gains from earlier shards.
"""
import argparse
import hashlib
import json
import sqlite3
import time
from pathlib import Path

from roc import libs, match


CASES = [
    ('2008-06', 'CXTPPropertyGrid', 'xtp-11.2.2', 'Source/PropertyGrid/XTPPropertyGrid.cpp'),
    ('2008-06', 'CXTPTabClientWnd', 'xtp-11.2.2', 'Source/CommandBars/XTPTabClientWnd.cpp'),
    ('2008-06', 'CXTPRibbonTheme', 'xtp-11.2.2', 'Source/Ribbon/XTPRibbonTheme.cpp'),
    ('2009-06', 'CXTPPropExchangeXMLNode', 'xtp-15.2.1', 'Source/Common/XTPPropExchange.cpp'),
    ('2011-06', 'CXTCaptionButton', 'xtp-15.2.1', 'Source/Controls/Deprecated/XTButton.cpp'),
    ('2012-06', 'CXTPPropExchangeXMLNode', 'xtp-15.2.1', 'Source/Common/XTPPropExchange.cpp'),
]


def verify(client, addr, code, relocs, obj):
    functions = match.coff_functions(obj)
    scored = [(match.score(code, relocs, f[1], f[2]), f) for f in functions]
    code_score = max(s for s, _ in scored)
    tied = [f for s, f in scored if s == code_score]
    best = tied[0]
    errors = None
    if code_score == 100:
        for candidate in tied:
            _, bad = match.data_check(client, addr, code, match.coff_data_refs(obj, candidate[0]))
            if errors is None:
                best, errors = candidate, bad
            if not bad:
                best, errors = candidate, []
                break
    return {'score': 99 if errors else code_score, 'code_score': code_score,
            'data_errors': errors, 'symbol': best[0]}


def run(limit):
    db = sqlite3.connect('file:work/server.db?mode=ro', uri=True)
    frozen = []
    # Freeze the entire cohort before any compilation; live miners can continue.
    for client, unit, recipe, path in CASES:
        rows = db.execute('SELECT addr,score,source FROM funcs WHERE client=? AND unit=? '
                          'AND score BETWEEN 90 AND 100 ORDER BY score DESC,addr',
                          (client, unit)).fetchall()
        partials = [r for r in rows if r[1] < 100][:limit]
        guards = [r for r in rows if r[1] == 100][:10]
        targets = []
        for i, (addr, stored, source) in enumerate(partials + guards):
            code, relocs, _ = match.target(client, addr)
            targets.append((addr, stored, source, code, relocs,
                            'guard' if i >= len(partials) else 'train' if i % 2 == 0 else 'holdout'))
        frozen.append((client, unit, recipe, path, targets))
    db.close()
    results = []
    for client, unit, recipe, path, targets in frozen:
        started = time.monotonic()
        source = libs.source_for(recipe + '-shared-mfc', path, 'cpp', 30729, '/O2 /GS- /MD')
        obj = match.compile_text(client, source)
        group = {'client': client, 'unit': unit, 'source': source,
                 'object_sha256': hashlib.sha256(obj).hexdigest(), 'targets': []}
        for addr, stored, baseline_source, code, relocs, split in targets:
            row = {'addr': addr, 'stored': stored, 'split': split,
                   'target_sha256': hashlib.sha256(code).hexdigest(),
                   'baseline_source': baseline_source,
                   'candidate': verify(client, addr, code, relocs, obj)}
            try:
                baseline_obj = match.compile_text(client, baseline_source)
                row['baseline'] = verify(client, addr, code, relocs, baseline_obj)
            except (match.CompileError, ValueError, SystemExit) as error:
                row['baseline_error'] = str(error)[-300:]
            group['targets'].append(row)
        group['seconds'] = round(time.monotonic() - started, 2)
        group['summary'] = {
            'targets': len(targets),
            'verified_exact': sum(r['candidate']['score'] == 100 for r in group['targets']),
            'improved_over_stored': sum(r['candidate']['score'] > r['stored'] for r in group['targets']),
            'regressed_from_stored': sum(r['candidate']['score'] < r['stored'] for r in group['targets']),
            'data_only_plateaus': sum(bool(r['candidate']['data_errors']) for r in group['targets']),
            'baseline_failures': sum('baseline_error' in r for r in group['targets']),
        }
        results.append(group)
        print(client, unit, group['summary'], flush=True)
        # Checkpoint each completed unit without touching server state.
        Path('work/shared-mfc-verified-shards.json').write_text(json.dumps(results, indent=2))
    return results


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--limit', type=int, default=10)
    args = parser.parse_args()
    if not 1 <= args.limit <= 30:
        parser.error('--limit must be between 1 and 30')
    run(args.limit)
