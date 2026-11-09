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
source = ROOT / "rebuild/2008-06/tests/../native-classes/CMainFrameCreate.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK", "/I" + str(ROOT / "tools/libs/xtp-11.2.2/Source")]
flags += ["/FoNativeMainFrameCreate.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeMainFrameCreate.obj").read_bytes()





import pefile
pe = pefile.PE(str(ROOT / "work/2008-06/original-p4-reference/Roblox.exe"),fast_load=True); base=pe.OPTIONAL_HEADER.ImageBase
methods=[]
for address,prefix in (("00431d00","?OnCreate@CMainFrame@@"), ("0042ef40","?InitCommandBars@?$CXTPCommandBarsSiteBase@VCMDIFrameWnd@@@@"), ("00430ec0","?reset@?$scoped_ptr@Vworker_thread@RBX@@")):
    target,tr,_=match.target("2008-06",address)
    name,body,relocs=next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith(prefix))
    assert match.exact_match(target,tr,body,relocs),name
    methods.append(dict(address=address,symbol=name,size=len(body)))
sections,symbols,definitions,_=match._coff_data_index(obj)
row=methods[0]; start,section=definitions[row["symbol"]]; table=sections[section]; refs={}
for i in range(table[7]):
    offset,sym,kind=struct.unpack_from("<IIH",obj,table[5]+i*10)
    if start<=offset<start+row["size"]: refs[offset-start]=symbols[sym][0]
original,_,_=match.target("2008-06","00431d00")
calls={i.address-0x431d00+1:int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(original,0x431d00) if i.mnemonic=="call" and i.op_str.startswith("0x")}
expected={0x1f:("?OnCreate@CFrameWnd@@",0x6a105e), 0x52:("?Create@CXTPStatusBar@@",0x70ec40), 0x68:("?SetIndicators@CXTPStatusBar@@",0x70fcd0),
 0x7c:("?InitCommandBars@?$CXTPCommandBarsSiteBase@",0x42ef40), 0x8d:("?SetTheme@CXTThemeManager@@",0x70dc00),
 0x94:("?SetTheme@CXTPPaintManager@@",0x6af0a0), 0xa7:("?InstallDockingPanes@CXTPDockingPaneManager@@",0x6e57f0),
 0xb0:("?SetTheme@CXTPDockingPaneManager@@",0x6e6620), 0xc0:("?Attach@CXTPTabClientWnd@@",0x702c00),
 0xc7:("?GetPaintManager@CXTPTabClientWnd@@",0x710e30), 0xd7:("?EnableToolTips@CXTPTabClientWnd@@",0x701860),
 0xf3:("?GetImageManager@CXTPCommandBars@@",0x6a2f80), 0xfa:("?SetIcons@CXTPImageManager@@",0x6c0f70),
 0x118:("?ShowKeyboardCues@CXTPCommandBarsOptions@@",0x6a2810), 0x121:("?GetToolTipContext@CXTPCommandBars@@",0x6a2f90),
 0x128:("?SetStyle@CXTPToolTipContext@@",0x70bb30), 0x144:("?SetImageManager@CXTPCommandBars@@",0x6a38f0),
 0x157:("?SetIcons@CXTPImageManager@@",0x6c0f70), 0x167:("?showEditorChrome@CMainFrame@@",0x430f50),
 0x172:("?InitializeAllIcons@@",0x42f490), 0x17c:("?updateMonitor@CMainFrame@@",0x4302b0),
 0x1a4:("?setFullscreen@CMainFrame@@",0x431b40), 0x1c1:("??2@YAPAXI@Z",0x6a0920),
 0x1db:("??0LoginRenewer@@",0x4277d0), 0x1f3:("?reset@?$scoped_ptr@Vworker_thread@RBX@@",0x430ec0)}
for offset,(prefix,address) in expected.items(): assert refs[offset].startswith(prefix) and calls[offset]==address,(hex(offset),refs.get(offset),calls.get(offset))
name=next(n for n in definitions if n.startswith("?nativeStatusIndicators@@"));start,section=definitions[name];table=sections[section]
assert obj[table[4]+start:table[4]+start+24]==pe.get_data(0x92ec48-base,24)
assert refs[0x75].startswith("?classMyXTPCommandBars@MyXTPCommandBars@@") and struct.unpack_from("<I",original,0x75)[0]==0x8107c4
assert pe.get_string_at_rva(struct.unpack("<I",pe.get_data(0x8107c4-base,4))[0]-base)==b"MyXTPCommandBars"
paths=[source,ROOT/"rebuild/2008-06/native-headers/CMainFrame.h",ROOT/"rebuild/2008-06/native-headers/LoginRenewer.h",ROOT/"rebuild/2008-06/native-headers/MyXTPCommandBars.h",Path(__file__)]
receipt=dict(revision=subprocess.check_output(["git","rev-parse","HEAD"],cwd=ROOT,text=True).strip(),sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},compiler_build=21022,flags=flags,methods=methods,verified_calls=len(expected),scope="Selected direct calls and status data verified; MyXTPCommandBars remaining vtable/data, icon TU alias and image initialization, remaining ABI and runtime gates open.")
output=ROOT/"work/2008-06"/sys.argv[1];output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(receipt,indent=2)+"\n")
print("PASS: CMainFrame OnCreate and XTP/owner helpers match")
