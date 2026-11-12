"""Independent original-toolchain draft measurements; uploaded claims are hypotheses.

This adapter never runs contributor scripts, selects providers, or grants credit.
Incomplete identity/ABI/family proofs remain explicit blockers for integration.
"""
import argparse
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor, as_completed
from contextlib import closing
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import subprocess
import struct
import sys
import uuid

from roc import clients, libs, match, native_drafts, rebuild
from roc.draft_merger import content_hash, proof_key

VERIFIER_SHA256 = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()


def closed_function_targets(bindings):
    """Only unique original-body identities may close external function calls."""
    found = defaultdict(set)
    for binding in bindings:
        if (binding.get('evidence') == 'unique-body' and binding.get('body_exact') is True
                and binding.get('function_start') is True):
            found[binding['symbol']].add(int(binding['address'], 16))
    return {symbol: next(iter(addresses)) for symbol, addresses in found.items() if len(addresses) == 1}


def numeric_literal_targets(original, obj, methods):
    """Close scalar/SIMD constant relocations only after checking actual original bytes."""
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {name: (body, refs) for name, body, refs in match.coff_functions(raw)}
    targets, evidence = defaultdict(set), []
    for name, address in methods:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        if not match.exact_match(target, target_refs, body, refs):
            raise ValueError('Numeric data verification requires exact original method code')
        start, section = definitions[name]
        table = sections[section]
        for index in range(table[7]):
            offset, symbol_index, kind = struct.unpack_from('<IIH', raw, table[5] + index * 10)
            offset -= start
            if kind != 6 or not 0 <= offset <= len(body) - 4:
                continue
            symbol = symbols[symbol_index][0]
            literal = re.fullmatch(r'__(real|xmm)@([0-9a-fA-F]+)', symbol)
            if not literal:
                continue
            width = len(literal[2]) // 2
            if (literal[1] == 'real' and width not in (4, 8)) or (literal[1] == 'xmm' and width != 16):
                raise ValueError('Unsupported compiler numeric literal width: ' + symbol)
            position, data_section = definitions[symbol]
            data_table = sections[data_section]
            if position < 0 or position + width > data_table[3]:
                raise ValueError('Compiler numeric literal exceeds its data section')
            emitted = raw[data_table[4] + position:data_table[4] + position + width]
            expected = int(literal[2], 16).to_bytes(width, 'little')
            value = (struct.unpack_from('<I', target, offset)[0] -
                     struct.unpack_from('<i', raw, table[4] + start + offset)[0]) & 0xffffffff
            if emitted != expected or original.data(value, width) != emitted:
                raise ValueError('Original numeric literal bytes differ: ' + symbol)
            targets[symbol].add(value)
            evidence.append(dict(symbol=symbol, address='%08x' % value, bytes=emitted.hex()))
    return dict(targets={symbol: next(iter(values)) for symbol, values in targets.items() if len(values) == 1},
                literals=evidence)


def reviewed_call_targets(original, binder, obj, methods, bindings):
    """Source-only name inference from local identity evidence, never uploaded call claims."""
    known = defaultdict(list)
    for row in bindings:
        if row.get('function_start') is True and row.get('votes', 0) >= 1:
            known[(row['symbol'], int(row['address'], 16))].append(row)
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {name: (body, refs) for name, body, refs in match.coff_functions(raw)}
    targets, notes, aliases = defaultdict(set), [], set()
    for name, address in methods:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        if not match.exact_match(target, target_refs, body, refs):
            raise ValueError('Reviewed call inference requires exact original method instructions')
        start, section = definitions[name]
        table = sections[section]
        for index in range(table[7]):
            offset, symbol_index, kind = struct.unpack_from('<IIH', raw, table[5] + index * 10)
            offset -= start
            if kind != 20 or not 1 <= offset <= len(body) - 4 or body[offset - 1] not in (0xe8, 0xe9):
                continue
            symbol = symbols[symbol_index][0]
            value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            candidates = known.get((symbol, value), [])
            if not candidates or symbol.startswith('__imp_'):
                continue
            executable = any(section.Characteristics & 0x20000000
                             and original.image + section.VirtualAddress <= value <
                             original.image + section.VirtualAddress + section.Misc_VirtualSize
                             for section in original.pe.sections)
            if not executable:
                continue
            imported = original.imported(value)
            if imported and imported[1] == binder.plain(symbol):
                continue  # The ordinary import verifier already provides stronger evidence.
            targets[symbol].add(value)
            note = max(candidates, key=lambda row: row['votes'])
            notes.append(dict(symbol=symbol, address='%08x' % value, evidence=note.get('evidence'),
                              votes=note['votes'], inferred=True, imported_alias=list(imported) if imported else None))
            if imported:
                aliases.add(value)
    if any(len(values) != 1 for values in targets.values()):
        raise ValueError('Conflicting inferred direct-call targets need review')
    return dict(targets={symbol: next(iter(values)) for symbol, values in targets.items()},
                notes=notes, import_aliases=aliases)


class ReviewedOriginal:
    """Keep byte/import/RTTI verification; permit explicitly evidenced function-name aliases."""
    def __init__(self, original, aliases):
        self.original, self.aliases = original, aliases

    def imported(self, value):
        return None if value in self.aliases else self.original.imported(value)

    def __getattr__(self, name):
        return getattr(self.original, name)

def claims_from(value, found=None):
    found = found if found is not None else defaultdict(set)
    if isinstance(value, dict):
        symbol = value.get('symbol', value.get('name'))
        address = value.get('address', value.get('addr'))
        if isinstance(symbol, str) and symbol.startswith(('?', '_')):
            try:
                address = int(address, 16) if isinstance(address, str) else address
                if type(address) is int and 0x400000 <= address < 0x1000000:
                    found[symbol].add(address)
            except ValueError:
                pass
        for item in value.values():
            claims_from(item, found)
    elif isinstance(value, list):
        for item in value:
            claims_from(item, found)
    return found


def flags(root):
    recipe = libs.RECIPES['rbxgs']
    result = ['/nologo', '/c', '/O2', '/Ob2', '/Oy', '/GF', '/GS-', '/EHsc', '/MD',
              '/D_AFXDLL', '/DNDEBUG', '/D_MBCS', '/DNOMINMAX', '/DBOOST_ALL_NO_LIB']
    result += ['/D' + word for word in recipe['defines'].split()]
    result += ['/I' + str(root / 'rebuild/2008-06/native-headers'),
               '/I' + str(root / 'tools/libs/mfc-9.0-rtm/atlmfc/include')]
    result += ['/I' + str((libs.LIBS / path).resolve()) for path in recipe['include'] if path != 'WINSDK']
    result += ['/D_XTP_STATICLINK', '/D_XTPLIB_NOAUTOLINK',
               '/I' + str(root / 'tools/libs/xtp-11.2.2/Source')]
    return result


def compile_review_blockers(raw, root=None, path=None):
    """Untrusted preprocessing cannot redirect compiler reads to external paths."""
    text = raw.decode('utf-8-sig').replace('\\\r\n', '').replace('\\\n', '')
    # Preserve quoted literals while removing comments before examining directives.
    text = re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|/\*.*?\*/|//[^\n]*',
                  lambda hit: hit[0] if hit[0].startswith(('"', "'")) else ' ', text, flags=re.S)
    blockers = []
    if re.search(r'\binclude_alias\b|^\s*#\s*import\b', text, re.M):
        blockers.append('Compiler import/include redirection needs explicit review')
    for directive in re.findall(r'^\s*#\s*include\b([^\n]*)', text, re.M):
        literal = re.fullmatch(r'\s*(?:"([A-Za-z0-9_./+ -]+)"|<([A-Za-z0-9_./+ -]+)>)\s*', directive)
        include = (literal[1] or literal[2]) if literal else None
        allowed_relative = False
        if literal and root is not None and path is not None:
            resolved = (Path(root) / path).parent.joinpath(include).resolve()
            allowed_relative = resolved.is_relative_to(Path(root).resolve()) and resolved.is_file()
        if not literal or include.startswith('/') or ('..' in include.split('/') and not allowed_relative):
            blockers.append('Computed/external include needs explicit review: ' + directive.strip())
    return blockers


def original_view(root):
    import pefile
    sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
    import native_bind
    path = clients.exe_path('2008-06', clients.load()['2008-06'])
    if content_hash(path.read_bytes()) != clients.load()['2008-06']['sha256']:
        raise ValueError('Registered original client hash mismatch')
    original = native_bind.Original.__new__(native_bind.Original)
    original.pe = pefile.PE(str(path))
    original.image = original.pe.OPTIONAL_HEADER.ImageBase
    original.imports = {item.address: (dll.dll.decode().lower(), item.ordinal,
                                      item.name.decode() if item.name else None)
                        for dll in original.pe.DIRECTORY_ENTRY_IMPORT for item in dll.imports}
    original.mfc = {}
    definition = root / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def'
    for line in definition.read_text(errors='ignore').splitlines():
        hit = re.match(r'\s*(\S+)\s+@\s*(\d+)', line)
        if hit:
            original.mfc[int(hit[2])] = hit[1]
    return original, native_bind


def freeze_headers(root, output):
    """Private compiler inputs; installed vendor/tool trees remain read-through."""
    from roc.input_reuse import ensure_link
    frozen = output / 'inputs'
    if frozen.exists():
        frozen = output / ('inputs-' + uuid.uuid4().hex)
    frozen.mkdir(parents=True)
    paths = []
    for family in ('native-headers', 'native-classes'):
        parent = root / 'rebuild/2008-06' / family
        for path in sorted(parent.rglob('*')):
            if not path.is_file():
                continue
            if path.is_symlink() or not path.resolve().is_relative_to(root):
                raise ValueError('Canonical compiler input alias needs review: ' + str(path))
            paths.append(path)
    inventory = {path.relative_to(root).as_posix():content_hash(path.read_bytes()) for path in paths}
    for path in paths:
        name = path.relative_to(root).as_posix()
        raw = path.read_bytes()
        if content_hash(raw) != inventory[name]:
            raise ValueError('Compiler input changed during frozen copy: ' + name)
        target = frozen / name
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(raw)
    current = {path.relative_to(root).as_posix():content_hash(path.read_bytes())
               for family in ('native-headers', 'native-classes')
               for path in (root/'rebuild/2008-06'/family).rglob('*') if path.is_file()}
    if current != inventory:
        raise ValueError('Canonical compiler inventory changed during frozen copy')
    ensure_link(root / 'tools', frozen / 'tools')
    native_drafts.atomic(frozen / 'inventory.json', inventory)
    return frozen, inventory


def measure(root, limit=None, workers=3, reviews_only=False):
    from roc.integration_verify import input_hash
    root = Path(root).resolve()
    token = native_drafts.integration_lock(root, 'start')['token']
    try:
        folder = root / 'work/draft-merger'
        latest = json.loads((folder / 'latest.json').read_text())
        before = input_hash(root)
        verifier_sha = VERIFIER_SHA256
        configuration = flags(root)
        key = proof_key(dict(inputs=before, verifier_sha256=verifier_sha, flags=configuration))
        output = folder / 'native' / key / uuid.uuid4().hex
        output.mkdir(parents=True, exist_ok=True)
        frozen, frozen_inventory = freeze_headers(root, output)
        effective_flags = flags(frozen)
        original, bindings = original_view(root)
        closure_path = root / 'work/native-client/claude-identity-closure.json'
        closure_raw = closure_path.read_bytes() if closure_path.is_file() else None
        external = closed_function_targets(json.loads(closure_raw).get('bindings', [])) if closure_raw else {}
        tc = rebuild.toolchain(21022)
        claims = defaultdict(set)
        unique = {}
        with closing(sqlite3.connect(folder / 'state.sqlite3')) as db:
            for bundle in latest['bundles']:
                for item in bundle['files']:
                    name, sha = item['path'], item['candidate_sha256']
                    if item['state'] == 'unsafe-current-path':
                        continue
                    native_drafts.safe_path(name)
                    if sha is None:
                        continue
                    raw = db.execute('SELECT bytes FROM contents WHERE sha256=?', (sha,)).fetchone()[0]
                    if content_hash(raw) != sha:
                        raise ValueError('Coordinator content archive hash mismatch')
                    if name.endswith('.json'):
                        try:
                            claims_from(json.loads(raw.decode('utf-8-sig')), claims)
                        except (ValueError, UnicodeError):
                            pass
                    if not reviews_only and name.startswith('rebuild/2008-06/native-classes/') and Path(name).suffix in ('.cpp', '.c', '.cc', '.cxx'):
                        identity = (name, sha)
                        if identity not in unique:
                            unique[identity] = dict(path=name, sha256=sha, raw=raw, bundles=[])
                        unique[identity]['bundles'].append(bundle['id'])
            if db.execute("SELECT 1 FROM sqlite_master WHERE type='table' AND name='review_proposals'").fetchone():
                for proposal, job, name, sha, source in db.execute("SELECT id,job,path,sha256,source FROM review_proposals WHERE state='unverified'"):
                    native_drafts.safe_path(name)
                    raw = source.encode()
                    if content_hash(raw) != sha:
                        raise ValueError('LLM proposal archive hash mismatch')
                    metadata = db.execute('SELECT packet FROM review_jobs WHERE id=?', (job,)).fetchone()
                    bundles = json.loads(metadata[0]).get('bundles', []) if metadata else []
                    identity = (name, sha)
                    unique.setdefault(identity, dict(path=name, sha256=sha, raw=raw, bundles=bundles, proposals=[]))
                    unique[identity].setdefault('proposals', []).append(proposal)
        candidates = sorted(unique.values(), key=lambda row: (row['path'], row['sha256']))
        if limit is not None:
            candidates = candidates[:limit]

        def compile_source(raw, path, directory):
            directory.mkdir(parents=True, exist_ok=True)
            source = directory / Path(path).name
            source.write_bytes(raw)
            obj = directory / 'unit.obj'
            code, log = rebuild.run(tc, 'cl', effective_flags + ['/showIncludes', '/I' + str((frozen / path).parent),
                                     '/Fo' + str(obj), str(source)], directory, timeout=120)
            (directory / 'compiler.log').write_text(log)
            return code, log, obj

        def one(candidate):
            path, sha = candidate['path'], candidate['sha256']
            directory = output / proof_key(dict(path=path, sha256=sha))
            row = dict(path=path, candidate_sha256=sha, bundles=candidate['bundles'],
                       proposals=candidate.get('proposals', []), input_key=key, methods=[], blockers=[], source_accepted=False)
            try:
                row['blockers'].extend(compile_review_blockers(candidate['raw'], root, path))
                if row['blockers']:
                    return row
                code, log, obj = compile_source(candidate['raw'], path, directory / 'candidate')
                row.update(compile_exit=code, object=str(obj))
                if code:
                    row['blockers'].append('Candidate compile failed against current canonical headers: ' + log[-3000:])
                    return row
                bodies = {name: (body, refs) for name, body, refs in match.coff_functions(obj.read_bytes())}
                current = frozen / path
                baseline = {}
                if current.is_file():
                    bcode, blog, bobj = compile_source(current.read_bytes(), path, directory / 'baseline')
                    row['baseline_compile_exit'] = bcode
                    if bcode:
                        row['blockers'].append('Current file baseline compile failed; cannot prove a replacement gain: ' + blog[-1200:])
                    else:
                        baseline = {name: (body, refs) for name, body, refs in match.coff_functions(bobj.read_bytes())}
                exact = []
                for symbol, (body, refs) in bodies.items():
                    for address in sorted(claims.get(symbol, ())):
                        target, target_refs, _ = match.target('2008-06', '%08x' % address)
                        hit = dict(symbol=symbol, address='%08x' % address,
                                   exact_code=match.exact_match(target, target_refs, body, refs),
                                   score=match.score(target, target_refs, body, refs),
                                   has_relocations=bool(refs), references_verified=False)
                        if symbol in baseline:
                            bbody, brefs = baseline[symbol]
                            hit['baseline_exact_code'] = match.exact_match(target, target_refs, bbody, brefs)
                        if hit['exact_code']:
                            exact.append(hit)
                        row['methods'].append(hit)
                own = {item['symbol']: int(item['address'], 16) for item in exact
                       if sum(other['symbol'] == item['symbol'] for other in exact) == 1}
                for item in exact:
                    try:
                        methods = [(item['symbol'], int(item['address'], 16))]
                        numeric = numeric_literal_targets(original, obj, methods)
                        evidence = bindings.verify(original, obj, methods, dict(external, **numeric['targets']), own)
                        item['numeric_literals'] = numeric['literals']
                        item['references_verified'] = not any(record['local_eh'] for record in evidence)
                        item['reference_evidence'] = evidence
                        if not item['references_verified']:
                            item['reference_blocker'] = 'Compiler-local exception/unwind metadata still unproved'
                    except (AssertionError, KeyError, ValueError, IndexError, UnicodeError) as error:
                        item['reference_blocker'] = str(error)
                if not row['methods']:
                    row['blockers'].append('No symbol/address hypothesis available for independently checking emitted methods')
                elif not exact:
                    row['blockers'].append('No claimed emitted method exactly matches original code under pinned recipe')
                row['blockers'].extend(['Original symbol-to-target identity and class ABI/dependency proof still required',
                                        'Reconcile against repo-wide existing providers before method extraction',
                                        'Final combined candidate preservation/symbol/regression gates not run'])
            except (ValueError, KeyError, OSError, IndexError, subprocess.TimeoutExpired) as error:
                row['blockers'].append('Verifier infrastructure or input error: ' + str(error))
            finally:
                native_drafts.atomic(directory / 'measurement.json', row)
            return row

        results = []
        with ThreadPoolExecutor(max_workers=workers) as pool:
            futures = [pool.submit(one, candidate) for candidate in candidates]
            for future in as_completed(futures):
                results.append(future.result())
                native_drafts.atomic(output / 'progress.json', dict(total=len(candidates), completed=len(results)))
                print('Measured %s/%s %s' % (len(results), len(candidates), results[-1]['path']), flush=True)
        stale = (input_hash(root) != before or content_hash(Path(__file__).read_bytes()) != verifier_sha
                 or (closure_raw is not None and closure_path.read_bytes() != closure_raw))
        summary = dict(input_key=key, run=latest['summary']['run'], total_available=len(unique),
                       measured=len(results), stale=stale,
                       compiled=sum(row.get('compile_exit') == 0 for row in results),
                       code_exacts=sum(item['exact_code'] for row in results for item in row['methods']),
                       reference_passes=sum(item['references_verified'] for row in results for item in row['methods']),
                       source_accepted=0, executable_promotions=0,
                       frozen_inputs=str(frozen), frozen_inventory_key=proof_key(frozen_inventory),
                       verifier_sha256=verifier_sha, flags=effective_flags)
        summary['external_identity_sha256'] = content_hash(closure_raw) if closure_raw else None
        native_drafts.atomic(output / 'report.json', dict(summary=summary, units=results))
        filename = 'native-review-latest.json' if reviews_only else 'native-latest.json' if limit is None else 'native-sample-latest.json'
        native_drafts.atomic(folder / filename,
                             dict(summary=summary, units=results))
        if limit is None and not reviews_only:
            native_drafts.atomic(folder / 'native-complete-latest.json', dict(summary=summary, units=results))
        return summary
    finally:
        native_drafts.integration_lock(root, 'release', token=token)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--limit', type=int)
    parser.add_argument('--workers', type=int, choices=(1, 2, 3), default=3)
    parser.add_argument('--reviews-only', action='store_true')
    args = parser.parse_args()
    print(json.dumps(measure(args.root, args.limit, args.workers, args.reviews_only), indent=2))
