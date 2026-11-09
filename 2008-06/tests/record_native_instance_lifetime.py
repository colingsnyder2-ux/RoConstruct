"""Compile and verify inactive native Instance destructor."""
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
source = ROOT / "rebuild/2008-06/tests/../native-classes/InstanceLifetime.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/FoNativeInstanceLifetime.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeInstanceLifetime.obj").read_bytes()
results = []
for address, prefix in (("0055b7e0", "??0Instance@RBX@@QAE@XZ"), ("0055b960", "??0Instance@RBX@@QAE@PBD@Z"), ("0055a540", "??1Instance@RBX@@"), ("0055a470", "?createChild@Instance@RBX@@")):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
sections, symbols, definitions, _ = match._coff_data_index(obj)
for address, expected in (("0055b7e0", [("??0Guid@RBX@@", 0x5a8300), ("??0?$Described@VInstance@RBX@@", 0x55b780), ("??0?$Notifier@VInstance@RBX@@UChildAdded@", 0x5e9ec0), ("??2@YAPAXI@Z", 0x6a0920)]),
                          ("0055b960", [("??0Guid@RBX@@", 0x5a8300), ("??0?$Described@VInstance@RBX@@", 0x55b780), ("??0?$Notifier@VInstance@RBX@@UChildAdded@", 0x5e9ec0), ("??2@YAPAXI@Z", 0x6a0920)]),
                          ("0055a540", [("??1SignalSource@Reflection@RBX@@", 0x56bd40), ("??1?$GuidItem@VInstance@RBX@@", 0x4b3760)]),
                          ("0055a470", [("?create@?$AbstractFactoryProduct@VInstance@RBX@@", 0x420190)])):
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
paths = [source, ROOT / "rebuild/2008-06/native-headers/v8tree/Instance.h", ROOT / "rebuild/2008-06/native-headers/util/GuidItem.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, object_sha256=hashlib.sha256(obj).hexdigest(), methods=results,
               scope="Selected direct calls verified; GuidItem destructor, remaining virtuals and runtime linking remain unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: Instance constructor and destructor match")
