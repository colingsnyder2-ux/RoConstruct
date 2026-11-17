"""Native-vendor lane (owner 2026-11-16: vendor library code may go native): one wrapper .cpp per library unit that
still holds remaining functions.  The wrapper pins the unit's matched compiler flags plus its recipe's defines /
include dirs ({libs} = tools/libs) and #includes the AUTHENTIC vendor .cpp - no vendor text is copied.
Recipes that edit headers (patches / noinline string calls) are reported and skipped: a plain include cannot replay them.
  python work/native-client/vendor_wrappers.py            # write wrappers for creator-partition/vendor-units.json
"""
import json
import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import libs  # noqa: E402

OUT = ROOT / 'rebuild/2008-06/native-classes/vendor'
units = json.loads((ROOT / 'work/native-client/creator-partition/vendor-units.json').read_text())
CRLF, LF = chr(13) + chr(10), chr(10)
PATCH_ROOT = OUT / '_patched'


def patch_headers(recipe, r, noinline, incs):
    """Reproduce libs.unit()'s `__declspec(noinline) ` insertion on the header text that holds each member, in a copy."""
    done = []
    for inc in incs:
        for name in ('atlsimpstr.h', 'afxv_w32.h'):
            hdr = inc / name
            if not hdr.is_file():
                continue
            text = hdr.read_text(errors='replace').replace(CRLF, LF)
            out = text
            for m in noinline:
                if m.startswith('inline BOOL __stdcall FreeResource'):
                    m = 'AFX_INLINE BOOL WINAPI FreeResource(HGLOBAL)'
                if m in out:
                    out = out.replace(m, '__declspec(noinline) ' + m)
            if out != text:
                dst = PATCH_ROOT / recipe / name
                dst.parent.mkdir(parents=True, exist_ok=True)
                dst.write_text('// PATCHED COPY of %s: reproduces recipe %s edit (roc/libs.py unit()): __declspec(noinline) before\n'
                               '// MFC_STRING_CALLS / FreeResource members the 2008 client calls out of line. Rest is authentic.\n' % (name, recipe) + out)
                done.append(name)
    return done


written, skipped = [], {}
for key, addrs in units.items():
    recipe, path, flags, cl = key.split('|')
    r = libs.RECIPES.get(recipe)
    if not r:
        skipped[key] = 'no recipe'
        continue
    if r.get('patches') or r.get('strip_header_asm'):
        skipped[key] = 'recipe edits headers (patches/strip_header_asm)'
        continue
    folder = libs.fetch(recipe).resolve()
    src = (folder / path.replace('\\', '/')).resolve()
    if not src.is_file():
        skipped[key] = 'missing vendor file'
        continue
    lib_root = libs.LIBS.resolve()
    incs = [folder] + [(lib_root / i).resolve() for i in r.get('include', []) if i != 'WINSDK']
    noinline = r.get('noinline', libs.MFC_STRING_CALLS if r.get('noinline_mfc_strings') else ())
    patched = patch_headers(recipe, r, noinline, incs) if noinline else None
    inc_flags = ' '.join('/I{libs}/' + i.relative_to(lib_root).as_posix() if i.is_relative_to(lib_root) else '/I' + str(i)
                         for i in incs)
    defs = ' '.join('/D' + d for d in (r.get('defines') or '').split())
    # libs.preprocess() ran WITHOUT the compile flags: no /EHsc (_CPPUNWIND), /MD only if _AFXDLL. Undo them in the source.
    dd = (r.get('defines') or '').split()
    undef = ['_CPPUNWIND'] + ([] if '_AFXDLL' in dd else ['_MT']) + ([] if '_AFXDLL' in dd or '_DLL' in dd else ['_DLL'])
    if re.split(r'[\\/]', path)[-1].startswith('roc_'):
        undef = []  # generated units: compiled with the plain flags (they define _AFXDLL/_CPPUNWIND themselves)
    pre = ''.join('#undef %s\n' % m for m in undef) + ''.join('#include "%s"\n' % h for h in r.get('preinclude') or [])
    stem = re.sub(r'[^A-Za-z0-9_.-]', '_', path.replace('\\', '/').rsplit('.', 1)[0].replace('/', '__'))
    tag = re.sub(r'[^0-9A-Za-z]', '', flags)[:12]
    wrapper = OUT / recipe / ('%s__%s.cpp' % (stem, tag))
    wrapper.parent.mkdir(parents=True, exist_ok=True)
    rel = os.path.relpath(src, wrapper.parent).replace('\\', '/')
    if patched:
        inc_flags = '/I{headers}/../native-classes/vendor/_patched/' + recipe + ' ' + inc_flags
    head = ['// native-profile: vendor',
            '// native-flags: /Gy %s %s %s' % (flags, defs, inc_flags),
            '// 2008-06 native-vendor wrapper (inactive): authentic %s unit %s, compiled with the flags its matched' % (recipe, path),
            '// functions were mined with (roc-flags, roc-cl %s) and the recipe include/define list. %d functions:' % (cl, len(addrs)),
            '// ' + ' '.join(sorted(addrs))]
    wrapper.write_text(chr(10).join(head) + chr(10) + pre + '#include "%s"' % rel + chr(10))
    written.append(str(wrapper.relative_to(ROOT)))
(ROOT / 'work/native-client/creator-partition/vendor-wrappers.json').write_text(json.dumps(dict(written=written, skipped=skipped), indent=1))
print('%d wrappers, %d units skipped' % (len(written), len(skipped)))
for why in sorted(set(skipped.values())):
    print('  %3d  %s' % (sum(1 for v in skipped.values() if v == why), why))
