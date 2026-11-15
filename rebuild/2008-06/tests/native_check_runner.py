"""Background native diagnostics: compile each source once, reuse isolated objects.

start MANIFEST launches hidden background work; status RUN reads a compact receipt.
run MANIFEST runs in foreground. analyze RUN [--manifest MANIFEST] compares the
recorded objects again WITHOUT compiling. Add --index-output PATH to analyze one
reviewed source and write a new inactive receipt only if all proof checks pass.
PATH must be a new JSON file in work/2008-06/shared-layouts. Successful object files cache under
work/2008-06/native-object-cache after source, dependencies, include search trees, compiler and environment inputs match.
Manifest: {"jobs":[{"source":
"native-classes/Foo.cpp","checks":[{"addr":"00500000","symbol":"?foo@"}],
"ranges":["00500000-00510000"],"layouts":[{"addr":"00500000","symbol":"?foo@",
"thiscall":true}]}]}. Source paths relative to rebuild/2008-06; other CLI paths
relative to cwd. Three workers default. No client run,
link, server match or P5/P6 gate. Range hits prove masked bytes, not identity.
Optional manifest compiler_build selects 21022 (default) or 50727; the recorded
compiler is retained during analysis. Optional compiler_variant="rtm" selects
the installed VS2005 RTM toolchain instead of the default detected 50727 release.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import subprocess
import struct
import sys
import time
import uuid

ROOT = Path(__file__).resolve().parents[3]
BASE = ROOT / 'rebuild/2008-06'
RUNS = ROOT / 'work/2008-06/native-check-runs'
CACHE = ROOT / 'work/2008-06/native-object-cache'
sys.path.insert(0, str(ROOT))
from roc import libs, match, rebuild, native_work


# Original IWorkspace COM slots (IDispatch + SaveToFile/SaveSelectionToFile).
# See record_native_workspace_save.py; verify the original slot before trusting a label.
METHOD_IDENTITIES = {
    '?SaveToFile@CWorkspace@@UAGJPA_W@Z': ('0046c780', 0x80ae88),
    '?SaveSelectionToFile@CWorkspace@@UAGJPA_W@Z': ('0046b8d0', 0x80ae8c),
}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def save(path, value):
    temporary = path.with_name(path.name + '.' + uuid.uuid4().hex + '.tmp')
    temporary.write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')
    try:
        for attempt in range(10):
            try:
                os.replace(temporary, path)
                break
            except PermissionError as error:
                if getattr(error, 'winerror', None) != 5 or attempt == 9:
                    raise
                time.sleep(0.05 * (attempt + 1))
    finally:
        temporary.unlink(missing_ok=True)


def compiler_build(data):
    build = data.get('compiler_build', 21022)
    if type(build) is not int or build not in (21022, 50727):
        raise ValueError('compiler_build must be 21022 or 50727')
    return build


def compiler_variant(data):
    variant = data.get('compiler_variant', 'default')
    if variant not in ('default', 'rtm') or (variant == 'rtm' and compiler_build(data) != 50727):
        raise ValueError('compiler_variant must be default or 50727 rtm')
    return variant


def selected_toolchain(data):
    build = compiler_build(data)
    variant = compiler_variant(data)
    tc = rebuild.toolchain(build)
    if variant == 'rtm':
        vc = ROOT / 'tools/vc2005/Program Files/Microsoft Visual Studio 8/VC'
        tc.update(cl=vc / 'bin/cl.exe', link=vc / 'bin/link.exe', lib=vc / 'bin/lib.exe',
                  vc_include=vc / 'include', vc_lib=vc / 'lib', crt=vc / 'lib/msvcrt.lib',
                  mspdb=vc.parent / 'Common7/IDE/mspdb80.dll')
        if not tc['cl'].is_file() or not tc['vc_include'].is_dir():
            raise ValueError('VS2005 RTM compiler or headers unavailable')
    return tc


def jobs_from(data):
    jobs = {}
    if not data.get('jobs'):
        raise ValueError('manifest needs nonempty jobs')
    for item in data['jobs']:
        source = (BASE / item['source']).resolve()
        if not source.is_file():
            raise ValueError('missing source: ' + str(source))
        job = jobs.setdefault(str(source).casefold(), {'source': str(source), 'checks': [], 'ranges': [], 'layouts': []})
        for field in ('checks', 'ranges', 'layouts'):
            for value in item.get(field, []):
                if field == 'ranges':
                    lo, hi = (int(s, 16) for s in value.split('-'))
                    if lo >= hi:
                        raise ValueError('range needs LO < HI')
                else:
                    int(value['addr'], 16)
                    if not value.get('symbol'):
                        raise ValueError('check/layout needs symbol')
                    if field == 'layouts' and value.get('thiscall') is not True:
                        raise ValueError('layout needs explicit thiscall=true')
                if value not in job[field]:
                    job[field].append(value)
    return list(jobs.values())


def compiler_flags(source, override=None):
    recipe = libs.RECIPES['rbxgs']
    headers = str(BASE / 'native-headers')
    pinned = re.search(r'^// native-flags: (.*)$', source.read_text(encoding='utf-8-sig'), re.M)
    profile = override or os.environ.get('NATIVE_FLAGS') or (pinned[1] if pinned else '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS')
    flags = ['/nologo', '/c'] + profile.replace('{headers}', headers).split()
    # Runner owns output paths; reject overrides that could collide with other work.
    if any(flag.lower().startswith(('/fo', '/fd', '/yc', '/yu'))
           or flag.lower().startswith('/fp') and not flag.lower().startswith('/fp:')
           or flag.lower().startswith('/fa') and not flag.lower().startswith('/favor:')
           or flag.startswith('@') for flag in flags):
        raise ValueError('profile output/PCH/response flags unsupported in isolated runner')
    flags = ['/DBOOST_ALL_NO_LIB'] + ['/D' + v for v in recipe['defines'].split()] + flags
    flags += ['/I' + headers, '/I' + str(ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
    flags += ['/I' + str((libs.LIBS / v).resolve()) for v in recipe['include'] if v != 'WINSDK']
    return flags + ['/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK', '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source')]


def import_evidence():
    """Read PE import names and configured VC9 CRT/SDK import-library aliases."""
    from roc import clients
    import pefile
    image = clients.exe_path('2008-06', clients.load()['2008-06'])
    image_data = image.read_bytes()
    hashes = {str(image): hashlib.sha256(image_data).hexdigest()}
    pe = pefile.PE(data=image_data, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
    labels = {}
    for descriptor in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []):
        dll = descriptor.dll.decode('ascii')
        for entry in descriptor.imports:
            if entry.name is None:
                continue  # Ordinal imports need their own independent proof.
            if entry.address in labels:
                raise ValueError('Duplicate PE import address')
            labels[entry.address] = dll + '!' + entry.name.decode('ascii')
    pe.close()
    aliases = {}
    directory = ROOT / 'tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/lib'
    paths = [directory / name for name in ('msvcrt.lib', 'msvcprt.lib')]
    sdk = rebuild.toolchain(21022).get('sdk_lib')
    if sdk:
        for name in ('Kernel32.Lib', 'WS2_32.Lib', 'Advapi32.Lib', 'OleAut32.Lib'):
            path = Path(sdk) / name
            if path.is_file():
                paths.append(path)
    # Resolve ordinal-only SDK imports against the actual 32-bit DLL exports.
    ordinal_exports = {}
    for name in ('ws2_32', 'oleaut32'):
        dll_path = Path(os.environ.get('SystemRoot', r'C:\Windows')) / 'SysWOW64' / (name + '.dll')
        if dll_path.is_file() and any(p.name.lower() == name + '.lib' for p in paths):
            data = dll_path.read_bytes()
            dll = pefile.PE(data=data, fast_load=True)
            if dll.FILE_HEADER.Machine == 0x14c:
                dll.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXPORT']])
                ordinal_exports[name + '.dll'] = {entry.ordinal: entry.name.decode('ascii')
                                                  for entry in dll.DIRECTORY_ENTRY_EXPORT.symbols if entry.name}
                hashes[str(dll_path)] = hashlib.sha256(data).hexdigest()
            dll.close()
    for path in paths:
        data = path.read_bytes()
        hashes[str(path)] = hashlib.sha256(data).hexdigest()
        if not data.startswith(b'!<arch>\n'):
            raise ValueError('Invalid CRT import library: ' + str(path))
        offset = 8
        while offset + 60 <= len(data):
            size = int(data[offset + 48:offset + 58])
            member = data[offset + 60:offset + 60 + size]
            offset += 60 + size + (size & 1)
            if member[:4] != b'\0\0\xff\xff':
                continue
            symbol, dll = member[20:].split(b'\0')[:2]
            symbol, dll = symbol.decode('ascii'), dll.decode('ascii').lower()
            name_type = (struct.unpack_from('<H', member, 18)[0] >> 2) & 7
            if name_type == 0 and dll in ordinal_exports:
                ordinal = struct.unpack_from('<H', member, 16)[0]
                export = ordinal_exports[dll].get(ordinal)
                if not export or symbol.lstrip('_@').split('@', 1)[0] != export:
                    continue
            elif name_type == 1:
                export = symbol
            elif name_type in (2, 3):
                export = symbol[1:] if symbol[:1] in ('_', '@', '?') else symbol
                if name_type == 3:
                    export = export.split('@', 1)[0]
            else:
                continue
            aliases.setdefault((dll, export), set()).add('__imp_' + symbol)
    return labels, aliases, hashes


def check_noncall_refs(raw, symbol, body, target, data_refs, calls, expected, address=None):
    """Account for every absolute relocation, including globals and callbacks.

    Reviewed call imports are covered by the separate call proof. Read-only
    local constants must compare in full and contain no nested relocations.
    Other pointers require an explicit independently reviewed identity.
    """
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    declarations = {row['offset']: row for row in expected}
    if len(declarations) != len(expected):
        raise ValueError('duplicate reference expectation offset')
    covered = set()
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    instructions = {i.address: i for i in decoder.disasm(target, 0)}
    for call in calls:
        if call.get('kind') == 'import':
            covered.add(call['offset'] + 2)
        elif call.get('kind') == 'import_reg':
            load = instructions.get(call.get('load_offset'))
            if load and load.disp_size == 4:
                covered.add(call['load_offset'] + load.disp_offset)
    constants = {off: (off, data, inner) for off, data, inner in data_refs
                 if 0 <= off and off + 4 <= len(target)}
    rows, imports = [], None
    for i in range(table[7]):
        offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
        off = offset - start
        if kind != 6 or not 0 <= off < len(body):
            continue
        name, value, number, _ = symbols[index]
        if off in covered:
            rows.append({'offset': off, 'symbol': name, 'status': 'verified_call_import'})
            continue
        actual = int.from_bytes(target[off:off + 4], 'little') if off + 4 <= len(target) else None
        if (name == '__ehhandler$' + symbol and actual is not None
                and body[off:off + 4] == b'\0\0\0\0'):
            if imports is None:
                imports = import_evidence()
            module_path = Path(__file__).with_name('native_simple_eh_proof.py')
            spec = importlib.util.spec_from_file_location('native_simple_eh_proof', module_path)
            module = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(module)
            image_base, image = match._image('2008-06')
            if module.verify(raw, symbol, actual, (sections, symbols, definitions, starts), image_base, image, imports):
                rows.append({'offset': off, 'symbol': name, 'target': f'{actual:08x}',
                             'status': 'verified_simple_eh_metadata'})
                continue
        if (address is not None and number - 1 == section and actual is not None and off + 4 <= len(body)
                and address <= actual < address + len(body)):
            addend = struct.unpack_from('<i', body, off)[0]
            if actual == (address + value - start + addend) & 0xffffffff:
                rows.append({'offset': off, 'symbol': name, 'status': 'verified_local_code_label'})
                continue
        if name.startswith('__imp_') and actual is not None and body[off:off + 4] == b'\0\0\0\0':
            if imports is None:
                imports = import_evidence()
            label = imports[0].get(actual, '')
            dll, separator, export = label.partition('!')
            if separator and name in imports[1].get((dll.lower(), export), set()):
                rows.append({'offset': off, 'symbol': name, 'target': f'{actual:08x}', 'status': 'verified_data_import'})
                continue
        local = constants.get(off)
        if local and number > 0 and not sections[number - 1][9] & 0x80000000 and not local[2] and address is not None:
            matches, errors = match.data_check('2008-06', f'{address:08x}', target, [local])
            if len(matches) == 1 and not errors:
                rows.append({'offset': off, 'symbol': name, 'status': 'verified_readonly_data'})
                continue
        wanted = declarations.pop(off, None)
        addend = wanted.get('addend', 0) if wanted else 0
        ok = bool(wanted and wanted.get('evidence') and wanted.get('symbol') == name
                  and type(addend) is int and -(1 << 31) <= addend < (1 << 31)
                  and off + 4 <= len(body) and struct.unpack_from('<i', body, off)[0] == addend
                  and actual == ((int(wanted['target'], 16) + addend) & 0xffffffff))
        rows.append({'offset': off, 'symbol': name, 'target': f'{actual:08x}' if actual is not None else None,
                     'status': 'verified_reviewed_reference' if ok else 'unresolved_reference'})
    return {'passed': not declarations and all(row['status'] != 'unresolved_reference' for row in rows),
            'references': rows, 'unused_expectations': list(declarations.values()),
            'import_evidence_inputs': imports[2] if imports else {},
            'scope': 'Absolute relocations only; provider selection, ABI and runtime remain separate.'}


def register_import_flow(target, address, load_offset, call_offset, register):
    """Conservatively prove a callee-saved register holds one import at a call.

    Reject unmodelled branches, paths bypassing the load, writes, and calls to
    anything else after the load. Callers must separately verify the IAT load.
    """
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_CALL, CS_GRP_JUMP, CS_GRP_RET
    from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG, X86_INS_JMP, X86_INS_MOV
    aliases = {'edi': {'edi', 'di'}, 'esi': {'esi', 'si'}, 'ebx': {'ebx', 'bx', 'bl', 'bh'}}
    if register not in aliases:
        return False
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    instructions = {i.address: i for i in decoder.disasm(target, address)}
    load = instructions.get(address + load_offset)
    call = instructions.get(address + call_offset)
    if not load or load.id != X86_INS_MOV or len(load.operands) != 2:
        return False
    dst, src = load.operands
    if (dst.type != X86_OP_REG or load.reg_name(dst.reg) != register or src.type != X86_OP_MEM
            or src.mem.base or src.mem.index):
        return False
    if (not call or not call.group(CS_GRP_CALL) or call.operands[0].type != X86_OP_REG
            or call.reg_name(call.operands[0].reg) != register):
        return False
    pending, seen, reached = [(address, False)], set(), False
    while pending:
        pc, valid = pending.pop()
        if (pc, valid) in seen:
            continue
        seen.add((pc, valid))
        ins = instructions.get(pc)
        if ins is None:
            return False
        if pc == address + call_offset:
            reached = True
            if not valid:
                return False
        if pc == address + load_offset:
            valid = True
        elif ins.group(CS_GRP_CALL):
            op = ins.operands[0]
            if op.type != X86_OP_REG or ins.reg_name(op.reg) != register:
                valid = False
        elif any(ins.reg_name(reg) in aliases[register] for reg in ins.regs_access()[1]):
            valid = False
        if ins.group(CS_GRP_RET):
            continue
        next_pc = pc + ins.size
        if ins.group(CS_GRP_JUMP):
            if ins.operands[0].type != X86_OP_IMM:
                return False
            pending.append((ins.operands[0].imm & 0xffffffff, valid))
            if ins.id != X86_INS_JMP:
                pending.append((next_pc, valid))
        else:
            pending.append((next_pc, valid))
    return reached


def check_calls(raw, symbol, body, target, address, expected):
    """Check reviewed direct calls, tail jumps and identified IAT calls.

    Direct rows specify offset, original target and exact COFF symbol. Import
    rows additionally specify kind=import and the original DLL!export. Their
    PE IAT address and CRT import-library alias must both agree. Dynamic or
    virtual calls, final provider selection and callee ABI remain unproven.
    """
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_CALL, CS_GRP_JUMP
    from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    start, section = definitions[symbol]
    table = sections[section]
    refs = {}
    for index in range(table[7]):
        offset, name, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * index)
        if start <= offset < start + len(body):
            refs[offset - start] = (symbols[name][0], kind)
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    declarations = {row['offset']: row for row in expected}
    if len(declarations) != len(expected):
        raise ValueError('duplicate call expectation offset')
    imports = import_evidence() if any(row.get('kind') in ('import', 'import_reg') for row in expected) else None
    instructions = {i.address - address: i for i in decoder.disasm(target, address)}
    rows = []
    for instruction in decoder.disasm(target, address):
        offset = instruction.address - address
        op = instruction.operands[0] if instruction.operands else None
        external_jump = (instruction.group(CS_GRP_JUMP) and
                         (op.type != X86_OP_IMM or not address <= op.imm < address + len(target)))
        jump = (instruction.group(CS_GRP_JUMP)
                and (external_jump or declarations.get(offset, {}).get('kind') == 'jump'))
        if not instruction.group(CS_GRP_CALL) and not jump:
            continue
        wanted = declarations.pop(offset, None)
        direct = instruction.operands[0].type == X86_OP_IMM
        destination = instruction.operands[0].imm if direct else None
        binding = refs.get(offset + 1)
        ok = bool(direct and (not wanted or wanted.get('kind', 'direct') == 'direct')
                  and instruction.bytes[0] == 0xe8 and binding and binding[1] == 20
                  and wanted and binding[0] == wanted['symbol']
                  and destination == int(wanted['target'], 16)
                  and body[offset + 1:offset + 5] == b'\0\0\0\0')
        kind = 'direct'
        if jump:
            kind = 'jump'
            ok = bool(wanted and direct and instruction.bytes[0] == 0xe9
                      and body[offset:offset + 1] == b'\xe9'
                      and body[offset + 1:offset + 5] == b'\0\0\0\0'
                      and binding and binding[1] == 20 and binding[0] == wanted['symbol']
                      and destination == int(wanted['target'], 16))
        if wanted and wanted.get('kind') == 'import':
            kind = 'import'
            binding = refs.get(offset + 2)
            op = instruction.operands[0]
            absolute = (op.type == X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0)
            destination = op.mem.disp & 0xffffffff if absolute else None
            label = imports[0].get(destination) if absolute else None
            expected_label = wanted.get('import', '')
            dll, separator, export = expected_label.partition('!')
            actual_dll, actual_separator, actual_export = (label or '').partition('!')
            ok = bool(absolute and bytes(instruction.bytes[:2]) == b'\xff\x15'
                      and body[offset:offset + 2] == b'\xff\x15'
                      and body[offset + 2:offset + 6] == b'\0\0\0\0'
                      and binding and binding[1] == 6 and binding[0] == wanted['symbol']
                      and destination == int(wanted['target'], 16)
                      and separator and actual_separator and dll.lower() == actual_dll.lower()
                      and export == actual_export
                      and binding[0] in imports[1].get((dll.lower(), export), set()))
        if wanted and wanted.get('kind') == 'import_reg':
            kind = 'import_reg'
            load_offset = wanted.get('load_offset')
            load = instructions.get(load_offset) if isinstance(load_offset, int) else None
            op = instruction.operands[0]
            reg = instruction.reg_name(op.reg) if op.type == X86_OP_REG else None
            load_op = load.operands[1] if load and len(load.operands) == 2 else None
            absolute = bool(load_op and load_op.type == X86_OP_MEM and not load_op.mem.base and not load_op.mem.index)
            destination = load_op.mem.disp & 0xffffffff if absolute else None
            binding = refs.get(load_offset + load.disp_offset) if absolute else None
            label = imports[0].get(destination) if absolute else None
            dll, separator, export = wanted.get('import', '').partition('!')
            actual_dll, actual_separator, actual_export = (label or '').partition('!')
            field = load_offset + load.disp_offset if absolute else -1
            ok = bool(absolute and load.disp_size == 4 and binding and binding[1] == 6
                      and binding[0] == wanted['symbol'] and destination == int(wanted['target'], 16)
                      and separator and actual_separator and dll.lower() == actual_dll.lower() and export == actual_export
                      and binding[0] in imports[1].get((dll.lower(), export), set())
                      and body[load_offset:field] == bytes(load.bytes[:load.disp_offset])
                      and body[field:field + 4] == b'\0\0\0\0'
                      and body[field + 4:load_offset + load.size] == bytes(load.bytes[load.disp_offset + 4:])
                      and body[offset:offset + instruction.size] == bytes(instruction.bytes)
                      and register_import_flow(target, address, load_offset, offset, reg))
        rows.append({'offset': offset, 'target': f'{destination:08x}' if destination is not None else None,
                     'symbol': binding[0] if binding else None, 'kind': kind,
                     'status': ('verified_import' if kind in ('import', 'import_reg') else 'verified_binding') if ok
                               else 'unresolved_or_wrong_binding'})
    if imports:
        for file, digest in imports[2].items():
            if sha(Path(file)) != digest:
                raise ValueError('CRT import library changed during analysis: ' + file)
    return {'passed': not declarations and all(row['status'] in ('verified_binding', 'verified_import') for row in rows),
            'calls': rows, 'unused_expectations': list(declarations.values()),
            'import_evidence_inputs': imports[2] if imports else {},
            'scope': 'Reviewed direct calls, explicitly declared tail jumps and IAT bindings only; dynamic calls, provider selection and callee ABI require separate proof.'}


def analyze_object(job, obj):
    raw = obj.read_bytes()
    bodies = match.coff_functions(raw)
    checks, coverage, layouts = [], [], []
    for check in job['checks']:
        check_started = time.monotonic()
        addr = f"{int(check['addr'], 16):08x}"
        target, refs, _ = match.target('2008-06', addr)
        found = [b for b in bodies if b[0] == check['symbol']] or [b for b in bodies if b[0].startswith(check['symbol'])]
        row = {'addr': addr, 'requested_symbol': check['symbol'], 'status': 'missing'}
        if len(found) > 1:
            row.update(status='ambiguous', candidates=[f[0] for f in found])
        elif found:
            name, body, relocs = found[0]
            exact = set(refs) <= set(relocs) and match.exact_match(target, refs, body, relocs)
            metrics = match.comparison_metrics(target, refs, body, relocs)
            row.update(symbol=name, status='exact' if exact else 'different',
                       score=100.0 if exact else min(99.999999, metrics['fuzzy_percent']),
                       legacy_score=match.score(target, refs, body, relocs), metrics=metrics,
                       target_size=len(target), object_size=len(body), target_sha256=hashlib.sha256(target).hexdigest())
            masked = set(refs) | set(relocs)
            row['first_byte_difference'] = next((i for i in range(min(len(target), len(body)))
                if not any(r <= i < r + 4 for r in masked) and target[i] != body[i]),
                min(len(target), len(body)) if len(target) != len(body) else None)
            if len(target) < len(body) <= 65536:
                _, symbols, definitions, _ = match._coff_data_index(raw)
                start, section = definitions[name]
                catch_prefix = '__catch$' + name + '$'
                has_catch = any(s.startswith(catch_prefix) and n == section + 1
                                and start + len(target) <= value < start + len(body)
                                for s, value, n, _ in symbols.values())
                if has_catch:
                    base, image = match._image('2008-06')
                    va = int(addr, 16)
                    offset = va - base
                    if 0 <= offset and offset + len(body) <= len(image):
                        extended = bytes(image[offset:offset + len(body)])
                        extended_refs = [r - va for r in match._base_relocs('2008-06')
                                         if va <= r < va + len(body)]
                        row['contiguous_catch_comparison'] = {
                            'scope': 'diagnostic contiguous bytes only; not a function boundary, reference, or runtime proof',
                            'relocation_normalized_match': set(extended_refs) <= set(relocs) and
                                match.exact_match(extended, extended_refs, body, relocs),
                            'metrics': match.comparison_metrics(extended, extended_refs, body, relocs),
                        }
            identity = METHOD_IDENTITIES.get(name)
            if identity:
                expected, slot = identity
                image_base, image = match._image('2008-06')
                original = struct.unpack_from('<I', image, slot - image_base)[0]
                passed = addr == expected and original == int(expected, 16)
                row['method_identity'] = dict(expected=expected, vtable_slot=f'{slot:08x}',
                                              original_slot_target=f'{original:08x}', passed=passed)
                if not passed:
                    row.update(status='method_identity_mismatch', masked_byte_score=row['score'], score=0)
                    exact = False
            if exact:
                data_refs = match.coff_data_refs(raw, name)
                data_matches, data_errors = match.data_check('2008-06', addr, target, data_refs)
                row.update(data_matches=data_matches, data_errors=data_errors)
                if 'calls' in check:
                    row['call_identity'] = check_calls(raw, name, body, target, int(addr, 16), check['calls'])
                    row['reference_identity'] = check_noncall_refs(raw, name, body, target, data_refs,
                                                                  check['calls'], check.get('references', []), int(addr, 16))
        row['check_seconds'] = round(time.monotonic() - check_started, 6)
        if 'metrics' in row:
            m = row['metrics']
            print(f"SCORE {addr} status={row['status']} score={row['score']:.6f} "
                  f"positional={m['positional_percent']} raw={m['raw_positional_percent']} "
                  f"diff={m['unmasked_differences']}/{m['compared_unmasked_bytes']} "
                  f"bytes={m['candidate_bytes']}/{m['target_bytes']} delta={m['length_delta']:+d} "
                  f"reloc_missing={len(m['missing_relocations'])} reloc_extra={len(m['extra_relocations'])}", flush=True)
            if 'contiguous_catch_comparison' in row:
                extra = row['contiguous_catch_comparison']
                m = extra['metrics']
                print(f"CATCH_RANGE {addr} match={extra['relocation_normalized_match']} "
                      f"fuzzy={m['fuzzy_percent']} positional={m['positional_percent']} "
                      f"raw={m['raw_positional_percent']} "
                      f"diff={m['unmasked_differences']}/{m['compared_unmasked_bytes']} "
                      f"bytes={m['candidate_bytes']}/{m['target_bytes']} (diagnostic only)", flush=True)
        checks.append(row)
    if job['ranges']:
        functions = [json.loads(line) for line in (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines()]
        for interval in job['ranges']:
            lo, hi = (int(v, 16) for v in interval.split('-'))
            hits, missing = [], []
            for function in functions:
                addr = function['addr']
                if not lo <= int(addr, 16) < hi or function.get('kind', 'code') != 'code':
                    continue
                target, refs, _ = match.target('2008-06', addr)
                names = [name for name, body, relocs in bodies if len(body) == len(target) and set(refs) <= set(relocs) and match.exact_match(target, refs, body, relocs)]
                if names:
                    hits.append({'addr': addr, 'symbols': names, 'size': len(target)})
                else:
                    missing.append({'addr': addr, 'size': len(target)})
            coverage.append({'range': interval, 'hits': hits, 'missing': missing,
                             'scope': 'masked-byte analogs; symbol identity and call bindings unproven'})
    if job['layouts']:
        import native_layout_evidence as layout
        for check in job['layouts']:
            hits = [b for b in bodies if b[0] == check['symbol']] or [b for b in bodies if b[0].startswith(check['symbol'])]
            if len(hits) != 1:
                raise ValueError('layout symbol missing/ambiguous: ' + check['symbol'])
            name, body, refs = hits[0]
            address = int(check['addr'], 16)
            target, target_refs, _ = match.target('2008-06', f'{address:08x}')
            original, candidate = layout.extract(target, address, target_refs), layout.extract(body, address, refs)
            layouts.append({'addr': check['addr'], 'symbol': name, 'target': original, 'candidate': candidate,
                            'comparison': layout.compare(original, candidate),
                            'call_obligations': layout.call_obligations(raw, name, body, refs, target, target_refs, address),
                            'scope': layout.__doc__})
    return {'checks': checks, 'coverage': coverage, 'layouts': layouts}


def build_inputs(tc):
    compiler = Path(tc['cl']) if tc.get('cl') else None
    paths = [compiler] + [compiler.with_name(name) for name in ('c1.dll', 'c1xx.dll', 'c2.dll')] if compiler else []
    paths.append(Path(tc['mspdb']) if tc.get('mspdb') else None)
    return dict(compiler={str(p): sha(p) if p.is_file() else None for p in paths if p},
                includes={k: str(tc[k]) if tc.get(k) else None for k in ('vc_include', 'atlmfc_include', 'sdk_include')},
                environment={k: os.environ.get(k) for k in ('INCLUDE', 'CL', '_CL_', 'NATIVE_FLAGS', 'PATH')},
                build_tools={str(p): sha(p) for p in (Path(__file__), ROOT / 'roc/rebuild.py', ROOT / 'roc/libs.py',
                                                       ROOT / 'roc/match.py', ROOT / 'roc/native_work.py') if p.is_file()})


def cache_key(source, flags, inputs):
    return hashlib.sha256(json.dumps({'source': sha(source), 'flags': flags, 'inputs': inputs},
                                     sort_keys=True, separators=(',', ':')).encode()).hexdigest()


def include_search_snapshot(source, flags, cwd, tc):
    if os.environ.get('CL') or os.environ.get('_CL_'):
        return None
    def absolute(path):
        path = Path(path)
        return (path if path.is_absolute() else cwd / path).resolve()
    roots = {str(source.parent.resolve()): source.parent.resolve()}
    index = 0
    while index < len(flags):
        flag = flags[index]
        if flag.lower() in ('/i', '-i'):
            index += 1
            if index == len(flags):
                return None
            path = flags[index]
            resolved = absolute(path)
            roots[str(resolved)] = resolved
        elif flag[:2].lower() in ('/i', '-i') and len(flag) > 2:
            resolved = absolute(flag[2:])
            roots[str(resolved)] = resolved
        index += 1
    roots.update({str(absolute(path)): absolute(path)
                  for path in os.environ.get('INCLUDE', '').split(os.pathsep) if path})
    configured = tc.get('includes', tc)
    roots.update({str(absolute(configured[key])): absolute(configured[key])
                  for key in ('vc_include', 'atlmfc_include', 'sdk_include') if configured.get(key)})
    roots['<working-directory>'] = cwd.resolve()
    snapshot = {}
    for label, root in sorted(roots.items()):
        if not root.is_dir():
            snapshot[label] = None
            continue
        names = []
        prefix = len(str(root)) + (0 if str(root).endswith(os.sep) else 1)
        for directory, folders, files in os.walk(root):
            folders.sort()
            # Same text as str(Path(directory, name).relative_to(root)), without 30k pathlib objects (~5 s per gate).
            names.extend(os.path.join(directory, name)[prefix:] for name in folders + files
                         if not (label == '<working-directory>' and name in
                                 ('candidate.obj', 'compiler.pdb', 'compile.log', 'receipt.json')))
        snapshot[label] = hashlib.sha256('\n'.join(names).encode()).hexdigest()
    return snapshot


def cached_result(key, job, source, flags, inputs, folder):
    receipt_path, object_path = CACHE / (key + '.json'), CACHE / (key + '.obj')
    try:
        receipt = json.loads(receipt_path.read_text(encoding='utf-8'))
        if (receipt.get('status') != 'complete' or receipt.get('source') != str(source)
                or receipt.get('flags') != flags or receipt.get('build_inputs') != inputs
                or receipt.get('source_sha256') != sha(source)
                or not receipt.get('include_search_snapshot')
                or receipt.get('include_search_snapshot') != include_search_snapshot(source, flags, folder, inputs)
                or any(not Path(path).is_file() or sha(path) != digest
                       for path, digest in receipt.get('dependencies', {}).items())
                or not object_path.is_file() or sha(object_path) != receipt.get('object_sha256')):
            return None
        output = folder / 'candidate.obj'
        output.write_bytes(object_path.read_bytes())
        result = dict(receipt)
        result.update(object=str(output), log=None, compile_seconds=0, cache_hit=True)
        analysis_started = time.monotonic()
        result.update(analyze_object(job, output), status='complete')
        result['analysis_seconds'] = round(time.monotonic() - analysis_started, 3)
        return result
    except (OSError, ValueError, KeyError, TypeError):
        return None


def store_cached_result(key, result):
    if result.get('status') != 'complete' or result.get('changed_inputs'):
        return
    CACHE.mkdir(parents=True, exist_ok=True)
    object_path = CACHE / (key + '.obj')
    receipt_path = CACHE / (key + '.json')
    temporary = CACHE / (key + '.' + uuid.uuid4().hex + '.obj')
    temporary.write_bytes(Path(result['object']).read_bytes())
    try:
        os.replace(temporary, object_path)
        save(receipt_path, result)
    finally:
        temporary.unlink(missing_ok=True)


def build_changes(receipt, tc):
    changed = []
    if not receipt.get('build_inputs'):
        changed.append('build configuration unrecorded; historical evidence only')
    elif receipt['build_inputs'] != build_inputs(tc):
        changed.append('compiler/toolchain inputs changed')
    # An explicit current override selects a new configuration. Otherwise reuse
    # the captured override, even after the original shell environment ended.
    override = os.environ.get('NATIVE_FLAGS') or receipt.get('native_flags')
    if compiler_flags(Path(receipt['source']), override) != receipt.get('flags'):
        changed.append('compiler flags changed')
    return changed


def compile_job(job, folder, tc):
    folder.mkdir()
    started = time.time_ns()
    clock = time.monotonic()
    source = Path(job['source'])
    result = {'source': str(source), 'status': 'failed', 'object': str(folder / 'candidate.obj')}
    try:
        exhausted = native_work.over_budget(job.get('checks', []))
        if exhausted:
            result['error'] = 'function budget exhausted; park or finish session: ' + ', '.join(exhausted)
            return result
        before = sha(source)
        flags = compiler_flags(source)
        inputs = build_inputs(tc)
        key = cache_key(source, flags, inputs)
        search_before = include_search_snapshot(source, flags, folder, inputs)
        hit = cached_result(key, job, source, flags, inputs, folder)
        if hit:
            hit.update(native_flags=os.environ.get('NATIVE_FLAGS'), cache_key=key)
            result = hit
            return hit
        result.update(build_inputs=inputs, native_flags=os.environ.get('NATIVE_FLAGS'), cache_key=key, cache_hit=False)
        compile_started = time.monotonic()
        code, log = rebuild.run(tc, 'cl', flags + ['/showIncludes', '/Fo' + result['object'], '/Fd' + str(folder / 'compiler.pdb'), str(source)], folder)
        result['compile_seconds'] = round(time.monotonic() - compile_started, 3)
        (folder / 'compile.log').write_text(log, encoding='utf-8')
        result.update(compiler_exit=code, source_sha256=before, flags=flags, log=str(folder / 'compile.log'))
        if code:
            result['error'] = 'compiler failed; see compile.log'
            return result
        dependencies = {source}
        for line in log.splitlines():
            hit = re.match(r'\s*Note: including file:\s*(.*?)\s*$', line)
            if hit:
                dependencies.add(Path(rebuild._host_include(hit[1])).resolve())  # Wine prints Z:\host\path
        result['dependencies'] = {str(p): sha(p) for p in sorted(dependencies)}
        result['include_search_snapshot'] = include_search_snapshot(source, flags, folder, inputs)
        # Fingerprints are evidence, not a cache key. No reuse of changed builds.
        changed = [str(p) for p in dependencies if p != source and p.stat().st_mtime_ns >= started]
        changed += build_changes(result, tc)
        if sha(source) != before or changed or result['include_search_snapshot'] != search_before:
            if result['include_search_snapshot'] != search_before:
                changed.append('include search paths changed during compile')
            result.update(error='inputs changed during compile; rerun', changed_inputs=changed)
            return result
        obj = Path(result['object'])
        result['object_sha256'] = sha(obj)
        analysis_started = time.monotonic()
        result.update(analyze_object(job, obj), status='complete')
        result['analysis_seconds'] = round(time.monotonic() - analysis_started, 3)
        if len(dependencies) > 1 and result.get('include_search_snapshot'):
            store_cached_result(key, result)
        return result
    except Exception as error:
        result['error'] = f'{type(error).__name__}: {error}'
        return result
    finally:
        result['seconds'] = round(time.monotonic() - clock, 3)
        save(folder / 'receipt.json', result)


def compact(results):
    checks = [row for result in results if result['status'] == 'complete' for row in result.get('checks', [])]
    ranges = {}
    for result in results:
        for coverage in result.get('coverage', []):
            group = ranges.setdefault(coverage['range'], {'functions': {}, 'hits': set()})
            for row in coverage['hits'] + coverage['missing']:
                group['functions'][row['addr']] = row['size']
            group['hits'].update(row['addr'] for row in coverage['hits'])
    return {'compiled_sources': len(results), 'cache_hits': sum(r.get('cache_hit', False) for r in results),
            'failed_sources': sum(r['status'] != 'complete' for r in results),
            'compile_seconds_sum': round(sum(r.get('compile_seconds', 0) for r in results), 3),
            'analysis_seconds_sum': round(sum(r.get('analysis_seconds', 0) for r in results), 3),
            'exact_checks': sum(r['status'] == 'exact' for r in checks), 'checks': len(checks),
            'data_checked': sum('data_errors' in r for r in checks),
            'verified_checks': sum(r['status'] == 'exact' and 'data_errors' in r and not r['data_errors'] for r in checks),
            'binding_verified_checks': sum(r['status'] == 'exact' and 'data_errors' in r and not r['data_errors']
                                           and r.get('call_identity', {}).get('passed', False) for r in checks),
            'data_mismatches': [r for r in checks if r.get('data_errors')][:8],
            'issues': [{'source': r['source'], 'error': r['error']} for r in results if r.get('error')][:8],
            'mismatches': [r for r in checks if r['status'] != 'exact'][:8],
            'coverage': [{'range': interval, 'matched_functions': len(group['hits']), 'functions': len(group['functions']),
                          'matched_bytes': sum(group['functions'][addr] for addr in group['hits']),
                          'scope': 'masked-byte analogs, not identity proof'} for interval, group in ranges.items()]}


def execute(run, workers):
    # Exclusive claim: two foreground/background workers never share a run.
    with (run / 'claim').open('x') as claim:
        claim.write(str(os.getpid()))
    data = json.loads((run / 'manifest.json').read_text())
    jobs = data['jobs']
    headers = native_work.headers()
    save(run / 'shared-headers.json', headers)
    summary = {'state': 'running', 'pid': os.getpid(), 'run': str(run), 'total_sources': len(jobs), 'completed_sources': 0,
               'observer_sha256': sha(Path(__file__)), 'manifest_sha256': sha(run / 'manifest.json'),
               'work_log_sha256': sha(native_work.__file__),
               'timing_log': str(run / 'function-timings.jsonl'),
               'scope': 'local diagnostics only; validated cached object or fresh compile per source; no ABI/server/P5/P6 gate proof; complete means finished; inspect exact_checks and data_mismatches'}
    save(run / 'summary.json', summary)
    started, results = time.monotonic(), []
    try:
        build = compiler_build(data)
        tc = selected_toolchain(data)
        summary['compiler_build'] = build
        summary['compiler_variant'] = compiler_variant(data)
        summary['compiler'] = str(tc['cl'])
        summary['compiler_sha256'] = sha(tc['cl'])
        with ThreadPoolExecutor(max_workers=workers) as pool:
            futures = {pool.submit(compile_job, job, run / f'unit-{index:03}', tc): index for index, job in enumerate(jobs)}
            for future in as_completed(futures):
                result = future.result()
                result['unit'] = futures[future]
                results.append(result)
                summary.update(completed_sources=len(results), **compact(results))
                summary['updated_at_ns'] = time.time_ns()
                save(run / 'summary.json', summary)
        drift = native_work.changed(headers, native_work.headers())
        for result in results:
            dependencies = result.get('dependencies', {})
            changed = [p for p, digest in dependencies.items() if not Path(p).exists() or sha(p) != digest]
            if drift or changed:
                result.update(status='failed', changed_inputs=sorted(set(drift + changed)),
                              error='inputs changed across batch; do not accept mixed-header evidence')
        summary.update(**compact(results), shared_headers_changed=drift)
        summary['state'] = 'failed' if any(r['status'] != 'complete' for r in results) else 'complete'
    except Exception as error:
        summary.update(state='failed', error=f'{type(error).__name__}: {error}')
    summary['seconds'] = round(time.monotonic() - started, 3)
    for result in results:
        native_work.log_checks(run, jobs[result['unit']], result)
    summary['results'] = str(run / 'results.json')
    save(run / 'results.json', sorted(results, key=lambda r: r['unit']))
    save(run / 'summary.json', summary)
    return summary


def alive(pid):
    if os.name != 'nt':
        try:
            os.kill(pid, 0)
            return True
        except ProcessLookupError:
            return False
        except PermissionError:
            return None
    import ctypes
    from ctypes import wintypes
    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    kernel.OpenProcess.argtypes = [wintypes.DWORD, wintypes.BOOL, wintypes.DWORD]
    kernel.OpenProcess.restype = wintypes.HANDLE
    kernel.GetExitCodeProcess.argtypes = [wintypes.HANDLE, ctypes.POINTER(wintypes.DWORD)]
    kernel.CloseHandle.argtypes = [wintypes.HANDLE]
    handle = kernel.OpenProcess(0x1000, False, pid)
    if not handle:
        return None if ctypes.get_last_error() == 5 else False
    try:
        code = wintypes.DWORD()
        if not kernel.GetExitCodeProcess(handle, ctypes.byref(code)):
            return None
        return code.value == 259
    finally:
        kernel.CloseHandle(handle)


def display(run):
    summary = json.loads((run / 'summary.json').read_text())
    launcher = run / 'launcher.json'
    pid = summary.get('pid') or (json.loads(launcher.read_text())['pid'] if launcher.exists() else None)
    if summary['state'] in ('queued', 'running') and pid and alive(pid) is False:
        summary = json.loads((run / 'summary.json').read_text())
        if summary['state'] in ('queued', 'running'):
            summary.update(state='failed', error='worker exited without terminal receipt; inspect worker.log')
    print(json.dumps(summary, separators=(',', ':')))
    return summary


def index_inactive(results, receipts, tc, output, analysis_path):
    """Index one explicitly reviewed, fully bound native source without overwriting receipts."""
    require_proof(results)
    if len(results) != 1:
        raise ValueError('index one source per receipt')
    result = results[0]
    source = Path(result['source']).resolve()
    roots = [(BASE / name).resolve() for name in ('native-classes', 'native-world', 'native-headers')]
    if not any(source.is_relative_to(root) for root in roots):
        raise ValueError('receipt source must be a native source or header')
    output = Path(output).resolve()
    if output.parent != (ROOT / 'work/2008-06/shared-layouts').resolve() or output.suffix.lower() != '.json':
        raise ValueError('receipt must be a JSON file in shared-layouts')
    receipt = receipts[str(source).casefold()]
    if receipt.get('status') != 'complete':
        raise ValueError('recorded build was not complete')
    if Path(receipt['object']).resolve() != Path(result['object']).resolve():
        raise ValueError('recorded object differs')
    checks = result['checks']
    if len({row['addr'] for row in checks}) != len(checks):
        raise ValueError('duplicate original address')

    def verify_inputs():
        expected = dict(receipt['dependencies'])
        expected[str(source)] = receipt['source_sha256']
        expected[receipt['object']] = receipt['object_sha256']
        changed = [name for name, digest in expected.items() if not Path(name).is_file() or sha(name) != digest]
        changed.extend(build_changes(receipt, tc))
        if changed:
            raise ValueError('proof inputs changed: ' + ', '.join(changed[:5]))
        require_proof(results)

    verify_inputs()
    rows = [{'address': row['addr'], 'symbol': row['symbol'], 'exact': True,
             'metrics': row['metrics'], 'data_matches': row['data_matches'],
             'verified_calls': row['call_identity']['calls'],
             'verified_references': row['reference_identity']['references']} for row in checks]
    data = {'source_path': str(source), 'source_sha256': receipt['source_sha256'],
            'object_sha256': receipt['object_sha256'], 'analysis': str(Path(analysis_path).resolve()),
            'checks': rows,
            'scope': 'Local masked byte/data, reviewed call and absolute-reference checks; original owner, provider selection, ABI, runtime and server credit remain separate.'}
    with output.open('x', encoding='utf-8') as handle:
        json.dump(data, handle, indent=2)
        handle.write('\n')
    try:
        verify_inputs()
    except BaseException:
        output.unlink()
        raise


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('start', 'run', 'status', 'analyze', '_worker'))
    parser.add_argument('input', type=Path, help='manifest for start/run; run directory otherwise')
    parser.add_argument('--manifest', type=Path, help='analyze: replacement comparisons against existing objects')
    parser.add_argument('--workers', type=int, choices=range(1, 9), default=3)
    parser.add_argument('--require-proof', action='store_true', help='run/analyze: fail unless every explicit check has fresh exact bytes, data and reviewed call bindings')
    parser.add_argument('--index-output', type=Path, help='analyze: write one new inactive receipt after all proof checks pass')
    args = parser.parse_args()
    if args.require_proof and args.action not in ('run', 'analyze'):
        parser.error('--require-proof supports foreground run/analyze only')
    if args.index_output and args.action != 'analyze':
        parser.error('--index-output supports analyze only')
    if args.action in ('start', 'run'):
        manifest = json.loads(args.input.read_text(encoding='utf-8-sig'))
        build = compiler_build(manifest)
        variant = compiler_variant(manifest)
        jobs = jobs_from(manifest)
        RUNS.mkdir(parents=True, exist_ok=True)
        run = RUNS / (time.strftime('%Y%m%d-%H%M%S') + '-' + uuid.uuid4().hex[:8])
        run.mkdir()
        save(run / 'manifest.json', {'compiler_build': build, 'compiler_variant': variant, 'jobs': jobs})
        save(run / 'summary.json', {'state': 'queued', 'run': str(run), 'total_sources': len(jobs)})
        if args.action == 'start':
            try:
                with (run / 'worker.log').open('w') as log:
                    options = {'creationflags': subprocess.CREATE_NO_WINDOW | subprocess.CREATE_NEW_PROCESS_GROUP} if os.name == 'nt' else {'start_new_session': True}
                    child = subprocess.Popen([sys.executable, str(Path(__file__).resolve()), '_worker', str(run), '--workers', str(args.workers)], cwd=ROOT,
                                             stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT, close_fds=True, **options)
            except OSError as error:
                save(run / 'summary.json', {'state': 'failed', 'run': str(run), 'error': str(error)})
                raise
            save(run / 'launcher.json', {'pid': child.pid})
        else:
            execute(run, args.workers)
        summary = display(run)
    elif args.action == 'analyze':
        run = args.input.resolve()
        jobs = jobs_from(json.loads((args.manifest or run / 'manifest.json').read_text(encoding='utf-8-sig')))
        receipts = {r['source'].casefold(): r for r in json.loads((run / 'results.json').read_text())}
        results = []
        recorded = json.loads((run / 'manifest.json').read_text(encoding='utf-8-sig'))
        tc = selected_toolchain(recorded)
        for job in jobs:
            receipt = receipts[job['source'].casefold()]
            obj = Path(receipt['object'])
            if receipt['status'] != 'complete' or sha(obj) != receipt['object_sha256']:
                raise ValueError('recorded object failed or changed: ' + str(obj))
            changed = [p for p, digest in receipt['dependencies'].items() if not Path(p).exists() or sha(p) != digest]
            changed += build_changes(receipt, tc)
            results.append({'source': job['source'], 'object': str(obj), 'changed_inputs': changed,
                            'scope': 'recorded object analysis only; not a fresh build', **analyze_object(job, obj)})
            native_work.log_checks(run, job, results[-1], mode='analyze')
        # Analysis can take seconds. Inputs must still match after the whole batch.
        for result in results:
            receipt = receipts[result['source'].casefold()]
            expected = dict(receipt['dependencies'])
            expected[receipt['object']] = receipt['object_sha256']
            result['changed_inputs'] = sorted(set(result['changed_inputs']) | set(build_changes(receipt, tc)) | {
                p for p, digest in expected.items() if not Path(p).exists() or sha(p) != digest})
        output = run / ('analysis-' + uuid.uuid4().hex[:8] + '.json')
        save(output, results)
        print(json.dumps({'state': 'analyzed', 'sources': len(results), 'changed_input_sources': sum(bool(r['changed_inputs']) for r in results), 'results': str(output)}))
        if args.require_proof or args.index_output:
            require_proof(results)
        if args.index_output:
            index_inactive(results, receipts, tc, args.index_output, output)
            print(json.dumps({'state': 'indexed', 'receipt': str(args.index_output.resolve())}))
        return
    elif args.action == '_worker':
        execute(args.input.resolve(), args.workers)
        return
    else:
        summary = display(args.input.resolve())
    if summary['state'] == 'failed':
        raise SystemExit(1)
    if args.require_proof:
        require_proof(json.loads((Path(summary['run']) / 'results.json').read_text()))


def require_proof(results):
    checks = [row for result in results for row in result.get('checks', [])]
    for row in checks:
        for evidence in ('call_identity', 'reference_identity'):
            for name, digest in row.get(evidence, {}).get('import_evidence_inputs', {}).items():
                try:
                    if sha(Path(name)) != digest:
                        raise SystemExit('import proof input changed: ' + name)
                except OSError:
                    raise SystemExit('import proof input unavailable: ' + name)
    if (not checks or any(result.get('status', 'complete') != 'complete' or result.get('changed_inputs') for result in results)
            or any(row['status'] != 'exact' or 'data_errors' not in row or row['data_errors']
                   or not row.get('call_identity', {}).get('passed', False)
                   or not row.get('reference_identity', {}).get('passed', False) for row in checks)):
        raise SystemExit('proof incomplete; inspect saved receipt (no ABI/runtime/server credit)')


if __name__ == '__main__':
    main()
