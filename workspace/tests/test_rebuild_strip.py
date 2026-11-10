import struct
import hashlib
import json
import os

from roc import match, rebuild


def test_explicitly_dropped_comdat_is_not_counted_as_reproduced_code():
    bodies = [b'\x33\xc0\xc3', b'\xb8\x01\x00\x00\x00\xc3', b'constant\0']
    symbols = bytearray()
    for section, name in enumerate([b'_keep', b'_discard', b'_literal'], 1):
        symbols += struct.pack('<8sIhHBB', b'.text' if section < 3 else b'.rdata', 0, section, 0, 3, 1)
        aux = bytearray(18)
        struct.pack_into('<B', aux, 14, 2)  # IMAGE_COMDAT_SELECT_ANY
        symbols += aux
        symbols += struct.pack('<8sIhHBB', name, 0, section, 0x20 if section < 3 else 0, 2, 0)
    offset = 20 + 3 * 40
    sections = bytearray()
    for index, body in enumerate(bodies):
        sections += struct.pack('<8sIIIIIIHHI', b'.text' if index < 2 else b'.rdata',
                                0, 0, len(body), offset, 0, 0, 0, 0,
                                0x60001020 if index < 2 else 0x40001040)
        offset += len(body)
    obj = struct.pack('<HHIIIHH', 0x14c, 3, 0, offset, 9, 0, 0)
    obj += sections + b''.join(bodies) + symbols + struct.pack('<I', 4)

    stripped = rebuild.strip_symbols(obj, drop={'_discard'})
    assert {name for name, _, _ in match.coff_functions(stripped)} == {'_keep'}
    assert rebuild.coff_externals(stripped) == {'_keep': True, '_literal': True, '_discard': False}

    # Unrequested template code must resolve to native code or an explicitly retained helper.
    stripped = rebuild.strip_symbols(obj, keep={'_keep'})
    assert {name for name, _, _ in match.coff_functions(stripped)} == {'_keep'}
    assert rebuild.coff_externals(stripped) == {'_keep': True, '_literal': True, '_discard': False}


def test_placement_discards_old_parser_cache_and_defers_unfinished_build(tmp_path, monkeypatch):
    modules = tmp_path / 'rebuild' / 'test' / 'modules'
    modules.mkdir(parents=True)
    (modules / 'module.json').write_text('{"name": "Module"}')
    out = tmp_path / 'out' / 'Module'
    (out / 'linked').mkdir(parents=True)
    obj = out / 'linked' / 'one.obj'
    obj.write_bytes(b'object')
    report = out / 'report.json'
    report.write_text('{"linked": true}')
    (out / 'placed.json').write_text(json.dumps({hashlib.sha256(b'object').hexdigest(): ['old']}))
    monkeypatch.setattr(rebuild, 'ROOT', tmp_path)
    monkeypatch.setattr(rebuild, 'workspace', lambda client: tmp_path)
    monkeypatch.setattr(match, '_image', lambda client: (0, b''))
    monkeypatch.setattr(match, 'coff_functions', lambda data: [])
    calls = []
    monkeypatch.setattr(rebuild, 'pair', lambda *args: calls.append(args) or [])

    assert rebuild.placed('test', log=lambda text: None) == {}
    assert len(calls) == 1  # old cache must not resurrect removed code
    os.utime(obj, ns=(report.stat().st_mtime_ns + 1000000,) * 2)
    messages = []
    assert rebuild.placed('test', log=messages.append) == {}
    assert len(calls) == 1
    assert any('placement deferred' in text for text in messages)
