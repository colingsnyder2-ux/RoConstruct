"""Plan isolated profile probes for closure-named methods already in native source."""
import argparse
import json
import re
from collections import defaultdict
from pathlib import Path

from native_convert_plan import ROOT, has_definition, marker_for_symbol, owner_namespace
from native_transplant_probe import method_start


FLAGS = re.compile(r'^// native-flags:\s*(.*)$', re.M)
PROFILE_NAMES = {'baseline', 'fp-fast', 'fp-strict'}


def native_sources(owner, method):
    marker = owner + '::' + method
    found = []
    for path in (ROOT / 'rebuild/2008-06/native-classes').glob('*.cpp'):
        if has_definition(path.read_text(errors='replace'), marker):
            found.append(path)
    return found


def completed_profile_attempts():
    """Addresses with all fixed profiles already measured from an isolated run."""
    seen = defaultdict(set)
    for path in ROOT.glob('work/native-client/**/result.json'):
        if path.parent.name not in PROFILE_NAMES:
            continue
        try:
            result = json.loads(path.read_text())
        except (OSError, json.JSONDecodeError):
            continue
        for row in result.get('requested', []):
            if row.get('addr'):
                seen[row['addr'].lower()].add(path.parent.name)
    return {addr for addr, profiles in seen.items() if profiles == PROFILE_NAMES}


def failed_profile_sources():
    """Source/header pairs whose three fixed isolated profiles all failed compile."""
    failed = set()
    for summary_path in ROOT.glob('work/native-client/**/result.json'):
        try:
            summary = json.loads(summary_path.read_text())
        except (OSError, json.JSONDecodeError):
            continue
        if not summary.get('scope', '').startswith('isolated compiler-profile evidence'):
            continue
        plan_path = Path(summary.get('plan', ''))
        if not plan_path.is_absolute():
            plan_path = ROOT / plan_path
        try:
            plan = json.loads(plan_path.read_text())['plans'][summary['batch']]
        except (OSError, KeyError, IndexError, json.JSONDecodeError):
            continue
        statuses = set()
        for profile in summary.get('profiles', []):
            result_path = ROOT / profile.get('result', '')
            try:
                result = json.loads(result_path.read_text())
            except (OSError, json.JSONDecodeError):
                continue
            statuses.update(row.get('status') for row in result.get('requested', []))
        if statuses == {'compile_failed'} and len(summary.get('profiles', [])) == len(PROFILE_NAMES):
            failed.add((str(Path(plan['source']).resolve()), plan['headers'][0]))
    return failed


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--gate', type=Path, required=True)
    ap.add_argument('--closure', type=Path, required=True,
                    help='current identity closure; stale gate rows are blocked')
    ap.add_argument('--skip-attempted', action='store_true',
                    help='skip rows with all fixed isolated profiles already measured')
    ap.add_argument('--limit', type=int, default=20)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    groups, blocked = defaultdict(list), []
    bound = {row['addr'].lower() for row in json.loads(args.closure.read_text()).get('bindings', [])}
    attempted = completed_profile_attempts() if args.skip_attempted else set()
    failed_sources = failed_profile_sources() if args.skip_attempted else set()
    for row in json.loads(args.gate.read_text())['rows']:
        if row['status'] != 'profile-sweep' or len(row['headers']) != 1:
            continue
        if row['addr'].lower() not in bound:
            blocked.append({'addr': row['addr'], 'reason': 'stale gate row is unbound by current closure'})
            continue
        if row['addr'].lower() in attempted:
            blocked.append({'addr': row['addr'], 'reason': 'all fixed profiles already measured'})
            continue
        sources = native_sources(row['owner'], row['method'])
        if len(sources) != 1:
            blocked.append({'addr': row['addr'], 'reason': 'native provider source ambiguous' if sources else
                            'native provider source missing', 'sources': [str(x) for x in sources]})
            continue
        source = sources[0]
        text = source.read_text(errors='replace')
        marker = marker_for_symbol(text, row['owner'] + '::' + row['method'], row['symbol'])
        marker_name, forced, occurrence_text = marker.rpartition('#')
        if not forced or not occurrence_text.isdigit():
            marker_name, occurrence = marker, 0
        else:
            occurrence = int(occurrence_text)
        try:
            method_start(text, marker_name, occurrence)
        except ValueError:
            blocked.append({'addr': row['addr'], 'reason': 'native source lacks closure owner/method body',
                            'source': str(source), 'marker': marker})
            continue
        header = ROOT / row['headers'][0]
        if (str(source.resolve()), row['headers'][0]) in failed_sources:
            blocked.append({'addr': row['addr'], 'reason': 'all fixed profiles already compile-failed for source/header',
                            'source': str(source)})
            continue
        flags = FLAGS.search(text)
        key = (str(source.resolve()), row['headers'][0], owner_namespace(header.read_text(errors='replace'), row['owner']),
               flags.group(1) if flags else '')
        groups[key].append({'addr': row['addr'], 'symbol': row['symbol'], 'marker': marker})
    plans = []
    for (source, header, namespace, flags), rows in sorted(groups.items()):
        for start in range(0, len(rows), args.limit):
            chosen = rows[start:start + args.limit]
            plans.append({'owner': 'existing-native-profile', 'headers': [header], 'source': source,
                          'namespace': namespace, 'roc_cl': 21022, 'roc_flags': flags,
                          'destination': '',
                          'probe_records': [x['addr'] + '=' + x['marker'] for x in chosen], 'rows': chosen})
    out = {'scope': 'existing native source profile probes only; no edits or promotion',
           'closure': str(args.closure),
           'summary': {'ready': sum(len(x['rows']) for x in plans), 'plans': len(plans), 'blocked': len(blocked),
                       'closure_bound': len(bound)},
           'plans': plans, 'blocked': blocked}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=1) + '\n')
    print(json.dumps(out['summary']))


if __name__ == '__main__':
    main()
