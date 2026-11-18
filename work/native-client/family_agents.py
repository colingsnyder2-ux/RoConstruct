"""Family agents (dashboard lane "families").  One headless session per FAMILY of byte-identical twins: the session
fixes ONE root cause (a template body, a missing instantiation line, a missing binding) on ONE address and then runs
the no-model lane over the whole family.  Measured 2026-11-18: 25 and 7 exact functions per session at ~6-20 K tokens
per function, versus 1-2 functions per session for one-function-at-a-time class agents.

Queue (built here, no model): families from research-twins/identities.json (identity from RTTI / typeid / strings),
minus addresses that already have a proved unit.  Brief: family-brief.md + the family's addresses, identities, owner
facts and one precomputed lane verdict, so the session does not explore.
  python work/native-client/family_agents.py [--jobs 2] [--model fable|sonnet] [--effort low] [--list] [--only LEAF]"""
import argparse
import collections
import json
import re
import shutil
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
ap = argparse.ArgumentParser()
ap.add_argument('--jobs', type=int, default=2)
ap.add_argument('--model', default='fable')
ap.add_argument('--effort', default='low')
ap.add_argument('--list', action='store_true')
ap.add_argument('--only', default='')
ap.add_argument('--exact', action='store_true', help='match --only against the full queue label')
ap.add_argument('--min', type=int, default=3, help='smallest family worth a session')
ap.add_argument('--queue', default='twins', help='twins (template families) or owners (functions of one class, owner '
                'and declarations recovered from the binary: research-owners/owners.json)')
args = ap.parse_args()
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
DONE = HERE / 'family-agents-done.json'
LOGS = HERE / 'agent-logs'


def spell(identity):
    return re.sub(r'^(?:class|struct)\s+', '', re.sub(r'\s*\[subobject [^\]]*\]', '', identity)).strip()


def family_of(row):
    ident = spell(row['identity'])
    rule = row['rule'].split()[0]
    if rule in ('functor', 'typeid', 'via-callee', 'via-caller'):
        return 'boost functor pieces: ' + re.sub(r'<.*', '', ident).rsplit('::', 1)[-1]
    if rule == 'ptr-string':
        return 'Lua::Bridge<T> (name strings)'
    if rule == 'string':
        return 'string-identified'
    return re.sub(r'<.*', '', ident)


try:        # addresses a worker already bound after a byte-equal proof (units other than TwinInst_*, e.g. a family unit)
    BOUND = {r.get('address') for r in json.loads((HERE / 'class-identity-bindings.json').read_text(encoding='utf-8'))['identity_bindings']
             if 'class_workflow' not in str(r.get('identity_evidence'))}
except (OSError, ValueError, KeyError):
    BOUND = set()


def proved(addr):
    return addr in BOUND or any((CLASSES / ('%s_%s.cpp' % (prefix, addr))).is_file() for prefix in ('TwinInst', 'FunctorInst', 'Thunk'))


def owner_queue():
    own = json.loads((HERE / 'research-owners/owners.json').read_text())
    twins = json.loads((HERE / 'research-twins/identities.json').read_text())['unique']
    remaining = json.loads((HERE / 'remaining-classified.json').read_text())
    groups = collections.defaultdict(list)
    for addr, fact in own.items():
        if addr in remaining and addr not in twins and not proved(addr):
            groups[re.sub(r'<.*', '', fact['owner'])].append(addr)
    done = set(json.loads(DONE.read_text())) if DONE.is_file() else set()
    out = []
    for name, addrs in sorted(groups.items(), key=lambda kv: -len(kv[1])):
        if len(addrs) < args.min or 'class ' + name in done or (args.only and (('class ' + name != args.only) if args.exact else not any(x in name for x in args.only.split(',')))):
            continue
        addrs.sort(key=lambda a: (remaining[a]['size'], a))
        lines = ['%s  %d bytes  %s  (%s)' % (a, remaining[a]['size'], own[a].get('declaration') or own[a].get('name') or
                                               'member, name unknown: use sub_' + a, own[a].get('method', '')) for a in addrs[:30]]
        out.append({'family': 'class ' + name, 'addresses': addrs, 'lines': lines, 'class_task': True})
    return out


def ownerless_queue():
    rows = json.loads((HERE / 'lane-drafts/codex-ownerless-primitive/ownerless-hints.json').read_text(encoding='utf-8'))['rows']
    owners = json.loads((HERE / 'research-owners/owners.json').read_text(encoding='utf-8'))
    twins = json.loads((HERE / 'research-twins/identities.json').read_text(encoding='utf-8'))['unique']
    hints = json.loads((HERE / 'owner-classes.json').read_text(encoding='utf-8'))
    rows.sort(key=lambda r: (r['size'], r['addr']))
    out = []
    for i in range(0, len(rows), 3):
        group = rows[i:i + 3]
        name = 'ownerless:' + group[0]['addr']
        batch = [r for r in group if r['addr'] not in owners and r['addr'] not in twins and not proved(r['addr'])]
        if not batch:
            continue
        if args.only and args.only not in name:
            continue
        lines = ['%s  %s bytes  symbol: %s  owner lead (unverified): %s' %
                 (r['addr'], r['size'], r.get('name', ''), json.dumps(hints.get(r['addr']))) for r in batch]
        out.append({'family': name, 'addresses': [r['addr'] for r in batch], 'lines': lines, 'ownerless_task': True})
    return out


def queue():
    if args.queue == 'owners':
        return owner_queue()
    if args.queue == 'ownerless':
        return ownerless_queue()
    unique = json.loads((HERE / 'research-twins/identities.json').read_text())['unique']
    owners = json.loads((HERE / 'research-owners/owners.json').read_text()) if (HERE / 'research-owners/owners.json').is_file() else {}
    lane = json.loads((HERE / 'twin-lane-done.json').read_text()) if (HERE / 'twin-lane-done.json').is_file() else {}
    groups = collections.defaultdict(list)
    for addr, row in unique.items():
        if not proved(addr) and not str(lane.get(addr, '')).startswith('EXACT'):
            groups[family_of(row)].append(addr)
    done = set(json.loads(DONE.read_text())) if DONE.is_file() else set()
    out = []
    for name, addrs in sorted(groups.items(), key=lambda kv: -len(kv[1])):
        if len(addrs) < args.min or name in done or (args.only and ((name != args.only) if args.exact else not any(x in name for x in args.only.split(',')))):
            continue
        lines = []
        for a in sorted(addrs)[:40]:
            fact = owners.get(a) or {}
            lines.append('%s  %s%s%s' % (a, spell(unique[a]['identity'])[:150],
                                         ('  | ' + (fact.get('declaration') or fact.get('name') or '')[:110]) if fact else '',
                                         ('  | last lane verdict: ' + str(lane[a])[:150]) if a in lane else ''))
        out.append({'family': name, 'addresses': sorted(addrs), 'lines': lines})
    return out


FAMILY_TEXT = ('\n\n# YOUR FAMILY: %s (%d addresses)\n\nLease name: family:%s. Addresses, identity from the binary, known '
              'declaration, last lane verdict:\n%s\n\nStart with ONE address: run the lane on it (`python work/native-client/'
              'twin_lane.py --only ADDR --jobs 1`; do not edit shared lane state without its lease; for '
              'boost functor pieces use work/native-client/functor_lane.py if it exists), find the single root cause, fix it, '
              'then run the lane over ALL addresses of the family in one command. First verify the identities represent '
              'the same template: string and caller/callee groupings may be unrelated. Do not hand-write the other functions. '
              'Run commands in the foreground; never use wake-run.\n')


def run_codex(task, brief, slug):
    codex = shutil.which('codex')
    remote = args.model.split(':', 1)[1] if ':' in args.model else 'gpt-6.1-terra'
    brief += ('\n\nCODEX SESSION NOTE: this is a one-shot non-interactive session. Run every command directly in the '
              'FOREGROUND and wait for it; do NOT use the wake-run watcher or any background job (AGENTS.md "Long native '
              'gates" does not apply here). `git add`/`git commit` are blocked by your sandbox: leave files uncommitted '
              'and list them in the report.\n')
    LOGS.mkdir(exist_ok=True)
    log, last = LOGS / ('family-codex-%s.log' % slug), LOGS / ('family-codex-%s.last.txt' % slug)
    started = time.time()
    try:
        subprocess.run([codex, 'exec', '-s', 'workspace-write', '-c', 'sandbox_workspace_write.network_access=true',
                        '-m', remote, '-c', 'model_reasoning_effort="%s"' % (args.effort if args.effort != 'low' else 'medium'),
                        '-C', str(ROOT), '-o', str(last), '-'], input=brief, text=True, encoding='utf-8', errors='replace',
                       cwd=ROOT, capture_output=True, timeout=120 * 60)
    except subprocess.TimeoutExpired:
        pass
    text = last.read_text(encoding='utf-8', errors='replace') if last.is_file() else ''
    exact = sum(1 for a in task['addresses'] if proved(a) or (CLASSES / ('TwinInst_%s.cpp' % a)).is_file())
    log.write_text('%s\n[family agents] codex %s: %d min\n' % (text, task['family'], (time.time() - started) / 60), encoding='utf-8')
    if 'usage limit' not in text:                # a spent quota must not consume the family
        done = set(json.loads(DONE.read_text())) if DONE.is_file() else set()
        DONE.write_text(json.dumps(sorted(done | {task['family']}), indent=1))
    return task['family'], exact, len(task['addresses']), 0, 'codex'


def run_opencode(task, brief, slug):
    import os
    exe = shutil.which('opencode')
    if not exe and os.name == 'nt':
        candidate = Path(os.environ.get('APPDATA', '')) / 'ai.opencode.desktop/cli/2.2.6-x64/opencode-cli.exe'
        if candidate.is_file():
            exe = str(candidate)
    if not exe:
        return task['family'], 0, len(task['addresses']), 0, 'OpenCode not found'
    model = args.model.split(':', 1)[1] if ':' in args.model else 'opencode/big-pickle'
    env = os.environ.copy()
    if model.startswith('roc-nim/'):
        sys.path.insert(0, str(ROOT))
        from roc import providers
        key = providers.secret('NVIDIA_API_KEY')
        if not key:
            return task['family'], 0, len(task['addresses']), 0, 'NVIDIA API key missing'
        env['NVIDIA_API_KEY'] = key
        env['OPENCODE_CONFIG'] = str(HERE / 'nim-opencode.json')
    LOGS.mkdir(exist_ok=True)
    log = LOGS / ('family-opencode-%s.log' % slug)
    if log.exists() and log.stat().st_size:
        log.replace(LOGS / ('family-opencode-%s-%d.previous.log' % (slug, time.time_ns())))
    started = time.time()
    try:
        with log.open('w', encoding='utf-8') as stream:
            proc = subprocess.run(
                [exe, 'run', '--standalone', '--auto', '--format', 'json', '-m', model],
                input=brief, text=True, encoding='utf-8', errors='replace',
                cwd=ROOT, env=env, stdout=stream, stderr=subprocess.STDOUT, timeout=120 * 60)
        status = 'exit %d' % proc.returncode
        if proc.returncode == 0:
            for line in log.read_text(encoding='utf-8', errors='replace').splitlines():
                try:
                    event = json.loads(line)
                except ValueError:
                    continue
                if event.get('type') == 'error':
                    status = 'provider error: ' + str(event.get('error', 'unknown'))[:250]
                    break
    except subprocess.TimeoutExpired:
        status = 'timeout'
    exact = sum(1 for addr in task['addresses'] if proved(addr))
    with log.open('a', encoding='utf-8') as stream:
        stream.write('\n[family agents] %s: %s; %d of %d proved; %d min\n' %
                     (task['family'], status, exact, len(task['addresses']), (time.time() - started) / 60))
    return task['family'], exact, len(task['addresses']), 0, status


def run(task):
    brief = ((ROOT / 'CLAUDE.md') if task.get('ownerless_task') or task.get('class_task') else (HERE / 'family-brief.md')).read_text(encoding='utf-8')
    slug = re.sub(r'\W+', '_', task['family'])[:60]
    if task.get('ownerless_task'):
        brief += ('\n\n# OWNERLESS INVESTIGATION: %s\nThese are independent candidates, not a proven family. '
                  'Check each address is still unmatched and not already inactive before working. Recover real ownership '
                  'and declarations from callers, callees, neighboring functions, RTTI, symbols and existing headers. '
                  'Owner leads are unverified. Do not invent a class, field, ABI, or claim a match without byte-exact '
                  'proof. Work smallest first; park uncertain cases with evidence. Use native code only, draft in '
                  'work/native-client/lane-drafts/%s, obtain leases before modifying native files or shared headers, '
                  'prove with agent_prove.py, and bind only verified matches. Do not submit. Run commands in the '
                  'foreground; do not use wake-run.\n%s\n' % (task['family'], slug, '\n'.join(task['lines'])))
    elif task.get('class_task'):
        brief += ('\n\n# YOUR TASK: %s (%d functions; owner class and declarations were recovered from the binary: '
                  'vftable slots, RTTI, link order)\n\nLease name: family:%s. This is NOT a template family: write each '
                  'function natively as a member of the real class (include its native header; add missing declarations '
                  'to that header under lease as `// INFERRED:` lines; never define the class or any stand-in type '
                  'yourself). Put them in ONE new unit `rebuild/2008-06/native-classes/<Class>Recovery_<firstaddr>.cpp` '
                  '(draft it under work/native-client/lane-drafts/<name>/ until proven). The byte-exact analog '
                  '`src/2008-06/<addr>.cpp` shows statement order; `python roc.py native-asm 2008-06 ADDR` the target. '
                  'Prove with agent_prove.py, bind byte-equal bodies with root_ref_bind.py / agent_bind.py. Smallest '
                  'functions first; park a function after three failed variants.\n%s\n'
                  % (task['family'], len(task['addresses']), slug, '\n'.join(task['lines'])))
    else:
        brief += FAMILY_TEXT % (task['family'], len(task['addresses']), slug, '\n'.join(task['lines']))
    previous = {}
    for filename in ('twin-lane-done.json', 'functor-lane-done.json'):
        try:
            previous.update(json.loads((HERE / filename).read_text(encoding='utf-8')))
        except (OSError, ValueError):
            pass
    verdicts = ['%s: %s' % (addr, str(previous[addr])[:400]) for addr in task['addresses'] if addr in previous]
    if verdicts:
        brief += '\nPREVIOUS VERDICTS (do not repeat unchanged):\n' + '\n'.join(verdicts[:12]) + '\n'
    clues = {
        'boost functor pieces: bind_t': '0048e470, 00492ea0, 00493210 had equal bytes but REJECTED due to unresolved referenced symbol/identity. Investigate binary references; do not recompile unchanged. 0041b040, 005ad140, 0041cf60 were already exact before the last run.',
        'boost functor pieces: basic_string': '00597740 draft work/native-client/lane-drafts/basic_string/TwinInst_00597740.cpp had equal bytes but REJECTED: genericConvert<TextureId> symbol identity not established. Inspect binary caller/type evidence; do not assume identity or repeat the same proof.',
        'class CComCtlWrapper': 'Existing draft: work/native-client/lane-drafts/CComCtlWrapper/CComCtlWrapperRecovery_00422000.cpp. For 00422000 target is 42 bytes; candidate was 58. Target compares [esi+0x68] to zero and calls one helper; candidate adds helper/operator calls and an extra push edi. Check real declarations before changing accessors; prove all relevant addresses together.',
        'class RBX::DxUserInput': '00467ad0 previously DIFF. Existing draft directory: work/native-client/lane-drafts/RBX_DxUserInput. 00467a00 compile failed on undeclared Guard/input and missing UIEvent::type; verify authentic declarations, do not invent fields.',
        'class RBX::World': '005e9170 has 12-byte target: mov eax,[ecx+0x84]; mov ecx,[eax]; mov eax,[ecx+0x78]; ret. A previous DIFF compared an unrelated Weld destructor, so it is not a useful comparison. Establish the real owner, field and declaration before implementing.',
        'class XItem': 'Start with 00441560 (111 bytes), a vftable-identified XItem<BrickColor,...>::OnValueChanged; 004414e0 and 00441660 are related Color3/Vector3 members, not proven twins. Check whether each is already inactive before proving.',
        'boost::any::holder': '00559a50 previous explicit constructor instantiation failed C3190; emitted alternative was 35 bytes versus a 179-byte target. Do not repeat the same instantiation; establish correct member template signature and compiler behavior first.',
    }
    label = task['family']
    if label in clues:
        brief += '\nSPECIFIC PREVIOUS FINDING: ' + clues[label] + '\n'
    brief += ('\nQUICK GUIDE: On Windows commands run in PowerShell. Use `rg`, `Select-Object -First 30`, '
              '`Select-Object -Last 30`, and `$null`; do not use Unix head, wc, /dev/null, dir /b or `||`. '
              'Do not run cl.exe directly: agent_prove.py sets the required compiler environment. '
              'Assembly uses ecx as this for ordinary 32-bit member calls; [ecx+offset] accesses memory; '
              'push/pop change the stack; call targets and relocation references must match. Registers and offsets '
              'are clues, not permission to invent fields. `EXACT` requires bytes AND accepted identity/references; '
              '`REJECTED` means bytes alone matched; `DIFF` means inspect the actual named candidate against target; '
              '`COMPILE FAILED` means fix the first real compiler error. Never count an old match as a new gain.\n')
    brief += ('\n\nEFFICIENCY: Read the project rules and task-specific evidence, then work directly on the smallest '
              'unmatched candidate. Verify it is not already inactive or proved before retrying; an existing exact is '
              'not a new gain. Use rg with exact addresses and bounded output; do not read entire identity/evidence '
              'JSON files, full historical logs, or run recursive globs. Batch related lookups and proof addresses '
              'where safe. Aim for at most 50 tool calls; after 3 failed variants or repeated identical compile errors, '
              'park the target and report the blocker instead of repeating. REJECTED means byte equality without proven '
              'identity/references: investigate that evidence, do not call it EXACT or recompile unchanged. Do not '
              'submit; report new inactive exacts separately from already-proved matches.\n')
    deny = ['%s(%s*)' % (shell, cmd) for shell in ('Bash', 'PowerShell')
            for cmd in ('git push', 'git reset', 'git checkout', 'git clean', 'git rebase', 'git branch -D', 'git stash',
                        'git filter', 'git worktree', 'rm -rf', 'rm -r', 'Remove-Item', 'del ', 'rmdir', 'curl', 'wget',
                        'Invoke-WebRequest', 'Invoke-RestMethod', 'python roc.py submit', 'roc.cmd submit', 'npm', 'pip',
                        'grep -r', 'grep -R', 'find work/native-client/prove-out', 'python work/native-client/prove.py --all')]
    deny += ['WebFetch', 'WebSearch', 'Agent', 'Task']
    if args.model.startswith('opencode'):
        return run_opencode(task, brief, slug)
    if args.model.startswith('codex'):          # Codex CLI (owner 2026-11-18: terra, medium effort); cannot commit
        return run_codex(task, brief, slug)
    model = 'claude-fable-5-2' if args.model == 'fable' else args.model
    cmd = [shutil.which('claude') or 'claude', '-p', '--model', model, '--effort', args.effort, '--max-budget-usd', '12',
           '--permission-mode', 'bypassPermissions', '--strict-mcp-config', '--mcp-config', str(HERE / 'agent-empty-mcp.json'),
           '--disable-slash-commands', '--exclude-dynamic-system-prompt-sections', '--setting-sources', 'project',
           '--output-format', 'stream-json', '--verbose', '--disallowedTools', *deny]
    LOGS.mkdir(exist_ok=True)
    log = LOGS / ('family-%s.log' % slug)
    started, tools, result, cost = time.time(), 0, '', ''
    proc = subprocess.Popen(cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True,
                            encoding='utf-8', errors='replace', cwd=ROOT)
    proc.stdin.write(brief)
    proc.stdin.close()
    for line in proc.stdout:
        try:
            ev = json.loads(line)
        except ValueError:
            continue
        content = (ev.get('message') or {}).get('content')
        for c in content if isinstance(content, list) else []:
            if isinstance(c, dict) and c.get('type') == 'tool_use':
                tools += 1
        if ev.get('type') == 'result':
            result = ev.get('result') or ''
            cost = '$%.2f' % ev['total_cost_usd'] if ev.get('total_cost_usd') is not None else ''
        if tools >= 150 or time.time() - started > 120 * 60:        # hard stop: a family session should be short
            proc.kill()
            result += '\n[stopped: %d tool calls / %d min]' % (tools, (time.time() - started) / 60)
            break
    proc.wait()
    exact = sum(1 for a in task['addresses'] if proved(a))
    log.write_text('%s\n[family agents] %s: %d of %d addresses have a proved unit; %d tool calls; %s; %d min\n'
                   % (result, task['family'], exact, len(task['addresses']), tools, cost, (time.time() - started) / 60), encoding='utf-8')
    done = set(json.loads(DONE.read_text())) if DONE.is_file() else set()
    DONE.write_text(json.dumps(sorted(done | {task['family']}), indent=1))
    return task['family'], exact, len(task['addresses']), tools, cost


tasks = queue()
print('family queue: %d families, %d functions' % (len(tasks), sum(len(t['addresses']) for t in tasks)), flush=True)
for t in tasks:
    print('  %3d  %s' % (len(t['addresses']), t['family']), flush=True)
if args.list or not tasks:
    sys.exit(0)
batch = tasks[:max(1, args.jobs)]
with ThreadPoolExecutor(len(batch)) as pool:
    for name, exact, total, tools, cost in pool.map(run, batch):
        print('RESULT family %s: %d of %d proved, %d tool calls, %s' % (name, exact, total, tools, cost), flush=True)
