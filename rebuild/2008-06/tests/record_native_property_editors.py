"""Verify native editor constructors and real SDK/member layouts."""
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_MEM, X86_OP_IMM

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild

OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
source = Path(__file__).with_name('NativePropertyEditorConstructors.cpp')
flags = json.loads((ROOT / 'work/2008-06/shared-layouts/property-grid-working-probe.json').read_text())['flags']
tc = rebuild.toolchain(21022)
category_source = ROOT / 'rebuild/2008-06/native-classes/CPropGridCategory.cpp'

def compile_source(pair):
    source, name = pair
    pre_dir = OUT / ('editor-constructors-' + name)
    pre_dir.mkdir(exist_ok=True)
    code, log = rebuild.run(tc, 'cl', [f for f in flags if f != '/c'] + ['/P', str(source)], pre_dir)
    assert code == 0, log
    body = (pre_dir / (source.stem + '.i')).read_text(errors='replace')
    needle = 'const _Elem * c_str() const'
    assert body.count(needle) == 1
    body = body.replace(needle, '__declspec(noinline) ' + needle)
    translation = OUT / (name + 'NoInline.cpp')
    translation.write_text(body)
    obj = OUT / (name + '.obj')
    compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
                     '/Fo' + str(obj), str(translation)]
    code, log = rebuild.run(tc, 'cl', compile_flags, OUT)
    assert code == 0, log
    return obj, compile_flags

with ThreadPoolExecutor(max_workers=2) as pool:
    compiled = dict((obj.name, (obj, compile_flags)) for obj, compile_flags in pool.map(
        compile_source, ((source, 'NativePropertyEditorConstructors'), (category_source, 'NativeCPropGridCategory'))))
original = pefile.PE(str(ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'))
expected_import = b'?c_str@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QBEPBDXZ'
assert any(dll.dll.lower() == b'msvcp90.dll' and item.address == 0x802464 and item.name == expected_import
           for dll in original.DIRECTORY_ENTRY_IMPORT for item in dll.imports)
bindings = {'?GetGridView@CXTPPropertyGrid@@': 0x6fa3b0, '?FindItem@CXTPPropertyGridItems@@': 0x712460,
            '?AddCategory@CXTPPropertyGridView@@': 0x716f60, '?Expand@CXTPPropertyGridItem@@': 0x7117e0,
            '??0Item@CPropGrid@@': 0x43a070, '??0?$XItem@_N': 0x43a0f0,
            '??0CXTPPropertyGridItem@@': 0x713510, '??0CXTPPropertyGridItemBool@@': 0x717b20,
            '??0CXTPPropertyGridItemColor@@': 0x713b80, '?SetReadOnly@CXTPPropertyGridItem@@': 0x7120e0,
            '?SetCheckBoxStyle@CXTPPropertyGridItemBool@@': 0x717780}
methods = []
edges = []
for address, prefix in (('00438630', '?getCategory@CPropGrid'), ('0043a650', '??0?$XItem@M'), ('0043ab10', '??0?$XItem@H'),
                        ('0043af00', '??0?$XItem@VColor3'), ('0043a0f0', '??0?$XItem@_N'),
                        ('0043d330', '??0XBoolItem'), ('0043b860', '??0?$XItem@V?$basic_string')):
    obj = compiled['NativeCPropGridCategory.obj' if address == '00438630' else 'NativePropertyEditorConstructors.obj'][0]
    raw = obj.read_bytes()
    functions = match.coff_functions(raw)
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    name, candidate, refs = next((n, b, r) for n, b, r in functions if n.startswith(prefix))
    target, target_refs, _ = match.target('2008-06', address)
    assert match.exact_match(target, target_refs, candidate, refs), (address, name)
    methods.append(dict(address=address, symbol=name, size=len(candidate), relocation_masked_match=True))
    start, section = definitions[name]
    table = sections[section]
    for index in range(table[7]):
        offset, si, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * index)
        offset -= start
        if not 0 <= offset <= len(candidate) - 4:
            continue
        symbol = symbols[si][0]
        if symbol.startswith('__imp_?c_str@?$basic_string'):
            assert symbol[len('__imp_'):].encode() == expected_import
            assert struct.unpack_from('<I', target, offset)[0] == 0x802464
        for beginning, destination in bindings.items():
            if symbol.startswith(beginning):
                assert kind == 20
                actual = (int(address, 16) + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                assert actual == destination, (address, symbol, hex(actual))
                edges.append(dict(caller=address, symbol=symbol, offset=offset, target=hex(destination)))
# Save original factory allocations and actual editor/base RTTI identities.
u32 = lambda address: struct.unpack('<I', original.get_data(address - original.OPTIONAL_HEADER.ImageBase, 4))[0]
editor_specs = (('0043d330', 0x144), ('0043a650', 0x130), ('0043ab10', 0x130),
                ('0043af00', 0x13c), ('0043d560', 0x13c), ('0043d6c0', 0x13c),
                ('0043e3a0', 0x138), ('0043db80', 0x134), ('0043df50', 0x130),
                ('00440db0', 0x130), ('00440d30', 0x130), ('0043b860', 0x130))
factory, _, _ = match.target('2008-06', '00440e30')
cs = Cs(CS_ARCH_X86, CS_MODE_32)
cs.detail = True
allocation = None
allocations = {}
previous = None
for instruction in cs.disasm(factory, 0x440e30):
    if instruction.mnemonic == 'call' and instruction.op_str.startswith('0x'):
        destination = int(instruction.op_str, 16)
        if destination == 0x6a0920:
            assert previous.mnemonic == 'push' and previous.operands[0].type == X86_OP_IMM
            allocation = previous.operands[0].imm
        if any(destination == int(address, 16) for address, _ in editor_specs):
            allocations['%08x' % destination] = allocation
    previous = instruction
editors = []
for address, size in editor_specs:
    assert allocations[address] == size
    target, _, _ = match.target('2008-06', address)
    primary = None
    for instruction in cs.disasm(target, int(address, 16)):
        ops = instruction.operands
        if instruction.mnemonic == 'mov' and len(ops) == 2 and ops[0].type == X86_OP_MEM and ops[0].mem.disp == 0 and ops[1].type == X86_OP_IMM and 0x800000 <= ops[1].imm < 0x900000:
            primary = ops[1].imm
            break
    assert primary is not None, address
    col = u32(primary - 4)
    descriptor = u32(col + 12)
    hierarchy = u32(col + 16)
    count, array = u32(hierarchy + 8), u32(hierarchy + 12)
    bases = []
    for index in range(count):
        record = u32(array + index * 4)
        name = original.get_string_at_rva(u32(record) + 8 - original.OPTIONAL_HEADER.ImageBase).decode()
        offset = struct.unpack('<i', original.get_data(record + 8 - original.OPTIONAL_HEADER.ImageBase, 4))[0]
        bases.append(dict(name=name, offset=offset))
    assert any(item['name'] == '.?AVItem@CPropGrid@@' for item in bases)
    editors.append(dict(constructor=address, allocation_size=size, primary_vtable=hex(primary),
                        name=original.get_string_at_rva(descriptor + 8 - original.OPTIONAL_HEADER.ImageBase).decode(),
                        bases=bases))

paths = [Path(__file__), source, category_source, HEADERS / 'PropertyGridItems.h', HEADERS / 'CPropGrid.h',
         HEADERS / 'SelectionGroup.h', ROOT / 'tools/libs/xtp-11.2.2/Source/PropertyGrid/XTPPropertyGridItem.h',
         ROOT / 'tools/rbxgs/Client/App/include/util/Name.h']
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): sha(p) for p in paths}, compiler=21022,
               preprocess_flags=flags, compilations={name: dict(compile_flags=entry[1], object_sha256=sha(entry[0]))
                                                 for name, entry in compiled.items()}, methods=methods,
               verified_bindings=edges, original_editor_rtti=editors, profile='Existing std::string::c_str noinline import recipe',
               layouts=dict(Item=0x20, SDKItem=0x10c, SDKBool=0x120, SDKColor=0x118,
                            Float=0x130, Int=0x130, Color=0x13c, String=0x130, BoolBase=0x144, XBool=0x144),
               scope='Inactive constructor/layout evidence. Native SDK field m_bHidden at +0xfc starts rows hidden. '
                     'Item vector/grid state corrected to 32 bytes; one RTTI slot never proved old size4 hypothesis. '
                     'Template update methods and SDK virtual overrides remain unresolved; full virtual data, '
                     'property-row factory, linking and game integration remain open. No runtime credit.')
(ROOT / 'work/2008-06/shared-layouts/property-editor-constructors-working-probe.json').write_text(
    json.dumps(receipt, indent=2) + '\n')
print('PASS: six native editor constructors and category lookup; SDK/layout assertions and selected bindings')
