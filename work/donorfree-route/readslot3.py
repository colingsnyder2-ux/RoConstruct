import frida, subprocess, time
proc=subprocess.Popen([r'C:\Users\colin\RoConstruct\work\donorfree-route\run\RobloxQT.exe'], cwd=r'C:\Users\colin\RoConstruct\work\donorfree-route\run')
session=frida.attach(proc.pid)
js="send({val:ptr('0xa9c764').readPointer().toString()});"
script=session.create_script(js)
script.on('message', lambda m,d: print(ascii(m), flush=True))
script.load()
time.sleep(3)
proc.kill(); proc.wait()