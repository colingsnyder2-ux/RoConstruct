"""Move UserInputBase lifetime ownership from the old player adapter to native source."""
from collections import Counter
import hashlib,json
from pathlib import Path
from roc import libs,match,rebuild
from captured_inputs import freeze
from script_context_owner import sha,references,data_symbols

def build(snapshot,output,tc,archive):
    folder=output/'user-input-owner';folder.mkdir(exist_ok=True)
    source,flags,inputs,recovered=freeze(snapshot/'P2RecoveredPlayer/layer-engine/PlayerNativeInput.command.json',snapshot/'P2RecoveredPlayer',snapshot,folder,overlay_root=snapshot/'P2RecoveredPlayer/overlay')
    manifest=Path(__file__).with_name('user_input_checks.json')
    policy=json.loads(manifest.read_text())
    native=output/'NativeUserInputBaseLifetimeFull.obj'
    for path in [archive,native,Path(__file__),manifest,Path(__file__).with_name('captured_inputs.py'),Path(__file__).with_name('script_context_owner.py'),tc['cl'],tc['lib']]:inputs[str(path)]=sha(path)
    signature=hashlib.sha256(json.dumps(inputs,sort_keys=True).encode()).hexdigest()
    target=folder/'linked.lib';receipt=folder/'receipt.json'
    if target.exists() and receipt.exists():
        saved=json.loads(receipt.read_text())
        if saved['signature']==signature and saved['archive_sha256']==sha(target):return target
    text=source.read_text()
    for declaration in ['UserInputBase::UserInputBase():currentCursor(NULL){}','UserInputBase::~UserInputBase(){}']:
        if text.count(declaration)!=1:raise RuntimeError('unexpected player lifetime source')
        text=text.replace(declaration,'')
    generated=folder/'PlayerNativeInput.cpp';generated.write_text(text)
    code,log=rebuild.run(tc,'cl',flags+['/FoPlayerNativeInput.obj',str(generated)],folder)
    (folder/'compile.log').write_text(log)
    if code:raise RuntimeError('player owner rebuild failed: '+log[-1200:])
    members=list(libs.archive_members(archive));old=next(raw for name,raw in members if name=='PlayerNativeInput.obj');new=(folder/'PlayerNativeInput.obj').read_bytes()
    a={n:(b,r) for n,b,r in match.coff_functions(old)};b={n:(b,r) for n,b,r in match.coff_functions(new)}
    if set(a)-set(b)!=set(policy['retired_functions']) or set(b)-set(a):raise RuntimeError('unexpected retired player bodies')
    ra,rb=references(old),references(new)
    if any(not match.exact_match(*a[n],*b[n]) or ra.get(n)!=rb.get(n) for n in b):raise RuntimeError('retained player body/relocations changed')
    da,db=data_symbols(old),data_symbols(new)
    if set(da)-set(db)!=set(policy['retired_data']) or set(db)-set(da) or any(da[n]!=db[n] for n in db):raise RuntimeError('retained player data changed')
    code,log=rebuild.run(tc,'lib',['/nologo','/OUT:'+str(target),str(archive),'PlayerNativeInput.obj'],folder)
    (folder/'librarian.log').write_text(log)
    if code:raise RuntimeError('player owner archive failed: '+log[-1200:])
    inventory=lambda rows:Counter((n,hashlib.sha256(r).hexdigest()) for n,r in rows)
    before,after=inventory(members),inventory(libs.archive_members(target))
    if list((before-after).elements())!=[('PlayerNativeInput.obj',hashlib.sha256(old).hexdigest())] or list((after-before).elements())!=[('PlayerNativeInput.obj',hashlib.sha256(new).hexdigest())]:raise RuntimeError('player archive changed another member')
    if any(sha(n)!=h for n,h in inputs.items()):raise RuntimeError('player owner inputs changed')
    receipt.write_text(json.dumps({'scope':__doc__+' Retained code/data and source ownership only; adapter/native game ABI and runtime remain unproven.','signature':signature,'inputs':inputs,'archive_sha256':sha(target),'retained_bodies':len(b),'retained_named_data':len(db),'unchanged_other_members':len(members)-1,'retired_functions':policy['retired_functions'],'retired_data':policy['retired_data'],'recovered_inputs':recovered},indent=2)+'\n')
    return target
