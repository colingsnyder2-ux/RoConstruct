"""Compile and verify inactive native workspace methods."""
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
source = ROOT / "rebuild/2008-06/native-classes/ServiceProvider.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/FoNativeServiceProvider.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeServiceProvider.obj").read_bytes()
results = []
for address, prefix in (("004530f0", "??$create@VRunService@RBX@@@ServiceProvider"),):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
sections, symbols, definitions, _ = match._coff_data_index(obj)
method = results[0]
start, section = definitions[method["symbol"]]
table = sections[section]
relocs = {}
for index in range(table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
    if offset >= start:
        relocs[offset - start] = symbols[symbol][0]
target, _, _ = match.target("2008-06", "004530f0")
calls = {instruction.address - 0x4530f0 + 1: int(instruction.op_str, 16)
         for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, 0x4530f0)
         if instruction.mnemonic == "call" and instruction.op_str.startswith("0x")}
for prefix, expected in (("??$find@VRunService@RBX@@@ServiceProvider", 0x452c80),
                         ("??$create@VRunService@RBX@@@?$Creatable", 0x405fa0),
                         ("?setParent@Instance@RBX@@", 0x55a8f0)):
    offset, symbol = next((offset, symbol) for offset, symbol in relocs.items() if symbol.startswith(prefix))
    assert calls[offset] == expected, (symbol, calls.get(offset), expected)
lookup, lookup_relocations, _ = match.target("2008-06", "00452c80")
lookup_name, lookup_body, lookup_refs = next((name, body, refs) for name, body, refs in match.coff_functions(obj)
                                             if name.startswith("??$find@VRunService@RBX@@@ServiceProvider"))
lookup_result = dict(address="00452c80", symbol=lookup_name, target_size=len(lookup),
                     compiled_size=len(lookup_body),
                     relocation_normalized_exact=match.exact_match(lookup, lookup_relocations, lookup_body, lookup_refs))
paths = [source, ROOT / "rebuild/2008-06/native-headers/v8tree/Service.h", ROOT / "rebuild/2008-06/native-headers/v8tree/Instance.h", ROOT / "rebuild/2008-06/native-headers/v8datamodel/DataModel.h", ROOT / "rebuild/2008-06/native-headers/util/Name.h", ROOT / "rebuild/2008-06/native-headers/util/RunStateOwner.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, object_sha256=hashlib.sha256(obj).hexdigest(), methods=results, lookup=lookup_result,
               scope="Inactive compiler proof; create method and selected call targets verified; lookup body, remaining relocations and runtime linking unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: RunService creation matches; lookup remains open")
