import frida, time, os, sys
exe = os.path.abspath('run/RobloxOrig.exe')
pid = frida.spawn([exe, '-script', open('auto/one.lua').read()], cwd=os.path.dirname(exe))
s = frida.attach(pid)
js = """
function rd(p, n) { try { return Array.from(new Uint32Array(ptr(p).readByteArray(n))).map(x => x.toString(16)); } catch (e) { return 'bad'; } }
Interceptor.attach(ptr('0x6390a0'), { onEnter() {
  const t = this.context.ecx; const w = rd(t, 0x20);
  let impl = 'n/a'; try { impl = rd(ptr(parseInt(w[0], 16)), 0x30); } catch (e) {}
  send({ret: this.context.esp.readPointer().toString(), this: t.toString(), obj: w, impl: impl});
}});
"""
sc = s.create_script(js); out = []
sc.on('message', lambda m, d: out.append(m.get('payload') or m))
sc.load(); frida.resume(pid); time.sleep(10)
try: frida.kill(pid)
except Exception: pass
for o in out[-5:]: print(o)
print('calls', len(out))
