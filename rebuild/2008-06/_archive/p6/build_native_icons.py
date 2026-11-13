from pathlib import Path
import sys, hashlib, json, subprocess
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT))
from roc import libs,match,rebuild
out=ROOT/'rebuild/2008-06/out/native-layouts';out.mkdir(parents=True,exist_ok=True)
header=ROOT/'tools/libs/mfc-9.0-rtm/atlmfc/include/atlimage.h'
text=header.read_text(encoding='latin1'); old='inline int CImage::GetWidth() const throw()\n{\n\tATLASSUME( m_hBitmap != NULL );\n\n\treturn( m_nWidth );\n}\n';assert text.count(old)==1
alias=out/'roc_espeon_nativeatlimagewidthdecl2e5804ac680a6dd9.cpp';alias.write_text(text.replace(old,'').replace('inline CImage::CImage()', '__declspec(noinline) inline CImage::CImage()').replace('inline CImage::~CImage()', '__declspec(noinline) inline CImage::~CImage()').replace('inline CImage::operator HBITMAP()', '__declspec(noinline) inline CImage::operator HBITMAP()').replace('inline BOOL CImage::Create( int nWidth', '__declspec(noinline) inline BOOL CImage::Create( int nWidth').replace('inline const void* CImage::GetPixelAddress(', '__declspec(noinline) inline const void* CImage::GetPixelAddress(').replace('inline void* CImage::GetPixelAddress(', '__declspec(noinline) inline void* CImage::GetPixelAddress('),encoding='latin1')
source=ROOT/'tools/libs/xtp-11.2.2/roc_claudeM_55bb15a72a4fb4db.cpp'
wrapper=out/'FrameIconsFreshWrapper.cpp';wrapper.write_text('#include "Common/XTPDLLExports.h"\n#include "XTToolkitPro.h"\n#include "'+source.as_posix()+'"\n')
r=libs.RECIPES['xtp-11.2.2-lib-imports'];include=';'.join([str(out),str(ROOT/'tools/libs/xtp-11.2.2'),str(ROOT/'tools/libs/xtp-11.2.2/Source'),str(ROOT/'tools/libs/mfc-9.0-rtm/atlmfc/include'),libs.winsdk_include()]);deps=[]
body=libs.preprocess(21022,wrapper,include,r['defines'],deps)
for member in r['noinline']:body=body.replace(member,'__declspec(noinline) '+member)
translation=out/'NativeFrameIconsFresh.cpp';translation.write_text(body,encoding='utf8')
flags=['/nologo','/c','/O2','/GS-','/EHsc','/MD','/arch:SSE2','/FoNativeFrameIconsFresh.obj',str(translation)]
code,log=rebuild.run(rebuild.toolchain(21022),'cl',flags,out);assert code==0,log
obj=(out/'NativeFrameIconsFresh.obj').read_bytes()
methods=[]
for addr,prefix in [('0042f490','?InitializeAllIcons@@'),('0042f380','?InitializeIcons@@'),('0042f290','?SetIcon@@'),('0042f0a0','?loadIcon@@')]:
 target,tr,_=match.target('2008-06',addr);name,b,refs=next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith(prefix));assert match.exact_match(target,tr,b,refs), name; methods.append(dict(address=addr,symbol=name,size=len(b)))
# Separate TU keeps the historical getter call visible to the icon compiler.
getter = out / 'NativeFrameIconWidth.cpp'
getter.write_text('#include <afxwin.h>\n#include <roc_espeon_nativeatlimagewidthdecl2e5804ac680a6dd9.cpp>\nint ATL::CImage::GetWidth() const throw() { return m_nWidth; }\n', encoding='utf8')
getter_body = libs.preprocess(21022, getter, include, r['defines'], [])
getter_translation = out / 'NativeFrameIconWidthPreprocessed.cpp'
getter_translation.write_text(getter_body, encoding='utf8')
getter_flags = ['/nologo', '/c', '/O2', '/GS-', '/EHsc', '/MD', '/FoNativeFrameIconWidth.obj', str(getter_translation)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', getter_flags, out)
assert code == 0, log
getter_obj = (out / 'NativeFrameIconWidth.obj').read_bytes()
target, tr, _ = match.target('2008-06', '00442c80')
name, b, refs = next((n,b,r) for n,b,r in match.coff_functions(getter_obj) if n.startswith('?GetWidth@CImage@ATL@@'))
assert match.exact_match(target, tr, b, refs)
methods.append(dict(address='00442c80', symbol=name, size=len(b)))
assert any(p.name==alias.name for p in map(Path,deps))
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
paths=[header,source,ROOT/'roc/libs.py',Path(__file__).resolve()]
receipt=dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),sources={str(p.relative_to(ROOT)):sha(p) for p in paths},reconstructed_alias_sha256=sha(alias),compiler_build=21022,flags=flags,methods=methods,scope='Fresh rebuild with reconstructed ATL alias and separately compiled GetWidth; historical alias bytes, full relocation targets and runtime integration remain unverified.')
output=ROOT/'work/2008-06/shared-layouts/frame-icons-fresh-working-probe.json';output.write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('PASS: fresh reconstructed ATL alias produces five relocation-masked matches')
