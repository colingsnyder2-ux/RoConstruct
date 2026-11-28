import frida, subprocess, time, ctypes, ctypes.wintypes as w
from pathlib import Path
root=Path(__file__).parent
exe=str(root/'run'/'RobloxQT.exe')
proc=subprocess.Popen([exe],cwd=str(root/'run'))
session=frida.attach(proc.pid)
js="""
let vt=ptr('0x96e50c');
let col=vt.sub(4).readPointer();
let td=col.add(12).readPointer();
send({col:col.toString(), td:td.toString(), name:td.add(8).readCString()});
"""
script=session.create_script(js)
script.on('message', lambda m,d: print(ascii(m), flush=True))
script.load()
time.sleep(2)
proc.kill(); proc.wait()