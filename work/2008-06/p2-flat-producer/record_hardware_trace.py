"""Trace native component identity without changing target code bytes."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import rebuild


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def record():
    parent = Path(__file__).resolve().parent
    build = parent / 'hardware-trace-build'
    build.mkdir(exist_ok=True)
    tc = rebuild.toolchain(21022)
    args = ['/nologo', '/O2', '/GS-', '/EHsc', '/MD', str(parent / 'trace_player.cpp'),
            '/Fe' + str(build / 'trace_player.exe'), '/link', 'kernel32.lib']
    code, log = rebuild.run(tc, 'cl', args, build)
    (build / 'build.log').write_text(log + '\n')
    assert code == 0, log
    binary = ROOT / 'rebuild/2008-06/out/tests/P2RecoveredPlayer/P2RecoveredPlayer.exe'
    rows = [re.match(r'\s+\w{4}:\w{8}\s+(\S+)\s+([0-9a-fA-F]{8})\b', line) for line in binary.with_suffix('.map').read_text().splitlines()]
    keys = ['?populate@BlockMesh@PlayerBlockMesh@@', '?upload@Level@PlayerBlockMesh@@',
            '?createSubEntity@RbxEntity@Ogre@@', '??1RbxEntity@Ogre@@', '?getRenderOperation@RbxSubEntity@Ogre@@']
    selected = {}
    for key in keys:
        found = [(m.group(1), m.group(2)) for m in rows if m and m.group(1).startswith(key)]
        assert len(found) == 1, (key, found)
        selected[key] = {'symbol': found[0][0], 'address': found[0][1]}
    output = parent / 'native-operation-hardware-trace'
    output.mkdir(exist_ok=False)
    env = os.environ.copy()
    env.pop('ROC_BUILD', None)
    asset = ROOT / 'work/client2007/content/textures/SurfacesStrip.png'
    env['ROC_TEXTURE_STRIP'] = str(asset)
    before = sha(binary)
    command = [str(build / 'trace_player.exe'), str(binary)] + [selected[key]['address'] for key in keys]
    with (output / 'stdout.txt').open('w') as stream:
        result = subprocess.run(command, cwd=output, env=env, stdout=stream, stderr=subprocess.STDOUT, timeout=65)
    assert result.returncode == 0, result.returncode
    assert sha(binary) == before, 'Target EXE changed'
    text = (output / 'stdout.txt').read_text()
    events = []
    for line in text.splitlines():
        if not line.startswith('TRACE_'):
            continue
        fields = dict(re.findall(r'(\w+)=([0-9a-f]+)', line))
        events.append({'event': line.split()[0], **fields})
    def one(kind):
        matches = [e for e in events if e['event'] == kind]
        assert len(matches) == 1, (kind, matches)
        return matches[0]
    producers = [e for e in events if e['event'] == 'TRACE_PRODUCER_RETURN']
    assert len(producers) == 2 and [e['levels'] for e in producers] == ['1', '2']
    assert producers[0]['mesh'] == producers[1]['mesh'] and producers[0]['level0'] == producers[1]['level0'] != '00000000'
    assert producers[1]['level1'] not in ('00000000', producers[0]['level0'])
    assert one('TRACE_UPLOAD_ENTRY')['receiver'] == producers[0]['level0']
    upload, created, returned, operation, destroyed = [one(k) for k in ('TRACE_UPLOAD_RETURN', 'TRACE_ENTITY_CREATE', 'TRACE_ENTITY_CREATED', 'TRACE_RENDER_OPERATION', 'TRACE_ENTITY_DESTROY')]
    assert upload['level'] == producers[0]['level0']
    assert upload['backend'] == created['submesh'] == operation['submesh'] != '00000000'
    assert created['entity'] == returned['entity'] == destroyed['entity'] != '00000000'
    assert returned['subentity'] == operation['subentity'] != '00000000'
    assert created['lod'] == operation['lod'] == '0'
    assert one('TRACE_EXIT')['code'] == '0'
    assert all(e['code'] == '406d1388' for e in events if e['event'] == 'TRACE_EXCEPTION')
    pixels = json.loads((output / 'selftest_result.json').read_text())
    assert pixels['failures'] == 0
    assert 'mesh cleanup: levels=0 refs=0 backends=0 spheres=0' in text
    report = ROOT / 'rebuild/2008-06/out/P2RecoveredPlayer/report.json'
    assert '00684fd0' in json.loads(report.read_text())['owned_addrs']
    receipt = {
        'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
        'command': command, 'exit': result.returncode, 'ROC_BUILD': env.get('ROC_BUILD'),
        'target_exe_sha256_before_and_after': before, 'map_sha256': sha(binary.with_suffix('.map')),
        'debugger_sha256': sha(build / 'trace_player.exe'), 'debugger_source_sha256': sha(parent / 'trace_player.cpp'),
        'compiler_sha256': sha(tc['cl']), 'asset_sha256': sha(asset), 'selected_symbols': selected,
        'events': events, 'pixels': pixels, 'report_sha256': sha(report),
        'method': 'DR0..DR3 execution breakpoints, retargeted to return sites; no target code bytes patched',
        'proof': 'Same Mesh produces level0; same Level uploads same SubMesh used by created child and actual render-op; same parent entity destroyed.',
        'limits': ['Rebuilt selftest trace, not original client execution.', '406d1388 is forwarded first-chance MSVC thread-name exception.', 'Local report identifies00684fd0; no new server-verified exact credit.'],
    }
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print('PASS: hardware-observed Mesh -> Level0 -> SubMesh -> SubEntity render-op -> Entity teardown')


if __name__ == '__main__':
    record()
