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
flags += ["/FoNativeMainFrameCommands.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeMainFrameCommands.obj").read_bytes()


methods = []
for address, name in (("0042e570", "showDockPane"), ("00431b40", "setFullscreen"), ("00430160", "restoreFullscreen"), ("004302b0", "updateMonitor"), ("0042f9d0", "exchangeLayout"), ("00431bf0", "OnActivate"),
                      ("00430360", "OnActivateApp"), ("00430b40", "OnDestroy"), ("00431c40", "OnGetMinMaxInfo"), ("0042ef10", "OnWindowPosChanging"), ("0042e550", "handle_42e550"),
                      ("0042eec0", "handle_42eec0"), ("0042eef0", "handle_42eef0"),
                      ("0042e5e0", "handle_42e5e0"), ("0042fb80", "handle_42fb80"),
                      ("0042fbb0", "handle_42fbb0"), ("0042ee90", "handle_42ee90"),
                      ("0042ed00", "handle_42ed00"), ("004314c0", "handle_4314c0"),
                      ("00431ce0", "handle_431ce0"), ("0042e610", "handle_42e610")):
    target, target_relocs, _ = match.target("2008-06", address)
    symbol, body, relocs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith("?" + name + "@CMainFrame@@"))
    assert match.exact_match(target, target_relocs, body, relocs), name
    methods.append(dict(address=address, symbol=symbol, size=len(body), relocation_normalized_exact=True))
sections, symbols, definitions, _ = match._coff_data_index(obj)
for address, name, expected in (("004302b0", "updateMonitor", [("?singleton@StandardOut@RBX@@", 0x569620), ("?print@StandardOut@RBX@@", 0x5693a0)]),
    ("0042f9d0", "exchangeLayout", [("?DoPropExchange@CXTPCommandBars@@", 0x6e4460), ("?GetShortcutManager@CXTPCommandBars@@", 0x6a2940), ("?DoPropExchange@CXTPCommandBarsOptions@@", 0x6a63e0), ("?DoPropExchange@CXTPDockingPaneManager@@", 0x6e6950), ("?InternalRelease@CCmdTarget@@", 0x6a0be4)]),
    ("00430b40", "OnDestroy", [("?restoreFullscreen@CMainFrame@@", 0x430160), ("?SaveWindowPos@CXTWindowPos@@", 0x6e4ab0), ("?initializeToolbars@CMainFrame@@", 0x4307e0), ("?OnDestroy@CMDIFrameWnd@@", 0x6a1034)]),
    ("00431c40", "OnGetMinMaxInfo", [("?Default@CWnd@@", 0x6a0c68), ("?singleton@?$GlobalSettingsItem@VCRenderSettings@@", 0x412d50), ("?getFullscreenSize@CRenderSettings@@", 0x445250)]),
    ("00431bf0", "OnActivate", [("?OnActivate@CFrameWnd@@", 0x6a1052), ("?configureFullscreen@CMainFrame@@", 0x4318b0), ("?ShowWindow@CWnd@@", 0x6a096e)]),
    ("00430360", "OnActivateApp", [("?Default@CWnd@@", 0x6a0c68), ("?restoreFullscreen@CMainFrame@@", 0x430160), ("?ShowWindow@CWnd@@", 0x6a096e)]),
    ("0042ef10", "OnWindowPosChanging", [("?Default@CWnd@@", 0x6a0c68)]),
    ("00430160", "restoreFullscreen", [("?singleton@StandardOut@RBX@@", 0x569620), ("?print@StandardOut@RBX@@", 0x5693a0), ("?ShowWindow@CWnd@@", 0x6a096e), ("?ModifyStyle@CWnd@@", 0x6a0e12)]),
    ("00431b40", "setFullscreen", [("?configureFullscreen@CMainFrame@@", 0x4318b0), ("?restoreFullscreen@CMainFrame@@", 0x430160), ("?SetWindowPos@CWnd@@", 0x6a0a46)]),
    ("0042e570", "showDockPane", [("?FindPane@CXTPDockingPaneManager@@", 0x6e5920), ("?CreatePane@CXTPDockingPaneManager@@", 0x6e6e60), ("?ShowPane@CXTPDockingPaneManager@@", 0x6e5960)]),
    ("0042e5e0", "handle_42e5e0", [("?showDockPane@CMainFrame@@", 0x42e570)]),
    ("0042fb80", "handle_42fb80", [("?showDockPane@CMainFrame@@", 0x42e570)]),
    ("0042fbb0", "handle_42fbb0", [("?showDockPane@CMainFrame@@", 0x42e570)]),
    ("0042ee90", "handle_42ee90", [("?showDockPane@CMainFrame@@", 0x42e570)]),
    ("004314c0", "handle_4314c0", [("?showEditorChrome@CMainFrame@@", 0x430f50)]),
    ("00431ce0", "handle_431ce0", [("?setFullscreen@CMainFrame@@", 0x431b40)])):
    row = next(row for row in methods if row["address"] == address)
    start, section = definitions[row["symbol"]]; table = sections[section]; found = {}
    for index in range(table[7]):
        offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
        if offset >= start: found[offset-start] = symbols[symbol][0]
    original, _, _ = match.target("2008-06", address)
    calls = {i.address-int(address,16)+1: int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(original,int(address,16)) if i.mnemonic == "call" and i.op_str.startswith("0x")}
    for prefix, target in expected:
        offset = next(offset for offset, symbol in found.items() if symbol.startswith(prefix))
        assert calls[offset] == target, (name, prefix, calls.get(offset), target)
destroy = next(row for row in methods if row["address"] == "00430b40")
start, section = definitions[destroy["symbol"]]; table = sections[section]
for index in range(table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + index * 10)
    if symbols[symbol][0].startswith("?Detach@CXTPTabClientWnd@@"):
        assert offset-start == 0x80
        break
else: raise AssertionError("tab detach relocation missing")
original, _, _ = match.target("2008-06", "00430b40")
assert any(i.mnemonic == "jmp" and i.op_str == "0x7054d0" and i.address - 0x430b40 + 1 == 0x80 for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(original, 0x430b40))
# Verify repeated relocation sites, including both docking branches and releases.
def verify_sites(address, expected):
    row = next(row for row in methods if row["address"] == address)
    start, section = definitions[row["symbol"]]; table = sections[section]
    sites = {}
    for index in range(table[7]):
        offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + index * 10)
        if start <= offset < start + row["size"]: sites[offset-start] = symbols[symbol][0]
    original, _, _ = match.target("2008-06", address)
    calls = {i.address-int(address,16)+1:int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(original,int(address,16)) if i.mnemonic == "call" and i.op_str.startswith("0x")}
    for offset, prefix, target in expected:
        assert sites[offset].startswith(prefix) and calls[offset] == target, (address,offset)
verify_sites("0042e610", [(0x14,"?FindPane@CXTPDockingPaneManager@@",0x6e5920), (0x45,"?showDockPane@CMainFrame@@",0x42e570),
    (0x55,"?FindPane@CXTPDockingPaneManager@@",0x6e5920), (0x68,"?FindPane@CXTPDockingPaneManager@@",0x6e5920),
    (0x7a,"?DockPane@CXTPDockingPaneManager@@",0x6e6f20), (0x8c,"?DockPane@CXTPDockingPaneManager@@",0x6e6f20)])
verify_sites("0042f9d0", [(offset,"?InternalRelease@CCmdTarget@@",0x6a0be4) for offset in (0xff,0x111,0x122,0x13b)])
# Save-layout path remains partial: older MFC code calls the CString conversion import.
show_target, show_target_relocs, _ = match.target("2008-06", "004309f0")
show_name, show_body, show_relocs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith("?hideEditorChrome@CMainFrame@@"))
assert len(show_target) == 230 and len(show_body) == 224
assert not match.exact_match(show_target, show_target_relocs, show_body, show_relocs)
show_start, show_section = definitions[show_name]; show_table = sections[show_section]
show_symbols = []
for index in range(show_table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, show_table[5] + index * 10)
    if show_start <= offset < show_start + len(show_body): show_symbols.append(symbols[symbol][0])
for prefix in ("??0CXTPPropExchangeXMLNode@@", "?OnBeforeExchange@CXTPPropExchangeXMLNode@@",
               "?SaveToFile@CXTPPropExchangeXMLNode@@", "?ShowWorkspace@CXTPTabClientWnd@@",
               "?RemoveAll@CXTPCommandBars@@", "?DestroyAll@CXTPDockingPaneManager@@"):
    assert any(symbol.startswith(prefix) for symbol in show_symbols)
restore_target, restore_relocs, _ = match.target("2008-06", "00430f50")
restore_name, restore_body, restore_refs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith("?showEditorChrome@CMainFrame@@"))
assert len(restore_target) == 226 and len(restore_body) == 220
assert not match.exact_match(restore_target, restore_relocs, restore_body, restore_refs)
close_target, close_relocs, _ = match.target("2008-06", "00431f10")
close_name, close_body, close_refs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith("?OnClose@CMainFrame@@"))
assert len(close_target) == 236 and len(close_body) == 230
assert not match.exact_match(close_target, close_relocs, close_body, close_refs)
close_start, close_section = definitions[close_name]; close_table = sections[close_section]; close_symbols = {}
for index in range(close_table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, close_table[5] + index * 10)
    if close_start <= offset < close_start+len(close_body): close_symbols[offset-close_start] = symbols[symbol][0]
close_calls = {i.address-0x431f10+1:int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(close_target,0x431f10) if i.mnemonic == "call" and i.op_str.startswith("0x")}
for prefix, target in (("??1worker_thread@RBX@@",0x4273a0), ("?setFullscreen@CMainFrame@@",0x431b40)):
    offset = next(offset for offset, symbol in close_symbols.items() if symbol.startswith(prefix))
    assert close_calls[offset] == target
# Original keep-alive delete target 004273a0 is a tail jump to worker_thread destructor.
worker_source = ROOT / "rebuild/2008-06/tests/NativeWorkerThread.cpp"
worker_flags = flags[:-2] + ["/FoNativeWorkerThread.obj", str(worker_source)]
worker_code, worker_log = rebuild.run(rebuild.toolchain(21022), "cl", worker_flags, out)
assert worker_code == 0, worker_log
worker_obj = (out / "NativeWorkerThread.obj").read_bytes()
worker_target, worker_target_relocs, _ = match.target("2008-06", "00595cb0")
_, worker_body, worker_refs = next((n,b,r) for n,b,r in match.coff_functions(worker_obj) if n.startswith("??1worker_thread@RBX@@"))
assert match.exact_match(worker_target, worker_target_relocs, worker_body, worker_refs)
trampoline, _, _ = match.target("2008-06", "004273a0")
assert next(Cs(CS_ARCH_X86, CS_MODE_32).disasm(trampoline, 0x4273a0)).op_str == "0x595cb0"
import pefile
pe = pefile.PE(str(ROOT / "work/2008-06/original-p4-reference/Roblox.exe"))
imports = {item.address: item.name for dll in pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports}
for address, name in ((0x802e34, b"GetWindowRect"), (0x802d70, b"CopyRect"), (0x802d6c, b"IsRectEmpty")):
    assert imports[address] == name
thunks = ((0x6a1052, 0x80341c, 4572, "?OnActivate@CFrameWnd@@"),
          (0x6a0c68, 0x80315c, 2069, "?Default@CWnd@@"),
          (0x6a096e, 0x803ec4, 6584, "?ShowWindow@CWnd@@"),
          (0x6a0e12, 0x803278, 4513, "?ModifyStyle@CWnd@@"))
exports = (ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def").read_text(errors="replace").splitlines()
for thunk, pointer, ordinal, prefix in thunks:
    assert pe.get_data(thunk-pe.OPTIONAL_HEADER.ImageBase, 6) == b"\xff\x25" + struct.pack("<I", pointer)
    assert any(i.address == pointer and i.ordinal == ordinal and dll.dll.lower() == b"mfc90.dll" for dll in pe.DIRECTORY_ENTRY_IMPORT for i in dll.imports)
    assert prefix in next(line for line in exports if " @ %d NONAME" % ordinal in line)
original, _, _ = match.target("2008-06", "00431b40")
assert original[0x2c:0x32] == bytes.fromhex("ff15342e8000")
assert original[0x38:0x3e] == bytes.fromhex("ff15702d8000")
assert original[0x64:0x6a] == bytes.fromhex("ff156c2d8000")
paths = [source, worker_source, ROOT / "rebuild/2008-06/native-headers/CMainFrame.h", ROOT / "rebuild/2008-06/native-headers/CMainFrameBases.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(), sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}, compiler_build=21022, flags=flags, methods=methods, partial_hideEditorChrome=dict(address="004309f0", original_size=230, candidate_size=224, relocation_normalized_exact=False), partial_showEditorChrome=dict(address="00430f50", original_size=226, candidate_size=220, relocation_normalized_exact=False), partial_close=dict(address="00431f10", original_size=236, candidate_size=230, relocation_normalized_exact=False), scope="Selected direct calls verified; editor chrome save/restore CString conversion mismatch, worker-thread synchronization ABI, settings base-template RTTI, full class ABI and runtime integration open.")
output = ROOT / "work/2008-06" / sys.argv[1]; output.parent.mkdir(parents=True,exist_ok=True); output.write_text(json.dumps(receipt,indent=2)+"\n")
print("PASS: CMainFrame monitor, layout exchange, fullscreen transitions and frame handlers match")

