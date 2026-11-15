"""Free gate for template instantiations the website counts as remaining: the real native headers plus one explicit
instantiation of the exact member (`template bool RBX::Reflection::TypedPropertyDescriptor<...>::equalValues(...) const;`)
through roc native-bulk with closure identity evidence.  No model call, no source write: an exact result is evidence that
the header template body already reproduces the original; a miss lists the template for header work.
Usage: python native_template_gate.py [--limit N] [--jobs J]"""
import argparse
import collections
import json
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.argv, ARGS = sys.argv[:1], sys.argv[1:]
import native_llm as m  # noqa: E402

ap = argparse.ArgumentParser()
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--jobs', type=int, default=6)
ap.add_argument('--retry', nargs='*', default=[], help='statuses to gate again (compile_failed missing no-header)')
args = ap.parse_args(ARGS)
ROOT = m.ROOT
OUT = ROOT / 'work/native-client/template-gate'
RESULTS = OUT / 'results.json'
VENDOR = ('std::', 'boost::', 'G3D::', 'ATL::', 'Ogre::', 'stdext::', 'CXTP', 'Wml::')

registry = json.loads(m.REGISTRY.read_text())
names = collections.Counter(r.get('name') for r in registry.values())
remaining = m.remaining_set()
results = json.loads(RESULTS.read_text()) if RESULTS.is_file() else {}


def instantiation(sig):
    """`public: virtual bool __thiscall NS::T<A>::f(x) const` -> `template bool NS::T<A>::f(x) const;`"""
    sig = re.sub(r'^(?:public|private|protected): ', '', sig)
    sig = re.sub(r'\b(?:virtual|static) |\b__(?:thiscall|cdecl|stdcall|fastcall) ', '', sig)
    return 'template ' + sig.strip() + ';'


BOOST = ROOT / 'tools/rbxgs/Client/boost_1_34_1/src'
G3D_INC = ROOT / 'tools/rbxgs/Client/Rendering/g3d/include'


def vendor_include(name):
    """<boost/any.hpp> for boost::any_cast, <G3D/Vector3.h> for G3D::Vector3 (vendor names the signature uses)."""
    parts = name.split('::')
    if parts[0] == 'boost' and len(parts) > 1:
        for stem in (parts[1], parts[1].replace('_cast', ''), parts[1].split('_')[0]):
            if (BOOST / 'boost' / (stem + '.hpp')).is_file():
                return '<boost/%s.hpp>' % stem
    if parts[0] == 'G3D' and len(parts) > 1 and (G3D_INC / 'G3D' / (parts[1] + '.h')).is_file():
        return '<G3D/%s.h>' % parts[1]
    return None


def headers_for(sig):
    """Native (else donor) headers defining every RBX-ish class the signature names, template owner first;
    vendor names (boost::, G3D::) map to their own headers."""
    out = []
    for name in dict.fromkeys(re.findall(r'\b((?:[A-Za-z_]\w*::)*[A-Za-z_]\w*)(?=\s*<|\s*::|\s*[\s*&>,)])', sig)):
        vendor = vendor_include(name) if name.startswith(VENDOR) else None
        if vendor and vendor not in out:
            out.append(vendor)
        if name.startswith(VENDOR) or name in ('class', 'struct', 'enum', 'const', 'unsigned', 'int', 'char', 'bool',
                                                'void', 'float', 'double', 'long', 'short', 'template'):
            continue
        header = m.declaring_header(name)
        if header and header not in out:
            out.append(header)
    return out


def gate(addr):
    row = registry[addr]
    sig = row['signature']
    work = OUT / addr
    work.mkdir(parents=True, exist_ok=True)
    headers = headers_for(sig)
    if not [h for h in headers if not h.startswith('<')]:
        return addr, 'no-header', ''
    flags = '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I%s /I%s' % (ROOT / 'rebuild/2008-06/native-headers', m.DONOR_INCLUDE)
    probe = work / 'probe.cpp'
    # MFC headers anywhere in the chain need afxwin.h before windows.h (C1189); the previous result says so.
    mfc = '#include <afxwin.h>\n' if 'C1189' in (results.get(addr) or {}).get('detail', '') else ''
    probe.write_text('// native-flags: %s\n%s\n%s\n' % (
        flags, mfc + ''.join(('#include %s\n' % h) if h.startswith('<') else '#include "%s"\n' % Path(h).resolve().as_posix()
                             for h in headers), instantiation(sig)))
    closure = json.loads(m.CLOSURE.read_text())
    closure['bindings'] = [b for b in closure['bindings'] if b['addr'] != addr] + [dict(
        symbol=row['name'], addr=addr, address=addr, votes=1, evidence='identity-registry', body_exact=False,
        function_start=True)]
    (work / 'closure.json').write_text(json.dumps(closure))
    evidence = work / 'identity.json'
    ran = subprocess.run([sys.executable, str(ROOT / 'work/native-client/native_identity_evidence.py'), '--closure',
                          str(work / 'closure.json'), '--output', str(evidence), '--addr', addr],
                         cwd=ROOT, capture_output=True, text=True)
    if ran.returncode:
        return addr, 'tool-error', ran.stderr[-300:]
    config = work / 'bulk.json'
    rel = lambda p: p.relative_to(ROOT).as_posix()
    config.write_text(json.dumps({'client': '2008-06', 'roc_cl': 21022, 'targets': [addr], 'families': [
        {'name': 'template-gate', 'sources': [rel(probe)], 'evidence': [rel(evidence)]}]}))
    bulk = OUT / (addr + '-bulk')
    for _ in range(3):      # another session edits native headers live: 'inputs changed during compile' -> rerun
        subprocess.run([str(ROOT / 'roc.cmd'), 'native-bulk', str(config), '--out', str(bulk)], cwd=ROOT,
                       capture_output=True, text=True)
        try:
            manifest = json.loads((bulk / 'manifest.json').read_text())
        except (OSError, ValueError):
            return addr, 'tool-error', 'no manifest'
        if not any('inputs changed' in b for f in manifest['families'] for b in f.get('blockers', [])):
            break
    rows = [s for f in manifest['families'] for s in f['symbols'] if s.get('symbol') == row['name']]
    if not rows:
        logs = list(bulk.rglob('compile.log'))
        try:        # cache hits keep their compile.log elsewhere; the ledger names it
            logs += [Path(v['log']) for v in json.loads((bulk / 'ledger.json').read_text()).values()
                     if isinstance(v, dict) and v.get('log') and Path(v['log']).is_file()]
        except (OSError, ValueError):
            pass
        err = next((line for log in logs for line in log.read_text(errors='replace').splitlines()
                    if re.search(r'error C\d+', line)), '')
        if not err:
            warn = next((line for log in logs for line in log.read_text(errors='replace').splitlines()
                         if 'C4661' in line), '')
            if warn:
                return addr, 'needs-body', warn[-300:]     # header only declares the member: a body must be written
        return addr, 'compile_failed' if err else 'missing', err[-300:]
    import shutil
    shutil.rmtree(bulk, ignore_errors=True)        # objects + logs: GBs over hundreds of targets
    (work / 'closure.json').unlink(missing_ok=True)
    status = rows[0]['status']
    detail = '; '.join(e for j in rows[0].get('rejections', []) for e in j.get('errors', []))[:300]
    return addr, status, detail


targets = [a for a in sorted(remaining) if a in registry and (a not in results or results[a]['status'] in args.retry)
           and ((registry[a].get('name') or '').startswith('??$') or '<' in (registry[a].get('owner_class') or ''))
           and names[registry[a]['name']] == 1 and registry[a].get('signature')
           and not (registry[a].get('owner_class') or '').startswith(VENDOR)]
targets = targets[:args.limit or None]
print('template targets', len(targets), flush=True)
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, status, detail in pool.map(gate, targets):
        results[addr] = {'status': status, 'detail': detail, 'name': registry[addr]['name']}
        RESULTS.write_text(json.dumps(results, indent=1))
        print(addr, status, detail[:140], flush=True)
print(collections.Counter(r['status'] for r in results.values()))
