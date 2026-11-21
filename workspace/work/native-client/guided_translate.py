"""Guided analog translation (trial lane).  Every remaining function has a byte-exact mined analog whose LOGIC is
right and whose NAMES are fake.  rename.py resolves each fake callee/global of the analog to the real 2008 symbol
the original bytes reference (byte-identical object, same relocation offsets).  This lane gives the model the analog
plus that fake->real table and asks for a translation only (same statements, same types), judged by the native gate.
  python work/native-client/guided_translate.py --rename-json FILE [--jobs 6] [--limit N] [--model claude:sonnet]"""
import argparse
import collections
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--rename-json', required=True)
ap.add_argument('--jobs', type=int, default=6)
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--model', default='claude:sonnet')
args, _ = ap.parse_known_args()
if (HERE / 'prove-out/CENSUS.lock').is_file():
    sys.exit('a census is running: try again when it finishes')
sys.argv = [sys.argv[0], '--limit', '0']
sys.path.insert(0, str(HERE))
src = (HERE / 'native_placeholder_llm.py').read_text(encoding='utf-8')
lane = {'__name__': 'guided', '__file__': str(HERE / 'native_placeholder_llm.py')}
exec(compile(src[:src.index('if args.polish:')], str(HERE / 'native_placeholder_llm.py'), 'exec'), lane)
m, OUT, NAMED, results_store = lane['m'], lane['OUT'], lane['NAMED'], lane['results_store']
CODE = re.compile(r'```(?:cpp|c\+\+)\s*\n(.*?)```', re.S)
reg = m.load_registry()
renames = json.loads(Path(args.rename_json).read_text())
GUIDE = ('\n--- TRANSLATION TASK ---\nThe REFERENCE ANALOG below compiles to EXACTLY the original bytes, but with placeholder '
         'names and local stand-in types. Do NOT redesign it. Keep every statement, its order, the control flow, the '
         'integer/float widths and signedness, and every temporary exactly as written; only (1) replace each '
         'placeholder callee/global with its REAL identity from the table (use the real class member or function the '
         'native headers declare for it, called the normal C++ way), (2) replace stand-in structs with the real '
         'native classes and each `field_XX`/pad access with the real member the header declares at that use, and '
         '(3) give the function its real signature. Include the native headers that declare what you use.\n'
         '--- PLACEHOLDER -> REAL IDENTITY (resolved from the original relocations) ---\n%s\n')


def number(p):
    return int(re.sub(r'\D', '', p.stem) or 0)


def one(addr):
    row = renames[addr]
    work = OUT / addr
    analog_path = m.ROOT / 'src/2008-06' / (addr + '.cpp')
    if not analog_path.is_file():
        return addr, 'no-analog', ''
    name = (reg.get(addr) or {}).get('name') or ''
    if name and not name.startswith(('func_', 'sub_', '?sub_')) and (reg.get(addr) or {}).get('signature'):
        NAMED[addr] = (name, reg[addr]['signature'])
    table = []
    for fake, real in (row.get('renamed') or {}).items():
        target = (row.get('refs') or {}).get(fake)
        sig = (reg.get(target) or {}).get('signature') if target else None
        table.append('%s  ->  %s%s' % (fake, sig or real, '   [%s]' % target if target else ''))
    rules = lane['RULES'].format(addr=addr) if addr not in NAMED else (
        'You recover one function of the 2008 Roblox client as REAL native C++ against the real native headers.\n'
        "Its real name and signature (from the binary's decorated symbol %s):\n    %s\n"
        'Reply with one ```cpp block defining exactly that function. Use only types, members and functions the native '
        'headers declare; never define your own classes; never invent globals; no asm.\n' % NAMED[addr])
    prompt = (rules + lane['HEADER_RULE'] + GUIDE % '\n'.join(table) + '\n--- REFERENCE ANALOG (byte-exact) ---\n' +
              analog_path.read_text(errors='replace')[:7000] + '\n--- ORIGINAL ASSEMBLY ---\n' + lane['target_asm'](addr)[:5000])
    m.ask(args.model, prompt, 'sub_' + addr)
    reply = getattr(m.TOOL, 'reply', '') or ''
    code = CODE.findall(reply)
    if not code:
        return addr, 'no-reply', ''
    try:
        status, detail, cls, decl = lane['judge'](work, addr, reply, code[-1])
    except Exception as error:                                   # noqa: BLE001
        status, detail, cls, decl = 'harness-error', repr(error), '', ''
    tries = sorted(work.glob('try*.cpp'), key=number)
    n = (number(tries[-1]) + 1) if tries else 0
    work.mkdir(parents=True, exist_ok=True)
    (work / ('try%d.cpp' % n)).write_text(reply)
    (work / ('err%d.txt' % n)).write_text('%s\n%s' % (status, detail))
    saved = dict(results_store.load().get(addr) or {})
    if saved.get('status') != 'inactive_exact':
        saved.update(status=status, detail=(detail or '')[-500:], model='guided:' + args.model,
                     runs=saved.get('runs', 0) + 1, **({'class': cls, 'decl': decl} if cls else {}))
        results_store.save({addr: saved})
    if status == 'inactive_exact':
        lane['record'](addr, len(m.match.target('2008-06', addr)[0]), status, 'guided', cls, decl)
    return addr, status, (detail.strip().splitlines() or [''])[0][:110]


todo = [a for a, v in renames.items() if v.get('status') == 'renamed'][:args.limit or None]
print('guided translation targets: %d' % len(todo), flush=True)
counts = collections.Counter()
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, status, detail in pool.map(one, todo):
        counts[status] += 1
        print(addr, status, detail, flush=True)
print('RESULT guided translation: %s' % dict(counts), flush=True)
