import sys
from pathlib import Path
sys.path.insert(0,'.')
from roc import libs, rebuild
recipe=libs.RECIPES['rbxgs']
out=Path('rebuild/2008-06/out/native-layouts'); out.mkdir(parents=True,exist_ok=True)
root=Path.cwd()
flags=['/nologo','/c','/O2','/Ob2','/Oy','/GF','/GS-','/EHsc','/MD','/D_AFXDLL','/DNDEBUG','/D_MBCS','/DNOMINMAX','/DBOOST_ALL_NO_LIB']
flags+=['/D'+v for v in recipe['defines'].split()]
flags+=['/I'+str(root/'rebuild/2008-06/native-headers'),'/I'+str(root/'tools/libs/mfc-9.0-rtm/atlmfc/include'),'/I'+'C:/Users/colin/RoConstruct/tools/libs/xtp-11.2.2/Source']
flags+=['/I'+str((libs.LIBS/v).resolve()) for v in recipe['include'] if v!='WINSDK']
flags+=['/FoNativeViewLayout.obj',str(root/'rebuild/2008-06/tests/NativeViewLayout.cpp')]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out)
print(code); print(log)
