import frida, subprocess, time, ctypes, ctypes.wintypes as w
from pathlib import Path
root=Path(__file__).parent
exe=str(root/'run'/'RobloxQT.exe')
proc=subprocess.Popen([exe],cwd=str(root/'run'))
session=frida.attach(proc.pid)
js="const seen=new Set(); Interceptor.attach(ptr('0x645b30'),{onEnter(){const c=this.returnAddress.toString(); if(!seen.has(c)){seen.add(c); send({caller:c})}}});"
script=session.create_script(js)
script.on('message', lambda m,d: print(ascii(m), flush=True))
script.load()
time.sleep(20)
proc.kill(); proc.wait()