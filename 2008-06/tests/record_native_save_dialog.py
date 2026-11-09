"""Verify native save dialog lifecycle and URL-base constructor."""
import hashlib,json,pathlib,sys,struct,pefile
r=pathlib.Path(__file__).resolve().parents[3];sys.path.insert(0,str(r));from roc import rebuild,match
out=r/'rebuild/2008-06/out/native-layouts';d=json.loads((r/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in d['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];src=r/'rebuild/2008-06/native-classes/CSaveToRobloxDialog.cpp';fixture=r/'rebuild/2008-06/tests/NativeSaveDialogLayout.cpp';obj=out/'NativeSaveDialog.obj'
for source,target in [(src,obj),(fixture,out/'NativeSaveDialogLayout.obj')]:
 c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(target),str(source)],out);assert c==0,log
rows=[]
for path,addr,prefix in [(obj,'0045fe80','??0CSaveToRobloxDialog@@'),(obj,'0045fe20','??1CSaveToRobloxDialog@@'),(out/'NativeDHtmlDialog.obj','0044eeb0','??0CRobloxDHtmlDialog@@QAE@IPBD')]:
 raw=path.read_bytes();n,b,refs=next(x for x in match.coff_functions(raw) if x[0].startswith(prefix));t,tr,_=match.target('2008-06',addr);assert match.exact_match(t,tr,b,refs),(addr,len(b),len(t));sec,sy,defs,_=match._coff_data_index(raw);start,idx=defs[n];tab=sec[idx];calls={}
 for i in range(tab[7]):
  off,si,k=struct.unpack_from('<IIH',raw,tab[5]+i*10);off-=start
  if 0<=off<=len(b)-4 and k==20:calls[sy[si][0]]=hex((int(addr,16)+off+4+struct.unpack_from('<i',t,off)[0])&0xffffffff)
 rows.append(dict(address=addr,size=len(b),symbol=n,direct_calls=calls))
assert '0x44eeb0' in rows[0]['direct_calls'].values();assert '0x401050' in rows[1]['direct_calls'].values()
pe=pefile.PE(str(r/'work/2008-06/original-p4-reference/Roblox.exe'));imp=next(x for d in pe.DIRECTORY_ENTRY_IMPORT for x in d.imports if x.address==0x803670);assert imp.ordinal==6275
pre=out/'save-dialog-pre';pre.mkdir(exist_ok=True)
pre_flags=[x for x in flags if x!='/c']+['/P',str(src)]
c,log=rebuild.run(rebuild.toolchain(21022),'cl',pre_flags,pre);assert c==0,log
body=(pre/'CSaveToRobloxDialog.i').read_text(errors='replace')
needle='operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'
assert body.count(needle)==1
unit=out/'NativeSaveDialogProfile.cpp';unit.write_text(body.replace(needle,'__declspec(noinline) '+needle))
profile_obj=out/'NativeSaveDialogProfile.obj'
c,log=rebuild.run(rebuild.toolchain(21022),'cl',['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(profile_obj),str(unit)],out);assert c==0,log
for addr,prefix in [('0044f500','??0CPublishAsPlaceDialog@@'),('0044f660','??0CSaveModelToRobloxDialog@@')]:
 n,b,refs=next(x for x in match.coff_functions(profile_obj.read_bytes()) if x[0].startswith(prefix));t,tr,_=match.target('2008-06',addr);assert match.exact_match(t,tr,b,refs),(addr,len(b),len(t));rows.append(dict(address=addr,size=len(b),symbol=n,profile='CString conversion noinline'))
# Bind derived constructor calls, original URL literal and both vtables.
profile_raw=profile_obj.read_bytes();psec,psy,pdefs,_=match._coff_data_index(profile_raw)
for addr,cls,literal,primary,sink in [('0044f500','CPublishAsPlaceDialog',b'/IDE/Upload.aspx',0x81737c,0x817350),('0044f660','CSaveModelToRobloxDialog',b'/UI/Save.aspx?type=Model',0x81777c,0x817750)]:
 name=next(n for n in pdefs if n.startswith('??0'+cls+'@@'));start,section=pdefs[name];tab=psec[section];target,_,_=match.target('2008-06',addr);edges={}
 for j in range(tab[7]):
  offset,si,kind=struct.unpack_from('<IIH',profile_raw,tab[5]+j*10);offset-=start
  if 0<=offset<len(target)-3:
   sym=psy[si][0];value=struct.unpack_from('<I',target,offset)[0]
   if kind==20:value=(int(addr,16)+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
   edges[sym]=value
 assert any(n.startswith('?applicationBaseUrl@@') and v==0x4060d0 for n,v in edges.items())
 assert any(n.startswith('??0CSaveToRobloxDialog@@') and v==0x45fe80 for n,v in edges.items())
 assert any(n.startswith('??HATL@@') and v==0x40e160 for n,v in edges.items())
 assert any(n.startswith('??_7'+cls+'@@6BCDialog') and v==primary for n,v in edges.items())
 assert any(n.startswith('??_7'+cls+'@@6BCDHtmlEventSink') and v==sink for n,v in edges.items())
 assert any(n.startswith('??_C@') and pe.get_string_at_rva(v-pe.OPTIONAL_HEADER.ImageBase)==literal for n,v in edges.items())
for addr,prefix in [('004012c0','?GetMessageMap@CSaveToRobloxDialog'),('0045fe70','?GetEventSinkMap@CSaveToRobloxDialog'),('0045fe40','?GetDHtmlEventMap@CSaveToRobloxDialog'),('0045ff20','?WindowClosing@CSaveToRobloxDialog')]:
 n,b,refs=next(x for x in match.coff_functions(profile_obj.read_bytes()) if x[0].startswith(prefix));t,tr,_=match.target('2008-06',addr);assert match.exact_match(t,tr,b,refs),(addr,len(b),len(t));rows.append(dict(address=addr,size=len(b),symbol=n,profile='CString conversion noinline'))
raw=profile_obj.read_bytes();sections,symbols,definitions,_=match._coff_data_index(raw)
for suffix,count,addresses,allowed in [('CDialog@@@',111,[0x81a564,0x81737c,0x81777c],[1]),('CDHtmlEventSink@@@',10,[0x81a538,0x817350,0x817750],[])]:
 tables=[]
 for cls in ['CSaveToRobloxDialog','CPublishAsPlaceDialog','CSaveModelToRobloxDialog']:
  name=next(n for n in definitions if n.startswith('??_7'+cls+'@@6B') and n.endswith(suffix));start,section=definitions[name];table=sections[section];assert table[3]-start==count*4;slots={}
  for i in range(table[7]):
   off,si,kind=struct.unpack_from('<IIH',raw,table[5]+i*10)
   if start<=off<start+count*4:slots[(off-start)//4]=symbols[si][0]
  assert len(slots)==count;tables.append(slots)
 original=[struct.unpack('<%dI'%count,pe.get_data(a-pe.OPTIONAL_HEADER.ImageBase,count*4)) for a in addresses]
 for i in (1,2):
  assert [j for j in range(count) if original[0][j]!=original[i][j]]==allowed
  assert [j for j in range(count) if tables[0][j]!=tables[i][j]]==allowed
 if suffix=='CDialog@@@':
  assert tables[0][12].startswith('?GetMessageMap@CSaveToRobloxDialog')
  assert tables[0][17].startswith('?GetEventSinkMap@CSaveToRobloxDialog')
 else: assert tables[0][7].startswith('?GetDHtmlEventMap@CSaveToRobloxDialog')
entry_name='?_eventsinkEntries@CSaveToRobloxDialog@@0QBUAFX_EVENTSINKMAP_ENTRY@@B'
start,section=definitions[entry_name];table=sections[section];assert table[3]-start==80
entry_raw=raw[table[4]+start:table[4]+start+80];entry_refs={}
for i in range(table[7]):
 off,si,kind=struct.unpack_from('<IIH',raw,table[5]+i*10)
 if start<=off<start+80:entry_refs[off-start]=symbols[si][0]
original=pe.get_data(0x81a4d0-pe.OPTIONAL_HEADER.ImageBase,80)
for entry in range(2):
 for field in range(10):
  off=entry*40+field*4
  if off not in entry_refs:assert entry_raw[off:off+4]==original[off:off+4],(entry,field)
  elif field in (0,2):
   source=entry_refs[off];pos,ix=definitions[source];table=sections[ix];actual=raw[table[4]+pos:table[4]+table[3]];pointer=struct.unpack_from('<I',original,off)[0];expected=pe.get_string_at_rva(pointer-pe.OPTIONAL_HEADER.ImageBase)+b'\0';assert actual.startswith(expected)
  else:assert field==4 and entry_refs[off].startswith('?WindowClosing@CSaveToRobloxDialog')
paths=[pathlib.Path(__file__),src,fixture,r/'rebuild/2008-06/native-headers/CSaveToRobloxDialog.h',r/'rebuild/2008-06/native-headers/CRobloxDHtmlDialog.h',r/'rebuild/2008-06/native-classes/CRobloxDHtmlDialog.cpp'];sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();(r/'work/2008-06/shared-layouts/save-dialog-working.json').write_text(json.dumps(dict(sources={str(p.relative_to(r)):sha(p) for p in paths},object_sha256=sha(obj),methods=rows,layout_size='0x130',mfc_set_external_dispatch_ordinal=6275,scope='Inactive lifecycle, event methods and derived vtable comparison; event sink entry data verified; remaining bindings and runtime integration remain open.'),indent=2)+'\n');print('PASS: save dialog lifecycle, derived constructors and original bindings')
