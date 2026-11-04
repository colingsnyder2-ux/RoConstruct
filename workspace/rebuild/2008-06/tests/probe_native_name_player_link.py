"""Relink existing player objects with original vs native Name; never run candidates here."""
import hashlib,json,re,subprocess,sys
from pathlib import Path
root=Path(__file__).resolve().parents[3];sys.path.insert(0,str(root));from roc import rebuild
out=root/'rebuild/2008-06/out/native-layouts/name-player-swap-probe';out.mkdir(parents=True,exist_ok=True);snap=root/'rebuild/2008-06/out';proof=root/'work/2008-06/shared-layouts';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();receipt=json.loads((proof/'name-whole-integrated.json').read_text());nameobj=snap/'native-layouts/name-whole-integrated/NameNative.obj';assert sha(nameobj)==receipt['object_sha256'];spec=rebuild.load_module('2008-06','player');libs=[snap/spec['name']/'linked/linked.lib'];pending=list(spec['depends'])
while pending:
 d=rebuild.load_module('2008-06',pending.pop(0));p=snap/d['name']/'linked/linked.lib'
 if p not in libs:libs.append(p);pending+=d.get('depends',[])
libs += [rebuild.dll_import_lib('2008-06',x) for x in spec['import_dlls']];source_archive=snap/'RbxgsApp/linked/linked.lib';assert source_archive in libs;filtered=out/'RbxgsAppWithoutName.lib';code,log=rebuild.run(rebuild.toolchain(21022),'lib',['/nologo','/REMOVE:Name.obj','/OUT:'+str(filtered),str(source_archive)],out);assert code==0,log
main=snap/'tests/P2RecoveredPlayer/P2RecoveredPlayer.obj';system=['kernel32.lib','user32.lib','gdi32.lib','advapi32.lib','shell32.lib','ole32.lib','oleaut32.lib','comdlg32.lib','ws2_32.lib','winmm.lib','opengl32.lib','glu32.lib','imagehlp.lib','version.lib','wininet.lib','dbghelp.lib','psapi.lib']+['/NODEFAULTLIB:'+x for x in rebuild.VENDOR_AUTOLINK];inputs=[main,nameobj]+libs;before={str(p):sha(p) for p in inputs};rows={}
for label in ('baseline','native-name'):
 chosen=[filtered if p==source_archive and label=='native-name' else p for p in libs];args=['/nologo','/SUBSYSTEM:CONSOLE','/MACHINE:X86','/MAP:'+label+'.map','/OUT:'+label+'.exe',str(main)]+([str(nameobj)] if label=='native-name' else [])+[str(x) for x in chosen]+system;rsp=out/(label+'.rsp');rsp.write_text('\n'.join(subprocess.list2cmdline([x]) for x in args)+'\n');c,log=rebuild.run(rebuild.toolchain(21022),'link',['@'+str(rsp)],out);(out/(label+'.log')).write_text(log);errors=[x.strip() for x in log.splitlines() if re.search(r'\berror LNK(?:2001|2019|2005|1104)',x)];rows[label]={'exit':c,'errors':errors,'exe_sha256':sha(out/(label+'.exe')) if c==0 else None,'map_sha256':sha(out/(label+'.map')) if c==0 else None};print(label,'exit',c,'errors',len(errors),flush=True)
assert all(sha(Path(p))==h for p,h in before.items()),'link input changed'
if all(row['exit']==0 for row in rows.values()):
 maps={label:(out/(label+'.map')).read_text(errors='replace').splitlines() for label in rows}
 symbols=('?declare@Name@RBX@@','?getNullName@Name@RBX@@','?lookup@Name@RBX@@','?dictionary@Name@RBX@@','?namMap@Name@RBX@@','?moo2@@','?initMoo@@','?initNullName@@')
 selected={symbol:[line.strip() for line in maps['native-name'] if symbol in line and ' f ' in line and 'NameNative.obj' in line and '__' not in line.split(symbol)[0]] for symbol in symbols}
 assert all(selected.values()),selected
 assert len(selected['?lookup@Name@RBX@@'])==2,selected['?lookup@Name@RBX@@']
 rows['native-name']['selected_symbols']=selected
 baseline=[line.strip() for line in maps['baseline'] if '?declare@Name@RBX@@' in line and ' f ' in line and 'linked:Name.obj' in line and '__' not in line.split('?declare@Name@RBX@@')[0]]
 assert baseline,'baseline Name provider not selected'
 rows['baseline']['selected_declare']=baseline
result={'scope':'Isolated player relink comparison only; inputs are current archived build artifacts, not a source rebuild. No execution, ABI or P5/P6 claim.','inputs':before,'filtered_archive_sha256':sha(filtered),'observer_sha256':sha(Path(__file__)),'results':rows};(proof/'name-player-relink-probe.json').write_text(json.dumps(result,indent=2)+'\n')
