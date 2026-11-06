"""Audit saved camera getter/ABI objects without compiling or running a client."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys

import capstone
import pefile

ROOT = Path(__file__).resolve().parents[3]
# Private copies may set ROOT before importing this module.
if not (ROOT / 'roc').is_dir():
    ROOT = Path.cwd()
sys.path.insert(0, str(ROOT))
from roc import match


def audit(run):
    rows = json.loads((run / 'results.json').read_text(encoding='utf-8'))
    objects = {}
    for row in rows:
        for name, expected in {row['source']: row['source_sha256'],
                               row['object']: row['object_sha256'],
                               **row['dependencies']}.items():
            assert hashlib.sha256(Path(name).read_bytes()).hexdigest() == expected, name
        objects[Path(row['source']).name] = Path(row['object']).read_bytes()
    native = objects['WorkspaceCamera.cpp']
    functions = {name: (body, refs) for name, body, refs in match.coff_functions(native)}
    methods = []
    for address, symbol in [
        ('005a05a0', '?getCamera@Workspace@RBX@@UBEPAVCamera@2@XZ'),
        ('005a0210', '?getGCamera@Workspace@RBX@@UBEABVGCamera@G3D@@XZ')
    ]:
        body, refs = functions[symbol]
        original, masks, _ = match.target('2008-06', address)
        assert match.exact_match(original, masks, body, refs), symbol
        _, errors = match.data_check('2008-06', address, original, match.coff_data_refs(native, symbol))
        assert not errors, errors
        methods.append(dict(address=address, symbol=symbol, size=len(body), exact=True))
    observer = {name: body for name, body, _ in match.coff_functions(objects['NativeWorkspaceCameraABI.cpp'])}
    # Original RTTI/constructor establishes Workspace -> ICameraOwner +0x288.
    # Original getGCamera below establishes Camera -> GCamera +0x130.
    assert observer['_workspaceCameraOwner'] == bytes.fromhex('8b44240485c074060588020000c333c0c3')
    assert observer['_workspaceCameraProjection'] == bytes.fromhex('8b4424040530010000c3')
    path = ROOT / 'clients/2008-06/Roblox.exe'
    pe = pefile.PE(str(path)); image = pe.OPTIONAL_HEADER.ImageBase
    def pointer(address):
        return struct.unpack('<I', pe.get_data(address - image, 4))[0]
    assert (pointer(0x83399c), pointer(0x8339a0)) == (0x5a05a0, 0x5a0210)
    locator = pointer(0x833994)
    assert pointer(locator + 4) == 0x288
    descriptor = pointer(locator + 12)
    assert pe.get_string_at_rva(descriptor + 8 - image) == b'.?AVWorkspace@RBX@@'
    disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    for address in ['005a4d90', '005a28c0']:
        body, _, _ = match.target('2008-06', address)
        instructions = [(i.mnemonic, i.op_str) for i in disassembler.disasm(body, int(address, 16))]
        assert ('mov', 'dword ptr [esi + 0x288], 0x833998') in instructions
    original, _, _ = match.target('2008-06', '005a0210')
    assert original == bytes.fromhex('8b018b5004ffd20530010000c3')
    return dict(methods=methods, original_sha256=hashlib.sha256(path.read_bytes()).hexdigest(),
                camera_owner_offset=0x288, camera_projection_offset=0x130,
                camera_size=0x1e8, original_camera_vtable='00833998',
                original_slots={'4': '005a05a0', '8': '005a0210'},
                inputs_unchanged=True, compile_only_abi_observers=True,
                scope='Original code/data, concrete Workspace camera slots and pointer adjustments only. '
                      'Indirect dispatch remains open for arbitrary overrides. No complete class lifetime, '
                      'selected client, P5/P6/runtime or server-credit proof.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('run', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    result = audit(args.run)
    args.output.write_text(json.dumps(result, indent=2), encoding='utf-8')
    print(json.dumps(result))


if __name__ == '__main__':
    main()
