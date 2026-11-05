"""Compile and verify inactive native ChatEnter layout."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import struct
import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
source = ROOT / "rebuild/2008-06/tests/NativeChatEnterLayout.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DNOMINMAX", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/FoNativeChatEnterLayout.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeChatEnterLayout.obj").read_bytes()
results = []
for address, prefix in (("00411720", "??0ChatEnter@@"),
                        ("004117c0", "?askAddChild@GuiItem@RBX@@"),
                        ("004117f0", "?getPosition@GuiItem@RBX@@"),
                        ("00411810", "?getChildPosition@GuiItem@RBX@@"),
                        ("00411830", "?getFontSize@GuiItem@RBX@@"),
                        ("00411840", "?getTitle@GuiItem@RBX@@"),
                        ("00411870", "?getSize@GuiItem@RBX@@"),
                        ("0060a2f0", "?canLoseFocus@GuiItem@RBX@@"),
                        ("00565950", "?isVisible@GuiItem@RBX@@"),
                        ("0070bdf0", "?render2d@GuiItem@RBX@@")):
    target, target_relocations, _ = match.target("2008-06", address)
    name, body, relocations = next((name, body, relocs) for name, body, relocs in match.coff_functions(obj)
                                   if name.startswith(prefix))
    assert match.exact_match(target, target_relocations, body, relocations), name
    results.append(dict(address=address, symbol=name, size=len(body), relocation_normalized_exact=True))
# Constructor-byte equality alone masks the vtable relocation. Compare the
# primary slot before claiming this class is safe to link.
original = ROOT / "work/2008-06/original-p4-reference/Roblox.exe"
pe = pefile.PE(str(original), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
original_slot0 = struct.unpack("<I", pe.get_data(0x80e12c - base, 4))[0]
assert original_slot0 == 0x47d410 and pe.get_data(original_slot0 - base, 1) == b"\xc3"
sections, symbols, definitions, _ = match._coff_data_index(obj)
vtable = next(name for name in definitions if name.startswith("??_7ChatEnter@@6B?$GuidItem@"))
start, section = definitions[vtable]
table = sections[section]
candidate_slot0 = None
for index in range(table[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", obj, table[5] + 10 * index)
    if offset == start:
        candidate_slot0 = symbols[symbol][0]
assert candidate_slot0 and candidate_slot0.startswith("?onGuidChanged@?$GuidItem@VInstance@RBX@@")
slot_name, slot_body, slot_relocs = next((name, body, refs) for name, body, refs in match.coff_functions(obj)
                                          if name == candidate_slot0)
assert slot_body == b"\xc3" and not slot_relocs
primary_vtable = dict(original_slot0=hex(original_slot0), original_body="ret", candidate_slot0=candidate_slot0,
                      compatible=True, source="roc_instance_guid_callback_5e8a3f385d045a38.cpp")
paths = [source, ROOT / "rebuild/2008-06/native-headers/ChatEnter.h", ROOT / "rebuild/2008-06/native-headers/gui/Gui.h", ROOT / "rebuild/2008-06/native-headers/util/GuidItem.h", ROOT / "tools/rbxgs/Client/Network/roc_instance_guid_callback_5e8a3f385d045a38.cpp", ROOT / "rebuild/2008-06/native-classes/ChatEnter.cpp", ROOT / "rebuild/2008-06/native-headers/v8tree/Instance.h", Path(__file__)]
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip(),
               sources={str(p.relative_to(ROOT)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, compile_exit=code, original_sha256=hashlib.sha256(original.read_bytes()).hexdigest(), primary_vtable=primary_vtable, methods=results,
               scope="Inactive candidate using donor GuiItem; primary slot 0 now matches original onGuidChanged no-op; remaining virtual slots and full lifetime remain unverified.")
output = ROOT / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: ChatEnter layout, constructor and nine GuiItem bodies match")
