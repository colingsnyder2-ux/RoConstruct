import json,sys,struct,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[4];sys.path.insert(0,str(root));from roc import match,rebuild
out=root/'rebuild/2008-06/out/native-layouts/writer-copyinit-worker';(out/'v8xml').mkdir(parents=True,exist_ok=True);(out/'v8xml/XmlSerializer.h').write_text((root/'rebuild/2008-06/out/native-layouts/write-worker/v8xml/XmlSerializer.h').read_text());orig=(root/'rebuild/2008-06/tests/NativeWorkspaceWriterNearWorker.cpp').read_text();needle='    TextXmlWriterWithEmbeddedContent writer(dataModel ? RBX::ServiceProvider::create<RBX::ContentProvider>(dataModel.get()) : 0, stream);';assert orig.count(needle)==1
expr='dataModel ? RBX::ServiceProvider::create<RBX::ContentProvider>(dataModel.get()) : 0'; variants=[('copyinit','    TextXmlWriterWithEmbeddedContent writer = TextXmlWriterWithEmbeddedContent('+expr+', stream);'),('constref','    const TextXmlWriterWithEmbeddedContent& writer = TextXmlWriterWithEmbeddedContent('+expr+', stream);'),('scope','    { TextXmlWriterWithEmbeddedContent writer('+expr+', stream);\n    writer.serialize(element); }\n    return S_OK;'),('provider_mut','    RBX::ContentProvider* provider = '+expr+';\n    TextXmlWriterWithEmbeddedContent writer(provider, stream);')]
prior=json.loads((root/'work/2008-06/shared-layouts/document-swap-current.json').read_text());flags=[x for x in prior['flags'] if not x.startswith('/Fo') and not x.lower().endswith('.cpp')];flags[:0]=['/I'+str(out),'/I'+str(root/'rebuild/2008-06/tests')];t,tr,_=match.target('2008-06','0046b860');rows=[]
for name,body in variants:
 s=orig.replace(needle,body)
 if name=='scope':s=s.replace('    writer.serialize(element);\n    return S_OK;\n}', '}')
 src=out/(name+'.cpp');src.write_text(s);obj=out/(name+'.obj');c,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(src)],out);row={'name':name,'exit':c}
 if c:row['error']=log[-350:]
 else:
  raw=obj.read_bytes();sym,b,r=next(x for x in match.coff_functions(raw) if x[0].startswith('?write@CWorkspace@@'));row.update(size=len(b),exact=match.exact_match(t,tr,b,r));secs,syms,defs,_=match._coff_data_index(raw);start,idx=defs['__unwindtable$'+sym];sec=secs[idx];row['eh_states']=struct.unpack_from('<I',raw,sec[4]+start+12)[0]
 rows.append(row);print(row,flush=True)
(root/'work/2008-06/shared-layouts/writer-copyinit-worker.json').write_text(json.dumps({'scope':'Isolated natural writer lifetime syntax; not runtime proof.','variants':rows,'observer_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest()},indent=2)+'\n')
