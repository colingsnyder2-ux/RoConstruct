"""Search compiler profiles for existing native ViewNew template near misses.

Read-only native sources. Reports body matches and losses, never promotes a
profile or claims reference/provider/layout proof.
"""
import json
import sys
import itertools
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT), str(ROOT / 'rebuild/2008-06/tests')]
from roc import match, rebuild
import native_bind

OUT = ROOT / 'work/native-client/viewnew-template-profiles'
PROFILES = {'base': [], 'o1': ['/O1'], 'ox': ['/Ox'], 'oy-off': ['/Oy-'],
            'ob1': ['/Ob1'], 'fp-precise': ['/fp:precise']}
PROFILES.update({'order-' + ''.join(map(str, p)): [] for p in itertools.permutations(range(3))})


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    rows = json.loads((ROOT / 'work/native-client/viewnew-template-existing.json').read_text())['rows']
    sources = ['ViewNewWedgeMesh', 'ViewNewTorsoMesh']
    tc = rebuild.toolchain(21022)
    def trial(item):
        stem, profile = item
        folder = OUT / (stem + '-' + profile)
        folder.mkdir(exist_ok=True)
        obj = folder / 'candidate.obj'
        source = ROOT / 'rebuild/2008-06/native-classes' / (stem + '.cpp')
        if profile.startswith('order-'):
            header = ROOT / 'rebuild/2008-06/native-headers/ViewNew/QuadVolumeFace.h'
            text = header.read_text()
            lines = ['const G3D::Vector3 size = G3D::abs(faceToObject<id>(halfSize));',
                     'G3D::Vector2 positionStep((rect.x1() - rect.x0()) / divisions.x, (rect.y1() - rect.y0()) / divisions.y);',
                     'G3D::Vector2 textureStep(textureExtent.x / divisions.x, textureExtent.y / divisions.y);']
            begin = text.index(lines[0])
            end = text.index(lines[2], begin) + len(lines[2])
            text = text[:begin] + '\n\t\t\t'.join(lines[int(i)] for i in profile[6:]) + text[end:]
            generated = folder / 'QuadVolumeFace.h'
            generated.write_text(text)
            candidate = folder / (stem + '.cpp')
            candidate.write_text(source.read_text().replace('"ViewNew/QuadVolumeFace.h"', '"' + generated.as_posix() + '"'))
            source = candidate
        code, log = rebuild.run(tc, 'cl', native_bind.flags() + ['/fp:fast'] + PROFILES[profile]
                                + ['/Fo' + str(obj), str(source)], folder)
        (folder / 'compile.log').write_text(log)
        result = {'source': stem, 'profile': profile, 'compile_exit': code, 'gained': [], 'lost': []}
        if not code:
            bodies = {s: (b, r) for s, b, r in match.coff_functions(obj.read_bytes())}
            for row in rows:
                if 'NativeViewNew_' + stem + '.obj' not in row['emitted_in']:
                    continue
                emitted = bodies.get(row['symbol'])
                target, relocs, _ = match.target('2008-06', row['addr'])
                exact = bool(emitted and len(emitted[0]) == len(target) and set(relocs) <= set(emitted[1])
                             and match.exact_match(target, relocs, *emitted))
                if exact and row['status'] != 'inactive_exact':
                    result['gained'].append(row['addr'])
                if not exact and row['status'] == 'inactive_exact':
                    result['lost'].append(row['addr'])
        print(json.dumps(result), flush=True)
        return result
    with ThreadPoolExecutor(3) as pool:
        results = list(pool.map(trial, [(s, p) for s in sources for p in PROFILES]))
    (OUT / 'report.json').write_text(json.dumps({'scope': 'body bytes only; no promotion', 'rows': results}, indent=1) + '\n')


if __name__ == '__main__':
    main()
