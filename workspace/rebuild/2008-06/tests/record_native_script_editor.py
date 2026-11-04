"""Verify the inactive native CScriptEditor (Scintilla view): layout test and 51 exact bodies with their targets.

The original imports CString PCXSTR, std::string c_str and size, so the unit is preprocessed and those three RTM
definitions are marked noinline (the same profile family as record_native_save_dialog.py). Scintilla MFC 1.20
headers come from tools/libs/scintilla-mfc-1.20. Internal call/data targets listed in
record_native_script_editor.json were bound from the original call/data operands; native_bind.verify re-checks
every one of them plus imports, literals, type descriptors and vtables (RTTI). reload 00465550 matches as a
668-byte raw range but the analysed extent stops at its catch funclet (493 bytes): bounds evidence, not listed.
Writes work/2008-06/shared-layouts/script-editor-working.json.
"""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from native_bind import OUT, ROOT, Original, compile_unit, flags, rebuild, sha, verify  # noqa: E402

side = json.loads(Path(__file__).with_name('record_native_script_editor.json').read_text())
source = ROOT / 'rebuild/2008-06/native-classes/CScriptEditor.cpp'
fixture = ROOT / 'rebuild/2008-06/tests/NativeScriptEditorLayout.cpp'
scintilla = ['/I' + str(ROOT / 'tools/libs/scintilla-mfc-1.20')]
compile_unit(fixture, 'NativeScriptEditorLayout', scintilla)
pre = OUT / 'script-editor-pre'
pre.mkdir(parents=True, exist_ok=True)
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', [x for x in flags() if x != '/c'] + scintilla + ['/P', str(source)], pre)
assert code == 0, log
body = (pre / 'CScriptEditor.i').read_text(errors='replace')
for needle in ('operator PCXSTR() const throw()\n\t{\n\t\treturn( m_pszData );', 'const _Elem * c_str() const', 'size_type  size() const'):
    assert body.count(needle) == 1, needle
    body = body.replace(needle, '__declspec(noinline) ' + needle)
unit = OUT / 'NativeScriptEditorProfile.cpp'
unit.write_text(body)
obj = OUT / 'NativeScriptEditorProfile.obj'
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
                                                       '/Fo' + str(obj), str(unit)], OUT)
assert code == 0, log[-3000:]
original = Original()
methods = [(name, int(address, 16)) for name, address in side['methods']]
internal = {name: int(address, 16) for name, address in side['internal'].items()}
rows = verify(original, obj, methods, internal)
headers = ['CScriptEditor.h', 'v8datamodel/DataModel.h', 'v8tree/Instance.h']
paths = [Path(__file__), Path(__file__).with_name('record_native_script_editor.json'), ROOT / 'rebuild/2008-06/tests/native_bind.py',
         source, fixture] + [ROOT / 'rebuild/2008-06/native-headers' / h for h in headers]
(ROOT / 'work/2008-06/shared-layouts/script-editor-working.json').write_text(json.dumps({
    'class': 'CScriptEditor', 'compiler': 'MSVC 15.00.21022 (VS2008 RTM)', 'flags': flags() + scintilla,
    'profile': 'noinline CString PCXSTR, std::string c_str and size (original imports them)',
    'original_sha256': sha(original.path),
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p) for p in paths}, 'object_sha256': sha(obj),
    'layout': {'size': '0x160', 'bases': 'Scintilla::CScintillaView +0 (0xec), Listener<Instance,AncestorChanged> +0xec, MarshaledListener<Instance,PropertyChanged> +0xf0, MarshaledListener<RunService,RunState> +0x114',
               'members': 'mutex shared_ptr +0x138, frame +0x140, script +0x144, runService +0x14c, bools +0x154..0x156, CFont +0x158',
               'evidence': 'CRuntimeClass 0081b208 and CreateObject operator new(0x160); RTTI COL offsets; constructor 00465010 and destructor 00465830; compile-time sizeof/offsetof test'},
    'methods': rows,
    'bounds': ['reload 00465550: 668-byte body matches the raw image with relocations masked; the analysed extent ends at the catch funclet 0046573d (493 bytes)'],
    'open': ['marshal 00465110 and the MarshaledListener<Instance,PropertyChanged> onEvent/marshal templates 004649f0/00464ea0: the original copies PropertyChanged inline; matching needs PropertyChanged/Property copy-constructor declarations that differ from the shared headers (not changed)'],
    'scope': 'Inactive. 51 exact bodies with verified targets; DataModel::getMutex and Instance::desc_Name declarations added to shared headers. No active build, swap or credit.'},
    indent=2) + '\n')
print('PASS native CScriptEditor: %d exact bodies, targets verified' % len(rows))
