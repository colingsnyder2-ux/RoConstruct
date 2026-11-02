"""declaration_view_profile.py [-v] [--src NAME] PREFIX=ADDR ... : CDeclarationView unit through the document-swap flags and the noinline
profile (CString operator PCXSTR and IsEmpty, std::string::c_str are imported in the original), compare named functions."""
import sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(HERE))
from native_bind import flags, match, rebuild  # noqa: E402
OUT = ROOT / 'rebuild/2008-06/out/native-layouts/declaration-view'; OUT.mkdir(parents=True, exist_ok=True)
FLAGS = flags()
NEEDLES = ('operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );',
           'const _Elem * c_str() const',
           'bool IsEmpty() const throw()\n\t{\n\t\treturn( GetLength() == 0 );')
tool = rebuild.toolchain(21022)
def build(name='CDeclarationView'):
    src = ROOT / 'rebuild/2008-06/native-classes' / (name + '.cpp')
    code, log = rebuild.run(tool, 'cl', [x for x in FLAGS if x != '/c'] + ['/P', str(src)], OUT)
    assert code == 0, log[-3000:]
    body = (OUT / (name + '.i')).read_text(errors='replace')
    for n in NEEDLES:
        n = n.encode().decode('unicode_escape')
        assert body.count(n) == 1, n
        body = body.replace(n, '__declspec(noinline) ' + n)
    unit = OUT / ('Native' + name[1:] + 'Profile.cpp'); unit.write_text(body)
    obj = OUT / ('Native' + name[1:] + 'Profile.obj')
    code, log = rebuild.run(tool, 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD', '/Fo' + str(obj), str(unit)], OUT)
    assert code == 0, log[-3000:]
    return obj
if __name__ == '__main__':
    args = sys.argv[1:]; verbose = '-v' in args; args = [a for a in args if a != '-v']
    name = 'CDeclarationView'
    if '--src' in args: i = args.index('--src'); name = args[i + 1]; del args[i:i + 2]
    funcs = match.coff_functions(build(name).read_bytes())
    if not args:
        for f in funcs: print(len(f[1]), f[0])
    for spec in args:
        p, ad = spec.rsplit('=', 1)
        hits = [f for f in funcs if f[0].startswith(p)]
        if not hits: print('MISSING', p); continue
        n, b, r = hits[0]; t, tr, _ = match.target('2008-06', ad)
        ok = match.exact_match(t, tr, b, r)
        print('EXACT' if ok else 'DIFF ', ad, n[:70], len(b), len(t))
        if not ok and verbose: print(match.diff(t, tr, b, r)[:6000])
