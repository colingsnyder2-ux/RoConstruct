"""Layout evidence for RBX::Network::Server::ClientProxy (2008-06). Nothing compiles yet: every row is blocked.

ClientProxy derives from Network::Replicator, and no native 2008 Replicator class exists yet. The committed native
headers stop at the Replicator bases (Network/IdSerializer.h, sizeof 0x2b74, see record_native_replicator.py, whose
receipt says the Replicator layout past +0x2b74, ctor 004b9bd0 and dtor 004b96b0 are still open). The donor-path
native-headers/Replicator.h is the provisional donor layout. Its classNames and propNames are SharedStringDictionary
(0x2a24 bytes each), but the 2008 ctor builds 0x44-byte objects there. A ClientProxy definition therefore cannot
be compiled against a proven base, and no source, header or pending build is produced. No row is exact here.

This recorder verifies the derived ClientProxy layout and the per-function facts in the original binary bytes:
  * RTTI of vtable 00823474: ClientProxy -> Replicator at 0, PluginInterface at +0x2b74, 22 primary slots;
  * Creatable::create<ClientProxy> 004a21c0: malloc(0x2d78), then the constructor 004a1ed0;
  * ctor 004a1ed0: Replicator(SystemAddress, server->peerInterface()) 004b9bd0, remotePlayer (shared_ptr<Player>)
    +0x2d68/+0x2d6c = 0, server +0x2d70, ret 0xc (SystemAddress 8 bytes + Server*);
  * Replicator ctor 004b9bd0: last stores +0x2d5c/+0x2d60 (shared_ptr-shaped pair), so sizeof(Replicator) is 0x2d68
    (8-aligned because of the G3D::RealTime at +0x2b78) and sizeof(ClientProxy) 0x2d74 rounds to 0x2d78;
  * dtor 004a18c0: releases the shared_ptr count at +0x2d6c, then calls ~Replicator 004b96b0;
  * leaves: slot 17 004a1a30 returns +0x2d68 (findTargetPlayer), slot 19 004a1570 sets byte +0x2cd0 (onSentMarker;
    the Replicator ctor clears +0x2cd0 and Replicator slot 19 is _purecall), slot 21 is the shared `mov al,1; ret`
    00565950 (canSendItems), PluginInterface slot 5 004a2c20 is the named ClientProxy::OnReceive.
Writes work/2008-06/shared-layouts/network-client-proxy-working.json.
"""
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
original = nb.Original()


def d(address):
    return struct.unpack('<I', original.data(address, 4))[0]


def body(address):
    code, _, _ = match.target('2008-06', '%08x' % address)
    return code


def rel32_targets(address):
    """Absolute targets of every E8 call in the target body whose operand is a real call (by disassembly)."""
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    out = []
    for insn in md.disasm(body(address), address):
        if insn.mnemonic == 'call' and insn.op_str.startswith('0x'):
            out.append(int(insn.op_str, 16))
    return out


def insns(address):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    return [(i.address, (i.mnemonic + ' ' + i.op_str).strip()) for i in md.disasm(body(address), address)]


def has(address, text):
    return any(t == text for _, t in insns(address))


VT = 0x823474
REPLICATOR_VT = 0x8254fc

# ---- RTTI and vtables ------------------------------------------------------------------------------
name, offset = original.vtable_class(VT)
assert name == '.?AVClientProxy@Server@Network@RBX@@' and offset == 0, (name, offset)
locator = d(VT - 4)
hierarchy = d(locator + 16)
items = [d(d(hierarchy + 12) + 4 * i) for i in range(d(hierarchy + 8))]
bases = {original.string(d(item) + 8): struct.unpack('<i', original.data(item + 8, 4))[0] for item in items}
assert bases['.?AVReplicator@Network@RBX@@'] == 0, bases
assert bases['.?AVIdSerializer@Network@RBX@@'] == 0, bases
assert bases['.?AVPluginInterface@@'] == 0x2b74, bases
assert original.vtable_class(0x8233c4) == ('.?AVClientProxy@Server@Network@RBX@@', 0x2b74)

slots = [d(VT + 4 * i) for i in range(22)]
replicator_slots = [d(REPLICATOR_VT + 4 * i) for i in range(22)]
PURECALL = 0x70bdf0
assert slots[:16] == replicator_slots[:16], 'Instance slots are inherited unchanged'
assert replicator_slots[19] == PURECALL and slots[19] == 0x4a1570
assert slots[16] == 0x4a3290 and replicator_slots[16] == 0x565ff0
assert slots[17] == 0x4a1a30 and replicator_slots[17] == 0x4ab9a0
assert slots[18] == replicator_slots[18] == 0x4aaf90          # wantReplicate (evidence name), inherited
assert slots[20] == replicator_slots[20] == 0x4ab960          # inherited
assert slots[21] == 0x565950 and replicator_slots[21] == 0x4aafc0
plugin_slots = [d(0x8233c4 + 4 * i) for i in range(11)]
assert plugin_slots[0] == 0x4a19a0 and plugin_slots[5] == 0x4a2c20, [hex(x) for x in plugin_slots]

# ---- allocation and constructor ----------------------------------------------------------------------
create = [t for _, t in insns(0x4a21c0)]
push = create.index('push 0x2d78')
assert create[push + 2] == 'call dword ptr [0x8028b0]', create[push:push + 3]   # push 0x2d78; ...; call [malloc]
assert original.imported(0x8028b0) == ('msvcr90.dll', 'malloc')
assert 0x4a1ed0 in rel32_targets(0x4a21c0)

assert rel32_targets(0x4a1ed0) == [0x609a30, 0x4b9bd0]
assert insns(0x609a30) == [(0x609a30, 'mov eax, dword ptr [ecx + 0x140]'), (0x609a36, 'ret')]
for text in ('mov dword ptr [esi], 0x823474', 'mov dword ptr [esi + 0x2b74], 0x8233c4',
             'mov dword ptr [esi + 0x2d68], eax', 'mov dword ptr [esi + 0x2d6c], eax',
             'mov dword ptr [esi + 0x2d70], edi', 'ret 0xc'):
    assert has(0x4a1ed0, text), text

rep = insns(0x4b9bd0)
rep_stores = [t for _, t in rep if t.startswith('mov dword ptr [esi + 0x2d') or t.startswith('mov byte ptr [esi + 0x2d')]
assert rep_stores[-2:] == ['mov dword ptr [esi + 0x2d5c], ebx', 'mov dword ptr [esi + 0x2d60], ebx'], rep_stores
assert 'mov byte ptr [esi + 0x2cd0], bl' in [t for _, t in rep]
assert 'fstp qword ptr [esi + 0x2b78]' in [t for _, t in rep]
assert not any('0x2d64' in t or '0x2d68' in t for _, t in rep)

# ---- destructor chain ----------------------------------------------------------------------------------
assert rel32_targets(0x4a18c0) == [0x4b96b0]
assert has(0x4a18c0, 'mov edi, dword ptr [esi + 0x2d6c]')
assert rel32_targets(0x4a1f70) == [0x4a18c0]
assert original.imported(0x8028c0) == ('msvcr90.dll', 'free')
THUNKS = {0x4a19a0: 0x2b74, 0x4a19b0: 0x24, 0x4a19c0: 0x44, 0x4a19d0: 0x64, 0x4a19e0: 0x84, 0x4a19f0: 0xa4,
          0x4a1a00: 0xc4, 0x4a1a10: 0x10, 0x4a1a20: 0x14}
for thunk, adjust in THUNKS.items():
    ins = insns(thunk)
    assert ins[0][1] == 'sub ecx, %s' % hex(adjust) and ins[1][1] == 'jmp 0x4a1f70', (hex(thunk), ins)

# ---- leaves --------------------------------------------------------------------------------------------
assert [t for _, t in insns(0x4a1a30)] == ['mov eax, dword ptr [ecx + 0x2d68]', 'ret']
assert [t for _, t in insns(0x4a1570)] == ['mov byte ptr [ecx + 0x2cd0], 1', 'ret 4']
assert [t for _, t in insns(0x565950)] == ['mov al, 1', 'ret']
assert original.string(0x92e1c8 + 8) == '.?AVScript@RBX@@' and original.string(0x939b1c + 8) == '.?AVMessage@RBX@@'
assert has(0x4a3290, 'mov esi, dword ptr [esi + 0x2d70]') and has(0x4a3290, 'mov edi, dword ptr [esi + 0x164]')
for text in ('push 0x4b', 'mov edx, dword ptr [esi + 0x2c58]', 'mov ebx, dword ptr [esi + 0x2c64]',
             'mov eax, dword ptr [esi + 0x2c68]', 'mov ecx, dword ptr [esi + 0x2d50]',
             'mov edx, dword ptr [esi + 0x2d54]'):
    assert has(0x4a2ac0, text), text                             # sendTop reads the Replicator fields it cites

BLOCK = ('blocked: needs the native 2008 Network::Replicator class (sizeof 0x2d68; layout +0x2b74..+0x2d68, ctor '
         '004b9bd0, dtor 004b96b0), not recovered by any native header')
ROWS = [
    (0x4a1ed0, 'ClientProxy::ClientProxy(SystemAddress, Server*)', BLOCK + '; also Server::peerInterface (shared '
     '00609a30 reads Server +0x140) needs a native Server/Peer'),
    (0x4a18c0, 'ClientProxy::~ClientProxy()', BLOCK),
    (0x4a1f70, 'ClientProxy scalar deleting destructor (Creatable operator delete -> free)', BLOCK),
] + [(t, 'ClientProxy deleting-destructor thunk (this -= %s)' % hex(a), BLOCK) for t, a in sorted(THUNKS.items())] + [
    (0x4a1a30, 'ClientProxy::findTargetPlayer() (slot 17, returns remotePlayer.get() +0x2d68)', BLOCK),
    (0x4a1570, 'ClientProxy::onSentMarker(long) (slot 19, sendPhysicsEnabled +0x2cd0 = true)', BLOCK),
    (0x565950, 'ClientProxy::canSendItems() (slot 21; ICF-shared `mov al,1; ret`, not ClientProxy-owned)', BLOCK),
    (0x4a3290, 'ClientProxy slot 16 bool(const Instance*): Script -> lookup in Server +0x164 container keyed by '
     'the script, else !dynamic_cast<Message>', BLOCK + '; also the Server +0x164 container type (ctor 004d8680) '
     'and a native Server/Peer'),
    (0x4a21c0, 'Creatable::create<ClientProxy>(SystemAddress, Server*) (malloc 0x2d78)', BLOCK),
    (0x4a2ac0, 'ClientProxy::sendTop() (packet 0x4b, version string, replicationContainers +0x2c58 vector, '
     'peer +0x2d50 Send slot 13, remotePlayerId +0x2d54)', BLOCK + '; also BitStream operator<< and serializeId'),
    (0x4a2c20, 'ClientProxy::OnReceive(RakPeerInterface*, Packet*) (PluginInterface slot 5)', BLOCK),
]
rows = [{'address': '%08x' % a, 'function': f, 'exact': False, 'reason': r} for a, f, r in ROWS]
assert len({r['address'] for r in rows}) == len(rows)

receipt = {
    'class': 'RBX::Network::Server::ClientProxy',
    'evidence_only': True,
    'sources': {str(Path(__file__).resolve().relative_to(ROOT)).replace('\\', '/'): nb.sha(Path(__file__).resolve())},
    'layout': {
        'sizeof': '0x2d78 (malloc in 004a21c0); 0x2d74 of data, 8-aligned because Replicator holds a double',
        'bases': 'Replicator at 0 (IdSerializer/Instance chain), PluginInterface +0x2b74 (RTTI 00823474)',
        'sizeof_Replicator': '0x2d68 (first ClientProxy member; Replicator ctor 004b9bd0 last stores +0x2d5c/+0x2d60)',
        'fields': {'+0x2d68': 'boost::shared_ptr<Player> remotePlayer (px +0x2d68, pn +0x2d6c; ctor zeroes both; '
                              'dtor releases +0x2d6c; findTargetPlayer returns +0x2d68)',
                   '+0x2d70': 'Server* server (ctor stores its third argument; slot 16 reads it)'},
        'replicator_fields_used': {'+0x2c58': 'vector-shaped replicationContainers (sendTop 004a2ac0 reads +0x2c58, '
                                              'first +0x2c64, last +0x2c68; element type unproven)',
                                   '+0x2cd0': 'bool sendPhysicsEnabled', '+0x2d50': 'RakPeerInterface* peer',
                                   '+0x2d54': 'SystemAddress remotePlayerId'},
        'server_fields_used': {'+0x140': 'rakPeer (peerInterface 00609a30)', '+0x164': 'container built by 004d8680 '
                               'in Server ctor 004a4b30, looked up by Script in slot 16'},
    },
    'vtable': {'address': hex(VT), 'slots': [hex(x) for x in slots],
               'plugin_interface': {'address': '0x8233c4', 'slots': [hex(x) for x in plugin_slots]}},
    'methods': rows, 'exact_distinct_addresses': [], 'not_exact': len(rows),
    'scope': 'Inactive, evidence only. No native-headers/Network/ClientProxy2008.h or native-classes unit is created '
             'until a native 2008 Replicator (and Server/Peer, which need util/Profiling.h) exists.',
}
(ROOT / 'work/2008-06/shared-layouts/network-client-proxy-working.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS native Network::Server::ClientProxy layout evidence: 0 exact rows, %d blocked (Replicator 2008 layout '
      'not natively recovered); sizeof 0x2d78, Replicator 0x2d68, PluginInterface +0x2b74 verified' % len(rows))
