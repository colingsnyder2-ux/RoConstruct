"""Compile-fix lane.  The model lane gives a function two one-shot tries; 800+ remaining functions ended at
compile_failed, yet about 45% of answers that DO compile are byte-exact.  This lane takes the last answer of each
compile-failed function and loops: compile -> feed the compiler's first 12 error lines back -> minimal fix, up to
ROUNDS times (Haiku first, Sonnet for the last rounds), stopping as soon as the answer compiles (exact or draft;
drafts go to the polish lane).  Every round is written as try<N>.cpp / err<N>.txt like the model lane's.
  python work/native-client/compile_fix_lane.py [--jobs 8] [--limit N] [--rounds 4]"""
import argparse
import collections
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--jobs', type=int, default=8)
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--rounds', type=int, default=4)
ap.add_argument('--only', default='', help='JSON list of addresses')
args, _ = ap.parse_known_args()
# Safe during a census: this lane writes only lane scratch and results.json, never census inputs.
sys.argv = [sys.argv[0], '--limit', '0']
sys.path.insert(0, str(HERE))
src = (HERE / 'native_placeholder_llm.py').read_text(encoding='utf-8')
lane = {'__name__': 'compile_fix', '__file__': str(HERE / 'native_placeholder_llm.py')}
exec(compile(src[:src.index('if args.polish:')], str(HERE / 'native_placeholder_llm.py'), 'exec'), lane)
m, cg, OUT, NAMED, results_store = lane['m'], lane['cg'], lane['OUT'], lane['NAMED'], lane['results_store']
CODE = re.compile(r'```(?:cpp|c\+\+)\s*\n(.*?)```', re.S)
FIX = ('\nThe answer above does NOT compile. Compiler errors (MSVC 2008):\n%s\n\n'
       'Fix ONLY what these errors need, keeping the logic: add the #include of the native header that declares a '
       'missing type (paths relative to the native-headers root, e.g. "v8world/World.h"), qualify namespaces, correct a '
       'member or method name to one the header really declares, or use the header-add block for a member the class '
       'truly lacks. Do not define your own classes or externs. Reply with the complete corrected answer in the same '
       'format as before.\n')


HEADERS = m.ROOT / 'rebuild/2008-06/native-headers'
_INDEX = None
SKIP = set('RBX std boost G3D const char int void unsigned class struct this type X T error identifier'.split())


def where_declared(names):
    """`name: header:line: text` for identifiers the errors mention - the model cannot grep, so it guessed includes."""
    global _INDEX
    if _INDEX is None:
        _INDEX = collections.defaultdict(list)
        for h in sorted(HEADERS.rglob('*.h'), key=lambda p: (len(p.relative_to(HEADERS).parts), str(p))):
            rel = h.relative_to(HEADERS).as_posix()
            try:
                lines = h.read_text(errors='replace').splitlines()
            except OSError:
                continue
            for i, line in enumerate(lines, 1):
                if line.lstrip().startswith(('//', '#include')):
                    continue
                for tok in set(re.findall(r'[A-Za-z_]\w{2,}', line)):
                    if len(_INDEX[tok]) < 4:
                        _INDEX[tok].append('%s:%d: %s' % (rel, i, line.strip()[:110]))
    out = []
    for name in names:
        hits = _INDEX.get(name)
        out.append('%s -> %s' % (name, '\n      '.join(hits) if hits else 'NOT declared in any native header'))
    return '\n'.join(out)


def number(p):
    return int(re.sub(r'\D', '', p.stem) or 0)


def fix_one(addr):
    work = OUT / addr
    tries = sorted(work.glob('try*.cpp'), key=number)
    if not tries:
        return addr, 'skip', ''
    reg = m.load_registry().get(addr) or {}
    name = reg.get('name') or ''
    if name and not name.startswith(('func_', 'sub_', '?sub_')) and reg.get('signature'):
        NAMED[addr] = (name, reg['signature'])
    reply = tries[-1].read_text(errors='replace')
    code = CODE.findall(reply)
    if not code:
        return addr, 'skip', ''
    rules = lane['RULES'].format(addr=addr) if addr not in NAMED else (
        'You recover one function of the 2008 Roblox client as REAL native C++ against the real native headers.\n'
        "Its real name and signature (from the binary's decorated symbol %s):\n    %s\n"
        'Reply with one ```cpp block defining exactly that function. Use only types, members and functions the native '
        'headers declare; never define your own classes; never invent globals; no asm.\n' % NAMED[addr])
    base = rules + lane['HEADER_RULE'] + '\n--- ORIGINAL ASSEMBLY ---\n' + lane['target_asm'](addr)[:6000]
    status, detail, cls, decl = 'compile_failed', '', '', ''
    n = number(tries[-1])
    for rnd in range(args.rounds + 1):
        try:
            status, detail, cls, decl = lane['judge'](work, addr, reply, code[-1])
        except Exception as error:                               # noqa: BLE001
            status, detail = 'harness-error', repr(error)
        if rnd:                                                  # round 0 only re-judges the saved answer
            n += 1
            (work / ('try%d.cpp' % n)).write_text(reply)
            (work / ('err%d.txt' % n)).write_text('%s\n%s' % (status, detail))
        if status != 'compile_failed' or rnd == args.rounds:
            break
        errors = '\n'.join(cg.LAST_ERRORS.get(addr) or [detail[:600]])
        names = [n for n in dict.fromkeys(t for q in re.findall(r"'([^']+)'", errors) for t in re.findall(r'[A-Za-z_]\w{2,}', q))
                 if n not in SKIP][:10]
        if names:
            errors += ('\n\nWhere the names in these errors are declared (native-headers root; include that header, or '
                       'use the exact declared spelling):\n' + where_declared(names))
        model = 'claude:haiku' if rnd < 2 else 'claude:sonnet'
        m.ask(model, base + '\n--- YOUR PREVIOUS ANSWER ---\n' + reply[-3500:] + FIX % errors, 'sub_' + addr)
        new = getattr(m.TOOL, 'reply', '') or ''
        fixed = CODE.findall(new)
        if not fixed:
            break
        reply, code = new, fixed
    row = dict(results_store.load().get(addr) or {})
    row.update(status=status, detail=(detail or '')[-500:], model='compile-fix', runs=row.get('runs', 0) + 1,
               **({'class': cls, 'decl': decl} if cls else {}))
    results_store.save({addr: row})
    if status == 'inactive_exact':
        lane['record'](addr, len(m.match.target('2008-06', addr)[0]), status, 'compile-fix', cls, decl)
    return addr, status, (detail.strip().splitlines() or [''])[0][:110]


cl = json.loads((HERE / 'remaining-classified.json').read_text())
todo = []
for addr, v in cl.items():
    if v.get('bucket') == 'vendor-library' or v['size'] > 2048:
        continue
    errs = sorted((OUT / addr).glob('err*.txt'), key=number)
    if errs and errs[-1].read_text(errors='replace').split('\n', 1)[0].strip() == 'compile_failed':
        todo.append((v['size'], addr))
todo = [a for _, a in sorted(todo)]
if args.only:
    only = set(json.loads(Path(args.only).read_text()))
    todo = [a for a in todo if a in only]
todo = todo[:args.limit or None]
print('compile-failed functions to fix: %d' % len(todo), flush=True)
counts = collections.Counter()
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, status, detail in pool.map(fix_one, todo):
        counts[status] += 1
        print(addr, status, detail, flush=True)
print('RESULT compile-fix: %s' % dict(counts), flush=True)
