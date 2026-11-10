import json,hashlib,sys,importlib.util,os
from pathlib import Path
R=Path.cwd();O=R/'work/2008-06/shared-layouts/sol-archive-resolve-owner-20261105'; S=R/'work/native-candidates/sol-archive-resolve-owner-20261105/SerializerV2.cpp'
sys.path.insert(0,str(R));from roc import libs,rebuild
H=lambda b:hashlib.sha256(b).hexdigest()
cpath=R/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/SerializerV2.command.json';c=json.loads(cpath.read_text());src=Path(c['source']).read_bytes();assert H(src)==c['source_sha256']
drift=[p for p,h in c['dependencies'].items() if not Path(p).exists() or H(Path(p).read_bytes())!=h]
archive=R/'work/2008-06/shared-layouts/sol-clone-owner-20261105/linked.lib';ab=archive.read_bytes();assert H(ab)=='3a0490de7239801417a5ae524ed5e54fd5301cf77a7b5cd88d170e8431a1fcbe'
mm=list(libs.archive_members(archive));old=[b for n,b in mm if n=='SerializerV2.obj'];assert len(old)==1 and H(old[0])=='c6f555a65d89f48ff15b4d01fdb45b81698c63eb24031c547aa0dd8d231f35f0'
(O/'old.obj').write_bytes(old[0]);(O/'actual-command.json').write_text(json.dumps(c,indent=2));guard=dict(command_sha256=H(cpath.read_bytes()),source_sha256=H(src),dependencies=len(c['dependencies']),drift=drift,member_count=len(mm),old_sha256=H(old[0]),archive_sha256=H(ab));(O/'guard.json').write_text(json.dumps(guard,indent=2));print(json.dumps(guard));assert not drift,'dependency drift: stop'
a=src.index(b'bool ArchiveBinder::resolveRefs()');b=src.index(b'bool ArchiveBinder::resolveIDREF',a);removed=src[a:b];assert removed.count(b'{')==1 and removed.count(b'}')==1
S.write_bytes(src[:a]+src[b:]);(O/'removed-definition.txt').write_bytes(removed)

