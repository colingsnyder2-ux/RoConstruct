import ast
import frida
import os
import subprocess
import time
from pathlib import Path

root = Path(__file__).parent
tree = ast.parse((root / 'mp_parity_probe.py').read_text())
expr = next(n.value for n in tree.body if isinstance(n, ast.Assign) and any(isinstance(t, ast.Name) and t.id == 'server' for t in n.targets))
lua = eval(compile(ast.Expression(expr), '<probe>', 'eval'), {'port': 53990})
exe = str(root / 'run/RobloxQT.exe')
place = r'C:\Users\colin\OneDrive\Documents\roblox junk\web-port\maps\2008\2008M - Crossroads.rbxl'
syms = {}
for line in (root / 'linkexp/qt.map').open(errors='ignore'):
    p = line.split()
    if len(p) >= 4:
        syms[p[1]] = p[2]
throw = syms['__CxxThrowException@8']
catch = int(syms['__catch$?execute@ScriptContext@@QAEXPAUState@@ULoader@@UResults@@@Z$0'], 16) + 0x24
proc = subprocess.Popen([exe, place, '-script', lua], cwd=str(root))
session = frida.attach(proc.pid)
script = session.create_script('''
let seen = 0;
Interceptor.attach(ptr('0x%s'), {onEnter(args) {
  if (seen++ > 40) return;
  let result = {caller:this.returnAddress.toString(), object:args[0].toString(), info:args[1].toString()};
  try { let s=args[0].add(16); let p=s.add(20).readU32()>=16?s.readPointer():s;
        result.message=p.readCString(); } catch(e) {}
  send({throw:result});
}});
Interceptor.attach(ptr('0x402950'), {onEnter() {this.site=this.returnAddress.toUInt32()}, onLeave(r) {
  if(this.site===%d && !r.isNull()) send({lua_error:r.readCString()});
}});
Process.setExceptionHandler(function(e) {
  if(e.type==='access-violation') send({fault:e.address.toString(), memory:e.memory,
    stack:Thread.backtrace(e.context,Backtracer.FUZZY).map(x=>x.toString())});
  return false;
});
''' % (throw, catch))
script.on('message', lambda m, data: print(ascii(m), flush=True))
script.load()
time.sleep(20)
print('exit=', proc.poll(), flush=True)
if proc.poll() is None:
    proc.kill()
    proc.wait()
