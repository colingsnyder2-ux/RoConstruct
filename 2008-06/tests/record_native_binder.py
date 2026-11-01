"""Compile shared binder layout without changing the active client ABI."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild

out = ROOT / 'rebuild/2008-06/out/native-layouts'
out.mkdir(parents=True, exist_ok=True)
source = ROOT / 'rebuild/2008-06/tests/NativeBinderLayout.cpp'
header = ROOT / 'rebuild/2008-06/native-headers/VerbBinder.h'
flags = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
         '/DWIN32', '/DNDEBUG', '/D_MBCS', '/D_AFXDLL',
         '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include'),
         '/FoNativeBinderLayout.obj', str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
(out / 'compile.log').write_text(log)
assert code == 0, log

original = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
pe = pefile.PE(str(original), fast_load=True)
target, relocations, row = match.target('2008-06', '00451590')
assert target == pe.get_data(0x451590 - pe.OPTIONAL_HEADER.ImageBase, len(target))
symbol = '??0?$VerbBinder@VCRobloxDoc@@VCDocument@@@@QAE@XZ'
body, candidate_relocations = next((body, relocs) for name, body, relocs in
    match.coff_functions((out / 'NativeBinderLayout.obj').read_bytes()) if name == symbol)
assert match.exact_match(target, relocations, body, candidate_relocations)
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               compiler_build='21022', flags=flags, compile_exit=code,
               sources={str(path.relative_to(ROOT)): sha(path) for path in (source, header, Path(__file__))},
               original_sha256=sha(original), object_sha256=sha(out / 'NativeBinderLayout.obj'),
               compile_log_sha256=sha(out / 'compile.log'),
               static_size_gates=dict(CDocument=0x54, CView=0x58, DocumentBinder=0x74, ViewBinder=0x78),
               constructor=dict(address='00451590', symbol=symbol, size=len(body),
                                relocation_normalized_exact=True, target_relocations=relocations,
                                candidate_relocations=candidate_relocations),
               active_client_changed=False,
               scope='Compiler-only shared binder size and constructor proof. OnCmdMsg remains declared for later recovery; its explicit-instantiation warnings are expected. No active class swap, linked-function increase or server verification is claimed.')
output = ROOT / 'work/2008-06' / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: four native size gates; document binder constructor 00451590 exact (86 bytes, relocations masked).')
