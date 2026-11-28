"""Find which members break a failing layout merge group.

For target T with members M1..Mn: compile each pair (anchor, Mi) joined, where anchor is the member that defines the
first changed symbol, and report the members whose presence changes any anchor/other symbol (compare_merge).
Compile-only; writes nothing under native-classes.

    python work/donorfree-route/merge_bisect.py inferred/client/app/v8datamodel/Workspace.cpp
"""
import json, sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parents[0] / 'native-client/layout'))
target = sys.argv[1]
sys.argv = [sys.argv[0]]
import layout_clean, layout_pipeline as lp   # noqa: E402
from coff_compare import compare_merge, parse   # noqa: E402
from layout_export import EXPORT, ROOT   # noqa: E402


def main():
    cache = json.loads((lp.GATE / 'merge-cache.json').read_text())
    row = next(v for v in cache.values() if isinstance(v, dict) and v.get('target') == target and v.get('detail'))
    bad = set(row['detail'].get('removed_or_changed') or [])
    smap = json.loads((HERE.parents[0] / 'native-client/layout/source-layout-map.json').read_text())
    members = sorted(k for k, r in smap.items()
                     if (r.get('target_path') or '').removeprefix('rebuild/2008-06/').casefold() ==
                     target.removeprefix('inferred/').casefold() and k.endswith('.cpp') and '/donor_i/' not in k)
    texts = {m: (ROOT / m).read_bytes().decode('latin-1').replace('\r\n', '\n') for m in members}
    alone = lp.compile_objects([ROOT / m for m in members], tag='bisect-alone')
    sys.path.insert(0, str(ROOT)); from roc.rebuild import coff_externals
    anchor = next((m for m in members if alone.get(ROOT / m) and
                   bad & {n for n, d in coff_externals(Path(alone[ROOT / m]).read_bytes()).items() if d}), None)
    if not anchor:
        raise SystemExit('no member defines %s' % sorted(bad)[:2])
    print('anchor', anchor.split('/')[-1], 'changed', sorted(bad)[:3])
    flags = layout_clean.build_notes(texts[anchor]).get('flags', '')
    breakers, fine = [], []
    for i, m in enumerate(x for x in members if x != anchor):
        dest = EXPORT / ('bisect/%d.cpp' % i)
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_bytes(lp.join_members([anchor, m], texts, dest).encode('latin-1'))
        obj = lp.compile_objects([dest], flags=flags or None, tag='bisect-%d' % i)[dest]
        if not (obj and alone.get(ROOT / m)):
            breakers.append((m, 'does not compile joined' if not obj else 'member alone fails'))
        else:
            v = compare_merge([parse(alone[ROOT / anchor]), parse(alone[ROOT / m])], [parse(obj)], dedupe=True)
            (fine if v['passed'] else breakers).append((m, v.get('removed_or_changed', [])[:3]))
        dest.unlink(missing_ok=True)
    print('BREAKERS:')
    for m, why in breakers:
        print('  ', m.split('/')[-1], why)
    print('ok with anchor:', [m.split('/')[-1] for m, _ in fine])


if __name__ == '__main__':
    main()
