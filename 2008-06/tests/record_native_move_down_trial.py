import json, struct, sys
from pathlib import Path
import pefile
main = Path(__file__).resolve().parents[3]
own = main / "rebuild/2008-06/out/native-layouts"
sys.path.insert(0, str(main))
from roc import match, rebuild
base = json.loads((main / "work/2008-06/shared-layouts/document-swap-current.json").read_text())
obj = own / "NativeSelectionCommandsMoveDownTrial.obj"
flags = [x for x in base["flags"] if not x.startswith("/Fo") and not x.endswith("NativeDocumentLayout.cpp")] + ["/Fo" + str(obj), str(main / "rebuild/2008-06/tests/NativeSelectionCommandsTrial.cpp")]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, own)
assert code == 0, log
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith("?doIt@MoveDownSelectionVerb@RBX@@"))
address = 0x581750
target, targetrefs, _ = match.target("2008-06", "%08x" % address)
assert len(body) == 310 and match.exact_match(target, targetrefs, body, refs)
start, index = definitions[name]
section = sections[index]
edges = {}
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from("<IIH", raw, section[5] + 10 * i)
    offset -= start
    if not 0 <= offset < len(body) - 3: continue
    value = struct.unpack_from("<I", target, offset)[0]
    if kind == 20: value = (address + offset + 4 + struct.unpack_from("<i", target, offset)[0]) & 0xffffffff
    edges[symbols[symbol][0]] = value
expected = {"__ehhandler$?doIt@MoveDownSelectionVerb@": 0x7d10f8, "?checkRunPermissions@": 0x57d250, "??$create@V?$FilteredSelection@": 0x5805d0, "??0MegaDragger@": 0x60e540, "?startDragging@": 0x60de00, "__real@bf99999a": 0x830b6c, "?safeMoveNoDrop@": 0x60e180, "?finishDragging@": 0x60e780, "??$create@VSoundService@": 0x4531e0, "?playSound@": 0x5bd820, "?raise@?$Notifier@VWorkspace@": 0x576940, "?recordCameraHistory@": 0x58c5c0, "??1MegaDragger@": 0x60e700}
assert len(edges) == len(expected), edges
for prefix, value in expected.items():
    found = [v for k,v in edges.items() if k.startswith(prefix)]
    assert found == [value], (prefix, found)
pe = pefile.PE(str(main / "work/2008-06/original-p4-reference/Roblox.exe"))
base = pe.OPTIONAL_HEADER.ImageBase
assert pe.get_data(0x830b6c - base, 4) == bytes.fromhex("9a9999bf")
assert struct.unpack("<I", pe.get_data(0x830890 + 4 * 4 - base, 4))[0] == address
assert pe.get_data(0x7d10f0-base, 4) == bytes.fromhex("8d4dc8e9")
assert 0x7d10f8 + struct.unpack("<i", pe.get_data(0x7d10f4-base,4))[0] == 0x60e700
assert pe.get_data(0x7d10f8-base,1) == b"\xb8"
assert struct.unpack("<I",pe.get_data(0x7d10f9-base,4))[0] == 0x8ed5a8
assert pe.get_data(0x7d10fd-base,1) == b"\xe9"
section = sections[definitions["__unwindtable$" + name][1]]
eh = raw[section[4]:section[4]+section[3]]
assert len(eh) == 44
actual = pe.get_data(0x8ed5a0-base,44)
assert match.masked(eh, [4,16]) == match.masked(actual, [4,16])
assert struct.unpack_from("<I", actual, 4)[0] == 0x7d10f0
assert struct.unpack_from("<I", actual, 16)[0] == 0x8ed5a0
assert match.data_check("2008-06", "00581750", target, match.coff_data_refs(raw, name)) == ([(0x830b6c, 4)], [])
print(json.dumps({"address": hex(address), "size": len(body), "code_exact": True, "edges": edges, "constant": "9a9999bf", "vtable_slot": "0x8308a0", "eh_handler": "0x7d10f8", "eh_contents_verified": True}, indent=2))

(main / "work/2008-06/shared-layouts/move-down-trial.json").write_text(json.dumps({"scope":"Diagnostic method; full ABI/runtime unproven.", "address":hex(address), "size":len(body), "edges":edges, "eh_contents_verified":True, "eh_runtime_target_verified":False},indent=2)+"\n")
