"""Compare original CRobloxView RTTI bases to native compiler layout."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, rebuild

out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
source = ROOT / "rebuild/2008-06/tests/NativeMainFrameBases.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK", "/I" + str(ROOT / "tools/libs/xtp-11.2.2/Source")]
flags += ["/d1reportSingleClassLayoutCMainFrameBases", "/d1reportSingleClassLayoutCMainFrame", "/FoCMainFrameBases.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
assert "class CMainFrameBases\tsize(244):" in log
assert "class CMainFrame\tsize(1204):" in log
frame_marker = next(line for line in log.splitlines() if line.startswith("CMainFrame::$vftable@") and "VFillToolColor" in line)
assert "| -240" in log[log.index(frame_marker):log.index(frame_marker) + 220]
marker = next(line for line in log.splitlines() if line.startswith("CMainFrameBases::$vftable@") and "VFillToolColor" in line)
assert "| -240" in log[log.index(marker):log.index(marker) + 220]
original = ROOT / "work/2008-06/original-p4-reference/Roblox.exe"
pe = pefile.PE(str(original), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
read32 = lambda address: struct.unpack("<I", pe.get_data(address - base, 4))[0]
locator = read32(0x811a1c - 4)
assert pe.get_string_at_rva(read32(locator + 12) - base + 8) == b".?AVCMainFrame@@"
hierarchy = read32(locator + 16)
array = read32(hierarchy + 12)
found = {}
for index in range(read32(hierarchy + 8)):
    descriptor = read32(array + 4 * index)
    name = pe.get_string_at_rva(read32(descriptor) - base + 8).decode("ascii")
    found[name] = struct.unpack("<i", pe.get_data(descriptor + 8 - base, 4))[0]
assert found[".?AVCXTPMDIFrameWnd@@"] == 0
assert found[".?AV?$Listener@VFillToolColor@RBX@@VBrickColor@2@@RBX@@"] == 240
pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
# CString ctor/dtor imports prove the 0x108 member type; monitor comes from Win32.
imports = {entry.address: (dll.dll.lower(), entry.name, entry.ordinal)
           for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports}
assert imports[0x803f04] == (b"mfc90.dll", None, 316)
assert imports[0x803f14] == (b"mfc90.dll", None, 601)
assert imports[0x802d58][1] == b"MonitorFromWindow"
exports = (ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def").read_text(errors="replace")
assert "??0?$CStringT@DV?$StrTraitMFC_DLL" in next(line for line in exports.splitlines() if " @ 316 NONAME" in line)
assert "??1?$CStringT@DV?$StrTraitMFC_DLL" in next(line for line in exports.splitlines() if " @ 601 NONAME" in line)
for address, expected in ((0x4302d1, "dword ptr [0x802d58]"), (0x4302d7, "dword ptr [esi + 0xfc], eax")):
    assert next(Cs(CS_ARCH_X86, CS_MODE_32).disasm(pe.get_data(address - base, 15), address)).op_str == expected
# Theme constructor installs its own RTTI vtable.
theme_locator = read32(0x85cf68 - 4)
assert pe.get_string_at_rva(read32(theme_locator + 12) - base + 8) == b".?AVCXTThemeManager@@"
# Pane constructors install typed vtables; allocation sites assign the three pointers.
for vtable, name in ((0x85c064, b".?AVCXTSplitterWnd@@"), (0x811444, b".?AVCDataModelPropGrid@@"), (0x81bbc4, b".?AVCSelectionCaption@@")):
    item_locator = read32(vtable - 4)
    assert pe.get_string_at_rva(read32(item_locator + 12) - base + 8) == name
for address, vtable in (("00708c50", 0x85c064), ("00431040", 0x811444), ("00466880", 0x81bbc4)):
    body, _, _ = __import__("roc.match", fromlist=["target"]).target("2008-06", address)
    assert struct.pack("<I", vtable) in body
for address, expected in ((0x431544, "edi, [ebx + 0x3a8]"), (0x431574, "0x708c50"),
                          (0x4315df, "0x466880"), (0x4315ec, "esi, [ebx + 0x3b0]"),
                          (0x43167f, "0x431040"), (0x431688, "esi, [ebx + 0x3ac]")):
    instruction = next(Cs(CS_ARCH_X86, CS_MODE_32).disasm(pe.get_data(address - base, 15), address))
    assert instruction.op_str == expected
# Original constructor calls these component constructors at these offsets.
constructor, _, _ = __import__("roc.match", fromlist=["target"]).target("2008-06", "004321f0")
instructions = {i.address: i for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(constructor, 0x4321f0)}
for address, operand in ((0x43226c, "ecx, [esi + 0x10c]"), (0x432277, "0x6e4a80"),
                         (0x43227c, "ecx, [esi + 0x138]"), (0x432282, "0x6e6b80"),
                         (0x432287, "ecx, [esi + 0x284]"), (0x432292, "0x703600"),
                         (0x4322a9, "ecx, [esi + 0x3b4]"), (0x4322b4, "0x70dbb0"),
                         (0x4322b9, "ecx, [esi + 0x3e0]"), (0x4322c4, "0x70ea60")):
    assert instructions[address].op_str == operand
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
files = [source, ROOT / "rebuild/2008-06/native-headers/CMainFrame.h", ROOT / "rebuild/2008-06/native-headers/CMainFrameBases.h", ROOT / "rebuild/2008-06/native-headers/util/Events.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
    sources={str(p.relative_to(ROOT)): sha(p) for p in files}, original_sha256=sha(original),
    compiler_build=21022, base_extent=244, listener_offset=240, full_class_size=1204,
    members={"CXTWindowPos": "0x10c", "CXTPDockingPaneManager": "0x138", "CXTPTabClientWnd": "0x284", "CXTThemeManager": "0x3b4", "CXTPStatusBar": "0x3e0", "splitter": "0x3a8", "propertyGrid": "0x3ac", "selectionCaption": "0x3b0"},
    scope="Candidate size and selected member offsets verified; some pointer identities, ownership, virtual bodies and runtime linkage unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: CMainFrame base hierarchy matches original RTTI")

