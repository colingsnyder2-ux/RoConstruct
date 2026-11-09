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
source = ROOT / "rebuild/2008-06/tests/../native-classes/LoginRenewer.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK", "/I" + str(ROOT / "tools/libs/xtp-11.2.2/Source")]
flags += ["/FoNativeLoginRenewer.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeLoginRenewer.obj").read_bytes()




target, target_relocs, _ = match.target("2008-06", "004277d0")
symbol, body, relocs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith("??0LoginRenewer@@"))
assert match.exact_match(target, target_relocs, body, relocs)
sections,symbols,definitions,_ = match._coff_data_index(obj)
start, section = definitions[symbol]; table = sections[section]; refs = {}
for index in range(table[7]):
    offset, sym, kind = struct.unpack_from("<IIH", obj, table[5] + index * 10)
    if start <= offset < start + len(body): refs[offset-start] = symbols[sym][0]
for offset,prefix in ((0x36,"?loginRenewalUrl@@"),(0x3e,"?renewLogin@@"),(0x44,"??$bind@"), (0x69,"??0worker_thread@RBX@@")):
    assert refs[offset].startswith(prefix)
assert struct.unpack_from("<I", target, 0x3e)[0] == 0x427480
calls = {i.address-0x4277d0+1:int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(target,0x4277d0) if i.mnemonic == "call" and i.op_str.startswith("0x")}
assert calls[0x36] == 0x427310 and calls[0x44] == 0x577110 and calls[0x69] == 0x5971d0
paths = [source, ROOT / "rebuild/2008-06/native-headers/LoginRenewer.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git","rev-parse","HEAD"],cwd=ROOT,text=True).strip(), sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}, compiler_build=21022, flags=flags, size=len(body), callback=hex(0x427480), scope="Constructor code and selected call targets match; callback and URL symbol identities remain provisional; runtime linkage unverified.")
output=ROOT / "work/2008-06" / sys.argv[1]; output.parent.mkdir(parents=True,exist_ok=True); output.write_text(json.dumps(receipt,indent=2)+"\n")
print("PASS: LoginRenewer constructor matches")
