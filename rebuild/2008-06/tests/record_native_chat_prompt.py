"""Compile and verify inactive native chat prompt layout."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import struct
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
source = ROOT / "rebuild/2008-06/tests/NativeChatPrompt.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/FoNativeChatPrompt.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeChatPrompt.obj").read_bytes()
results = []
for address, prefix in (("00411be0", "??0CChatPrompt@@"),
                        ("00412800", "?bind@CChatPrompt@@")):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
original = ROOT / "work/2008-06/original-p4-reference/Roblox.exe"
pe = pefile.PE(str(original), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
read32 = lambda address: struct.unpack("<I", pe.get_data(address - base, 4))[0]
for vtable, expected in ((0x80e1ac, b".?AVCChatPrompt@@"), (0x80e068, b".?AVCBrush@@"),
                         (0x80e12c, b".?AVChatEnter@@")):
    locator = read32(vtable - 4)
    assert pe.get_string_at_rva(read32(locator + 12) - base + 8) == expected
assert pe.get_data(0x411f06 - base, 5) == b"\x68\xa8\x00\x00\x00"
# Resolve call relocations for the recovered binding body.
sections, symbols, definitions, _ = match._coff_data_index(obj)
bind = results[1]
start, section = definitions[bind["symbol"]]
table = sections[section]
relocations = {}
for index in range(table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
    if offset >= start:
        relocations[offset - start] = symbols[symbol][0]
native_bind, _, _ = match.target("2008-06", "00412800")
calls = {instruction.address - 0x412800 + 1: int(instruction.op_str, 16)
         for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(native_bind, 0x412800)
         if instruction.mnemonic == "call" and instruction.op_str.startswith("0x")}
targets = {"??$shared_from@VDataModel@RBX@@": 0x618a40,
           "??4shared_count@detail@boost@@": 0x4025b0,
           "??0Lock@DataModel@RBX@@": 0x411b40,
           "?setParent@Instance@RBX@@": 0x55a8f0,
           "?reset@?$shared_ptr@VChatEnter@@": 0x456e80,
           "??$create@VPlayers@Network@RBX@@@ServiceProvider": 0x412710,
           "??$create@VChatEnter@@@?$Creatable": 0x411f50,
           "?EnableWindow@CWnd@@": 0x6a0d16,
           "??1Lock@DataModel@RBX@@": 0x5773c0}
bind["verified_direct_calls"] = []
for offset, symbol in relocations.items():
    target = next((value for prefix, value in targets.items() if symbol.startswith(prefix)), None)
    if target is not None:
        assert calls.get(offset) == target, (symbol, calls.get(offset), target)
        bind["verified_direct_calls"].append(dict(offset=offset, symbol=symbol, target=hex(target)))
assert len(bind["verified_direct_calls"]) == 11
gui_locator = read32(0x82f9fc - 4)
gui_hierarchy = read32(gui_locator + 16)
gui_bases = read32(gui_hierarchy + 12)
gui_types = {}
for index in range(read32(gui_hierarchy + 8)):
    descriptor = read32(gui_bases + 4 * index)
    name = pe.get_string_at_rva(read32(descriptor) - base + 8).decode("ascii")
    gui_types[name] = struct.unpack("<i", pe.get_data(descriptor + 8 - base, 4))[0]
assert gui_types[".?AVGuiRoot@RBX@@"] == 0
assert gui_types[".?AVGuiItem@RBX@@"] == 0
assert gui_types[".?AVInstance@RBX@@"] == 0
# The stored context is passed to native DataModel::Lock; the +0xa4
# service comes from a factory whose constructor installs Players RTTI.
for address, target_address in ((0x412800, 0x411b40), (0x412800, 0x412710),
                                (0x412710, 0x411fd0), (0x411fd0, 0x49bdc0)):
    native, _, _ = match.target("2008-06", "%08x" % address)
    assert any(instruction.mnemonic == "call" and instruction.op_str == hex(target_address)
               for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(native, address))
players_locator = read32(0x8227bc - 4)
assert pe.get_string_at_rva(read32(players_locator + 12) - base + 8) == b".?AVPlayers@Network@RBX@@"
paths = [source, ROOT / "rebuild/2008-06/native-headers/CChatPrompt.h", ROOT / "rebuild/2008-06/native-classes/CChatPrompt.cpp", ROOT / "rebuild/2008-06/native-headers/ChatEnter.h", ROOT / "rebuild/2008-06/native-headers/v8datamodel/DataModel.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, original_sha256=hashlib.sha256(original.read_bytes()).hexdigest(), methods=results,
               scope="Inactive layout candidate; Context is passed to DataModel::Lock; Players factory RTTI corroborates +0xa4 type. ChatEnter ownership, other virtual methods, GuiItem ABI and runtime linking need further verification.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: chat prompt size, offsets, constructor and binding match")
