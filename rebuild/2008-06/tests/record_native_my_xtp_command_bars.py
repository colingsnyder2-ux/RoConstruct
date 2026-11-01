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
source = ROOT / "rebuild/2008-06/tests/../native-classes/MyXTPCommandBars.cpp"
recipe = libs.RECIPES["rbxgs"]
flags = ["/nologo", "/c", "/O2", "/Ob2", "/Oy", "/GF", "/GS-", "/EHsc", "/MD",
         "/D_AFXDLL", "/DNDEBUG", "/D_MBCS", "/DBOOST_ALL_NO_LIB"]
flags += ["/D" + value for value in recipe["defines"].split()]
flags += ["/I" + str(ROOT / "rebuild/2008-06/native-headers"),
          "/I" + str(ROOT / "tools/libs/mfc-9.0-rtm/atlmfc/include")]
flags += ["/I" + str((libs.LIBS / value).resolve()) for value in recipe["include"] if value != "WINSDK"]
flags += ["/D_XTP_STATICLINK", "/D_XTPLIB_NOAUTOLINK", "/I" + str(ROOT / "tools/libs/xtp-11.2.2/Source")]
flags += ["/FoNativeMyXTPCommandBars.obj", str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeMyXTPCommandBars.obj").read_bytes()





import pefile
pe=pefile.PE(str(ROOT/"work/2008-06/original-p4-reference/Roblox.exe"),fast_load=True); base=pe.OPTIONAL_HEADER.ImageBase
methods=[]
for address,prefix in (("0042e470","?AddCustomBar@MyXTPCommandBars@@"),("0042f950","?CreateObject@MyXTPCommandBars@@"),("0042e4b0","?GetRuntimeClass@MyXTPCommandBars@@"),("0042e4a0","?_GetBaseClass@MyXTPCommandBars@@")):
    target,tr,_=match.target("2008-06",address); name,body,relocs=next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith(prefix))
    assert match.exact_match(target,tr,body,relocs); methods.append(dict(address=address,symbol=name,size=len(body)))
sections,symbols,definitions,_=match._coff_data_index(obj)
override = next(row for row in methods if row["address"] == "0042e470")
start,section=definitions[override["symbol"]];table=sections[section];refs={}
for i in range(table[7]):
    offset,sym,kind=struct.unpack_from("<IIH",obj,table[5]+i*10)
    if start<=offset<start+override["size"]:refs[offset-start]=symbols[sym][0]
original,_,_=match.target("2008-06","0042e470")
calls={i.address-0x42e470+1:int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(original,0x42e470) if i.mnemonic=="call" and i.op_str.startswith("0x")}
assert refs[0x12].startswith("?AddCustomBar@CXTPCommandBars@@") and calls[0x12]==0x6a3ee0
assert refs[0x25].startswith("?EnableDocking@CXTPToolBar@@") and calls[0x25]==0x6c1ea0
name=next(n for n in definitions if n.startswith("?classMyXTPCommandBars@MyXTPCommandBars@@"));start,section=definitions[name];table=sections[section]
fields=struct.unpack_from("<6I",obj,table[4]+start); native=struct.unpack("<6I",pe.get_data(0x8107c4-base,24))
assert fields[1:3]==native[1:3]==(0xcc,0xffff) and fields[5]==native[5]==0
refs={}
for i in range(table[7]):
    offset,sym,kind=struct.unpack_from("<IIH",obj,table[5]+i*10)
    if start<=offset<start+24: refs[offset-start]=symbols[sym][0]
assert refs[0].startswith("??_C@") and refs[12].startswith("?CreateObject@MyXTPCommandBars@@") and refs[16].startswith("?_GetBaseClass@MyXTPCommandBars@@")
assert pe.get_string_at_rva(native[0]-base)==b"MyXTPCommandBars" and native[3]==0x42f950 and native[4]==0x42e4a0
original_vtable=struct.unpack("<38I",pe.get_data(0x810804-base,152));assert original_vtable[0]==0x42e4b0
vtable=next(n for n in definitions if n.startswith("??_7MyXTPCommandBars@@"));vstart,vsection=definitions[vtable];vt=sections[vsection];slots={}
for i in range(vt[7]):
    offset,sym,kind=struct.unpack_from("<IIH",obj,vt[5]+i*10)
    if vstart<=offset<vstart+152:slots[(offset-vstart)//4]=symbols[sym][0]
assert len(slots)==38 and slots[0].startswith("?GetRuntimeClass@MyXTPCommandBars@@")
assert slots[33].startswith("?AddCustomBar@MyXTPCommandBars@@") and original_vtable[33]==0x42e470
# MFC vtable entries 5-21 are original import thunks; verify ordinal and decorated target.
pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
imports={entry.address:(dll.dll.lower(),entry.ordinal) for dll in pe.DIRECTORY_ENTRY_IMPORT for entry in dll.imports}
exports=(ROOT/"tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def").read_text(errors="replace").splitlines()
mfc_slots=[]
for index in range(5,22):
    thunk=original_vtable[index]; insn=pe.get_data(thunk-base,6)
    assert insn[:2]==b"\xff\x25"
    pointer=struct.unpack_from("<I",insn,2)[0]; dll,ordinal=imports[pointer]
    assert dll==b"mfc90.dll"
    export=next(line.strip().split()[0] for line in exports if " @ %d NONAME" % ordinal in line)
    assert export==slots[index],(index,export,slots[index])
    mfc_slots.append(dict(slot=index,ordinal=ordinal,symbol=export))
assert pe.get_data(original_vtable[2]-base,3)==b"\xc2\x04\x00"
assert pe.get_data(original_vtable[3]-base,1)==b"\xc3"
assert original_vtable[4]==original_vtable[2]
for index,method in ((2,"Serialize"),(3,"AssertValid"),(4,"Dump")):
    assert slots[index].startswith("?"+method+"@CObject@@")
scalar_target,scalar_tr,_=match.target("2008-06","0042f9b0")
_,scalar_body,scalar_refs=next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith("??_GMyXTPCommandBars@@"))
assert match.exact_match(scalar_target,scalar_tr,scalar_body,scalar_refs)
assert original_vtable[1]==0x42f9b0 and slots[1].startswith("??_EMyXTPCommandBars@@")
# Compare inherited XTP slots against the original functions, including folded code.
xtp_paths=[ROOT/"rebuild/2008-06/out/XTP/linked/XTPCommandBars.obj", ROOT/"rebuild/2008-06/out/XTP/linked/XTPDockState.obj"]
xtp_functions={}
for path in xtp_paths:
    for symbol,body,relocs in match.coff_functions(path.read_bytes()): xtp_functions[symbol]=(body,relocs)
inherited=[]
for index in list(range(22,33))+list(range(34,38)):
    target,tr,_=match.target("2008-06", "%08x" % original_vtable[index])
    body,relocs=xtp_functions[slots[index]]
    assert match.exact_match(target,tr,body,relocs), (index,slots[index])
    inherited.append(dict(slot=index,address=hex(original_vtable[index]),symbol=slots[index],size=len(body)))
paths=[source,*xtp_paths,ROOT/"rebuild/2008-06/native-headers/MyXTPCommandBars.h",Path(__file__)]
receipt=dict(revision=subprocess.check_output(["git","rev-parse","HEAD"],cwd=ROOT,text=True).strip(),sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},compiler_build=21022,flags=flags,methods=methods,runtime_size=204,vtable_slots=len(slots),inherited_slots=inherited,mfc_slots=mfc_slots,scalar_destructor_size=len(scalar_body),scope="Metadata shape, native override and selected methods verified; no-op function linkage, scalar/vector destructor folding and remaining relocations, runtime data/linkage and gates open.")
output=ROOT/"work/2008-06"/sys.argv[1];output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(receipt,indent=2)+"\n")
print("PASS: MyXTPCommandBars metadata and four methods match")
