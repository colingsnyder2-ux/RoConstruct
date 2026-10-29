import struct
from roc import match


def object_bytes(addend=0):
    code=b'\xb8'+struct.pack('<i',addend)+b'\xc3'
    data=b'abcdefghNEXT'
    code_at=100;data_at=code_at+len(code);rel_at=data_at+len(data);sym_at=rel_at+20
    symbols=[(b'_f',0,1,0x20),(b'_a',0,2,0),(b'_b',8,2,0),(b'_extern',0,0,0)]
    header=struct.pack('<HHIIIHH',0x14c,2,0,sym_at,len(symbols),0,0)
    text=struct.pack('<8sIIIIIIHHI',b'.text',0,0,len(code),code_at,rel_at,0,1,0,0x60000020)
    rdata=struct.pack('<8sIIIIIIHHI',b'.rdata',0,0,len(data),data_at,rel_at+10,0,1,0,0x40000040)
    refs=struct.pack('<IIH',1,1,6)+struct.pack('<IIH',4,3,6)
    syms=b''.join(struct.pack('<8sIhHBB',n.ljust(8,b'\0'),v,s,t,2,0) for n,v,s,t in symbols)
    return header+text+rdata+code+data+refs+syms+struct.pack('<I',4)


def test_index_keeps_symbol_bounds_addends_and_inner_relocations():
    assert match.coff_data_refs(object_bytes(),'_f') == [(1,b'abcdefgh',[4])]
    assert match.coff_data_refs(object_bytes(4),'_f') == [(1,b'efgh',[0])]
    assert match.coff_data_refs(object_bytes(8),'_f') == []  # addend outside symbol
    assert match.coff_data_refs(object_bytes(),'missing') == []


def test_index_keys_content_and_returns_fresh_data_relocation_lists():
    obj=object_bytes()
    refs=match.coff_data_refs(obj,'_f');refs[0][2].append(99)
    assert match.coff_data_refs(obj,'_f') == [(1,b'abcdefgh',[4])]
    assert match.coff_data_refs(obj.replace(b'abcdefgh',b'ABCDEFGH'),'_f') == [(1,b'ABCDEFGH',[4])]
