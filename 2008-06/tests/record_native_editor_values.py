"""Verify recovered editor value operations; record unresolved bodies without credit."""
from concurrent.futures import ThreadPoolExecutor
import hashlib,json,struct,subprocess,sys,re
import pefile
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT))
from roc import match,rebuild
OUT=ROOT/'rebuild/2008-06/out/native-layouts'
HEADERS=ROOT/'rebuild/2008-06/native-headers'
flags=json.loads((ROOT/'work/2008-06/shared-layouts/property-grid-working-probe.json').read_text())['flags']
get_value='CString CXTPPropertyGridItem::GetValue() const'
empty='bool IsEmpty() const throw()\n\t{\n\t\treturn( GetLength() == 0 );'
conversion='operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'
jobs=(('Virtuals',Path(__file__).with_name('NativePropertyEditorConstructors.cpp'),('const _Elem * c_str() const',get_value,empty)),
      ('Numbers',ROOT/'rebuild/2008-06/native-classes/PropertyGridNumericValues.cpp',(get_value,conversion)))
def compile_job(job):
    name,source,profile=job
    pre=[f for f in flags if f!='/c']+['/P',str(source)]
    c,log=rebuild.run(rebuild.toolchain(21022),'cl',pre,OUT)
    assert c==0,log
    body=(OUT/(source.stem+'.i')).read_text(errors='replace')
    for needle in profile:
        assert body.count(needle)==1,needle
        body=body.replace(needle,'__declspec(noinline) '+needle)
    translation=OUT/('NativeEditor'+name+'Profile.cpp')
    translation.write_text(body)
    obj=OUT/('NativeEditor'+name+'.obj')
    cmd=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/Fo'+str(obj),str(translation)]
    c,log=rebuild.run(rebuild.toolchain(21022),'cl',cmd,OUT)
    assert c==0,log
    return name,dict(obj=obj,preprocess_flags=pre,compile_flags=cmd,profile=profile)
with ThreadPoolExecutor(max_workers=2) as pool:
    compiled=dict(pool.map(compile_job,jobs))
methods=[];unresolved=[];edges=[]
original=pefile.PE(str(ROOT/'work/2008-06/original-p4-reference/Roblox.exe'))
base=original.OPTIONAL_HEADER.ImageBase
imports={item.address:(dll.dll.lower(),item.name,item.ordinal) for dll in original.DIRECTORY_ENTRY_IMPORT for item in dll.imports}
mfc_def=ROOT/'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def'
exports={int(o):n for n,o in re.findall(r'^\s*(\S+)\s+@\s*(\d+)\s+NONAME',mfc_def.read_text(),re.M)}
bindings={'?GetValue@CXTPPropertyGridItem@@':0x437ed0,'?OnValueChanged@CXTPPropertyGridItem@@':0x711ac0,
          '?applyValue@?$XItem@M':0x43ee40,'?applyValue@?$XItem@H':0x43f1c0}
for address,prefix,unit,required in (
    ('0043b4c0','?equalValues@?$XItem@H','Virtuals',True),
    ('0043b4e0','?emptyValue@?$XItem@M','Virtuals',True),
    ('004413e0','?OnValueChanged@?$XItem@M','Virtuals',True),
    ('00441460','?OnValueChanged@?$XItem@H','Virtuals',True),
    ('00437880','?displayValue@?$XItem@M','Numbers',True),
    ('004378d0','?displayValue@?$XItem@H','Numbers',True),
    ('0043a700','?equalValues@?$XItem@M','Virtuals',False),
    ('004380c0','?readValue@?$XItem@M','Numbers',False),
    ('00438160','?readValue@?$XItem@H','Numbers',False),
):
    obj=compiled[unit]['obj'];raw=obj.read_bytes();functions=match.coff_functions(raw)
    symbol,body,refs=next((n,b,r) for n,b,r in functions if n.startswith(prefix))
    target,tr,_=match.target('2008-06',address)
    exact=match.exact_match(target,tr,body,refs)
    if required:assert exact,(address,symbol,len(body),len(target))
    row=dict(address=address,symbol=symbol,object=obj.name,size=len(body),target_size=len(target),relocation_masked_match=exact)
    (methods if exact else unresolved).append(row)
    if exact:
        sections,symbols,defs,_=match._coff_data_index(raw)
        start,section=defs[symbol];table=sections[section]
        for i in range(table[7]):
            offset,si,kind=struct.unpack_from('<IIH',raw,table[5]+i*10)
            offset-=start
            if not 0<=offset<=len(body)-4:continue
            name=symbols[si][0]
            for prefix,destination in bindings.items():
                if name.startswith(prefix):
                    assert kind==20
                    actual=(int(address,16)+offset+4+struct.unpack_from('<i',target,offset)[0])&0xffffffff
                    assert actual==destination,(address,name,hex(actual))
                    edges.append(dict(caller=address,offset=offset,symbol=name,target=hex(destination)))
            if name.startswith('__imp_'):
                dll,imported,ordinal=imports[struct.unpack_from('<I',target,offset)[0]]
                expected=name[len('__imp_'):]
                if dll==b'mfc90.dll':assert exports[ordinal]==expected,(address,expected,ordinal)
                elif imported is not None:
                    expected=expected[1:].split('@')[0] if expected.startswith('_') else expected
                    assert imported.decode()==expected,(address,expected,imported)
            if address in ('00437880','004378d0') and name.startswith('??_C@'):
                literal=original.get_string_at_rva(struct.unpack_from('<I',target,offset)[0]-base)
                assert literal==(b'%.3g' if address=='00437880' else b'%d')

# Correct full editor ABI: SDK57 primary slots plus five native operations.
raw=compiled['Virtuals']['obj'].read_bytes();sections,symbols,defs,_=match._coff_data_index(raw)
vt=next(n for n in defs if n.startswith('??_7?$XItem@M') and n.endswith('6BCCmdTarget@@@'))
start,section=defs[vt];table=sections[section]
assert table[3]-start==62*4
expected={25:'?OnValueChanged@?$XItem@M',57:'?readValue@?$XItem@M',58:'?displayValue@?$XItem@M',
          59:'?equalValues@?$XItem@M',60:'?writeValue@?$XItem@M',61:'?emptyValue@?$XItem@M'}
virtuals={}
for i in range(table[7]):
    off,si,kind=struct.unpack_from('<IIH',raw,table[5]+i*10)
    if start<=off<start+62*4:virtuals[(off-start)//4]=symbols[si][0]
for slot,prefix in expected.items():assert virtuals[slot].startswith(prefix),(slot,virtuals[slot])
original_slots={25:0x4413e0,57:0x4380c0,58:0x437880,59:0x43a700,60:0x43a7d0,61:0x43b4e0}
for slot,address in original_slots.items():assert struct.unpack('<I',original.get_data(0x813984+slot*4-base,4))[0]==address
paths=[Path(__file__),mfc_def,HEADERS/'PropertyGridItems.h',HEADERS/'CPropGrid.h',HEADERS/'SelectionGroup.h']
paths+=[source for _,source,_ in jobs]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
receipt=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
             sources={str(p.relative_to(ROOT)):sha(p) for p in paths},compiler=21022,methods=methods,unresolved=unresolved,verified_bindings=edges,original_float_virtual_slots=original_slots,
             primary_virtual_slots=62,selected_virtuals={str(i):virtuals[i] for i in expected},
             compilations={n:dict(object_sha256=sha(j['obj']),preprocess_flags=j['preprocess_flags'],compile_flags=j['compile_flags'],profile=j['profile']) for n,j in compiled.items()},
             scope='Inactive value-operation recovery. Exact source bodies only; float equality and numeric parsers retain zero credit when nonexact. '
                   'Read/display/equality/write/empty slots57-61 and SDK OnValueChanged slot25 established. Full update/write/apply behavior, '
                   'remaining virtual bindings, factory and runtime remain open; no game integration credit.')
(ROOT/'work/2008-06/shared-layouts/editor-values-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n')
print('PASS: %d exact editor value bodies; %d unresolved with zero credit; 62-slot primary ABI'%(len(methods),len(unresolved)))
