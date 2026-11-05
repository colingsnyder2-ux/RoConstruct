import json,hashlib
from pathlib import Path
from roc import libs
p=Path('work/2008-06/shared-layouts/sol-snapshot-20261105')
sha=lambda b:hashlib.sha256(b).hexdigest()
old=json.loads((p/'rbxgs-app-inputs.json').read_text())
archive=Path('rebuild/2008-06/out/RbxgsApp/linked/linked.lib')
cmd=Path('rebuild/2008-06/out/RbxgsApp/layer-rbxgs/ContentProvider.command.json')
a=json.loads(cmd.read_text()); b=json.loads(Path('work/2008-06/shared-layouts/sol-content-owner-20261105/canonical-command.json').read_text())
changed={k:{'prior':b.get(k),'current':a.get(k)} for k in ['source','source_sha256','compiler','args','dependencies'] if a.get(k)!=b.get(k)}
members={n:sha(d) for n,d in libs.archive_members(archive)}
result={'archive':str(archive.resolve()),'sha256':sha(archive.read_bytes()),'prior_sha256':old['archive_sha256'],'member_hashes':members,'content_command_differences':changed,'command_sha256':sha(cmd.read_bytes()),'prior_commands_now_changed':[r['path'] for r in old['commands'] if sha(Path(r['path']).read_bytes())!=r['sha256']]}
(p/'post-refresh-app-audit.json').write_text(json.dumps(result,indent=2)+'\n')
print({'archive_equal':result['sha256']==result['prior_sha256'],'members':len(members),'content_command_changed_fields':list(changed),'changed_commands':len(result['prior_commands_now_changed'])})
