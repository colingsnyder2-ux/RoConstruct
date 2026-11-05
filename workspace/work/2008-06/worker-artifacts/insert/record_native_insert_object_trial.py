import sys,json
from pathlib import Path
root=Path(__file__).resolve().parents[3]; main=root.parent/'RoConstruct'; sys.path.insert(0,str(main))
from roc import match,rebuild
out=root/'rebuild/2008-06/out/insert-object'; out.mkdir(parents=True,exist_ok=True)
base=json.loads((main/'work/2008-06/shared-layouts/document-swap-current.json').read_text())
flags=[x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]
overlay=out/'overlay/v8tree'; overlay.mkdir(parents=True,exist_ok=True)
hdr=(main/'rebuild/2008-06/native-headers/v8tree/Service.h').read_text(); (overlay/'Service.h').write_text(hdr.replace('    static size_t newIndex();','    static Instance* create(Instance*, const Name&);\n    static size_t newIndex();'))
(overlay.parent/'StandardVerbs.h').write_text((main/'rebuild/2008-06/native-headers/StandardVerbs.h').read_text())
inst=(main/'rebuild/2008-06/native-headers/v8tree/Instance.h').read_text(); (overlay/'Instance.h').write_text(inst.replace('    Instance();','    bool canAddChild(const Instance*) const;\n    Instance();'))
selection=overlay.parent/'v8datamodel'; selection.mkdir(exist_ok=True); hdr=(main/'rebuild/2008-06/native-headers/v8datamodel/Selection.h').read_text(); (selection/'Selection.h').write_text(hdr.replace('    void clearSelection();','    void setSelection(Instance*);\n    void clearSelection();'))
flags.insert(0,'/I'+str(overlay.parent))
source=root/'rebuild/2008-06/tests/NativeInsertObjectTrial.cpp'; obj=out/'NativeInsertObjectTrial.obj'
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags+['/Fo'+str(obj),str(source)],out)
print(log); assert code==0
name,body,refs=next(x for x in match.coff_functions(obj.read_bytes()) if x[0].startswith('?doIt@InsertObject@@'))
target,targetrefs,_=match.target('2008-06','0041f680')
print(name,'body',len(body),'target',len(target),'exact',match.exact_match(target,targetrefs,body,refs))

