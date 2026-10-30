import struct
from pathlib import Path

import pytest

from roc import match, native_refs, standins


def coff(reference):
    code=b'\xff\x15\0\0\0\0\xc3'
    raw=reference.encode()
    string_table=struct.pack('<I',5+len(raw))+raw+b'\0'
    code_at=60;rel_at=code_at+len(code);sym_at=rel_at+10
    header=struct.pack('<HHIIIHH',0x14c,1,0,sym_at,2,0,0)
    text=struct.pack('<8sIIIIIIHHI',b'.text',0,0,len(code),code_at,rel_at,0,1,0,0x60000020)
    symbols=struct.pack('<8sIhHBB',b'_f\0\0\0\0\0\0',0,1,0x20,2,0)
    symbols+=struct.pack('<8sIhHBB',struct.pack('<II',0,4),0,0,0,2,0)
    return header+text+code+struct.pack('<IIH',2,1,6)+symbols+string_table


@pytest.fixture
def reference_image(monkeypatch):
    code=b'\xff\x15'+struct.pack('<I',0x500000)+b'\xc3'
    monkeypatch.setattr(match,'target',lambda *a:(code,[2],{}))
    monkeypatch.setattr(match,'_image',lambda *a:(0x400000,b''))
    monkeypatch.setattr(match,'_base_relocs',lambda *a:[])
    monkeypatch.setattr(standins,'_imports',lambda *a:{0x500000:'kernel32.dll!Good'})
    return code


def test_import_relocation_identity_cannot_hide_under_masked_code(reference_image):
    good,bad=coff('__imp__Good@0'),coff('__imp__Wrong@0')
    assert match.exact_match(reference_image,[2],match.coff_functions(bad)[0][1],[2])
    assert native_refs.import_checks(good,'_f','00401000')[0]['status']=='compatible_import_name'
    report=native_refs.import_checks(bad,'_f','00401000')[0]
    assert report['status']=='incorrect_symbol_reference' and report['expected']=='kernel32.dll!Good'


def test_new_native_credit_requires_code_data_and_reference_witness(tmp_path,reference_image):
    folder=tmp_path/'rebuild/2008-06/out/RbxgsApp/linked';folder.mkdir(parents=True)
    (folder/'bad.obj').write_bytes(coff('__imp__Wrong@0'))
    report=dict(module='RbxgsApp',owned_symbols={'00401000':[dict(symbol='_f',object='bad.obj')]})
    with pytest.raises(ValueError,match='reference mismatch'):
        native_refs.validate(tmp_path,report,['00401000'])
    (folder/'good.obj').write_bytes(coff('__imp__Good@0'))
    report['owned_symbols']['00401000'].append(dict(symbol='_f',object='good.obj'))
    assert native_refs.validate(tmp_path,report,['00401000'])['checked']==1


def test_referenced_data_mismatch_rejects_even_with_correct_import(tmp_path,reference_image,monkeypatch):
    folder=tmp_path/'rebuild/2008-06/out/RbxgsApp/linked';folder.mkdir(parents=True)
    (folder/'good.obj').write_bytes(coff('__imp__Good@0'))
    monkeypatch.setattr(match,'data_check',lambda *a:([],['float literal differs']))
    report=dict(module='RbxgsApp',owned_symbols={'00401000':[dict(symbol='_f',object='good.obj')]})
    with pytest.raises(ValueError,match='float literal differs'):
        native_refs.validate(tmp_path,report,['00401000'])


def test_missing_or_escaped_witnesses_cannot_bypass_reference_gate(tmp_path):
    with pytest.raises(ValueError,match='map missing'):
        native_refs.validate(tmp_path,dict(module='RbxgsApp'),['00401000'])
    report=dict(module='RbxgsApp',owned_symbols={'00401000':[dict(symbol='_f',object='../../escape.obj')]})
    with pytest.raises(ValueError,match='escaped'):
        native_refs.validate(tmp_path,report,['00401000'])


def test_sidecar_reference_map_is_contained_and_rechecked(tmp_path,reference_image):
    import json
    directory=tmp_path/'rebuild/2008-06/out/RbxgsApp'
    (directory/'linked').mkdir(parents=True)
    (directory/'linked/good.obj').write_bytes(coff('__imp__Good@0'))
    (directory/'owned-symbols.json').write_text(json.dumps({'00401000':[dict(symbol='_f',object='good.obj')]}))
    report=dict(module='RbxgsApp',owned_symbols_file='owned-symbols.json')
    assert native_refs.validate(tmp_path,report,['00401000'])['checked']==1
    report['owned_symbols_file']='../../escape.json'
    with pytest.raises(ValueError,match='map escaped'):
        native_refs.validate(tmp_path,report,['00401000'])


def test_refreshed_baseline_checks_all_accepted_bodies(tmp_path,reference_image):
    from roc import integration_verify
    directory=tmp_path/'rebuild/2008-06/out/RbxgsApp'
    (directory/'linked').mkdir(parents=True)
    (directory/'linked/good.obj').write_bytes(coff('__imp__Good@0'))
    report=dict(module='RbxgsApp',owned_addrs=['00401000'],
        owned_symbols={'00401000':[dict(symbol='_f',object='good.obj')]})
    assert integration_verify.check_credited(tmp_path,report,['00401000'])['checked']==1
    with pytest.raises(ValueError,match='Accepted native bodies missing'):
        integration_verify.check_credited(tmp_path,report,['00401000','00402000'])
