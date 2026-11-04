"""Compile and verify inactive native DataModel lock methods."""
import hashlib
import json
from pathlib import Path
import subprocess
import struct

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
source = ROOT / "rebuild/2008-06/native-classes/DataModelLock.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/FoNativeDataModelLock.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeDataModelLock.obj").read_bytes()
results = []
for address, prefix in (("00411b40", "??0Lock@DataModel@RBX@@QAE@V?$shared_ptr"),
                        ("005773c0", "??1Lock@DataModel@RBX@@"),
                        ("00576f00", "?doLock@Lock@DataModel@RBX@@")):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
# Check direct-call targets separately; relocation-masked equality alone cannot.
sections, symbols, definitions, _ = match._coff_data_index(obj)
expected_calls = {
    "00411b40": [("?doLock@Lock@DataModel@RBX@@", 0x576f00)],
    "00576f00": [("??4shared_count@detail@boost@@", 0x4025b0),
                 ("??2@YAPAXI@Z", 0x6a0920), ("?do_lock@recursive_mutex@boost@@", 0x563090)],
    "005773c0": [("?do_unlock@recursive_mutex@boost@@", 0x5630e0), ("??3@YAXPAX@Z", 0x6a067a)],
}
for result in results:
    address = result["address"]
    start, section = definitions[result["symbol"]]
    table = sections[section]
    relocations = {}
    for index in range(table[7]):
        offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
        if offset >= start:
            relocations[offset - start] = symbols[symbol][0]
    target, _, _ = match.target("2008-06", address)
    calls = {instruction.address - int(address, 16) + 1: int(instruction.op_str, 16)
             for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, int(address, 16))
             if instruction.mnemonic == "call" and instruction.op_str.startswith("0x")}
    verified = []
    for prefix, target_address in expected_calls[address]:
        offset, symbol = next((offset, symbol) for offset, symbol in relocations.items() if symbol.startswith(prefix))
        assert calls[offset] == target_address, (symbol, calls.get(offset), target_address)
        verified.append(dict(offset=offset, symbol=symbol, target=hex(target_address)))
    result["verified_direct_calls"] = verified
paths = [source, ROOT / "rebuild/2008-06/native-headers/v8datamodel/DataModel.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, methods=results,
               scope="Inactive compiler proof; selected direct-call targets checked against original. Full data relocations and runtime linking remain unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: DataModel lock constructor, doLock, destructor match")
