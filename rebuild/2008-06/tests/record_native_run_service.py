"""Compile and verify inactive native RunService methods."""
import hashlib
import json
from pathlib import Path
import subprocess
import struct

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
import sys
import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
source = ROOT / "rebuild/2008-06/native-classes/RunService.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/FoNativeRunService.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeRunService.obj").read_bytes()
results = []
for address, prefix in (("00556b00", "??0RunService@RBX@@"),
                        ("00555c00", "??1RunService@RBX@@"),
                        ("00555900", "?enqueueTask@RunService@RBX@@"),
                        ("005559a0", "?drainTasks@RunService@RBX@@"),
                        ("00554440", "?onAncestorChanged@RunService@RBX@@"),
                        ("00554da0", "?setRunState@RunService@RBX@@"),
                        ("00554ae0", "?raise@?$Notifier@VRunService@RBX@@W4RunState@2@@RBX@@IBEXW4RunState@2@@Z"),
                        ("00554750", "?raise@?$Notifier@VRunService@RBX@@W4RunState@2@@RBX@@IBEXW4RunState@2@PAV"),
                        ("00554a60", "?raise@?$Notifier@VRunService@RBX@@VRunTransition@2@@RBX@@IBEXVRunTransition@2@@Z")):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))

add_flags = flags[:-2]
header_i = next(i for i, flag in enumerate(add_flags) if flag.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
add_flags[header_i:header_i] = ["/I" + str(ROOT / "rebuild/2008-06/native-headers/std-noinline-string"),
                                "/I" + str(ROOT / "rebuild/2008-06/native-headers/runservice-events")]
add_flags += ["/FoNativeRunServiceAddRunView.obj", str(source)]
add_code, add_log = rebuild.run(rebuild.toolchain(21022), "cl", add_flags, out)
assert add_code == 0, add_log
add_obj = (out / "NativeRunServiceAddRunView.obj").read_bytes()
name, body, relocations = next(row for row in match.coff_functions(add_obj) if row[0].startswith("?addRunView@RunService@RBX@@"))
target, target_relocations, _ = match.target("2008-06", "005557c0")
assert match.exact_match(target, target_relocations, body, relocations), name
add_sections, add_symbols, add_definitions, _ = match._coff_data_index(add_obj)
start, section = add_definitions[name]
table = add_sections[section]
relocs = {}
for index in range(table[7]):
    offset, symbol_index, kind = struct.unpack_from("<IIH", add_obj, table[5] + 10 * index)
    if start <= offset < start + len(body):
        relocs[offset - start] = add_symbols[symbol_index][0]
calls = {instruction.address - 0x5557c0 + 1: int(instruction.op_str, 16)
         for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, 0x5557c0)
         if instruction.mnemonic == "call" and instruction.op_str.startswith("0x")}
verified = []
for prefix, address in (("?do_lock@mutex@boost@@", 0x594ce0), ("??A?$map@PAVIRunView@RBX@@", 0x5556d0),
                        ("?do_unlock@mutex@boost@@", 0x594d00)):
    offset, symbol = next((offset, symbol) for offset, symbol in relocs.items() if symbol.startswith(prefix))
    assert calls[offset] == address, (name, symbol, calls.get(offset), address)
    verified.append(dict(offset=offset, symbol=symbol, target=hex(address)))
results.append(dict(address="005557c0", symbol=name, size=len(body), relocation_normalized_exact=True,
                    verified_direct_calls=verified, profile="std-noinline-string + runservice-events"))
sections, symbols, definitions, _ = match._coff_data_index(obj)
for method, expected in (("00554440", [("?notify_all@condition_impl@detail@boost@@", 0x5f1d30)]),
                         ("005559a0", [("?do_lock@mutex@boost@@", 0x594ce0),
                                         ("?do_unlock@mutex@boost@@", 0x594d00),
                                         ("??D?$_Deque_const_iterator", 0x496020),
                                         ("??4?$function@", 0x554f90),
                                         ("?singleton@StandardOut@RBX@@", 0x569620),
                                         ("?print@StandardOut@RBX@@", 0x5693a0)]),
                         ("00555900", [("?do_lock@mutex@boost@@", 0x594ce0),
                                         ("?push_back@?$deque@V?$function@$$A6AXXZ", 0x419ae0),
                                         ("?do_unlock@mutex@boost@@", 0x594d00)]),
                         ("00555c00", [("?tock@Stopwatch@G3D@@", 0x511df0),
                                         ("?_Tidy@?$deque@V?$function@$$A6AXXZ", 0x419b40),
                                         ("??1?$FactoryProduct@VRunService@RBX@@", 0x554350)]),
                         ("00554da0", [("?raise@?$Notifier@VRunService@RBX@@W4RunState", 0x554ae0),
                                         ("?raise@?$Notifier@VRunService@RBX@@VRunTransition", 0x554a60)]),
                         ("00554ae0", [("?raise@?$Notifier@VRunService@RBX@@W4RunState", 0x554750)]),
                         ("00554a60", [("?raise@?$Notifier@VRunService@RBX@@VRunTransition", 0x554690)])):
    result = next(item for item in results if item["address"] == method)
    start, section = definitions[result["symbol"]]
    table = sections[section]
    relocs = {}
    for index in range(table[7]):
        offset, symbol_index, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
        if offset >= start:
            relocs[offset - start] = symbols[symbol_index][0]
    original_body, _, _ = match.target("2008-06", method)
    calls = {instruction.address - int(method, 16) + 1: int(instruction.op_str, 16)
             for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(original_body, int(method, 16))
             if instruction.mnemonic == "call" and instruction.op_str.startswith("0x")}
    result["verified_direct_calls"] = []
    for prefix, address in expected:
        offset, symbol = next((offset, symbol) for offset, symbol in relocs.items() if symbol.startswith(prefix))
        assert calls[offset] == address, (method, symbol, calls.get(offset), address)
        result["verified_direct_calls"].append(dict(offset=offset, symbol=symbol, target=hex(address)))
layout_source = ROOT / "rebuild/2008-06/tests/NativeRunServiceLayout.cpp"
layout_flags = flags[:-2] + ["/d1reportSingleClassLayoutRunService", "/FoNativeRunServiceLayout.obj", str(layout_source)]
layout_code, layout_log = rebuild.run(rebuild.toolchain(21022), "cl", layout_flags, out)
assert layout_code == 0, layout_log
layout_obj = (out / "NativeRunServiceLayout.obj").read_bytes()
layout_sections, _, layout_definitions, _ = match._coff_data_index(layout_obj)
value, section = layout_definitions["?donorRunServiceSize@@3IA"]
assert struct.unpack_from("<I", layout_obj, layout_sections[section][4] + value)[0] == 0x2d8
value, section = layout_definitions["?offsets@@3PAIA"]
offsets = struct.unpack_from("<11I", layout_obj, layout_sections[section][4] + value)
assert offsets[:10] == (0x1b4, 0x1b8, 0x1c0, 0x1c8, 0x1d0, 0x1d8, 0x1e0, 0x1e8, 0x2ac, 0x2b4)
# The function index ends at the catch boundary (66 bytes), but PE execution
# continues through its EH handler. Compare the entire 189-byte function, ending
# immediately before three INT3 alignment bytes and the next function.
original_image = ROOT / "work/2008-06/original-p4-reference/Roblox.exe"
original_pe = pefile.PE(str(original_image), fast_load=True)
original_base = original_pe.OPTIONAL_HEADER.ImageBase
whole = original_pe.get_data(0x554690 - original_base, 189)
assert original_pe.get_data(0x554690 - original_base + 189, 3) == b"\xcc\xcc\xcc"
callback_symbol, callback_body, callback_relocs = next(
    (name, body, relocs) for name, body, relocs in match.coff_functions(obj)
    if name.startswith("?raise@?$Notifier@VRunService@RBX@@VRunTransition@2@@RBX@@IBEXVRunTransition@2@PAV"))
assert len(callback_body) == len(whole)
disassembler = Cs(CS_ARCH_X86, CS_MODE_32)
disassembler.detail = True
operand_offsets = set()
for instruction in disassembler.disasm(whole, 0x554690):
    if instruction.imm_size == 4:
        operand_offsets.add(instruction.address - 0x554690 + instruction.imm_offset)
    if instruction.disp_size == 4:
        operand_offsets.add(instruction.address - 0x554690 + instruction.disp_offset)
assert set(callback_relocs) <= operand_offsets, (callback_relocs, operand_offsets)
assert match.exact_match(whole, callback_relocs, callback_body, callback_relocs)
results.append(dict(address="00554690", symbol=callback_symbol, size=189,
                    relocation_normalized_exact=True, indexed_size=66,
                    scope="Original PE body includes exception handler through 0055474c."))
# Check the concrete notifier base displacements against original RTTI and compiler output.
original = ROOT / "work/2008-06/original-p4-reference/Roblox.exe"
pe = pefile.PE(str(original), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
read32 = lambda address: struct.unpack("<I", pe.get_data(address - base, 4))[0]
locator = read32(0x82d4c4 - 4)
assert pe.get_string_at_rva(read32(locator + 12) - base + 8) == b".?AVRunService@RBX@@"
hierarchy = read32(locator + 16)
base_array = read32(hierarchy + 12)
native_bases = {}
for index in range(read32(hierarchy + 8)):
    descriptor = read32(base_array + index * 4)
    typename = pe.get_string_at_rva(read32(descriptor) - base + 8).decode("ascii")
    displacement = struct.unpack("<i", pe.get_data(descriptor + 8 - base, 4))[0]
    native_bases[typename] = displacement
notifiers = (("VHeartbeat", 0x130), ("VStepped", 0x150),
             ("VRunTransition", 0x170), ("W4RunState", 0x190))
for name, offset in notifiers:
    matches = [value for key, value in native_bases.items() if key.startswith(".?AV?$Notifier@VRunService@RBX@@" + name)]
    assert matches == [offset], (name, matches)
    marker = "RunService::$vftable@?$Notifier@VRunService@RBX@@" + name
    position = layout_log.index(marker)
    assert "| -%d" % offset in layout_log[position:position + 300], name
assert native_bases[".?AVService@RBX@@"] == 0x1b1
# Relocation masking does not validate the primary vtable contents.
original_primary_slot0 = read32(0x82d4c4)
assert original_primary_slot0 == 0x47d410 and pe.get_data(original_primary_slot0 - base, 1) == b"\xc3"
vtables = [name for name in definitions if name.startswith("??_7RunService@RBX@@6B?$GuidItem@")]
assert len(vtables) == 1
vtable_start, vtable_section = definitions[vtables[0]]
vtable_table = sections[vtable_section]
primary_symbol = None
for index in range(vtable_table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, vtable_table[5] + 10 * index)
    if offset == vtable_start:
        primary_symbol = symbols[symbol][0]
assert primary_symbol and primary_symbol.startswith("?onGuidChanged@?$GuidItem@VInstance@RBX@@")
slot_name, slot_body, slot_relocs = next((name, body, refs) for name, body, refs in match.coff_functions(obj)
                                          if name == primary_symbol)
assert slot_body == b"\xc3" and not slot_relocs
primary_vtable = dict(original_slot0=hex(original_primary_slot0), original_body="ret",
                      candidate_slot0=primary_symbol, compatible=True,
                      source="roc_instance_guid_callback_5e8a3f385d045a38.cpp")
constructor_symbol = results[0]['symbol']
constructor_start, constructor_section = definitions[constructor_symbol]
constructor_table = sections[constructor_section]
constructor_bytes, _, _ = match.target('2008-06', '00556b00')
deleting_thunks = []
for index in range(constructor_table[7]):
    offset, symbol_index, kind = struct.unpack_from('<IIH', obj, constructor_table[5] + 10 * index)
    offset -= constructor_start
    vtable_symbol = symbols[symbol_index][0]
    if not (0 <= offset < len(constructor_bytes) - 3 and vtable_symbol.startswith('??_7RunService@') and vtable_symbol in definitions):
        continue
    vtable_address = struct.unpack_from('<I', constructor_bytes, offset)[0]
    vtable_start, vtable_index = definitions[vtable_symbol]
    vtable_table = sections[vtable_index]
    for slot in range(vtable_table[7]):
        entry_offset, entry_symbol, _ = struct.unpack_from('<IIH', obj, vtable_table[5] + 10 * slot)
        entry_offset -= vtable_start
        if entry_offset < 0 or not symbols[entry_symbol][0].startswith('??_ERunService@'):
            continue
        thunk = read32(vtable_address + entry_offset)
        instructions = list(Cs(CS_ARCH_X86, CS_MODE_32).disasm(pe.get_data(thunk - base, 16), thunk))
        assert instructions[0].mnemonic == 'sub' and instructions[0].op_str.startswith('ecx, '), hex(thunk)
        assert instructions[1].mnemonic == 'jmp' and instructions[1].op_str == '0x556410', hex(thunk)
        deleting_thunks.append(dict(vtable=hex(vtable_address), slot=entry_offset // 4, thunk=hex(thunk), adjustment=instructions[0].op_str))
assert len(deleting_thunks) == 12, deleting_thunks
deleting_body, _, _ = match.target('2008-06', '00556410')
assert any(i.mnemonic == 'call' and i.op_str == '0x555c00' for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(deleting_body, 0x556410))
paths = [source, ROOT / "rebuild/2008-06/native-headers/util/RunStateOwner.h", ROOT / "rebuild/2008-06/native-headers/util/Events.h", ROOT / "rebuild/2008-06/native-headers/util/GuidItem.h", ROOT / "rebuild/2008-06/native-headers/v8tree/Instance.h", ROOT / "rebuild/2008-06/tests/NativeRunServiceLayout.cpp", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, add_run_view_flags=add_flags, compile_exit=code,
               object_sha256=hashlib.sha256(obj).hexdigest(), add_run_view_object_sha256=hashlib.sha256(add_obj).hexdigest(),
               size=0x2d8, offsets=list(offsets), primary_vtable=primary_vtable, notifier_bases=dict(notifiers), deleting_destructor_thunks=deleting_thunks, original_sha256=hashlib.sha256(original.read_bytes()).hexdigest(), methods=results,
               scope="Inactive compiler proof; constructor/destructor and selected calls match; callable return type inferred, remaining virtual slots, runDisabled field, call/data relocations and runtime linking remain unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: RunService bodies and primary vtable slot match")
