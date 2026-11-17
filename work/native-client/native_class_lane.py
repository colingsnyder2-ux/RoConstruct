"""Class-layout lane (dashboard lane `layout`): one class per step instead of one function.
For the classes the most remaining compile failures blame ("'x' : is not a member of 'Y'", or the member's own class),
one model call sees the assembly of up to 8 failing functions, their errors and the current native class header, and
answers with class-level ```header-add lines (methods and data members, each with binary evidence).  Every saved
answer of that class is then re-judged with those lines in a private header copy (placeholder lane judge(): hardlink
mirror, real headers untouched).  Rows that improve are written back with their header_add lines, so
promote_header_adds.py can apply them (before/after prove) and the promoter can land the functions.
  python work/native-client/native_class_lane.py [--classes 10] [--jobs 8]"""
import argparse
import collections
import json
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--classes', type=int, default=10)
ap.add_argument('--jobs', type=int, default=8)
ap.add_argument('--model', default='claude:opus')
args, _ = ap.parse_known_args()
sys.argv = [sys.argv[0], '--limit', '0']
src = (HERE / 'native_placeholder_llm.py').read_text(encoding='utf-8')
lane = {'__name__': 'class_lane', '__file__': str(HERE / 'native_placeholder_llm.py')}
sys.path.insert(0, str(HERE))
exec(compile(src[:src.index('if args.regate:')], str(HERE / 'native_placeholder_llm.py'), 'exec'), lane)
m, ROOT, OUT, results = lane['m'], lane['ROOT'], lane['OUT'], lane['results']
cl = json.loads((HERE / 'remaining-classified.json').read_text())

blamed = collections.defaultdict(list)
for addr, row in results.items():
    if addr not in cl or row.get('status') not in ('compile_failed', 'draft'):
        continue
    detail = row.get('detail') or ''
    classes = re.findall(r"is not a member of '([\w:]+)'", detail)
    if row.get('class'):
        classes.append(row['class'])
    for c in dict.fromkeys(classes):
        if c.startswith(('RBX', 'C')) and '::' in c or c.startswith('C'):
            blamed[c].append(addr)
ranked = sorted(blamed.items(), key=lambda kv: -len(kv[1]))[:args.classes]
print('classes:', ', '.join('%s (%d)' % (c, len(a)) for c, a in ranked), flush=True)


def latest_answer(addr):
    tries = sorted((OUT / addr).glob('try*.cpp'))
    return tries[-1].read_text(errors='replace') if tries else ''


def class_step(cls, addrs):
    header = lane['class_header'](cls)
    if not header or not Path(header).is_relative_to(lane['HEADERS']):
        return cls, 0, 'no native header (no-header lane)'
    text = Path(header).read_text(errors='replace')
    leaf = cls.rsplit('::', 1)[-1]
    found = re.search(r'(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % re.escape(leaf), text)
    block = text[found.start():found.start() + 6000] if found else text[:6000]
    parts = []
    for addr in addrs[:8]:
        asm = subprocess.run([str(ROOT / 'roc.cmd'), 'native-asm', '2008-06', addr], cwd=ROOT, capture_output=True,
                             text=True).stdout[-2500:]
        err = (results[addr].get('detail') or '')[-600:]
        parts.append('=== %s (last result: %s)\n--- assembly ---\n%s%s\n--- last error ---\n%s\n'
                     % (addr, results[addr].get('status'), asm, m.annotate_asm(asm)[:1500], err))
    prompt = ('You fix the native header of ONE class of the 2008 Roblox client so its functions compile and match.\n'
              'CLASS: %s   HEADER: %s\n--- CURRENT CLASS DECLARATION ---\n%s\n'
              '--- FAILING FUNCTIONS OF THIS CLASS (assembly, annotations, last compile error) ---\n%s\n'
              'Reply with ONE ```header-add block: lines `%s | declaration;   // evidence: <decorated symbol / asm offset +0xNN '
              'read by ADDR / donor header>`. Add only members the binary proves (methods the errors name, data members at '
              'offsets the assembly reads with their real types). Never padding arrays or placeholder names like unk_/field_; '
              'never redeclare existing members. At most 6 lines. Reply with nothing else.'
              % (cls, Path(header).relative_to(lane['HEADERS']).as_posix(), block, '\n'.join(parts), cls))
    m.ask(args.model, prompt, cls)
    reply = getattr(m.TOOL, 'reply', '') or ''
    adds, why = lane['parse_header_adds'](reply)
    if not adds:
        return cls, 0, 'no usable header-add (%s)' % (why or 'empty')
    block_text = '```header-add\n' + '\n'.join('%s | %s   %s' % a for a in adds) + '\n```\n'
    gained = 0
    for addr in addrs:
        answer = latest_answer(addr)
        code = re.findall(r'```(?:cpp|c\+\+)\s*\n(.*?)```', answer, re.S)
        if not code:
            continue
        reply2 = block_text + re.sub(r'```header-add\s*\n.*?```', '', answer, flags=re.S)
        before = results[addr]['status']
        try:
            status, detail, c2, d2 = lane['judge'](OUT / addr, addr, reply2, code[-1])
        except Exception as error:                                   # noqa: BLE001
            status, detail = 'harness-error', repr(error)
        rank = {'inactive_exact': 3, 'draft': 2, 'compile_failed': 1}
        if rank.get(status, 0) > rank.get(before, 0):
            results[addr].update(status=status, detail=detail[-500:], header_add=[list(a) for a in adds],
                                 **({'class': c2, 'decl': d2} if c2 else {}))
            gained += status == 'inactive_exact'
            print('  %s %s -> %s' % (addr, before, status), flush=True)
            if status == 'inactive_exact':
                lane['record'](addr, len(m.match.target('2008-06', addr)[0]), status, 'class-lane:' + args.model, c2, d2)
    return cls, gained, '%d header lines' % len(adds)


with ThreadPoolExecutor(min(args.jobs, 4)) as pool:          # 4 classes at a time: each step re-judges many answers
    for cls, gained, note in pool.map(lambda kv: class_step(*kv), ranked):
        print('%s: +%d exact (%s)' % (cls, gained, note), flush=True)
        lane['RESULTS'].write_text(json.dumps(results, indent=1))
print('RESULT class-layout lane done', flush=True)
