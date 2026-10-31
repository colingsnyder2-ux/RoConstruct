"""Offline, evidence-labelled function graph. No compilation or server writes."""
import gzip
import hashlib
import json
import os
import re
from collections import defaultdict, deque
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
VERSION = 1
P2 = ['004e53c0', '004e5ff0', '007ab0a0', '0067d1f0', '0067d9b0']


def address(value):
    return '%08x' % (value if isinstance(value, int) else int(value, 16))


def read(path, default):
    return json.loads(path.read_text(encoding='utf-8')) if path.exists() else default


def dump(path, value):
    text = json.dumps(value, sort_keys=True, separators=(',', ':'), ensure_ascii=True) + '\n'
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.suffix == '.gz':
        payload = bytearray(gzip.compress(text.encode('utf-8'), mtime=0))
        payload[9] = 255  # Stable OS marker across Python platforms.
        if not path.exists() or path.read_bytes() != payload:
            path.write_bytes(payload)
    elif not path.exists() or path.read_text(encoding='utf-8') != text:
        path.write_text(text, encoding='utf-8')


class Graph:
    def __init__(self, data):
        self.data = data
        self.nodes = data['nodes']
        self.out = defaultdict(list)
        self.inc = defaultdict(list)
        for edge in data['edges']:
            self.out[edge['source']].append(edge)
            self.inc[edge['target']].append(edge)

    def walk(self, seeds, depth=2, reverse=False, kinds=None, limit=250):
        seen = set(seeds)
        queue = deque((s, 0) for s in sorted(seen))
        while queue and len(seen) < limit:
            node, distance = queue.popleft()
            if distance >= depth:
                continue
            for edge in (self.inc if reverse else self.out)[node]:
                if kinds and edge['kind'] not in kinds:
                    continue
                target = edge['source' if reverse else 'target']
                if target not in seen:
                    seen.add(target)
                    queue.append((target, distance + 1))
                    if len(seen) >= limit:
                        break
        return sorted(seen)

    def components(self, kinds=('dependency',)):
        # Iterative Kosaraju: safe for inventories deeper than Python's stack.
        adj, rev = defaultdict(list), defaultdict(list)
        for e in self.data['edges']:
            if e['kind'] in kinds:
                adj[e['source']].append(e['target'])
                rev[e['target']].append(e['source'])
        seen, order = set(), []
        for seed in sorted(self.nodes):
            if seed in seen:
                continue
            stack = [(seed, False)]
            while stack:
                n, done = stack.pop()
                if done:
                    order.append(n)
                elif n not in seen:
                    seen.add(n)
                    stack.append((n, True))
                    stack.extend((x, False) for x in adj[n] if x not in seen)
        seen, groups = set(), []
        for seed in reversed(order):
            if seed in seen:
                continue
            group, stack = [], [seed]
            seen.add(seed)
            while stack:
                n = stack.pop()
                group.append(n)
                for x in rev[n]:
                    if x not in seen:
                        seen.add(x)
                        stack.append(x)
            groups.append(sorted(group))
        return groups

    def order(self):
        groups = self.components()
        owner = {a: i for i, group in enumerate(groups) for a in group}
        deps = {i: set() for i in range(len(groups))}
        reverse = defaultdict(set)
        for e in self.data['edges']:
            a, b = owner[e['source']], owner[e['target']]
            if e['kind'] == 'dependency' and a != b:
                deps[a].add(b)
                reverse[b].add(a)
        queue = deque(sorted(i for i in deps if not deps[i]))
        result = []
        while queue:
            i = queue.popleft()
            result.append(groups[i])
            for dependent in sorted(reverse[i]):
                deps[dependent].discard(i)
                if not deps[dependent]:
                    queue.append(dependent)
        return result

    def path(self, start, targets, kinds=('call', 'dependency', 'virtual')):
        queue, previous = deque([start]), {start: None}
        while queue:
            n = queue.popleft()
            if n in targets:
                result = []
                while n is not None:
                    result.append(n)
                    n = previous[n]
                return result[::-1]
            for e in self.out[n]:
                if e['kind'] in kinds and e['target'] not in previous:
                    previous[e['target']] = n
                    queue.append(e['target'])
        return []

    def rank(self, milestone=None, count=20):
        from roc import ranking
        distances = {}
        queue = deque((a, 0) for a in self.data['milestones'].get(milestone, []))
        while queue:
            a, d = queue.popleft()
            if a in distances or d > 5:
                continue
            distances[a] = d
            queue.extend((e['target'], d+1) for e in self.out[a] if e['kind'] in ('call','dependency','virtual'))
        result = []
        for a, n in self.nodes.items():
            if n.get('kind', 'code') != 'code' or n.get('unresolved_inventory') or n.get('external') or n['states']['RUNTIME_VERIFIED'] or n['states']['LINKED'] or n.get('claimed'):
                continue
            unlocked = self.walk([a], len(self.nodes), True, ('dependency',), len(self.nodes))
            unlocks = sum(b != a and self.nodes[b].get('node_type', 'function') == 'function' for b in unlocked)
            module_impact = len({f for e in self.inc[a] if e['kind']=='dependency'
                                 for f in self.nodes[e['source']].get('owned_functions', [])
                                 if f in self.nodes and not self.nodes[f]['states'].get('LINKED')})
            mining_hint = ranking.rank_one(dict(addr=a, score=n.get('score'), size=n.get('size'),
                has_source=bool(n.get('source')), attempts=n.get('failed_attempts', 0)), profile_name='balanced')
            factors = dict(mining_readiness=round((mining_hint['rank']-500)/100, 3), module_impact=min(100, module_impact / 5), unlocks=unlocks * 20, milestone=max(0, 60-10*distances[a]) if a in distances else 0,
                           recovered=12 if n['states']['MINED'] else 0,
                           compiled=8 if n['states']['COMPILED'] else 0,
                           blockers=-5 * len(n.get('blockers', [])),
                           effort=-min(20, (n.get('size') or 512) / 256),
                           failed_attempts=-3 * n.get('failed_attempts', 0))
            result.append(dict(addr=a, name=n['name'], score=round(sum(factors.values()), 3),
                               reasons=factors, mining_hint=mining_hint['difficulty_reason'], unlocks=unlocks, module_affected_functions=module_impact, heuristic=True,
                               action='retrieve existing mined source (roc pull)' if n['states']['MINED'] and not n.get('source') and not n.get('library_source') else 'resolve module linker symbol' if n.get('node_type') == 'symbol' else 'inspect existing implementation' if n.get('native_paths') or n.get('library_source') else
                               'integrate recovered source' if n['states']['MINED'] else 'recover source',
                               claim='roc integrate next'+(' --unit '+n['unit'] if n.get('unit') and not n['unit'].startswith('seg_') else '')+' (server lease required)'))
        return sorted(result, key=lambda r: (-r['score'], r['addr']))[:count]

    def explain(self, a, milestone=None):
        a = a if a in self.nodes else address(a)
        return dict(node=self.nodes[a], callers=self.inc[a], callees=self.out[a],
                    dependencies=[b for b in self.walk([a], 5, kinds=('dependency',)) if b != a],
                    blocked_functions=[b for b in self.walk([a], 5, True, ('dependency',)) if b != a],
                    priority=next((r for r in self.rank(milestone, len(self.nodes)) if r['addr'] == a), None))


def build(client, root=ROOT):
    from roc.native_adapt import symbol_unit
    from roc.integration_site import readable
    from roc import libs, match
    root = Path(root)
    work, rebuild = root/'work'/client, root/'rebuild'/client
    inventory = work/'functions.jsonl'
    if not inventory.exists():
        raise RuntimeError('No function inventory; run roc analyze '+client)
    rows = [json.loads(line) for line in inventory.read_text().splitlines() if line.strip()]
    scores = read(work/'scores.json', {})
    manifests = {address(r['addr']): r for r in read(rebuild/'manifests/functions.json', [])}
    names = read(rebuild/'out/native-names.json', {})
    nodes, edges = {}, []
    library_roots = {}
    source_cache = read(work/'graph-sources.json', {})
    warnings = []
    def edge(a, b, kind, evidence, confidence='confirmed'):
        edges.append(dict(source=a, target=b, kind=kind, evidence=evidence, confidence=confidence))
    for row in rows:
        a = address(row['addr'])
        source = root/'src'/client/(a+'.cpp')
        stamp = [source.stat().st_mtime_ns, source.stat().st_size] if source.exists() else None
        cached = source_cache.get(a, {})
        if cached.get('stamp', False) != stamp:
            text = source.read_text(errors='replace') if stamp else ''
            cached = dict(stamp=stamp, present=bool(text), directives=match.directives(text) if text else {},
                definitions=re.findall(r'(?m)^[\w:<>,*& \t]+?\b([A-Za-z_]\w*(?:::[A-Za-z_]\w*)+)\s*\([^;{}]*\)\s*(?:const\s*)?\{', text))
            source_cache[a] = cached
        text = cached['present']
        directives = dict(cached['directives'])
        manifest = manifests.get(a, {})
        if not directives.get('lib') and manifest.get('recipe') and manifest.get('file'):
            directives['lib'] = manifest['recipe']+' '+manifest['file']
        score = scores.get(a, manifest.get('score'))
        symbol = names.get(a, {}).get('symbol')
        cls = symbol_unit(symbol) or row.get('class')
        definitions = cached['definitions']
        name = row.get('name') or (readable(symbol) if symbol else None) or (definitions[-1] if definitions else a)
        cls = cls or (definitions[-1].rsplit('::', 1)[0] if definitions else None)
        states = {s: False for s in ('UNMINED','PARTIAL','MINED','COMPILED','LINKED','RUNTIME_VERIFIED','BLOCKED')}
        states.update(UNMINED=not bool(text) and not bool(score), PARTIAL=(bool(text) or bool(score)) and score != 100, MINED=score == 100)
        library = None
        if directives.get('lib'):
            recipe, _, rel = directives['lib'].partition(' ')
            definition = libs.RECIPES.get(recipe, {})
            if definition.get('src') and rel.strip():
                if recipe not in library_roots:
                    library_roots[recipe] = libs._case_path(root/'tools/libs'/definition['src'])
                candidate = Path(os.path.normpath(library_roots[recipe]/rel.strip().replace('\\','/')))
                library = candidate.relative_to(root).as_posix() if candidate.is_relative_to(root) else None
        nodes[a] = dict(addr=a, client=client, name=name, owning_class=cls, symbol=symbol, kind=row.get('kind', 'code'),
                        node_type='inventory_data' if row.get('kind') in ('data','bad') else 'function',
                        size=row.get('size'), score=score, score_evidence='cached hint; not fresh verification',
                        source=source.relative_to(root).as_posix() if text else None, library_source=library,
                        source_available=bool(text),
                        integration_evidence_status='artifact snapshot; source freshness unverified',
                        name_confidence='source label; not original declaration' if definitions and not symbol else 'inventory / native symbol',
                        unit=row.get('unit'), accepted_native=None, runtime_verification=None, states=states, native_paths=[], ownership=[], blockers=[],
                        unknown_virtual=row.get('virtual_slots', []), evidence=['work/%s/functions.jsonl' % client])
        for target in row.get('call_targets', []):
            edge(a, address(target), 'call', 'work/%s/functions.jsonl:call_targets' % client)
        for external in sorted(set(row.get('external_calls', []))):
            edge(a, 'external:'+external, 'external', 'work/%s/functions.jsonl:external_calls' % client)
    dump(work/'graph-sources.json', source_cache)
    for e in edges:
        if e['target'] not in nodes:
            a = e['target']
            nodes[a] = dict(addr=a, client=client, name=a.removeprefix('external:'), external=a.startswith('external:'), unresolved_inventory=True,
                            states={}, size=None, score=None, source=None)
    abi = read(rebuild/'manifests/abi-evidence.json', {})
    for n in nodes.values():
        if n.get('unit') in abi:
            n['abi_evidence'] = dict(path='rebuild/%s/manifests/abi-evidence.json' % client, key=n['unit'])
    module_edges = []
    for report_path in sorted((rebuild/'out').glob('*/report.json')):
        report = read(report_path, {})
        owned = read(report_path.parent/'owned-symbols.json', {})
        if report.get('unresolved'):
            module_id = 'module:'+report_path.parent.name
            nodes[module_id] = dict(addr=module_id, client=client, name=report_path.parent.name,
                node_type='module', external=True, states={'BLOCKED':True},
                owned_functions=report.get('owned_addrs', []),
                evidence=[report_path.relative_to(root).as_posix()])
            for symbol in report['unresolved']:
                symbol_id = 'symbol:'+symbol
                if symbol_id not in nodes:
                    nodes[symbol_id] = dict(addr=symbol_id, client=client, name=symbol, node_type='symbol',
                        original_address=None, states={s:s == 'UNMINED' for s in
                        ('UNMINED','PARTIAL','MINED','COMPILED','LINKED','RUNTIME_VERIFIED','BLOCKED')},
                        blockers=[], source=None, size=None, score=None)
                module_edges.append((module_id, symbol_id, report_path.relative_to(root).as_posix()))
        for a in report.get('owned_addrs', []):
            if a not in nodes:
                continue
            n = nodes[a]
            n['states']['COMPILED'] = True
            n['states']['LINKED'] |= report.get('linked') is True
            n['ownership'].append(dict(module=report.get('module'), objects=owned.get(a, []),
                                       evidence=report_path.relative_to(root).as_posix()))
            if report.get('unresolved'):
                edge(a, module_id, 'ownership', report_path.relative_to(root).as_posix()+':owned_addrs (module scope)')
            n['module_blockers'] = sorted(set(n.get('module_blockers', []) + report.get('unresolved', [])))
            # A passing module smoke test does not verify every function's runtime behavior.
    for a, b, provenance in module_edges:
        edge(a, b, 'dependency', provenance+':unresolved (module scope)')
    for n in nodes.values():
        if n.get('module_blockers') and not n['states'].get('LINKED'):
            n['states']['BLOCKED'] = True
            n['blockers'] = ['Module link unresolved: '+s for s in n['module_blockers']]
    snapshot = read(root/'docs/integration.json', {})
    if snapshot.get('client') == client:
        linked = snapshot.get('native', [])
        native_sources = snapshot.get('sources', {})
        provenance = 'docs/integration.json:native'
    else:
        linked, native_sources, provenance = [], {}, None
    from roc import integration
    if client == integration.CLIENT:
        native_path = root/'work/integration/progress-native.json'
        if native_path.exists():
            linked = read(native_path, {}).get('addresses', [])
            provenance = 'work/integration/progress-native.json:addresses'
        native_sources.update(read(root/'local/findings'/client/'verification/native-source-links.json', {}))
    for a in linked:
        if a in nodes:
            n = nodes[a]
            n['states']['COMPILED'] = n['states']['LINKED'] = True
            n['states']['BLOCKED'] = False
            n['blockers'] = []
            n['accepted_native'] = dict(evidence=provenance, scope='server verified native baseline')
            n['native_source'] = native_sources.get(a)
            n['evidence'].append(provenance)
    for tu in read(rebuild/'manifests/tu-coverage.json', []):
        for a in tu.get('exact', []):
            if a in nodes:
                nodes[a]['native_paths'].append(tu.get('file'))
    # Optional reviewed evidence overlay: never infer build blockers from calls.
    evidence_path = rebuild/'manifests/graph-evidence.json'
    evidence = read(root/'research/graph'/(client+'.json'), {})
    local_evidence = read(evidence_path, {})
    evidence = dict(nodes={**evidence.get('nodes', {}), **local_evidence.get('nodes', {})},
                    edges=evidence.get('edges', [])+local_evidence.get('edges', []))
    for e in evidence.get('edges', []):
        if not e.get('evidence') or e['source'] not in nodes or e['target'] not in nodes:
            raise ValueError('Graph evidence requires existing IDs and provenance')
        edge(e['source'], e['target'], e['kind'], e['evidence'], e.get('confidence', 'inferred'))
    for a, facts in evidence.get('nodes', {}).items():
        if a not in nodes:
            warnings.append('stale evidence address '+a)
            continue
        if facts.get('label'):
            if not facts.get('evidence'):
                raise ValueError('Graph labels require provenance')
            nodes[a]['name'] = facts['label']
            nodes[a]['owning_class'] = facts.get('class') or facts['label'].rsplit('::', 1)[0]
            nodes[a]['name_confidence'] = facts.get('confidence', 'source-supported label')
            nodes[a]['evidence'].append(facts['evidence'])
        nodes[a]['blockers'] += facts.get('blockers', [])
        nodes[a]['states']['BLOCKED'] = bool(nodes[a]['blockers'])
        nodes[a]['failed_attempts'] = facts.get('failed_attempts', 0)
        for state, receipt in facts.get('verified_states', {}).items():
            if state in ('COMPILED','LINKED','RUNTIME_VERIFIED') and receipt:
                nodes[a]['states'][state] = True
                nodes[a]['evidence'].append(receipt)
    attempts = root/'work/agent-memory/attempts.jsonl'
    from roc import research
    for trial in research.journal_records(attempts):
        if trial.get('client') == client and trial.get('outcome') in ('no_gain','failed','rejected'):
            for a in trial.get('addresses', []):
                a = address(a)
                if a in nodes:
                    nodes[a]['failed_attempts'] = nodes[a].get('failed_attempts', 0) + 1
    for a, n in list(nodes.items()):
        cls = n.get('owning_class')
        if cls:
            class_id = 'class:'+cls
            if class_id not in nodes:
                nodes[class_id] = dict(addr=class_id, client=client, name=cls, node_type='class',
                    external=True, states={}, abi_evidence=dict(path='rebuild/%s/manifests/abi-evidence.json' % client, key=cls) if cls in abi else None)
            edge(a, class_id, 'class', ('rebuild/%s/out/native-names.json:%s' % (client,a) if n.get('symbol') else n.get('source') or n.get('evidence', ['unknown'])[-1])+':class label; not a build blocker', 'inferred')
    if manifests and any(m.get('score') != scores[a] for a, m in manifests.items() if a in scores):
        warnings.append('manifest scores differ from current mining cache; integration evidence kept separate')
    if not manifests:
        warnings.append('function manifest unavailable; inventory and cached scores only')
    edges.sort(key=lambda e: (e['source'], e['target'], e['kind'], str(e['evidence'])))
    return Graph(dict(version=VERSION, client=client, nodes=nodes, edges=edges, warnings=warnings,
                      milestones={'p2': [a for a in P2 if a in nodes]} if client == '2008-06' else {}))


def fingerprint(client, root=ROOT):
    root = Path(root)
    files = [root/'work'/client/'functions.jsonl', root/'work'/client/'scores.json']
    files += list((root/'src'/client).glob('*.cpp'))
    files += list((root/'rebuild'/client/'manifests').glob('*.json'))
    files += list((root/'rebuild'/client/'out').glob('*/report.json'))
    files += list((root/'rebuild'/client/'out').glob('*/owned-symbols.json'))
    files += [root/'docs/integration.json', root/'work/integration/progress-native.json', root/'local/findings'/client/'verification/native-source-links.json', root/'work/agent-memory/attempts.jsonl', root/'rebuild'/client/'out/native-names.json', root/'research/graph'/(client+'.json')]
    entries = []
    for p in sorted(set(files)):
        if p.exists():
            stat = p.stat()
            entries.append((p.relative_to(root).as_posix(), stat.st_size, stat.st_mtime_ns))
    return hashlib.sha256(json.dumps([VERSION, hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), entries]).encode()).hexdigest()


def load(client, root=ROOT, refresh=False):
    root = Path(root)
    signature = fingerprint(client, root)
    path = root/'work'/client/'graph.json'
    stamp = path.with_suffix('.stamp')
    if not refresh and path.exists() and stamp.exists() and stamp.read_text() == signature:
        return Graph(read(path, {}))
    graph = build(client, root)
    dump(path, graph.data)
    stamp.write_text(signature)
    return graph


def active_claims(graph, root=ROOT, api=None):
    # Existing local server-issued leases only; never export tokens or worker names.
    from roc import claims
    import time
    from roc import integration
    if api is not None and graph.data['client'] == integration.CLIENT:
        snapshot = api.call('/v1/integration?claims=1')
        occupied = {r['unit'] for r in snapshot.get('claims', []) if r['state'] == 'submitted' or r['state'] == 'claimed' and r['expires'] > time.time()}
        occupied.update(snapshot.get('parked_units', []))
        for unit in occupied:
            for a in snapshot.get('inventory', {}).get(unit, []):
                if a in graph.nodes:
                    graph.nodes[a]['claimed'] = True
    for packet in (Path(root)/'work/integration-client/claims').glob('*/packet.json'):
        row = read(packet, {})
        if row.get('client', '2008-06') == graph.data['client'] and row.get('expires', 0) > time.time():
            for a in row.get('addresses', []):
                if a in graph.nodes:
                    graph.nodes[a]['claimed'] = True
    if not claims.db_path(root).exists():
        return
    for row in claims.claims(graph.data['client'], root=root):
        if row['addr'] in graph.nodes:
            graph.nodes[row['addr']]['claimed'] = True


def export(graph, directory):
    directory = Path(directory)
    data = graph.data
    buckets = defaultdict(dict)
    def bucket(a):
        return a[:5] if re.fullmatch('[0-9a-f]{8}', a) else 'external'
    evidence = sorted({str(e['evidence']) for e in data['edges']})
    evidence_ids = {e: i for i, e in enumerate(evidence)}
    owners = {}
    for a, n in sorted(graph.nodes.items()):
        item = {k: v for k, v in n.items() if v not in (None, [], {}) and
                k not in ('addr','client','score_evidence','ownership')}
        if n.get('ownership'):
            item['ownership'] = []
            for o in n['ownership']:
                owners[o['module']] = o['evidence']
                item['ownership'].append(dict(module=o['module'], objects=o['objects']))
        buckets[bucket(a)][a] = item
    links = defaultdict(list)
    for e in data['edges']:
        compact = [e['source'], e['target'], e['kind'], evidence_ids[str(e['evidence'])], e['confidence']]
        for key in sorted({bucket(e['source']), bucket(e['target'])}):
            links[key].append(compact)
    for key, nodes in sorted(buckets.items()):
        dump(directory/(key+'.json.gz'), dict(nodes=nodes, edges=links[key]))
    dump(directory/'index.json.gz', dict(version=VERSION, client=data['client'], warnings=data['warnings'],
         evidence=evidence, ownership_evidence=owners,
         milestones=data['milestones'], recommendations=graph.rank('p2', 30),
         search=[[a, n['name'], n.get('owning_class')] for a,n in sorted(graph.nodes.items()) if not n.get('external') and not n.get('unresolved_inventory')],
         partitions=sorted(buckets)))


def command(args):
    client = args.client if args.target == 'build' else args.target
    if args.next < 0:
        raise RuntimeError('--next must be nonnegative')
    if not client:
        raise RuntimeError('Specify client: roc graph build 2008-06 --web')
    graph = load(client, refresh=args.target == 'build')
    if args.milestone and args.milestone not in graph.data['milestones']:
        raise RuntimeError('Unknown milestone '+args.milestone)
    if args.target == 'build':
        dump(ROOT/'work'/client/'graph.json', graph.data)
    if args.web:
        export(graph, ROOT/'docs/graph-data'/client)
        clients = sorted(p.parent.name for p in (ROOT/'docs/graph-data').glob('*/index.json.gz'))
        dump(ROOT/'docs/graph-data/clients.json', clients)
    if args.server:
        from roc import worker
        api = worker.Api(args.server, args.token or worker.load_settings().get('token'))
        try:
            active_claims(graph, api=api)
        finally:
            api.close()
    else:
        active_claims(graph)
    if args.cycles:
        result = [g for g in graph.components() if len(g) > 1 or any(e['target'] == g[0] and e['kind'] == 'dependency' for e in graph.out[g[0]])]
    elif args.order:
        result = graph.order()
    elif args.path:
        result = {a: graph.path(a, {args.path if args.path in graph.nodes else address(args.path)}) for a in graph.data['milestones'].get(args.milestone or 'p2', [])}
    elif args.why:
        result = graph.explain(args.why, args.milestone)
    elif args.focus:
        ids = graph.walk([args.focus if args.focus in graph.nodes else address(args.focus)], args.depth, args.upstream)
        result = dict(nodes={a:graph.nodes[a] for a in ids if a in graph.nodes},
                      edges=[e for e in graph.data['edges'] if e['source'] in ids and e['target'] in ids])
    else:
        result = dict(client=client, nodes=len(graph.nodes), functions=sum(not n.get('external') and not n.get('unresolved_inventory') and n.get('kind', 'code') == 'code' and n.get('node_type', 'function') == 'function' for n in graph.nodes.values()), edges=len(graph.data['edges']),
                      warnings=graph.data['warnings'], next=graph.rank(args.milestone, args.next))
    print(json.dumps(result, indent=None if args.json else 2))
