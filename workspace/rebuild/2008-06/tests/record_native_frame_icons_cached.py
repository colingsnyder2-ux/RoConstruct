"""Verify recovered icon unit from its existing preprocessed cache."""
import hashlib, json, struct, subprocess, sys
from pathlib import Path
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild
source = ROOT / "tools/libs/xtp-11.2.2/roc_claudeM_55bb15a72a4fb4db.cpp"
cache = ROOT / "work/libcache/xtp-11.2.2-lib-imports/21022/roc_claudeM_55bb15a72a4fb4db.cpp.i"
deps = cache.with_suffix(".i.deps")
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
dep = json.loads(deps.read_text(encoding="utf8"))
key = next(k for k in dep["files"] if k.lower().endswith("roc_claudem_55bb15a72a4fb4db.cpp"))
assert sha(source) == dep["files"][key][2]
assert any("nativeatlimagewidthdecl2e5804ac680a6dd9.cpp" in k.lower() for k in dep["files"])
out = ROOT / "rebuild/2008-06/out/native-layouts"
out.mkdir(parents=True, exist_ok=True)
translation = out / "NativeFrameIconsCached.cpp"
translation.write_bytes(cache.read_bytes())
flags = ["/nologo", "/c", "/O2", "/GS-", "/EHsc", "/MD", "/arch:SSE2", "/FoNativeFrameIconsCached.obj", str(translation)]
code, log = rebuild.run(rebuild.toolchain(21022), "cl", flags, out)
assert code == 0, log
obj = (out / "NativeFrameIconsCached.obj").read_bytes()
methods = []
for address,prefix in (("0042f490","?InitializeAllIcons@@"),("0042f380","?InitializeIcons@@"),("0042f290","?SetIcon@@"),("0042f0a0","?loadIcon@@")):
    target,tr,_ = match.target("2008-06", address)
    name,body,refs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith(prefix))
    assert match.exact_match(target,tr,body,refs),name
    methods.append(dict(address=address,symbol=name,size=len(body)))
sections,symbols,definitions,_ = match._coff_data_index(obj)
for address,sites in (("0042f490",((0x9,"?InitializeIcons@@",0x42f380),(0x18,"?RemoveIcon@CXTPImageManager@@",0x6bde60),(0x2d,"?SetIcon@@",0x42f290))),
                      ("0042f380",((0xf,"?RemoveIcon@CXTPImageManager@@",0x6bde60),(0x24,"?SetIcon@@",0x42f290))),
                      ("0042f290",((0x60,"?loadIcon@@",0x42f0a0),))):
    row=next(row for row in methods if row["address"]==address);start,section=definitions[row["symbol"]];table=sections[section];refs={}
    for i in range(table[7]):
        offset,sym,kind=struct.unpack_from("<IIH",obj,table[5]+i*10)
        if start<=offset<start+row["size"]:refs[offset-start]=symbols[sym][0]
    target,_,_=match.target("2008-06",address)
    calls={i.address-int(address,16)+1:int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(target,int(address,16)) if i.mnemonic=="call" and i.op_str.startswith("0x")}
    for offset,prefix,value in sites:assert refs[offset].startswith(prefix) and calls[offset]==value
paths=[source,cache,deps,Path(__file__)]
receipt=dict(revision=subprocess.check_output(["git","rev-parse","HEAD"],cwd=ROOT,text=True).strip(),sources={str(p.relative_to(ROOT)):sha(p) for p in paths},compiler_build=21022,flags=flags,methods=methods,scope="Cached preprocessed unit only; original alias source is missing, so fresh regeneration and runtime linkage remain unverified.")
output=ROOT/"work/2008-06"/sys.argv[1];output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(receipt,indent=2)+"\n")
print("PASS: cached native icon initializer and three helpers match")
