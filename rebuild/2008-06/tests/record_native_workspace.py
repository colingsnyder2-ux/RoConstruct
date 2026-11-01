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
source = ROOT / "rebuild/2008-06/tests/NativeWorkspaceLayout.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/FoNativeWorkspaceLayout.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeWorkspaceLayout.obj").read_bytes()
results = []
for address, prefix in (("0046ab60", "??0CWorkspace@@"),
                        ("0046a940", "?getDataModel@CWorkspace@@"),
                        ("0046ab90", "?writeXmlModel@CWorkspace@@")):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
# Resolve direct calls in the writer instead of masking them as arbitrary bytes.
sections, symbols, definitions, _ = match._coff_data_index(obj)
writer = results[2]
start, section = definitions[writer["symbol"]]
table = sections[section]
relocations = {}
for index in range(table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
    if offset >= start:
        relocations[offset - start] = symbols[symbol][0]
target, _, _ = match.target("2008-06", "0046ab90")
calls = {instruction.address - 0x46ab90 + 1: int(instruction.op_str, 16)
         for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, 0x46ab90)
         if instruction.mnemonic == "call" and instruction.op_str.startswith("0x")}
writer["verified_direct_calls"] = []
for prefix, address in (("?newRootElement@SerializerV2@@", 0x591a30),
                        ("??0Lock@DataModel@RBX@@QAE@V?$shared_ptr", 0x411b40),
                        ("?getDataModel@CWorkspace@@", 0x46a940),
                        ("?writeChildren@Instance@RBX@@", 0x558110),
                        ("??1Lock@DataModel@RBX@@", 0x5773c0)):
    offset, symbol = next((offset, symbol) for offset, symbol in relocations.items() if symbol.startswith(prefix))
    assert calls[offset] == address, (symbol, calls.get(offset), address)
    writer["verified_direct_calls"].append(dict(offset=offset, symbol=symbol, target=hex(address)))
paths = [source, ROOT / "rebuild/2008-06/native-classes/CWorkspace.cpp", ROOT / "rebuild/2008-06/native-headers/CWorkspace.h", ROOT / "rebuild/2008-06/native-headers/v8tree/Instance.h", ROOT / "rebuild/2008-06/native-headers/v8datamodel/DataModel.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, methods=results,
               scope="Inactive compiler proof; XML writer direct calls verified against original. Other relocations and runtime linking remain unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: workspace constructor, getter and XML writer match")
