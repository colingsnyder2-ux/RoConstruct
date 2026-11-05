"""Isolated original-MSVC evidence; no link, activation, or runtime claim."""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild

evidence = root / 'work/2008-06/shared-layouts/colin2-camera-predicates'
evidence.mkdir(parents=True, exist_ok=True)
out = root / 'rebuild/2008-06/out/colin2-camera-predicates'
out.mkdir(parents=True, exist_ok=True)
source = root / 'rebuild/2008-06/native-classes/CameraPredicates.cpp'
obj = out / 'CameraPredicates.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags = []
for flag in base['flags']:
    if flag.startswith('/Fo') or flag.endswith('NativeDocumentLayout.cpp'):
        continue
    if flag.startswith('/I'):
        parts = re.split(r'[\\/]+', flag[2:])
        index = next(i for i, part in enumerate(parts) if part in ('tools', 'rebuild'))
        flag = '/I' + str(root.joinpath(*parts[index:]))
    flags.append(flag)
flags += ['/fp:fast', '/showIncludes', '/Fo' + str(obj), str(source)]
tc = rebuild.toolchain(21022)
code, log = rebuild.run(tc, 'cl', flags, out)
(evidence / 'compile.txt').write_text(log, encoding='utf-8')
sha = lambda p: hashlib.sha256(Path(p).read_bytes()).hexdigest()
headers = {}
for line in log.splitlines():
    if 'including file:' in line:
        path = Path(line.split('including file:', 1)[1].strip())
        if path.is_file():
            headers[str(path)] = sha(path)
receipt = {
    'scope': 'Inactive Camera predicates; no linked ownership, complete class ABI, runtime, P5/P6 or server credit proof.',
    'compiler_build': 21022, 'compiler_sha256': sha(tc['cl']),
    'flags': flags, 'source_sha256': sha(source), 'observer_sha256': sha(__file__),
    'header_sha256': headers, 'compile_exit': code, 'compile_log_sha256': sha(evidence / 'compile.txt'),
    'original_sha256': sha(root / 'clients/2008-06/Roblox.exe'),
    'methods': [], 'unresolved': ['Camera complete layout/lifetime', 'Final linked provider and relocation ownership', 'Runtime validation'],
    'prior_evidence': ['research/log.jsonl:005cbf90-exact-20261020', 'research/graph/2008-06.json: no Camera nodes or edges'],
}
if code == 0:
    raw = obj.read_bytes()
    receipt['object_sha256'] = sha(obj)
    pe = pefile.PE(str(root / 'clients/2008-06/Roblox.exe'))
    imagebase = pe.OPTIONAL_HEADER.ImageBase
    relocs = {imagebase + e.rva for b in pe.DIRECTORY_ENTRY_BASERELOC for e in b.entries if e.type == 3}
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    for method, address, size in [('canZoom', 0x5cbf90, 98), ('canTilt', 0x5cc040, 127)]:
        name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?' + method + '@Camera@RBX@@'))
        target = pe.get_data(address - imagebase, size)
        targetrefs = {r - address for r in relocs if address <= r < address + size}
        code_exact = match.exact_match(target, targetrefs, body, refs)
        good, bad = match.data_check('2008-06', address, target, match.coff_data_refs(raw, name)) if code_exact else ([], ['Code differs; data correspondence not assumed'])
        edges = []
        start, secidx = definitions[name]
        section = sections[secidx]
        for i in range(section[7]):
            offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + i * 10)
            offset -= start
            if 0 <= offset < len(body) - 3:
                resolved = None
                if code_exact:
                    resolved = struct.unpack_from('<I', target, offset)[0]
                    if kind == 20:
                        resolved = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                edges.append({'offset': offset, 'kind': kind, 'symbol': symbols[symbol][0], 'original_target': hex(resolved) if resolved is not None else None})
        (evidence / (method + '-asm.txt')).write_text('\n'.join(
            [label + '\n' + '\n'.join(f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(data, address)) for label, data in [('original', target), ('candidate', body)]]
        ) + '\n', encoding='utf-8')
        receipt['methods'].append({'method': method, 'address': hex(address), 'symbol': name, 'original_size': size,
            'candidate_size': len(body), 'code_exact': code_exact, 'data_matches': good, 'data_mismatches': bad, 'relocations': edges})
(evidence / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
print(json.dumps({'compile_exit': code, 'methods': receipt['methods']}, indent=2))
sys.exit(1 if code else 0)
