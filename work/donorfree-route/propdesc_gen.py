"""python propdesc_gen.py: scans linkexp/qt.map for stubbed RefPropDescriptor, PropDescriptor,
EnumPropDescriptor, EnumDesc, and BoundProp instantiations -> emits one explicit-instantiation
.cpp per header/type under work/native-client/stub-drafts/Gemini_PropDesc_*.cpp, compiles via
native_check_runner.py, verifies defined symbols with roc.rebuild.coff_externals, and appends
clean results.json to work/native-client/GEMINI_RESULTS.txt.
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
BS = chr(92)

_dbg = ctypes.windll.dbghelp
_dbg.UnDecorateSymbolName.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_uint, ctypes.c_uint]
_dbg.UnDecorateSymbolName.restype = ctypes.c_uint


def und_name_only(sym: str) -> str:
    buf = ctypes.create_string_buffer(4096)
    n = _dbg.UnDecorateSymbolName(sym.encode('ascii', 'ignore'), buf, 4096, 0x1000)
    return buf.value.decode('ascii', 'ignore') if n else ''


def extract_outer_class(demangled: str, marker: str):
    """Extract `RBX::Reflection::<marker><...>` with balanced angle brackets."""
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
    cls_hdr, enum_hdr = {}, {}
    skip_dirs = {'boundfunc-call3', 'creatable-n-params', 'nullable-class-name', 'part-embedded', 'part-resize', 'content-cache-inline', 'engine-world'}
    # Prefer canonical native headers over *2008.h / Native*.h duplicates
    hdrs = sorted(HDR.rglob('*.h'), key=lambda p: ('2008' in p.name or 'Native' in p.name or 'Gyro.h' == p.name, p.as_posix()))
    for h in hdrs:
        if any(s in h.parts for s in skip_dirs):
            continue
        rel = h.relative_to(HDR).as_posix()
        txt = h.read_text(errors='replace')
        for m in re.finditer(r'^\s*(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?(\w+)\s*(?::|\{)', txt, re.M):
            cls_hdr.setdefault(m.group(1), rel)
        for m in re.finditer(r'^\s*enum\s+(\w+)\s*\{', txt, re.M):
            enum_hdr.setdefault(m.group(1), rel)
    return cls_hdr, enum_hdr


def headers_for_spec(spec: str, cls_hdr: dict, enum_hdr: dict):
    incs = []
    inner = spec[spec.find('<') + 1:-1]
    for tok in re.findall(r'\b[A-Za-z_]\w*\b', inner):
        if tok in cls_hdr and cls_hdr[tok] not in incs:
            incs.append(cls_hdr[tok])
        if tok in enum_hdr and enum_hdr[tok] not in incs:
            incs.append(enum_hdr[tok])
    return incs


def clean_spec(spec: str) -> str:
    # MSVC explicit instantiation dislikes `enum ` / `class ` inside some template args? Actually MSVC accepts them,
    # except `class std::basic_string<...>` is fine. Clean `> >` is already spaced by dbghelp.
    return spec


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
    cls_hdr, enum_hdr = index_headers()
    markers = ['RefPropDescriptor', 'PropDescriptor', 'EnumPropDescriptor', 'EnumDesc', 'BoundProp']
    stubs = []
    for line in (H / 'linkexp/qt.map').open(errors='replace'):
        p = line.split()
        if len(p) >= 4 and 'stubs' in p[-1]:
            if any(f'?${m}@' in p[1] for m in markers):
                stubs.append(p[1])

    specs = {}  # (marker, spec) -> list of stub syms
    for sym in stubs:
        dem = und_name_only(sym)
        for m in markers:
            sp = extract_outer_class(dem, m)
            if sp:
                specs.setdefault((m, sp), []).append(sym)
                break

    DRAFTS.mkdir(parents=True, exist_ok=True)
    jobs = []
    for idx, ((marker, spec), syms) in enumerate(sorted(specs.items())):
        incs = headers_for_spec(spec, cls_hdr, enum_hdr)
        base_incs = ['reflection/reflection.h', 'reflection/enumconverter.h', 'util/Object.h', 'v8datamodel/BrickColor.h', 'util/ContentProvider.h']
        all_incs = []
        for h in base_incs + incs:
            if h not in all_incs:
                all_incs.append(h)
        src = DRAFTS / f'Gemini_PropDesc_{idx:03d}.cpp'
        inc_lines = '\n'.join(f'#include "{h}"' for h in all_incs)
        cspec = clean_spec(spec)
        force = f'typedef {cspec} _GemT;\nvoid _gem_force_{idx}(_GemT* p, _GemT* a) {{ delete p; delete[] a; }}\n'
        if marker == 'RefPropDescriptor':
            force = (f'typedef {cspec} _GemT;\n'
                     f'void _gem_force_{idx}(_GemT* p, _GemT* a) {{\n'
                     f'    volatile bool b1 = p->equalValues(0, 0);\n'
                     f'    volatile bool b2 = p->isReadOnly();\n'
                     f'    p->readValue(0, 0, *(RBX::IReferenceBinder*)0);\n'
                     f'    p->writeValue(0, 0);\n'
                     f'    p->setRefValue(0, 0);\n'
                     f'    delete p; delete[] a;\n}}\n')
        elif marker == 'EnumDesc':
            force = f'typedef {cspec} _GemT;\nconst _GemT& _gem_force_{idx}() {{ return _GemT::singleton(); }}\n'
        src.write_text(
            '// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS\n'
            '// generated by work/donorfree-route/propdesc_gen.py\n'
            f'{inc_lines}\n\n'
            f'template class {cspec};\n'
            f'{force}'
        )
        jobs.append({'source': str(src), 'checks': [], 'ranges': [], 'layouts': []})

    resf, rows = run_manifest(jobs, 'Gemini_PropDesc')
    ok_jobs, ok_defs, failed = [], set(), []
    for job, row in zip(jobs, rows):
        if row.get('status') == 'complete' and row.get('object'):
            ok_jobs.append(job)
            ok_defs |= {k for k, v in rb.coff_externals(Path(row['object']).read_bytes()).items() if v}
        else:
            failed.append(Path(job['source']).name)

    # Re-run clean subset if any failed so GEMINI_RESULTS.txt only gets 0-failure runs
    final_resf = resf
    if failed and ok_jobs:
        final_resf, _ = run_manifest(ok_jobs, 'Gemini_PropDesc_Clean')

    matched = [s for s in stubs if s in ok_defs]
    if final_resf and ok_jobs:
        existing = GEMINI_RESULTS.read_text().splitlines() if GEMINI_RESULTS.exists() else []
        if final_resf not in existing:
            with GEMINI_RESULTS.open('a') as f:
                f.write(final_resf + '\n')

    print(f'propdesc_gen: stubs={len(stubs)} specs={len(specs)} ok={len(ok_jobs)} failed={len(failed)} matched_stubs={len(matched)}')
    if failed:
        print('failed:', ', '.join(failed[:15]))
    print(final_resf)


if __name__ == '__main__':
    main()
