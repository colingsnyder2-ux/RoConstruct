"""Frozen Workspace template link experiment, diagnostic only; never run."""
import hashlib, json, re, struct, subprocess, sys
from pathlib import Path
import pefile
root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import match, rebuild
out = root/'rebuild/2008-06/out/native-layouts'
old = out/'workspace-integrated-names-fullobj-worker'
work = out/'workspace-template-link-worker'
work.mkdir(parents=True, exist_ok=True)
proof = root/'work/2008-06/shared-layouts'
baseline = json.loads((proof/'workspace-integrated-names-fullobj-worker.json').read_text())
source = out/'workspace-template-inst-worker/WorkspaceTemplates.cpp'
obj = work/'WorkspaceTemplates.obj'
life = json.loads((proof/'workspace-lifetime-integrated.json').read_text())
flags = [x for x in life['flags'] if not x.startswith('/Fo') and not x.endswith('WorkspaceLifetime.cpp')]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags+['/Fo'+str(obj),str(source)], work)
assert code == 0, log
raw = obj.read_bytes(); functions = match.coff_functions(raw); sections, symbols, defs, _ = match._coff_data_index(raw)
rows = []
for prefix, addr in [('??0?$DescribedNonCreatable@VWorkspace@', 0x5a4280), ('??0?$NonFactoryProduct@VRootInstance@', 0x5a07b0), ('??_G?$DescribedNonCreatable@VWorkspace@', 0x5a0910)]:
    name, body, refs = next(x for x in functions if x[0].startswith(prefix))
    target, targetrefs, _ = match.target('2008-06', '%08x'%addr)
    assert match.exact_match(target,targetrefs,body,refs)
    start, index = defs[name]; section = sections[index]; bindings = {}
    for i in range(section[7]):
        off, sym, kind = struct.unpack_from('<IIH', raw, section[5]+10*i); off -= start
        if 0 <= off < len(body)-3:
            value = struct.unpack_from('<I', target, off)[0]
            if kind == 20: value = (addr+off+4+struct.unpack_from('<i',target,off)[0]) & 0xffffffff
            bindings[symbols[sym][0]] = value
    if addr == 0x5a4280:
        assert any(k.startswith('??0?$NonFactoryProduct@VRootInstance@') and v == 0x5a07b0 for k,v in bindings.items())
        assert any(k.startswith('??_7?$DescribedNonCreatable@') and v == 0x833d80 for k,v in bindings.items())
    if addr == 0x5a0910:
        assert any(k.startswith('??1RootInstance@RBX@@') and v == 0x590630 for k,v in bindings.items())
    rows.append({'symbol':name,'address':hex(addr),'size':len(body),'bindings':{k:hex(v) for k,v in bindings.items()}})
pe=pefile.PE(str(root/'work/2008-06/original-p4-reference/Roblox.exe')); image=pe.OPTIONAL_HEADER.ImageBase
assert struct.unpack('<I',pe.get_data(0x833d88-image,4))[0] == 0x5a08f0
assert pe.get_data(0x5a08f0-image,3) == bytes.fromhex('83e910')
assert 0x5a08f8 + struct.unpack('<i',pe.get_data(0x5a08f4-image,4))[0] == 0x5a0910
sha=lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
assert sha(old/'native-workspace-lifetime.obj') == baseline['candidate_filtered_sha256']
assert sha(old/'Profiling.obj') == baseline['native_profiler_sha256']
assert sha(old/'donor-no-profiling.lib') == baseline['filtered_archive_sha256']
args=[]
for line in (old/'candidate.rsp').read_text().splitlines():
    arg=line.strip().strip(chr(34))
    if arg.upper().startswith('/OUT:'): arg='/OUT:'+str(work/'candidate.exe')
    elif arg.upper().startswith('/MAP:'): arg='/MAP:'+str(work/'candidate.map')
    args.append(arg)
args.append(str(obj)); rsp=work/'candidate.rsp';rsp.write_text('\n'.join(subprocess.list2cmdline([x]) for x in args)+'\n')
code,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],work);(work/'candidate.log').write_text(log)
errors=[x for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)\b',x)]
record={'scope':'Frozen diagnostic only; nonexact profiler, writer and full ABI not proven; never execute.', 'baseline_receipt_sha256':sha(proof/'workspace-integrated-names-fullobj-worker.json'), 'template_source_sha256':sha(source),'template_object_sha256':sha(obj),'methods':rows,'baseline_errors':baseline['candidate_errors'],'candidate_exit':code,'candidate_errors':errors}
(proof/'workspace-template-link-worker.json').write_text(json.dumps(record,indent=2)+'\n')
print('baseline',len(baseline['candidate_errors']),'candidate',len(errors),'exit',code)
