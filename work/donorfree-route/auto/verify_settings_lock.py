"""Verify loadState releases its settings lock, including on exception."""
import os, re, sys, time
from pathlib import Path
import frida

root = Path(__file__).resolve().parent.parent
symbols = {}
for line in (root / 'linkexp/qt.map').read_text(errors='replace').splitlines():
    parts = line.split()
    if len(parts) >= 4 and ':' in parts[0]:
        try:
            symbols[parts[1]] = int(parts[2], 16)
        except ValueError:
            pass
names = ['?loadState@GlobalSettings@RBX@@QAEXXZ', 'func_00563090', 'func_005630e0', '?mutex@GlobalSettings@RBX@@2Vrecursive_mutex@boost@@A']
load, lock, unlock, mutex = (symbols[n] for n in names)
exe = str(root / 'run/RobloxQT.exe')
pid = frida.spawn([exe, '-script', 'local v = Instance.new("StringValue") v.Name = "R1 pass=1 fail=" v.Parent = workspace'], cwd=os.path.dirname(exe))
session = frida.attach(pid)
js = '''
const mutex = ptr(MUTEX); let thread = 0, depth = 0, throws = 0;
Interceptor.attach(ptr(LOAD), {
  onEnter() { thread = Process.getCurrentThreadId(); depth = 0; throws = 0; },
  onLeave() { send({depth, throws}); thread = 0; }
});
Interceptor.attach(ptr(LOCK), {
  onEnter() { this.match = thread && Process.getCurrentThreadId() === thread && this.context.ecx.equals(mutex); },
  onLeave() { if (this.match) depth++; }
});
Interceptor.attach(ptr(UNLOCK), { onEnter() {
  if (thread && Process.getCurrentThreadId() === thread && this.context.ecx.equals(mutex)) depth--;
}});
Interceptor.attach(Module.getGlobalExportByName('RaiseException'), { onEnter(args) {
  if (thread && Process.getCurrentThreadId() === thread && args[0].toUInt32() === 0xe06d7363) throws++;
}});
'''
for key, value in [('LOAD', load), ('LOCK', lock), ('UNLOCK', unlock), ('MUTEX', mutex)]:
    js = re.sub(r'\b' + key + r'\b', hex(value), js)
script = session.create_script(js)
events = []
script.on('message', lambda m, _: events.append(m.get('payload')) if m.get('type') == 'send' else print(m, flush=True))
script.load(); frida.resume(pid)
time.sleep(12)
frida.kill(pid)
print('loadState results:', events)
if not events or any(e['depth'] != 0 for e in events):
    sys.exit(1)
