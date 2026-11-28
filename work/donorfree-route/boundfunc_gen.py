"""python boundfunc_gen.py: scans linkexp/qt.map for stubbed BoundFuncDesc<C, Sig, N> (and 2-arg
BoundFuncDesc<C, Sig>) instantiations -> emits one explicit-instantiation .cpp per specialization
under work/native-client/stub-drafts/Gemini_BoundFunc_*.cpp, compiles via native_check_runner.py,
appends clean results.json to work/native-client/GEMINI_RESULTS.txt, and appends verified 2-arg->3-arg
NAME=TARGET aliases to work/donorfree-route/aliases_gemini.txt.
"""
import ctypes, json, re, subprocess, sys
from pathlib import Path

H = Path(__file__).parent
ROOT = H.parents[1]
sys.path.insert(0, str(ROOT))
from roc import rebuild as rb

HDR = ROOT / 'rebuild/2008-06/native-headers'
DRAFTS = ROOT / 'work/native-client/stub-drafts'
GEMINI_RESULTS = ROOT / 'work/native-client/GEMINI_RESULTS.txt'
ALIASES_OUT = H / 'aliases_gemini.txt'
BS = chr(92)

_dbg = ctypes.windll.dbghelp
_dbg.UnDecorateSymbolName.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_uint, ctypes.c_uint]
_dbg.UnDecorateSymbolName.restype = ctypes.c_uint


def und_name_only(sym: str) -> str:
    buf = ctypes.create_string_buffer(4096)
    n = _dbg.UnDecorateSymbolName(sym.encode('ascii', 'ignore'), buf, 4096, 0x1000)
    return buf.value.decode('ascii', 'ignore') if n else ''


def extract_outer_class(demangled: str, marker: str):
    idx = demangled.find(f'RBX::Reflection::{marker}<')
    if idx < 0:
        return None
    i = demangled.find('<', idx)
    depth = 0
    for j in range(i, len(demangled)):
        c = demangled[j]
        if c == '<':
            depth += 1
        elif c == '>':
            depth -= 1
            if depth == 0:
                return demangled[idx:j + 1]
    return None


def index_headers():
    cls_hdr = {}
    skip_dirs = {'boundfunc-call3', 'creatable-n-params', 'nullable-class-name', 'part-embedded', 'part-resize', 'content-cache-inline', 'engine-world'}
    hdrs = sorted(HDR.rglob('*.h'), key=lambda p: ('2008' in p.name or 'Native' in p.name or 'Gyro.h' == p.name, p.as_posix()))
    for h in hdrs:
        if any(s in h.parts for s in skip_dirs):
            continue
        rel = h.relative_to(HDR).as_posix()
        txt = h.read_text(errors='replace')
        for m in re.finditer(r'^\s*(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?(\w+)\s*(?::|\{)', txt, re.M):
            cls_hdr.setdefault(m.group(1), rel)
    return cls_hdr


def headers_for_spec(spec: str, cls_hdr: dict):
    incs = []
    inner = spec[spec.find('<') + 1:-1]
    for tok in re.findall(r'\b[A-Za-z_]\w*\b', inner):
        if tok in cls_hdr and cls_hdr[tok] not in incs:
            incs.append(cls_hdr[tok])
    return incs


def normalize_boundfunc_spec(spec: str) -> str:
    # Remove __cdecl inside function type: `void __cdecl(double)` -> `void(double)`
    s = spec.replace(' __cdecl(', '(')
    # If 2-arg BoundFuncDesc<C, R(void)>, add `,0` (default arity 0 in 2008 native reflection.h)
    inner = s[s.find('<') + 1:-1].strip()
    if not re.search(r',\s*\d+\s*$', inner):
        s = s[:-1] + ', 0>'
    return s


def run_manifest(jobs, tag: str):
    man = DRAFTS / f'{tag}.json'
    man.write_text(json.dumps({'compiler_build': 21022, 'compiler_variant': 'default', 'jobs': jobs}, indent=2))
    r = subprocess.run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/native_check_runner.py'), 'run', str(man)],
                       capture_output=True, text=True)
    m = re.search(r'"results":"([^"]+)"', r.stdout)
    resf = m.group(1).replace(BS + BS, BS) if m else None
    rows = []
    if resf and Path(resf).exists():
        data = json.loads(Path(resf).read_text())
        rows = data if isinstance(data, list) else data.get('results', [])
    return resf, rows


def main():
    cls_hdr = index_headers()
    stubs = []
    for line in (H / 'linkexp/qt.map').open(errors='replace'):
        p = line.split()
        if len(p) >= 4 and 'stubs' in p[-1] and '?$BoundFuncDesc@' in p[1]:
            stubs.append(p[1])

    specs = {}
    cand_aliases = []
    for sym in stubs:
        dem = und_name_only(sym)
        sp = extract_outer_class(dem, 'BoundFuncDesc')
        if sp:
            nsp = normalize_boundfunc_spec(sp)
            specs.setdefault(nsp, []).append(sym)
            # Check 2-arg -> 3-arg ($0A@) alias candidate
            if '@Z@Reflection@RBX@@' in sym:
                cand_aliases.append((sym, sym.replace('@Z@Reflection@RBX@@', '@Z$0A@@Reflection@RBX@@', 1)))

    DRAFTS.mkdir(parents=True, exist_ok=True)
    jobs = []
    for idx, spec in enumerate(sorted(specs.keys())):
        incs = headers_for_spec(spec, cls_hdr)
        base_incs = ['reflection/reflection.h', 'reflection/BoundFuncDesc.h', 'util/Object.h', 'util/ContentProvider.h']
        all_incs = []
        for h in base_incs + incs:
            if h not in all_incs:
                all_incs.append(h)
        src = DRAFTS / f'Gemini_BoundFunc_{idx:03d}.cpp'
        inc_lines = '\n'.join(f'#include "{h}"' for h in all_incs)
        src.write_text(
            '// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS\n'
            '// generated by work/donorfree-route/boundfunc_gen.py\n'
            f'{inc_lines}\n\n'
            f'template class {spec};\n'
            f'typedef {spec} _GemBF;\n'
            f'void _gem_bf_force_{idx}(_GemBF* p, _GemBF* a) {{ delete p; delete[] a; }}\n'
        )
        jobs.append({'source': str(src), 'checks': [], 'ranges': [], 'layouts': []})

    resf, rows = run_manifest(jobs, 'Gemini_BoundFunc')
    ok_jobs, ok_defs, failed = [], set(), []
    for job, row in zip(jobs, rows):
        if row.get('status') == 'complete' and row.get('object'):
            ok_jobs.append(job)
            ok_defs |= {k for k, v in rb.coff_externals(Path(row['object']).read_bytes()).items() if v}
        else:
            failed.append(Path(job['source']).name)

    final_resf = resf
    if failed and ok_jobs:
        final_resf, _ = run_manifest(ok_jobs, 'Gemini_BoundFunc_Clean')

    matched = [s for s in stubs if s in ok_defs]
    verified_aliases = sorted({f'{a}={b}' for a, b in cand_aliases if a not in ok_defs and b in ok_defs})
    if verified_aliases:
        existing_a = set(ALIASES_OUT.read_text().splitlines()) if ALIASES_OUT.exists() else set()
        new_a = [a for a in verified_aliases if a not in existing_a]
        if new_a:
            with ALIASES_OUT.open('a') as f:
                for a in new_a:
                    f.write(a + '\n')

    if final_resf and ok_jobs:
        existing = GEMINI_RESULTS.read_text().splitlines() if GEMINI_RESULTS.exists() else []
        if final_resf not in existing:
            with GEMINI_RESULTS.open('a') as f:
                f.write(final_resf + '\n')

    print(f'boundfunc_gen: stubs={len(stubs)} specs={len(specs)} ok={len(ok_jobs)} failed={len(failed)} matched_stubs={len(matched)} aliases={len(verified_aliases)}')
    if failed:
        print('failed:', ', '.join(failed[:15]))
    print(final_resf)


if __name__ == '__main__':
    main()
