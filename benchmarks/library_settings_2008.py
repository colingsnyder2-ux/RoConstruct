"""Settings-only trials on verified sibling-supported 2008-06 vendor sources."""
import argparse
import json
import re
from collections import defaultdict
from pathlib import Path

from benchmarks.claude_continuation import run_sources
from benchmarks.library_fill import trial
from benchmarks.match_campaign import Campaign, digest
from roc import libs, match

ROOT = Path('work/library-settings-20261011')
CLIENT = '2008-06'


def variants(source):
    directives = match.directives(source)
    flags = directives['flags']
    # One setting changes per candidate; source and library definitions stay fixed.
    for pattern, option in ((r'/GS-?', '/GS-' if '/GS-' not in flags else '/GS'),
                            (r'/Oy-?', '/Oy-'), (r'/Ob[012]', '/Ob2'),
                            (r'/Ob[012]', '/Ob0'), (r'/Oi-?', '/Oi'),
                            (r'/O[12x]', '/O1')):
        changed, count = re.subn(r'(?<!\S)' + pattern + r'(?!\S)', option, flags)
        if not count:
            changed = flags + ' ' + option
        if changed != flags:
            yield re.sub(r'^// roc-flags:.*$', '// roc-flags: ' + changed, source, flags=re.M), \
                dict(setting=option, compiler=directives['cl'])
    recipe = directives['lib'].split(' ', 1)[0]
    for build in libs.RECIPES[recipe].get('builds', libs.BUILDS):
        if str(build) != directives['cl']:
            yield re.sub(r'^// roc-cl:.*$', '// roc-cl: ' + str(build), source, flags=re.M), \
                dict(setting='compiler-only', compiler=build)


def run(limit, server):
    campaign = Campaign(ROOT, server)
    try:
        rows = campaign.api.call('/v1/sources?client=' + CLIENT, timeout=300)
        prior = json.loads(Path('work/library-fill-20261011/summary.json').read_text())['gains']
        targets = sorted((r for r in rows if 0 < prior.get(r['addr'], 100) < 100
                          and r['score'] < 100 and r.get('source')),
                         key=lambda r: (-r['score'], r['addr']))[:limit]
        grouped = defaultdict(list)
        for row in targets:
            grouped[row['source']].append(row)
        plans = {}
        for original, group in grouped.items():
            for source, evidence in variants(original):
                plans.setdefault(source, dict(evidence, targets=[r['addr'] for r in group],
                                              original_sha256=digest(original)))
        campaign.record('plan', dict(targets=[r['addr'] for r in targets], configurations=len(plans)))
        print('settings plan', len(targets), 'targets', len(plans), 'configurations', flush=True)
        run_sources(campaign, 'settings-exacts', plans.items(), 3)
        done = {(r['addr'], r['source_sha256']) for r in campaign.previous('settings-partials')}
        for source, evidence in plans.items():
            for addr in evidence['targets']:
                if (addr, digest(source)) in done or campaign.current(CLIENT, addr)['score'] == 100:
                    continue
                trial(campaign, 'settings-partials', addr, source, evidence)
    finally:
        campaign.api.close()


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--limit', type=int, default=4)
    parser.add_argument('--server', default='http://127.0.0.1:8765')
    args = parser.parse_args()
    run(args.limit, args.server)
