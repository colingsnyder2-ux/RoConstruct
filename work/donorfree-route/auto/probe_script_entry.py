import ctypes, ctypes.wintypes as w, os, time
import frida

exe = os.path.abspath('run/RobloxQT.exe')
pid = frida.spawn([exe, '-script', 'local v = Instance.new("StringValue") v.Name = "R1 pass=1 fail=" v.Parent = workspace assert(v.Name == "R1 pass=1 fail=" and v.Parent == workspace, "BAD")'], cwd=os.path.dirname(exe))
session = frida.attach(pid)
script = session.create_script('''
for (const [name, address] of [['openState', 0x6a8070], ['execute', 0x516d40], ['loadbuffer', 0x55f360], ['resume', 0x6a8cf0]]) {
  Interceptor.attach(ptr(address), {onEnter(args) { send(name + ' enter'); }, onLeave(ret) { send(name + ' return ' + ret); }});
}
Interceptor.attach(ptr(0x6a7950), {onEnter(args) {
  const tostring = new NativeFunction(ptr(0x811a20), 'pointer', ['pointer', 'int', 'pointer']);
  try { send('Lua error: ' + tostring(args[0], -1, ptr(0)).readCString()); } catch (e) { send('Lua error unreadable: ' + e); }
}});
Interceptor.attach(ptr(0x4e00d0), {onEnter(args) { try { send('output: ' + args[1].readCString()); } catch (e) {} }});
Interceptor.attach(ptr(0x55f360), {onEnter(args) { try { send('source: ' + args[1].readUtf8String(args[2].toInt32())); } catch (e) { send('source unreadable: ' + e); } }});
Interceptor.attach(ptr(0x403630), {onEnter(args) { try { send('newindex: ' + args[1].readCString()); } catch (e) { send('newindex'); } }});
Interceptor.attach(ptr(0x4d54f0), {onEnter(args) { send('setParent: ' + this.context.ecx + ' -> ' + args[0]); }});
Interceptor.attach(ptr(0x6037e0), {onEnter(args) { send('setName: ' + this.context.ecx); }});
Interceptor.attach(ptr(0x65e050), {onEnter(args) { send('setValue<string> enter'); }});
Interceptor.attach(ptr(0x51e5a0), {onEnter(args) { send('name descriptor: ' + this.context.ecx + ' fn=' + this.context.ecx.add(0x10).readPointer() + ' adjust=' + this.context.ecx.add(0x14).readS32()); }});
Interceptor.attach(ptr(0x63d130), {onEnter(args) { send('virtual setter: obj=' + this.context.ecx + ' vtable=' + this.context.ecx.readPointer() + ' target=' + this.context.ecx.readPointer().add(4).readPointer()); }});
let traceLocks = false;
Interceptor.attach(ptr(0x4dcdd0), {onEnter(args) { this.lock = this.context.ecx; const cs = this.lock.readPointer(), owner = cs.add(12).readU32(); if (this.lock.equals(ptr(0x125a960)) || (traceLocks && owner && owner !== Process.getCurrentThreadId())) send('lock wait tid=' + Process.getCurrentThreadId() + ' lock=' + this.lock + ' owner=' + owner + ' stack=' + Thread.backtrace(this.context, Backtracer.ACCURATE).join(',')); }, onLeave() { if (this.lock.equals(ptr(0x125a960))) send('settings acquired tid=' + Process.getCurrentThreadId()); }});
Interceptor.attach(ptr(0x4dce20), {onEnter(args) { if (this.context.ecx.equals(ptr(0x125a960))) send('settings unlock tid=' + Process.getCurrentThreadId() + ' stack=' + Thread.backtrace(this.context, Backtracer.ACCURATE).join(',')); }});
rpc.exports = { trace() { traceLocks = true; }, stacks() { return Process.enumerateThreads().map(t => ({id:t.id, state:t.state, stack:Thread.backtrace(t.context, Backtracer.ACCURATE).map(p => p.toString())})); } };
''')
script.on('message', lambda m, d: print(m, flush=True))
script.load()
frida.resume(pid)
time.sleep(10)
script.exports_sync.trace()
u = ctypes.WinDLL('user32')
P = ctypes.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
def cb(h, _):
    p = w.DWORD(); u.GetWindowThreadProcessId(h, ctypes.byref(p))
    c = ctypes.create_unicode_buffer(128); u.GetClassNameW(h, c, 128)
    if p.value == pid:
        print('window', hex(h), c.value, 'visible', u.IsWindowVisible(h), flush=True)
    if p.value == pid and u.IsWindowVisible(h) and c.value.startswith('Afx:'):
        def child(ch, _):
            name = ctypes.create_unicode_buffer(128); u.GetClassNameW(ch, name, 128)
            if name.value == 'SysTreeView32': print('tree', hex(ch), 'visible', u.IsWindowVisible(ch), 'root', hex(u.SendMessageW(ch, 0x110a, 0, 0)), flush=True)
            return True
        u.EnumChildWindows(h, P(child), 0)
        u.PostMessageW(h, 0x111, 32966, 0)
    return True
u.EnumWindows(P(cb), 0)
time.sleep(5)
print('stacks', script.exports_sync.stacks(), flush=True)
frida.kill(pid)
