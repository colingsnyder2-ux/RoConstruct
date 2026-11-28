import ctypes, ctypes.wintypes as w, json, os, re, struct, subprocess, sys, time
from pathlib import Path
import scripttest

base = Path(__file__).parent
exe, mapfile, port = sys.argv[1], sys.argv[2], int(sys.argv[3])
exe = str(Path(exe).resolve())
server = '''local ns=game:GetService('NetworkServer')
local plrs=game:GetService('Players')
local function mark(s) local v=Instance.new('StringValue') v.Name=s v.Parent=workspace end
local incoming=0 local joined=0
ns.IncommingConnection:connect(function() incoming=incoming+1 end)
plrs.PlayerAdded:connect(function(p) joined=joined+1 p:LoadCharacter() end)
ns:Start(%d,20) game:GetService('RunService'):Run() mark('PROOF server started')
wait(35) local names='' for _,p in ipairs(plrs:GetChildren()) do names=names..p.Name..':'..tostring(p.Character~=nil)..',' end
mark('PROOF server incoming '..incoming..' joined '..joined..' players '..names)''' % port
client = '''local nc=game:GetService('NetworkClient')
local function mark(s) local v=Instance.new('StringValue') v.Name=s v.Parent=workspace end
mark('PROOF client started')
nc.ConnectionAccepted:connect(function(url,rep)
 mark('PROOF accepted')
 local p=game:GetService('Players'):CreateLocalPlayer(1)
 mark('PROOF local player')
 local m=rep:SendMarker() mark('PROOF marker sent')
 m.Received:connect(function() mark('PROOF marker received') end)
 wait(12)
 local ch=p.Character local bp=p:FindFirstChild('Backpack') local used=0
 if bp and ch then for _,t in ipairs(bp:GetChildren()) do if t:IsA('Tool') then t.Parent=ch used=used+1 wait(0.3) end end end
 if ch and ch:FindFirstChild('Humanoid') then ch.Humanoid.Jump=true ch.Humanoid:MoveTo(Vector3.new(12,5,12)) end
 mark('PROOF character '..tostring(ch~=nil)..' tools '..used)
end)
nc:Connect('127.0.0.1',%d,0)''' % port

u, k = scripttest.u, scripttest.k
def names(p):
    hp=k.OpenProcess(0x1F0FFF,False,p.pid)
    mem=k.VirtualAllocEx(hp,None,4096,0x3000,4)
    out=[]
    def top(h,_):
        pid=w.DWORD(); u.GetWindowThreadProcessId(h,ctypes.byref(pid))
        if pid.value!=p.pid: return True
        def child(t,_):
            if scripttest.cls(t)!='SysTreeView32': return True
            def text(it):
                k.WriteProcessMemory(hp,mem,struct.pack('<IIIIIIIIII',1,it,0,0,mem+512,256,0,0,0,0),40,None)
                scripttest.snd(t,0x110C,0,mem,a=True)
                b=ctypes.create_string_buffer(256); k.ReadProcessMemory(hp,mem+512,b,256,None)
                return b.value.decode('latin-1')
            it=scripttest.snd(t,0x110A,0,0)
            while it:
                if text(it)=='Workspace':
                    scripttest.snd(t,0x1102,2,it); time.sleep(.5)
                    c=scripttest.snd(t,0x110A,4,it)
                    while c:
                        n=text(c)
                        if n.startswith('PROOF '): out.append(n)
                        c=scripttest.snd(t,0x110A,1,c)
                it=scripttest.snd(t,0x110A,1,it)
            return True
        u.EnumChildWindows(h,scripttest.P(child),0); return True
    u.EnumWindows(scripttest.P(top),0)
    k.VirtualFreeEx(hp,mem,0,0x8000); k.CloseHandle(hp)
    return out

def exercise(p):
    wins=[]
    def top(h,_):
        pid=w.DWORD(); u.GetWindowThreadProcessId(h,ctypes.byref(pid))
        if pid.value==p.pid and u.IsWindowVisible(h): wins.append(h)
        return True
    u.EnumWindows(scripttest.P(top),0)
    if not wins: return False
    h=wins[0]
    for key in (0x31,0x32,0x33,0x34,0x57,0x20):
        u.PostMessageW(h,0x100,key,0); time.sleep(.08); u.PostMessageW(h,0x101,key,0)
        if key<0x35:
            u.PostMessageW(h,0x201,1,(220<<16)|320); u.PostMessageW(h,0x202,0,(220<<16)|320)
    return True

def trace(p, label):
    import frida
    stubs={}
    for line in (base/'linkexp/qt.map').open(errors='ignore'):
        m=re.search(r'\s(func_([0-9a-f]{8}))\s+([0-9a-f]{8})\s+qt_stubs\w*\.obj',line,re.I)
        if m and (base/'renamed/obj'/('%s.obj'%m[2])).exists(): stubs['0x'+m[3]]=m[1]
    session=frida.attach(p.pid)
    script=session.create_script('const s='+json.dumps(stubs)+'; for (const a in s) { let seen=false; Interceptor.attach(ptr(a),{onEnter(){if(!seen){seen=true;send({name:s[a],caller:this.returnAddress.toString()})}}}) }')
    hits={}
    def message(m,_):
        if m.get('type')=='send':
            h=m['payload']; hits.setdefault(h['name'],h['caller'])
    script.on('message',message); script.load()
    return label,session,script,hits

ps=[]
traces=[]
try:
    ps.append(subprocess.Popen([exe,mapfile,'-script',server],cwd=os.path.dirname(exe)))
    if os.environ.get('MP_STUBS'): traces.append(trace(ps[0],'server'))
    time.sleep(15)
    print('server before connect exit=',ps[0].poll(),'proof=',names(ps[0]) if ps[0].poll() is None else [],flush=True)
    ps.append(subprocess.Popen([exe,'-script',client],cwd=os.path.dirname(exe)))
    if os.environ.get('MP_STUBS'): traces.append(trace(ps[1],'client'))
    time.sleep(12)
    print('client input=',exercise(ps[1]) if ps[1].poll() is None else False,flush=True)
    time.sleep(28)
    for label,p in zip(('server','client'),ps):
        print(label,'exit=',p.poll(),'proof=',names(p) if p.poll() is None else [],flush=True)
    for label,session,script,hits in traces: print(label,'stub hits=',hits,flush=True)
finally:
    for p in ps:
        if p.poll() is None: p.kill(); p.wait()
