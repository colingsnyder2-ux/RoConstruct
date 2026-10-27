import sys, subprocess, shutil
sys.path.insert(0,".")
from pathlib import Path
from roc import rebuild
tc=rebuild.toolchain()
src=Path("C:/Users/colin/RoConstruct/rebuild/2008-06/tests/empty_main.cpp")
objs=sorted(Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/RbxgsApp/linked").glob("*.obj"))
deps=[Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/G3D/linked/linked.lib"),Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/G3D-GL/linked/linked.lib"),Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/libpng/linked/linked.lib"),Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/Boost/linked/linked.lib"),Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/RakNet/linked/linked.lib"),Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/zlib-winapi/linked/linked.lib"),Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/zlib/linked/linked.lib")]
syslibs=['kernel32.lib','user32.lib','gdi32.lib','advapi32.lib','shell32.lib','ole32.lib','oleaut32.lib','comdlg32.lib','ws2_32.lib','winmm.lib','opengl32.lib','glu32.lib','imagehlp.lib','version.lib','wininet.lib','dbghelp.lib','psapi.lib']

def test(subset, label):
    o=Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/tests")/(label)
    o.mkdir(parents=True,exist_ok=True)
    shutil.copy(Path("C:/Users/colin/RoConstruct/rebuild/2008-06/out/tests/empty_chunk0/empty_main.obj"), o/"empty_main.obj")
    code,text=rebuild.run(tc,'link',['/nologo','/SUBSYSTEM:CONSOLE','/MACHINE:X86','/OUT:empty_main.exe','empty_main.obj']+[str(x) for x in subset+deps]+syslibs+['/FORCE:UNRESOLVED'], o)
    if code!=0:
        print(label,'link fail', code); return None
    r=subprocess.run([str(o/'empty_main.exe')], capture_output=True)
    print(label,'run',r.returncode,'n=',len(subset))
    return r.returncode

# binary search
import bisect
bad=objs
# iterative halving
frontier=[bad]
while frontier:
    cur=frontier.pop(0)
    if len(cur)<=1:
        print("SINGLE", [p.name for p in cur]); continue
    mid=len(cur)//2
    left=cur[:mid]; right=cur[mid:]
    for part in (left,right):
        rc=test(part, 'bin_'+str(len(part)))
        if rc not in (0,None) and rc!=0:
            frontier.append(part)
