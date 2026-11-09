"""Exercise recovered window/registry code without the adapted game shell."""
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild

OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
PROBE = ROOT / 'work/2008-06/shared-layouts/frame-marshalling-working-probe.json'
subprocess.run([sys.executable, str(Path(__file__).with_name('record_native_frame_marshalling.py'))],
               cwd=ROOT, check=True)
probe = json.loads(PROBE.read_text())
source = Path(__file__).with_name('NativeMarshalWindowRuntime.cpp')
flags = probe['flags'] + ['/FoNativeMarshalWindowRuntime.obj', str(source)]
tc = rebuild.toolchain(21022)
code, log = rebuild.run(tc, 'cl', flags, OUT)
assert code == 0, log
link_flags = ['/nologo', '/SUBSYSTEM:CONSOLE', '/MACHINE:X86',
              '/OUT:NativeMarshalWindowRuntime.exe', '/MAP:NativeMarshalWindowRuntime.map',
              '/MANIFEST', 'NativeMarshalWindowRuntime.obj', 'NativeMarshalWindow.obj',
              'NativeMarshalWindowRegistry.obj', 'kernel32.lib', 'user32.lib', 'advapi32.lib']
code, log = rebuild.run(tc, 'link', link_flags, OUT)
assert code == 0, log
exe = OUT / 'NativeMarshalWindowRuntime.exe'
mapping = OUT / 'NativeMarshalWindowRuntime.map'
addresses = {m[1]: int(m[2], 16) for m in re.finditer(
    r'^\s+[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s',
    mapping.read_text(), re.M)}
pe = pefile.PE(str(exe))
linked = []
for row in probe['methods']:
    if row['object'] not in ('NativeMarshalWindow.obj', 'NativeMarshalWindowRegistry.obj'):
        continue
    symbol = row['symbol']
    assert symbol in addresses, symbol
    obj = (OUT / row['object']).read_bytes()
    _, body, refs = next((n, b, r) for n, b, r in match.coff_functions(obj) if n == symbol)
    running = pe.get_data(addresses[symbol] - pe.OPTIONAL_HEADER.ImageBase, len(body))
    assert match.exact_match(body, refs, running, refs), symbol
    target, target_refs, _ = match.target('2008-06', row['address'])
    exact = match.exact_match(target, target_refs, running, refs)
    assert exact == row['relocation_masked_match'], symbol
    linked.append(dict(symbol=symbol, original=row['address'], linked_va=hex(addresses[symbol]),
                       relocation_masked_match=exact))
runs = []
for _ in range(3):
    result = subprocess.run([str(exe)], cwd=OUT, capture_output=True, text=True,
                            timeout=20, creationflags=subprocess.CREATE_NO_WINDOW)
    assert result.returncode == 0, (result.returncode, result.stdout, result.stderr)
    assert result.stdout.strip() == 'executed=2 deleted=4 registry=0', result.stdout
    runs.append(dict(exit=result.returncode, stdout=result.stdout.strip()))
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
sources = dict(probe['sources'])
sources.update({str(p.relative_to(ROOT)): sha(p) for p in (source, Path(__file__))})
receipt = dict(revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               sources=sources, compiler=21022, compile_flags=flags, link_flags=link_flags,
               exe_sha256=sha(exe), map_sha256=sha(mapping), probe_sha256=sha(PROBE),
               linked_methods=linked, runs=runs,
               scope='Isolated native CMarshalWindow and registry runtime: hidden windows, per-thread reuse, '
                     'reference counts, dispatch, destruction of queued events, and empty registry. '
                     'Fixture event is diagnostic. OnDestroy remains nonexact. Does not prove Selection '
                     'payload delivery, P5/P6, game integration, or original global initialization.')
(ROOT / 'work/2008-06/shared-layouts/marshal-runtime-working-probe.json').write_text(
    json.dumps(receipt, indent=2) + '\n')
print('PASS: native hidden windows, two threads, dispatch/queued cleanup, empty registry; 3 runs')
