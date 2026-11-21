"""Template-instance lane (no model calls).  Remaining functions whose registry signature is a known template shape are
written as explicit instantiations - the recipe of AppUnit400_2008Creators.cpp - and gated standalone:
  Creatable<Instance>::create<X>()                     -> template shared_ptr<X> Creatable<Instance>::create<X>();
  FactoryProduct<C,D,sX>::Creator::create() const      -> Creator::create definition + explicit instantiation
  boost::any_cast<T>(const any*)                       -> template const T* boost::any_cast<T>(const boost::any*);
Exact ones become rebuild/2008-06/native-classes/TmplInst_<addr>.cpp (listed in class-lane-new-sources.json for the
census) and template-instance-hits.json.
  python work/native-client/template_instances.py [--jobs 8] [--limit N] [--dry]"""
import argparse
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--jobs', type=int, default=8)
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--creators', action='store_true', help='FactoryProduct Creator::create rows (class from creator-classes.json)')
ap.add_argument('--create', action='store_true', help='Creatable::create<X> rows with X from the ctor they call (create-classes.json)')
ap.add_argument('--dry', action='store_true', help='print generated code, no gate')
args = ap.parse_args()
if not args.dry and (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: evidence/source writes would void it (prove-out/CENSUS.lock)')
sys.argv = sys.argv[:1]
sys.path.insert(0, str(HERE))
import native_llm as m                # noqa: E402
import native_creator_gate as cg      # noqa: E402

ROOT = m.ROOT
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
WORK = HERE / 'template-instances'
CREATOR_DEF = '''namespace RBX
{
	// util/Object.h declares Creator::create() only (definition as in AppUnit400_2008Creators.cpp).
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}
'''


def cxx(t):
    """MSVC undecorated type -> C++ spelling (`class RBX::Team` -> `RBX::Team`, `char const *` stays)."""
    return re.sub(r'\b(?:class|struct|enum) ', '', t).strip()


def split_args(s):
    parts, depth, cur = [], 0, ''
    for ch in s:
        depth += {'<': 1, '>': -1}.get(ch, 0)
        if ch == ',' and depth == 0:
            parts.append(cur)
            cur = ''
        else:
            cur += ch
    return [p.strip() for p in parts + [cur]]


def headers_for(text):
    out = []
    for name in dict.fromkeys(re.findall(r'\b((?:RBX::)?(?:\w+::)*[A-Z]\w+)\b', text)):
        if name in ('RBX::Object','RBX::Creatable', 'RBX::FactoryProduct'):
            continue
        h = m.declaring_header(name)
        if h and Path(h).is_relative_to(HEADERS) and h not in out:
            out.append(h)
    return out


def generate(addr, sig):
    found = re.search(r'Creatable<class RBX::Instance>::create<(.+)>\(void\)$', sig)
    if found:
        x = cxx(found.group(1))
        return 'creatable', headers_for(x), 'template boost::shared_ptr<%s> RBX::Creatable<RBX::Instance>::create<%s>();\n' % (x, x)
    found = re.search(r'RBX::FactoryProduct<(.+)>::Creator::create\(void\) ?const$', sig)
    if found:
        parts = split_args(found.group(1))
        if len(parts) != 3:
            return None
        c, d = cxx(parts[0]), cxx(parts[1])
        n = re.sub(r'^&char(?: const)? \*(?: const)? ', '', parts[2]).strip()
        return 'creator', headers_for(c + ' ' + d), CREATOR_DEF + (
            'template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<%s, %s, %s>::Creator::create() const;\n' % (c, d, n))
    found = re.search(r'boost::any_cast<(.+)>\(class boost::any const \*\)$', sig)
    if found:
        t = cxx(found.group(1))
        return 'any_cast', headers_for(t), '#include <boost/any.hpp>\ntemplate %s const* boost::any_cast<%s>(const boost::any*);\n' % (t, t)
    return None


def run(addr):
    row = dict(reg.get(addr) or {})
    if args.creators:
        # The registry gives all of these one shared (wrong) name; the class comes from the code installing the
        # Creator vtable whose slot 0 is this function (creator-classes.json), the symbol from the compiled probe.
        row['signature'] = 'x RBX::FactoryProduct<%s>::Creator::create(void)const' % CREATORS[addr]
    if args.create:
        row['signature'] = 'x RBX::Creatable<class RBX::Instance>::create<%s>(void)' % CREATES[addr]
    gen = generate(addr, (row.get('signature') or '').strip())
    if not gen:
        return addr, 'no-shape', ''
    kind, headers, code = gen
    headers = headers + [str(HEADERS / 'util/Object.h')]
    if args.dry:
        return addr, 'dry', '%s %s\n%s' % (kind, [Path(h).relative_to(HEADERS).as_posix() for h in headers], code)
    if args.creators or args.create:
        needle = 'create@Creator@' if args.creators else '$create@V%s@' % CREATES[addr].split('::')[-1]
        sym = cg.discover_symbol(WORK / addr, headers, code, addr, needle)
        if not sym:
            return addr, 'no-symbol', (cg.LAST_ERROR.get(addr) or '')[:200]
        row['name'] = SYMS[addr] = sym
    try:
        status, detail = cg.gate_code(WORK / addr, headers, code, {addr: row['name']})
    except Exception as error:                                   # noqa: BLE001
        return addr, 'harness-error', repr(error)
    st = status.get(addr, 'missing')
    if st == 'inactive_exact':
        tu = CLASSES / ('TmplInst_%s.cpp' % addr)
        sdk = ''.join(l + '\n' for l in code.splitlines() if l.startswith('#include'))
        body = '\n'.join(l for l in code.splitlines() if not l.startswith('#include'))
        tu.write_text('// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL\n'
                      '// %08x %s: explicit template instantiation (template_instances.py, byte-proved standalone)\n%s%s\n%s\n'
                      % (int(addr, 16), row['name'][:120], sdk,
                         ''.join('#include "%s"\n' % Path(h).relative_to(HEADERS).as_posix() for h in dict.fromkeys(headers)),
                         body))
        return addr, st, tu.relative_to(ROOT).as_posix()
    return addr, st, (detail or '')[:200]


reg = m.load_registry()
cl = json.loads((HERE / 'remaining-classified.json').read_text())
SYMS = {}
CREATORS = json.loads((HERE / 'creator-classes.json').read_text()) if args.creators else {}
CREATES = json.loads((HERE / 'create-classes.json').read_text()) if args.create else {}
targets = sorted(CREATORS) if args.creators else sorted(CREATES) if args.create else [a for a in cl if generate(a, ((reg.get(a) or {}).get('signature') or '').strip())
           and 'Creator::create' not in ((reg.get(a) or {}).get('signature') or '')]   # shared wrong name: --creators
done_hits = json.loads((HERE / 'template-instance-hits.json').read_text()) if (HERE / 'template-instance-hits.json').is_file() else {}
targets = [a for a in targets if a not in done_hits][:args.limit or None]
print('template-instance targets: %d' % len(targets), flush=True)
hits_path = HERE / 'template-instance-hits.json'
hits = json.loads(hits_path.read_text()) if hits_path.is_file() else {}
counts = {}
with ThreadPoolExecutor(1 if args.dry else args.jobs) as pool:
    for addr, status, detail in pool.map(run, targets):
        counts[status] = counts.get(status, 0) + 1
        if args.dry:
            print(addr, detail, flush=True)
            continue
        print(addr, status, detail.splitlines()[0][:150] if detail else '', flush=True)
        if status == 'inactive_exact':
            if args.creators or args.create:       # real symbol for the census (the registry name is a shared wrong one)
                ev_path = HERE / 'creator-identity-bindings.json'
                ev = json.loads(ev_path.read_text()) if ev_path.is_file() else {'identity_bindings': []}
                rows = ev['identity_bindings']
                sym = SYMS.get(addr)
                if sym and not any(b.get('address') == addr and b.get('symbol') == sym for b in rows):
                    rows.append({'symbol': sym, 'address': addr, 'votes': 1, 'identity_evidence':
                                 ('Creator vtable slot 0 installed by FactoryProduct<%s> code; body byte-proved' % CREATORS[addr][:120])
                                 if args.creators else ('calls the %s constructor; body byte-proved' % CREATES[addr])})
                    ev_path.write_text(json.dumps(ev, indent=1))
            hits[addr] = detail
            hits_path.write_text(json.dumps(hits, indent=1))
            src = HERE / 'class-lane-new-sources.json'
            lst = json.loads(src.read_text()) if src.is_file() else []
            if detail not in lst:
                src.write_text(json.dumps(lst + [detail], indent=1))
print('RESULT template instances: %s' % counts, flush=True)
