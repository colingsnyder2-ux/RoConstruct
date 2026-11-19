"""Evolve a draft toward byte-exact by editing only the first divergent hunk (graded by prefix_match).
  python work/native-client/evolve.py ADDR --file FILE.cpp [--name SUBSTR] [--rounds 6] [--width 4] [--model M]
Each round: score best draft (prefix_match), ask the model for --width variants of the whole file that change ONLY
the code producing the first divergent instruction, compile+score each, keep the best by prefix bytes.  Stops at
100% or after the rounds.  Best draft is written to lane-drafts/evolve_<addr>/best.cpp; run agent_prove.py on it
for the full proof (this tool never claims exactness itself).  Variants that define class/struct/union/extern,
pad fields or change the function signature are discarded."""
import argparse
import os
os.environ.setdefault('ROC_LLM_MAX_TOKENS', '24000')   # a reply holds several whole files; 4096 truncated them to nothing
os.environ.setdefault('ROC_LLM_TIMEOUT', '600')   # free reasoning models need minutes; the 120 s default returned empty replies
import re
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('addr', nargs='?', default='')
ap.add_argument('--file', default='')
ap.add_argument('--batch', default='', help='text file listing drafts (one path per line; address = parent folder name)')
ap.add_argument('--no-permute', action='store_true')
ap.add_argument('--permute-compiles', type=int, default=10, help='compile budget of the permuter stage (each ~10-60 s)')
ap.add_argument('--name', default='')
ap.add_argument('--rounds', type=int, default=6)
ap.add_argument('--width', type=int, default=8)
ap.add_argument('--model', default='opencode/big-pickle,opencode/deepseek-v4.1-flash-free,opencode/mimo-v2.6-flash-free,opencode/nemotron-3.5-lightning-free,claude:sonnet',
                help='comma list tried in order until one returns text (free first, Sonnet last)')
args, _ = ap.parse_known_args()
sys.argv = [sys.argv[0], '--limit', '0']
sys.path.insert(0, str(HERE))
src = (HERE / 'native_placeholder_llm.py').read_text(encoding='utf-8')
lane = {'__name__': 'evolve', '__file__': str(HERE / 'native_placeholder_llm.py')}
exec(compile(src[:src.index('if args.polish:')], str(HERE / 'native_placeholder_llm.py'), 'exec'), lane)
m = lane['m']
import prefix_match as pm  # noqa: E402
import hashlib  # noqa: E402
from roc import match, mutate  # noqa: E402

PWORK = HERE / 'permute'


BUDGET = [0]


def make_check(addr, flags_line):
    """copied from native_permute.make_check: compile with the native toolchain, score with match.check_text"""
    def check(client, address, text, flags=None, include_diagnosis=False):
        base = PWORK / addr / hashlib.sha1(text.encode('utf-8', 'replace')).hexdigest()[:16]
        base.mkdir(parents=True, exist_ok=True)
        source, folder = base / 'probe.cpp', base / 'job'
        obj = folder / 'candidate.obj'
        if not obj.is_file():
            BUDGET[0] += 1
            if BUDGET[0] > args.permute_compiles:
                raise match.CompileError('permuter compile budget spent')
            if folder.is_dir():
                raise match.CompileError('native compile failed earlier')
            source.write_text(flags_line + chr(10) + text)
            runner, tc = pm._rt()
            job = runner.compile_job({'source': str(source.resolve()), 'checks': [], 'ranges': [], 'layouts': []}, folder, tc)
            obj = Path(job.get('object') or obj)
        if not obj.is_file():
            raise match.CompileError('native compile failed')
        return match.check_text(client, address, text, flags, include_diagnosis=include_diagnosis, obj=obj.read_bytes())
    return check


def permute(addr, text):
    """stage 1 (no model): roc.mutate permuter; returns the best full text (flags line kept)"""
    BUDGET[0] = 0
    first, _, rest = text.partition(chr(10))
    if not first.startswith('// native-flags:'):
        return text
    try:
        res = mutate.improve('2008-06', addr, rest, flags=None, check=make_check(addr, first), guided=True, permute=True)
    except Exception as error:  # noqa: BLE001
        print('permuter error', repr(error)[:100])
        return text
    print('permuter: score %s after %s tries' % (res[0], res[2]), flush=True)
    return first + chr(10) + res[1]

BLOCK = re.compile(r'```(?:cpp|c\+\+)?\s*\n(.*?)```', re.S)
TYPE = re.compile(r'\b(?:struct|class|union)\s+(\w+)\s*(?:final\s*)?(?::[^{;]*)?\{')
LEVERS = """MSVC 2008 codegen levers that change register allocation / instruction order WITHOUT changing meaning (try ONE):
- statement order of independent statements; order of local variable declarations; narrower or wider scope of a local
- a temporary for a member/expression used twice (take the member into a local first), or remove such a temporary
- early return vs if/else; `&&`/`||` chain shape vs nested ifs; negating a condition and swapping branches
- loop form: for / while / do-while; pointer iteration vs index access
- unsigned vs int (or size_t) for a counter or compare; float vs double temporary; explicit cast placement
- `inline` / `__forceinline` / out-of-line on a small helper that already exists; argument evaluation order
- `const` locals, reusing one local for two values vs two locals"""
RULES = """RULES: reply with ONE ```cpp block per variant, each the COMPLETE file. Change ONLY the statements that produce the first
divergent instruction; keep everything else byte-for-byte. NEVER define a class/struct/union, pad field or extern; never
change a function signature or the first `// native-flags:` line; no asm, no raw this+offset."""


def bad(code, ref):
    plain = re.sub(r'/\*.*?\*/', '', re.sub(r'//[^\n]*', '', code), flags=re.S)
    if TYPE.search(plain) or re.search(r'^\s*extern\b', plain, re.M) or re.search(r'__asm|_emit', plain):
        return True
    sig = lambda s: re.findall(r'^[\w:<>\*&~ ,]+\([^;{)]*\)\s*(?:const)?\s*\{?$', s, re.M)   # noqa: E731
    return sig(code) != sig(ref)


def window(rows, n, a=6, b=8):
    return '\n'.join('%s %08x  %s' % ('>' if k == n else ' ', rows[k][0], rows[k][1][:80]) for k in range(max(0, n - a), min(len(rows), n + b)))


def evolve_one(addr, file):
    addr = addr.lower().zfill(8)
    out = HERE / 'lane-drafts' / ('evolve_%s_w%d' % (addr, args.width))
    out.mkdir(parents=True, exist_ok=True)
    best_text = Path(file).read_text(encoding='utf-8', errors='replace')
    if not args.no_permute:
        best_text = permute(addr, best_text)
    calls, n = 0, 0

    def run(text, tag):
        nonlocal n
        n += 1
        p = out / ('v%03d_%s.cpp' % (n, tag))
        p.write_text(text, encoding='utf-8')
        return pm.score(p, addr, args.name)

    cur = run(best_text, 'start')
    print('round 0: ' + (('%.1f%% (%d/%d insns)' % (100 * cur['score'], cur['prefix_insns'], cur['total_insns'])) if cur['ok'] else cur['error'][:300]), flush=True)
    if not cur['ok']:
        return
    hist = [cur['score']]
    for rnd in range(1, args.rounds + 1):
        if cur['exact']:
            break
        pool = [x for x in args.model.split(',') if x not in m.EXHAUSTED]   # comma list = fallback ladder
        if not pool:
            print('model exhausted'); break
        i = cur['i']
        prompt = '\n\n'.join([
            'You are tuning one C++ function so MSVC 2008 (x86, /O2) emits exactly the original machine code. The draft below '
            'matches the original for the first %d instructions and then diverges.' % i,
            '=== FIRST DIVERGENCE (target = original, cand = our draft; > marks the first differing instruction) ===\n'
            'TARGET:\n%s\nCANDIDATE:\n%s' % (window(cur['t'], i), window(cur['c'], i) if i < len(cur['c']) else '(candidate ends before this point: statements are missing)'),
            '=== DRAFT FILE ===\n' + best_text[-9000:], LEVERS, RULES,
            'Produce %d DIFFERENT variants (different levers).' % args.width])
        text = ''
        for live in pool:                                   # empty reply (free limit, timeout) -> next model
            m.ask(live, prompt, 'x')
            calls += 1
            text = getattr(m.TOOL, 'reply', '') or ''
            if text.strip():
                break
            print('  empty reply from %s, trying next' % live, flush=True)
        print('  reply %d chars' % len(text), flush=True)
        variants = [v for v in BLOCK.findall(text) if '#include' in v][:args.width]
        scored = []
        for k, v in enumerate(variants):
            if bad(v, best_text):
                continue
            r = run(v.strip() + '\n', 'r%d_%d' % (rnd, k))
            if r['ok']:
                scored.append((r['prefix_bytes'], r['prefix_insns'], v, r))
        if scored:
            top = max(scored, key=lambda s: (s[0], s[1]))
            if (top[0], top[1]) > (cur['prefix_bytes'], cur['prefix_insns']):
                best_text, cur = top[2].strip() + '\n', top[3]
        hist.append(cur['score'])
        print('round %d: %d variants, %d compiled, best %.1f%% (%d/%d insns)' % (
            rnd, len(variants), len(scored), 100 * cur['score'], cur['prefix_insns'], cur['total_insns']), flush=True)
    (out / 'best.cpp').write_text(best_text, encoding='utf-8')
    print('scores per round: %s | model calls: %d | best: %s' % (' '.join('%.1f' % (100 * s) for s in hist), calls, out / 'best.cpp'))
    print(pm.report(cur, addr))
    if cur['exact']:
        print('prefix_match says identical: now run agent_prove.py on best.cpp')


def main():
    if args.batch:
        for line in Path(args.batch).read_text().split():
            p = Path(line)
            print('#### %s' % p, flush=True)
            if re.fullmatch(r'[0-9a-f]{8}', p.parent.name) and p.read_text(errors='replace').startswith('// native-flags:'):
                evolve_one(p.parent.name, str(p))
    else:
        evolve_one(args.addr, args.file)


main()
