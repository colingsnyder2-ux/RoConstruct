"""Compare x86 this-relative access evidence; never infer complete class layouts.

Usage: --addr HEX --obj FILE --sym PREFIX --thiscall [--header FILE ...]
--thiscall explicitly asserts entry ECX is this on BOTH sides. Do not use for
static/free functions, hidden-return-pointer ABI or unverified calling conventions.
Register aliases/constant adjustments use conservative control-flow merges.
Loaded-pointer paths, indexed bases and segmented memory are classified separately;
their pointee types/index bounds are not inferred. Repeated direct calls group by
expected destination, with COFF names attached only under equal code shape.
ESP/EBP coordinates and exact 32-bit spill slots propagate through CFG merges.
Overlapping/unknown writes invalidate slots. Calls discard slots and ESP because
callee stack cleanup/escaped-local writes are unproven; dynamic alignment loses
the affected coordinate. Call-result bits get provenance, never a return type.
Calls and indirect accesses still leave uncertainty. Differences may reflect
optimization; equal observations do not prove layout/ABI/runtime.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_JUMP, CS_GRP_CALL, CS_AC_READ, CS_AC_WRITE
from capstone.x86 import X86_OP_REG, X86_OP_IMM, X86_OP_MEM, X86_REG_ESP, X86_REG_EBP

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match


def parent_register(name):
    for full, parts in [('eax', ('ax', 'al', 'ah')), ('ebx', ('bx', 'bl', 'bh')),
                        ('ecx', ('cx', 'cl', 'ch')), ('edx', ('dx', 'dl', 'dh')),
                        ('esi', ('si',)), ('edi', ('di',)), ('ebp', ('bp',)), ('esp', ('sp',))]:
        if name in parts:
            return full
    return name


def shifted(origin, displacement):
    if isinstance(origin, int):
        return origin + displacement
    return ('adjust', origin, displacement) if displacement else origin


def stack_location(operand, aliases):
    if operand.type != X86_OP_MEM or operand.mem.index or operand.mem.segment:
        return None
    frame = aliases.get(('frame_id', operand.mem.base))
    return frame + operand.mem.disp if frame is not None else None


def extract_linear(code, base=0, relocs=(), entry=None):
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    aliases = dict(entry if entry is not None else {'ecx': 0})
    if entry is None:
        aliases[('frame_id', X86_REG_ESP)] = 0
    accesses, uncertain, returns = [], [], []
    derived, indexed, context, stack = [], [], [], []
    decoded = 0
    for ins in decoder.disasm(code, base):
        decoded += ins.size
        offset = ins.address - base
        evidence = {'offset': offset, 'instruction': ins.mnemonic + ' ' + ins.op_str}
        ops = ins.operands
        relocated = any(offset <= r < offset + ins.size for r in relocs)
        for op in ops:
            if op.type != X86_OP_MEM:
                continue
            name = ins.reg_name(op.mem.base)
            relocated = any(offset <= r < offset + ins.size for r in relocs)
            location = stack_location(op, aliases)
            if location is not None and not relocated:
                stack.append({**evidence, 'entry_sp_offset': location, 'width': op.size,
                              'scope': 'observed stack location; argument/local type unknown'})
            elif op.mem.segment:
                context.append({**evidence, 'segment': ins.reg_name(op.mem.segment), 'displacement': op.mem.disp,
                                'scope': 'segmented memory; not a proven class-field access'})
            elif name in aliases and op.mem.index and not relocated:
                indexed.append({**evidence, 'base_origin': aliases[name], 'index_register': ins.reg_name(op.mem.index),
                                'scale': op.mem.scale, 'displacement': op.mem.disp, 'width': op.size,
                                'scope': 'base provenance only; dynamic index/value bounds unknown'})
            elif name in aliases and not op.mem.index and not relocated:
                if not isinstance(aliases[name], int):
                    derived.append({**evidence, 'pointer_origin': aliases[name], 'displacement': op.mem.disp,
                                    'width': op.size, 'scope': 'pointer-load path observed; pointee type/lifetime unknown'})
                    continue
                accesses.append({**evidence, 'this_offset': aliases[name] + op.mem.disp,
                                 'width': op.size, 'kind': 'address' if ins.mnemonic == 'lea' else
                                 ('read_write' if op.access == CS_AC_READ | CS_AC_WRITE else
                                  'write' if op.access & CS_AC_WRITE else 'read' if op.access & CS_AC_READ else 'unknown')})
            elif name not in ('esp', 'ebp') or name in aliases:
                uncertain.append({**evidence, 'reason': 'memory base/index/relocation not proven this-relative'})
        transfer = None
        frame_transfer = None
        stored = None
        stack_update = None
        sp = aliases.get(('frame_id', X86_REG_ESP))
        if ins.mnemonic == 'push' and sp is not None:
            location = sp - (2 if ops[0].size == 2 else 4)
            stack_update = location
            for key in list(aliases):
                if isinstance(key, tuple) and key[0] == 'slot' and key[1] < sp and location < key[1] + 4:
                    aliases.pop(key)
            if ops[0].type == X86_OP_REG and ops[0].size == 4 and ins.reg_name(ops[0].reg) in aliases:
                stored = (('slot', location), aliases[ins.reg_name(ops[0].reg)])
        elif ins.mnemonic == 'pop' and sp is not None and ops[0].type == X86_OP_REG and ops[0].reg != X86_REG_ESP:
            stack_update = sp + (2 if ops[0].size == 2 else 4)
            if ops[0].size == 4:
                transfer = (ins.reg_name(ops[0].reg), aliases.get(('slot', sp), ('stack_load', sp, base + offset)))
            aliases.pop(('slot', sp), None)
        elif ins.mnemonic == 'leave' and ('frame_id', X86_REG_EBP) in aliases:
            stack_update = aliases[('frame_id', X86_REG_EBP)] + 4
        if ins.mnemonic.startswith(('pop', 'push', 'enter', 'leave')) and ins.mnemonic not in ('push', 'pop', 'leave') or ins.mnemonic == 'pop' and ops[0].type != X86_OP_REG:
            for key in list(aliases):
                if isinstance(key, tuple) and key[0] == 'slot':
                    aliases.pop(key)
        # Save/restore only exact 32-bit slots; overlapping/unknown writes kill evidence.
        for op in ops:
            if op.type != X86_OP_MEM or not op.access & CS_AC_WRITE:
                continue
            location = stack_location(op, aliases)
            for key in list(aliases):
                if isinstance(key, tuple) and key[0] == 'slot' and (location is None or key[1] < location + op.size and location < key[1] + 4):
                    aliases.pop(key)
            if ins.mnemonic == 'mov' and location is not None and not relocated and op.size == 4 and ops[1].type == X86_OP_REG:
                value = aliases.get(ins.reg_name(ops[1].reg))
                if value is not None:
                    stored = (('slot', location), value)
        if len(ops) == 2 and ops[0].type == X86_OP_REG and ops[0].size == 4:
            dest = ins.reg_name(ops[0].reg)
            src = ops[1]
            if ins.mnemonic == 'mov' and src.type == X86_OP_REG and ('frame_id', src.reg) in aliases:
                frame_transfer = (('frame_id', ops[0].reg), aliases[('frame_id', src.reg)])
            elif ins.mnemonic == 'lea' and stack_location(src, aliases) is not None and not relocated:
                frame_transfer = (('frame_id', ops[0].reg), stack_location(src, aliases))
            elif ins.mnemonic in ('add', 'sub') and ('frame_id', ops[0].reg) in aliases and src.type == X86_OP_IMM and not relocated:
                frame_transfer = (('frame_id', ops[0].reg), aliases[('frame_id', ops[0].reg)] + src.imm * (1 if ins.mnemonic == 'add' else -1))
            if ins.mnemonic == 'mov' and src.type == X86_OP_REG and ins.reg_name(src.reg) in aliases:
                transfer = (dest, aliases[ins.reg_name(src.reg)])
            elif ins.mnemonic == 'mov' and stack_location(src, aliases) is not None and not relocated:
                location = stack_location(src, aliases)
                transfer = (dest, aliases.get(('slot', location), ('stack_load', location, base + offset)))
            elif ins.mnemonic == 'mov' and src.type == X86_OP_MEM and ins.reg_name(src.mem.base) in aliases and not src.mem.index and not src.mem.segment and not any(offset <= r < offset + ins.size for r in relocs):
                origin = aliases[ins.reg_name(src.mem.base)]
                # Bound provenance depth; never assume arbitrarily recursive pointer types.
                if len(repr(origin)) < 240:
                    transfer = (dest, ('load', origin, src.mem.disp))
            elif ins.mnemonic in ('mov', 'lea') and src.type == X86_OP_MEM and ins.reg_name(src.mem.base) in aliases and src.mem.index and not src.mem.segment and not relocated:
                origin = aliases[ins.reg_name(src.mem.base)]
                if len(repr(origin)) < 240:
                    transfer = (dest, ('indexed_load' if ins.mnemonic == 'mov' else 'indexed_address', origin,
                                       ins.reg_name(src.mem.index), src.mem.scale, src.mem.disp, base + offset))
            elif ins.mnemonic == 'lea' and src.type == X86_OP_MEM and ins.reg_name(src.mem.base) in aliases and not src.mem.index and not src.mem.segment and not any(offset <= r < offset + ins.size for r in relocs):
                transfer = (dest, shifted(aliases[ins.reg_name(src.mem.base)], src.mem.disp))
            elif ins.mnemonic in ('add', 'sub') and dest in aliases and src.type == X86_OP_IMM and not any(offset <= r < offset + ins.size for r in relocs):
                transfer = (dest, shifted(aliases[dest], src.imm * (1 if ins.mnemonic == 'add' else -1)))
        for reg in ins.regs_access()[1]:
            aliases.pop(parent_register(ins.reg_name(reg)), None)
            # Full/partial writes both invalidate any frame coordinate on that register.
            for key in list(aliases):
                if isinstance(key, tuple) and key[0] == 'frame_id' and parent_register(ins.reg_name(key[1])) == parent_register(ins.reg_name(reg)):
                    aliases.pop(key)
        if transfer:
            aliases[transfer[0]] = transfer[1]
        if frame_transfer:
            aliases[frame_transfer[0]] = frame_transfer[1]
        if stack_update is not None:
            aliases[('frame_id', X86_REG_ESP)] = stack_update
        if stored:
            aliases[stored[0]] = stored[1]
        if ins.group(CS_GRP_CALL):
            for reg in ('eax', 'ecx', 'edx'):
                aliases.pop(reg, None)
            for key in list(aliases):
                if isinstance(key, tuple) and (key[0] == 'slot' or key[0] == 'frame_id' and ins.reg_name(key[1]) in ('esp', 'eax', 'ecx', 'edx')):
                    aliases.pop(key)
            aliases['eax'] = ('call_result_bits', base + offset)
            uncertain.append({**evidence, 'relocated': any(offset <= r < offset + ins.size for r in relocs),
                              'reason': 'callee effects/argument ABI not analyzed; volatile aliases cleared'})
        if ins.group(CS_GRP_JUMP) or ins.mnemonic.startswith('ret'):
            if ins.mnemonic.startswith('ret'):
                returns.append({'offset': offset, 'stack_pop': ops[0].imm if ops else 0})
    if decoded != len(code):
        uncertain.append({'offset': decoded, 'reason': 'undecoded trailing bytes', 'bytes': len(code) - decoded})
    return {'accesses': accesses, 'uncertain': uncertain, 'returns': returns, 'derived_accesses': derived,
            'indexed_accesses': indexed, 'context_accesses': context, 'stack_accesses': stack, 'exit_aliases': aliases}


def extract(code, base=0, relocs=()):
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    instructions = {ins.address: ins for ins in decoder.disasm(code, base)}
    states, pending = {base: {'ecx': 0, ('frame_id', X86_REG_ESP): 0}}, [base]

    def step(address):
        ins = instructions[address]
        offset = address - base
        return extract_linear(bytes(ins.bytes), address,
                              [r - offset for r in relocs if offset <= r < offset + ins.size], states[address])

    while pending:
        address = pending.pop()
        if address not in instructions:
            continue
        ins = instructions[address]
        state = step(address)['exit_aliases']
        successors = []
        if ins.group(CS_GRP_JUMP):
            if ins.operands[0].type == X86_OP_IMM:
                successors.append(ins.operands[0].imm)
            if ins.mnemonic != 'jmp':
                successors.append(address + ins.size)
        elif not ins.mnemonic.startswith('ret'):
            successors.append(address + ins.size)
        for successor in successors:
            if successor not in instructions:
                continue
            previous = states.get(successor)
            merged = dict(state) if previous is None else {reg: value for reg, value in previous.items() if state.get(reg) == value}
            if previous is None or merged != previous:
                states[successor] = merged
                pending.append(successor)
    result = {key: [] for key in ('accesses', 'uncertain', 'returns', 'derived_accesses', 'indexed_accesses', 'context_accesses', 'stack_accesses')}
    for address in sorted(states):
        if address not in instructions:
            continue
        ins = instructions[address]
        observed = step(address)
        for key in result:
            for row in observed[key]:
                result[key].append({**row, 'offset': row['offset'] + address - base})
        if ins.group(CS_GRP_JUMP) and (ins.operands[0].type != X86_OP_IMM or ins.operands[0].imm not in instructions):
            result['uncertain'].append({'offset': address - base, 'reason': 'indirect/external jump; destination not analyzed'})
    decoded = sum(ins.size for ins in instructions.values())
    if decoded != len(code):
        result['uncertain'].append({'offset': decoded, 'reason': 'undecoded trailing bytes', 'bytes': len(code) - decoded})
    return result


def review_groups(evidence):
    """Deduplicate obligations without claiming unresolved semantics are solved."""
    groups = {}
    for category in ('uncertain', 'derived_accesses', 'indexed_accesses', 'context_accesses'):
        for row in evidence.get(category, []):
            if category == 'uncertain':
                key = (category, row['reason'], row.get('instruction', ''))
                if row.get('instruction', '').startswith('call ') and (row.get('relocated') or not re.fullmatch(r'call (?:0x[0-9a-f]+|\d+)', row['instruction'])):
                    key += (row['offset'],)  # Same register/addend does not imply same callee.
            else:
                key = (category, json.dumps({k: v for k, v in row.items() if k not in ('offset', 'instruction')}, sort_keys=True))
            group = groups.setdefault(key, {'category': category, 'evidence': row, 'sites': []})
            group['sites'].append(row['offset'])
    return sorted(groups.values(), key=lambda row: (-len(row['sites']), row['category']))


def call_obligations(raw, symbol, body, refs, target, target_refs, address):
    """Attach original expected destinations to COFF names only with equal code shape."""
    aligned = len(body) == len(target) and set(target_refs) <= set(refs) and match.exact_match(target, target_refs, body, refs)
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section_index = definitions[symbol]
    section = sections[section_index]
    bindings = {}
    for index in range(section[7]):
        offset, sym, kind = struct.unpack_from('<IIH', raw, section[5] + 10 * index)
        if kind == 20:
            bindings[offset - start] = symbols[sym][0]
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    groups = {}
    for ins in decoder.disasm(target, address):
        if not ins.group(CS_GRP_CALL):
            continue
        offset = ins.address - address
        direct = ins.operands[0].type == X86_OP_IMM
        destination = ins.operands[0].imm if direct else None
        name = bindings.get(offset + 1) if aligned and direct else None
        key = (destination, name) if direct else ('indirect_site', offset)
        row = groups.setdefault(key, {'expected_original_destination': hex(destination) if direct else None,
                                     'candidate_rel32_symbol': name, 'sites': [],
                                     'status': 'expected_binding_only; provider identity/callee ABI unproven' if name else 'callee_identity_unresolved'})
        row['sites'].append(offset)
    return {'code_shape_aligned': aligned, 'groups': list(groups.values()),
            'scope': 'Direct relative call bindings only; original address is an expected binding, not proof of selected provider. Each indirect site remains separate.'}


def compare(target, candidate):
    def counts(value):
        return Counter((row['this_offset'], row['width'], row['kind']) for row in value['accesses'])
    a, b = counts(target), counts(candidate)
    def rows(counter):
        return [{'this_offset': key[0], 'width': key[1], 'kind': key[2], 'count': count}
                for key, count in sorted(counter.items())]
    return {'shared': rows(a & b), 'target_only': rows(a - b), 'candidate_only': rows(b - a),
            'observed_stack_pops_equal': sorted(r['stack_pop'] for r in target['returns']) == sorted(r['stack_pop'] for r in candidate['returns']),
            'interpretation': 'Observed accesses only. Differences need review; equality is not layout or ABI proof.'}


def header_assertions(path):
    text = path.read_text(encoding='utf-8-sig', errors='replace')
    pattern = r'(offsetof\s*\(\s*([^,()]+)\s*,\s*([^()]+)\)|sizeof\s*\(\s*([^()]+)\))\s*==\s*(0x[0-9a-fA-F]+|\d+)\b'
    return [{'line': text.count('\n', 0, hit.start()) + 1, 'expression': hit[1], 'expected': int(hit[5], 0),
             'status': 'source_assertion_uncompiled'} for hit in re.finditer(pattern, text)]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--client', default='2008-06')
    parser.add_argument('--addr', required=True)
    parser.add_argument('--obj', required=True, type=Path)
    parser.add_argument('--sym', required=True, help='exact decorated symbol or unique prefix')
    parser.add_argument('--thiscall', required=True, action='store_true')
    parser.add_argument('--header', type=Path, action='append', default=[])
    parser.add_argument('--output', type=Path, default=ROOT / 'work/2008-06/shared-layouts/native-layout-evidence.json')
    args = parser.parse_args()
    raw = args.obj.read_bytes()
    hits = [row for row in match.coff_functions(raw) if row[0] == args.sym]
    if not hits:
        hits = [row for row in match.coff_functions(raw) if row[0].startswith(args.sym)]
    if len(hits) != 1:
        parser.error(f'expected one candidate symbol, found {len(hits)}; use exact decorated symbol')
    symbol, body, refs = hits[0]
    addr = int(args.addr, 16)
    target, target_refs, _ = match.target(args.client, f'{addr:08x}')
    original = extract(target, addr, target_refs)
    candidate = extract(body, addr, refs)
    result = {'scope': __doc__, 'client': args.client, 'address': f'{addr:08x}', 'symbol': symbol,
              'entry_assumption': 'User asserts ECX=this on both sides; no hidden return pointer',
              'object': str(args.obj.resolve()), 'object_sha256': hashlib.sha256(raw).hexdigest(),
              'target_bytes_sha256': hashlib.sha256(target).hexdigest(),
              'observer_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
              'target': original, 'candidate': candidate, 'comparison': compare(original, candidate),
              'review_groups': {'target': review_groups(original), 'candidate': review_groups(candidate)},
              'call_obligations': call_obligations(raw, symbol, body, refs, target, target_refs, addr),
              'headers': [{'path': str(p.resolve()), 'sha256': hashlib.sha256(p.read_bytes()).hexdigest(),
                           'assertions': header_assertions(p)} for p in args.header]}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    diff = result['comparison']
    print(f"Access groups: {len(diff['shared'])} shared, {len(diff['target_only'])} target-only, {len(diff['candidate_only'])} candidate-only")
    print(f"Uncertain observations: target={len(original['uncertain'])}, candidate={len(candidate['uncertain'])}")
    print('Target evidence groups:', dict(Counter(row['category'] for row in result['review_groups']['target'])))
    print(args.output.resolve())


if __name__ == '__main__':
    main()
