import gzip
import json
from pathlib import Path

import pytest
from roc import graph, libs


def fixture(tmp_path, rows=None):
    work = tmp_path/'work/test'
    work.mkdir(parents=True)
    (work/'functions.jsonl').write_text('\n'.join(json.dumps(r) for r in (rows or [
        {'addr':'00401000','size':64,'call_targets':['0x00402000'],'virtual_slots':[{'slot':3}]},
        {'addr':'00402000','size':32,'call_targets':[]},
        {'addr':'00403000','size':16,'call_targets':[]},
    ])))
    (work/'scores.json').write_text(json.dumps({'00401000':100}))
    src=tmp_path/'src/test';src.mkdir(parents=True)
    (src/'00401000.cpp').write_text('void Test::run() {}')
    return tmp_path


def evidence(root, payload):
    p=root/'rebuild/test/manifests/graph-evidence.json';p.parent.mkdir(parents=True,exist_ok=True)
    p.write_text(json.dumps(payload))


def test_address_normalization():
    assert graph.address('0x67D9B0') == graph.address(0x67d9b0) == '0067d9b0'
    with pytest.raises(ValueError):graph.address('not address')


def test_calls_reverse_and_unknown_virtual(tmp_path):
    g=graph.build('test',fixture(tmp_path))
    assert g.walk(['00401000'],1,kinds=('call',))==['00401000','00402000']
    assert g.walk(['00402000'],1,True)==['00401000','00402000']
    assert g.nodes['00401000']['unknown_virtual']==[{'slot':3}]
    assert not any(e['kind']=='virtual' for e in g.data['edges'])
    assert g.nodes['00401000']['name']=='Test::run'


def test_calls_do_not_block_integration(tmp_path):
    g=graph.build('test',fixture(tmp_path))
    n=g.nodes['00401000']
    assert n['states']['MINED'] and not n['states']['LINKED']
    assert not n['states']['BLOCKED']
    assert g.walk(['00401000'],5,kinds=('dependency',))==['00401000']


def test_cycles_and_work_order(tmp_path):
    root=fixture(tmp_path)
    evidence(root,{'edges':[
        dict(source='00401000',target='00402000',kind='dependency',evidence='link receipt'),
        dict(source='00402000',target='00401000',kind='dependency',evidence='ABI receipt'),
        dict(source='00403000',target='00401000',kind='dependency',evidence='link receipt')]})
    g=graph.build('test',root)
    assert ['00401000','00402000'] in g.components()
    assert g.order().index(['00401000','00402000']) < g.order().index(['00403000'])
    assert len(g.walk(['00401000'],100,kinds=('dependency',)))==2


def test_priority_rewards_real_blockers(tmp_path):
    root=fixture(tmp_path)
    evidence(root,{'edges':[dict(source='00401000',target='00402000',kind='dependency',evidence='link receipt')]})
    g=graph.build('test',root)
    assert g.rank()[0]['addr']=='00402000'
    assert g.rank()[0]['unlocks']==1
    assert g.rank()[0]['heuristic']
    assert g.path('00401000',{'00402000'})==['00401000','00402000']


def test_library_resolution(tmp_path,monkeypatch):
    root=fixture(tmp_path)
    monkeypatch.setitem(libs.RECIPES,'graph-test',{'src':'GraphLib'})
    (root/'src/test/00401000.cpp').write_text('// roc-lib: graph-test src/actual.cpp\n')
    n=graph.build('test',root).nodes['00401000']
    assert n['library_source']=='tools/libs/GraphLib/src/actual.cpp'
    assert n['states']['MINED']


def test_missing_and_stale_manifests(tmp_path):
    root=fixture(tmp_path)
    assert graph.build('test',root).data['warnings']
    p=root/'rebuild/test/manifests/functions.json';p.parent.mkdir(parents=True)
    p.write_text('[{"addr":"00401000","score":30}]')
    g=graph.build('test',root)
    assert g.nodes['00401000']['score']==100
    assert 'differ' in g.data['warnings'][0]


def test_module_smoke_is_not_function_runtime(tmp_path):
    root=fixture(tmp_path)
    p=root/'rebuild/test/out/App/report.json';p.parent.mkdir(parents=True)
    p.write_text(json.dumps(dict(module='App',linked=True,test_exit=0,owned_addrs=['00401000'])))
    n=graph.build('test',root).nodes['00401000']
    assert n['states']['COMPILED'] and n['states']['LINKED']
    assert not n['states']['RUNTIME_VERIFIED']
    assert not n['accepted_native']


def test_mined_can_be_blocked(tmp_path):
    root=fixture(tmp_path)
    evidence(root,{'nodes':{'00401000':{'blockers':['layout missing']}}})
    n=graph.build('test',root).nodes['00401000']
    assert n['states']['MINED'] and n['states']['BLOCKED']


def test_overlay_requires_provenance(tmp_path):
    root=fixture(tmp_path)
    evidence(root,{'edges':[dict(source='00401000',target='00402000',kind='virtual')]})
    with pytest.raises(ValueError,match='provenance'):graph.build('test',root)


def test_deterministic_export_and_cache(tmp_path):
    root=fixture(tmp_path)
    g=graph.load('test',root)
    dest=root/'public'
    graph.export(g,dest)
    before={p.name:p.read_bytes() for p in dest.glob('*.gz')}
    graph.export(graph.load('test',root),dest)
    assert before=={p.name:p.read_bytes() for p in dest.glob('*.gz')}
    (root/'src/test/00401000.cpp').write_text('void Test::changed() {}')
    assert graph.load('test',root).nodes['00401000']['name']=='Test::changed'
    shard=json.loads(gzip.decompress((dest/'00401.json.gz').read_bytes()))
    assert shard['edges'][0][:3]==['00401000','00402000','call']


def test_deep_inventory_iterative_and_bounded():
    nodes={str(i):{} for i in range(10000)}
    edges=[dict(source=str(i),target=str(i+1),kind='dependency') for i in range(9999)]
    g=graph.Graph(dict(nodes=nodes,edges=edges))
    assert len(g.components())==10000
    assert len(g.walk(['0'],10000,limit=150))==150
    assert len(g.order())==10000


def test_missing_local_source_does_not_erase_mining(tmp_path):
    root=fixture(tmp_path)
    (root/'work/test/scores.json').write_text('{"00402000":100}')
    g=graph.build('test',root)
    assert g.nodes['00402000']['states']['MINED']
    assert not g.nodes['00402000']['states']['UNMINED']
    assert not g.nodes['00402000']['source_available']
    assert next(r for r in g.rank() if r['addr']=='00402000')['action'].startswith('retrieve')


def test_module_blocker_has_module_scope(tmp_path):
    root=fixture(tmp_path)
    p=root/'rebuild/test/out/App/report.json';p.parent.mkdir(parents=True)
    p.write_text(json.dumps(dict(module='App',linked=False,owned_addrs=['00401000'],unresolved=['?missing@@'])))
    g=graph.build('test',root)
    rec=next(r for r in g.rank() if r['addr']=='symbol:?missing@@')
    assert rec['unlocks']==0
    assert rec['module_affected_functions']==1
    assert g.nodes['00401000']['states']['BLOCKED']
    assert any(e['kind']=='ownership' for e in g.out['00401000'])
    assert not any(e['kind']=='dependency' for e in g.out['00401000'])


def test_claim_exclusion_and_failed_attempts(tmp_path):
    from roc import claims
    root=fixture(tmp_path)
    p=root/'work/agent-memory/attempts.jsonl';p.parent.mkdir(parents=True)
    p.write_text(json.dumps(dict(client='test',outcome='no_gain',addresses=['00402000'])))
    g=graph.build('test',root)
    assert g.nodes['00402000']['failed_attempts']==1
    claims.save_claim('test','00402000','private-token',root=root)
    graph.active_claims(g,root)
    assert '00402000' not in [r['addr'] for r in g.rank()]
    assert 'private-token' not in json.dumps(g.data)


def test_native_baseline_reuses_existing_public_evidence(tmp_path):
    root=fixture(tmp_path)
    p=root/'docs/integration.json';p.parent.mkdir()
    p.write_text(json.dumps(dict(client='test',native=['00401000'],sources={'00401000':{'path':'native.cpp','line':3}})))
    g=graph.build('test',root)
    n=g.nodes['00401000']
    assert n['accepted_native']['scope']=='server verified native baseline'
    assert n['native_source']['path']=='native.cpp'
    assert n['states']['LINKED'] and not n['states']['RUNTIME_VERIFIED']
    assert '00401000' not in [r['addr'] for r in g.rank()]


def test_helpers_remain_searchable_but_not_work_candidates(tmp_path):
    g=graph.build('test',fixture(tmp_path,[{'addr':'00401000','kind':'eh','call_targets':[]}]))
    assert '00401000' in g.nodes
    assert g.rank()==[]


def test_legacy_attempt_journal_bom_and_concatenated_records(tmp_path):
    root=fixture(tmp_path)
    p=root/'work/agent-memory/attempts.jsonl';p.parent.mkdir(parents=True)
    record=json.dumps(dict(client='test',outcome='no_gain',addresses=['00402000']))
    p.write_text('\ufeff'+record+record+'\n',encoding='utf-8')
    assert graph.build('test',root).nodes['00402000']['failed_attempts']==2


def test_live_native_claim_lookup_uses_existing_inventory(tmp_path):
    import time
    root=fixture(tmp_path)
    g=graph.build('test',root)
    g.data['client']='2008-06'
    class API:
        def call(self,path):
            assert path=='/v1/integration?claims=1'
            return dict(claims=[dict(unit='OtherWorker',state='claimed',expires=time.time()+60)],
                        inventory={'OtherWorker':['00401000']})
    graph.active_claims(g,root,API())
    assert '00401000' not in [r['addr'] for r in g.rank()]
