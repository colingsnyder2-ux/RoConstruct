"""Indirect-call ABI proof for recovered StandardVerbs bodies (2008-06).

The isolated native runner verifies exact bytes, referenced data and reviewed
DIRECT-call symbol/address bindings.  Every call it cannot bind with a direct
REL32 relocation stays an explicit blocker: `std::string` construction and
`std::operator+` in the recovered `StandardVerbs` bodies are compiled as calls
through the MSVCP90 import address table, so no direct binding exists for them.

This probe closes exactly that obligation, and nothing more:

  1. the original client's own import directory is parsed with pefile to map each
     IAT slot virtual address to its DLL and exact decorated import name, so the
     callee identity is established from the original binary and never from the
     candidate;
  2. the ORIGINAL body at the target address is disassembled and every call site
     is classified direct (`e8` REL32) or indirect, and each indirect site is
     traced to the IAT slot it reads (either `call dword ptr [slot]` or a register
     loaded by the nearest preceding `mov reg, dword ptr [slot]`);
  3. the already compiled candidate object is disassembled at the same offsets:
     the instruction, loader and argument-setup bytes must be identical once the
     relocated windows are masked, and the COFF relocation that covers the IAT
     operand must name an external that is the import-lib symbol for that exact
     original import (`__imp_` + decorated name);
  4. both the original import name and the candidate external are demangled with
     the historical `undname.exe` from the same VC2008 RTM toolchain.

What this proves: the recovered source calls the same imported function, through
the same IAT slot, with the same declared ABI and the same argument setup, as the
original client.
What this does NOT prove: callee ABI of any direct call, provider selection in a
linked image, linked selection of these bodies, EH/tail-jump/data identity beyond
the runner's data check, or runtime/P5/P6 safety.  Those remain separate
obligations.
"""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve()
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[3])
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG

from roc import match


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def original_imports(client):
    """IAT slot virtual address -> {dll, import} read from the ORIGINAL client."""
    import pefile
    from roc import clients
    entry = clients.load()[client]
    pe = pefile.PE(str(clients.exe_path(client, entry)), fast_load=True)
    pe.parse_data_directories([pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
    out = {}
    for dll in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []):
        for imp in dll.imports:
            name = imp.name.decode() if imp.name else '#%d' % imp.ordinal
            out[imp.address] = {'dll': dll.dll.decode(), 'import': name}
    return out


def undname(names):
    """Demangle MSVC decorated names with the historical undname from this toolchain."""
    tool = ROOT / 'tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/bin/undname.exe'
    if not tool.is_file():
        return {'__available__': False, '__tool__': str(tool)}
    out = {}
    for name in sorted(set(names)):
        with tempfile.TemporaryDirectory() as tmp:
            script = Path(tmp) / 'names.txt'
            script.write_text(name + '\n', encoding='ascii')
            try:
                proc = subprocess.run([str(tool), str(script)], capture_output=True,
                                      text=True, timeout=120)
            except OSError as error:
                return {'__available__': False, '__tool__': str(tool), '__error__': str(error)}
        lines = [l.rstrip() for l in proc.stdout.splitlines() if l.strip()]
        picked = [l for l in lines if not l.startswith('Microsoft (R)')]
        out[name] = picked[-1] if picked else None
    return {'__available__': True, '__tool__': str(tool), 'names': out}


def candidate_relocations(raw, symbol):
    """COFF relocation offset (relative to the function body) -> external name."""
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    matches = [s for s in definitions if s == symbol] or [s for s in definitions if s.startswith(symbol)]
    if len(matches) != 1:
        raise ValueError('candidate symbol missing or ambiguous for %s' % symbol)
    start, section = definitions[matches[0]]
    table = sections[section]
    relocs = {}
    for index in range(table[7]):
        offset, name, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * index)
        relocs[offset - start] = {'symbol': symbols[name][0], 'type': kind}
    return matches[0], start, relocs


def window(data, start, end, covered):
    """Body bytes [start:end) with relocated 4-byte windows zeroed."""
    return bytes(0 if (start + i) in covered else b for i, b in enumerate(data[start:end])).hex()


def call_sites(body, address, imports):
    """Classify every call in an x86 body and trace indirect ones to an IAT slot."""
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    instructions = list(decoder.disasm(body, address))
    definitions = {}
    sites = []
    for pos, ins in enumerate(instructions):
        _, written = ins.regs_access()
        for reg in written:
            definitions[reg] = (pos, ins)
        if ins.mnemonic != 'call':
            continue
        offset = ins.address - address
        op = ins.operands[0]
        row = {'offset': offset, 'bytes': body[offset:offset + ins.size].hex(),
               'size': ins.size, 'kind': 'unclassified', 'operand': None}
        if op.type == X86_OP_IMM:
            row.update(kind='direct_rel32', operand='%08x' % op.imm)
        elif op.type == X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
            slot = op.mem.disp
            row.update(kind='indirect_absolute_slot', operand='%08x' % slot,
                       operand_offset=offset + 2,
                       iat_slot=slot, iat=imports.get(slot))
        elif op.type == X86_OP_REG:
            reg = op.reg
            source = definitions.get(reg)
            if source and source[1].mnemonic == 'mov' and len(source[1].operands) == 2:
                dst, src = source[1].operands
                if dst.type == X86_OP_REG and dst.reg == reg and src.type == X86_OP_MEM \
                        and src.mem.base == 0 and src.mem.index == 0:
                    slot = src.mem.disp
                    loader_offset = source[1].address - address
                    row.update(kind='indirect_register_slot', operand='reg',
                               loader_offset=loader_offset,
                               loader_bytes=body[loader_offset:loader_offset + source[1].size].hex(),
                               loader_operand_offset=loader_offset + 2,
                               iat_slot=slot, iat=imports.get(slot))
            if row['kind'] == 'unclassified':
                # A register-indirect call whose register was not loaded from an absolute
                # address is a virtual dispatch (or another computed target): a separate
                # obligation, not an IAT import binding.
                row.update(kind='virtual_dispatch',
                           scope=('indirect call through a register loaded from a computed/vtable address; '
                                  'not an IAT import, so this probe does not assert its ABI'))
        setup_start = instructions[max(0, pos - 6)].address - address
        row['argument_setup'] = {'offset': setup_start,
                                 'bytes': body[setup_start:offset].hex()}
        sites.append(row)
    return sites, definitions


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--client', default='2008-06')
    parser.add_argument('--object', required=True)
    parser.add_argument('--receipt', required=True)
    parser.add_argument('checks', nargs='+', help='ADDR:SYMBOL pairs')
    args = parser.parse_args()

    imports = original_imports(args.client)
    raw = Path(args.object).read_bytes()
    report = {
        'schema': 1,
        'workflow': 52,
        'client': args.client,
        'scope': ('Indirect-call ABI only: the same imported callee, reached through the same '
                  'IAT slot with the same declared ABI and the same argument setup as the '
                  'original client. Direct-call bindings, referenced data, provider selection, '
                  'linked selection, EH/tail-jump identity and runtime gates are separate '
                  'obligations and are asserted by the runner receipt, not here. Register-indirect '
                  'virtual dispatch sites are counted separately and are not IAT import bindings.'),
        'object': str(args.object),
        'object_sha256': sha(args.object),
        'bodies': [],
    }
    failures = []
    for item in args.checks:
        addr, symbol = item.split(':', 1)
        address = int(addr, 16)
        target, refs, _ = match.target(args.client, addr)
        body_name, _, relocs = candidate_relocations(raw, symbol)
        candidate = [b for b in match.coff_functions(raw) if b[0] == body_name][0][1]
        covered = set()
        for offset in list(refs) + list(relocs):
            covered |= set(range(offset, offset + 4))
        original_sites, _ = call_sites(target, address, imports)
        candidate_sites, _ = call_sites(candidate, 0, imports)

        row = {
            'addr': addr,
            'symbol': body_name,
            'target_size': len(target),
            'candidate_size': len(candidate),
            'byte_identical': window(target, 0, len(target), covered)
            == window(candidate, 0, len(candidate), covered),
            'target_sha256': hashlib.sha256(target).hexdigest(),
            'candidate_sha256': hashlib.sha256(candidate).hexdigest(),
            'relocated_windows': len(covered),
            'indirect_sites': [],
            'virtual_dispatch_sites': len([s for s in original_sites if s['kind'] == 'virtual_dispatch']),
            'direct_sites': len([s for s in original_sites if s['kind'] == 'direct_rel32']),
            'unclassified_sites': len([s for s in original_sites if s['kind'] == 'unclassified']),
        }
        for site in original_sites:
            if site['kind'] == 'direct_rel32':
                continue
            pair = next((c for c in candidate_sites if c['offset'] == site['offset']), None)
            entry = {
                'offset': site['offset'],
                'instruction_bytes': site['bytes'],
                'candidate_bytes': pair['bytes'] if pair else None,
                'instruction_bytes_identical': bool(pair and window(target, site['offset'],
                                                                    site['offset'] + site['size'], covered)
                                                     == window(candidate, site['offset'],
                                                               site['offset'] + site['size'], covered)),
                'operand_kind': site['kind'],
                'iat_slot': '%08x' % site['iat_slot'] if site.get('iat_slot') else None,
                'iat_resolved_in_original_import_table': bool(site.get('iat')),
                'original_import': site.get('iat'),
                'argument_setup_bytes': site['argument_setup']['bytes'],
                'candidate_argument_setup_bytes': pair['argument_setup']['bytes'] if pair else None,
                'argument_setup_identical': bool(pair and site['argument_setup']['offset'] == pair['argument_setup']['offset']
                                                 and window(target, site['argument_setup']['offset'], site['offset'], covered)
                                                 == window(candidate, pair['argument_setup']['offset'], site['offset'], covered)),
            }
            operand_offset = site.get('operand_offset') or site.get('loader_operand_offset')
            entry['operand_offset'] = operand_offset
            entry['candidate_relocation'] = relocs.get(operand_offset) if operand_offset is not None else None
            if site.get('loader_offset') is not None:
                entry['loader_bytes'] = site['loader_bytes']
                entry['candidate_loader_bytes'] = pair['loader_bytes'] if pair else None
                entry['loader_bytes_identical'] = bool(pair and window(target, site['loader_offset'],
                                                                      site['loader_offset'] + len(site['loader_bytes']) // 2, covered)
                                                       == window(candidate, site['loader_offset'],
                                                                 site['loader_offset'] + len(site['loader_bytes']) // 2, covered))
            expected = ('__imp_' + site['iat']['import']) if site.get('iat') else None
            got = entry['candidate_relocation']['symbol'] if entry['candidate_relocation'] else None
            entry['expected_external'] = expected
            entry['candidate_external'] = got
            entry['candidate_relocation_is_import_symbol'] = bool(
                got and site.get('iat') and got in ('__imp_' + site['iat']['import'], site['iat']['import']))
            ok = (entry['iat_resolved_in_original_import_table']
                  and entry['candidate_relocation_is_import_symbol']
                  and entry['instruction_bytes_identical']
                  and entry['argument_setup_identical']
                  and entry.get('loader_bytes_identical', True))
            entry['verified_indirect_call_binding'] = ok
            if not ok:
                failures.append('%s@%d' % (body_name, entry['offset']))
            row['indirect_sites'].append(entry)
        report['bodies'].append(row)

    names = set()
    for body in report['bodies']:
        for site in body['indirect_sites']:
            if site['original_import']:
                names.add(site['original_import']['import'])
            if site['candidate_external']:
                names.add(site['candidate_external'])
    report['demangle'] = undname(names)
    report['totals'] = {
        'bodies': len(report['bodies']),
        'indirect_sites': sum(len(b['indirect_sites']) for b in report['bodies']),
        'verified': sum(1 for b in report['bodies'] for s in b['indirect_sites'] if s['verified_indirect_call_binding']),
        'byte_identical_bodies': sum(1 for b in report['bodies'] if b['byte_identical']),
        'direct_sites': sum(b['direct_sites'] for b in report['bodies']),
        'unclassified_sites': sum(b['unclassified_sites'] for b in report['bodies']),
        'virtual_dispatch_sites': sum(b['virtual_dispatch_sites'] for b in report['bodies']),
    }
    report['indirect_call_bindings_verified'] = (
        report['totals']['verified'] == report['totals']['indirect_sites']
        and report['totals']['indirect_sites'] > 0
        and not report['totals']['unclassified_sites']
        and report['totals']['byte_identical_bodies'] == report['totals']['bodies'])
    report['failures'] = failures
    Path(args.receipt).parent.mkdir(parents=True, exist_ok=True)
    Path(args.receipt).write_text(json.dumps(report, indent=1, sort_keys=True), encoding='utf-8')
    print(json.dumps({'receipt': str(args.receipt), 'totals': report['totals'],
                      'verified': report['indirect_call_bindings_verified'],
                      'failures': failures[:10]}, indent=1))
    return 0 if report['indirect_call_bindings_verified'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
