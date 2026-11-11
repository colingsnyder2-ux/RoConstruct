"""Compile whole real library sources with a roc recipe and count byte-exact named functions.

usage: claude_lib_tu_probe.py RECIPE OUTPUT_DIR [file.cpp ...]   (default: every .cpp of the recipe)
Objects carry real compiler-made names: valid --objects input for the identity closure.
"""
import json
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import libs, rebuild  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402
from native_template_probe import exact  # noqa: E402

recipe_name, out = sys.argv[1], Path(sys.argv[2]).resolve()
recipe = libs.RECIPES[recipe_name]
src = (libs.LIBS / recipe['src']).resolve()
flags = ['/nologo', '/c'] + recipe.get('flags', '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD').split()
flags += ['/D' + d for d in recipe.get('defines', '').split()]
flags += ['/I' + str((libs.LIBS / i).resolve()) for i in recipe['include'] if i != 'WINSDK']
flags += __import__('os').environ.get('CLAUDE_EXTRA_FLAGS', '').split()
files = [Path(a).resolve() for a in sys.argv[3:]] or sorted(src.glob('*.cpp'))
targets = Targets('2008-06')
tc = rebuild.toolchain(21022)


def one(path):
    folder = out / path.stem
    folder.mkdir(parents=True, exist_ok=True)
    started = time.monotonic()
    code, log = rebuild.run(tc, 'cl', flags + ['/Fo' + str(folder / 'candidate.obj'), str(path)], folder)
    (folder / 'compile.log').write_text(log, encoding='utf-8')
    row = {'file': path.name, 'exit': code, 'seconds': round(time.monotonic() - started, 2)}
    if not code:
        hits = exact((folder / 'candidate.obj').read_bytes(), targets)
        row.update(exact_symbols=len(hits), unique=sum(len(a) == 1 for a in hits.values()))
    return row


with ThreadPoolExecutor(6) as pool:
    rows = list(pool.map(one, files))
(out / 'receipt.json').write_text(json.dumps({'recipe': recipe_name, 'flags': flags, 'rows': rows}, indent=1))
ok = [r for r in rows if not r['exit']]
print('files', len(rows), 'compiled', len(ok), 'exact symbols', sum(r['exact_symbols'] for r in ok),
      'unique', sum(r['unique'] for r in ok), 'seconds', round(sum(r['seconds'] for r in rows)))
print(sorted(((r['exact_symbols'], r['file']) for r in ok), reverse=True)[:10])
