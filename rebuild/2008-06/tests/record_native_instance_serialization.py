"""Compile and verify inactive native Instance XML serialization."""
import hashlib
import json
from pathlib import Path
import subprocess
import struct
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
source = ROOT / "rebuild/2008-06/native-classes/InstanceSerialization.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/FoNativeInstanceSerialization.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeInstanceSerialization.obj").read_bytes()
results = []
for address, prefix in (("00558110", "?writeChildren@Instance@RBX@@"), ("00558c50", "?write@Instance@RBX@@")):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
sections, symbols, definitions, _ = match._coff_data_index(obj)
write = results[1]
start, section = definitions[write['symbol']]
table = sections[section]
target, _, _ = match.target('2008-06', write['address'])
bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', obj, table[5] + 10*i)
    offset -= start
    if 0 <= offset < len(target)-3:
        value = struct.unpack_from('<I', target, offset)[0]
        if kind == 20:
            value = (0x558c50 + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
        bindings.setdefault(symbols[index][0], []).append(value)
for prefix, value in [('?getNullName@Name@RBX@@',0x554270),('?tag_Item@@',0x97535c),('?tag_class@@',0x975378),('?name_referent@@',0x975310),('?tag_Properties@@',0x97530c),('?tag_External@@',0x975358),('?writeProperties@Instance@RBX@@',0x558b80),('?writeChildren@Instance@RBX@@',0x558110),('??0InstanceHandle@RBX@@',0x594e00)]:
    assert any(k.startswith(prefix) and value in v for k,v in bindings.items()), (prefix, bindings)
assert any(k.startswith('?writeProperties@Instance@RBX@@ABEX') for k in bindings), bindings
write['bindings'] = {k:[hex(x) for x in v] for k,v in bindings.items()}
paths = [source, ROOT / "rebuild/2008-06/native-headers/v8tree/Instance.h", ROOT / "rebuild/2008-06/native-headers/v8xml/XmlElement.h", ROOT / "rebuild/2008-06/native-headers/v8datamodel/DataModel.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, object_sha256=hashlib.sha256(obj).hexdigest(), methods=results,
               scope="Inactive compiler proof; write selected calls and data bindings checked, full ABI and runtime remain unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: Instance::write and writeChildren match")
