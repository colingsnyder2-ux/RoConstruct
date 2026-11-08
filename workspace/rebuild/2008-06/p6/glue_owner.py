"""Private archive rebuild preserving every unrelated native glue provider."""
from collections import Counter
from pathlib import Path
import hashlib,json,re,struct,sys,os,tempfile
from roc import clients,libs,match,rebuild

CACHE='?getCacheDirectory@FileSystem@RBX@@'

def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def sections(raw):
    tables,symbols,_,_=match._coff_data_index(raw); result=[]; seh=[]
    for table in tables:
        name=table[0].rstrip(b'\0').decode('latin-1');flags=table[9]
        if name=='.sxdata':
            seh.extend(symbols[i][0] for i in struct.unpack('<'+'I'*(table[3]//4),raw[table[4]:table[4]+table[3]]));continue
        if name.startswith(('.debug','.drectve','.text')) or flags & (0x20|0x1000):continue
        rel=[]
        for i in range(table[7]):
            off,sym,kind=struct.unpack_from('<IIH',raw,table[5]+i*10);rel.append((off,kind,symbols[sym][0]))
        result.append((name,flags,raw[table[4]:table[4]+table[3]] if table[4] else b'',tuple(sorted(rel))))
    return Counter(result),seh

def compare(original,replacement):
    norm=lambda s:re.sub(r'\?A0x[0-9a-fA-F]+','?ANON',s)
    def bodies(raw):
        result={}
        for n,body,relocs in match.coff_functions(raw):
            key=norm(n)
            if key in result:raise ValueError('ambiguous normalized provider: '+key)
            result[key]=(n,body,relocs)
        return result
    def refs(raw,name,size):
        tables,syms,defs,_=match._coff_data_index(raw);start,idx=defs[name];t=tables[idx];out=[]
        for i in range(t[7]):
            off,sym,kind=struct.unpack_from('<IIH',raw,t[5]+i*10);off-=start
            if 0<=off<size:out.append((off,kind,norm(syms[sym][0])))
        return sorted(out)
    a,b=bodies(original),bodies(replacement);removed=set(a)-set(b)
    if len(removed)!=1 or not next(iter(removed)).startswith(CACHE) or set(b)-set(a):raise ValueError('unexpected changed provider set')
    for key in b:
        x,y=a[key],b[key]
        if not match.exact_match(x[1],x[2],y[1],y[2]) or refs(original,x[0],len(x[1]))!=refs(replacement,y[0],len(y[1])) or match.coff_data_refs(original,x[0])!=match.coff_data_refs(replacement,y[0]):
            raise ValueError('retained function changed: '+key)
    if sections(original)!=sections(replacement):raise ValueError('non-COMDAT data or SEH changed')
    return len(b),next(iter(removed))

def verify_native(native_obj, names_path):
    raw = Path(native_obj).read_bytes()
    candidates = [(n, body, relocs) for n, body, relocs in match.coff_functions(raw) if n.startswith(CACHE)]
    if len(candidates) != 1:
        raise ValueError('native cache provider missing or ambiguous')
    name, body, relocs = candidates[0]
    names = json.loads(Path(names_path).read_text(encoding='utf-8'))
    addresses = [addr for addr, item in names.items() if item.get('symbol') == name]
    if len(addresses) != 1:
        raise ValueError('native cache original identity missing or ambiguous')
    target, refs, _ = match.target('2008-06', addresses[0])
    if not set(refs) <= set(relocs) or not match.exact_match(target, refs, body, relocs):
        raise ValueError('native cache code differs from original')
    _, errors = match.data_check('2008-06', addresses[0], target, match.coff_data_refs(raw, name))
    if errors:
        raise ValueError('native cache referenced data differs from original')
    return name, addresses[0]

def build(command_path,archive,source,native_obj,output,tc):
    command_path,archive,source,native_obj,output=map(Path,(command_path,archive,source,native_obj,output));cmd=json.loads(command_path.read_text());output.mkdir(parents=True,exist_ok=True);out=Path(tempfile.mkdtemp(prefix='glue-owner-',dir=output))
    if cmd.get('exit')!=0 or Path(cmd['compiler']).resolve()!=Path(tc['cl']).resolve():raise ValueError('compiler receipt mismatch')
    if any(not Path(p).is_file() for p in cmd['dependencies']):raise ValueError('recorded header missing')
    historical_drift=[p for p,h in cmd['dependencies'].items() if sha(p)!=h]
    inputs={p:sha(p) for p in cmd['dependencies']}
    inputs.update({str(archive):sha(archive),str(source):sha(source),str(native_obj):sha(native_obj),str(command_path):sha(command_path),str(tc['cl']):sha(tc['cl']),str(tc['lib']):sha(tc['lib'])})
    members=list(libs.archive_members(archive));old=[(n,b) for n,b in members if Path(n).name.lower()=='glue_content_provider.obj']
    if len(old)!=1:raise ValueError('expected one glue member')
    expected_obj=command_path.with_name('glue_content_provider.obj')
    if not expected_obj.is_file() or sha(expected_obj)!=hashlib.sha256(old[0][1]).hexdigest():raise ValueError('archive member not from recorded compile')
    inputs[str(expected_obj)]=sha(expected_obj)
    evidence_root=Path(match.ROOT)
    names_path=evidence_root/'rebuild/2008-06/out/native-names.json'
    functions_path=evidence_root/'work/2008-06/functions.jsonl'
    image=clients.exe_path('2008-06',clients.load()['2008-06'])
    for path in (names_path,functions_path,image):inputs[str(path)]=sha(path)
    native_name,native_address=verify_native(native_obj,names_path)
    args=[a for a in cmd['args'] if not a.lower().startswith('/fo') and not a.lower().endswith('.cpp')]
    obj=out/'glue_content_provider.obj';code,log=rebuild.run(tc,'cl',args+['/Fo'+str(obj),str(source)],out);(out/'compile.log').write_text(log,encoding='utf-8')
    if code:raise ValueError('glue compile failed')
    actual={os.path.normcase(str(Path(x.group(1)).resolve())) for line in log.splitlines() if (x:=re.match(r'\s*Note: including file:\s*(.*?)\s*$',line))}
    recorded={os.path.normcase(str(Path(p).resolve())) for p in cmd['dependencies']}
    if actual-recorded:raise ValueError('new include paths require fresh review: '+', '.join(sorted(actual-recorded)[:4]))
    retained,removed=compare(old[0][1],obj.read_bytes())
    if native_name!=removed:raise ValueError('native owner ABI symbol mismatch')
    clean=out/'without-glue.lib';final=out/'linked.lib'
    code,log=rebuild.run(tc,'lib',['/nologo','/remove:'+old[0][0],'/out:'+str(clean),str(archive)],out)
    if code:raise ValueError('archive removal failed: '+log[-500:])
    code,log=rebuild.run(tc,'lib',['/nologo','/out:'+str(final),str(clean),str(obj)],out)
    if code:raise ValueError('archive replacement failed: '+log[-500:])
    before=Counter((n,hashlib.sha256(b).hexdigest()) for n,b in members);after=Counter((n,hashlib.sha256(b).hexdigest()) for n,b in libs.archive_members(final));deleted=list((before-after).elements());added=list((after-before).elements())
    if len(deleted)!=1 or deleted[0][0]!=old[0][0] or len(added)!=1 or added[0][1]!=sha(obj):raise ValueError('unrelated archive member changed')
    if any(not Path(p).is_file() or sha(p)!=h for p,h in inputs.items()):raise ValueError('input drift during build')
    receipt={'inputs':inputs,'historical_header_drift':historical_drift,'archive_sha256':sha(final),'retained_functions':retained,'removed_owner':removed,'native_original_address':native_address,'other_members_unchanged':sum(before.values())-1,'scope':'archive ownership only; byte/data/calls/ABI/selection/runtime gates separate'};(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');return final
