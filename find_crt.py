from pathlib import Path
import subprocess
objs=sorted(Path("rebuild/2008-06/out/RbxgsApp/linked").glob("*.obj"))
dumpbin=r"C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.44.35207\bin\HostX64\x64\dumpbin.exe"
for p in objs:
    out=subprocess.run([dumpbin,"/headers",str(p)],capture_output=True,text=True)
    if ".CRT" in out.stdout:
        print(p.name)
