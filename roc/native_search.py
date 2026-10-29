"""Search-only native diagnostics and retained candidates. Never grants coverage."""
import difflib
import json
import re
import threading
import time
from collections import Counter
from pathlib import Path

from roc import integration, match


def diagnose(obj, symbols):
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
        target, target_relocs, _ = match.target('2008-06', addr)
        before, after = match.asm_lines(target, target_relocs), match.asm_lines(code, relocs)
        frame = lambda lines: next((s for s in lines if re.match(r'sub esp,', s)), '')
        calls = lambda lines: [s for s in lines if s.startswith('call ')]
        frame_ok, calls_ok = frame(before) == frame(after), calls(before) == calls(after)
        byte_equal = (set(target_relocs) <= set(relocs) and len(target) == len(code)
                      and match.masked(target, relocs) == match.masked(code, relocs))
        bad = []
        if byte_equal:
            _, bad = match.data_check('2008-06', addr, target, match.coff_data_refs(obj, symbol))
        blocker = ('referenced-data' if bad else 'exact-unowned' if byte_equal else
                   'frame-lifetime' if not frame_ok else 'callee-context' if not calls_ok else
                   'floating-point' if any(s.startswith(('fld ', 'fmul ', 'fadd ', 'fstp ')) for s in before) else
                   'instruction-order')
        recipes = {'referenced-data': ['authentic-constants'], 'exact-unowned': ['ownership-review'],
                   'frame-lifetime': ['scope-lifetime', 'map-value-type'],
                   'callee-context': ['visible-callee', 'template-emission', 'scoped-noautoinline'],
                   'floating-point': ['scoped-fp', 'expression-lifetime'],
                   'instruction-order': ['scoped-osize', 'scoped-speed', 'expression-lifetime']}
        rows[addr] = dict(score=round(100 * match.similarity_ratio(target, target_relocs, code, relocs), 6),
                          frame_ok=frame_ok, calls_ok=calls_ok, blocker=blocker, recipes=recipes[blocker],
                          symbol=symbol, code_exact=byte_equal, data_exact=byte_equal and not bad,
                          diff='\n'.join(list(difflib.unified_diff(before, after, 'target', 'rebuilt', n=1))[:60]))
    return rows


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
                records = [r for r in records if r['base_revision'] == self.revision and r['baseline_sha256'] == integration.digest(original)]
                previous_score = max([base.get('score', 0)] + [r['score'] for r in records])
                frame_before = any(r.get('frame_ok') for r in records) or base.get('frame_ok', False)
                calls_before = any(r.get('calls_ok') for r in records) or base.get('calls_ok', False)
                row = dict(row, file=rel, addr=addr, base_revision=self.revision,
                           baseline_sha256=integration.digest(original), source_sha256=integration.digest(candidate),
                           source=candidate, object_sha256=result.get('object_sha256'), object=result.get('object'),
                           mode=result.get('mode'), accepted=False, losses=[], status='local-partial')
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
                                   and r['source_sha256'] == integration.digest(r['source']))
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


def metrics(records, seconds, proposals=(), verified=0, compilations=None):
    compiled = compilations if compilations is not None else records
    return dict(wall_seconds=round(seconds, 3), compile_seconds=round(sum(r.get('seconds', 0) for r in compiled), 3),
                match_seconds=round(sum(r.get('match_seconds', 0) for r in records), 3),
                generation_seconds=round(sum(r.get('generation_seconds') or 0 for r in records), 3),
                queue_seconds=round(sum(r.get('queue_seconds', 0) for r in compiled), 3),
                compile_cache_hits=sum(bool(r.get('compile_cache_hit')) for r in compiled),
                search_cache_hits=sum(bool(r.get('search_cache_hit')) for r in records),
                blockers=dict(Counter(d['blocker'] for r in records for d in r.get('diagnostics', {}).values())),
                local_exact=sum(len(p['witnesses']) for p in proposals), server_verified=verified,
                verified_per_hour=verified * 3600 / max(seconds, .001))


def blocker_queues(records):
    queues = {}
    for result in records:
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
