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
source = ROOT / "rebuild/2008-06/tests/../native-classes/CMainFrameMap.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK", "/I" + str(ROOT / "tools/libs/xtp-11.2.2/Source")]
flags += ["/FoNativeMainFrameMap.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeMainFrameMap.obj").read_bytes()

import pefile
pe = pefile.PE(str(ROOT / "work/2008-06/original-p4-reference/Roblox.exe"), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
sections, symbols, definitions, _ = match._coff_data_index(obj)
map_symbol = next(name for name in definitions if name.startswith("?messageMap@?1??GetThisMessageMap@CMainFrame@@"))
map_start, map_section = definitions[map_symbol]
map_table = sections[map_section]
map_targets = {}
for index in range(map_table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, map_table[5] + 10 * index)
    map_targets[offset - map_start] = symbols[symbol][0]
assert map_targets[0].startswith("?GetThisMessageMap@CMDIFrameWnd@@")
assert struct.unpack("<I", pe.get_data(0x811624 - base, 4))[0] == 0x6a1064
assert pe.get_data(0x6a1064 - base, 6) == bytes.fromhex("ff2528348000")
pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
assert any(entry.address == 0x803428 and entry.ordinal == 4000 and dll.dll.lower() == b"mfc90.dll" for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports)
def_file = (ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def").read_text(errors="replace")
assert "?GetThisMessageMap@CMDIFrameWnd@@" in next(line for line in def_file.splitlines() if " @ 4000 NONAME" in line)
message_symbol = next(name for name in definitions if name.startswith("?_messageEntries@?1??GetThisMessageMap@CMainFrame@@"))
start, section = definitions[message_symbol]
table = sections[section]
assert table[3] - start == 41 * 24
relocations = {}
for index in range(table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
    assert kind == 6
    relocations[offset - start] = symbols[symbol][0]
assert len(relocations) == 40
standard = {0x431bf0:"OnActivate", 0x431c40:"OnGetMinMaxInfo", 0x430360:"OnActivateApp",
            0x431d00:"OnCreate", 0x431f10:"OnClose", 0x6c4ce0:"OnPaint",
            0x430b40:"OnDestroy", 0x42ef10:"OnWindowPosChanging"}
entries = []
for index in range(41):
    offset = index * 24
    candidate = struct.unpack_from("<6I", obj, table[4] + start + offset)
    original = struct.unpack("<6I", pe.get_data(0x811630 + offset - base, 24))
    assert candidate[:5] == original[:5] and candidate[5] == 0, (index, candidate, original)
    if index == 40:
        assert not any(original)
        break
    expected = "?" + standard.get(original[5], "handle_%x" % original[5]) + "@CMainFrame@@"
    assert relocations[offset + 20].startswith(expected), (index, relocations[offset + 20], expected)
    entries.append(dict(index=index, original_handler=hex(original[5]), candidate_symbol=relocations[offset + 20]))
target, target_relocs, _ = match.target("2008-06", "004321c0")
_, body, relocs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith("?GetMessageMap@CMainFrame@@"))
assert match.exact_match(target, target_relocs, body, relocs)
paths = [source, ROOT / "rebuild/2008-06/native-headers/CMainFrame.h", ROOT / "rebuild/2008-06/native-headers/CMainFrameBases.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(), sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}, compiler_build=21022, flags=flags, entries=entries, scope="40 message records and handler symbols match; handlers and runtime linkage remain open; parent map import ordinal verified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: CMainFrame 40 message records match")
