"""Native-vendor from the mined preprocessed units: for every vendor-library unit that still holds remaining functions
(creator-partition/vendor-units.json: recipe|path|flags|roc-cl -> addresses) write
rebuild/2008-06/native-classes/vendor_i/<recipe>/<unit>__<flags>.cpp, which #includes the exact preprocessed text the
mining server compiled (roc/libs.py unit() -> work/libcache/<recipe>/<cl>/<path>.i, regenerated on demand) under the
vendor profile with the mined flags + /Gy (match.py compiles mined units with /Gy).  Same input as the server -> same
bytes; plain-source wrappers (vendor_wrappers.py) differed by preprocess macros (_CPPUNWIND/_MT/_DLL) and header edits.
The .i files are a local cache (work/ is not committed): regenerate with this script on another machine.
  python work/native-client/vendor_i.py [--limit N]"""
import argparse
import json
import os
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
from roc import libs, match  # noqa: E402

ap = argparse.ArgumentParser()
ap.add_argument('--limit', type=int, default=0)
args = ap.parse_args()
OUT = ROOT / 'rebuild/2008-06/native-classes/vendor_i'
units = json.loads((HERE / 'creator-partition/vendor-units.json').read_text())
written, failed = [], {}
for key, addrs in list(units.items())[:args.limit or None]:
    recipe, path, flags, cl = key.split('|')
    if recipe not in libs.RECIPES or not path or path == '?':
        failed[key] = 'no recipe/path'
        continue
    build = int(cl) if cl.isdigit() else 21022
    try:
        libs.unit(recipe, path.replace('\\', '/'), build)       # writes work/libcache/<recipe>/<build>/<file>.i
    except Exception as error:                                  # noqa: BLE001 - one unbuildable unit must not stop the batch
        failed[key] = 'preprocess failed: %s' % str(error)[:200]
        continue
    flat = path.replace('\\', '/').replace('/', '__')
    folder = ROOT / 'work' / 'libcache' / recipe / str(build)
    cache = next((p for p in sorted(folder.glob(flat + '*.i'))), None)
    if not cache:
        failed[key] = 'no .i after preprocess'
        continue
    stem = re.sub(r'[^A-Za-z0-9_.-]', '_', flat.rsplit('.', 1)[0])
    tag = re.sub(r'[^0-9A-Za-z]', '', flags)[:12]
    wrapper = OUT / recipe / ('%s__%s.cpp' % (stem, tag))
    wrapper.parent.mkdir(parents=True, exist_ok=True)
    rel = os.path.relpath(cache, wrapper.parent).replace('\\', '/')
    wrapper.write_text('// native-profile: vendor\n'
                       '// native-flags: %s /Gy\n'
                       '// 2008-06 native-vendor (inactive): authentic %s unit %s, preprocessed exactly as mined (roc/libs.py\n'
                       '// unit(), roc-cl %s; local cache - regenerate with work/native-client/vendor_i.py). %d remaining functions:\n'
                       '// %s\n'
                       '#include "%s"\n' % (flags, recipe, path, cl, len(addrs), ' '.join(sorted(addrs)), rel))
    written.append(str(wrapper.relative_to(ROOT)).replace('\\', '/'))
    print('wrote', written[-1], flush=True)
(HERE / 'creator-partition/vendor-i-wrappers.json').write_text(json.dumps(dict(written=written, failed=failed), indent=1))
print('%d wrappers, %d failed' % (len(written), len(failed)))
for key, why in failed.items():
    print('  ', key[:90], '->', why)
