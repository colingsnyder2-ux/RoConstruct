import ast, frida, os, subprocess, sys, time
exe=os.path.abspath('run/RobloxOrig.exe' if os.environ.get('MP_ORIG') else 'run/RobloxQT.exe')
lua="local ns=game:GetService('NetworkServer') local plrs=game:GetService('Players') local function mark(s) local v=Instance.new('StringValue') v.Name=s v.Parent=workspace end local incoming=0 local joined=0 ns.IncommingConnection:connect(function() incoming=incoming+1 end) plrs.PlayerAdded:connect(function(p) joined=joined+1 p:LoadCharacter() end) ns:Start(53990,20) game:GetService('RunService'):Run() mark('PROOF server started') wait(25)"
if os.environ.get('MP_EXACT'):
    tree=ast.parse(open('mp_parity_probe.py').read())
    expr=next(n.value for n in tree.body if isinstance(n,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='server' for t in n.targets))
    lua=eval(compile(ast.Expression(expr),'<probe>','eval'),{'port':53990})
mapfile=r'C:\Users\colin\OneDrive\Documents\roblox junk\web-port\maps\2008\2008M - Crossroads.rbxl'
mapfile=mapfile.replace('\\','/')
device=frida.get_local_device()
process=subprocess.Popen([exe,mapfile,'-script',lua],cwd=os.path.dirname(exe))
pid=process.pid
session=device.attach(pid)
script=session.create_script('''%s
Interceptor.attach(ptr('%s'),{onEnter(args){
 try { let message=args[1].readCString(); if(message.indexOf('ChangeHistory')>=0) send({permission:args[0].toInt32(),identity:this.context.ecx.readU32(),message:message,caller:this.returnAddress.toString()}); } catch(e) {}
}}); let recent=[]; let sent=false; Process.setExceptionHandler(function(e) {
 let item={type:e.type,address:e.address.toString(),memory:e.memory,context:e.context,
       stack:Thread.backtrace(e.context,Backtracer.FUZZY).map(x=>x.toString())};
 if(e.type==='access-violation' && !sent) { sent=true; send({recent:recent, fault:item}); }
 recent.push(item); if(recent.length>5) recent.shift(); return false;
});''' % ('' if os.environ.get('MP_ORIG') else "Interceptor.attach(ptr('0x100c58b0'),{onEnter(args){try{let m=this.context.ecx;let p=m.add(0xb8).readPointer();let q=m.add(0xbc).readPointer();if(!Process.findRangeByAddress(p)) send({badmesh:m.toString(),begin:p.toString(),end:q.toString(),index:args[0].toInt32(),caller:this.returnAddress.toString(),stack:Thread.backtrace(this.context,Backtracer.ACCURATE).map(x=>x.toString())})}catch(e){send({mesh_error:e.toString()})}}}); Interceptor.attach(ptr('0x402950'),{onEnter(){this.site=this.returnAddress.toString()},onLeave(r){if(this.site==='0x5184fd' && !r.isNull()) send({lua_error:r.readCString()})}});", '0x489810' if os.environ.get('MP_ORIG') else '0x463790'))
script.on('message',lambda m,d: print(m,flush=True))
script.load()
time.sleep(20)
print('exit=',process.poll(),flush=True)
if process.poll() is None: process.kill(); process.wait()
