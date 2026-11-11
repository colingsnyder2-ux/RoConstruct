"""Verify original split destructor ranges and stream-buffer RTTI; no runtime claim."""
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match

CASES = [
    ('HttpWinInet', 'WiniInetRequest_source', '005f9800', '005f9880', '005f98d0', '005f9900', 0x840eac),
    ('HttpWinHttp', 'WinHttpRequest_source', '005f3e80', '005f3f00', '005f3f50', '005f3fa0', 0x840a74),
]
base, image = match._image('2008-06')
rows = []
for unit, cls, ctor, head, tail, deleting, vtable in CASES:
    out = ROOT / 'out' / ('native-layout-' + unit)
    env = os.environ.copy()
    env['NATIVE_CHECK_OUT'] = str(out)
    prefix = '?$stream_buffer@V' + cls
    cmd = [sys.executable, str(ROOT / 'rebuild/2008-06/tests/check_native_class.py'),
           'native-classes/' + unit + '.cpp', ctor + '=??0' + prefix, deleting + '=??_G' + prefix]
    run = subprocess.run(cmd, cwd=ROOT, env=env, capture_output=True, text=True)
    assert run.returncode == 0 and '2/2 exact' in run.stdout, run.stdout + run.stderr
    obj = out / ('Check' + unit + '.obj')
    raw = obj.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    destructor = next(n for n in definitions if n.startswith('??1' + prefix))
    name, candidate, cand_refs = next(x for x in match.coff_functions(raw) if x[0] == destructor)
    first, first_refs, _ = match.target('2008-06', head)
    second, second_refs, _ = match.target('2008-06', tail)
    assert int(tail, 16) == int(head, 16) + len(first)
    target = first + second
    assert len(candidate) == len(target) == 120
    assert match.exact_match(target, list(first_refs) + [len(first) + i for i in second_refs], candidate, cand_refs)
    start, section = definitions[name]
    table = sections[section]
    calls = {}
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        offset -= start
        if kind == 20 and 0 <= offset < len(target) - 3:
            calls[symbols[index][0]] = (int(head, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
    assert any(k.startswith('?close@?$indirect_streambuf@V' + cls) and v == 0x5f3d80 for k, v in calls.items())
    assert any(k.startswith('??1?$indirect_streambuf@V' + cls) and v == 0x5f9620 for k, v in calls.items())
    def u32(address):
        return struct.unpack_from('<I', image, address - base)[0]
    locator = u32(vtable - 4)
    descriptor = u32(locator + 12)
    name_bytes = bytes(image[descriptor - base + 8:]).split(b'\0', 1)[0]
    assert cls.encode() in name_bytes and b'stream_buffer' in name_bytes
    assert b'.?' + name_bytes[2:] in raw
    assert u32(int(ctor, 16) + 0x4c) == vtable
    source = ROOT / 'rebuild/2008-06/native-classes' / (unit + '.cpp')
    rows.append({'unit': unit, 'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
                 'object_sha256': hashlib.sha256(raw).hexdigest(), 'ctor': ctor,
                 'destructor_fragments': [head, tail], 'destructor_size': len(target),
                 'vtable': hex(vtable), 'original_rtti': name_bytes.decode(), 'calls': calls})
output = ROOT / 'work/2008-06/native-http-stream-layout-20261105.json'
output.write_text(json.dumps({'scope': 'split-range constructor/destructor and RTTI evidence; not runtime proof',
                              'methods': rows}, indent=2) + '\n')
print('PASS: two stream buffer constructors, split destructors, calls and RTTI')
