"""Compile and verify inactive native serializer XML root."""
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
source = ROOT / "rebuild/2008-06/native-classes/SerializerRoot.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/FoNativeSerializerRoot.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeSerializerRoot.obj").read_bytes()
results = []
for address, prefix in (("00591a30", "?newRootElement@SerializerV2@@"),
                        ("00591970", "??$addAttribute@PBD@XmlElement@@"),
                        ("0058c920", "??0XmlNameValuePair@@QAE@ABVName@RBX@@PBD@Z")):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
# Verify repeated attribute calls and name construction, not just masked bytes.
sections, symbols, definitions, _ = match._coff_data_index(obj)
root = results[0]
start, section = definitions[root["symbol"]]
table = sections[section]
relocations = {}
for index in range(table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
    if offset >= start:
        relocations[offset - start] = symbols[symbol][0]
target, _, _ = match.target("2008-06", "00591a30")
calls = {instruction.address - 0x591a30 + 1: int(instruction.op_str, 16)
         for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(target, 0x591a30)
         if instruction.mnemonic == "call" and instruction.op_str.startswith("0x")}
for prefix, address, count in (("?declare@Name@RBX@@", 0x553f90, 1),
                               ("??$addAttribute@PBD@XmlElement@@", 0x591970, 3)):
    found = [(offset, symbol) for offset, symbol in relocations.items() if symbol.startswith(prefix)]
    assert len(found) == count, (prefix, found)
    assert all(calls[offset] == address for offset, symbol in found)
root["verified_direct_calls"] = [dict(offset=offset, symbol=symbol, target=hex(calls[offset]))
                                 for offset, symbol in relocations.items()
                                 if symbol.startswith(("?declare@Name@RBX@@", "??$addAttribute@PBD@XmlElement@@"))]
attribute = results[1]
start, section = definitions[attribute["symbol"]]
table = sections[section]
constructor_relocations = []
for index in range(table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
    if symbols[symbol][0].startswith("??0XmlNameValuePair@@QAE@ABVName@RBX@@PBD@Z"):
        constructor_relocations.append(offset - start)
attribute_target, _, _ = match.target("2008-06", "00591970")
attribute_calls = {instruction.address - 0x591970 + 1: int(instruction.op_str, 16)
                   for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(attribute_target, 0x591970)
                   if instruction.mnemonic == "call" and instruction.op_str.startswith("0x")}
assert len(constructor_relocations) == 1 and attribute_calls[constructor_relocations[0]] == 0x58c920
attribute["verified_constructor_target"] = "0x58c920"
paths = [source, ROOT / "rebuild/2008-06/native-headers/v8tree/Instance.h", ROOT / "rebuild/2008-06/native-headers/v8datamodel/DataModel.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, methods=results,
               scope="Inactive compiler proof; call targets and runtime linking remain unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: serializer root, XML attribute and value constructor match")
