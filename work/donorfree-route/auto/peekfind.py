import frida, time, os, sys, json
exe = os.path.abspath('run/RobloxQT.exe')
pid = frida.spawn([exe, '-script', open('auto/one.lua').read()], cwd=os.path.dirname(exe))
s = frida.attach(pid)
js = """
Interceptor.attach(ptr('0x40fe40'), { onEnter() {
  const a = Array.from(new Uint32Array(this.context.esp.readByteArray(0x48)));
  const r = this.context.esp.readPointer();
  send({a: a.map(x => x.toString(16)), ret: r.toString()});
}});
"""
sc = s.create_script(js); out = []
sc.on('message', lambda m, d: out.append(m.get('payload') or m))
sc.load(); frida.resume(pid); time.sleep(10)
try: frida.kill(pid)
except Exception: pass
for o in out[-4:]: print(o)
print('calls', len(out))
