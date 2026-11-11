"""Classify Ogre placeholder names without turning hypotheses into declarations."""
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402


def owner_from_vtable(symbol):
    """RTTI-derived MSVC vtable spelling -> namespace owner; templates stay unknown."""
    body = symbol[4:].split('@@6B', 1)[0]
    if '$' in body or not body:
        return None
    return '::'.join(reversed(body.split('@')))


def vtable_slots():
    """Original vtable slots: owner and __thiscall stack pop, never parameter types."""
    tables = json.loads((ROOT / 'work/native-client/ogre/link/ogre_vtables.json').read_text())
    base, image = match._image('2008-06')
    rd = lambda va: struct.unpack_from('<I', image, va - base)[0]
    slots = {}
    for raw, symbol in tables.items():
        owner = owner_from_vtable(symbol)
        if not owner:
            continue
        table = int(raw, 16)
        for index in range(512):
            va = rd(table + index * 4)
            if not 0x00400000 <= va < 0x00800000:
                break
            address = '%08x' % va
            slots.setdefault(address, []).append({'owner': owner, 'vtable': raw, 'slot': index})
    return slots


def ret_bytes(address):
    body = match.target('2008-06', address)[0]
    if len(body) >= 3 and body[-3] == 0xc2:
        return struct.unpack_from('<H', body, len(body) - 2)[0]
    if body and body[-1] == 0xc3:
        return 0
    return None


def main():
    registry = json.loads((ROOT / 'work/native-client/ogre-names-registry.json').read_text())
    fieldless = json.loads((ROOT / 'work/native-client/claude-fieldless.json').read_text())
    memfn = json.loads((ROOT / 'work/native-client/claude-memfn-args.json').read_text())
    fields = {row['address']: row for row in fieldless.get('functions', [])}
    args = {row['address']: row for row in memfn.get('functions', []) if row.get('consistent')}
    slots = vtable_slots()
    rows = []
    for address, row in registry.items():
        if not row['placeholder']:
            continue
        field = fields.get(address, {})
        call = args.get(address, {})
        signatures = call.get('signatures', [])
        virtual = slots.get(address, [])
        owner = call.get('owner') or (virtual[0]['owner'] if len(virtual) == 1 else row.get('owner_class'))
        # A queue owner is only a routing hint.  Do not emit a class declaration
        # until the caller itself proves owner and a complete signature.
        ready = bool(call.get('owner') and len(signatures) == 1)
        asm = None
        if len(virtual) == 1:
            asm = {'calling_convention': '__thiscall', 'callee_stack_bytes': ret_bytes(address),
                   'vtable': virtual[0]['vtable'], 'slot': virtual[0]['slot']}
        rows.append({'addr': address, 'name': row['name'], 'owner_hint': owner,
                     'owner_proved': bool(call.get('owner') or asm), 'field_use': field.get('verdict', 'unknown'),
                     'call_signature': signatures[0] if len(signatures) == 1 else None,
                     'asm_signature': asm,
                     'status': 'declaration-ready' if ready else ('asm-owner-only' if asm else 'blocked-proof'),
                     'blocked_reason': None if ready or asm else ('no-proved-owner' if not call.get('owner')
                                                                    else 'no-unique-signature')})
    output = ROOT / 'work/native-client/ogre-placeholder-queue.json'
    output.write_text(json.dumps({'scope': 'Ogre placeholder declarations; no layout inferred', 'rows': rows}, indent=1) + '\n')
    print(json.dumps({'placeholders': len(rows), 'declaration_ready': sum(r['status'] == 'declaration-ready' for r in rows),
                      'asm_owner_only': sum(r['status'] == 'asm-owner-only' for r in rows),
                      'blocked': sum(r['status'] == 'blocked-proof' for r in rows)}, sort_keys=True))


if __name__ == '__main__':
    main()
