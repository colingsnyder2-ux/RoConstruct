import struct

from roc import match, rebuild


def graph(monkeypatch, addend=0, external=False, duplicate_leaf=False, duplicate_callback=False, opcode=0xe9, cycle=False, conflicting=False):
    bodies = [b'\xb8\0\0\0\0\xc3', bytes([opcode])+struct.pack('<i',addend), b'\x68\0\0\0\0\xc3', b'Name\0']
    refs = [[(1,3,6)], [(1,4 if external else 2 if cycle else 0,20)], [(1,1,6)], []]
    if conflicting:
        bodies[2]=b'\x68\0\0\0\0\xe9\0\0\0\0'
        refs[2].append((6,0,20))
    names = [b'_leaf',b'_cb',b'_wrap',b'_tag',b'_ext']
    offset=20+4*40
    raw=[]
    for body in bodies:
        raw.append(offset); offset+=len(body)
    reloc=[]
    for group in refs:
        reloc.append(offset); offset+=10*len(group)
    header=struct.pack('<HHIIIHH',0x14c,4,0,offset,len(names),0,0)
    sections=b''.join(struct.pack('<8sIIIIIIHHI',name.ljust(8,b'\0'),0,0,len(body),ptr,rptr,0,len(group),0,
                                  0x60000020 if i<3 else 0x40000040)
                      for i,(name,body,ptr,rptr,group) in enumerate(zip([b'.text$L',b'.text$C',b'.text$W',b'.rdata'],bodies,raw,reloc,refs)))
    symbols=b''.join(struct.pack('<8sIhHBB',name.ljust(8,b'\0'),0,i+1 if i<4 else 0,0x20 if i<3 else 0,2,0)
                     for i,name in enumerate(names))
    obj=header+sections+b''.join(bodies)+b''.join(struct.pack('<IIH',*r) for group in refs for r in group)+symbols+struct.pack('<I',4)
    image=bytearray(512); image[256:261]=b'Name\0'; image[272:277]=b'Name\0' if duplicate_leaf else b'Else\0'
    targets={'00500000':b'\xb8'+struct.pack('<I',0x500100)+b'\xc3',
             '00500010':b'\xb8'+struct.pack('<I',0x500110)+b'\xc3',
             '00500020':bytes([opcode])+struct.pack('<i',0x500000-0x500020-5),
             '00500030':bytes([opcode])+struct.pack('<i',(0x500000 if duplicate_callback else 0x500010)-0x500030-5),
             '00500040':b'\x68'+struct.pack('<I',0x500020)+b'\xc3',
             '00500050':b'\x68'+struct.pack('<I',0x500030)+b'\xc3'}
    choices={'_leaf':['00500000','00500010'],'_cb':['00500020','00500030'],'_wrap':['00500040','00500050']}
    if conflicting:
        targets['00500040']=b'\x68'+struct.pack('<I',0x500020)+b'\xe9'+struct.pack('<i',0x500010-0x500040-10)
        targets['00500050']=b'\x68'+struct.pack('<I',0x500030)+b'\xe9'+struct.pack('<i',0x500000-0x500050-10)
    monkeypatch.setattr(match,'_image',lambda client:(0x500000,bytes(image)))
    monkeypatch.setattr(match,'_base_relocs',lambda client:frozenset())
    monkeypatch.setattr(match,'target',lambda client,address:(targets[address],[1],{}))
    monkeypatch.setattr(rebuild,'pair',lambda client,funcs:[(s,len(b),choices[s]) for s,b,r in funcs])
    return obj


def test_data_leaf_resolves_jump_then_pushed_callback(monkeypatch):
    obj=graph(monkeypatch)
    assert rebuild.pair_object('test',obj)==[('_leaf',6,['00500000']),('_cb',5,['00500020']),('_wrap',6,['00500040'])]


def test_filtered_wrapper_still_checks_callees_outside_discovery_subset(monkeypatch):
    obj=graph(monkeypatch)
    assert rebuild.pair_object('test',obj,{'_wrap'})==[('_wrap',6,['00500040'])]


def test_ambiguous_data_leaf_cannot_bootstrap_caller_ownership(monkeypatch):
    obj=graph(monkeypatch,duplicate_leaf=True)
    assert all(len(hits)==2 for _,_,hits in rebuild.pair_object('test',obj))


def test_identical_callee_destinations_preserve_callback_ambiguity(monkeypatch):
    obj=graph(monkeypatch,duplicate_callback=True)
    assert rebuild.pair_object('test',obj,{'_wrap'})==[('_wrap',6,['00500040','00500050'])]


def test_external_callee_without_object_definition_is_not_an_anchor(monkeypatch):
    obj=graph(monkeypatch,external=True)
    assert rebuild.pair_object('test',obj,{'_wrap'})==[('_wrap',6,['00500040','00500050'])]


def test_nonzero_code_addend_is_not_guessed(monkeypatch):
    obj=graph(monkeypatch,addend=4)
    assert rebuild.pair_object('test',obj,{'_wrap'})==[('_wrap',6,['00500040','00500050'])]


def test_non_branch_relocation_does_not_become_a_call(monkeypatch):
    obj=graph(monkeypatch,opcode=0x90)
    assert rebuild.pair_object('test',obj,{'_wrap'})==[('_wrap',6,['00500040','00500050'])]


def test_call_cycle_cannot_bootstrap_unique_ownership(monkeypatch):
    obj=graph(monkeypatch,cycle=True)
    assert rebuild.pair_object('test',obj,{'_wrap'})==[('_wrap',6,['00500040','00500050'])]


def test_callee_proof_cannot_waive_missing_caller_data(monkeypatch):
    obj=graph(monkeypatch)
    original=match.coff_data_refs
    monkeypatch.setattr(match,'coff_data_refs',lambda data,symbol,**kwargs:
                        [(999,b'Name',[])] if symbol=='_wrap' else original(data,symbol,**kwargs))
    assert rebuild.pair_object('test',obj,{'_wrap'})==[('_wrap',6,['00500040','00500050'])]


def test_callee_proof_cannot_waive_mismatched_caller_data(monkeypatch):
    obj=graph(monkeypatch)
    original=match.coff_data_refs
    monkeypatch.setattr(match,'coff_data_refs',lambda data,symbol,**kwargs:
                        [(1,b'Wrong',[])] if symbol=='_wrap' else original(data,symbol,**kwargs))
    assert rebuild.pair_object('test',obj,{'_wrap'})==[('_wrap',6,[])]


def test_all_known_callee_constraints_must_agree(monkeypatch):
    obj=graph(monkeypatch,conflicting=True)
    assert rebuild.pair_object('test',obj,{'_wrap'})==[('_wrap',10,[])]
