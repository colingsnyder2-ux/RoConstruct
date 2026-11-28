"""python auto/resizetest.py [EXE] [LUA]: launch, then resize/maximize/restore the main frame 20 times; report survival."""
import ctypes,ctypes.wintypes as w,subprocess,os,sys,time
u=ctypes.WinDLL('user32'); P=ctypes.WINFUNCTYPE(w.BOOL,w.HWND,w.LPARAM)
exe=os.path.abspath(sys.argv[1] if len(sys.argv)>1 else 'run/RobloxQT.exe')
lua=open(sys.argv[2]).read() if len(sys.argv)>2 and not sys.argv[2].startswith('--') else 'local p=Instance.new("Part") p.Anchored=true p.Parent=workspace'
p=subprocess.Popen([exe,'-script',lua],cwd=os.path.dirname(exe))
EV=[]
if '--frida' in sys.argv:
    import frida,re,bisect
    js='''var re=Module.getExportByName('kernelbase.dll','RaiseException');
Interceptor.attach(re,{onEnter:function(a){ if(a[0].toInt32()!==0xe06d7363|0) return; var t='?'; try{ var ti=a[3].add(8).readPointer(); var cta=ti.add(12).readPointer(); t=cta.add(4).readPointer().add(4).readPointer().add(8).readCString(); }catch(e){}
 if(t.indexOf('COleException')>=0) return;
 var s=''; try{ var o=a[3].add(4).readPointer(); s=o.add(4).readPointer().readCString(); }catch(e){}
 send({t:t,s:s,bt:Thread.backtrace(this.context,Backtracer.ACCURATE).slice(0,14).map(function(x){return x.toString();})}); }});
Process.setExceptionHandler(function(e){ if(e.type!=='access-violation') return false; var m=Process.findModuleByAddress(e.address);
 var raw=[]; for(var i=0;i<96;i++){ try{ raw.push(e.context.esp.add(i*4).readU32().toString(16)); }catch(_){} }
 send({t:'AV '+(m?m.name+'+'+e.address.sub(m.base):e.address)+' ecx='+e.context.ecx+' eax='+e.context.eax+' esi='+e.context.esi+' mem='+(e.memory?e.memory.address:''), s:'', bt:[e.address.toString()].concat(raw)}); return false; });'''
    if os.environ.get('RT_HOOK'): js+=open(os.environ['RT_HOOK']).read()
    sc=frida.attach(p.pid).create_script(js); sc.on('message',lambda m,d:EV.append(m.get('payload',m))); sc.load()
time.sleep(float(os.environ.get('RT_WAIT','9')))
def top():
    r=[]
    def cb(h,_):
        q=w.DWORD(); u.GetWindowThreadProcessId(h,ctypes.byref(q))
        c=ctypes.create_unicode_buffer(64); u.GetClassNameW(h,c,64)
        if q.value==p.pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'): r.append(h)
        return True
    u.EnumWindows(P(cb),0); return r[0] if r else None
h=top(); n=0
for i in range(20):
    if p.poll() is not None or not h: break
    if i%5==4: u.ShowWindow(h,3)
    elif i%5==0: u.ShowWindow(h,9)
    else: u.SetWindowPos(h,0,40+i*7,40,500+i*45,400+i*30,0x14)
    time.sleep(0.8); n+=1
time.sleep(2)
print(os.path.basename(exe),'resizes',n,'alive' if p.poll() is None else 'CRASH 0x%08X'%(p.returncode&0xffffffff))
if p.poll() is None: p.kill()
if EV:
    import re,bisect
    rows=[]
    for l in open('linkexp/qt.map',errors='ignore'):
        q=l.split()
        if len(q)>=4 and q[0].startswith('0001:') and re.fullmatch('[0-9a-f]{8}',q[2]): rows.append((int(q[2],16),q[1]))
    rows.sort(); ks=[r[0] for r in rows]
    def sym(v):
        v=int(v,16); j=bisect.bisect_right(ks,v)-1
        return '%08x %s+%x'%(v,rows[j][1][:100],v-ks[j]) if j>=0 and 0x401000<=v<0x8f0000 else '%08x'%v
    for e in EV:
        if 'hook' in e: print('HOOK',e)
    EV=[e for e in EV if 'hook' not in e]
    for e in EV[-1:]:
        print('THROW',e.get('t'),repr(e.get('s'))[:80]); [print('   ',sym(x)) for x in e.get('bt',[]) if 0x401000<=int(x,16)<0x8f0000]
