import frida, subprocess, time, ctypes, ctypes.wintypes as w
from pathlib import Path
root=Path(__file__).parent
lua=(root/'feature_test.lua').read_text()
code=chr(10).join(l.split('--')[0].strip() for l in lua.splitlines() if l.split('--')[0].strip())
exe=str(root/'run'/'RobloxQT.exe')
proc=subprocess.Popen([exe,'-script',code],cwd=str(root/'run'))
session=frida.attach(proc.pid)
target='0xdd45288'
js = """
let o=ptr('%s');
let vt=o.readPointer();
send({obj:o.toString(), vtable:vt.toString()});
for(let i=0;i<8;i++){ send({slot:i, val:vt.add(i*4).readPointer().toString()}); }
""" % target
script=session.create_script(js)
script.on('message', lambda m,d: print(ascii(m), flush=True))
script.load()
time.sleep(2)
proc.kill(); proc.wait()
PY