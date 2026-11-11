"""Verify and harvest only the two native Axis render bodies. Never run a client."""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import delink, match, native_work, rebuild

REFERENCES = {
    '?getCoordinateFrame@GCamera@G3D@@QBE?AVCoordinateFrame@2@XZ': 0x5107b0,
    '?inf@Vector3@G3D@@SAABV12@XZ': 0x510960,
    '??0Matrix3@G3D@@QAE@ABV01@@Z': 0x513220,
    '?identity@Matrix3@G3D@@SAABV12@XZ': 0x513e20,
    '?orange@Color3@G3D@@SAABV12@XZ': 0x5149b0,
    '?bounds@AxisMoveTool@RBX@@AAE_NAAVExtents@2@@Z': 0x640b40,
    '?handles3d@DrawAdorn@RBX@@SAXABVVector3@G3D@@ABVCoordinateFrame@4@PAVAdorn@2@W4HandleType@2@0@Z': 0x6776a0,
    '?handles2d@DrawAdorn@RBX@@SAXABVVector3@G3D@@ABVCoordinateFrame@4@ABVGCamera@4@PAVAdorn@2@ABVColor3@4@@Z': 0x677b20,
    '__real@3f000000': 0x819bac,
}


def reference_map(raw, symbol, address, expected):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    body, offsets = next((b, r) for n, b, r in match.coff_functions(raw) if n == symbol)
    target, original_offsets, _ = match.target('2008-06', '%08x' % address)
    assert match.exact_match(target, original_offsets, body, offsets), 'body changed'
    table, found, covered = sections[section], {}, set()
    for i in range(table[7]):
        position, index, kind = struct.unpack_from('<IIH', raw, table[5] + i * 10)
        at = position - start
        if not 0 <= at < len(body):
            continue
        assert at + 4 <= len(body) and kind in (6, 20), 'unsupported relocation'
        assert kind != 6 or at in original_offsets, 'unrelocated original pointer'
        original = struct.unpack_from('<I', target, at)[0] if kind == 6 else (
            address + at + 4 + struct.unpack_from('<i', target, at)[0]) & 0xffffffff
        value = (original - struct.unpack_from('<i', body, at)[0]) & 0xffffffff
        name = symbols[index][0]
        assert expected.get(name) == value, (name, hex(value), expected.get(name))
        found[name] = '%08x' % value
        covered.add(at)
    assert set(original_offsets) <= covered, 'missing original relocation'
    return found


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path)
    args = parser.parse_args()
    out = (args.out or ROOT / ('work/2008-06/axis-render-proof-' + str(time.time_ns()))).resolve()
    out.mkdir(parents=True, exist_ok=False)
    spec = importlib.util.spec_from_file_location('axis_check_runner', Path(__file__).with_name('native_check_runner.py'))
    runner = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(runner)
    tc = rebuild.toolchain(21022)
    job = {'source': str(ROOT / 'rebuild/2008-06/native-classes/AxisMoveToolRender.cpp'),
           'checks': [{'addr': '00640f30', 'symbol': '?render2d@AxisMoveTool@'},
                      {'addr': '00641040', 'symbol': '?render3dAdorn@AxisMoveTool@'}], 'ranges': [], 'layouts': []}
    result = runner.compile_job(job, out / 'compile', tc)
    native_work.log_checks(out, job, result)
    assert result['status'] == 'complete', result.get('error')
    assert all(c['status'] == 'exact' and 'data_errors' in c and not c['data_errors']
               for c in result['checks']), result['checks']
    raw, bindings, allowed = Path(result['object']).read_bytes(), {}, {}
    for check in result['checks']:
        address = int(check['addr'], 16)
        bindings[check['symbol']] = reference_map(raw, check['symbol'], address, REFERENCES)
        allowed[check['symbol']] = address
    assert set().union(*(set(row) for row in bindings.values())) == set(REFERENCES)
    wrong = dict(REFERENCES)
    wrong['?bounds@AxisMoveTool@RBX@@AAE_NAAVExtents@2@@Z'] += 4
    try:
        reference_map(raw, result['checks'][0]['symbol'], 0x640f30, wrong)
    except AssertionError:
        pass
    else:
        raise AssertionError('wrong-call negative control passed')
    selection = delink.bind_objects('2008-06', [result['object']], sorted(allowed.values()), {}, out,
                                   allowed={str(Path(result['object']).resolve()): allowed})
    assert not selection['problems'] and not selection['ambiguous'], selection
    assert set(map(tuple, selection['swaps'])) == {(v, k) for k, v in allowed.items()}
    assert {n for p in selection['objects'] for n, _, _ in match.coff_functions(Path(p).read_bytes())} == set(allowed)
    math_source = Path(__file__).with_name('NativeAxisVectorNegation.cpp')
    flags = ['/nologo', '/O2', '/fp:fast', '/EHsc', '/MT',
             '/I' + str(ROOT / 'rebuild/2008-06/native-headers/axis-vector-negation'),
             '/I' + str(ROOT / 'tools/libs/g3d-6.09/source/include'),
             '/Fo' + str(out / 'math.obj'), '/Fe' + str(out / 'math.exe'), str(math_source)]
    code, log = rebuild.run(tc, 'cl', flags, out)
    (out / 'math-compile.log').write_text(log, encoding='utf-8')
    assert code == 0, log[-2000:]
    # This fixture only tests vector math; it never loads or runs the client.
    test = subprocess.run([str(out / 'math.exe')], cwd=out, capture_output=True, text=True, timeout=15)
    assert test.returncode == 0, test.stdout + test.stderr
    assert all(runner.sha(Path(p)) == h for p, h in result['dependencies'].items()), 'input drift'
    receipt = {'scope': 'Inactive exact renderer harvest. No full class ABI, client runtime, P5/P6 or server proof.',
               'compile': result, 'references': bindings, 'selection': selection,
               'wrong_call_rejected': True, 'math': test.stdout.strip(),
               'math_source_sha256': runner.sha(math_source),
               'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
               'original_sha256': runner.sha(ROOT / 'clients/2008-06/Roblox.exe')}
    (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'out': str(out), 'exact_renderers': 2, 'bound_symbols': len(REFERENCES),
                      'wrong_call_rejected': True, 'math': receipt['math'], 'scope': receipt['scope']}))


if __name__ == '__main__':
    main()
