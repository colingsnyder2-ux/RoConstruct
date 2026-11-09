"""Verify the inactive native CScriptDoc (CNullDoc subclass holding the edited script): layout test and its 4 exact
bodies with every call/data target (GetRuntimeClass, CreateObject, destructor, deleting destructor).
Profile: plain document-swap flags (VS2008 RTM). CScriptDoc has no message map of its own (slot 12 is CNullDoc's
GetMessageMap 00433360); _GetBaseClass is the shared jump thunk 0040df90 -> CNullDoc::GetRuntimeClass 004332e0,
so it is not a CScriptDoc row. Writes work/2008-06/shared-layouts/script-doc-working.json.
"""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from native_bind import ROOT, Original, compile_unit, flags, sha, verify  # noqa: E402

source = ROOT / 'rebuild/2008-06/native-classes/CScriptDoc.cpp'
fixture = ROOT / 'rebuild/2008-06/tests/NativeScriptDocLayout.cpp'
compile_unit(fixture, 'NativeScriptDocLayout')
obj = compile_unit(source, 'NativeScriptDocProfile')
original = Original()
methods = [
    ('?GetRuntimeClass@CScriptDoc@@UBEPAUCRuntimeClass@@XZ', 0x004638a0),
    ('??_GCScriptDoc@@UAEPAXI@Z', 0x004646f0),
    ('??1CScriptDoc@@UAE@XZ', 0x00464670),
    ('?CreateObject@CScriptDoc@@SGPAVCObject@@XZ', 0x004647b0),
]
internal = {'?classCScriptDoc@CScriptDoc@@2UCRuntimeClass@@B': 0x0081b1ec}
rows = verify(original, obj, methods, internal)
paths = [Path(__file__).resolve(), ROOT / 'rebuild/2008-06/tests/native_bind.py', source, fixture,
         ROOT / 'rebuild/2008-06/native-headers/CScriptDoc.h', ROOT / 'rebuild/2008-06/native-headers/CBrowserDoc.h']
(ROOT / 'work/2008-06/shared-layouts/script-doc-working.json').write_text(json.dumps({
    'class': 'CScriptDoc', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags(),
    'profile': 'document-swap flags, no noinline edits',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj),
    'layout': {'size': '0x5c', 'bases': 'CNullDoc +0 (0x54 == CDocument)', 'members': 'boost::shared_ptr<RBX::Script> script +0x54',
               'evidence': 'RTTI of vtable 0081b2ac; CRuntimeClass 0081b1ec and CreateObject operator new(0x5c); '
                           'CreateObject 004647b0 stores +0x54/+0x58; destructor 00464670 releases +0x58; compile-time sizeof/offsetof test'},
    'methods': rows,
    'notes': ['CNullDoc::CNullDoc is inline in the original (CreateObject calls CDocument::CDocument directly); '
              'CBrowserDoc.h declares it without a body, so CScriptDoc.cpp supplies the empty inline body',
              '_GetBaseClass is the shared jump thunk 0040df90 (also used by CBrowserDoc), not a compiled body'],
    'scope': 'Inactive. 4 exact bodies with verified targets; all CScriptDoc-owned functions. No active build, swap or credit.'},
    indent=2) + '\n')
print('PASS native CScriptDoc: %d exact bodies, targets verified' % len(rows))
