"""Reproducible class, provenance and compiler-piece review; never awards mining credit."""
import collections
import hashlib
import json
import re
import struct
from pathlib import Path

from roc import match, rebuild


def scope(symbol):
    """Conservative non-template member scope; complex manglings remain unresolved."""
    symbol = symbol or ''
    special = re.match(r'^\?\?(?:[01]|_G|_E)([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)*)@', symbol)
    if special:
        return '::'.join(list(reversed(special[2].rstrip('@').split('@'))) + [special[1]]).lstrip(':')
    if symbol.startswith('??'):
        return None
    found = re.match(r'^\?[^@?$]+@([A-Za-z_]\w*(?:@[A-Za-z_]\w*)*)@@(?!Y)', symbol)
    return '::'.join(reversed(found[1].split('@'))) if found else None


def class_backlog(functions, inventory, names, donors, abi):
    groups = {}
    for row in inventory:
        if row['source_kind'] != 'snippet' or row['score'] != 100:
            continue
        addr = row['addr']
        native = names.get(addr, {})
        donor = donors.get(addr, [])
        symbol = native.get('symbol', '') if native.get('score') == 100 else ''
        symbol = symbol or (donor[2] if donor else '')
        cls = scope(symbol)
        basis = 'symbol' if cls else 'unit_hint'
        cls = cls or functions[addr].get('unit') or 'unknown'
        item = groups.setdefault(cls, {'class': cls, 'addrs': [], 'basis': collections.Counter(),
                                       'this_reads': collections.Counter(), 'this_writes': collections.Counter(),
                                       'donor_paths': set(), 'abi': abi.get(cls)})
        item['addrs'].append(addr)
        item['basis'][basis] += 1
        for field in ('this_reads', 'this_writes'):
            item[field].update(functions[addr].get(field, []))
        if donor and donor[3]:
            item['donor_paths'].add(donor[3])
    rows = sorted(groups.values(), key=lambda r: (-len(r['addrs']), r['class']))
    cumulative = 0
    for row in rows:
        row['count'] = len(row['addrs'])
        cumulative += row['count']
        row['cumulative'] = cumulative
        row['basis'] = dict(row['basis'])
        row['donor_paths'] = sorted(row['donor_paths'])
        for field in ('this_reads', 'this_writes'):
            row[field] = dict(sorted(row[field].items()))
    return rows


def vendor_review(inventory):
    """Flag provenance conflicts, not byte failures. Unit labels are heuristic."""
    rows = []
    for row in inventory:
        if row['source_kind'] != 'vendor-file' or row['score'] != 100:
            continue
        unit = row.get('unit') or ''
        stem = Path(row.get('file') or '').stem
        # A segment bucket contains no class evidence. CNullDoc vs
        # OgreScriptLexer is a conflict; CXTPFoo vs XTPFoo is compatible.
        if unit.startswith('seg_') or not unit or not stem:
            state = 'unresolved'
        else:
            normalize = lambda x: re.sub('[^a-z0-9]', '', x.lower()).removeprefix('c')
            u, s = normalize(unit.split('::')[-1]), normalize(stem)
            state = 'compatible_hint' if u in s or s in u else 'unit_file_conflict'
        rows.append(dict(row, provenance=state, authentic_source_verified=False))
    return rows


class ByteIndex:
    """Exact candidates, indexed by the object's relocation mask; preserves twins."""
    def __init__(self, client, functions):
        self.client = client
        self.sizes = collections.defaultdict(list)
        self.masks = {}
        for addr, row in functions.items():
            if row.get('kind', 'code') not in ('data', 'bad'):
                code, relocs, _ = match.target(client, addr)
                self.sizes[len(code)].append((addr, code, frozenset(relocs)))

    def hits(self, body, relocs):
        mask = tuple(sorted(set(relocs)))
        key = len(body), mask
        if key not in self.masks:
            index = collections.defaultdict(list)
            allowed = set(mask)
            for addr, code, required in self.sizes[len(body)]:
                if required <= allowed:
                    index[match.masked(code, mask)].append(addr)
            self.masks[key] = index
        return self.masks[key].get(match.masked(body, mask), [])


def piece_parents(functions, client=None):
    """Parent addresses proven by FuncInfo references or direct calls; no proximity guesses."""
    handler_owners = collections.defaultdict(set)
    for addr, row in functions.items():
        if row.get('kind', 'code') == 'code':
            for ref in row.get('data_refs', []):
                handler_owners[int(ref, 16)].add(addr)
    parents = {}
    if client:
        from capstone import Cs, CS_ARCH_X86, CS_MODE_32
        from capstone.x86_const import X86_OP_IMM
        decoder = Cs(CS_ARCH_X86, CS_MODE_32)
        decoder.detail = True
    for addr, row in functions.items():
        if row.get('kind', 'code') not in ('eh', 'gen', 'adjustor', 'thunk'):
            continue
        owners = set(row.get('call_targets', []))
        if client:
            code, _, _ = match.target(client, addr)
            for ins in decoder.disasm(code, int(addr, 16)):
                if ins.mnemonic == 'jmp' and ins.operands[0].type == X86_OP_IMM:
                    owners.add('%08x' % (ins.operands[0].imm & 0xffffffff))
        for context in row.get('unwind_context', []) + row.get('catch_context', []):
            owners.update(handler_owners[context['handler']])
        # The handler stub itself is referenced from its parent's prologue.
        owners.update(handler_owners[int(addr, 16)])
        parents[addr] = {a for a in owners if a in functions and functions[a].get('kind', 'code') == 'code'}
    return parents


def object_parent_names(data, symbol, size):
    for prefix in ('__ehhandler$', '__unwindfunclet$', '__catch$'):
        if symbol.startswith(prefix):
            name = symbol[len(prefix):]
            return {name if prefix == '__ehhandler$' else name.rsplit('$', 1)[0]}
    sections, symbols, funcs, _ = match._coff_data_index(data)
    if symbol not in funcs:
        return set()
    start, sec = funcs[symbol]
    result = set()
    for i in range(sections[sec][7]):
        offset, index, typ = struct.unpack_from('<IIH', data, sections[sec][5] + i * 10)
        if start <= offset < start + size and typ == 20 and index in symbols:
            result.add(symbols[index][0])
    return result


def ownership(client, functions, log=print):
    index = ByteIndex(client, functions)
    parents = piece_parents(functions, client)
    modules, compiled, linked, pieces = [], set(), set(), {}
    parsed = {}
    for spec_path in sorted((rebuild.workspace(client) / 'modules').glob('*.json')):
        spec = json.loads(spec_path.read_text())
        out = rebuild.workspace(client) / 'out' / spec['name']
        report_path = out / 'report.json'
        if not report_path.exists():
            continue
        report_bytes = report_path.read_bytes()
        report = json.loads(report_bytes)
        report_digest = hashlib.sha256(report_bytes).hexdigest()
        object_paths = sorted((out / 'linked').glob('*.obj'))
        unfinished = any(p.stat().st_mtime_ns > report_path.stat().st_mtime_ns for p in object_paths)
        if unfinished:
            log('%s: review deferred; objects newer than report' % spec['name'])
            modules.append({'module': spec['name'], 'deferred': True, 'linked': False,
                            'compiled_unique': 0, 'unresolved': [], 'test_exit': None, 'objects': []})
            continue
        owned = set(report.get('owned_addrs', []))
        compiled.update(owned)
        if report.get('linked'):
            linked.update(owned)
        module = {'module': spec['name'], 'linked': report.get('linked'),
                  'test_exit': report.get('test_exit'), 'compiled_unique': len(owned),
                  'unresolved': report.get('unresolved', []), 'objects': [], 'report_sha256': report_digest}
        modules.append(module)
        if not report.get('linked'):
            continue
        candidates, named_parents = [], collections.defaultdict(set)
        for obj in object_paths:
            data = obj.read_bytes()
            digest = hashlib.sha256(data).hexdigest()
            module['objects'].append({'path': str(obj), 'sha256': digest})
            if digest not in parsed:
                parsed[digest] = [(symbol, body, relocs, index.hits(body, relocs))
                                  for symbol, body, relocs in match.coff_functions(data)]
            for symbol, body, relocs, hits in parsed[digest]:
                code_hits = [a for a in hits if functions[a].get('kind', 'code') == 'code']
                if len(code_hits) == 1 and code_hits[0] in owned:
                    named_parents[symbol].add(code_hits[0])
                for addr in hits:
                    if addr not in parents or not parents[addr] & owned:
                        continue
                    candidates.append((addr, symbol, len(body), data, hits, str(obj)))
        for addr, symbol, size, data, hits, obj in candidates:
            # Proven parent narrows identical funclets. More than one child of
            # that parent still means ambiguity; never fan credit out to twins.
            object_owners = set().union(*(named_parents[n] for n in object_parent_names(data, symbol, size)))
            owner = parents[addr] & owned & object_owners
            if not owner:
                continue
            siblings = [a for a in hits if parents.get(a, set()) & owner]
            if len(siblings) != 1 or addr in pieces:
                continue
            code, _, _ = match.target(client, addr)
            refs = match.coff_data_refs(data, symbol)
            _, bad = match.data_check(client, addr, code, refs)
            if not bad:
                pieces[addr] = {'kind': functions[addr]['kind'], 'parents': sorted(owner),
                                'symbol': symbol, 'object': obj, 'data_spans_checked': len(refs)}
        log('%s: linked=%s compiled=%d paired pieces so far=%d' %
            (spec['name'], report.get('linked'), len(owned), len(pieces)))
        if hashlib.sha256(report_path.read_bytes()).hexdigest() != report_digest:
            raise RuntimeError('%s report changed during review; rerun after builds finish' % spec['name'])
        for entry in module['objects']:
            if hashlib.sha256(Path(entry['path']).read_bytes()).hexdigest() != entry['sha256']:
                raise RuntimeError('%s object changed during review; rerun after builds finish' % entry['path'])
    for module in modules:
        if module.get('deferred'):
            continue
        path = rebuild.workspace(client) / 'out' / module['module'] / 'report.json'
        if hashlib.sha256(path.read_bytes()).hexdigest() != module['report_sha256']:
            raise RuntimeError('%s report changed during review; rerun after builds finish' % module['module'])
        for entry in module['objects']:
            if hashlib.sha256(Path(entry['path']).read_bytes()).hexdigest() != entry['sha256']:
                raise RuntimeError('%s object changed during review; rerun after builds finish' % entry['path'])
    kinds = collections.Counter(functions[a].get('kind', 'code') for a in linked)
    return {'modules': modules, 'compiled_unique': len(compiled), 'linked_unique': len(linked),
            'compiled_but_unlinked': sorted(compiled - linked), 'linked_addrs': sorted(linked),
            'linked_by_kind': dict(kinds), 'paired_pieces': pieces,
            'denominators': dict(collections.Counter(r.get('kind', 'code') for r in functions.values())),
            'paired_piece_counts': dict(collections.Counter(v['kind'] for v in pieces.values())),
            'linked_code_plus_pieces': len(linked) + len(pieces),
            'note': 'Module counts are cached relocation-normalized object matches, not server gains or proof of PE retention. '
                    'Pieces are freshly byte/data checked, parent constrained; no address-proximity ownership.'}


def review(client='2008-06', log=print):
    from roc import matchers
    root = rebuild.workspace(client)
    inventory_path = root / 'manifests/functions.json'
    inventory = json.loads(inventory_path.read_text())
    functions = match._functions(client)
    names_path = root / 'out/native-names.json'
    names = json.loads(names_path.read_text()) if names_path.exists() else {}
    abi = json.loads((root / 'manifests/abi-evidence.json').read_text())
    ranked = class_backlog(functions, inventory, names, matchers._table().get(client, {}), abi)
    vendor = vendor_review(inventory)
    evidence = ownership(client, functions, log)
    evidence.update(inventory_sha256=hashlib.sha256(inventory_path.read_bytes()).hexdigest(),
                    inventory_note='Snapshot scores/provenance; no fresh source verification.',
                    functions_sha256=hashlib.sha256((rebuild.ROOT / 'work' / client / 'functions.jsonl').read_bytes()).hexdigest(),
                    snippet_count=sum(r['count'] for r in ranked),
                    vendor_counts=dict(collections.Counter(r['provenance'] for r in vendor)),
                    authentic_source_verified=0,
                    authentic_source_note='Unit/file compatibility alone cannot prove original source.')
    for name, value in [('class-backlog', ranked), ('vendor-provenance', vendor), ('ownership-review', evidence)]:
        rebuild._dump(root / 'out' / (name + '.json'), value)
    log('snippets=%d classes/buckets=%d top30=%d; compiled=%d linked=%d pieces=%s' %
        (evidence['snippet_count'], len(ranked), sum(r['count'] for r in ranked[:30]),
         evidence['compiled_unique'], evidence['linked_unique'], evidence['paired_piece_counts']))
    return evidence


def cached_review(client):
    """A changing checkout invalidates cached counts instead of resurrecting old credit."""
    root = rebuild.workspace(client)
    path = root / 'out/ownership-review.json'
    if not path.exists():
        return None
    report = json.loads(path.read_text())
    inputs = [(rebuild.ROOT / 'work' / client / 'functions.jsonl', report.get('functions_sha256'))]
    for module in report['modules']:
        if module.get('deferred'):
            return None
        inputs.append((root / 'out' / module['module'] / 'report.json', module['report_sha256']))
        inputs.extend((Path(o['path']), o['sha256']) for o in module['objects'])
    for path, expected in inputs:
        if not path.exists() or hashlib.sha256(path.read_bytes()).hexdigest() != expected:
            return None
    return report
