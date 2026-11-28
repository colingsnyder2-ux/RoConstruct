import frida, time, os, sys
exe = os.path.abspath(sys.argv[1]); addrs = sys.argv[2:]
pid = frida.spawn([exe, '-script', open('auto/one.lua').read()], cwd=os.path.dirname(exe))
s = frida.attach(pid)
js = "const A=%s; for (const a of A) Interceptor.attach(ptr(a), { onEnter() { send([a, this.context.esp.toString(), this.context.esp.readPointer().toString(), this.context.ecx.toString()]); } });" % repr(addrs)
sc = s.create_script(js); out = []
sc.on('message', lambda m, d: out.append(m.get('payload') or m))
sc.load(); frida.resume(pid); time.sleep(10)
try: frida.kill(pid)
except Exception: pass
for o in out[-40:]: print(o)
print('calls', len(out))
