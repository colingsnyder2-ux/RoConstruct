"""Native-source recovery with free OpenCode models doing only the C++ rewrite.

Per target (a declared method of a class that already has a real native header and a native .cpp, whose
mined analog is server-exact):  the model rewrites the exact analog as a real member-function definition
against the real header -> native_convert_run.py compiles it with the class's own flags and runs the
existing byte + reference gates -> on a miss, the compile error or asm diff goes back to the model.
Nothing is written to native-classes/ without --apply, and then only through native_autorecover.py
(lease, draft upload, layout/vtable gates, destination-TU reproof).

  python work/native-client/native_llm.py --limit 8                 # prove only, writes work/ only
  python work/native-client/native_llm.py --limit 8 --apply         # also promote exact survivors
  python work/native-client/native_llm.py --owner-prefix Ogre:: --model opencode/glm-5.3-flash-free
"""
import argparse
import collections
import fnmatch
import json
import os
import re
import subprocess
import sys
import tempfile
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402

HERE = ROOT / 'work/native-client/native-llm'
QUEUE = ROOT / 'work/native-client/ogre-conversion-queue-v10.json'
CLOSURE = ROOT / 'work/native-client/claude-identity-closure.json'
LOG = HERE / 'attempts.jsonl'
REGISTRY = ROOT / 'work/native-client/ogre-names-registry.json'
METRICS = HERE / 'bytes-per-hour.jsonl'
PREFLIGHT = HERE / 'preflight-blocked.json'
LAYOUTS = ROOT / 'work/native-client/ogre-layout-solutions.json'
NATIVE_CENSUS = ROOT / 'work/native-client/ogre-native-full-census-current/manifest.json'
OPENCODE = Path(os.environ.get('APPDATA', '')) / 'ai.opencode.desktop/cli/2.2.6-x64/opencode-cli.exe'
# Escalation ladder, fastest first: attempt n uses LADDER[n % len]. "provider:model" goes through
# roc/providers.py (NVIDIA NIM API key, signed-in Codex CLI); "opencode*/..." through the OpenCode CLI.
# Owner's standing choice: strongest NVIDIA + OpenCode models are first-class here, not a backlog. Each
# target starts at a different rung (its index), so all providers' quotas work in parallel.
LADDER = ['codex:gpt-6-luna', 'nvidia:nvidia/nemotron-3-ultra-550b-a55b', 'opencode-go/kimi-k3.1-pro',
          'codex:gpt-6.1-terra', 'nvidia:nvidia/nemotron-3.5-super-vl-120b-a12b', 'opencode-go/deepseek-v4-pro',
          'opencode-go/qwen3.8-max', 'opencode-go/longcat-2.5-free']
EXHAUSTED = set()          # models that reported a spent quota this run
PREFLIGHT_BLOCKED = []
SOURCE_DESTINATIONS = None
SOURCE_LEAVES = None
NATIVE_EXACT = None

RULES = """You are rewriting one function from a matching decompilation into its real source form.
The REFERENCE ANALOG below compiles (MSVC 2008, same flags) to exactly the original machine code, but it
uses invented names, raw pointer offsets and placeholder types. Rewrite it as the real member function:

- Exact signature: {decl}
- Write it against the REAL HEADER: use only its members, types and methods. Map each raw offset
  `*(T*)((char*)this + N)` to the header field at that offset (headers mark offsets in comments).
- Keep the analog's statement order, expression shapes, temporaries, branches and loop forms: the
  compiler output must stay byte-identical. Do not "clean up" logic.
- No inline asm, no casts to raw offsets, no new fields, globals, includes or declarations.
- Output ONE ```cpp block containing only the definition, qualified as `{qual}(` (no namespace block).
"""


def lease_globs():
    out = subprocess.run([str(ROOT / 'roc.cmd'), 'lease', 'ls'], cwd=ROOT, capture_output=True, text=True).stdout
    return [g for line in out.splitlines() for g in line.split() if g.startswith('rebuild/')]


def flags_of(dest):
    if not dest:
        return ''
    m = re.search(r'^// native-flags:\s*(.*)$', (ROOT / dest).read_text(errors='replace'), re.M)
    return m.group(1).strip() if m else ''


def destination_for(owner):
    """One existing class TU when text proves it owns members; else one deterministic new class TU."""
    global SOURCE_DESTINATIONS, SOURCE_LEAVES
    classes = ROOT / 'rebuild/2008-06/native-classes'
    if SOURCE_DESTINATIONS is None:
        SOURCE_DESTINATIONS = collections.defaultdict(set)
        SOURCE_LEAVES = collections.defaultdict(set)
        pattern = re.compile(r'\b((?:[A-Za-z_]\w*::)+[A-Za-z_]\w*)::~?[A-Za-z_]\w*\s*\(')
        for path in classes.glob('*.cpp'):
            relative = path.relative_to(ROOT).as_posix()
            text = path.read_text(errors='replace')
            for found in pattern.findall(text):
                SOURCE_DESTINATIONS[found].add(relative)
            for leaf in re.findall(r'\b([A-Za-z_]\w*)::~?[A-Za-z_]\w*\s*\(', text):
                SOURCE_LEAVES[leaf].add(relative)
    hits = sorted(SOURCE_DESTINATIONS.get(owner, ()))
    if not hits:
        leaf = owner.rsplit('::', 1)[-1].lower()
        leaf_hits = sorted(SOURCE_LEAVES.get(owner.rsplit('::', 1)[-1], ()))
        if len(leaf_hits) == 1:
            hits = leaf_hits
        named = [path.relative_to(ROOT).as_posix() for path in classes.glob('*.cpp')
                 if path.stem.lower().endswith(leaf)]
        # Filename is a routing hint only; exact owner/body proof still gates promotion.
        if not hits and len(named) == 1:
            hits = named
    if len(hits) == 1:
        return hits[0], False
    if len(hits) > 1:
        return None, False
    stem = re.sub(r'[^A-Za-z0-9]+', '_', owner).strip('_')
    return 'rebuild/2008-06/native-classes/OgreAuto_%s.cpp' % stem, True


def native_exact_addresses():
    """Skip bodies already current-TU byte-proved; stale queue state is not work."""
    global NATIVE_EXACT
    if NATIVE_EXACT is None:
        NATIVE_EXACT = set()
        if NATIVE_CENSUS.is_file():
            manifest = json.loads(NATIVE_CENSUS.read_text())
            # Candidates include byte-only aliases.  ``addr`` exists only
            # after identity plus relocation/data reference proof.
            NATIVE_EXACT = {symbol['addr'] for family in manifest.get('families', [])
                            for symbol in family.get('symbols', [])
                            if symbol.get('status') == 'inactive_exact'
                            and isinstance(symbol.get('addr'), str)}
            NATIVE_EXACT = {address.lower() for address in NATIVE_EXACT}
    return NATIVE_EXACT


def header_include_flags(header, destination):
    """Known vendor roots required by real native headers, never guessed from analog text."""
    native_headers = ROOT / 'rebuild/2008-06/native-headers'
    paths = [ROOT / header]
    if destination:
        paths.append(ROOT / destination)
    seen, text = set(), ''
    while paths:
        path = paths.pop()
        if path in seen or not path.is_file():
            continue
        seen.add(path)
        unit = path.read_text(errors='replace')
        text += '\n' + unit
        for relative in re.findall(r'^\s*#include\s*"([^"/]+(?:/[^"/]+)*)"', unit, re.M):
            candidate = native_headers / relative
            if candidate.is_file():
                paths.append(candidate)
    flags = []
    ogre = ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include'
    if re.search(r'^\s*#include\s*[<\"]Ogre[A-Za-z0-9_]+\.h[>\"]', text, re.M) and ogre.is_dir():
        flags.append('/I' + str(ogre))
    return ' '.join(flags)


def unmapped_externs(packet, header, destination):
    """Analog globals cannot become native source without a real provider."""
    missing = []
    visible = header + '\n' + destination
    for declaration in re.findall(r'(?m)^\s*extern\b[^;]+;', packet):
        # Function imports are not variable providers.  The old token scan
        # misclassified return types such as `long` as globals.
        body = re.sub(r'^\s*extern\s+(?:"C"\s+)?', '', declaration).rstrip(';').strip()
        if '(' in body or re.match(r'^(?:class|struct|union|enum|typedef)\b', body):
            continue
        names = []
        for declarator in body.split(','):
            found = re.search(r'([A-Za-z_]\w*)\s*(?:\[[^]]*\])?\s*$', declarator.strip())
            if found:
                names.append(found.group(1))
        for name in names:
            if name not in visible:
                missing.append(name)
    return sorted(set(missing))


def targets(prefixes, max_size, tried, allow_new_source=False):
    """Queue rows an LLM can rewrite: one real header declaring it, a native .cpp for the class, a 100% analog."""
    global PREFLIGHT_BLOCKED
    PREFLIGHT_BLOCKED = []
    leased = lease_globs()
    classes = json.loads(QUEUE.read_text())['classes']
    registry = json.loads(REGISTRY.read_text()) if REGISTRY.is_file() else {}
    native_exact = native_exact_addresses()
    solved = ({row['owner'] for row in json.loads(LAYOUTS.read_text()).get('rows', []) if row.get('accepted')}
              if LAYOUTS.is_file() else set())
    # An address several symbols share is an ICF fold: one body, no unique identity to recover.
    shared = collections.Counter(m['addr'] for cl in classes for m in cl['methods'])
    out = []
    for cl in classes:
        if (cl['template'] or (prefixes and not cl['owner'].startswith(tuple(prefixes)))
                or cl['owner'].startswith(('G3D::', 'std::', 'boost::'))):     # library code: vendor lane, not native
            continue
        prov = collections.Counter(p for m in cl['methods'] if m['state'] == 'existing-native'
                                   for p in m['native_providers'])
        dest, is_new = destination_for(cl['owner'])
        if not dest:
            PREFLIGHT_BLOCKED.append({'owner': cl['owner'], 'reason': 'multiple-native-destinations'})
            continue
        if is_new and not allow_new_source:
            continue
        if cl['owner'].startswith('Ogre::Rbx') and cl['owner'] not in solved:
            PREFLIGHT_BLOCKED.append({'owner': cl['owner'], 'reason': 'layout-solver-not-accepted'})
            continue
        if dest and any(fnmatch.fnmatch(dest, g) for g in leased):
            continue
        for m in cl['methods']:
            identity = registry.get(m['addr'])
            if (m['addr'].lower() in native_exact or m['state'] != 'convert' or len(m['headers']) != 1 or '$' in m['symbol'] or m['addr'] in tried
                    or shared[m['addr']] > 1 or not identity or identity['placeholder']
                    or identity['name'] != m['symbol'] or identity.get('owner_class') != cl['owner']):
                continue
            analog = ROOT / 'src/2008-06' / (m['addr'] + '.cpp')
            packet = analog.read_text(errors='replace') if analog.is_file() else ''
            if not packet or '// from server: 100%' not in packet[:400]:
                continue
            qual = m['declaration'].split('(')[0].split()[-1]          # RBX::Camera::lookAt
            name = qual.rsplit('::', 1)[-1]
            text = Path(ROOT / m['headers'][0]).read_text(errors='replace')
            if name not in text or re.search(r'\b%s\s*\([^;{}]*\)[^;{}]*\{' % re.escape(name), text):
                continue                                   # undeclared, or the header already defines it inline
            leaf = cl['owner'].rsplit('::', 1)[-1]
            # A class-name token can be the class declaration, not a declared
            # ctor/copy-ctor.  Defining an implicit special member is illegal.
            if name in (leaf, '~' + leaf) and not re.search(r'\b~?%s\s*\(' % re.escape(leaf), text):
                PREFLIGHT_BLOCKED.append({'addr': m['addr'], 'owner': cl['owner'],
                                          'reason': 'special-member-not-declared', 'names': [name]})
                continue
            destination_text = (ROOT / dest).read_text(errors='replace') if dest and (ROOT / dest).is_file() else ''
            missing = unmapped_externs(packet, text, destination_text)
            if missing:
                PREFLIGHT_BLOCKED.append({'addr': m['addr'], 'owner': cl['owner'],
                                          'reason': 'unmapped-analog-extern', 'names': missing})
                continue
            size = len(match.target('2008-06', m['addr'])[0])
            if 16 <= size <= max_size:
                out.append(dict(addr=m['addr'], symbol=m['symbol'], decl=m['declaration'], owner=cl['owner'],
                                qual=qual, header=m['headers'][0], dest=dest, size=size,
                                name_source=identity['name_source'], placeholder=False,
                                new_source=is_new))
    # ponytail: smallest first, highest pass rate; add a byte-weighted order once rates are measured
    return sorted(out, key=lambda t: t['size'])


def ask(model, prompt, name):
    """-> the last ```cpp block of one model reply, or None."""
    if model.startswith('opencode'):
        text = ask_opencode(model, prompt)
    else:
        from roc import providers
        try:
            text = providers.generate(model, prompt, {'allow_cloud': True, 'timeout': 120, 'max_tokens': 4096}).text
        except providers.ProviderError as error:
            if providers.quota_exhausted(str(error)):
                EXHAUSTED.add(model)
            return None
    # Only a block that defines the target counts; models sometimes echo header excerpts as code.
    blocks = re.findall(r'```(?:cpp|c\+\+)?\s*\n(.*?)```', text or '', re.S) or [text or '']   # codex CLI strips fences
    code = [c for c in blocks if re.search(r'::\s*%s\s*\(' % re.escape(name), c)]
    return code[-1] if code else None


def ask_opencode(model, prompt):
    """One `opencode run` with the task as an attached file (no command-line length limit)."""
    with tempfile.TemporaryDirectory(prefix='roc-native-llm-') as folder:
        task = Path(folder) / 'task.txt'
        task.write_text(prompt, encoding='utf-8')
        run = subprocess.run([str(OPENCODE), 'run', '-m', model, '--format', 'json', '--file', str(task),
                              'Follow the attached task exactly. Return only the requested code. Do not use tools.'],
                             cwd=folder, capture_output=True, text=True, encoding='utf-8', errors='replace',
                             timeout=120)
    events = [e for e in map(_json, run.stdout.splitlines()) if isinstance(e, dict)]
    if any(e.get('type') == 'error' and re.search(r'provider\.\w+-limit', json.dumps(e.get('error')))
           for e in events):                                        # free-limit / go-limit: quota spent
        EXHAUSTED.add(model)
    return ''.join(e['part'].get('text', '') for e in events
                   if e.get('type') == 'text' and isinstance(e.get('part'), dict))


def _json(line):
    try:
        return json.loads(line)
    except ValueError:
        return None


def prove(t, body, out):
    """Write donor + one-row plan, run the existing isolated gates. -> (status, feedback text)."""
    ns, cls = t['owner'].rsplit('::', 1) if '::' in t['owner'] else ('', t['owner'])
    marker = t['qual'][len(ns) + 2:] if ns and t['qual'].startswith(ns + '::') else t['qual']
    body = body.replace(t['qual'] + '(', marker + '(')          # definition goes inside the namespace block
    # The donor's folder becomes an include dir; keep the gate's own output out of it, or the gate
    # sees the include search change mid-compile and voids an exact result as 'stale'.
    (out / 'donor').mkdir(parents=True, exist_ok=True)
    (out / 'donor' / 'donor.cpp').write_text(body + '\n')
    destination = (ROOT / t['dest']).read_text(errors='replace') if t['dest'] else ''
    support_includes = re.findall(r'^\s*#include\s*<((?:Ogre|G3D)[A-Za-z0-9_]+\.h)>', destination, re.M)
    header_root = ROOT / 'rebuild/2008-06/native-headers'
    for relative in re.findall(r'^\s*#include\s*"([^"]+)"', destination, re.M):
        native = (header_root / relative).resolve()
        if native.is_file() and native != (ROOT / t['header']).resolve():
            support_includes.append(str(native))
    flags = ' '.join(x for x in (flags_of(t['dest']), header_include_flags(t['header'], t['dest'])) if x)
    plan = {'plans': [{'owner': t['owner'], 'headers': [t['header']],
                       'source': str((out / 'donor' / 'donor.cpp').relative_to(ROOT)),
                       'namespace': ns, 'roc_cl': 21022, 'roc_flags': flags, 'destination': t['dest'],
                       'support_includes': support_includes,
                       'probe_records': ['%s=%s#0' % (t['addr'], marker)],
                       'rows': [{'addr': t['addr'], 'symbol': t['symbol'], 'marker': marker + '#0', 'header': t['header'],
                                 'namespace': ns, 'roc_cl': 21022, 'roc_flags': flags,
                                 'evidence': 'llm rewrite of server-exact analog; every gate rerun'}]}]}
    (out / 'plan.json').write_text(json.dumps(plan, indent=1))
    run = subprocess.run([sys.executable, str(ROOT / 'work/native-client/native_convert_run.py'), '--plan', str(out / 'plan.json'),
                          '--closure', str(CLOSURE), '--batch', '0', '--out', str(out / 'run'),
                          '--source-includes', '--add-flags', '/GS-'], cwd=ROOT, capture_output=True, text=True)
    try:
        res = json.loads((out / 'run' / 'result.json').read_text())
    except (OSError, ValueError):
        return 'tool-error', (run.stdout + run.stderr)[-1500:]
    status = res['requested'][0]['status']
    if status == 'compile_failed':
        return status, 'Compile error:\n' + str(res.get('first_compile_error', ''))[:1500]
    if status == 'inactive_exact':
        return status, ''
    objs = sorted(Path(res['manifest']).parent.rglob('*.obj'))
    diff = subprocess.run([str(ROOT / 'roc.cmd'), 'native-asm', '2008-06', t['addr'], '--obj', str(objs[0]),
                           '--sym', t['symbol'], '--context', '2', '--head', '80'],
                          cwd=ROOT, capture_output=True, text=True).stdout if objs else ''
    return status, 'Bytes differ (%s). Original vs your code, assembly diff:\n%s' % (status, diff[-3000:])


def folder(t):
    return HERE / ('%s-%s' % (t['addr'], re.sub(r'\W+', '_', t['qual'].rsplit('::', 1)[-1])[:40]))


def work(t, ladder, tries, start=0):
    analog = (ROOT / 'src/2008-06' / (t['addr'] + '.cpp')).read_text(errors='replace')
    directives = match.directives(analog)
    if 'lib' in directives:
        from roc import libs
        recipe, _, path = directives['lib'].partition(' ')
        expanded = libs.unit(recipe, path.strip(), 21022)
        # Recipe preprocessors can emit megabytes of dependency declarations.
        # Give the actual trailing analog body instead of an empty directive.
        analog += '\n// Expanded recipe trailing source excerpt (analog types are not native declarations):\n' + expanded[-32000:]
    header = (ROOT / t['header']).read_text(errors='replace')[:40000]
    asm = subprocess.run([str(ROOT / 'roc.cmd'), 'native-asm', '2008-06', t['addr']], cwd=ROOT,
                         capture_output=True, text=True).stdout[-6000:]
    prompt = (RULES.format(decl=t['decl'], qual=t['qual']) + '\n--- REAL HEADER %s ---\n%s\n--- REFERENCE ANALOG ---\n%s\n'
              '--- ORIGINAL ASSEMBLY (the target) ---\n%s\n' % (t['header'], header, analog, asm))
    status, history = 'no-reply', []
    # Re-gate an already generated answer before spending another provider call.
    # Driver/header flag changes are valid new evidence; model text is not resent unchanged.
    cached = sorted((folder(t)).glob('try*/donor/donor.cpp'))
    if cached:
        body = cached[-1].read_text(errors='replace')
        started = time.time()
        status, feedback = prove(t, body, folder(t) / 'recheck')
        row = dict(t, model='cache', attempt=-1, status=status, llm_seconds=0.0,
                   gate_seconds=round(time.time() - started, 1))
        with LOG.open('a') as log:
            log.write(json.dumps(row) + '\n')
        print('%s %-34s %4dB cache %-16s' % (t['addr'], t['qual'][-34:], t['size'], status), flush=True)
        if status == 'inactive_exact':
            return t, folder(t) / 'recheck'
        history = ['\n--- YOUR PREVIOUS ANSWER ---\n```cpp\n%s\n```\n--- RESULT ---\n%s\nFix it. Same output rules.\n'
                   % (body, feedback)]
    for n in range(tries):
        live = [m for m in ladder if m not in EXHAUSTED]
        if not live:
            break                                       # every quota spent: stop instead of burning attempts
        model = live[(start + n) % len(live)]           # each retry moves to the next provider's model
        started = time.time()
        try:
            body = ask(model, prompt + ''.join(history), t['qual'].rsplit('::', 1)[-1])
        except subprocess.TimeoutExpired:
            body = None
        llm = time.time() - started
        if not body:
            status, feedback = 'no-reply', ''
        else:
            status, feedback = prove(t, body, folder(t) / ('try%d' % n))
        row = dict(t, model=model, attempt=n, status=status, llm_seconds=round(llm, 1),
                   gate_seconds=round(time.time() - started - llm, 1))
        with LOG.open('a') as log:
            log.write(json.dumps(row) + '\n')
        print('%s %-34s %4dB try%d %-16s %-28s llm %5.1fs gate %5.1fs' % (t['addr'], t['qual'][-34:], t['size'], n,
              status, model.split('/')[-1][:28], row['llm_seconds'], row['gate_seconds']), flush=True)
        if status == 'inactive_exact':
            return t, folder(t) / ('try%d' % n)
        if body:
            history = ['\n--- YOUR PREVIOUS ANSWER ---\n```cpp\n%s\n```\n--- RESULT ---\n%s\nFix it. Same output rules.\n'
                       % (body, feedback)]
    return t, None


def main():
    global QUEUE, CLOSURE
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--limit', type=int, default=8)
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--tries', type=int, default=len(LADDER))
    ap.add_argument('--max-size', type=int, default=512)
    ap.add_argument('--models', default=','.join(LADDER), help='comma ladder, fastest first')
    ap.add_argument('--owner-prefix', action='append', default=[])
    ap.add_argument('--queue', type=Path, default=QUEUE, help='identity-backed conversion queue')
    ap.add_argument('--closure', type=Path, default=CLOSURE, help='matching identity evidence for native gates')
    ap.add_argument('--apply', action='store_true', help='promote exact survivors via native_autorecover (lease+draft+gates)')
    ap.add_argument('--new-source', action='store_true',
                    help='probe real-header methods with no native .cpp; never promotes them')
    ap.add_argument('--retry-address', action='append', default=[], metavar='ADDR',
                    help='recheck cached donor only for this address after a driver/input repair')
    args = ap.parse_args()
    QUEUE, CLOSURE = args.queue.resolve(), args.closure.resolve()
    HERE.mkdir(parents=True, exist_ok=True)
    started = time.time()
    prior_log = LOG.read_text().count('\n') if LOG.is_file() else 0
    tried = {json.loads(l)['addr'] for l in LOG.open()} if LOG.is_file() else set()
    for address in args.retry_address:
        tried.discard(address.lower())
    todo = targets(args.owner_prefix, args.max_size, tried, args.new_source)[:args.limit]
    if args.retry_address:
        wanted = {address.lower() for address in args.retry_address}
        todo = [target for target in todo if target['addr'].lower() in wanted]
    PREFLIGHT.write_text(json.dumps(PREFLIGHT_BLOCKED, indent=1) + '\n')
    print('%d targets (%d B)' % (len(todo), sum(t['size'] for t in todo)), flush=True)
    with ThreadPoolExecutor(args.jobs) as pool:
        done = list(pool.map(lambda it: work(it[1], args.models.split(','), args.tries, it[0]), enumerate(todo)))
    exact = [(t, d) for t, d in done if d]
    print('exact %d/%d (%d B)' % (len(exact), len(done), sum(t['size'] for t, _ in exact)), flush=True)
    attempts = [json.loads(line) for line in LOG.read_text().splitlines()[prior_log:]] if LOG.is_file() else []
    failures = collections.Counter(row['status'] for row in attempts if row['status'] != 'inactive_exact')
    calls = collections.Counter(row['model'] for row in attempts)
    exact_bytes = sum(t['size'] for t, _ in exact)
    wall = max(time.time() - started, .001)
    metric = dict(wall_seconds=round(wall, 2), calls_per_provider=calls, exact_targets=len(exact),
                  exact_bytes=exact_bytes, exact_bytes_per_hour=round(exact_bytes * 3600 / wall, 2),
                  exact_bytes_per_call=round(exact_bytes / max(1, len(attempts)), 2),
                  real_name_bytes=exact_bytes, placeholder_bytes=0,
                  top_failure_causes=failures.most_common(5))
    with METRICS.open('a') as stream:
        stream.write(json.dumps(metric, sort_keys=True) + '\n')
    for t, d in exact if args.apply else []:
        # Serial: one destination edit at a time; the runner leases, drafts, re-proves the whole TU.
        run = subprocess.run([sys.executable, str(ROOT / 'work/native-client/native_autorecover.py'), '--plan-file',
                              str(d / 'plan.json'), '--out', str(d / 'apply'), '--apply'],
                             cwd=ROOT, capture_output=True, text=True)
        print(t['addr'], 'apply:', (run.stdout.strip().splitlines() or [run.stderr[-300:]])[-1], flush=True)


if __name__ == '__main__':
    main()
