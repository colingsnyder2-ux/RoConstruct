"""Search-only native diagnostics and retained candidates. Never grants coverage."""
import difflib
import hashlib
import json
import re
import threading
import time
from collections import Counter
from pathlib import Path
import sqlite3

from roc import integration, match


def diagnose(obj, symbols, client='2008-06'):
    """Compare only the rebuild's known symbols; fuzzy results never prove ownership."""
    if not symbols:
        return {}
    functions = {s: (b, r) for s, b, r in match.coff_functions(obj)}
    rows = {}
    for addr, symbol in symbols.items():
        if symbol not in functions:
            rows[addr] = dict(score=0, blocker='missing-body', recipes=['native-declaration', 'template-emission'])
            continue
        code, relocs = functions[symbol]
        target, target_relocs, _ = match.target(client, addr)
        before, after = match.asm_lines(target, target_relocs), match.asm_lines(code, relocs)
        frame = lambda lines: next((s for s in lines if re.match(r'sub esp,', s)), '')
        calls = lambda lines: [s for s in lines if s.startswith('call ')]
        frame_ok, calls_ok = frame(before) == frame(after), calls(before) == calls(after)
        byte_equal = (set(target_relocs) <= set(relocs) and len(target) == len(code)
                      and match.masked(target, relocs) == match.masked(code, relocs))
        bad = []
        if byte_equal:
            _, bad = match.data_check(client, addr, target, match.coff_data_refs(obj, symbol))
        ret = lambda lines: next((s for s in reversed(lines) if s.startswith('ret')), '')
        immediates = []
        numeric = re.compile(r'^(.*?, )(-?(?:0x[0-9a-f]+|\d+))$')
        matcher = difflib.SequenceMatcher(None, [s.split(' ', 1)[0] for s in before],
                                          [s.split(' ', 1)[0] for s in after], autojunk=False)
        for block in matcher.get_matching_blocks():
            for i in range(block.size):
                left, right = before[block.a + i], after[block.b + i]
                a, b = numeric.match(left), numeric.match(right)
                if a and b and a[1] == b[1] and a[2] != b[2] and '[' not in a[1]:
                    immediates.append(dict(value=int(a[2], 0), compiled_value=int(b[2], 0), target_asm=left, rebuilt_asm=right))
        blocker = ('referenced-data' if bad else 'exact-unowned' if byte_equal else
                   'abi-review' if ret(before) != ret(after) else 'wrong-immediate' if immediates else
                   'frame-lifetime' if not frame_ok else 'callee-context' if not calls_ok else
                   'floating-point' if any(s.startswith(('fld ', 'fmul ', 'fadd ', 'fstp ')) for s in before) else
                   'instruction-order')
        recipes = {'referenced-data': ['authentic-constants'], 'exact-unowned': ['ownership-review'],
                   'abi-review': ['native-declaration', 'calling-convention'],
                   'wrong-immediate': ['target-immediate'],
                   'frame-lifetime': ['scope-lifetime', 'map-value-type'],
                   'callee-context': ['visible-callee', 'template-emission', 'scoped-noautoinline'],
                   'floating-point': ['scoped-fp', 'expression-lifetime'],
                   'instruction-order': ['scoped-osize', 'scoped-speed', 'expression-lifetime']}
        rows[addr] = dict(score=round(100 * match.similarity_ratio(target, target_relocs, code, relocs), 6),
                          frame_ok=frame_ok, calls_ok=calls_ok, blocker=blocker, recipes=recipes[blocker],
                          symbol=symbol, code_exact=byte_equal, data_exact=byte_equal and not bad, immediates=immediates,
                          diff='\n'.join(list(difflib.unified_diff(before, after, 'target', 'rebuilt', n=1))[:60]))
    return rows


def visible_callees_ok(source, obj, facts, rel, client='2008-06'):
    from roc.native_sweep import methods, symbol_method
    defined = methods(source)
    required = [f for f in facts if f.get('file') == rel and f.get('required_symbol')
                and f.get('definition') and (f['definition'] in source or symbol_method(f['required_symbol']) in defined)]
    if not required:
        return True
    functions = {s:(b,r) for s,b,r in match.coff_functions(obj)}
    for fact in required:
        if fact['required_symbol'] not in functions:
            continue  # Fully inlined: cannot override the original out-of-line implementation.
        body, relocs = functions[fact['required_symbol']]
        target, target_relocs, _ = match.target(client, fact['target'])
        if not set(target_relocs) <= set(relocs) or len(target) != len(body) or match.masked(target,relocs) != match.masked(body,relocs):
            return False
        if match.data_check(client,fact['target'],target,match.coff_data_refs(obj,fact['required_symbol']))[1]:
            return False
    return True


class Partials:
    """Versioned per-function Pareto shortlist; local suggestions, never accepted edits."""
    def __init__(self, output, revision, floor=50, limit=3, on_improvement=None):
        self.root = Path(output) / 'partials'
        self.root.mkdir(parents=True, exist_ok=True)
        self.revision, self.floor, self.limit = revision, floor, limit
        self.lock = threading.Lock()
        self.on_improvement = on_improvement

    def retain(self, rel, original, candidate, result, rows, baseline, losses):
        if losses or not result.get('ok') or candidate == original:
            return []
        saved = []
        with self.lock:
            for addr, row in rows.items():
                base = baseline.get(addr, {})
                metrics = lambda r: (r.get('score', 0), int(r.get('frame_ok', False)), int(r.get('calls_ok', False)))
                if row['score'] < self.floor or row.get('data_exact') or not any(a > b for a, b in zip(metrics(row), metrics(base))):
                    continue
                key = integration.digest([rel, addr])[:24]
                path = self.root / (key + '.json')
                records = json.loads(path.read_text()) if path.exists() else []
                if any(r['base_revision'] != self.revision or r['baseline_sha256'] != integration.digest(original) for r in records):
                    integration.atomic_json(self.root / 'history' / (key + '-' + integration.digest(records)[:16] + '.json'), records)
                records = [r for r in records if r['base_revision'] == self.revision and r['baseline_sha256'] == integration.digest(original)]
                previous_score = max([base.get('score', 0)] + [r['score'] for r in records])
                frame_before = any(r.get('frame_ok') for r in records) or base.get('frame_ok', False)
                calls_before = any(r.get('calls_ok') for r in records) or base.get('calls_ok', False)
                row = dict(row, file=rel, addr=addr, base_revision=self.revision,
                           baseline_sha256=integration.digest(original), source_sha256=hashlib.sha256(candidate.encode('utf-8')).hexdigest(),
                           format=2, baseline_content_sha256=hashlib.sha256(original.encode('utf-8')).hexdigest(),
                           compiler_source_sha256=result.get('compiler_config', {}).get('source_sha256'),
                           source=candidate, object_sha256=result.get('object_sha256'), object=result.get('object'),
                           mode=result.get('mode'), accepted=False, losses=[], status='local-partial',
                           compiler_config=result.get('compiler_config', {}), input_signature=result.get('input_signature'))
                if any(all(a >= b for a, b in zip(metrics(r), metrics(row))) for r in records):
                    continue
                records = [r for r in records if not all(a >= b for a, b in zip(metrics(row), metrics(r)))]
                records.append(row)
                records.sort(key=lambda r: metrics(r), reverse=True)
                # Preserve structural alternatives even when byte score ranks lower.
                chosen = []
                for field in ('frame_ok', 'calls_ok'):
                    best = max(records, key=lambda r: (r.get(field, False), r['score']))
                    if best not in chosen:
                        chosen.append(best)
                records = (records[:1] + [r for r in chosen + records[1:] if r != records[0]])
                unique = {r['source_sha256']: r for r in records}
                integration.atomic_json(path, list(unique.values())[:self.limit])
                saved.append(addr)
                if self.on_improvement and (row['score'] > previous_score or row.get('frame_ok') and not frame_before
                                            or row.get('calls_ok') and not calls_before):
                    self.on_improvement(dict(file=rel, addr=addr, previous=previous_score, score=row['score'],
                        frame_before=frame_before, frame_ok=row.get('frame_ok', False),
                        calls_before=calls_before, calls_ok=row.get('calls_ok', False),
                        source_sha256=row['source_sha256'], object_sha256=row.get('object_sha256'),
                        base_revision=self.revision, accepted=False))
        return saved

    def seed(self, rel, original, addrs):
        choices = []
        with self.lock:
            for addr in addrs:
                path = self.root / (integration.digest([rel, addr])[:24] + '.json')
                if path.exists():
                    choices.extend(r for r in json.loads(path.read_text()) if r['base_revision'] == self.revision
                                   and r['baseline_sha256'] == integration.digest(original)
                                   and r['source_sha256'] == (hashlib.sha256(r['source'].encode('utf-8')).hexdigest()
                                       if r.get('format') == 2 else integration.digest(r['source'])))
        return max(choices, key=lambda r: r['score'], default=None)


class Journal:
    """Append results immediately; checkpoint legacy JSON at bounded intervals."""
    def __init__(self, output, interval=10):
        self.output, self.interval, self.last = Path(output), interval, time.monotonic()
        self.records = []
        self.output.mkdir(parents=True, exist_ok=True)
        self.run_id = __import__('uuid').uuid4().hex

    def add(self, records):
        self.records.extend(records)
        with (self.output / 'trials.jsonl').open('a', encoding='utf-8') as stream:
            for row in records:
                stream.write(json.dumps(dict(row, search_run=self.run_id)) + '\n')
        if time.monotonic() - self.last >= self.interval:
            self.flush()

    def flush(self):
        integration.atomic_json(self.output / 'trials.json', self.records)
        self.last = time.monotonic()


def scoped_variants(text, modes, selected=None):
    """Each pragma trial changes exactly one native method; restore command-line state."""
    from roc.native_sweep import methods, masked_cpp
    pragmas = {'scoped-osize': ('#pragma optimize("s", on)', '#pragma optimize("", on)'),
               'scoped-speed': ('#pragma optimize("t", on)', '#pragma optimize("", on)'),
               'scoped-noautoinline': ('#pragma auto_inline(off)', '#pragma auto_inline(on)'),
               'scoped-fp': ('#pragma float_control(push)\n#pragma float_control(precise, off)', '#pragma float_control(pop)')}
    clean = masked_cpp(text)
    for method, (start, end) in methods(text).items():
        if selected is not None and method not in selected:
            continue
        # Method scanner includes return type. Pragmas require their own physical line.
        # Existing pragmas can carry nested state; leave those files to explicit recipes.
        if re.search(r'^\s*#\s*pragma\s+(?:optimize|auto_inline|float_control)', masked_cpp(text), re.M):
            continue
        start = max(clean.rfind(c, 0, start) for c in ('\n', ';', '{', '}')) + 1
        if '#' in clean[start:end].split('{', 1)[0]:
            continue
        for mode in modes:
            if mode not in pragmas:
                continue
            before, after = pragmas[mode]
            old = text[start:end]
            new = '\n' + before + '\n' + old + '\n' + after + '\n'
            yield mode + ':' + method, text[:start] + new + text[end:], [[old, new]]


def anchored_changes(original, candidate):
    """Compose a retained seed and model edits against the original accepted file."""
    from roc.native_sweep import apply_edits
    before, after = original.splitlines(keepends=True), candidate.splitlines(keepends=True)
    edits = []
    for group in difflib.SequenceMatcher(None, before, after, autojunk=False).get_grouped_opcodes(3):
        edits.append([''.join(before[group[0][1]:group[-1][2]]), ''.join(after[group[0][3]:group[-1][4]])])
    try:
        if apply_edits(original, edits) == candidate:
            return edits
    except ValueError:
        pass
    return [[original, candidate]] if original != candidate else []


def explicit_variants(text, rules, rel):
    """Evidence-backed anchored rewrites, reusable across an explicitly listed family."""
    from roc.native_sweep import apply_edits
    for rule in rules:
        if not rule.get('evidence') or rel not in rule.get('files', []):
            continue
        edits = rule['edits']
        try:
            integration.validate_patches({rel: edits})
            changed = apply_edits(text, edits)
        except ValueError:
            continue
        yield 'rule:' + rule['name'], changed, edits


def merge_choices(text, choices, verify):
    """Greedily combine compatible proofs. Every increment rechecks the full TU."""
    from roc.native_sweep import apply_edits
    edits, witnesses, best = [], {}, None
    for choice in sorted(choices, key=lambda p: (-len(p['witnesses']), len(p['edits']))):
        additions = [pair for pair in choice['edits'] if pair not in edits]
        if not additions:
            continue
        trial = edits + additions
        wanted = {h['addr']: h for h in choice['witnesses']}
        if set(wanted) <= set(witnesses):
            continue
        wanted.update(witnesses)
        try:
            source = apply_edits(text, trial)
        except ValueError:
            continue
        proof = verify(source, set(wanted))
        if proof is not None:
            edits, witnesses, best = trial, wanted, proof
    if best is not None:
        return dict(edits=edits, witnesses=list(witnesses.values()), proof=best, mode='combined')


def metrics(records, seconds, proposals=(), verified=0, compilations=None, verification_wait=0):
    compiled = compilations if compilations is not None else records
    from roc.integration_policy import local_metrics
    measured = local_metrics(records, compiled)
    return dict(measured, wall_seconds=round(seconds, 3), compile_seconds=round(sum(r.get('seconds', 0) for r in compiled), 3),
                match_seconds=round(sum(r.get('match_seconds', 0) for r in records), 3),
                generation_seconds=round(sum(r['generation_seconds'] for r in measured['model_usage'].values()) if measured['model_requests'] else sum(r.get('generation_seconds') or 0 for r in records), 3),
                queue_seconds=round(sum(r.get('queue_seconds', 0) for r in compiled), 3),
                compile_cache_hits=sum(bool(r.get('compile_cache_hit')) for r in compiled),
                search_cache_hits=sum(bool(r.get('search_cache_hit')) for r in records),
                blockers=dict(Counter(d['blocker'] for r in records for d in r.get('diagnostics', {}).values())),
                local_exact=sum(len(p['witnesses']) for p in proposals), server_verified=verified,
                verification_wait_seconds=round(verification_wait, 3),
                verified_per_hour=verified * 3600 / max(seconds, .001))


def blocker_queues(records):
    queues = {}
    for result in records:
        if result.get('blocker') or result.get('error_category'):
            kind = result.get('blocker') or result['error_category']
            queues[result.get('file', '?') + ':' + kind] = dict(file=result.get('file'), blocker=kind,
                score=0, error=result.get('error', ''), accepted=False)
        for addr, row in result.get('diagnostics', {}).items():
            key = result['file'] + ':' + addr
            if key not in queues or row['score'] > queues[key]['score']:
                queues[key] = dict(row, file=result['file'], addr=addr)
        for addr, candidates in result.get('ownership_candidates', {}).items():
            if candidates != [addr]:
                queues[result['file'] + ':' + addr] = dict(file=result['file'], addr=addr, score=100,
                    blocker='ambiguous-ownership', candidates=candidates, accepted=False)
    grouped = {}
    for row in queues.values():
        grouped.setdefault(row['blocker'], []).append(row)
    return grouped


def production_report(root, hours=6):
    """Read independently accepted receipts; never convert local proofs into throughput."""
    root = Path(root)
    if hours <= 0:
        raise ValueError('Receipt window must be positive')
    database = root/'work/server.db'
    if not database.exists():
        return dict(state='missing-server-receipts', server_verified=0)
    now = time.time()
    with sqlite3.connect('file:'+database.as_posix()+'?mode=ro', uri=True, timeout=10) as db:
        rows = db.execute('SELECT id,state,receipt,created,updated FROM integration_jobs WHERE updated>=?', (now-hours*3600,)).fetchall()
        count = db.execute('SELECT COUNT(*) FROM integration_credit WHERE ts>=?', (now-hours*3600,)).fetchone()[0]
    accepted, verification, jobs = 0, [], []
    for identifier, state, payload, created, updated in rows:
        receipt = json.loads(payload or '{}')
        if state == 'accepted' and receipt.get('accepted'):
            accepted += 1
        if 'verification_seconds' in receipt:
            verification.append(receipt['verification_seconds'])
        jobs.append(dict(id=identifier, state=state, credits=receipt.get('credits', 0),
                         elapsed_seconds=round(updated-created, 3), verification_seconds=receipt.get('verification_seconds')))
    return dict(window_hours=hours, server_verified=count, verified_per_hour=count/hours,
                accepted_jobs=accepted, verification_seconds=sum(verification),
                timed_jobs=len(verification), jobs=jobs, local_proofs_counted=False)


def status(args):
    from roc import clients, native_sweep
    root = native_sweep.ROOT
    report = production_report(root, args.hours)
    report['native_profiles'] = {client: dict(ready=all((root/'rebuild'/client/p).is_file()
        for p in ('modules/rbxgs-app.json','manifests/functions.json','out/native-names.json')))
        for client in clients.load()}
    print(json.dumps(report, indent=1))


def register(cmd):
    cmd('native-search-status', status, 'accepted native throughput, verification timing and client readiness',
        (['--hours'], dict(type=float, default=6)))


def client_profile(config, client, output, jobs, limit, log):
    """Client-isolated native discovery when that client's authentic build inputs exist."""
    import hashlib
    from roc import clients, libs, rebuild, native_sweep
    root, output = native_sweep.ROOT, Path(output)
    profile = config.get('profiles', {}).get(client, {})
    module = profile.get('module', 'rbxgs-app')
    needed = [root/'rebuild'/client/'modules'/(module+'.json'), root/'rebuild'/client/'manifests/functions.json',
              root/'rebuild'/client/'out/native-names.json']
    missing = [str(p.relative_to(root)) for p in needed if not p.is_file()]
    if missing:
        result = dict(client=client, state='blocked', blocker='missing-native-profile', missing=missing, new_verified=0)
        integration.atomic_json(output/'summary.json', result)
        log(client + ': native discovery blocked by missing authentic client build inputs')
        return result
    entry = clients.load()[client]
    build = entry.get('compiler_build')
    if not build:
        raise ValueError('Unknown compiler build for '+client)
    spec = rebuild.load_module(client, module)
    tree, overlay = rebuild.build_overlay(client, spec['name'], spec.get('overlay'))
    layer = next(layer for layer in spec['layers'] if layer.get('recipe') and layer.get('direct'))
    recipe = libs.RECIPES[layer['recipe']]
    includes = [tree] + [libs._case_path(libs.LIBS/p) for p in recipe.get('include', []) if p != 'WINSDK']
    flags = profile.get('flags', layer['flags'])
    defines = (recipe.get('defines', '')+' '+layer.get('extra_defines', '')).strip()
    by_addr = {r['addr']: r for r in json.loads(needed[1].read_text())}
    names = json.loads(needed[2].read_text())
    targets = {a for a, r in by_addr.items() if r.get('score') == 100}
    matcher = native_sweep.Matcher(targets, output/'match-cache', client)
    paths = sorted({p for pattern in profile.get('files', config.get('files', ['App/*/*.cpp'])) for p in tree.glob(pattern)})
    if limit:
        paths = paths[:limit]
    texts = {p.relative_to(tree).as_posix(): (overlay/p.relative_to(tree) if (overlay/p.relative_to(tree)).exists() else p).read_text(errors='replace') for p in paths}
    def compile_source(source, rel, label):
        folder = output/'objects'/integration.digest([rel,label])[:24]
        folder.mkdir(parents=True, exist_ok=True)
        unit = folder/Path(rel).name
        unit.write_text(source, encoding='utf-8')
        started = time.monotonic()
        ok, message = rebuild.compile_direct(client, [unit], folder,
            [overlay/Path(rel).parent, tree/Path(rel).parent]+includes, defines, flags, cl=build)[str(unit)]
        obj = unit.with_suffix('.obj')
        command = obj.with_suffix('.command.json')
        signature = obj.with_suffix('.compile.json')
        return dict(file=rel, mode=label, ok=ok, object=str(obj), error=None if ok else message,
            seconds=time.monotonic()-started, compiler_config=json.loads(command.read_text()) if command.exists() else {},
            input_signature=json.loads(signature.read_text()).get('inputs') if signature.exists() else None,
            object_sha256=hashlib.sha256(obj.read_bytes()).hexdigest() if ok else None,
            compile_cache_hit=message == 'content cache hit')
    proposals, records, checks = native_sweep.grid_discovery(dict(config, client=client,
        base_revision=integration.digest([entry, spec, texts])), texts, targets, matcher, output, jobs,
        compile_source, names, by_addr, log)
    integration.atomic_json(output/'proposals.json', proposals)
    integration.atomic_json(output/'final-checks.json', checks)
    result = dict(client=client, state='proposals', native_verifier_available=False, new_verified=0,
                  compiler_build=build, proposed_files=len(proposals), tried=len(records))
    integration.atomic_json(output/'summary.json', result)
    return result
