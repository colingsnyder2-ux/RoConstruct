"""Verify inactive typed frame-pane marshalling layouts and recovered bodies."""
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
TESTS = ROOT / 'rebuild/2008-06/tests'
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
recipe = libs.RECIPES['rbxgs']
flags = ['/nologo', '/c', '/O2', '/GS-', '/EHsc', '/MD', '/D_AFXDLL', '/DNDEBUG', '/D_MBCS',
         '/DBOOST_ALL_NO_LIB', '/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK',
         '/I' + str(HEADERS), '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include'),
         '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source')]
flags += ['/I' + str((libs.LIBS / i).resolve()) for i in recipe['include'] if i != 'WINSDK']

methods = []
for name, source, fixture, targets in (
    ('MarshalWindow', CLASSES / 'CMarshalWindow.cpp', TESTS / 'NativeMarshalWindowLayout.cpp', (
        ('00432c50', '??0CMarshalWindow'), ('00432950', '?post@CMarshalWindow'),
        ('004328c0', '??0CCriticalSection@ATL'), ('00432a70', '?OnFinalMessage@CMarshalWindow'),
        ('00432970', '?OnDestroy@CMarshalWindow'), ('00432a90', '?ProcessWindowMessage@CMarshalWindow'),
        ('0041a400', '?GetWindowProc@?$CWindowImplBaseT'), ('00432b10', '??_GCMarshalWindow'))),
    ('MarshaledListener', TESTS / 'NativeMarshaledListener.cpp', None, (
        ('004661e0', '??0?$MarshaledListener'), ('004663c0', '??1?$MarshaledListener'))),
    ('SelectionCaption', CLASSES / 'CSelectionCaption.cpp', TESTS / 'NativeSelectionCaptionLayout.cpp', (
        ('00466880', '??0CSelectionCaption'), ('00465de0', '?GetRuntimeClass@CSelectionCaption'),
        ('00466670', '?filter@CSelectionCaption'))),
):
    translation = OUT / (name + 'LayoutProbe.cpp')
    body = '#include "' + source.as_posix() + '"\n'
    if fixture:
        body += '#include "' + fixture.as_posix() + '"\n'
    translation.write_text(body, encoding='utf8')
    obj = OUT / ('Native' + name + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(translation)], OUT)
    assert code == 0, log
    functions = match.coff_functions(obj.read_bytes())
    for address, prefix in targets:
        symbol, data, refs = next((n,b,r) for n,b,r in functions if n.startswith(prefix))
        target, target_refs, _ = match.target('2008-06', address)
        exact = match.exact_match(target, target_refs, data, refs)
        assert exact or address == '00432970', (address, symbol, len(data), len(target))
        methods.append(dict(address=address, symbol=symbol, size=len(data), target_size=len(target),
                            object=obj.name, relocation_masked_match=exact))

paths = [Path(__file__), CLASSES / 'CMarshalWindow.cpp', CLASSES / 'CSelectionCaption.cpp',
         HEADERS / 'util/MarshalWindow.h', HEADERS / 'util/MarshaledListener.h',
         HEADERS / 'util/EventDataBase.h', HEADERS / 'CSelectionCaption.h', HEADERS / 'ActiveDocView.h',
         TESTS / 'NativeMarshalWindowLayout.cpp', TESTS / 'NativeMarshaledListener.cpp',
         TESTS / 'NativeSelectionCaptionLayout.cpp']
receipt = dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
               sources={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},
               compiler_build=21022, flags=flags, methods=methods,
               layouts=dict(CMarshalWindow=0x44, EventDataBase=0xc, MarshaledListener=0x24,
                            FilteredListener=0x24, CSelectionCaption=0x1c8),
               scope='Inactive recovery. Native layout/lifecycle evidence only. OnDestroy is nonexact; weak pointee identity, dispatch/filter behavior, complete caption virtual/message ABI, globals and runtime integration remain open.')
(ROOT / 'work/2008-06/shared-layouts/frame-marshalling-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('Frame marshalling: %d/%d body matches; five typed layouts verified' %
      (sum(m['relocation_masked_match'] for m in methods),len(methods)))
