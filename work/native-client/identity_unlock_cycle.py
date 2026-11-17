"""Run the identity-unlock refresh cycle in one process so header scans, disassembly
(target_refs) and undname results are computed once and shared by every route.

  python identity_unlock_cycle.py [--bodyhash] [--max-rounds N]
--bodyhash reruns identity_unlock_bodyhash.py first (after the body index changed).
Repeats align, merge, inferred, upgrade, reflect, vtsib, vthdr, merge until
unnamed-identities.json stops changing, then writes the inferred tier.
"""
import argparse
import json
from identity_unlock_common import dump_json  # noqa: E402
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import identity_unlock_align as A  # noqa: E402
import identity_unlock_dupctor as DC  # noqa: E402
import identity_unlock_dupfix as DF  # noqa: E402
import identity_unlock_dupref as DR  # noqa: E402
import identity_unlock_inferred as INF  # noqa: E402
import identity_unlock_merge as M  # noqa: E402
import identity_unlock_reflect as R  # noqa: E402
import identity_unlock_upgrade as UP  # noqa: E402
import identity_unlock_vthdr as VH  # noqa: E402
import identity_unlock_vtsib as VS  # noqa: E402
import identity_unlock_ws as WS  # noqa: E402
import identity_unlock_wsfp as WF  # noqa: E402
import identity_unlock_wsgraph as WG  # noqa: E402

NC = Path(__file__).parent
REAL = NC / 'unnamed-identities.json'


def step(name, fn):
    t = time.time()
    fn()
    print('[cycle] %-9s %5.1fs' % (name, time.time() - t), flush=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--bodyhash', action='store_true')
    ap.add_argument('--max-rounds', type=int, default=3)
    a = ap.parse_args()
    sys.argv = [sys.argv[0]] + [str(p) for p in sorted(NC.glob('identity-unlock-objindex*.pkl.gz'))]
    if a.bodyhash:
        import identity_unlock_bodyhash as B
        step('bodyhash', B.main)
    step('dupfix', DF.main)
    step('dupctor', DC.main)
    prev = None
    for rnd in range(a.max_rounds):
        for name, fn in (('align', A.main), ('merge', M.main), ('inferred', INF.main), ('upgrade', UP.main),
                         ('reflect', R.main), ('vtsib', VS.main), ('vthdr', VH.main), ('ws', WS.main), ('wsfp', WF.main), ('dupref', DR.main), ('merge', M.main)):
            step(name, fn)
        cur = {k: v['name'] for k, v in json.load(open(REAL)).items()}
        print('[cycle] round %d: %d real' % (rnd + 1, len(cur)), flush=True)
        if prev is not None:
            for k in sorted(set(cur) | set(prev)):
                if cur.get(k) != prev.get(k):
                    print('[cycle]   %s %s -> %s' % (k, prev.get(k), cur.get(k)), flush=True)
        if cur == prev:
            break
        if prev is not None and rnd == a.max_rounds - 1:
            # rules that disagree between rounds (anchors shift) mark the name ambiguous:
            # keep only rows whose name is identical in the last two rounds
            rows = json.load(open(REAL))
            keep = {k: r for k, r in rows.items() if prev.get(k) == r['name']}
            print('[cycle] unstable names dropped: %d' % (len(rows) - len(keep)), flush=True)
            dump_json(keep, REAL)
        prev = cur
    step('wsgraph', WG.main)
    step('inferred', INF.main)


if __name__ == '__main__':
    main()
