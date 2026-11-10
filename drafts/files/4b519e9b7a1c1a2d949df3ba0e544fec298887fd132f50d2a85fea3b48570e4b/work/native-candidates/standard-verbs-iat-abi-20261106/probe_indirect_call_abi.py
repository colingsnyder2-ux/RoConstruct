"""Indirect-call ABI proof for recovered StandardVerbs bodies (2008-06).

The isolated native runner verifies exact bytes, referenced data and reviewed
DIRECT-call symbol/address bindings.  Every call it cannot bind with a direct
REL32 relocation stays an explicit blocker: `std::string` construction and
`std::operator+` in the recovered `StandardVerbs` bodies are compiled as calls
through the MSVCP90 import address table, so no direct binding exists.

This probe closes exactly that obligation, and nothing more:

  1. the original client's own import directory is parsed with pefile to map each
     IAT slot virtual address to its DLL and exact decorated import name, so the
     callee identity is established from the original binary and never from the
     candidate;
  2. the ORIGINAL body at the target address is disassembled and every call site
     is classified direct (`e8` REL32) or indirect, and each indirect site is
     traced to the IAT slot it reads (either `call dword ptr [slot]` or a register
     loaded by a preceding `mov reg, dword ptr [slot]`);
  3. the already compiled candidate object is disassembled at the same offsets:
     the call instruction bytes must be identical, and the COFF relocation that
     covers the IAT operand must name an external that is the import-lib symbol
     for that exact original import (`__imp_` + decorated name);
  4. both the original import name and the candidate external are demangled with
     the historical `undname.exe` from the same VC2008 RTM toolchain, and the
     argument-setup instructions preceding each call are compared byte for byte.

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
import re
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
    out = {}
    if not tool.is_file():
        return {'__tool__': str(tool), '__available__': False}
    for name in sorted(set(names)):
        with tempfile.TemporaryDirectory() as tmp:
            script = Path(tmp) / 'names.txt'
            script.write_text(name + '\n', encoding='ascii')
            try:
                proc = subprocess.run([str(tool), str(script)], capture_output=True,
                                      text=True, timeout=120)
            except OSError as error:
                return {'__tool__': str(tool), '__available__': False, '__error__': str(error)}
        lines = [l.rstrip() for l in proc.stdout.splitlines() if l.strip()]
        picked = [l for l in lines if not l.startswith('Microsoft (R)')]
        out[name] = picked[-1] if picked else None
    return out


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
    return matches[0], start, table, relocs


def call_sites(body, address, imports, window=24):
    """Classify every call in an x86 body and trace indirect ones to an IAT slot."""
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    instructions = list(decoder.disasm(body, address))
    index = {ins.address - address: ins for ins in instructions}
    sites = []
    for pos, ins in enumerate(instructions):
        if ins.mnemonic != 'call':
            continue
        offset = ins.address - address
        op = ins.operands[0]
        row = {'offset': offset, 'bytes': ins.bytes.hex(), 'size': ins.size,
               'kind': 'unclassified', 'operand': None}
        if op.type == X86_OP_IMM:
            row.update(kind='direct_rel32', operand='%08x' % op.imm)
        elif op.type == X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
            slot = op.mem.disp
            row.update(kind='indirect_absolute_slot', operand='%08x' % slot,
                       operand_offset=offset + 2,
                       iat_slot=slot, iat=imports.get(slot))
        elif op.type == X86_OP_REG:
            # look back for the nearest `mov <reg>, dword ptr [slot]`
            reg = ins.operands[0].reg
            for back in range(pos - 1, max(-1, pos - window), -1):
                prev = instructions[back]
                if prev.mnemonic != 'mov' or len(prev.operands) != 2:
                    continue
                dst, src = prev.operands
                if dst.type != X86_OP_REG or dst.reg != reg:
                    continue
                if src.type != X86_OP_MEM or src.mem.base != 0 or src.mem.index != 0:
                    continue
                slot = src.mem.disp
                row.update(kind='indirect_register_slot', operand='reg',
                           loader_offset=prev.address - address,
                           loader_bytes=prev.bytes.hex(),
                           loader_operand_offset=(prev.address - address) + 2,
                           iat_slot=slot, iat=imports.get(slot))
                break
        row['argument_setup'] = [i.bytes.hex() for i in instructions[max(0, pos - 6):pos]]
        sites.append(row)
    return sites, index


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--client', default='2008-06')
    parser.add_argument('--object', required=True)
    parser.add_argument('--run', default='')
    parser.add_argument('--receipt', required=True)
    parser.add_argument('checks', nargs='+', help='ADDR:SYMBOL pairs')
    args = parser.parse_args()

    imports = original_imports(args.client)
    raw = Path(args.object).read_bytes()
    demangled_cache = {}

    report = {
        'schema': 1,
        'workflow': 52,
        'client': args.client,
        'scope': ('Indirect-call ABI only: the same imported callee, reached through the same '
                  'IAT slot with the same declared ABI and the same argument setup as the '
                  'original client. Direct-call bindings, referenced data, provider selection, '
                  'linked selection, EH/tail-jump identity and runtime gates are separate '
                  'obligations and are asserted by the runner receipt, not here.'),
        'object': str(args.object),
        'object_sha256': sha(args.object),
        'imports_observed': {('%08x' % slot): value for slot, value in sorted(imports.items())
                             if value['dll'].lower().endswith('msvcp90.dll')},
        'bodies': [],
    }
    failures = []

    for item in args.checks:
        addr, symbol = item.split(':', 1)
        address = int(addr, 16)
        target, refs, _ = match.target(args.client, addr)
        body_name, start, section, relocs = candidate_relocations(raw, symbol)
        candidate = [b for b in match.coff_functions(raw) if b[0] == body_name][0][1]
        # A COFF object stores a zero addend at every relocated operand, so raw byte
        # equality is only meaningful outside relocated windows.  Mask both bodies with
        # the union of the original and candidate relocation coverage and compare that.
        covered = set()
        for offset in list(refs) + [r[0] for r in [b for b in match.coff_functions(raw) if b[0] == body_name][0][2]]:
            covered |= set(range(offset, offset + 4))
        target_masked = bytes(0 if i in covered else b for i, b in enumerate(target))
        candidate_masked = bytes(0 if i in covered else b for i, b in enumerate(candidate))
        original_sites, _ = call_sites(target, address, imports)
        candidate_sites, _ = call_sites(candidate, 0, imports)

        row = {
            'addr': addr,
            'symbol': body_name,
            'target_size': len(target),
            'candidate_size': len(candidate),
            'byte_identical': target_masked == candidate_masked,
            'raw_bytes_identical': target == candidate,
            'relocated_windows': len(covered),
            'target_sha256': hashlib.sha256(target).hexdigest(),
            'candidate_sha256': hashlib.sha256(candidate).hexdigest(),
            'indirect_sites': [],
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
                'instruction_bytes_identical': bool(pair and pair['bytes'] == site['bytes']),
                'operand_kind': site['kind'],
                'iat_slot': '%08x' % site['iat_slot'] if site.get('iat_slot') else None,
                'original_import': site.get('iat'),
                'argument_setup_bytes': site['argument_setup'],
                'candidate_argument_setup_bytes': pair['argument_setup'] if pair else None,
                'argument_setup_identical': bool(pair and pair['argument_setup'] == site['argument_setup']),
            }
            operand_offset = site.get('operand_offset') or site.get('loader_operand_offset')
            entry['operand_offset'] = operand_offset
            entry['candidate_relocation'] = relocs.get(operand_offset) if operand_offset is not None else None
            if site.get('loader_bytes'):
                entry['loader_bytes'] = site['loader_bytes']
                entry['candidate_loader_bytes'] = pair.get('loader_bytes') if pair else None
                entry['loader_bytes_identical'] = bool(pair and pair.get('loader_bytes') == site['loader_bytes'])
            expected = ('__imp_' + site['iat']['import']) if site.get('iat') else None
            got = entry['candidate_relocation']['symbol'] if entry['candidate_relocation'] else None
            entry['expected_external'] = expected
            entry['candidate_external'] = got
            entry['external_matches_original_import'] = bool(expected and got in (expected, site['iat']['import']))
            for name in (site['iat']['import'] if site.get('iat') else None, got):
                if name and name not in demangled_cache:
                    demangled_cache[name] = None
            row['indirect_sites'].append(entry)
            if not (entry['instruction_bytes_identical'] and entry['external_matches_original_import']
                    and entry['argument_setup_identical']):
                failures.append('%s@%d' % (body_name, entry['offset']))
        report['bodies'].append(row)

    demangled = undname(demangled_cache)
    report['demangle'] = {'tool': demangled.get('__tool__'), 'available': demangled.get('__available__', True),
                          'names': {k: v for k, v in demangled.items() if not k.startswith('__')}}
    report['totals'] = {
        'bodies': len(report['bodies']),
        'indirect_sites': sum(len(b['indirect_sites']) for b in report['bodies']),
        'verified': sum(1 for b in report['bodies'] for s in b['indirect_sites']
                        if s['instruction_bytes_identical'] and s['external_matches_original_import']
                        and s['argument_setup_identical']),
        'byte_identical_bodies': sum(1 for b in report['bodies'] if b['byte_identical']),
        'direct_sites': sum(b['direct_sites'] for b in report['bodies']),
        'unclassified_sites': sum(b['unclassified_sites'] for b in report['bodies']),
    }
    report['indirect_call_bindings_verified'] = (
        report['totals']['verified'] == report['totals']['indirect_sites']
        and report['totals']['indirect_sites'] > 0
        and not report['totals']['unclassified_sites'])
    report['failures'] = failures
    Path(args.receipt).parent.mkdir(parents=True, exist_ok=True)
    Path(args.receipt).write_text(json.dumps(report, indent=1, sort_keys=True), encoding='utf-8')
    print(json.dumps({'receipt': str(args.receipt), 'totals': report['totals'],
                      'verified': report['indirect_call_bindings_verified'],
                      'failures': failures[:10]}, indent=1))
    return 0 if report['indirect_call_bindings_verified'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
