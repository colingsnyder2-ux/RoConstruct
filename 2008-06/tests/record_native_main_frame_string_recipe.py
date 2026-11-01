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
source = ROOT / "rebuild/2008-06/tests/../native-classes/CMainFrameCommands.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK", "/I" + str(ROOT / "tools/libs/xtp-11.2.2/Source")]
flags += ["/FoNativeFrameNoInline.obj", str(source)]

# Mirror xtp-11.2.2-lib-imports recipe: mark the imported CString conversion noinline
# in preprocessed source; the source and shared headers remain unchanged.
pre_flags = [flag for flag in flags[:-2] if flag != "/c"] + ["/P", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", pre_flags, out)
assert code == 0, log
preprocessed = (out / "CMainFrameCommands.i").read_text(encoding="utf8", errors="replace")
needle = "operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );"
assert preprocessed.count(needle) == 1
patched = preprocessed.replace(needle, "__declspec(noinline) " + needle)
translation = out / "NativeFrameNoInline.cpp"
translation.write_text(patched, encoding="utf8")
compile_flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD", "/FoNativeFrameNoInline.obj", str(translation)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", compile_flags, out)
assert code == 0, log
obj = (out / "NativeFrameNoInline.obj").read_bytes()
methods = []
for address, prefix in (("004309f0", "?hideEditorChrome@CMainFrame@@"), ("00430f50", "?showEditorChrome@CMainFrame@@"), ("00431f10", "?OnClose@CMainFrame@@")):
    target, target_relocs, _ = match.target("2008-06", address)
    name, body, refs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith(prefix))
    assert match.exact_match(target, target_relocs, body, refs), name
    methods.append(dict(address=address,symbol=name,size=len(body),relocation_normalized_exact=True))
sections,symbols,definitions,_ = match._coff_data_index(obj)
for row in methods:
    start,section=definitions[row["symbol"]];table=sections[section];refs=[]
    for index in range(table[7]):
        offset,sym,kind=struct.unpack_from("<IIH",obj,table[5]+index*10)
        if start<=offset<start+row["size"]:refs.append(symbols[sym][0])
    assert any(symbol.startswith("__imp_??B?$CSimpleStringT@D$00@ATL@@") for symbol in refs), row
import pefile
pe=pefile.PE(str(ROOT/"work/2008-06/original-p4-reference/Roblox.exe")); base=pe.OPTIONAL_HEADER.ImageBase
assert any(entry.address==0x803ee0 and entry.ordinal==910 and dll.dll.lower()==b"mfc90.dll" for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports)
exports=(ROOT/"tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def").read_text(errors="replace").splitlines()
assert "??B?$CSimpleStringT@D$00@ATL@@" in next(line for line in exports if " @ 910 NONAME" in line)
for row in methods:
    target,_,_=match.target("2008-06",row["address"])
    assert bytes.fromhex("ff15e03e8000") in target
paths=[source, ROOT/"rebuild/2008-06/native-headers/CMainFrame.h", ROOT/"rebuild/2008-06/native-headers/CMainFrameBases.h", ROOT/"roc/libs.py",Path(__file__)]
receipt=dict(revision=subprocess.check_output(["git","rev-parse","HEAD"],cwd=ROOT,text=True).strip(),sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},compiler_build=21022,preprocess_flags=pre_flags,compile_flags=compile_flags,methods=methods,scope="CString conversion import matches; remaining direct/data relocations and runtime integration remain open.")
output=ROOT/"work/2008-06"/sys.argv[1];output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(receipt,indent=2)+"\n")
print("PASS: frame save, restore and close match with original CString recipe")
