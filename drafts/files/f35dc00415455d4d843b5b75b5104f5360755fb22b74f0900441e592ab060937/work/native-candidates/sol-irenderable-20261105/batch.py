from pathlib import Path
import sys,json,hashlib
R=Path.cwd();sys.path.insert(0,str(R));sys.path.insert(0,str(R/'rebuild/2008-06/tests'))
import native_check_runner as n
from roc import match
O=R/'work/2008-06/shared-layouts/sol-irenderable-20261105'; C=R/'work/native-candidates/sol-irenderable-20261105'
cmd=json.loads((R/'rebuild/2008-06/out/RbxgsApp/layer-rbxgs/IRenderable.command.json').read_text());src=Path(cmd['source']);text=src.read_text();assert hashlib.sha256(src.read_bytes()).hexdigest()==cmd['source_sha256']
assert text.count('IRenderable::~IRenderable()')==1
body=text[text.index('\tIRenderable::~IRenderable()'):text.index('\n\tvoid IRenderable::shouldRenderSetDirty')]
assert body.count('RBXASSERT(')==3
native=R/'rebuild/2008-06/native-classes/IRenderableLifetime.cpp'
native.write_text('#include "util/Debug.h"\n#include "util/IRenderable.h"\nnamespace RBX {\n'+body+'\n}\n')
remainder=C/'IRenderable.cpp';remainder.write_text(text.replace('IRenderable::~IRenderable()','inline IRenderable::~IRenderable()'))
base=R/'work/2008-06/shared-layouts/sol-filesystem-owner-20261105/linked.lib';assert n.sha(base)=='0c597337028cf2cda5addf6ededafd11d546ec6205720401a5e1c166ab1b0836'
# Original bytes independently fetched from verified image.
assert n.sha(R/'clients/2008-06/Roblox.exe')=='2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764'
import capstone
b,img=match._image('2008-06');md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
original={hex(a):[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in md.disasm(bytes(img[a-b:a-b+sz]),a)] for a,sz in [(0x47d410,1),(0x615780,8),(0x615a20,60)]}
(O/'original.json').write_text(json.dumps(original,indent=2))
# Scoped adapter replaces flags only, preserving runner isolation, fingerprints and analysis.
original_flags=n.compiler_flags
def flags(p):
 if p==native:return original_flags(p)+['/U_RELEASEASSERT','/U_DEBUG']
 assert p==remainder
 return [a for a in cmd['args'] if not a.lower().startswith(('/fo','/fd')) and a!=cmd['source']]
n.compiler_flags=flags
manifest={'jobs':[{'source':str(native),'checks':[{'addr':'0047d410','symbol':'??1IRenderable@RBX@@QAE@XZ','calls':[]}]},{'source':str(remainder),'checks':[]}]}
jobs=n.jobs_from(manifest);run=O/'run';run.mkdir();n.save(run/'manifest.json',{'jobs':jobs})
n.execute(run,1)
print((run/'summary.json').read_text())
