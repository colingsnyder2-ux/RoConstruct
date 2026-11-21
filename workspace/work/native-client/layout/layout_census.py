"""Original file of a native unit from the census: which named functions does it define?

The native census (`prove-out/OgreNativeFull/checks.json`) lists every address and symbol each
source emits. function-files.json gives a function its original `.cpp` two ways: its decorated
name exists in the 2007 WebService.pdb (evidence 'pdb'), or its owner and method name match one
OpenRBX definition (evidence 'openrbx'). A unit gets a target only when

- the vote uses symbols that exactly one native source emits (shared inline/COMDAT helpers are
  emitted by many units and say nothing about the unit's own file),
- every such symbol of one kind points at the same original file, and
- the PDB vote and the OpenRBX vote do not contradict each other.

PDB votes checked against units whose path is known from a PDB file-name match: 56 agree,
0 disagree (2026-11-17). OpenRBX votes are weaker (18 agree, 5 disagree against PDB and census
paths, and several of those 5 showed the PDB vote to be the wrong one: a template instantiation
the PDB lists under another file), hence the contradiction rule and the separate evidence name.
A unit with no uniquely owned named function can still be placed by functions that exactly two
native pieces define ('shared' votes: line-located PDB functions, no templates), when they all
point at one file: 11 agree, 0 disagree against PDB file-name matches (2026-11-18).
Read-only: the census files belong to the recovery lane.
"""
import json
from collections import Counter

from common import NC, ROOT

CHECKS = NC / 'prove-out/OgreNativeFull/checks.json'
SNAPSHOT = NC / 'layout/census-checks-snapshot.json'   # the recovery lane regenerates CHECKS for hours at a time: keep a copy
try:
    if CHECKS.exists():
        if not SNAPSHOT.exists() or CHECKS.stat().st_mtime > SNAPSHOT.stat().st_mtime:
            SNAPSHOT.write_bytes(CHECKS.read_bytes())
    elif SNAPSHOT.exists():
        CHECKS = SNAPSHOT
except OSError:
    pass


def targets(funcs, case):
    """{repo-relative source: {'target', 'votes', 'case_source', 'kind'}}; 'conflict' instead of 'target' on contradiction."""
    if not CHECKS.exists():
        return {}
    jobs = json.loads(CHECKS.read_text(encoding='utf-8'))['jobs']
    root = ROOT.as_posix().lower() + '/'
    owners = Counter(check['addr'].lower() for job in jobs for check in job['checks'])
    result = {}
    for job in jobs:
        source = job['source'].replace('\\', '/')
        if not source.lower().startswith(root):
            continue
        votes = {'pdb': Counter(), 'openrbx': Counter()}
        shared = Counter()
        for check in job['checks']:
            row = funcs.get(check['addr'].lower())
            target = (row or {}).get('target_path') or ''
            if (owners[check['addr'].lower()] == 1 and row and row.get('evidence') in votes
                    and target.lower().endswith(('.cpp', '.c')) and '/unclassified/' not in target):
                votes[row['evidence']][target.lower()] += 1
            elif (owners[check['addr'].lower()] == 2 and '?$' not in check.get('symbol', '?$') and row
                  and row.get('evidence') == 'pdb' and row.get('line') is not None
                  and target.lower().endswith(('.cpp', '.c')) and '/unclassified/' not in target):
                shared[target.lower()] += 1       # two native pieces define it; templates never count
        single = {kind: next(iter(c.items())) for kind, c in votes.items() if len(c) == 1}
        if not single and not any(votes.values()) and len(shared) == 1:
            single = {'shared': next(iter(shared.items()))}
        if not single or any(len(c) > 1 for c in votes.values()):
            continue
        if len({target for target, _ in single.values()}) > 1:
            result[source[len(root):]] = {'conflict': {kind: target for kind, (target, _) in single.items()}}
            continue
        kind = 'pdb' if 'pdb' in single else 'openrbx' if 'openrbx' in single else 'shared'
        target, count = single[kind]
        spelling = case.get(target, [])
        cased = len(spelling) == 1
        if cased:
            target = target.rsplit('/', 1)[0] + '/' + spelling[0].rsplit('/', 1)[-1]
        result[source[len(root):]] = {'target': target, 'votes': count, 'kind': kind,
                                      'agreeing_kinds': sorted(single),
                                      'case_source': 'openrbx' if cased else 'lowercase'}
    return result
