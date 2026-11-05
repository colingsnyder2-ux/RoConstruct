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
source = ROOT / "rebuild/2008-06/tests/../native-classes/CMainFrameToolbars.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK", "/I" + str(ROOT / "tools/libs/xtp-11.2.2/Source")]
flags += ["/FoNativeMainFrameToolbars.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeMainFrameToolbars.obj").read_bytes()



xtp_source = ROOT / "rebuild/2008-06/tests/NativeXtpToolbar.cpp"
xtp_flags = flags[:-2] + ["/FoNativeXtpToolbar.obj", str(xtp_source)]
xtp_code, xtp_log = rebuild.run(rebuild.toolchain(21022), "cl", xtp_flags, out)
assert xtp_code == 0, xtp_log
xtp_obj = (out / "NativeXtpToolbar.obj").read_bytes()
xtp_target, xtp_target_relocs, _ = match.target("2008-06", "006c1ea0")
_, xtp_body, xtp_relocs = next((n,b,r) for n,b,r in match.coff_functions(xtp_obj) if n.startswith("?EnableDocking@CXTPToolBar@@"))
assert match.exact_match(xtp_target, xtp_target_relocs, xtp_body, xtp_relocs)
popup_source = ROOT / "rebuild/2008-06/tests/NativeXtpPopup.cpp"
popup_vendor = ROOT / "tools/libs/xtp-11.2.2/Source/CommandBars/XTPCommandBar.cpp"
popup_method = popup_source.read_text().split("BOOL CXTPCommandBar::SetPopuped(", 1)[1]
assert "BOOL CXTPCommandBar::SetPopuped(" + popup_method.strip() in popup_vendor.read_text(encoding="latin1")
popup_flags = flags[:-2] + ["/FoNativeXtpPopup.obj", str(popup_source)]
popup_code, popup_log = rebuild.run(rebuild.toolchain(21022), "cl", popup_flags, out)
assert popup_code == 0, popup_log
popup_obj = (out / "NativeXtpPopup.obj").read_bytes()
popup_target, popup_target_relocs, _ = match.target("2008-06", "006b6ed0")
popup_name, popup_body, popup_relocs = next((n,b,r) for n,b,r in match.coff_functions(popup_obj) if n.startswith("?SetPopuped@CXTPCommandBar@@"))
assert match.exact_match(popup_target, popup_target_relocs, popup_body, popup_relocs)
popup_sections, popup_symbols, popup_defs, _ = match._coff_data_index(popup_obj)
popup_start, popup_section = popup_defs[popup_name]; popup_table = popup_sections[popup_section]
popup_refs = {}
for index in range(popup_table[7]):
    offset, sym, kind = struct.unpack_from("<IIH", popup_obj, popup_table[5] + index * 10)
    if popup_start <= offset < popup_start+len(popup_body): popup_refs[offset-popup_start] = popup_symbols[sym][0]
assert popup_refs[0xde].startswith("?s_nExpandDelay@CXTPCommandBar@@")
assert struct.unpack_from("<I", popup_target, 0xde)[0] == 0x96617c
import pefile
pe = pefile.PE(str(ROOT / "work/2008-06/original-p4-reference/Roblox.exe"), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
target, target_relocs, _ = match.target("2008-06", "004307e0")
symbol, body, relocs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith("?initializeToolbars@CMainFrame@@"))
assert match.exact_match(target, target_relocs, body, relocs)
sections, symbols, definitions, _ = match._coff_data_index(obj)
start, section = definitions[symbol]; table = sections[section]; resolved = {}
for index in range(table[7]):
    offset, sym, kind = struct.unpack_from("<IIH", obj, table[5] + index * 10)
    if start <= offset < start + len(body): resolved[offset-start] = symbols[sym][0]
calls = {i.address - 0x4307e0 + 1: int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(target,0x4307e0) if i.mnemonic == "call" and i.op_str.startswith("0x")}
expected = {0x1a:("?SetMenu@CXTPCommandBars@@",0x6a3df0), 0x37:("?SetFlags@CXTPCommandBar@@",0x6b5090),
            0x47:("?Add@CXTPCommandBars@@",0x6a3ff0), 0x82:("?Add@CXTPCommandBars@@",0x6a3ff0),
            0xb9:("?Add@CXTPCommandBars@@",0x6a3ff0), 0xee:("?Add@CXTPCommandBars@@",0x6a3ff0),
            0x120:("?Add@CXTPCommandBars@@",0x6a3ff0), 0x14a:("?EnableDocking@CXTPToolBar@@",0x6c1ea0),
            0x165:("?DockRightOf@?$CXTPCommandBarsSiteBase@VCMDIFrameWnd@@@@",0x4303a0), 0x172:("?DockRightOf@?$CXTPCommandBarsSiteBase@VCMDIFrameWnd@@@@",0x4303a0),
            0x180:("?HideCommands@CXTPCommandBars@@",0x6a66e0)}
for offset,(prefix,address) in expected.items():
    assert resolved[offset].startswith(prefix) and calls[offset] == address
dock_name, dock_body, dock_relocs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith("?DockRightOf@?$CXTPCommandBarsSiteBase@VCMDIFrameWnd@@@@"))
dock_target, dock_target_relocs, _ = match.target("2008-06", "004303a0")
assert match.exact_match(dock_target, dock_target_relocs, dock_body, dock_relocs)
dock_start, dock_section = definitions[dock_name]; dock_table = sections[dock_section]
dock_symbols = {}
for index in range(dock_table[7]):
    offset, sym, kind = struct.unpack_from("<IIH", obj, dock_table[5] + index * 10)
    if dock_start <= offset < dock_start + len(dock_body): dock_symbols[offset-dock_start] = symbols[sym][0]
dock_calls = {i.address-0x4303a0+1:int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(dock_target,0x4303a0) if i.mnemonic == "call" and i.op_str.startswith("0x")}
for offset, prefix, address in ((0x1f,"?RepositionBars@CWnd@@",0x6a0fc8),(0x2d,"??0CXTPWindowRect@@",0x6f7ad0),(0x86,"?DockCommandBar@CXTPCommandBars@@",0x6a2a00)):
    assert dock_symbols[offset].startswith(prefix) and dock_calls[offset] == address
assert dock_symbols[0x6a].startswith("__imp__OffsetRect@12")
name = next(n for n in definitions if n.startswith("?nativeHiddenCommands@@"))
start, section = definitions[name]; table = sections[section]
assert obj[table[4]+start:table[4]+start+104] == pe.get_data(0x92ec60-base,104)
assert resolved[0x179].startswith("?nativeHiddenCommands@@") and resolved[0x192].startswith("?s_nExpandDelay@CXTPCommandBar@@")
paths = [source, xtp_source, popup_source, popup_vendor, ROOT / "rebuild/2008-06/native-headers/CMainFrame.h", ROOT / "rebuild/2008-06/native-headers/CMainFrameBases.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git","rev-parse","HEAD"],cwd=ROOT,text=True).strip(), sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}, compiler_build=21022, flags=flags, method=dict(address="004307e0", size=len(body), relocation_normalized_exact=True), verified_calls=len(expected), hidden_commands=26, docking_method_size=len(dock_body), enable_docking_size=len(xtp_body), popup_method_size=len(popup_body), scope="Hidden command bytes and calls verified; Expand-delay global identity verified; data linkage and runtime gates remain open.")
output=ROOT / "work/2008-06" / sys.argv[1]; output.parent.mkdir(parents=True,exist_ok=True); output.write_text(json.dumps(receipt,indent=2)+"\n")
print("PASS: toolbar initializer, XTP docking method and hidden-command data match")
