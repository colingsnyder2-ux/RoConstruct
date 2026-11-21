"""Generic template-member lane (no model).  A remaining function that is a member of a class template has its whole
instantiation spelled in the registry signature (`... std::_Tree<class std::_Tmap_traits<...> >::insert(...)`).
Vendor/native headers already define the template body, so the function exists as soon as the instantiation is
requested: variant A `template class X<args>;`, variant B the single member
`template R X<args>::member(params) cv;`.  Each variant is gated against the registry's decorated symbol; byte-exact
ones become rebuild/2008-06/native-classes/TmplInst_<addr>.cpp (same bookkeeping as template_instances.py).
  python work/native-client/generic_templates.py [--jobs 8] [--limit N] [--dry]"""
import argparse
import collections
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--jobs', type=int, default=8)
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--dry', action='store_true')
ap.add_argument('--trial', action='store_true', help='gate but never write sources (safe during a census)')
args = ap.parse_args()
if not args.dry and not args.trial and (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: source writes would void it (prove-out/CENSUS.lock)')
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
import native_llm as m                # noqa: E402
import native_creator_gate as cg      # noqa: E402

ROOT = m.ROOT
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
WORK = HERE / 'generic-templates'
STD = ('#include <map>\n#include <set>\n#include <list>\n#include <vector>\n#include <string>\n#include <algorithm>\n'
       '#include <functional>\n#include <memory>\n#include <boost/shared_ptr.hpp>\n#include <boost/weak_ptr.hpp>\n'
       '#include <boost/function.hpp>\n#include <boost/bind.hpp>\n#include <boost/any.hpp>\n')
SIG = re.compile(r'^(?:(?:public|private|protected): )?(?:virtual |static )*(?P<ret>.*?)\s*__(?:thiscall|cdecl|stdcall)\s+'
                 r'(?P<rest>.+)$')


def cxx(text):
    text = re.sub(r'\b(?:class|struct|enum|union) ', '', text).replace(' >', '>')
    while '>>' in text:                     # VS2008 parses `>>` as a shift
        text = text.replace('>>', '> >')
    return text.strip()


def split_member(rest):
    """`A<..>::B<..>::member(params)const ` -> (class_spec, member, params, cv); None when not a class-template member."""
    depth, last, par = 0, -1, -1
    for i, ch in enumerate(rest):
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth -= 1
        elif ch == '(' and depth == 0:
            par = i
            break
        elif ch == ':' and depth == 0 and rest[i:i + 2] == '::':
            last = i
    if par < 0:
        return None
    owner, member = (rest[:last], rest[last + 2:par]) if last >= 0 else ('', rest[:par])
    if '<' not in owner and '<' not in member:
        return None                          # neither a class-template member nor a function template
    close = rest.rfind(')')
    return owner, member, rest[par + 1:close], rest[close + 1:].strip()


G3D_INC = ROOT / 'tools/rbxgs/Client/Rendering/g3d/include'


def headers_for(text):
    out = []
    for name in dict.fromkeys(re.findall(r'\b((?:\w+::)*[A-Z]\w+)\b', text)):
        parts = name.split('::')
        for cut in range(len(parts), 0, -1):         # RBX::Network::AbuseReport::Message -> try shorter owners too
            h = m.declaring_header('::'.join(parts[:cut]))
            if h and Path(h).is_relative_to(HEADERS):
                if h not in out:
                    out.append(h)
                break
    return out[:12]


def vendor_includes(text):
    """SDK/vendor headers the instantiation names: ATL (after MFC), G3D value types."""
    inc = ''
    if 'ATL::' in text or re.search(r'\bC(?:Com|Simple|Atl)\w+<', text):
        inc += '#include <afxwin.h>\n#include <atlbase.h>\n#include <atlcom.h>\n#include <atlcoll.h>\n#include <atlstr.h>\n'
    for name in dict.fromkeys(re.findall(r'\bG3D::(\w+)', text)):
        if (G3D_INC / 'G3D' / (name + '.h')).is_file():
            inc += '#include <G3D/%s.h>\n' % name
    return inc


def variants(sig):
    hit = SIG.match(sig.strip())
    if not hit:
        return None
    parts = split_member(hit.group('rest'))
    if not parts:
        return None
    cls, member, params, cv = parts
    if '`' in hit.group('rest') or re.search(r'<(?:E|T|X)[,>]', cls):       # initializer rows / junk registry args
        return None
    cls = re.sub(r'&char(?: const)? \*(?: const)? ', '', cls)                 # string template argument: &char * RBX::sX
    cls_c, ret, params_c = cxx(cls), cxx(hit.group('ret')), cxx(params)
    if params_c == 'void':
        params_c = ''
    if '<' not in cls:                       # function template (free, or a member template of a plain class)
        member_c = cxx(re.sub(r'&char(?: const)? \*(?: const)? ', '', member))
        return cls_c + ' ' + member_c, [('function', 'template %s %s%s(%s)%s;\n' % (
            ret, (cls_c + '::') if cls_c else '', member_c, params_c, (' ' + cv) if cv else ''))]
    out = [('class', 'template class %s;\n' % cls_c)]
    leaf = re.sub(r'<.*', '', cls.rsplit('::', 1)[-1])
    if not member.startswith(('~', 'operator')) and member != leaf and '`' not in member:
        out.append(('member', 'template %s %s::%s(%s)%s;\n' % (ret, cls_c, member, params_c, (' ' + cv) if cv else '')))
    return cls_c, out


def run(addr):
    row = reg.get(addr) or {}
    made = variants(row.get('signature') or '')
    if not made:
        return addr, 'no-shape', ''
    cls_c, codes = made
    headers = headers_for(cls_c + ' ' + (row.get('signature') or '')) + [str(HEADERS / 'util/Object.h')]
    if args.dry:
        return addr, 'dry', codes[0][1].strip()[:150]
    last = ''
    for kind, line in codes:
        code = vendor_includes(cls_c + ' ' + line) + STD + line
        cg.EXPECT[addr] = row['name']
        try:
            status, detail = cg.gate_code(WORK / addr, headers, code, {addr: row['name']})
        except Exception as error:                               # noqa: BLE001
            last = 'harness-error ' + repr(error)[:80]
            continue
        st = status.get(addr, 'missing')
        last = st
        if st == 'inactive_exact':
            if args.trial or (HERE / 'prove-out/CENSUS.lock').is_file():
                return addr, 'exact-not-written', kind
            tu = CLASSES / ('TmplInst_%s.cpp' % addr)
            tu.write_text('// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL\n'
                          '// %08x %s: explicit template instantiation (generic_templates.py, %s form, byte-proved standalone)\n%s%s\n%s'
                          % (int(addr, 16), row['name'][:110], kind, vendor_includes(cls_c + ' ' + line) + STD,
                             ''.join('#include "%s"\n' % Path(h).relative_to(HEADERS).as_posix() for h in dict.fromkeys(headers)),
                             line))
            return addr, st, tu.relative_to(ROOT).as_posix()
    return addr, last, ''


reg = m.load_registry()
cl = json.loads((HERE / 'remaining-classified.json').read_text())
done = json.loads((HERE / 'template-instance-hits.json').read_text()) if (HERE / 'template-instance-hits.json').is_file() else {}
targets = [a for a, v in cl.items() if a not in done and v.get('bucket') != 'vendor-library'
           and variants((reg.get(a) or {}).get('signature') or '')
           and (reg.get(a) or {}).get('name', '').startswith('?')]
targets = sorted(targets, key=lambda a: cl[a]['size'])[:args.limit or None]
print('generic template-member targets: %d' % len(targets), flush=True)
counts = collections.Counter()
with ThreadPoolExecutor(1 if args.dry else args.jobs) as pool:
    for addr, status, detail in pool.map(run, targets):
        counts[status.split(' ')[0]] += 1
        if args.dry and counts['dry'] > 6:
            continue
        print(addr, status, detail, flush=True)
        if status == 'inactive_exact' and detail:
            done[addr] = detail
            (HERE / 'template-instance-hits.json').write_text(json.dumps(done, indent=1))
            src = HERE / 'class-lane-new-sources.json'
            lst = json.loads(src.read_text()) if src.is_file() else []
            if detail not in lst:
                src.write_text(json.dumps(lst + [detail], indent=1))
print('RESULT generic templates: %s' % dict(counts), flush=True)
