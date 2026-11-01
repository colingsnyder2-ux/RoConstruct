"""Verify typed pane lifecycle, document/selection callbacks and caption text."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild

OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
recipe = libs.RECIPES['rbxgs']
flags = ['/nologo', '/O2', '/GS-', '/EHsc', '/MD', '/D_AFXDLL', '/DNDEBUG', '/D_MBCS',
         '/DBOOST_ALL_NO_LIB', '/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK',
         '/I' + str(HEADERS), '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include'),
         '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source')]
flags += ['/I' + str((libs.LIBS / i).resolve()) for i in recipe['include'] if i != 'WINSDK']
methods = []
for name, targets in (
    ('ActiveDocViewRefresh', (('00420bd0', '?refresh@ActiveDocView'),)),
    ('CDataModelPropGridUpdate', (('00442900', '?update@CDataModelPropGrid'),)),
    ('CSelectionCaptionUpdate', (('00466940', '?update@CSelectionCaption'), ('00466510', '??1CSelectionCaption'))),
    ('CSelectionCaption', (('00466880', '??0CSelectionCaption'), ('00465de0', '?GetRuntimeClass@CSelectionCaption'),
                           ('00466670', '?filter@CSelectionCaption'), ('00465df0', '?PreCreateWindow@CSelectionCaption'),
                           ('00466680', '?Create@CSelectionCaption'), ('00465e00', '?OnCreate@CSelectionCaption'),
                           ('004666b0', '?onMarshaledEvent@CSelectionCaption'), ('00465e30', '?GetMessageMap@CSelectionCaption'))),
    ('CSelectionCaptionText', (('00465e40', '?updateCaption@CSelectionCaption'),)),
):
    source = CLASSES / (name + '.cpp')
    obj = OUT / ('Native' + name + '.obj')
    compile_flags = flags + ['/c', '/Fo' + str(obj), str(source)]
    if name == 'CSelectionCaptionText':
        code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/P', str(source)], OUT)
        assert code == 0, log
        body = (OUT / (name + '.i')).read_text(encoding='utf8', errors='replace')
        for needle in ('\t basic_string()', '~basic_string()', 'const _Elem * c_str() const',
                       'operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );'):
            assert body.count(needle) == 1, needle
            body = body.replace(needle, '__declspec(noinline) ' + needle)
        translation = OUT / 'NativeSelectionCaptionText.cpp'
        translation.write_text(body, encoding='utf8')
        compile_flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
                         '/Fo' + str(obj), str(translation)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', compile_flags, OUT)
    assert code == 0, log
    functions = match.coff_functions(obj.read_bytes())
    for address, prefix in targets:
        symbol, body, refs = next((n,b,r) for n,b,r in functions if n.startswith(prefix))
        target, target_refs, _ = match.target('2008-06', address)
        assert match.exact_match(target, target_refs, body, refs), (address, symbol)
        methods.append(dict(address=address, symbol=symbol, size=len(body), object=obj.name,
                            relocation_masked_match=True))

paths = [Path(__file__), HEADERS / 'ActiveDocView.h', HEADERS / 'CSelectionCaption.h',
         HEADERS / 'v8tree/Service.h', HEADERS / 'v8datamodel/Selection.h',
         HEADERS / 'v8datamodel/SelectionChanged.h']
paths += [CLASSES / (name + '.cpp') for name in ('ActiveDocViewRefresh', 'CDataModelPropGridUpdate', 'CSelectionCaptionUpdate',
                                               'CSelectionCaption', 'CSelectionCaptionText')]
receipt = dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
               sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, methods=methods,
               scope='Inactive typed recovery. Native caption uses AbstractFactoryProduct::getClassName/Name, not the mined fake reflection descriptor. Full bindings/message data, marshal framework, ActiveDocView refresh/globals and runtime remain open.')
(ROOT / 'work/2008-06/shared-layouts/pane-callbacks-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('Pane callbacks: %d recovered bodies match; no runtime credit' % len(methods))
