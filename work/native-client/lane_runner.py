"""One entry point for the automatic native lanes (dashboard job kind `native_lane`).
  python work/native-client/lane_runner.py LANE [--jobs N]
LANE:
  failures  re-queue every remaining compile failure (placeholder + named) and run the lane with header-add enabled
  regate    re-check saved placeholder answers against the current headers (no model calls)
  vendor    preprocessed-unit vendor wrappers (vendor_i.py) -> prove -> learn reference identities -> re-prove
  layout    class-layout lane (native_class_lane.py): one class's failing functions + a header fix per run
  promote   promote proven header-add lines (with before/after prove), then the functions, then prove the new TUs
  census    full census (prove.py --all) + publish the site (drop guard applies)
  classify  refresh remaining-classified.json and print the buckets
Every step prints progress lines; the dashboard streams them."""
import argparse
import os
import shutil
import re
import glob
import json
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
PY = sys.executable
ap = argparse.ArgumentParser()
ap.add_argument('lane', choices=['failures', 'regate', 'vendor', 'layout', 'promote', 'census', 'classify', 'flags', 'auto', 'agent', 'donor', 'pattern', 'polish', 'gateserver', 'inferred', 'names', 'templates', 'untried', 'agents'])
ap.add_argument('--jobs', type=int, default=8)
ap.add_argument('--model', default='sonnet', help='agents lane: sonnet or haiku')
args = ap.parse_args()


def run(cmd, cwd=ROOT, tail=8):
    print('$ ' + ' '.join(map(str, cmd)), flush=True)
    started = time.time()
    proc = subprocess.Popen(list(map(str, cmd)), cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
                            encoding='utf-8', errors='replace')
    lines = []
    for line in proc.stdout:
        lines.append(line.rstrip())
        if len(line) < 300:
            print('  ' + line.rstrip(), flush=True)
    proc.wait()
    print('  (exit %s, %ds)' % (proc.returncode, time.time() - started), flush=True)
    return proc.returncode, lines


def inputs_changed():
    """True when a census input (native sources/headers, binding/evidence JSON) is newer than the last census manifest."""
    manifest = HERE / 'prove-out/OgreNativeFull/manifest.json'
    if not manifest.is_file():
        return True
    last = manifest.stat().st_mtime
    roots = [ROOT / 'rebuild/2008-06/native-classes', ROOT / 'rebuild/2008-06/native-headers']
    for root in roots:
        for p in root.rglob('*'):
            if p.suffix in ('.cpp', '.h', '.hpp') and p.stat().st_mtime > last:
                return True
    return any(p.stat().st_mtime > last for p in HERE.glob('*bindings*.json'))


def census_running():
    return (HERE / 'prove-out/CENSUS.lock').is_file()


def results():
    sys.path.insert(0, str(HERE))
    import results_store
    return results_store.load()


def counts(addrs=None):
    r = results()
    rows = [v for a, v in r.items() if addrs is None or a in addrs]
    out = {}
    for v in rows:
        out[v['status']] = out.get(v['status'], 0) + 1
    return out


def ensure_gate_server():
    # Resident native-bulk workers (gate_server.py): every gate in this lane skips process start + target index load.
    import urllib.request
    try:
        urllib.request.urlopen('http://127.0.0.1:8799/', timeout=2).read()
        return
    except OSError:
        pass
    subprocess.Popen([PY, str(HERE / 'gate_server.py'), '--jobs', str(max(4, args.jobs))], cwd=ROOT,
                     stdout=open(HERE / 'gate-server.log', 'a'), stderr=subprocess.STDOUT,
                     creationflags=getattr(subprocess, 'CREATE_NEW_PROCESS_GROUP', 0) | getattr(subprocess, 'DETACHED_PROCESS', 0))
    print('started gate server (port 8799)', flush=True)


if args.lane not in ('census', 'classify', 'agent', 'auto'):
    ensure_gate_server()

if args.lane in ('failures', 'regate', 'promote', 'vendor', 'layout', 'polish', 'inferred', 'names', 'templates', 'untried') and census_running():
    sys.exit('a census is running (prove-out/CENSUS.lock): try again when it finishes')

if args.lane == 'failures':
    cl = json.loads((HERE / 'remaining-classified.json').read_text())
    named = set()
    for f in glob.glob(str(HERE / 'creator-partition/named-*.json')):
        if 'all-fail' in f or 'hdradd' in f:
            continue
        try:
            named |= set(json.loads(Path(f).read_text()))
        except (ValueError, OSError):
            pass
    r = results()
    # Token budget: no-class-header needs class recovery (agent/subagent), and a target with 3+ lane runs waits for a
    # header change instead of burning more model calls.
    fail = [a for a, v in r.items() if v['status'] in ('compile_failed', 'rejected-header-add') and a in cl
            and v.get('runs', 1) < 3]
    # Marked 'requeue' (not deleted) so the run count survives: the 3-run budget used to reset every cycle.
    import results_store
    results_store.save({a: dict(r[a], status='requeue') for a in fail})
    nm = [a for a in fail if a in named]
    (HERE / 'creator-partition/named-all-fail.json').write_text(json.dumps(nm))
    print('re-queued %d compile failures (%d named) for the header-add lane' % (len(fail), len(nm)), flush=True)
    run([PY, 'native_placeholder_llm.py', '--jobs', args.jobs], cwd=HERE)
    run([PY, 'native_placeholder_llm.py', '--named', 'creator-partition/named-all-fail.json', '--jobs', args.jobs], cwd=HERE)
    done = set(fail)
    r = results()
    print('RESULT %s; exact using header-add: %d' % (counts(done), sum(1 for a in done if r.get(a, {}).get('header_add')
                                                                     and r[a]['status'] == 'inactive_exact')), flush=True)

elif args.lane == 'regate':
    run([PY, 'native_placeholder_llm.py', '--regate', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'vendor':
    run([PY, 'vendor_i.py'], cwd=HERE)
    files = json.loads((HERE / 'creator-partition/vendor-i-wrappers.json').read_text())['written']
    if not files:
        sys.exit('no vendor wrappers written')
    family = 'prove-' + Path(files[0]).stem
    run([PY, 'work/native-client/prove.py', *files, '--rounds', '1', '--no-register'])
    run([PY, 'work/native-client/creator-partition/learn_refs.py', family, 'work/native-client/vendor-identity-bindings.json'])
    run([PY, 'work/native-client/prove.py', *files, '--rounds', '2', '--no-register'])
    units = json.loads((HERE / 'creator-partition/vendor-units.json').read_text())
    targets = {a for v in units.values() for a in v}
    manifest = json.loads((HERE / 'prove-out' / family / 'manifest.json').read_text())
    exact = {c['addr'] for f in manifest['families'] for j in f.get('jobs', []) for c in j.get('checks', [])}
    print('RESULT vendor targets exact: %d of %d' % (len(targets & exact), len(targets)), flush=True)

elif args.lane == 'layout':
    run([PY, 'native_class_lane.py', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'promote':
    # No-model lane exacts (flag sweep, donor transplant, pattern lane) live in their own hits files: merge them.
    import results_store
    for name in ('flag-sweep-hits.json', 'donor-transplant-hits.json', 'pattern-lane-hits.json'):
        hits_path = HERE / name
        if not hits_path.is_file():
            continue
        r = results()
        hits = json.loads(hits_path.read_text())
        for addr, hit in hits.items():
            row = r.setdefault(addr, {'model': hit.get('model', name.split('-hits')[0])})
            row.update(status='inactive_exact', **({'flags': hit['flags']} if hit.get('flags') else {}),
                       **({'class': hit['cls'], 'decl': hit['decl']} if hit.get('cls') else {}))
        results_store.save({a: r[a] for a in hits})
        print('merged %d exacts from %s' % (len(hits), name), flush=True)
    run([PY, 'promote_header_adds.py'], cwd=HERE)
    run([PY, 'native_placeholder_promote.py'], cwd=HERE)
    _, status = run(['git', 'status', '--short', 'rebuild/2008-06/native-classes'])
    new = [l.split()[-1] for l in status if l.startswith('??') and 'Inferred_' in l]
    if new:
        run([PY, 'work/native-client/prove.py', *new, '--rounds', '2', '--quiet'])
    print('RESULT promoted; %d new Inferred TUs proved' % len(new), flush=True)

elif args.lane == 'census':
    if census_running():
        sys.exit('a census is already running')
    # Register what the lanes and subagents produced: evidence files and new native sources.
    run([PY, 'lane_identity.py'], cwd=HERE)            # identity rows for lane-proven files (before the lock)
    run([PY, 'ehbind.py', 'OgreNativeFull', 'eh-identity-bindings.json'], cwd=HERE)   # __ehhandler$ from prologue push
    run([PY, 'ref_alias.py'], cwd=HERE)                # census rejections' original reference addresses
    run([PY, 'unique_identity.py'], cwd=HERE)          # INFERRED tier: symmetric unique byte-equal bodies (>=24 B)
    inv_path = HERE / 'ogre-native-full-inventory-all.json'
    inv = json.loads(inv_path.read_text())
    fam = inv['families'][0]
    for ev in ['class-identity-bindings.json', 'template-identity-bindings.json', 'template-identity-bindings-round3.json',
               'template-identity-bindings-netser.json', 'template-identity-bindings-signal.json', 'vendor-identity-bindings.json',
               'inferred-identity-bindings.json', 'identity-session-bindings.json', 'creator-reference-bindings.json',
               'creator-identity-bindings.json', 'vtable-identity-bindings.json', 'lane-identity-bindings.json', 'order-identity-bindings.json',
               'eh-identity-bindings.json', 'unique-identity-bindings.json',
               'ref-alias-bindings.json', 'template-identity-bindings-round4.json']:
        rel = 'work/native-client/' + ev
        if (HERE / ev).is_file() and rel not in fam['evidence']:
            fam['evidence'].append(rel)
    new_src = HERE / 'class-lane-new-sources.json'
    extra = json.loads(new_src.read_text()) if new_src.is_file() else []
    extra += json.loads((HERE / 'creator-partition/vendor-i-wrappers.json').read_text()).get('written', [])         if (HERE / 'creator-partition/vendor-i-wrappers.json').is_file() else []
    for src in extra:
        if (ROOT / src).is_file() and src not in fam['sources']:
            fam['sources'].append(src)
    inv_path.write_text(json.dumps(inv, indent=1))
    print('registered evidence and %d candidate sources' % len(extra), flush=True)
    run([PY, 'work/native-client/prove.py', '--all', '--rounds', '2', '--quiet'])
    run([PY, '-c', 'from roc import integration_site, server; import shutil; '
                   'r = integration_site.build(); print({k: v["functions"] for k, v in r["groups"].items()}); '
                   'server.publish_pages(shutil.which("git"))'])

elif args.lane == 'inferred':
    # Functions whose registry name comes from the identity-unlock tier (sole-authentic-candidate, one-of-N) were never
    # queued: placeholder_targets() takes only 'placeholder' rows.  Named lane, most certain names first, then smallest.
    cl = json.loads((HERE / 'remaining-classified.json').read_text())
    inf = json.loads((HERE / 'unnamed-identities-inferred.json').read_text())
    rank = {'sole-authentic-candidate': 0, 'one-of-2-authentic': 1, 'one-of-3-authentic': 2, 'one-of-4-authentic': 3}
    r = results()
    queue = sorted((a for a, v in cl.items() if v['bucket'] == 'inferred name only' and 8 <= v['size'] <= 2048
                    and r.get(a, {}).get('status') in (None, 'requeue')),
                   key=lambda a: (rank.get((inf.get(a) or {}).get('confidence'), 9), cl[a]['size']))
    (HERE / 'creator-partition/named-inferred.json').write_text(json.dumps(queue))
    print('inferred-name functions queued: %d' % len(queue), flush=True)
    run([PY, 'native_placeholder_llm.py', '--named', 'creator-partition/named-inferred.json', '--jobs', args.jobs], cwd=HERE)
    r = results()
    print('RESULT %s' % counts(set(queue)), flush=True)

elif args.lane == 'agents':
    # N headless Claude Code (Sonnet) class-recovery sessions in parallel, one class each, from the generated queue
    # (build_agent_queue.py: remaining functions by owner class).  Same rules as the session's class agents.
    import concurrent.futures
    run([PY, 'header_gaps.py', '--top', '0'], cwd=HERE)
    run([PY, 'build_agent_queue.py'], cwd=HERE)
    queue = json.loads((HERE / 'agent-class-queue.json').read_text())
    done_path = HERE / 'agent-class-done.json'
    done = json.loads(done_path.read_text()) if done_path.is_file() else []
    batch = queue[:max(1, args.jobs)]
    done += [t['class'] for t in batch]
    done_path.write_text(json.dumps(done, indent=1))
    rules = (HERE / 'agent-brief.md').read_text()
    # CLI 2.x patterns use a space ("Bash(python *)"); headless sessions on Windows run PowerShell, so both tools.
    tools = ['Read', 'Edit', 'Write', 'Grep', 'Glob'] + [
        '%s(%s *)' % (shell, cmd) for shell in ('Bash', 'PowerShell')
        for cmd in ('python', 'git add', 'git commit', 'git status', 'git diff', 'git log', 'ls', 'cat', 'head', 'Get-Content',
                    'Select-String', 'Test-Path')] + ['PowerShell(.\roc.cmd *)', 'Bash(./roc.cmd *)']

    # Owner 2026-11-17: unattended sessions run with permission checks off, minus a deny list; spend is capped.
    deny = ['%s(%s*)' % (shell, cmd) for shell in ('Bash', 'PowerShell')
            for cmd in ('git push', 'git reset', 'git checkout', 'git clean', 'git rebase', 'git branch -D', 'git stash',
                        'git filter', 'git worktree', 'rm -rf', 'rm -r', 'Remove-Item', 'del ', 'rmdir', 'curl', 'wget',
                        'Invoke-WebRequest', 'Invoke-RestMethod', 'python roc.py submit', 'roc.cmd submit', 'npm', 'pip')]
    deny += ['WebFetch', 'WebSearch']
    claude = shutil.which('claude') or 'claude'

    def asm_for(addrs):
        """Target assembly up front (saves the session's own native-asm round trips, the bulk of its tokens)."""
        out = subprocess.run([PY, str(ROOT / 'roc.py'), 'native-asm', '2008-06', *addrs[:12]], cwd=ROOT,
                             capture_output=True, text=True, encoding='utf-8', errors='replace').stdout
        blocks, cur = [], []
        for line in out.splitlines():
            if line.startswith('== ') and cur:
                blocks.append(cur)
                cur = []
            cur.append(line)
        blocks.append(cur)
        return '\n'.join('\n'.join(b[:70] + (['... (%d more lines)' % (len(b) - 70)] if len(b) > 70 else [])) for b in blocks)

    def evidence(task):
        """Header, donor sources and last model attempts in the prompt: the transcript audit showed sessions spending
        most turns (each re-reading the whole growing context) on cat/grep/sed of exactly these files."""
        parts = []
        if task.get('header') and (ROOT / task['header']).is_file():
            parts.append('--- declaring header %s (first 8 KB) ---\n%s'
                         % (task['header'], (ROOT / task['header']).read_text(errors='replace')[:8000]))
        for a in task['addresses'][:6]:
            donor = ROOT / 'src/2008-06' / (a + '.cpp')
            if donor.is_file():
                parts.append('--- donor analog %s (first 2.5 KB) ---\n%s' % (a, donor.read_text(errors='replace')[:2500]))
            tries = sorted((HERE / 'placeholder-lane' / a).glob('try*.cpp'))
            if tries:
                parts.append('--- last model attempt %s (first 1.5 KB; it did not match) ---\n%s'
                             % (a, tries[-1].read_text(errors='replace')[:1500]))
        gaps_path = HERE / 'header-gaps.json'
        if gaps_path.is_file():               # members the model lane found missing for this class (header_gaps.py)
            leaf = task['class'].split(' + ')[0].split('::')[-1]
            gaps = [g for g in json.loads(gaps_path.read_text()).get('members', [])
                    if g['class'].split('::')[-1] == leaf][:15]
            if gaps:
                parts.append('--- members earlier compiles found missing (verify against the asm before adding) ---\n' +
                             '\n'.join('%s::%s (blocks %s)' % (g['class'], g['member'], ' '.join(g['functions'][:4]))
                                       for g in gaps))
        return '\n'.join(parts)

    EMPTY_MCP = HERE / 'agent-empty-mcp.json'
    EMPTY_MCP.write_text('{"mcpServers": {}}')

    STALL_TOOLS = 18                # tool calls without any Write/Edit -> the session is only reading: stop it

    def one(task):
        # Shared rules FIRST, task-specific text LAST: parallel sessions then share one cached prompt prefix.
        brief = ('%s\n\n=== TASK ===\nClass recovery task for %s. Remaining addresses: %s. Declaring header: %s.\n\n'
                 'Target assembly (first 12 addresses, up to 70 lines each; fetch the rest with python roc.py native-asm):\n%s\n\n'
                 'Evidence already loaded below - do not re-read these files:\n%s\n'
                 % (rules, task['class'], ' '.join(task['addresses']), task.get('header') or 'none found',
                    asm_for(task['addresses']), evidence(task)))
        log = HERE / 'agent-logs' / ('%s-%s.log' % (args.model, re.sub(r'\W+', '_', task['class'])))
        log.parent.mkdir(exist_ok=True)
        cmd = [claude, '-p', '--model', args.model, '--effort', 'medium',
               '--max-budget-usd', '3' if args.model == 'haiku' else '6',
               '--permission-mode', 'bypassPermissions',
               # lean context: no MCP tools, no skills list, no user-level plugins/hooks (~80% cheaper start)
               '--strict-mcp-config', '--mcp-config', str(EMPTY_MCP), '--disable-slash-commands',
               '--exclude-dynamic-system-prompt-sections', '--setting-sources', 'project',
               '--output-format', 'stream-json', '--verbose', '--disallowedTools', *deny]
        started, tools, writes, result, note = time.time(), 0, 0, '', ''
        proc = subprocess.Popen(cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
                                encoding='utf-8', errors='replace', cwd=ROOT)
        proc.stdin.write(brief)
        proc.stdin.close()
        for line in proc.stdout:
            try:
                ev = json.loads(line)
            except ValueError:
                continue
            for c in ((ev.get('message') or {}).get('content') or []) if isinstance((ev.get('message') or {}).get('content'), list) else []:
                if c.get('type') == 'tool_use':
                    tools += 1
                    if c.get('name') in ('Write', 'Edit', 'MultiEdit', 'NotebookEdit'):
                        writes += 1
            if ev.get('type') == 'result':
                result = ev.get('result') or ''
                note = 'cost $%.2f, %s turns' % (ev.get('total_cost_usd') or 0, ev.get('num_turns'))
            if (tools >= STALL_TOOLS and not writes) or time.time() - started > 90 * 60:
                note = 'stopped: %s' % ('%d tool calls without writing a file' % tools if not writes else '90 min')
                proc.kill()
                break
        proc.wait()
        log.write_text('%s\n[agents lane] %d tool calls, %d writes; %s\n' % (result, tools, writes, note), encoding='utf-8')
        return task['class'], log.read_text(encoding='utf-8', errors='replace')[-600:]
    print('agents: %s' % ', '.join(t['class'] for t in batch), flush=True)
    with concurrent.futures.ThreadPoolExecutor(len(batch)) as pool:
        for cls, tail in pool.map(one, batch):
            print('=== %s ===\n%s' % (cls, tail), flush=True)
    print('RESULT agents finished: %d classes' % len(batch), flush=True)

elif args.lane == 'untried':
    # Every remaining named function the model lane never saw (any bucket but vendor-library, 8..2048 B), smallest first.
    sys.path.insert(0, str(HERE))
    sys.argv = sys.argv[:1]
    import native_llm as m
    reg = m.load_registry()
    cl = json.loads((HERE / 'remaining-classified.json').read_text())
    r = results()
    queue = sorted((a for a, v in cl.items() if v['bucket'] != 'vendor-library' and 8 <= v['size'] <= 2048
                    and r.get(a, {}).get('status') in (None, 'requeue')
                    and (reg.get(a) or {}).get('name') and not reg[a]['name'].startswith(('func_', 'sub_', '?sub_'))
                    and reg[a].get('signature')), key=lambda a: cl[a]['size'])
    (HERE / 'creator-partition/named-untried.json').write_text(json.dumps(queue))
    print('untried named functions queued: %d' % len(queue), flush=True)
    run([PY, 'native_placeholder_llm.py', '--named', 'creator-partition/named-untried.json', '--jobs', args.jobs], cwd=HERE)
    print('RESULT %s' % counts(set(queue)), flush=True)

elif args.lane == 'templates':
    # Explicit template instantiations (Creatable::create<X>, FactoryProduct Creator::create, boost::any_cast), no model.
    run([PY, 'creator_classes.py'], cwd=HERE)
    run([PY, 'template_instances.py', '--jobs', args.jobs], cwd=HERE)
    run([PY, 'template_instances.py', '--creators', '--jobs', args.jobs], cwd=HERE)
    run([PY, 'create_classes.py'], cwd=HERE)
    run([PY, 'template_instances.py', '--create', '--jobs', args.jobs], cwd=HERE)
    run([PY, 'vtable_disambiguate.py'], cwd=HERE)
    run([PY, 'order_identity.py'], cwd=HERE)              # identical-body runs bound by registry name + address order        # byte-equal ledger candidates picked by vtable/caller class

elif args.lane == 'names':
    # Name::callDoDeclare<sX> forwarders: explicit instantiations in the TU defining sX, proven by bytes, jump target
    # and sX data identity (native_name_declare_probe.py); applied with lease + re-prove + restore on any lost exact.
    run([PY, 'native_name_declare_probe.py', '--apply'], cwd=HERE)

elif args.lane == 'polish':
    run([PY, 'native_placeholder_llm.py', '--polish', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'gateserver':
    print('gate server is up on 127.0.0.1:8799', flush=True)

elif args.lane == 'donor':
    run([PY, 'donor_transplant.py', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'pattern':
    run([PY, 'pattern_lane.py', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'flags':
    run([PY, 'flag_sweep.py', '--jobs', args.jobs], cwd=HERE)

elif args.lane == 'auto':
    # Unattended cycle: regate -> header-add failures -> class layout -> flag sweep -> promote -> census + publish,
    # repeated; each cycle counts its gains on the site (census takes minutes since the parallel/per-file cache work).
    for cycle in range(1, 100):
        print('=== auto cycle %d ===' % cycle, flush=True)
        for lane in ('regate', 'names', 'templates', 'donor', 'inferred', 'untried', 'agents', 'polish', 'layout', 'promote', 'census'):   # failures: 3.8% yield, manual only   # flags: 0 of 29 drafts, slow - manual only
            if lane == 'census' and not inputs_changed():
                print('census skipped: no native source or evidence changed since the last census', flush=True)
                continue
            run([PY, str(HERE / 'lane_runner.py'), lane, '--jobs', 4 if lane == 'agents' else args.jobs])
        if (HERE / 'native-llm' / 'STOP').is_file():
            print('STOP file present: ending auto cycles', flush=True)
            break

elif args.lane == 'agent':
    # One headless Claude Code (Sonnet) class-recovery task per run, from work/native-client/agent-class-queue.json
    # (list of {"class": ..., "brief": ...}); same constrained brief as the class subagents; tool allowlist only.
    queue_path = HERE / 'agent-class-queue.json'
    queue = json.loads(queue_path.read_text()) if queue_path.is_file() else []
    if not queue:
        sys.exit('agent-class-queue.json is empty')
    task = queue.pop(0)
    queue_path.write_text(json.dumps(queue, indent=1))
    brief = (task.get('brief') or '') + '''

Rules (from CLAUDE.md): real native headers and member names, `// INFERRED: <evidence>` on inferred members, no padding
arrays, no (char*)this+offset access, no invented globals, no __emit/asm. Lease files with `roc.cmd lease take`. Prove
with `python work/native-client/prove.py <file> --rounds 1 --no-register` (never --all). Never edit roc/native_bulk.py,
roc/match.py, roc/rebuild.py, rebuild/2008-06/tests/native_check_runner.py, the core headers v8tree/Instance.h,
v8datamodel/DataModel.h, util/Events.h, reflection/*.h, or ogre-native-full-inventory-all.json. Append addr->symbol pairs
of exact functions to work/native-client/class-identity-bindings.json and new .cpp paths to
work/native-client/class-lane-new-sources.json. Commit locally (message ending with
`Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>`), never push. Stop after about 2 hours.'''
    tools = ['Read', 'Edit', 'Write', 'Grep', 'Glob', 'Bash(python:*)', 'Bash(roc.cmd:*)', 'Bash(./roc.cmd:*)',
             'Bash(git add:*)', 'Bash(git commit:*)', 'Bash(git status:*)', 'Bash(git diff:*)', 'Bash(ls:*)', 'Bash(cat:*)']
    print('agent task: %s' % task.get('class'), flush=True)
    run(['claude', '-p', 'Class recovery task for %s.\n%s' % (task.get('class'), brief), '--model', 'sonnet',
         '--permission-mode', 'acceptEdits', '--allowedTools', *tools])

elif args.lane == 'classify':
    run([PY, 'work/native-client/classify_remaining.py', '--refresh'])
