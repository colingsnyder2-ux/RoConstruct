import json
import struct
import subprocess
import sys

import pytest

from roc import match, rebuild
from test_coff_data_index import object_bytes


@pytest.fixture
def native_target(monkeypatch, tmp_path):
    image = bytearray(256)
    image[:6] = b'\xb8' + struct.pack('<I', 0x500080) + b'\xc3'
    image[0x80:0x88] = b'abcdefgh'
    functions = {'00500000': {'size': 6, 'relocs': [1]}}
    relocations = set()
    monkeypatch.setattr(match, '_image', lambda client: (0x500000, bytes(image)))
    monkeypatch.setattr(match, '_functions', lambda client: functions)
    monkeypatch.setattr(match, '_base_relocs', lambda client: relocations)
    obj, cache = tmp_path / 'native.obj', tmp_path / 'cache.json'
    obj.write_bytes(object_bytes())
    return image, functions, relocations, obj, cache


def test_same_proof_reused_without_rematching(native_target, monkeypatch):
    _, _, _, obj, cache = native_target
    context = rebuild._ownership_context('test')
    expected = [('_f', 6, ['00500000'])]
    assert rebuild._ownership_rows('test', obj, cache, context) == (expected, False)
    def unexpected(*args):
        raise AssertionError('Unchanged proof should be reused')
    monkeypatch.setattr(rebuild, 'pair_object', unexpected)
    assert rebuild._ownership_rows('test', obj, cache, context) == (expected, True)


def test_object_data_change_rejects_previously_exact_function(native_target):
    _, _, _, obj, cache = native_target
    context = rebuild._ownership_context('test')
    assert rebuild._ownership_rows('test', obj, cache, context)[0][0][2] == ['00500000']
    obj.write_bytes(object_bytes().replace(b'abcdefgh', b'ABCDEFGH'))
    assert rebuild._ownership_rows('test', obj, cache, context) == ([('_f', 6, [])], False)


@pytest.mark.parametrize('changed', ['image', 'bounds', 'relocs', 'implementation'])
def test_target_and_loaded_matcher_changes_invalidate(native_target, monkeypatch, changed):
    image, functions, relocations, obj, cache = native_target
    before = rebuild._ownership_context('test')
    rebuild._ownership_rows('test', obj, cache, before)
    if changed == 'image':
        image[0x80] = ord('X')
    elif changed == 'bounds':
        functions['00500000']['size'] = 5
    elif changed == 'relocs':
        relocations.add(0x500080)
    else:
        original = match.exact_match
        def replacement(*args):
            return original(*args)
        replacement.__module__ = match.__name__
        monkeypatch.setattr(match, 'exact_match', replacement)
    after = rebuild._ownership_context('test')
    assert after != before
    rows, hit = rebuild._ownership_rows('test', obj, cache, after)
    assert not hit
    assert rows == rebuild.pair_object('test', obj.read_bytes())
    if changed in ('image', 'bounds'):
        assert rows[0][2] == []


@pytest.mark.parametrize('corrupt', ['truncated', 'checksum', 'shape'])
def test_damaged_cache_rechecked(native_target, corrupt):
    _, _, _, obj, cache = native_target
    context = rebuild._ownership_context('test')
    expected, _ = rebuild._ownership_rows('test', obj, cache, context)
    saved = json.loads(cache.read_text())
    if corrupt == 'truncated':
        cache.write_text('{')
    else:
        saved['rows'] = [['_f', 6, ['00509999']]] if corrupt == 'checksum' else [1]
        if corrupt == 'shape':
            from roc.integration import digest
            saved['digest'] = digest(saved['rows'])
        cache.write_text(json.dumps(saved))
    assert rebuild._ownership_rows('test', obj, cache, context) == (expected, False)


def test_cached_twins_stay_ambiguous(native_target):
    image, functions, _, obj, cache = native_target
    image[16:22] = image[:6]
    functions['00500010'] = dict(functions['00500000'])
    context = rebuild._ownership_context('test')
    expected = [('_f', 6, ['00500000', '00500010'])]
    assert rebuild._ownership_rows('test', obj, cache, context) == (expected, False)
    assert rebuild._ownership_rows('test', obj, cache, context) == (expected, True)


def test_loaded_code_identity_stable_across_process_hash_seeds():
    program = '''
import json
from roc import rebuild
def proof(value):
    return value in {'alpha', 'beta', 'gamma'}
print(json.dumps(rebuild._ownership_code(proof.__code__)))
'''
    import os
    outputs = [subprocess.check_output([sys.executable, '-c', program],
                                      env=dict(os.environ, PYTHONHASHSEED=seed))
               for seed in ('1', '2')]
    assert outputs[0] == outputs[1]


def test_context_stable_after_matcher_execution(native_target):
    _, _, _, obj, _ = native_target
    before = rebuild._ownership_context('test')
    rebuild.pair_object('test', obj.read_bytes())
    assert rebuild._ownership_context('test') == before
