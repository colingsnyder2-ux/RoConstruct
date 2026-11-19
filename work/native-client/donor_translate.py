"""Donor-context translation (trial lane).  338 remaining functions turned byte-exact when compiled in the 2007
rbxgs donor context (complete, consistent headers); the native-header lanes fail mostly at compile because native
headers are incomplete.  This lane asks the model to translate a function's byte-exact mined analog into real C++
against the DONOR headers (rbxgs include tree searched first), with the placeholder->real name table from rename.py
when available, then loops compile-fix rounds with "where is this name declared" over the donor tree.
  python work/native-client/donor_translate.py --only FILE.json [--jobs 6] [--rounds 3] [--model claude:sonnet]"""
import argparse
import collections
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent
ap = argparse.ArgumentParser()
ap.add_argument('--only', default='', help='JSON list of addresses (default: every remaining non-library function)')
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--rename-json', default='', help='rename.py output with fake->real tables (optional)')
ap.add_argument('--jobs', type=int, default=6)
ap.add_argument('--rounds', type=int, default=3)
ap.add_argument('--model', default='codex:gpt-6.1-terra')   # owner 2026-11-17: Codex only
args, _ = ap.parse_known_args()
sys.argv = [sys.argv[0], '--limit', '0']
sys.path.insert(0, str(HERE))
src = (HERE / 'native_placeholder_llm.py').read_text(encoding='utf-8')
lane = {'__name__': 'donor_translate', '__file__': str(HERE / 'native_placeholder_llm.py')}
exec(compile(src[:src.index('if args.polish:')], str(HERE / 'native_placeholder_llm.py'), 'exec'), lane)
m, cg = lane['m'], lane['cg']
from roc import libs  # noqa: E402

ROOT = m.ROOT
OUT = HERE / 'donor-translate'
CODE = re.compile(r'```(?:cpp|c\+\+)\s*\n(.*?)```', re.S)
DONOR_DIRS = [str((libs.LIBS / i).resolve()) for i in libs.RECIPES['rbxgs']['include']
              if i != 'WINSDK' and (libs.LIBS / i).is_dir()]
APP_INC = Path(DONOR_DIRS[0])
ANY = str(APP_INC / 'util/Name.h')
reg = m.load_registry()
renames = json.loads(Path(args.rename_json).read_text()) if args.rename_json else {}
_INDEX = None
SKIP = set('RBX std boost G3D const char int void unsigned class struct this type error identifier'.split())


def where_declared(names):
    global _INDEX
    if _INDEX is None:
        _INDEX = collections.defaultdict(list)
        for root in DONOR_DIRS[:4]:
            for h in sorted(Path(root).rglob('*.h')):
                rel = h.relative_to(root).as_posix()
                try:
                    lines = h.read_text(errors='replace').splitlines()
                except OSError:
                    continue
                for i, line in enumerate(lines, 1):
                    if line.lstrip().startswith(('//', '#include')):
                        continue
                    for tok in set(re.findall(r'[A-Za-z_]\w{2,}', line)):
                        if len(_INDEX[tok]) < 3:
                            _INDEX[tok].append('%s:%d: %s' % (rel, i, line.strip()[:110]))
    return '\n'.join('%s -> %s' % (n, '\n      '.join(_INDEX[n]) if _INDEX.get(n) else 'NOT declared in the donor headers')
                     for n in names)


def class_header(sig):
    flat = re.sub(r'<[^<>]*>', '', sig or '')
    hit = re.search(r'__\w+ ((?:\w+::)*)(\w+)::~?\w+\(', flat)
    if not hit:
        return ''
    found = sorted(APP_INC.rglob(hit.group(2) + '.h'))
    return ('--- donor header %s (first 7 KB) ---\n%s\n' % (found[0].relative_to(APP_INC).as_posix(),
                                                           found[0].read_text(errors='replace')[:7000])) if found else ''


def judge(work, addr, code, needle, expect):
    if m.invented_externs(code) or m.OFFSET_HACK.search(code):
        return 'rejected', 'invented extern or raw offset arithmetic'
    if expect:
        cg.EXPECT[addr] = expect
    sym = cg.discover_symbol(work, [ANY], code, addr, needle, include_first=DONOR_DIRS, raw_includes=[])
    if not sym:
        return 'compile_failed', '\n'.join(cg.LAST_ERRORS.get(addr) or ['no symbol for %s emitted' % needle])
    status, detail = cg.gate_code(work, [ANY], code, {addr: sym}, include_first=DONOR_DIRS, raw_includes=[])
    return status.get(addr, 'missing'), detail or ''


def one(addr):
    row = reg.get(addr) or {}
    analog = ROOT / 'src/2008-06' / (addr + '.cpp')
    if not analog.is_file():
        return addr, 'no-analog', ''
    name, sig = row.get('name') or '', row.get('signature') or ''
    named = bool(name) and not name.startswith(('func_', 'sub_', '?sub_')) and bool(sig)
    leaf = re.sub(r'\W', '', re.sub(r'<[^<>]*>', '', sig.split('(')[0]).split()[-1].rsplit('::', 1)[-1]) if named else ''
    needle = leaf or ('sub_' + addr)
    table = ''
    if addr in renames and renames[addr].get('renamed'):
        rows = []
        for fake, real in renames[addr]['renamed'].items():
            target = (renames[addr].get('refs') or {}).get(fake)
            rows.append('%s  ->  %s' % (fake, (reg.get(target) or {}).get('signature') or real))
        table = '--- PLACEHOLDER -> REAL IDENTITY (from the original relocations) ---\n' + '\n'.join(rows) + '\n'
    prompt = (
        'You translate one function of the 2008 Roblox client into real C++ against the 2007 rbxgs DONOR headers '
        '(include paths like "v8world/World.h", "v8datamodel/PartInstance.h", "util/Name.h", <G3D/Vector3.h>, boost).\n'
        + ('Its real signature: %s\n' % sig if named else 'It has no known name: define it as a function or member named sub_%s.\n' % addr)
        + 'The REFERENCE ANALOG below compiles to EXACTLY the original bytes but uses placeholder names and stand-in '
        'structs. Keep every statement, order, type width and temporary; only replace stand-in structs with the real '
        'donor classes (members by the SAME offset/meaning), placeholder callees with real functions, and give the real '
        'signature. Never define your own classes or externs; no raw pointer+offset arithmetic; no asm. Reply with one '
        '```cpp block containing the needed #include lines and the function.\n'
        + table + class_header(sig) + '--- REFERENCE ANALOG (byte-exact) ---\n' + analog.read_text(errors='replace')[:6500]
        + '\n--- ORIGINAL ASSEMBLY ---\n' + lane['target_asm'](addr)[:4500])
    work = OUT / addr
    work.mkdir(parents=True, exist_ok=True)
    reply, status, detail = '', 'no-reply', ''
    for rnd in range(args.rounds + 1):
        ask = prompt if not rnd else (prompt + '\n--- YOUR PREVIOUS ANSWER ---\n' + reply[-3500:] +
                                      '\nIt does NOT compile. Errors:\n' + detail[:1500] + '\n\nWhere those names are '
                                      'declared in the donor headers:\n' + where_declared(
                                          [n for n in dict.fromkeys(t for q in re.findall(r"'([^']+)'", detail)
                                                                    for t in re.findall(r'[A-Za-z_]\w{2,}', q)) if n not in SKIP][:10])
                                      + '\nFix only what the errors need; reply with the complete corrected block.\n')
        m.ask(args.model if rnd != 1 or not args.model.startswith('claude:') else 'claude:haiku', ask, 'sub_' + addr)
        new = getattr(m.TOOL, 'reply', '') or ''
        code = CODE.findall(new) or ([new] if '#include' in new else [])     # the Codex CLI strips code fences
        if not code:
            break
        reply = new
        try:
            status, detail = judge(work, addr, code[-1], needle, name if named else '')
        except Exception as error:                               # noqa: BLE001
            status, detail = 'harness-error', repr(error)
        (work / ('try%d.cpp' % rnd)).write_text(reply, encoding='utf-8')
        (work / ('err%d.txt' % rnd)).write_text('%s\n%s' % (status, detail), encoding='utf-8', errors='replace')
        if status != 'compile_failed':
            break
    if not any(work.iterdir()):                                # no reply at all (provider down): leave the target untried
        work.rmdir()
    if status == 'inactive_exact':
        PENDING[addr] = str(work)
        (OUT / 'pending.json').write_text(json.dumps(PENDING, indent=1))
    return addr, status, (detail.strip().splitlines() or [''])[0][:100]


PENDING = json.loads((OUT / 'pending.json').read_text()) if (OUT / 'pending.json').is_file() else {}
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
HDR = (ROOT / 'rebuild/2008-06/native-headers').as_posix()


def flush():
    """Write byte-proved answers as native files (never while a census runs): the probe that passed the gate, with its
    include roots made repo-relative ({headers} token), donor roots first as compiled."""
    import time
    while (HERE / 'prove-out/CENSUS.lock').is_file():
        time.sleep(30)
    written = []
    for addr, work in sorted(PENDING.items()):
        probe = Path(work) / 'probe.cpp'
        tu = CLASSES / ('DonorCtx_%s.cpp' % addr)
        if tu.is_file() or not probe.is_file():
            continue
        first, rest = probe.read_text(errors='replace').split('\n', 1)
        flags = []
        for tok in first[len('// native-flags:'):].split():
            if tok.startswith('/I'):
                q = Path(tok[2:]).as_posix()
                if q.lower() == HDR.lower():
                    q = '{headers}'
                elif q.lower().startswith(ROOT.as_posix().lower()):
                    q = '{headers}/../../..' + q[len(ROOT.as_posix()):]
                flags.append('/I' + q)
            else:
                flags.append(tok)
        tu.write_text('// native-flags: %s\n// %s: translated from its byte-exact mined analog against the 2007 rbxgs donor headers '
                      '(donor_translate.py); byte-proved standalone\n%s' % (' '.join(flags), addr, rest.lstrip('\n')))
        written.append(tu.relative_to(ROOT).as_posix())
    src = HERE / 'class-lane-new-sources.json'
    lst = json.loads(src.read_text()) if src.is_file() else []
    src.write_text(json.dumps(lst + [w for w in written if w not in lst], indent=1))
    print('wrote %d DonorCtx files' % len(written), flush=True)


if args.only:
    todo = json.loads(Path(args.only).read_text())
else:
    cl = json.loads((HERE / 'remaining-classified.json').read_text())
    from roc import integration_site
    exact = {a for a, v in integration_site.inactive_code(ROOT).items() if v[1]}
    body = set(json.loads((HERE / 'ambiguous-candidates.json').read_text())) if (HERE / 'ambiguous-candidates.json').is_file() else set()
    donor = {a for v in json.loads((HERE / 'creator-partition/donor-units.json').read_text()).values() for a in v}
    todo = sorted((a for a, v in cl.items() if a not in exact and a not in body and a not in donor and a not in PENDING
                   and v.get('bucket') != 'vendor-library' and 24 <= v['size'] <= 2048
                   and not 0x7e0000 <= int(a, 16) < 0x800000        # initializer/atexit thunks, not authored functions
                   and not (OUT / a).is_dir()), key=lambda a: cl[a]['size'])
todo = todo[:args.limit or None]
if todo and not args.model.startswith(('claude:', 'opencode')):   # OpenCode goes through native_llm's desktop CLI path              # preflight: a spent quota must not burn the target list
    from roc import providers
    try:
        providers.generate(args.model, 'Reply with exactly: ok', {'allow_cloud': True, 'timeout': 120, 'max_tokens': 16})
    except providers.ProviderError as error:
        flush()
        sys.exit('RESULT donor-context translation: %s unavailable (%s); nothing attempted' % (args.model, str(error)[:120]))
print('donor-context translation targets: %d' % len(todo), flush=True)
counts = collections.Counter()
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, status, detail in pool.map(one, todo):
        counts[status] += 1
        print(addr, status, detail, flush=True)
print('RESULT donor-context translation: %s' % dict(counts), flush=True)
flush()
