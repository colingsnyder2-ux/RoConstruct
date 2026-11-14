import importlib.util
from pathlib import Path
import struct
from unittest.mock import patch


path = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests/native_simple_eh_proof.py'
spec = importlib.util.spec_from_file_location('native_simple_eh_proof', path)
proof = importlib.util.module_from_spec(spec)
spec.loader.exec_module(proof)


def fixture():
    owner = '?method@Thing@@QAEXXZ'
    suffix = '$' + owner
    handler, info, unwind, action = ['__ehhandler' + suffix, '__ehfuncinfo' + suffix,
                                      '__unwindtable' + suffix, '__unwindfunclet' + suffix + '$0']
    names = [handler, info, unwind, action, '___CxxFrameHandler3', '__imp__dtor']
    symbols = {i: (name, 0, i + 1 if i < 4 else 0, 0) for i, name in enumerate(names)}
    definitions = {name: (0, i) for i, name in enumerate(names[:4])}
    data = [(b'\xb8' + b'\0' * 4 + b'\xe9' + b'\0' * 4, [(1, 1, 6), (6, 4, 20)]),
            (struct.pack('<9I', 0x19930522, 1, 0, 0, 0, 0, 0, 0, 1), [(8, 2, 6)]),
            (struct.pack('<2I', 0xffffffff, 0), [(4, 3, 6)]),
            (bytes.fromhex('8d4dfc ff25 00000000'), [(5, 5, 6)])]
    raw = bytearray(b'X')
    sections, starts = [], {}
    for i, (body, refs) in enumerate(data):
        ptr = len(raw)
        raw.extend(body)
        relptr = len(raw)
        for ref in refs:
            raw.extend(struct.pack('<IIH', *ref))
        sections.append((b'.text', 0, 0, len(body), ptr, relptr, 0, len(refs), 0, 0x20))
        starts[i + 1] = (0,)
    image = bytearray(0x1000)
    def put(address, value):
        image[address - 0x1000:address - 0x1000 + len(value)] = value
    put(0x1100, b'\xb8' + struct.pack('<I', 0x1200) + b'\xe9' + struct.pack('<i', 0x1500 - 0x110a))
    put(0x1200, struct.pack('<9I', 0x19930522, 1, 0x1300, 0, 0, 0, 0, 0, 1))
    put(0x1300, struct.pack('<2I', 0xffffffff, 0x1400))
    put(0x1400, bytes.fromhex('8d4dfc ff25 04160000'))
    put(0x1500, bytes.fromhex('ff25 00160000'))
    imports = ({0x1600: 'MSVCR90.dll!__CxxFrameHandler3', 0x1604: 'TEST.dll!dtor'},
               {('msvcr90.dll', '__CxxFrameHandler3'): {'__imp____CxxFrameHandler3'},
                ('test.dll', 'dtor'): {'__imp__dtor'}}, {})
    return bytes(raw), owner, (sections, symbols, definitions, starts), image, imports


def test_simple_unwind_proof_rejects_changed_code_and_metadata():
    raw, owner, index, image, imports = fixture()
    assert proof.verify(raw, owner, 0x1100, index, 0x1000, image, imports)
    changed = bytearray(image)
    changed[0x400] ^= 1
    assert not proof.verify(raw, owner, 0x1100, index, 0x1000, changed, imports)
    changed = bytearray(image)
    changed[0x20c] = 1  # introduces a catch block, unsupported by this verifier
    assert not proof.verify(raw, owner, 0x1100, index, 0x1000, changed, imports)
    changed = bytearray(image)
    changed[0x220] ^= 1  # compiler EH flags are part of FuncInfo
    assert not proof.verify(raw, owner, 0x1100, index, 0x1000, changed, imports)
    assert not proof.verify(raw, owner, 0x1100, index, 0x1000, image, ({}, {}, {}))


def test_reference_guard_accepts_only_verified_simple_handler():
    runner_path = path.with_name('native_check_runner.py')
    runner_spec = importlib.util.spec_from_file_location('eh_test_runner', runner_path)
    runner = importlib.util.module_from_spec(runner_spec)
    runner_spec.loader.exec_module(runner)
    raw, owner, index, image, imports = fixture()
    sections, symbols, definitions, starts = index
    raw = bytearray(raw)
    body = bytes.fromhex('b8 00000000 c3')
    target = bytes.fromhex('b8 00110000 c3')
    ptr = len(raw)
    raw.extend(body)
    reloc = len(raw)
    raw.extend(struct.pack('<IIH', 1, 0, 6))
    sections.append((b'.text', 0, 0, len(body), ptr, reloc, 0, 1, 0, 0x20))
    definitions[owner] = (0, len(sections) - 1)
    starts[len(sections)] = (0,)
    with patch.object(runner.match, '_coff_data_index', return_value=index), \
         patch.object(runner.match, '_image', return_value=(0x1000, image)), \
         patch.object(runner, 'import_evidence', return_value=imports):
        result = runner.check_noncall_refs(bytes(raw), owner, body, target, [], [], [], 0x1800)
        assert result['passed']
        assert result['references'][0]['status'] == 'verified_simple_eh_metadata'
        image[0x400] ^= 1
        assert not runner.check_noncall_refs(bytes(raw), owner, body, target, [], [], [], 0x1800)['passed']
