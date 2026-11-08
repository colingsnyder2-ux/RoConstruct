import hashlib,json,struct,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts';base=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')];obj=out/'NativeMotorFeatureTrial.obj';code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(root/'rebuild/2008-06/experiments/trials/NativeMotorFeatureTrial.cpp')],out);assert code==0,log
raw=obj.read_bytes();name,body,refs=next(x for x in match.coff_functions(raw) if x[0].startswith('?canJoin@MotorFeature@'));target,targetrefs,_=match.target('2008-06','00609a60');assert match.exact_match(target,targetrefs,body,refs);sections,symbols,defs,_=match._coff_data_index(raw);start,sec=defs[name];table=sections[sec];bindings={}
for i in range(table[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+10*i);off-=start
 if not 0<=off<len(body)-3:continue
 value=struct.unpack_from('<I',target,off)[0]
 if kind==20:value=(0x609a60+off+4+struct.unpack_from('<i',target,off)[0])&0xffffffff
 bindings[symbols[sym][0]]=value
assert any('__RTDynamicCast' in k and v==0x6a17c6 for k,v in bindings.items()),bindings
assert bindings['??_R0?AVHole@RBX@@@8']==0x959a28 and bindings['??_R0?AVMotorFeature@RBX@@@8']==0x959a08 and bindings['??_R0?AVInstance@RBX@@@8']==0x92907c,bindings
name2,body2,refs2=next(x for x in match.coff_functions(raw) if x[0].startswith('?join@MotorFeature@'));target2,targetrefs2,_=match.target('2008-06','0060ca00');assert match.exact_match(target2,targetrefs2,body2,refs2);start2,sec2=defs[name2];table2=sections[sec2];bindings2={}
for i in range(table2[7]):
 off,sym,kind=struct.unpack_from('<IIH',raw,table2[5]+10*i);off-=start2
 if not 0<=off<len(body2)-3:continue
 value=struct.unpack_from('<I',target2,off)[0]
 if kind==20:value=(0x60ca00+off+4+struct.unpack_from('<i',target2,off)[0])&0xffffffff
 bindings2[symbols[sym][0]]=value
for token,value in [('?canJoin@MotorFeature@',0x609a60),('?setHole@VelocityMotor@',0x60c400),('?setParent@Instance@',0x55a8f0)]:assert any(k.startswith(token) and v==value for k,v in bindings2.items()),(token,bindings2)
assert any('create@VVelocityMotor@RBX@@' in k and v==0x5804a0 for k,v in bindings2.items()),bindings2
assert bindings2['??_R0?AVHole@RBX@@@8']==0x959a28 and bindings2['??_R0?AVInstance@RBX@@@8']==0x92907c
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();src=root/'rebuild/2008-06/experiments/trials/NativeMotorFeatureTrial.cpp';receipt={'scope':'canJoin matches. Hole and MotorFeature inheritance in this isolated diagnostic is incomplete and cannot be used at runtime.','address':'0x609a60','size':len(body),'symbol':name,'bindings':{k:hex(v) for k,v in bindings.items()},'join':{'address':'0x60ca00','size':len(body2),'symbol':name2,'bindings':{k:hex(v) for k,v in bindings2.items()}},'source_sha256':sha(src),'object_sha256':sha(obj),'observer_sha256':sha(Path(__file__))};(root/'work/2008-06/shared-layouts/motor-feature-trial.json').write_text(json.dumps(receipt,indent=2)+'\n');print('PASS MotorFeature::canJoin and RTTI bindings')
