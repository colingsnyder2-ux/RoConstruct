"""Free gate for FactoryProduct<X>::creator dynamic initializers (??__E) and atexit destructors (??__F) that the
identity session named (unnamed-identities.json): the class's native header + FactoryProduct template definitions
(Flag.cpp's block plus Creator ctor/dtor and the static member) + an explicit instantiation of `creator`.
No model call, no source write.  Usage: python native_creator_gate.py [--limit N] [--jobs J]"""
import argparse
import collections
import json
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ARGS = sys.argv[1:] if __name__ == '__main__' else []
sys.argv = sys.argv[:1]
import native_llm as m  # noqa: E402

ap = argparse.ArgumentParser()
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--jobs', type=int, default=4)
args = ap.parse_args(ARGS)
ROOT = m.ROOT
OUT = ROOT / 'work/native-client/creator-gate'
RESULTS = OUT / 'results.json'
OUT.mkdir(parents=True, exist_ok=True)
results = json.loads(RESULTS.read_text()) if RESULTS.is_file() else {}

DEFINITIONS = '''namespace RBX {
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::Creator::Creator() { getCreators()[&className()] = this; }
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::Creator::~Creator() { getCreators().erase(&className()); }
	template<class C, class D, const char* N>
	const typename FactoryProduct<C, D, N>::Creator FactoryProduct<C, D, N>::creator;
}
'''


def instance(sig):
    """`... 'private: static class RBX::FactoryProduct<A,B,&char const * const RBX::sX>::Creator const RBX::FactoryProduct<...>::creator''`
    -> template arguments as C++ (`RBX::A, RBX::B, RBX::sX`) and the class names to include."""
    found = re.search(r"FactoryProduct<(.*?)>::Creator const", sig)
    if not found:
        return None, []
    parts, depth, cur = [], 0, ''
    for ch in found.group(1):
        depth += {'<': 1, '>': -1}.get(ch, 0)
        if ch == ',' and depth == 0:
            parts.append(cur)
            cur = ''
        else:
            cur += ch
    parts.append(cur)
    parts = [re.sub(r'^(?:class|struct) ', '', p.strip()) for p in parts]
    parts[-1] = re.sub(r'^&char(?: const)? \*(?: const)? ', '', parts[-1])     # QBDB (const) and PADA (non-const) names
    return ', '.join(parts), [p for p in parts[:2]]


def gate(pair):
    cls, rows = pair
    e = next((a for a, r in rows if r['name'].startswith('??__E')), None)
    f = next((a for a, r in rows if r['name'].startswith('??__F')), None)
    sig = rows[0][1]['signature']
    targs, classes = instance(sig)
    if not targs:
        return cls, {a: 'unparsed' for a, _ in rows}, ''
    headers = [h for h in (m.declaring_header(c) for c in classes) if h]
    if not headers:
        return cls, {a: 'no-header' for a, _ in rows}, ''
    work = OUT / re.sub(r'\W+', '_', cls)[:60]
    # `creator` and `Creator` are private (explicit instantiation of them is C2248): instantiating the public inline
    # getCreator(), which returns creator, instantiates the static member's definition implicitly.
    code = '%s\ntemplate const RBX::ICreator& RBX::FactoryProduct<%s>::getCreator();\n' % (DEFINITIONS, targs)
    status, detail = gate_code(work, headers, code, {a: r['name'] for a, r in rows})
    return cls, status, detail


def gate_code(work, headers, code, want, keep=False):
    """Compile HEADERS + CODE as one probe and prove the WANT {addr: symbol} functions through native-bulk with closure
    identity evidence, learning callee identities from the candidate object (3 rounds).  -> ({addr: status}, detail)."""
    work.mkdir(parents=True, exist_ok=True)
    probe = work / 'probe.cpp'
    flags = '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I%s /I%s' % (ROOT / 'rebuild/2008-06/native-headers', m.DONOR_INCLUDE)
    vendor = m.header_include_flags(Path(headers[0]).resolve().relative_to(ROOT).as_posix(), '', [str(Path(h).resolve()) for h in headers[1:]])
    flags += (' ' + vendor) if vendor else ''      # RakNet (DS_LinkedList.h), Ogre, Scintilla roots the headers need
    probe.write_text('// native-flags: %s\n%s\n%s\n'
                     % (flags, ''.join('#include "%s"\n' % Path(h).resolve().as_posix() for h in dict.fromkeys(headers)), code))
    closure = json.loads(m.CLOSURE.read_text())
    closure['bindings'] = [b for b in closure['bindings'] if b['addr'] not in want] + [
        dict(symbol=n, addr=a, address=a, votes=1, evidence='identity-unlock-init', body_exact=False, function_start=True)
        for a, n in want.items()]
    (work / 'closure.json').write_text(json.dumps(closure))
    evidence = work / 'identity.json'
    ran = subprocess.run([sys.executable, str(ROOT / 'work/native-client/native_identity_evidence.py'), '--closure',
                          str(work / 'closure.json'), '--output', str(evidence), *sum((['--addr', a] for a in want), [])],
                         cwd=ROOT, capture_output=True, text=True)
    if ran.returncode:
        return {a: 'tool-error' for a in want}, ran.stderr[-300:]
    rel = lambda p: p.relative_to(ROOT).as_posix()
    config = work / 'bulk.json'
    config.write_text(json.dumps({'client': '2008-06', 'roc_cl': 21022, 'targets': sorted(want), 'families': [
        {'name': 'creator-gate', 'sources': [rel(probe)], 'evidence': [rel(evidence)]}]}))
    bulk = OUT / (work.name + '-bulk')
    for _ in range(3):
        subprocess.run([str(ROOT / 'roc.cmd'), 'native-bulk', str(config), '--out', str(bulk)], cwd=ROOT,
                       capture_output=True, text=True)
        try:
            manifest = json.loads((bulk / 'manifest.json').read_text())
        except (OSError, ValueError):
            return {a: 'tool-error' for a in want}, 'no manifest'
        if not any('inputs changed' in b for fam in manifest['families'] for b in fam.get('blockers', [])):
            break
    symbols = {s['symbol']: s for fam in manifest['families'] for s in fam['symbols']}
    status = {a: (symbols[n]['status'] if n in symbols else 'missing') for a, n in want.items()}
    # Bytes exact, only callee identities open (Creator::create in the vftable, std::map erase/operator[]): bind them
    # from the candidate object's relocations (native_reference_alias_bind.py) into this gate's closure, regate once.
    for _round in range(3):
        blocked = [a for a, n in want.items() if status[a] == 'draft' and n in symbols and all(
            e.startswith('unproven reference identity') for j in symbols[n].get('rejections', []) for e in j.get('errors', []))]
        objs = sorted(bulk.rglob('candidate.obj'))
        if not blocked or not objs:
            break
        learned = []
        for a in blocked:
            receipt = work / ('alias-%s.json' % a)
            subprocess.run([sys.executable, str(ROOT / 'work/native-client/native_reference_alias_bind.py'), '--object',
                            str(objs[-1]), '--symbol', want[a], '--address', a, '--closure', str(work / 'closure.json'),
                            '--output', str(receipt)], cwd=ROOT, capture_output=True, text=True)
            try:
                learned += json.loads(receipt.read_text()).get('identity_bindings', [])
            except (OSError, ValueError):
                pass
        have = {(b['symbol'], b['addr']) for b in closure['bindings']}
        new = [dict(symbol=b['symbol'], addr=b['address'], address=b['address'], votes=1,
                    evidence=b.get('identity_evidence', 'creator-gate-reference'), body_exact=False, function_start=False)
               for b in learned if (b['symbol'], b['address']) not in have and m.plausible_binding(b['symbol'], b['address'])]
        if not new:
            break
        closure['bindings'] += new
        (work / 'closure.json').write_text(json.dumps(closure))
        subprocess.run([sys.executable, str(ROOT / 'work/native-client/native_identity_evidence.py'), '--closure',
                        str(work / 'closure.json'), '--output', str(evidence), *sum((['--addr', a] for a in want), [])],
                       cwd=ROOT, capture_output=True, text=True)
        subprocess.run([str(ROOT / 'roc.cmd'), 'native-bulk', str(config), '--out', str(bulk)], cwd=ROOT,
                       capture_output=True, text=True)
        try:
            manifest = json.loads((bulk / 'manifest.json').read_text())
            symbols = {s['symbol']: s for fam in manifest['families'] for s in fam['symbols']}
            status = {a: (symbols[n]['status'] if n in symbols else 'missing') for a, n in want.items()}
        except (OSError, ValueError):
            break
    detail = ''
    objs = sorted(bulk.rglob('candidate.obj'))
    if objs and any(v == 'draft' for v in status.values()):
        # Byte drafts: the assembly diff is the model lane's feedback (native_init_llm.py).
        a = next(a for a, v in status.items() if v == 'draft')
        detail = subprocess.run([str(ROOT / 'roc.cmd'), 'native-asm', '2008-06', a, '--obj', str(objs[-1]), '--sym', want[a],
                                 '--context', '2', '--head', '60'], cwd=ROOT, capture_output=True, text=True).stdout[-2500:]
    if all(v == 'missing' for v in status.values()):
        logs = list(bulk.rglob('compile.log'))
        detail = next((line for log in logs for line in log.read_text(errors='replace').splitlines()
                       if re.search(r'error C\d+', line)), '')[-300:]
    elif not detail:
        detail = '; '.join(e for n in want.values() if n in symbols for j in symbols[n].get('rejections', [])
                           for e in j.get('errors', []))[:300]
    import shutil
    if not (keep or __import__('os').environ.get('KEEP')):
        shutil.rmtree(bulk, ignore_errors=True)
    (work / 'closure.json').unlink(missing_ok=True)
    return status, detail


def main():
  identities = json.loads((ROOT / 'work/native-client/unnamed-identities.json').read_text())
  pairs = collections.defaultdict(list)
  for addr, row in identities.items():
      found = re.match(r'\?\?__[EF]\?creator@\?\$FactoryProduct@(.*)$', row['name'])
      if found and addr not in results:
          pairs[found.group(1)].append((addr, row))
  todo = list(pairs.items())[:args.limit or None]
  print('creator pairs', len(todo), flush=True)
  with ThreadPoolExecutor(args.jobs) as pool:
      for cls, status, detail in pool.map(gate, todo):
          for addr, st in status.items():
              results[addr] = {'status': st, 'detail': detail, 'class': cls[:80]}
          RESULTS.write_text(json.dumps(results, indent=1))
          print(cls[:50], status, detail[:160], flush=True)
  print(collections.Counter(r['status'] for r in results.values()))


if __name__ == '__main__':
    main()
