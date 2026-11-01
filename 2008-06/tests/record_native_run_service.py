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
                        ("00554da0", "?setRunState@RunService@RBX@@"),
                        ("00554ae0", "?raise@?$Notifier@VRunService@RBX@@W4RunState@2@@RBX@@IBEXW4RunState@2@@Z"),
                        ("00554750", "?raise@?$Notifier@VRunService@RBX@@W4RunState@2@@RBX@@IBEXW4RunState@2@PAV"),
                        ("00554a60", "?raise@?$Notifier@VRunService@RBX@@VRunTransition@2@@RBX@@IBEXVRunTransition@2@@Z")):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
sections, symbols, definitions, _ = match._coff_data_index(obj)
for method, expected in (("00554da0", [("?raise@?$Notifier@VRunService@RBX@@W4RunState", 0x554ae0),
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
paths = [source, ROOT / "rebuild/2008-06/native-headers/util/RunStateOwner.h", ROOT / "rebuild/2008-06/native-headers/util/Events.h", ROOT / "rebuild/2008-06/tests/NativeRunServiceLayout.cpp", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, size=0x2d8, offsets=list(offsets), notifier_bases=dict(notifiers), original_sha256=hashlib.sha256(original.read_bytes()).hexdigest(), methods=results,
               scope="Inactive compiler proof; runDisabled field, call/data relocations and runtime linking remain unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: RunService constructor, state transitions and notifier callbacks match")
