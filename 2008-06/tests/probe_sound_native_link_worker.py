"""Frozen, incompatible-ABI diagnostic only; never run the linked output."""
import hashlib
import json
import re
import shutil
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(root))
from roc import rebuild

out = root / 'rebuild/2008-06/out'
work = out / 'native-layouts/sound-native-link-frozen-worker'
work.mkdir(parents=True, exist_ok=True)
sound = out / 'native-layouts/sound-migration-isolated-worker'
names = ('PlayerNativeSound', 'PlayerNativeSoundService', 'PlayerNativeSoundGC',
         'PlayerNativeSoundChannel', 'PlayerNativeSoundReflection', 'PlayerNativeReverb', 'PlayerNativeSoundStats')
inputs = [out / 'tests/P4SoundAssetTest/P4SoundAssetTest.obj'] + [sound / (name + '.obj') for name in names]
inputs += [out / name / 'linked/linked.lib' for name in ('RbxgsApp', 'G3D', 'G3D-GL', 'Boost', 'RakNet', 'libpng')]
inputs += [out / 'importlibs/fmodex.lib']
copied = []
hashes = {}
for index, src in enumerate(inputs):
    dst = work / ('%02d_' % index + src.name)
    shutil.copyfile(src, dst)
    digest = hashlib.sha256(dst.read_bytes()).hexdigest()
    assert digest == hashlib.sha256(src.read_bytes()).hexdigest(), src
    hashes[str(src.relative_to(root))] = digest
    copied.append(str(dst))
args = ['/nologo', '/SUBSYSTEM:CONSOLE', '/MACHINE:X86', '/MAP:probe.map', '/OUT:probe.exe'] + copied
args += ['kernel32.lib', 'user32.lib', 'gdi32.lib', 'advapi32.lib', 'shell32.lib', 'ole32.lib',
         'oleaut32.lib', 'comdlg32.lib', 'ws2_32.lib', 'winmm.lib', 'opengl32.lib', 'glu32.lib',
         'imagehlp.lib', 'version.lib', 'wininet.lib', 'dbghelp.lib', 'psapi.lib']
args += ['/NODEFAULTLIB:' + lib for lib in rebuild.VENDOR_AUTOLINK]
code, log = rebuild.run(rebuild.toolchain(21022), 'link', args, work)
(work / 'probe.log').write_text(log, encoding='utf-8')
errors = [line.strip() for line in log.splitlines() if re.search(r'\berror LNK\d+', line)]
receipt = {'scope': 'Frozen diagnostic linking native-first sound objects to donor-ABI test and libraries. Never run; incompatible ABI and transitive closure unproven.',
           'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
           'inputs': hashes, 'link_exit': code, 'errors': errors, 'flags': args}
target = root / 'work/2008-06/shared-layouts/sound-native-link-frozen-worker.json'
target.write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
print('link exit', code, 'errors', len(errors), 'receipt', target)
