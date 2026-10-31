"""Normal-process regressions for the measured sphere-cache and owner lifetime."""
import hashlib
import json
import os
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[3]


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def record():
    output = Path(__file__).with_name('sphere-unit-runtime')
    output.mkdir(exist_ok=True)
    env = os.environ.copy()
    env.pop('ROC_BUILD', None)
    receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
               'ROC_BUILD': env.get('ROC_BUILD'), 'runs': {}}
    for test, module in [('P2MeshBackendTest', 'P2MeshBackend'), ('P2BlockMeshTest', 'P2BlockMesh'), ('P2BlockFactoryTest', 'P2BlockFactory')]:
        folder = output / test
        folder.mkdir(exist_ok=False)
        binary = ROOT / 'rebuild/2008-06/out/tests' / test / (test + '.exe')
        with (folder / 'stdout.txt').open('w') as stream:
            result = subprocess.run([str(binary)], cwd=folder, env=env, stdout=stream, stderr=subprocess.STDOUT, timeout=60)
        assert result.returncode == 0, (test, result.returncode)
        assert 'PASS:' in (folder / 'stdout.txt').read_text()
        mapping = binary.with_suffix('.map').read_text()
        selected = [s.strip() for s in mapping.splitlines() if any(k in s for k in ('?set@PlayerSphereCache@','?get@PlayerSphereCache@','?remove@PlayerSphereCache@','?has@PlayerSphereCache@'))]
        assert selected
        receipt['runs'][test] = {
            'command': [str(binary)], 'cwd': str(folder), 'exit': result.returncode,
            'exe_sha256': sha(binary), 'map_sha256': sha(binary.with_suffix('.map')),
            'report_sha256': sha(ROOT / 'rebuild/2008-06/out' / module / 'report.json'),
            'library_sha256': sha(ROOT / 'rebuild/2008-06/out' / module / 'linked/linked.lib'),
            'stdout_sha256': sha(folder / 'stdout.txt'), 'selected_symbols': selected,
            'runtime_dll_inputs': {name: sha(binary.parent / name) for name in ('rgmain.dll','rgdx.dll')},
        }
    sources = ['PlayerMeshBackend.cpp','PlayerMeshBackend.h','PlayerBlockMesh.cpp','P2MeshBackendTest.cpp','P2BlockMeshTest.cpp','P2BlockFactoryTest.cpp']
    receipt['source_sha256'] = {f'rebuild/2008-06/tests/{p}': sha(ROOT / 'rebuild/2008-06/tests' / p) for p in sources}
    receipt['coverage'] = ['Map insertion/update/reference stability/key zero/missing error/removal.',
                           '32 smooth/tiled block lifetimes, both index widths, retained owner preserves sphere until final destruction.',
                           '512 factory requests,120-key purge regression.']
    receipt['limits'] = ['Unit DLL inputs hashed; actual loaded DLL paths are traced separately in sphere-player-runtime.',
                         'Empty global container persists as in native initializer.', 'Shared-index and full node/scene integration remain open.']
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print('PASS: three normal-process sphere/mesh/factory regressions')


if __name__ == '__main__':
    record()
