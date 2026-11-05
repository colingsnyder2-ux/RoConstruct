"""Verify frame pane RTTI, primary vtables and deleting-destructor targets."""
import hashlib,json,struct,subprocess,sys
from pathlib import Path
import pefile
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT))
exe=ROOT/'work/2008-06/original-p4-reference/Roblox.exe';pe=pefile.PE(str(exe));base=pe.OPTIONAL_HEADER.ImageBase;data=pe.get_memory_mapped_image()
u32=lambda va:struct.unpack_from('<I',data,va-base)[0]
items=[('CSelectionCaption',0x81bbc4,0x466920,0x466510,['.?AVCXTCaption@@','.?AVCWnd@@']),('CDataModelPropGrid',0x811444,0x431140,0x4310f0,['.?AVCSelectionPropGrid@@','.?AVCPropGrid@@','.?AVCXTPPropertyGrid@@','.?AVCWnd@@']),('CXTSplitterWnd',0x85c064,0x708d30,0x708280,['.?AVCSplitterWnd@@','.?AVCWnd@@'])]
rows=[]
for name,vtable,wrapper,dtor,required in items:
 col=u32(vtable-4);assert u32(col)==0 and u32(col+4)==0
 td=u32(col+12);typename=pe.get_string_at_rva(td+8-base).decode('ascii');assert typename=='.?AV'+name+'@@'
 hierarchy=u32(col+16);count=u32(hierarchy+8);array=u32(hierarchy+12);bases=[]
 for i in range(count):
  desc=u32(array+4*i);t=u32(desc);tname=pe.get_string_at_rva(t+8-base).decode('ascii');bases.append(dict(name=tname,offset=u32(desc+8)))
 for expected in required:assert any(x['name']==expected and x['offset']==0 for x in bases),(name,expected)
 assert u32(vtable+4)==wrapper
 calls=[int(i.op_str,16) for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(pe.get_data(wrapper-base,0x1c),wrapper) if i.mnemonic=='call' and i.op_str.startswith('0x')]
 assert calls[:2]==[dtor,0x6a067a]
 rows.append(dict(name=name,vtable=hex(vtable),deleting_wrapper=hex(wrapper),destructor=hex(dtor),bases=bases))
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),original_sha256=sha(exe),observer_sha256=sha(Path(__file__)),panes=rows,scope='Original binary RTTI and primary deleting-destructor slots; complete native pane declarations, ownership templates and runtime remain unverified.')
(ROOT/'work/2008-06/shared-layouts/main-frame-pane-rtti-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('PASS: three native frame pane hierarchies and destructor targets')
