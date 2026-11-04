"""Compile and verify inactive native multiplayer pane."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import struct
import re
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
source = ROOT / "rebuild/2008-06/tests/NativeMultiPlayerPane.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/FoNativeMultiPlayerPane.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeMultiPlayerPane.obj").read_bytes()
results = []
for address, prefix in (("00432e30", "??0CMultiPlayerPane@@"),
                        ("00432e50", "??1CMultiPlayerPane@@"),
                        ("00432e60", "?initialize@CMultiPlayerPane@@"),
                        ("00432e20", "?GetRuntimeClass@CMultiPlayerPane@@"),
                        ("00432fa0", "?GetMessageMap@CMultiPlayerPane@@"),
                        ("00432f20", "?OnSize@CMultiPlayerPane@@"),
                        ("00432f60", "?OnDestroy@CMultiPlayerPane@@")):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
original = ROOT / "work/2008-06/original-p4-reference/Roblox.exe"
pe = pefile.PE(str(original), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
read32 = lambda address: struct.unpack("<I", pe.get_data(address - base, 4))[0]
locator = read32(0x811cdc - 4)
assert pe.get_string_at_rva(read32(locator + 12) - base + 8) == b".?AVCMultiPlayerPane@@"
assert pe.get_string_at_rva(read32(0x80df88) - base) == b"CChatPrompt"
target, _, _ = match.target("2008-06", "00432e60")
instructions = list(Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, 0x432e60))
assert any(i.address == 0x432ea5 and i.op_str == "0x411360" for i in instructions)
assert any(i.address == 0x432ec2 and i.op_str == "dword ptr [esi + 0x54], eax" for i in instructions)
# Link the original MFC ordinal thunks to SDK export definitions and COFF symbols.
pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
imports = {item.address: (entry.dll.decode("ascii").lower(), item.ordinal)
           for entry in pe.DIRECTORY_ENTRY_IMPORT for item in entry.imports}
exports = ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def"
export_text = exports.read_text(errors="replace")
sections, symbols, definitions, _ = match._coff_data_index(obj)
verified_mfc = []
for method_prefix, source_address, thunk, ordinal, decorated in (
        ("?OnSize@CMultiPlayerPane@@", 0x432f20, 0x6a0a4c, 4529, "?MoveWindow@CWnd@@QAEXHHHHH@Z"),
        ("?OnSize@CMultiPlayerPane@@", 0x432f20, 0x6a0c68, 2069, "?Default@CWnd@@IAEJXZ"),
        ("?OnDestroy@CMultiPlayerPane@@", 0x432f60, 0x6a107c, 4760, "?OnDestroy@CWnd@@IAEXXZ"),
        ("?initialize@CMultiPlayerPane@@", 0x432e60, 0x6a06f2, 1728, "?Create@CWnd@@UAEHPBD0KABUtagRECT@@PAV1@IPAUCCreateContext@@@Z"),
        ("?initialize@CMultiPlayerPane@@", 0x432e60, 0x6a0fc2, 1855, "?CreateObject@CRuntimeClass@@QAEPAVCObject@@XZ")):
    method_name = next(name for name in definitions if name.startswith(method_prefix))
    start, section = definitions[method_name]
    table = sections[section]
    offsets = []
    for index in range(table[7]):
        offset, symbol_index, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
        if symbols[symbol_index][0] == decorated:
            offsets.append(offset - start)
    assert len(offsets) == 1, (decorated, offsets)
    native, _, _ = match.target("2008-06", "%08x" % source_address)
    instructions = {instruction.address - source_address + 1: instruction for instruction in
                    Cs(CS_ARCH_X86, CS_MODE_32).disasm(native, source_address)
                    if instruction.mnemonic in ("call", "jmp") and instruction.op_str.startswith("0x")}
    assert int(instructions[offsets[0]].op_str, 16) == thunk
    thunk_bytes = pe.get_data(thunk - base, 6)
    assert thunk_bytes[:2] == b"\xff\x25"
    import_address = struct.unpack("<I", thunk_bytes[2:])[0]
    assert imports[import_address] == ("mfc90.dll", ordinal)
    assert re.search(re.escape(decorated) + r"\s+@\s+" + str(ordinal) + r"\s+NONAME", export_text)
    verified_mfc.append(dict(symbol=decorated, thunk=hex(thunk), ordinal=ordinal))
# Compare message-map fields and link-time handler names with original data.
sections, symbols, definitions, _ = match._coff_data_index(obj)
entries_name = next(name for name in definitions if name.startswith("?_messageEntries@?1??GetThisMessageMap@CMultiPlayerPane@@"))
start, section = definitions[entries_name]
table = sections[section]
assert table[3] - start == 72 and table[7] == 2
map_relocations = {}
for index in range(table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
    assert kind == 6
    map_relocations[offset - start] = symbols[symbol][0]
for index, handler in enumerate(("?OnSize@CMultiPlayerPane@@", "?OnDestroy@CMultiPlayerPane@@")):
    offset = index * 24
    compiled = struct.unpack_from("<6I", obj, table[4] + start + offset)
    native = struct.unpack("<6I", pe.get_data(0x811e28 + offset - base, 24))
    assert compiled[:5] == native[:5] and compiled[5] == 0
    assert map_relocations[offset + 20].startswith(handler)
assert not any(struct.unpack_from("<6I", obj, table[4] + start + 48))
paths = [source, ROOT / "rebuild/2008-06/native-headers/CMultiPlayerPane.h", ROOT / "rebuild/2008-06/native-classes/CMultiPlayerPane.cpp", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, original_sha256=hashlib.sha256(original.read_bytes()).hexdigest(), mfc_exports_sha256=hashlib.sha256(exports.read_bytes()).hexdigest(), verified_mfc_calls=verified_mfc, methods=results,
               scope="Inactive compiler proof; CChatPrompt runtime-class allocation and storage confirmed. Five original MFC thunk ordinals are mapped to SDK export symbols; ChatPrompt bind symbol remains provisional; full pane virtual methods and runtime linkage remain unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: CMultiPlayerPane layout, seven bodies and message map match")
