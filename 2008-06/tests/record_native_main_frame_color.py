"""Compile and verify inactive CMainFrame color callback."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import struct
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
source = ROOT / "rebuild/2008-06/tests/NativeMainFrameVtable.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK", "/I" + str(ROOT / "tools/libs/xtp-11.2.2/Source")]
flags += ["/FoNativeMainFrameColor.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeMainFrameColor.obj").read_bytes()
results = []
for address, prefix in (("0042fb20", "?onEvent@CMainFrame@@"),):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
sections, symbols, definitions, _ = match._coff_data_index(obj)
for address, expected in (("0042fb20", [("?color3@BrickColor@RBX@@", 0x5b6270), ("??0Color3uint8@G3D@@", 0x5106a0), ("?FindControl@CXTPCommandBars@@", 0x6a4f40), ("?SetColor@CXTPControlPopupColor@@", 0x6e97f0)]),):
    result = next(row for row in results if row["address"] == address)
    start, section = definitions[result["symbol"]]
    table = sections[section]
    relocs = {}
    for index in range(table[7]):
        offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
        if offset >= start:
            relocs[offset - start] = symbols[symbol][0]
    original, _, _ = match.target("2008-06", address)
    calls = {instruction.address - int(address, 16) + 1: int(instruction.op_str, 16)
             for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(original, int(address, 16))
             if instruction.mnemonic == "call" and instruction.op_str.startswith("0x")}
    result["verified_direct_calls"] = []
    for prefix, target in expected:
        offset, symbol = next((offset, symbol) for offset, symbol in relocs.items() if symbol.startswith(prefix))
        assert calls[offset] == target, (address, symbol, calls.get(offset), target)
        result["verified_direct_calls"].append(dict(offset=offset, symbol=symbol, target=hex(target)))
# Verify listener vtable targets the exact callback; primary slot still needs native MFC runtime class.
listener = next(name for name in definitions if name.startswith("??_7CMainFrame@@6B?$Listener@"))
primary = next(name for name in definitions if name.startswith("??_7CMainFrame@@6BCXTPMDIFrameWnd"))
def slot_zero(name):
    start, section = definitions[name]
    table = sections[section]
    for index in range(table[7]):
        offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
        if offset == start:
            return symbols[symbol][0]
    raise AssertionError(name)
assert slot_zero(listener).startswith("?onEvent@CMainFrame@@")
assert slot_zero(primary).startswith("?GetRuntimeClass@CMainFrame@@")
target, target_relocs, _ = match.target("2008-06", "0042e460")
_, body, relocs = next((name, body, refs) for name, body, refs in match.coff_functions(obj)
                       if name.startswith("?GetRuntimeClass@CMainFrame@@"))
assert match.exact_match(target, target_relocs, body, relocs)
original = ROOT / "work/2008-06/original-p4-reference/Roblox.exe"
import pefile
pe = pefile.PE(str(original), fast_load=True)
assert struct.unpack("<I", pe.get_data(0x811a0c - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x42fb20
assert struct.unpack("<I", pe.get_data(0x811a1c - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x42e460
paths = [source, ROOT / "rebuild/2008-06/native-classes/CMainFrameColor.cpp", ROOT / "rebuild/2008-06/native-headers/CMainFrame.h", ROOT / "rebuild/2008-06/native-headers/CMainFrameBases.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, methods=results,
               scope="Listener slot and primary GetRuntimeClass body verified; runtime class data, remaining ABI and runtime linkage open.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: CMainFrame color callback matches")
