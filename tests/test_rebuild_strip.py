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
    monkeypatch.setattr(rebuild, '_ownership_context', lambda client: 'target-context')
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



def test_partial_object_keeps_only_selected_exports_and_preserves_other_directives():
    directives = (b' /DEFAULTLIB:MSVCRT /EXPORT:_keep /EXPORT:"public_name=_keep",DATA'
                  b' /EXPORT:_discard /EXPORT:"other=_discard",NONAME /INCLUDE:_legit ')
    raw = b'\xc3' + directives
    symbol_offset = 20 + 2 * 40 + len(raw)
    obj = struct.pack('<HHIIIHH', 0x14c, 2, 0, symbol_offset, 1, 0, 0)
    obj += struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, 1, 100, 0, 0, 0, 0, 0x60000020)
    obj += struct.pack('<8sIIIIIIHHI', b'.drectve', 0, 0, len(directives), 101, 0, 0, 0, 0, 0x00100A00)
    obj += raw + struct.pack('<8sIhHBB', b'_keep', 0, 1, 0x20, 2, 0) + struct.pack('<I', 4)
    assert rebuild.strip_symbols(obj) == obj
    result = rebuild.strip_symbols(obj, keep={'_keep'})
    assert len(result) == len(obj)
    assert match.coff_functions(result) == [('_keep', b'\xc3', [])]
    assert b'/EXPORT:_keep' in result and b'/EXPORT:"public_name=_keep",DATA' in result
    assert b'_discard' not in result
    assert b'/DEFAULTLIB:MSVCRT' in result and b'/INCLUDE:_legit' in result


def test_coff_subset_preserves_callbacks_weak_fallbacks_and_unwind_associations():
    bodies = [b'\xe8\0\0\0\0\xc3', b'\xc3', b'\xb8\0\0\0\0\xc3',
              b'\0' * 4, b'\xc3', b'unwind', struct.pack('<II', 4, 1),
              b' /DEFAULTLIB:MSVCRT /EXPORT:_unused ']
    section_names = [b'.text', b'.text', b'.text', b'.rdata', b'.text', b'.xdata', b'.sxdata', b'.drectve']
    relocations = {0: [(1, 7)], 2: [(1, 3)], 3: [(0, 4)]}
    definitions = [('_owner', 1, 0x20), ('_unused', 2, 0x20), ('_helper', 3, 0x20),
                   ('_vtable', 4, 0), ('_cb', 5, 0x20)]
    symbols = bytearray()
    for name, section, typ in definitions:
        symbols += struct.pack('<8sIhHBB', name.encode(), 0, section, typ, 2, 0)
    symbols += struct.pack('<8sIhHBB', b'.xdata', 0, 6, 0, 3, 1)
    aux = bytearray(18)
    struct.pack_into('<HB', aux, 12, 1, 5)
    symbols += aux
    symbols += struct.pack('<8sIhHBB', b'_alias', 0, 0, 0, 105, 1)
    symbols += struct.pack('<II10x', 2, 3)
    obj = bytearray(20 + 40 * len(bodies))
    for index, (name, body) in enumerate(zip(section_names, bodies)):
        raw_at = len(obj)
        obj += body
        refs = relocations.get(index, [])
        ref_at = len(obj) if refs else 0
        for offset, symbol in refs:
            obj += struct.pack('<IIH', offset, symbol, 6)
        struct.pack_into('<8sIIIIIIHHI', obj, 20 + 40 * index, name, 0, 0,
                         len(body), raw_at, ref_at, 0, len(refs), 0, 0x60000020)
    struct.pack_into('<HHIIIHH', obj, 0, 0x14c, len(bodies), 0, len(obj), 9, 0, 0)
    obj += symbols + struct.pack('<I', 4)
    subset, names = rebuild._coff_subset(bytes(obj), {'_owner'})
    assert names == {'_owner', '_helper', '_vtable', '_cb'}
    assert {name for name, _, _ in match.coff_functions(subset)} == {'_owner', '_helper', '_cb'}
    assert '_unused' not in rebuild.coff_externals(subset)
    _, section_count, _, symbol_at, count, _, _ = struct.unpack_from('<HHIIIHH', subset)
    assert section_count == 7 and count == 8
    sections = [struct.unpack_from('<8sIIIIIIHHI', subset, 20 + 40 * i) for i in range(section_count)]
    sxdata = next(section for section in sections if section[0].startswith(b'.sxdata'))
    assert subset[sxdata[4]:sxdata[4] + sxdata[3]] == struct.pack('<I', 3)
    # Associative unwind section now follows owner section 1; weak fallback follows helper's new symbol index.
    assert struct.unpack_from('<HB', subset, symbol_at + 4 * 18 + 18 + 12) == (1, 5)
    assert struct.unpack_from('<I', subset, symbol_at + 6 * 18 + 18)[0] == 1

    external, names = rebuild._coff_subset(bytes(obj), {'_owner'}, external={'_helper'})
    assert names == {'_owner'}
    assert {name for name, _, _ in match.coff_functions(external)} == {'_owner'}
    assert rebuild.coff_externals(external) == {'_owner': True, '_helper': False}
    alias, _ = rebuild._coff_subset(bytes(obj), {'_alias'})
    assert {name for name, _, _ in match.coff_functions(alias)} == {'_helper', '_cb'}


def test_coff_subset_preserves_zero_initialized_storage_without_file_payload():
    obj = struct.pack('<HHIIIHH', 0x14c, 1, 0, 60, 1, 0, 0)
    obj += struct.pack('<8sIIIIIIHHI', b'.bss', 0, 0, 8, 0, 0, 0, 0, 0, 0xC0300080)
    obj += struct.pack('<8sIhHBB', b'_global', 0, 1, 0, 2, 0) + struct.pack('<I', 4)
    result, names = rebuild._coff_subset(obj, {'_global'})
    assert names == {'_global'}
    section = struct.unpack_from('<8sIIIIIIHHI', result, 20)
    assert section[3:5] == (8, 0)
    assert rebuild.coff_externals(result) == {'_global': True}


def test_coff_subset_omits_safeseh_table_when_no_handlers_survive():
    # Both a compiler's empty table and a table pruned to zero entries must go.
    # VS2008 reports LNK1236 (or LNK1000 in archive lookup) if either remains.
    for payload in (b'', struct.pack('<I', 1)):
        obj = bytearray(100)
        struct.pack_into('<HHIIIHH', obj, 0, 0x14c, 2, 0, 101 + len(payload), 2, 0, 0)
        struct.pack_into('<8sIIIIIIHHI', obj, 20, b'.text', 0, 0, 1, 100, 0, 0, 0, 0, 0x60000020)
        struct.pack_into('<8sIIIIIIHHI', obj, 60, b'.sxdata', 0, 0, len(payload), 101, 0, 0, 0, 0, 0x300200)
        obj += b'\xc3' + payload
        obj += struct.pack('<8sIhHBB', b'_owner', 0, 1, 0x20, 2, 0)
        obj += struct.pack('<8sIhHBB', b'_unused', 0, 0, 0x20, 2, 0) + struct.pack('<I', 4)
        result, _ = rebuild._coff_subset(bytes(obj), {'_owner'})
        assert struct.unpack_from('<H', result, 2)[0] == 1
        assert match.coff_functions(result) == [('_owner', b'\xc3', [])]


def test_coff_subset_resolves_forward_symbol_entry_to_its_later_definition():
    obj = struct.pack('<HHIIIHH', 0x14c, 2, 0, 117, 3, 0, 0)
    obj += struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, 6, 100, 107, 0, 1, 0, 0x60000020)
    obj += struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, 1, 106, 0, 0, 0, 0, 0x60000020)
    obj += b'\xe8\0\0\0\0\xc3\xc3' + struct.pack('<IIH', 1, 1, 0x14)
    obj += struct.pack('<8sIhHBB', b'_owner', 0, 1, 0x20, 2, 0)
    obj += struct.pack('<8sIhHBB', b'_later', 0, 0, 0x20, 2, 0)
    obj += struct.pack('<8sIhHBB', b'_later', 0, 2, 0x20, 2, 0) + struct.pack('<I', 4)
    result, _ = rebuild._coff_subset(obj, {'_owner'})
    assert {name for name, _, _ in match.coff_functions(result)} == {'_owner', '_later'}
    assert rebuild.coff_externals(result) == {'_owner': True, '_later': True}
