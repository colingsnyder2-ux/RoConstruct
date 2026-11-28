import ast
import frida
import os
import subprocess
import sys
import time
from pathlib import Path

root = Path(__file__).parent
tree = ast.parse((root / 'mp_parity_probe.py').read_text())
expr = next(n.value for n in tree.body if isinstance(n, ast.Assign) and any(isinstance(t, ast.Name) and t.id == 'server' for t in n.targets))
lua = eval(compile(ast.Expression(expr), '<probe>', 'eval'), {'port': 53991})
exe = str(root / 'run' / sys.argv[1])
place = r'C:\Users\colin\OneDrive\Documents\roblox junk\web-port\maps\2008\2008M - Crossroads.rbxl'
proc = subprocess.Popen([exe, place, '-script', lua], cwd=str(root))
session = frida.attach(proc.pid)
symbols={}
for line in (root / 'linkexp/qt.map').open(errors='ignore'):
 p=line.split()
 if len(p)>=4: symbols[p[1]]=p[2]
shade=next(int(v,16) for k,v in symbols.items() if k.startswith('?shade@TextureProxy@RenderNew@RBX@@'))
zero=int(symbols['__roc_abs_zero'],16)
script = session.create_script('''
if (%s) Interceptor.attach(ptr(%d),{onEnter(args){if(this.context.ecx.toUInt32()===%d)
 send({zero_shade:true,caller:this.returnAddress.toString(),stack:Thread.backtrace(this.context,Backtracer.ACCURATE).map(x=>x.toString())})}});
let timer=setInterval(function(){
 let m=Process.findModuleByName('rgmain.dll'); if(!m) return;
 let p=m.findExportByName('?load@Image@Ogre@@QAEAAV12@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z');
 if(!p) {send({missing_export:true});clearInterval(timer);return;}
 let mesh=m.findExportByName('?getSubMesh@Mesh@Ogre@@QBEPAVSubMesh@2@G@Z');
 if(mesh) Interceptor.attach(mesh,{onEnter(args){try{
   let obj=this.context.ecx, begin=obj.add(0xb8).readPointer(), end=obj.add(0xbc).readPointer();
   if(!Process.findRangeByAddress(begin) || end.sub(begin).toUInt32()>0x100000)
     send({bad_mesh:obj.toString(),begin:begin.toString(),end:end.toString(),index:args[0].toInt32(),
       caller:this.returnAddress.toString(),stack:Thread.backtrace(this.context,Backtracer.FUZZY).map(x=>x.toString())});
 }catch(e){send({mesh_error:e.toString()})}}});
 Interceptor.attach(p,{onEnter(args){try{
   let obj=args[0], s=obj.add(4), text=(s.add(20).readU32()>=16?s.readPointer():s).readCString();
   if(!text) {let source=obj.sub(12);send({empty_image:true,source:source.toString(),
     sourceRoot:source.add(64).readPointer().toString(), sourceShade:source.add(68).readPointer().toString(),
     caller:this.returnAddress.toString(),stack:Thread.backtrace(this.context,Backtracer.FUZZY).map(x=>x.toString())});}
 }catch(e){send({error:e.toString()})}}});
 send({armed:true}); clearInterval(timer);
},25);
''' % ('true' if sys.argv[1].lower()=='robloxqt.exe' else 'false',shade,zero))
script.on('message', lambda m, data: print(ascii(m), flush=True))
script.load()
time.sleep(25)
print('exit=', proc.poll(), flush=True)
if proc.poll() is None:
    proc.kill()
    proc.wait()
