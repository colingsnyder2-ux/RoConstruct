"""Automated recovery loop for boot stubs (LLM workers). For each target function address:
  packet (annotated 2008 disassembly + class header excerpt + donor/OpenRBX analog by Class::method name + a sibling native source)
  -> headless Sonnet (`claude -p`) drafts native-classes/AutoRecover_<ADDR>.cpp -> native_check_runner compile -> compiler errors fed
  back (<= --tries) -> exact_check ratio recorded. Output: work/donorfree-route/auto/results.json (+ packets). A compiled draft is NOT
  proof; boot.py links it. Only new files are written (never existing sources/headers), so up to 5 workers can run side by side.
usage: python autorecover.py ADDR|@file [...] [--workers N<=5] [--tries 3] [--model sonnet]
Under the roc gui (job kind boot_recover, env ROC_GUI_EVENTS) every worker shows up as a slot on the Workers tab."""
import json, re, subprocess, sys, os, glob, shutil, time, queue, threading, concurrent.futures as cf
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
H = ROOT / 'work/donorfree-route'
OUT = H / 'auto'
OUT.mkdir(exist_ok=True)
NC = ROOT / 'rebuild/2008-06/native-classes'
names = {int(a, 16): r for a, r in json.load(open(ROOT / 'work/native-client/layout/function-files.json')).items()}
SORTED_ADDRS = sorted(names)


def native_defined():
    """Addresses of functions already defined by ANY compiled native object (trial objects + extra objects), by mangled name via the
    COFF symbol tables (the link map is not enough: /OPT:REF drops unreferenced functions), plus addresses with an AutoRecover draft.
    Cached in auto/defined_cache.json per object-set fingerprint."""
    sys.path.insert(0, str(ROOT))
    from roc.rebuild import coff_externals
    objs = []
    try:
        log = (ROOT / 'rebuild/2008-06/out/donorfree/runner-all-native.log').read_text().strip().splitlines()[-1]
        rows = json.loads(Path(json.loads(log)['results']).read_text())
        objs += [r['object'] for r in (rows if isinstance(rows, list) else rows['results']) if r.get('status') == 'complete']
    except Exception:
        pass
    ex = H / 'extra/objs.txt'
    if ex.exists():
        objs += [l.strip() for l in ex.read_text().splitlines() if l.strip()]
    objs = [o for o in dict.fromkeys(objs) if os.path.exists(o)]
    fp = '%d:%d' % (len(objs), int(max((os.path.getmtime(o) for o in objs), default=0)))
    cache = OUT / 'defined_cache.json'
    defined = None
    if cache.exists():
        c = json.loads(cache.read_text())
        if c.get('fp') == fp:
            defined = set(c['symbols'])
    if defined is None:
        defined = set()
        for o in objs:
            try:
                for name, is_def in coff_externals(Path(o).read_bytes()).items():
                    if is_def:
                        defined.add(name)
            except Exception:
                pass
        cache.write_text(json.dumps({'fp': fp, 'symbols': sorted(defined)}))
    out = {a for a, r in names.items() if (r.get('name') or '') in defined}
    out |= {int(p.stem.split('_')[1], 16) for p in NC.glob('AutoRecover_*.cpp')}
    out |= native_by_address()
    return out


def native_by_address():
    """addresses a non-AutoRecover native file already defines under its real name (placeholder func_ names in
    function-files.json hide them from the symbol match): a `// <8 hex>` header comment, an `fn_<8 hex>(...) {`
    definition, or a file named *_<8 hex>.cpp. 2026-11-24: 130 of 846 LLM-only targets were like this."""
    out = set()
    for p in NC.glob('*.cpp'):
        if p.name.startswith('AutoRecover_'):
            continue
        try:
            t = p.read_text(errors='replace')
        except OSError:
            continue
        out |= {int(a, 16) for a in re.findall(r'^\s*//\s*(?:0x)?([0-9a-f]{8})\b', t, re.M)}
        out |= {int(a, 16) for a in re.findall(r'\bfn_([0-9a-f]{8})\s*\([^;{]*\)\s*\{', t)}
        m = re.search(r'_([0-9a-f]{8})\.cpp$', p.name)
        if m:
            out.add(int(m.group(1), 16))
    return out


NATIVE = native_defined()
NATIVE_ADDR = native_by_address()   # also blocks retries and redrafts of these
UN = str(ROOT / 'tools/msvc800sp1/VC/bin/undname.exe')
args = sys.argv[1:]
BS = chr(92)
NL = chr(10)
FENCE = chr(96) * 3


def opt(n, d):
    if n in args:
        i = args.index(n)
        v = args[i + 1]
        del args[i:i + 2]
        return v
    return d


MIX = opt('--mix', '')   # e.g. sonnet:3,codex:2 -> slots 0-2 headless Sonnet, slots 3-4 Codex (gpt-6.1-terra, medium effort)
BACKENDS = []
for part in [p for p in MIX.split(',') if p]:
    name_, _, count_ = part.rpartition(':')   # backend[:model]:count, e.g. sonnet:3,codex:2,opencode:opencode/big-pickle:2
    BACKENDS += [name_.strip()] * int(count_ or 1)
_workers_arg = int(opt('--workers', 3))   # always consume the flag; --mix decides the count when given
WORKERS = max(1, min(10, len(BACKENDS) if BACKENDS else _workers_arg))   # owner cap: 10 (API only)
TRIES = int(opt('--tries', 3))
MODEL = opt('--model', 'sonnet')
CODEX_MODEL = opt('--codex-model', 'gpt-6.2-sol')   # owner 2026-11-24: Sol is Codex's coding model (Terra: visual/computer use)
if MODEL.startswith('api:') and not BACKENDS:
    # --model api:<model> means the API backend for every slot (it used to silently run `claude -p --model api:...` on the
    # user's CLI credits, which failed with "issue with the selected model")
    BACKENDS = [MODEL] * WORKERS
if os.environ.get('ROC_API_ONLY') == '1' or MODEL.startswith('api:'):
    _cli = [b for b in BACKENDS if not b.startswith('api:')]
    if _cli:
        sys.exit('refusing non-API backends %s (API-only run)' % sorted(set(_cli)))
BACKENDS = (BACKENDS + ['sonnet'] * WORKERS)[:WORKERS]
FORCE = '--force' in args
RETRY_FAILED = '--retry-failed' in args
if RETRY_FAILED:
    args.remove('--retry-failed')
if FORCE:
    args.remove('--force')
# default: no relink/probe at the end of a batch (the cycle job links and probes every round anyway; a second link per
# worker job only queued behind the cycle's link lock). --link restores the old behaviour.
NOLINK = '--link' not in args
for _f in ('--no-link', '--link'):
    if _f in args:
        args.remove(_f)
WATCH = '--watch' in args   # keep running: pull new targets from auto/worker_queue.txt + auto/stub_hit_targets.txt
QUEUES = opt('--queues', 'stub_hit_targets.txt,worker_queue.txt').split(',')   # hot (runtime stub hits) first   # per-milestone pools: their own files
if WATCH:
    args.remove('--watch')
SNOWBALL = '--snowball' in args
if SNOWBALL:
    args.remove('--snowball')
MAXN = int(opt('--max', 60))
targets = []
for a_ in args:
    if a_.startswith('@'):
        targets += [int(x.split()[0], 16) for x in open(a_[1:]) if x.strip() and not x.startswith('#')]
    else:
        targets.append(int(a_, 16))

SLOTS = queue.Queue()
for _i in range(WORKERS):
    SLOTS.put(_i)
_emit_lock = threading.Lock()


_metric_lock = threading.Lock()


def metric(row):
    with _metric_lock, open(OUT / 'metrics.jsonl', 'a') as mf:
        mf.write(json.dumps(dict({'ts': int(time.time())}, **row)) + NL)


def emit(event, **fields):
    """ROC_EVENT lines are what the roc gui Workers tab consumes (job kind boot_recover); plain lines otherwise."""
    with _emit_lock:
        if os.environ.get('ROC_GUI_EVENTS'):
            print('ROC_EVENT ' + json.dumps(dict(event=event, **fields)), flush=True)
        else:
            print('[w%s] %s' % (fields.get('slot', '-'), fields.get('message') or fields.get('file') or event), flush=True)


def run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT, **kw)


_STARTS = []
_DIS = {}


def disasm(addr):
    """whole function (up to the next known function start, cap 0x2000 bytes), padding squeezed to save tokens."""
    if addr in _DIS:
        return _DIS[addr]
    if not _STARTS:
        _STARTS.extend(sorted(names))
    import bisect
    i = bisect.bisect_right(_STARTS, addr)
    size = min((_STARTS[i] - addr) if i < len(_STARTS) else 0x700, 0x2000) or 0x700
    out = run([sys.executable, str(H / 'annot_dis.py'), '%08x' % addr, '-n', hex(size)]).stdout
    res = []
    for l in out.splitlines():
        if l.rstrip().endswith('int3'):
            break
        res.append(re.sub(r' {2,}', ' ', l.rstrip()))
    _DIS[addr] = NL.join(res)
    return _DIS[addr]


def class_of(sym):
    t = re.search(r'is :- "(.*)"', run([UN, sym]).stdout)
    if not t:
        return None, None, ''
    full = t.group(1)
    mm = re.search(r'__\w+ ([A-Za-z0-9_:]+)::(~?[A-Za-z0-9_]+)\(', full)
    return (mm.group(1), mm.group(2), full) if mm else (None, None, full)


def header_excerpt(cls):
    short = cls.split('::')[-1]
    for h in glob.glob(str(ROOT / 'rebuild/2008-06/native-headers/**/*.h'), recursive=True):
        hp = h.replace(BS, '/')
        if any(x in hp for x in ('profile', 'inline', 'writer', 'mfc-', 'std-', 'pv-parent')):
            continue
        try:
            t = open(h, errors='ignore').read()
        except Exception:
            continue
        m = re.search(r'\b(?:class|struct)\s+(?:__declspec\(novtable\)\s+)?' + re.escape(short) + r'\b[^;{]*\{', t)
        if m:
            return hp.split('native-headers/')[1], t[max(0, m.start() - 200): m.start() + 5000]
    return None, ''


def analogs(cls, meth):
    if not cls or not meth:
        return ''
    out = []
    pat = re.compile(r'\b' + re.escape(cls.split('::')[-1]) + r'::' + re.escape(meth) + r'\s*\(')
    for root in ('tools/openrbx/Client', 'tools/rbxgs/Client/App', 'tools/rbxgs/Client/win'):
        for f in glob.glob(str(ROOT / root / '**/*.cpp'), recursive=True)[:4000]:
            try:
                t = open(f, errors='ignore').read()
            except Exception:
                continue
            m = pat.search(t)
            if m:
                out.append('// ---- %s%s%s' % (f.replace(str(ROOT) + os.sep, '').replace(BS, '/'), NL, t[max(0, m.start() - 100): m.start() + 3500]))
                if len(out) >= 2:
                    return (NL * 2).join(out)
    return (NL * 2).join(out)


def sibling(cls):
    short = (cls or '').split('::')[-1]
    if not short:
        return None, ''
    for f in sorted(glob.glob(str(NC / ('*' + short + '*.cpp'))))[:1]:
        return Path(f).name, open(f, errors='ignore').read()[:3500]
    return None, ''



_EXE = {}


def ret_bytes(addr):
    """bytes popped by the first `ret` after addr in the original exe (None if not found): 0 for cdecl/void-arg, N for stdcall/thiscall."""
    if not _EXE:
        import pefile, capstone
        sys.path.insert(0, str(ROOT))
        from roc import clients
        data = clients.exe_path('2008-06', clients.load()['2008-06']).read_bytes()
        _EXE.update(data=data, pe=pefile.PE(data=data), md=capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32))
    try:
        o = _EXE['pe'].get_offset_from_rva(addr - 0x400000)
    except Exception:
        return None
    for ins in _EXE['md'].disasm(_EXE['data'][o:o + 0x500], addr):
        if ins.mnemonic == 'ret':
            return int(ins.op_str, 16) if ins.op_str else 0
    return None


try:   # only unnamed functions: a named one (mangled in function-files) is already identified in the disassembly comments
    NATIVE_IDX = {a: e for a, e in json.loads((OUT / 'native_index.json').read_text()).items()
                  if (names.get(int(a, 16), {}).get('name') or 'func_').startswith('func_')}
except Exception:
    NATIVE_IDX = {}


def native_callees(dis_text):
    """callee addresses with a documented native definition (auto/native_index.json from native_index.py)."""
    out = []
    for a in dict.fromkeys(re.findall(r'call +0x([0-9a-f]{6,8})', dis_text)):
        e = NATIVE_IDX.get(a.zfill(8))
        if e:
            out.append('0x%s: %s   (defined in %s; headers %s)' % (a.zfill(8), e['signature'], e['file'], ', '.join(e['headers'][:3])))
    return NL.join(out) or 'none'


def target_abi(dis_text):
    """the target's own convention: ecx read before written -> thiscall; ret N -> N bytes of stack args."""
    ecx_this = False
    for l in dis_text.splitlines()[:40]:
        p = l.split(None, 2)
        if len(p) < 3:
            continue
        ops = p[2].split(';')[0]
        dst = ops.split(',')[0]
        if 'ecx' in ops.split(',', 1)[-1] and not dst.strip().startswith('ecx') or (p[1] in ('push', 'test', 'cmp') and 'ecx' in ops):
            ecx_this = True
            break
        if dst.strip().startswith('ecx') or p[1] == 'call':
            break
    m = re.findall(r'\bret[ \t]+(0x[0-9a-f]+|\d+)[ \t]*$', dis_text, re.M)
    n = int(m[0], 0) if m else 0
    k = n // 4
    if ecx_this:
        return ('__thiscall, %d stack argument dword(s) (ret %d). If unnamed, declare it exactly as extern "C" <ret> __fastcall '
                'fn_<addr>(<Class>* self, int unusedEdx%s)' % (k, n, ''.join(', <arg%d>' % i for i in range(1, k + 1))))
    return '__stdcall, %d argument dword(s) (ret %d)' % (k, n) if n else '__cdecl (plain ret; caller pops)'


def callee_conventions(dis_text):
    """For every direct call to a function without a known name (func_XXXXXXXX) in the target's disassembly: infer the convention from
    the caller (ecx loaded just before the call = thiscall; pushes since the previous call = argument count) and from the callee's ret N,
    and print the exact extern declaration to use. This is what keeps separately drafted files linkable."""
    lines = dis_text.splitlines()
    out, seen = [], set()
    pushes = 0
    ecx_set = False
    for line in lines:
        parts = line.split(None, 2)
        if len(parts) < 2:
            continue
        mn = parts[1]
        ops = parts[2].split(';')[0].strip() if len(parts) > 2 else ''
        if mn == 'push':
            pushes += 1
        elif mn in ('mov', 'lea') and ops.startswith('ecx,'):
            ecx_set = True
        elif mn == 'call':
            m = re.match(r'0x([0-9a-f]+)$', ops)
            if m:
                t = int(m.group(1), 16)
                nm = names.get(t, {}).get('name') or ''
                if t not in seen and (not nm or nm.startswith('func_')) and ('%08x' % t) not in NATIVE_IDX:   # natives get their real signature instead
                    seen.add(t)
                    rb = ret_bytes(t)
                    nargs = (rb // 4) if rb else pushes
                    if ecx_set:
                        extra = ', '.join('int a%d' % i for i in range(1, nargs + 1))
                        out.append('fn_%08x: __thiscall member helper (ecx = object) taking %d stack arg(s): extern "C" int __fastcall fn_%08x(void* self, int unusedEdx%s);' % (t, nargs, t, (', ' + extra) if extra else ''))
                    else:
                        conv = 'stdcall (callee pops %d)' % rb if rb else 'cdecl (caller pops)'
                        args = ', '.join('int a%d' % i for i in range(1, nargs + 1)) or 'void'
                        decl = ('extern "C" int __stdcall fn_%08x(%s);' if rb else 'extern "C" int fn_%08x(%s);') % (t, args)
                        out.append('fn_%08x: %s, %d arg(s): %s' % (t, conv, nargs, decl))
            pushes = 0
            ecx_set = False
    return NL.join(out)


PROMPT = '''You are recovering ONE function of the 2008 Roblox client (MSVC 2008, /O2) as native C++ source, matching the original machine code.
Target: {name} at 0x{addr:08x}   (demangled: {demangled})
Target ABI from its own code: {tabi}
Rules: output ONE C++ source file in a single ```cpp fenced block, nothing else. First line exactly: {flags}
Define ONLY this function (plus file-local helpers it needs). Use only the native headers shown / under rebuild/2008-06/native-headers (include paths relative to native-headers, e.g. "v8datamodel/DataModel.h"); do NOT include tools/rbxgs or native-donor-2007 headers. Never use __emit, byte blobs or inline asm. Mark guesses with a comment starting "// INFERRED:". Match the disassembly's call order, member accesses and control flow; callees are named in the disassembly comments after ';'. Unknown callees (func_XXXXXXXX) and, when the target itself is unnamed (func_XXXXXXXX), the target: use ONE fixed naming convention so separately drafted files link: extern "C" linkage and the name fn_<8 hex digit address> (for example extern "C" void fn_0045b3a0(CRobloxWnd* self);). C linkage makes the symbol independent of the parameter list. For a __thiscall member helper declare it __fastcall with the object pointer first and a dummy int second (ecx, edx): extern "C" int __fastcall fn_0045b3a0(CRobloxWnd* self, int unusedEdx, int arg);. Plain cdecl/stdcall helpers keep their own convention. Never invent other names for unknown callees. NEVER define a class or struct that already exists in the native headers (RBX::Instance, ModelInstance, PVInstance, RootInstance, Name, Descriptor, BoundProp, ...): a copy exports constructors, destructors and vtables under the real names and breaks the link. Include the real header; for a file-local helper type use a unique name such as Local_<8 hex address>. A named target (mangled name given above) is defined with its real class-member name instead.
## Annotated 2008 disassembly of the target
{dis}
## Callee conventions inferred from the disassembly (use these declarations verbatim; change the return/arg types to what the code needs, never the convention or name)
{conv}
## Callees that already have native C++ definitions (call these real functions through their headers instead of declaring fn_ externs for them)
{natives}
## Class header excerpt ({hdrname})
{hdr}
{mined}## Analog source from the 2007 client/donor (evidence only; the 2008 code differs)
{analog}
## A sibling native source (style example)
// {sibname}
{sib}
{feedback}'''



API_SPEND = OUT / 'api_spend.json'
_spend_lock = threading.Lock()
API_BUDGET = float(os.environ.get('ROC_API_BUDGET_USD', '93.5'))      # owner 2026-11-24: spend the last ~$2 of API credit ($91.53 recorded), then CLI
# USD per million tokens (input, output), Anthropic list prices 2026-11. Cache writes bill 1.25x input, cache reads 0.1x input.
API_PRICES = {'claude-sonnet-5-5': (2.0, 10.0), 'claude-opus-5-5': (4.0, 20.0)}


def api_cost(model, u):
    pin, pout = API_PRICES.get(model, (4.0, 20.0))   # unknown model: charge the higher (Opus) price
    return ((u.get('input_tokens') or 0) * pin + (u.get('cache_creation_input_tokens') or 0) * pin * 1.25 +
            (u.get('cache_read_input_tokens') or 0) * pin * 0.1 + (u.get('output_tokens') or 0) * pout) / 1e6


def api_spent():
    try:
        return json.loads(API_SPEND.read_text()).get('usd', 0.0)
    except Exception:
        return 0.0


def api_add(usd, model):
    with _spend_lock:
        d = {}
        try:
            d = json.loads(API_SPEND.read_text())
        except Exception:
            pass
        d['usd'] = round(d.get('usd', 0.0) + usd, 4)
        d['calls'] = d.get('calls', 0) + 1
        d.setdefault('by_model', {})[model] = round(d.get('by_model', {}).get(model, 0.0) + usd, 4)   # since 2026-11-24 fix
        API_SPEND.write_text(json.dumps(d))
        return d['usd']


def api_exhausted(mark=None):
    flag = OUT / 'api_exhausted.flag'
    if mark:
        flag.write_text(mark)
    return flag.exists() or api_spent() >= API_BUDGET

CODEX_DOWN_UNTIL = [0.0]


def ask_llm(prompt, slot, addr, cache_prefix=None):
    """Run one draft on this slot's backend and return its text. Backends: sonnet (headless claude -p, no tools) or codex
    (codex exec, read-only sandbox, final message captured with -o)."""
    if BACKENDS[slot] == 'codex':
        last = OUT / ('codex_%08x.txt' % addr)
        if last.exists():
            last.unlink()
        if time.time() > CODEX_DOWN_UNTIL[0]:
            r = subprocess.run([shutil.which('codex') or 'codex', 'exec', '-s', 'read-only', '--skip-git-repo-check', '--ephemeral',
                                '-m', CODEX_MODEL, '-c', 'model_reasoning_effort="medium"', '-C', str(ROOT), '-o', str(last), '-'],
                               input=prompt, text=True, encoding='utf-8', errors='replace', capture_output=True, cwd=ROOT, timeout=1500)
            text = last.read_text(encoding='utf-8', errors='replace') if last.exists() else ''
            if text.strip():
                return text
            if 'usage limit' in (r.stdout + r.stderr):   # quota spent: stop calling codex for 30 min, use Sonnet meanwhile
                CODEX_DOWN_UNTIL[0] = time.time() + 1800
                emit('log', slot=slot, message='codex usage limit reached; codex slots pause for 30 min')
            elif r.returncode:
                emit('log', slot=slot, message='codex exit %s: %s' % (r.returncode, (r.stderr or r.stdout)[-200:].strip()))
        else:
            time.sleep(60)   # quota pause: don't spin through the queue
    if BACKENDS[slot].startswith('oc:'):
        # free OpenCode models through the signed-in desktop CLI, exactly as work/native-client/native_llm.py does
        import tempfile
        cli = Path(os.environ.get('APPDATA', '')) / 'ai.opencode.desktop/cli/2.2.6-x64/opencode-cli.exe'
        with tempfile.TemporaryDirectory(prefix='roc-auto-') as folder:
            task = Path(folder) / 'task.txt'
            task.write_text(prompt, encoding='utf-8')
            try:
                run_ = subprocess.run([str(cli), 'run', '-m', BACKENDS[slot][3:], '--format', 'json', '--file', str(task),
                                       'Follow the attached task exactly. Return only the requested code in one cpp fenced block. Do not use tools.'],
                                      cwd=folder, capture_output=True, text=True, encoding='utf-8', errors='replace', timeout=600)
                events = []
                for line_ in run_.stdout.splitlines():
                    try:
                        events.append(json.loads(line_))
                    except ValueError:
                        pass
                text = ''.join(e['part'].get('text', '') for e in events if isinstance(e, dict) and e.get('type') == 'text' and isinstance(e.get('part'), dict))
                if text.strip():
                    return text
                emit('log', slot=slot, message='%s returned no text (free limit/timeout); falling back to Sonnet for this draft' % BACKENDS[slot])
            except subprocess.TimeoutExpired:
                emit('log', slot=slot, message='%s timed out; falling back to Sonnet for this draft' % BACKENDS[slot])
    elif BACKENDS[slot].startswith('api:'):
        # Anthropic Messages API (bills API credit, incl. promotional credit): key from env ANTHROPIC_API_KEY only, never logged.
        key = os.environ.get('ANTHROPIC_API_KEY')
        if not key and os.name == 'nt':   # dashboard started before the key was set: read the user environment (never logged)
            try:
                import winreg
                with winreg.OpenKey(winreg.HKEY_CURRENT_USER, 'Environment') as rk:
                    key = winreg.QueryValueEx(rk, 'ANTHROPIC_API_KEY')[0]
                    os.environ['ANTHROPIC_API_KEY'] = key
            except OSError:
                key = None
        if not key:
            (OUT / 'STOP').write_text('no ANTHROPIC_API_KEY')   # stop the whole job instead of churning through targets
            raise RuntimeError('ANTHROPIC_API_KEY not available to this process')
        if key and api_exhausted():
            if os.environ.get('ROC_API_THEN_CLI', '1') == '1':   # owner 2026-11-24: API spent -> this slot continues on `claude -p` (CLI)
                emit('log', slot=slot, message='API budget/credit spent ($%.2f of $%.2f); slot %d switches to claude -p CLI' % (api_spent(), API_BUDGET, slot))
                BACKENDS[slot] = 'sonnet'
                return ask_llm(prompt, slot, addr)
            emit('log', slot=slot, message='API budget/credit spent ($%.2f of $%.0f); stopping draft' % (api_spent(), API_BUDGET))
        elif key:
            import urllib.request, urllib.error
            # max_tokens covers adaptive thinking too (on by default, effort high on Sonnet 5.5): at 8000 big targets spent
            # it all on thinking and returned no or a truncated code block
            model_ = BACKENDS[slot][4:] or 'claude-sonnet-5-5'
            # effort medium (Opus 5.5's default): at Sonnet 5.5's default high, diff-retry drafts sometimes thought for all
            # 16000 tokens and returned no code ($0.17 each)
            body = json.dumps({'model': model_, 'max_tokens': 16000, 'output_config': {'effort': os.environ.get('ROC_API_EFFORT', 'medium')},
                               'messages': [{'role': 'user', 'content': (
                                   [{'type': 'text', 'text': cache_prefix, 'cache_control': {'type': 'ephemeral'}},
                                    {'type': 'text', 'text': prompt[len(cache_prefix):] or '.'}]
                                   if cache_prefix and prompt.startswith(cache_prefix) and len(cache_prefix) > 6000 else prompt)}]}).encode()
            req = urllib.request.Request('https://api.anthropic.com/v1/messages', data=body, headers={
                'x-api-key': key, 'anthropic-version': '2023-06-01', 'content-type': 'application/json'})
            try:
                data = json.loads(urllib.request.urlopen(req, timeout=600).read())
                text = ''.join(c.get('text', '') for c in data.get('content', []) if c.get('type') == 'text')
                u = data.get('usage', {})
                usd = api_cost(model_, u)
                spent = api_add(usd, model_)
                if spent >= API_BUDGET:
                    api_exhausted('budget')
                    emit('log', slot=slot, message='API budget reached ($%.2f); remaining drafts stop' % spent)
                metric({'kind': 'api_usage', 'addr': '%08x' % addr, 'model': model_, 'in': u.get('input_tokens'), 'out': u.get('output_tokens'),
                        'cache_w': u.get('cache_creation_input_tokens'), 'cache_r': u.get('cache_read_input_tokens'),
                        'usd': round(usd, 5), 'stop': data.get('stop_reason')})
                if data.get('stop_reason') == 'max_tokens':
                    emit('log', slot=slot, message='%s hit max_tokens on %08x (answer truncated)' % (model_, addr))
                if text.strip():
                    return text
            except urllib.error.HTTPError as e:
                body = ''
                try:
                    body = e.read().decode('utf-8', 'replace').lower()
                except Exception:
                    pass
                if e.code == 402 or 'credit' in body or 'billing' in body:
                    api_exhausted('credit')
                emit('log', slot=slot, message='anthropic api http %s%s; stopping draft' % (e.code, ' (credit/billing)' if 'credit' in body or 'billing' in body else ''))
            except Exception as e:
                emit('log', slot=slot, message='anthropic api failed (%s); stopping draft' % type(e).__name__)
        else:
            emit('log', slot=slot, message='ANTHROPIC_API_KEY not set; stopping draft')
        return ''
    elif BACKENDS[slot] not in ('sonnet', 'codex'):
        # any model the repo's provider layer knows (free ones: opencode:opencode/big-pickle, opencode:opencode/beam-free via the
        # signed-in OpenCode CLI; nvidia:nvidia/nemotron-3-ultra-550b-a55b with NVIDIA_API_KEY; local:<ollama model>)
        sys.path.insert(0, str(ROOT))
        from roc import providers
        try:
            out = providers.generate(BACKENDS[slot], prompt, {'allow_cloud': True, 'timeout': 900, 'max_tokens': 8000})
            return out if isinstance(out, str) else str(getattr(out, 'text', None) or (out.get('text') if isinstance(out, dict) else out))
        except Exception as e:
            emit('log', slot=slot, message='%s failed (%s)' % (BACKENDS[slot], str(e)[:120]))
    if BACKENDS[slot] != 'sonnet':   # owner rule: API/Codex slots never fall back to `claude -p` (CLI credits)
        emit('log', slot=slot, message='%s returned no draft for %08x (no CLI fallback)' % (BACKENDS[slot], addr))
        return ''
    # slim CLI call (2026-11-24): own short system prompt, no MCP servers, no settings/hooks, run outside the repo so
    # CLAUDE.md is not loaded: ~1K tokens of overhead per call instead of ~25K. The packet carries all context.
    cli_dir = OUT / 'cli_cwd'
    cli_dir.mkdir(exist_ok=True)
    cmd = [shutil.which('claude') or shutil.which('claude.cmd') or 'claude', '-p', '--model', MODEL, '--tools', '', '--no-session-persistence']
    if os.environ.get('ROC_CLI_FULL') == '1':   # A/B test only: the old full Claude Code context (~25K tokens per call)
        cli_dir = ROOT
    else:
        cmd += ['--strict-mcp-config', '--setting-sources', '',
                '--system-prompt', 'You recover C++ source for one function of an MSVC 2008 binary. Follow the task exactly; '
                                   'answer with one cpp fenced code block and nothing else.',
                '--exclude-dynamic-system-prompt-sections', '--effort', os.environ.get('ROC_CLI_EFFORT', 'medium')]
    r = subprocess.run(cmd,
                       input=prompt, capture_output=True, text=True, encoding='utf-8', errors='replace', cwd=cli_dir, timeout=900,
                       # CLI login, not the API key: with ANTHROPIC_API_KEY set, `claude -p` would bill API credit
                       env={k: v for k, v in os.environ.items() if k not in ('ANTHROPIC_API_KEY', 'ANTHROPIC_AUTH_TOKEN')})
    return r.stdout


def crash_context(addr):
    """runtime crash evidence written by crashfix.py (auto/crash_<addr>.txt) plus the current draft, so the redraft fixes the bug."""
    f = OUT / ('crash_%08x.txt' % addr)
    if not f.exists():
        return ''
    cur = NC / ('AutoRecover_%08x.cpp' % addr)
    prev = ('## Previous draft' + NL + FENCE + 'cpp' + NL + cur.read_text(errors='replace')[:8000] + NL + FENCE + NL) if cur.exists() else ''
    return '## RUNTIME CRASH in the previous draft of this function (fix it; keep what was right)' + NL + f.read_text()[:3000] + NL + prev + NL


_TWIN = {}


def twins(addr):
    """other original functions with the identical masked body (auto/orig_hash.json)"""
    if not _TWIN:
        oh = json.load(open(OUT / 'orig_hash.json'))
        by = {}
        for a, x in oh.items():
            by.setdefault(x, []).append(a)
        _TWIN.update(oh=oh, by=by)
    a = '%08x' % addr
    return [b for b in _TWIN['by'].get(_TWIN['oh'].get(a), []) if b != a]


def exact_drafts():
    """addresses whose AutoRecover draft was byte-exact (metrics result rows)"""
    out = set()
    try:
        for l in open(OUT / 'metrics.jsonl'):
            if '"result"' in l and '"exact": 1' in l:
                try:
                    out.add(json.loads(l)['addr'])
                except ValueError:
                    pass
    except OSError:
        pass
    return out


def twin_analog(addr):
    """an original function with the identical (masked) body that has a 100% analog: same shape, other types"""
    try:
        ex = exact_drafts()
        for b in twins(addr):   # first choice: a same-shape twin whose native draft went byte-exact (native names already)
            f = NC / ('AutoRecover_%s.cpp' % b)
            if b in ex and f.exists():
                return ('## SAME-SHAPE TWIN: %s has a byte-identical body (other types/callees) and this native draft of it is '
                        'byte-exact. Reuse its structure statement for statement; adapt types, globals and callees to THIS '
                        'function (take them from THIS disassembly).' % b + NL + FENCE + 'cpp' + NL +
                        f.read_text(errors='replace')[:8000] + NL + FENCE + NL)
        for b in twins(addr):
            f = ROOT / 'src/2008-06' / (b + '.cpp')
            if f.exists():
                t = f.read_text(errors='replace')
                if t.startswith('// from server: 100%'):
                    return ('## SAME-SHAPE TWIN: %s has a byte-identical body (other types/callees) and this 100%% exact analog. '
                            'Reuse its structure statement for statement; adapt types and callees to THIS function.' % b + NL +
                            FENCE + 'cpp' + NL + t[:8000] + NL + FENCE + NL)
    except Exception:
        pass
    return ''


def native_impl(addr):
    """the existing native implementation of this named method (repair it rather than start blank)"""
    sym = names.get(addr, {}).get('name') or ''
    m = re.match(r'\?([A-Za-z_]\w*)@([A-Za-z_]\w*)@', sym)
    if not m:
        return ''
    pat = re.compile(r'\b%s::%s\s*\(' % (re.escape(m.group(2)), re.escape(m.group(1))))
    for f in sorted(NC.glob('*.cpp')):
        if f.name.startswith('AutoRecover_'):
            continue
        t = f.read_text(errors='replace')
        mm = pat.search(t)
        if mm:
            st = t.rfind(NL + NL, 0, mm.start())
            return ('## EXISTING NATIVE IMPLEMENTATION (%s): real layouts and callee names; make it byte-exact rather than '
                    'starting over' % f.name + NL + FENCE + 'cpp' + NL + t[max(0, st):mm.start() + 4000] + NL + FENCE + NL)
    return ''


def library_excerpt(analog):
    """analogs that are library units (// roc-lib: RECIPE FILE) carry no code: give the real function name and the library
    source of that function (from the exact preprocessed unit) so the draft reproduces the vendor code."""
    lib = re.search(r'//\s*roc-lib:\s*(\S+)\s+(\S+)', analog)
    fn = re.search(r'// library \S+ \(function (\S+)\)', analog)
    if not lib:
        return ''
    out = '## LIBRARY FUNCTION: this target is vendor code from %s %s' % (lib.group(1), lib.group(2))
    if fn:
        out += ', real name %s' % fn.group(1)
    out += '. Reproduce that vendor implementation (same statements, same inlining) as this function.' + NL
    try:
        from roc import libs
        cl = int((re.search(r'//\s*roc-cl:\s*(\d+)', analog) or [0, 21022])[1])
        unit = libs.unit(lib.group(1), lib.group(2), cl)
        m = re.match(r'\?(\w+)@(?:\?\$)?(\w+)@', fn.group(1)) if fn else None
        if m:
            meth, cls = m.group(1), m.group(2)
            best = None
            for mm in re.finditer(r'\b%s\s*\(' % re.escape(meth), unit):
                ctx = unit[max(0, mm.start() - 3000):mm.start()]
                if cls in ctx and '{' in unit[mm.end():mm.end() + 400]:
                    best = mm.start()
            if best is not None:
                st = unit.rfind(NL, 0, max(0, best - 300))
                out += FENCE + 'cpp' + NL + unit[st:best + 2500] + NL + FENCE + NL
    except (Exception, SystemExit):   # roc.libs raises SystemExit for missing source trees; in a worker thread it killed the slot silently
        pass
    return out


def mined_analog(addr):
    """the server-verified 100% byte-exact 2008 analog (src/2008-06/<addr>.cpp from roc pull): exact codegen, invented names."""
    f = ROOT / 'src/2008-06' / ('%08x.cpp' % addr)
    if not f.exists():
        return twin_analog(addr) + native_impl(addr)
    t = f.read_text(errors='replace')
    if not t.startswith('// from server: 100%'):
        return twin_analog(addr) + native_impl(addr)
    return library_excerpt(t) + ('## START FROM THIS: server-verified 100%% byte-exact 2008 codegen analog of THIS function' + NL +
            'Its statements, local variables, types/sizes, inline expansions and control flow are what make the bytes match: '
            'keep them exactly. Its helper functions, globals and structs are INVENTED names: replace each called helper '
            'with the callee at the same position in the disassembly call order (its real C++ name when the disassembly '
            'comment names it, else fn_<8 hex address> with the convention shown below), each global with its real native '
            'name or extern g_<8 hex address>, and keep struct member offsets. Do not restructure anything else.' + NL +
            FENCE + 'cpp' + NL + t[:9000] + NL + FENCE + NL)


def draft(addr, feedback, slot=0):
    sym = names.get(addr, {}).get('name') or ''
    cls, meth, full = class_of(sym) if sym.startswith('?') else (None, None, '')
    hn, hx = header_excerpt(cls) if cls else (None, '')
    sn, sx = sibling(cls)
    p = PROMPT.format(name=sym or 'func_%08x' % addr, addr=addr, demangled=full or '?',
                      flags='// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS',
                      dis=disasm(addr)[:24000], tabi=target_abi(disasm(addr)), natives=native_callees(disasm(addr)), conv=callee_conventions(disasm(addr)) or 'none (all callees are named)', hdrname=hn or 'none found', hdr=hx[:6000],
                      analog=analogs(cls, meth)[:7000] or 'none found', sibname=sn or 'none', sib=sx, feedback='\x00FB\x00', mined=mined_analog(addr))
    _pre, _, _post = p.partition('\x00FB\x00')
    _fbk = crash_context(addr) + feedback
    p = _pre + _fbk + _post
    (OUT / ('packet_%08x.md' % addr)).write_text(p)
    t0 = time.time()
    text = ask_llm(p, slot, addr, cache_prefix=_pre)
    try:   # raw answers kept for harness review (what the model actually wrote)
        (OUT / 'responses').mkdir(exist_ok=True)
        with open(OUT / 'responses' / ('%08x.txt' % addr), 'a', encoding='utf-8', errors='replace') as rf:
            rf.write(NL + '=' * 30 + ' %s %s' % (time.strftime('%H:%M:%S'), BACKENDS[slot]) + NL + text)
    except Exception:
        pass
    metric({'kind': 'draft', 'addr': '%08x' % addr, 'backend': BACKENDS[slot],   # tokens ~ chars/4; one line per LLM call (see rates.py)
            'prompt_chars': len(p), 'out_chars': len(text), 'secs': round(time.time() - t0, 1)})
    m = re.search(FENCE + r'(?:cpp|c\+\+)?\n(.*?)' + FENCE, text, re.S)
    return (m.group(1) if m else None), text


ADDR_LIT = re.compile(r'\b0x0*([4-9][0-9a-fA-F]{5})\b')


def address_literals(src):
    """exe addresses used as values in code (comments and fn_/g_ names excluded): meaningless after relinking."""
    code = re.sub(r'//[^\n]*|/\*.*?\*/', '', src, flags=re.S)
    return sorted({m.group(0) for m in ADDR_LIT.finditer(code) if 0x401000 <= int(m.group(1), 16) < 0x9a0000})


HDR_CLASSES = {}


def redefined_header_classes(src):
    """class/struct definitions (with a body) in a draft whose name is a class defined in rebuild/2008-06/native-headers"""
    if not HDR_CLASSES:
        for h in sorted(glob.glob(str(ROOT / 'rebuild/2008-06/native-headers/**/*.h'), recursive=True)):
            hp = h.replace(BS, '/').split('native-headers/')[1]
            try:
                t = open(h, errors='ignore').read()
            except OSError:
                continue
            for c in re.findall(r'^\s*(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?([A-Z]\w+)\s*(?::[^;{]*)?\{', t, re.M):
                HDR_CLASSES.setdefault(c, hp)
    defs = re.findall(r'^\s*(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?(\w+)\s*(?::[^;{]*)?\{', src, re.M)
    return sorted({c for c in defs if c in HDR_CLASSES})


def compile_(addr, src, ehs=True):
    f = NC / ('AutoRecover_%08x.cpp' % addr)
    # extern "C" fn_<addr> definitions: /EHsc makes the compiler assume C functions never throw and drops the EH frame the
    # original C++ function has; /EHs keeps it (same codegen otherwise). ehs=False keeps /EHsc (wins for e.g. 007f6910).
    if ehs:
        src = re.sub(r'^(// native-flags:.*?)/EHsc\b', lambda m: m.group(1) + '/EHs', src, count=1, flags=re.M)
    src = re.sub(r'^\s*`{3}.*$', '', src, flags=re.M)   # stray fence lines inside the block (C2018 unknown character 0x60)
    _need = [h for h, pat in (('<new>', r'\bnew\s*\(|operator new'),
                              ('<math.h>', r'\b(?:fabsf?|sqrtf?|sinf?|cosf?|floorf?|ceilf?|atan2f?|powf?)\s*\('),
                              ('<crtdefs.h>', r'_invalid_parameter_noinfo'))
             if re.search(pat, src) and ('#include ' + h) not in src]
    if _need:   # headers drafts keep forgetting: declarations only, no codegen change
        _l = src.split(NL, 1)
        src = _l[0] + NL + ''.join('#include %s' % h + NL for h in _need) + (_l[1] if len(_l) > 1 else '')
    f.write_text(src)
    bad_names =sorted(set(re.findall(r'\bfn_(?![0-9a-f]{8}\b)\w+', src)))
    if bad_names:   # invented helper names never link: they become zero stubs and crash at run time
        return False, ('invented helper names %s: unknown callees must be named exactly fn_<8 hex digit address> '
                       '(the address from the disassembly) or use their real C++ name.' % ' '.join(bad_names[:6])), None
    m = re.search(r'extern\s+"C"[^;{()]*?(__fastcall|__stdcall|__cdecl)?\s*\**\s*fn_%08x\s*\(([^)]*)\)\s*\{' % addr, src)
    if m:   # the target's own definition must match the exe's ABI (callers in other drafts rely on it)
        want = target_abi(disasm(addr))
        n = 0 if m.group(2).strip() in ('', 'void') else m.group(2).count(',') + 1
        conv = m.group(1) or '__cdecl'
        k = int(re.search(r'(\d+) (?:stack )?argument', want).group(1)) if re.search(r'(\d+) (?:stack )?argument', want) else 0
        ok = (want.startswith('__thiscall') and conv == '__fastcall' and n - 2 == k) or              (want.startswith('__stdcall') and conv == '__stdcall' and n == k) or (want.startswith('__cdecl') and conv == '__cdecl')
        if not ok and 'std::string' not in m.group(2):
            return False, ('ABI mismatch: the definition is %s with %d parameter(s), but the original is %s' % (conv, n, want)), None
    fake = redefined_header_classes(src)
    if fake:   # invented copies of real classes export ctors/dtors/vtables under the REAL decorated names (link-order roulette)
        return False, ('redefined classes that already exist in the native headers: %s. Never define these yourself: '
                       '#include the real header instead (%s) and use its members; for an unknown member use the real class '
                       'plus an `// INFERRED:` offset access through a char* cast.' % (
                           ', '.join(fake[:6]), ', '.join('"%s"' % HDR_CLASSES[c] for c in fake[:6]))), None
    lits = address_literals(src)
    _dis = disasm(addr).lower()
    _fix = [l for l in lits if ('0x%x' % int(l, 16)) in _dis]
    if _fix:   # unnamed data addresses copied from the disassembly: name them g_<addr> (the prompt's own convention) instead of a retry
        decl = ''
        for l in _fix:
            g = 'g_%08x' % int(l, 16)
            had = re.search(r'\b%s\b' % g, src)
            src = re.sub(re.escape(l) + r'\b', '((int)&%s)' % g, src)
            if not had:
                decl += 'extern "C" char %s[];   // INFERRED: unnamed global at 0x%s in the original' % (g, g[2:]) + NL
        _l = src.split(NL, 1)
        src = _l[0] + NL + decl + (_l[1] if len(_l) > 1 else '')
        f.write_text(src)
        lits = address_literals(src)
    if lits:   # reject before compiling: these crashed File->New (GUID_SysMouse, c_dfDIMouse2 at exe addresses)
        return False, ('hardcoded exe addresses %s: these addresses mean nothing in the relinked exe. Use the real symbol '
                       '(e.g. GUID_SysMouse, c_dfDIKeyboard, IID_*, a class vtable, a string literal) or declare '
                       '`extern "C" <type> g_<8hex>;` for an unknown global.' % ' '.join(lits[:8])), None
    man = OUT / ('m_%08x.json' % addr)
    man.write_text(json.dumps({'compiler_build': 21022, 'jobs': [{'source': 'native-classes/' + f.name}]}))
    for _attempt in range(4):   # other workers editing shared inputs make the runner refuse ("inputs changed during compile; rerun")
        r = run([sys.executable, str(ROOT / 'rebuild/2008-06/tests/native_check_runner.py'), 'run', str(man), '--workers', '1'])
        if 'inputs changed during compile' not in r.stdout:
            break
    try:
        d = json.loads(r.stdout.strip().splitlines()[-1])
    except Exception:
        return False, 'runner failed: ' + (r.stdout + r.stderr)[-800:], None
    log = Path(d['run']) / 'unit-000' / 'compile.log'
    errs = []
    if log.exists():
        for l in log.read_text(errors='replace').splitlines():
            if 'error C' in l or 'fatal error' in l:
                errs.append(re.sub(r'^.*native-classes.', '', l))
    ok = d['state'] == 'complete' and not d.get('issues')
    return ok, NL.join(errs[:10]) or str(d.get('issues'))[:600], d.get('results')


EXACT_TARGET = float(os.environ.get('ROC_EXACT_TARGET', '95'))   # keep retrying with the byte diff below this score


def byte_score(addr, ec):
    """100 when every function in the draft is exact, else the score exact_check printed for the target address."""
    m = re.search(r'exact (\d+)/(\d+)', ec)
    if m and m.group(1) == m.group(2) and m.group(2) != '0':
        return 100.0
    v = re.findall(r"'%08x', '[^']*', ([0-9.]+)\)" % addr, ec)
    return float(v[0]) if v else 0.0


def asm_diff(addr, res):
    """instruction diff of the compiled draft against the original (roc native-asm --obj)."""
    try:
        rows = json.load(open(res))
        rows = rows if isinstance(rows, list) else rows['results']
        obj = rows[0]['object']
        from roc.rebuild import coff_externals as _ce
        syms = [n for n, d in _ce(Path(obj).read_bytes()).items() if d and ('%08x' % addr) in n]
        args = [sys.executable, str(ROOT / 'roc.py'), 'native-asm', '2008-06', '%08x' % addr, '--obj', obj, '--context', '2']
        name = names.get(addr, {}).get('name') or ''
        sym = syms[0] if syms else (name if name.startswith('?') else '')
        out = run(args + (['--sym', sym] if sym else [])).stdout
        return out[:6000] or 'diff unavailable'
    except Exception as e:
        return 'diff unavailable: %s' % e


def work(addr):
    slot = SLOTS.get()
    t0 = time.time()
    label = (names.get(addr, {}).get('name') or 'func_%08x' % addr)[:60]
    rec = {'addr': '%08x' % addr, 'name': names.get(addr, {}).get('name', ''), 'tries': 0}
    _of = NC / ('AutoRecover_%08x.cpp' % addr)
    orig = _of.read_text(errors='replace') if _of.exists() else None
    try:
        emit('native_started', slot=slot, file=label, message='drafting')
        fb = ''
        best = [-1.0, None, None, '']
        for t in range(1, TRIES + 1):
            rec['tries'] = t
            try:
                emit('native_progress', slot=slot, file=label, message='draft %d/%d (%s)' % (t, TRIES, BACKENDS[slot]))
                src, raw = draft(addr, fb, slot)
            except Exception as e:
                rec['error'] = 'draft failed: %s' % e
                break
            if not src:
                rec['error'] = 'no code block'
                fb = NL + '## Your previous answer had no cpp code block; answer with exactly one fenced block.'
                continue
            emit('native_progress', slot=slot, file=label, message='compiling draft %d' % t)
            ok, info, res = compile_(addr, src)
            rec['compile'] = ok
            if ok:
                ex = run([sys.executable, str(H / 'exact_check.py'), 'native-classes/AutoRecover_%08x.cpp' % addr]).stdout.strip().splitlines()
                ec_ = ex[-1][:300] if ex else ''
                sc = byte_score(addr, ec_)
                src_ = (NC / ('AutoRecover_%08x.cpp' % addr)).read_text(errors='replace')   # the text actually compiled (/EHs, fixes)
                if sc < 100 and re.search(r'^// native-flags:.*/EHsc\b', src, re.M):
                    # triage 2026-11-24: /EHs made 38 drafts exact, /EHsc 6: try the other flag, keep the better
                    ok2, _i2, res2 = compile_(addr, src, ehs=False)
                    if ok2:
                        ex2 = run([sys.executable, str(H / 'exact_check.py'), 'native-classes/AutoRecover_%08x.cpp' % addr]).stdout.strip().splitlines()
                        ec2 = ex2[-1][:300] if ex2 else ''
                        sc2 = byte_score(addr, ec2)
                        if sc2 > sc:
                            sc, ec_, res = sc2, ec2, res2
                            src_ = (NC / ('AutoRecover_%08x.cpp' % addr)).read_text(errors='replace')
                src = src_   # save what was scored: the draft text kept /EHsc while its /EHs object was scored (~30 stale exacts)
                if sc >= best[0]:   # keep the closest draft (byte score vs the original), not merely the last one
                    best[:] = [sc, src, res, ec_]
                rec.update(results=best[2], exact_check=best[3], score=best[0])
                rec.pop('error', None)
                if sc >= EXACT_TARGET or t == TRIES:
                    break
                diff = asm_diff(addr, res)
                emit('native_progress', slot=slot, file=label, message='byte score %.1f%%: retrying with the diff' % sc)
                fb = (NL + '## Your previous draft compiled but is only %.1f%% byte-identical to the original. Make it byte-exact. '
                      'Instruction diff (- original, + yours; addresses/relocations masked):' % sc + NL + diff[:5000] + NL +
                      '## Previous source:' + NL + FENCE + 'cpp' + NL + src[:6000] + NL + FENCE + NL +
                      'Fix the source so the compiler emits the original instructions (control flow, EH frame, locals, call order, '
                      'inlining), and answer with the full corrected file in one cpp fenced block.')
                continue
            rec['last_errors'] = info
            fb = (NL + '## Your previous attempt failed to compile. Compiler errors:' + NL + info + NL + '## Previous source:' + NL + FENCE + 'cpp' + NL
                  + src[:6000] + NL + FENCE + NL + 'Fix and answer with the full corrected file in one cpp fenced block.')
        if best[0] < EXACT_TARGET and BACKENDS[slot].startswith('api:') and 'opus' not in BACKENDS[slot] and not os.environ.get('ROC_NO_ESCALATE') and not api_exhausted():
            _bk = BACKENDS[slot]
            BACKENDS[slot] = 'api:claude-opus-5-5'
            try:
                emit('native_progress', slot=slot, file=label, message='escalating to Opus (best %.1f%%)' % max(best[0], 0))
                src, raw = draft(addr, fb, slot)
                if src:
                    ok, info, res = compile_(addr, src)
                    src = (NC / ('AutoRecover_%08x.cpp' % addr)).read_text(errors='replace')
                    if ok:
                        ex = run([sys.executable, str(H / 'exact_check.py'), 'native-classes/AutoRecover_%08x.cpp' % addr]).stdout.strip().splitlines()
                        ec_ = ex[-1][:300] if ex else ''
                        sc = byte_score(addr, ec_)
                        if sc >= best[0]:
                            best[:] = [sc, src, res, ec_]
                            rec.update(compile=True, results=res, exact_check=ec_, score=sc, escalated=True)
                            rec.pop('error', None)
            except Exception as e:
                emit('log', slot=slot, message='opus escalation failed: %s' % type(e).__name__)
            finally:
                BACKENDS[slot] = _bk
        ec = rec.get('exact_check', '')
        _mm = re.search(r'exact (\d+)/(\d+)', ec)
        _exact = bool(rec.get('compile') and _mm and _mm.group(1) == _mm.group(2) != '0')
        if orig is not None and not _exact:   # a redraft that is not exact never replaces an existing draft
            (NC / ('AutoRecover_%08x.cpp' % addr)).write_text(orig)
            rec['kept_original'] = True
        elif best[1] is not None:   # leave the best-scoring draft on disk
            (NC / ('AutoRecover_%08x.cpp' % addr)).write_text(best[1])
        mm_ = re.search(r'exact (\d+)/(\d+)', ec)
        exact = 1 if rec.get('compile') and mm_ and int(mm_.group(2)) > 0 and ("'%08x'" % addr) not in ec else 0
        nxt = [a for a in SORTED_ADDRS if a > addr][:1]
        code_bytes = (nxt[0] - addr) if (exact and nxt) else 0   # function size = distance to the next known function
        metric({'kind': 'result', 'addr': '%08x' % addr, 'backend': BACKENDS[slot], 'compiled': bool(rec.get('compile')),
                'exact': exact, 'bytes': code_bytes, 'tries': rec['tries'], 'secs': round(time.time() - t0, 1),
                'escalated': bool(rec.get('escalated')), 'error': (rec.get('error') or '')[:80]})
        err = '' if rec.get('compile') else (rec.get('last_errors') or rec.get('error') or 'failed')
        emit('native_result', slot=slot, file=label, local_exact=exact, error=err, error_summary=err.splitlines()[0] if err else '',
             seconds=round(time.time() - t0, 1), message=rec.get('exact_check', '')[:200])
        return rec
    except (Exception, SystemExit) as e:
        rec['error'] = 'worker crash: %r' % e
        emit('native_result', slot=slot, file=label, local_exact=0, error=rec['error'][:300], error_summary=rec['error'][:200],
             seconds=round(time.time() - t0, 1), message='')
        return rec
    finally:
        SLOTS.put(slot)


def discover(src, attempted):
    """Helper functions a draft declares as name_<8 hex address> (its convention for unknown callees): new targets."""
    found = []
    for m in re.finditer(r'(?:fn|[A-Za-z_][A-Za-z0-9_]*?)_([0-9a-fA-F]{8})', src or ''):   # convention fn_<addr>; older drafts used name_<addr>
        a = int(m.group(1), 16)
        if 0x401000 <= a < 0x680000 and a in names and a not in attempted and a not in found and a not in NATIVE:   # fn_<addr> convention
            found.append(a)
    return found


def hopeless():
    """owner 2026-11-24: a function with >= 3 LLM drafts in total (all runs, all backends) and no exact result is not
    tried again; it is listed in auto/needs_review.txt for a person."""
    drafts, good = {}, set()
    try:
        for l in open(OUT / 'metrics.jsonl'):
            try:
                r = json.loads(l)
            except ValueError:   # one interleaved line used to end the scan early
                continue
            if r.get('kind') == 'draft':
                a = int(r['addr'], 16)
                drafts[a] = drafts.get(a, 0) + 1
            elif r.get('kind') == 'result' and r.get('exact'):
                good.add(int(r['addr'], 16))
    except Exception:
        pass
    out = {a for a, n in drafts.items() if n >= 3 and a not in good}
    try:
        (OUT / 'needs_review.txt').write_text('# >= 3 LLM drafts, never exact: stop trying, review by hand (draft count)' + NL +
                                              ''.join('%08x %d' % (a, drafts[a]) + NL for a in sorted(out)))
    except OSError:
        pass
    return out


def risky_exact(rec):
    """why an exact draft must not join the link set unreviewed ('' = safe): static initializers/finalizers
    (??__E/??__F) and drafts that define their own struct/class (invented layouts)."""
    nm = rec.get('name') or ''
    if nm.startswith(('??__E', '??__F')) or 0x7c0000 <= int(rec.get('addr') or '0', 16) < 0x800000:   # initializer/atexit range
        return 'static-initializer'
    try:
        src = (NC / ('AutoRecover_%s.cpp' % rec.get('addr'))).read_text(errors='replace')
    except OSError:
        return ''
    if re.search(r'^\s*(?:struct|class)\s+\w+\s*(?::[^;{]*)?\{', src, re.M):
        return 'own-class'
    return ''


def _accept(rec):
    """draft auto-accept: a compiled draft whose every function is byte-exact joins quicktest's link set at once
    (linkexp/qt_results.txt, sticky); >= 95 % drafts go to auto/draft_review.txt for a person"""
    import re as _re
    if not rec.get('compile') or not rec.get('results'):
        return
    m = _re.search(r'exact (\d+)/(\d+)', str(rec.get('exact_check', '')))
    best = max([float(x) for x in _re.findall(r"(\d+\.\d+)\)", str(rec.get('exact_check', '')))] or [0])
    if m and m.group(1) == m.group(2) and int(m.group(2)) > 0 and risky_exact(rec):
        # byte-exact with relocations masked does not prove the right globals/types: a static initializer or a draft
        # with its own class can construct the wrong object (crash after 16:41 on 2026-11-24). A person reviews these.
        with open(OUT / 'draft_review.txt', 'a') as fh:
            fh.write('%s 100.0 %s RISKY:%s' % (rec.get('addr'), rec['results'], risky_exact(rec)) + chr(10))
        emit('log', slot=0, message='exact draft %s held for review (%s), not auto-accepted' % (rec.get('addr'), risky_exact(rec)))
    elif m and m.group(1) == m.group(2) and int(m.group(2)) > 0:
        # never write linkexp/qt_results.txt directly (main session, 2026-11-24): its loop links each candidate and
        # gates it on quicktest + startcheck. Quarantined results are never offered again.
        q = OUT / 'quarantined_llm_results.txt'
        if q.exists() and rec['results'] in q.read_text():
            return
        f = OUT / 'llm_candidates.txt'
        cur = f.read_text().split(NL) if f.exists() else []
        if not any(rec['results'] in l for l in cur):
            with open(f, 'a') as fh:
                fh.write('%s %s' % (rec.get('addr'), rec['results']) + NL)
            emit('log', slot=0, message='exact draft %s -> auto/llm_candidates.txt (startup-gated by the main loop)' % rec.get('addr'))
    elif best >= 95:
        with open(OUT / 'draft_review.txt', 'a') as fh:
            fh.write('%s %.1f %s' % (rec.get('addr'), best, rec['results']) + chr(10))


def llm_only_pool():
    """renamed/rename.json statuses nomatch/compile/error (read-only; rename_par.py owns it): functions no exact analog converts.
    Order: compile (an analog exists but failed to build), error, nomatch; small functions first within each (cheaper, likelier exact)."""
    try:
        d = json.loads((H / 'renamed/rename.json').read_text())
    except Exception:
        return []
    rank = {'compile': 0, 'error': 1, 'nomatch': 2}
    out = [(rank[v['status']], int(a, 16)) for a, v in d.items() if v.get('status') in rank and int(a, 16) in names
           and not (names[int(a, 16)].get('name') or '').startswith(('??__E', '??__F')) and not 0x7c0000 <= int(a, 16) < 0x800000]   # initializers: names unreliable (270 share one), held until reviewed
    import bisect
    def size(a):
        i = bisect.bisect_right(SORTED_ADDRS, a)
        return SORTED_ADDRS[i] - a if i < len(SORTED_ADDRS) else 0x700
    return [a for _, a in sorted(out, key=lambda x: (x[0], size(x[1]), x[1]))]


POOL = llm_only_pool() if WATCH else []
POOL_SET = set(POOL) or set(llm_only_pool())


def main():
    if (OUT / 'NO_LLM').exists() and not (os.environ.get('ROC_API_ONLY') == '1' and all(b.startswith('api:') for b in BACKENDS)):
        print('auto/NO_LLM present: no LLM workers'); return
    (OUT / 'STOP').unlink(missing_ok=True)   # a stop request belongs to the job that was stopped, not to this new one
    emit('control', config=dict(workers=WORKERS, tries=TRIES, model=MODEL, mix=MIX, client='2008-06', lease_mode='native'), revision=1, paused=False, stopping=False)
    todo = queue.Queue()
    if not FORCE:
        skipped = [t for t in targets if t in NATIVE]
        targets[:] = [t for t in targets if t not in NATIVE]
        if skipped:
            emit('log', slot=0, message='skipped %d targets already defined natively: %s' % (len(skipped), ' '.join('%08x' % t for t in skipped[:12])))
    if not (RETRY_FAILED or FORCE):
        hp = hopeless()
        dropped = [t for t in targets if t in hp]
        targets[:] = [t for t in targets if t not in hp]
        if dropped:
            emit('log', slot=0, message='skipped %d targets that already failed twice (use --retry-failed): %s' % (len(dropped), ' '.join('%08x' % t for t in dropped[:12])))
    try:   # auto/priority.txt (cycle.py: crash stack + difftrace divergence) first; then by class so context repeats
        _pr = [int(x.split()[0], 16) for x in open(OUT / 'priority.txt') if x.strip()]
    except Exception:
        _pr = []
    _rank = {a: i for i, a in enumerate(_pr)}
    _cls = lambda a: (class_of(names.get(a, {}).get('name') or '')[0] or '') if (names.get(a, {}).get('name') or '').startswith('?') else ''
    targets.sort(key=lambda a: (_rank.get(a, 10 ** 6), _cls(a), a))
    attempted = set(targets)
    for t in targets:
        todo.put(t)
    results, lock, active, retwinned = [], threading.Lock(), [0], set()
    snow = SNOWBALL
    limit = MAXN

    def loop():
        while True:
            if (OUT / 'STOP').exists():
                return
            try:
                addr = todo.get(timeout=1.0)
            except queue.Empty:
                if WATCH:   # idle: feed from the crash classifier / stub-hit probe files, never exit on our own
                    with lock:
                        for f_ in QUEUES:
                            try:
                                new_ = [int(x.split()[0], 16) for x in open(OUT / f_) if x.strip() and not x.startswith('#')]
                            except Exception:
                                new_ = []
                            hp_ = hopeless()
                            for a in new_:
                                if a not in attempted and a not in hp_ and a not in NATIVE_ADDR and (a not in NATIVE or f_ == 'redraft.txt'):   # redraft: replace a bad existing draft
                                    attempted.add(a); todo.put(a)
                                    emit('log', slot=0, message='watch: queued %08x from %s' % (a, f_))
                        if todo.empty() and POOL:   # queues dry: LLM-only functions (exact-source conversion cannot provide them)
                            hp = hopeless()
                            # tried by the LLM, not exact, < 3 drafts: retry (its AutoRecover file made it look native);
                            # a non-exact retry never replaces the existing file
                            retry_ = set()
                            for l_ in open(OUT / 'metrics.jsonl'):
                                if '"result"' in l_:
                                    try:
                                        r_ = json.loads(l_)
                                    except ValueError:
                                        continue
                                    retry_.add(int(r_['addr'], 16))
                            retry_ -= {int(a_, 16) for a_ in exact_drafts()} | NATIVE_ADDR
                            n_ = 0
                            for a in POOL:
                                if a not in attempted and (a not in NATIVE or a in retry_) and a not in hp:
                                    attempted.add(a); todo.put(a); n_ += 1
                                    if n_ >= WORKERS * 2:
                                        break
                            if n_:
                                emit('log', slot=0, message='watch: queued %d LLM-only targets from renamed/rename.json' % n_)
                        if todo.empty():   # owner 2026-11-24: never-tried functions first, redrafts of bad existing drafts last
                            try:
                                rd_ = [int(x.split()[0], 16) for x in open(OUT / 'redraft.txt') if x.strip() and not x.startswith('#')]
                            except Exception:
                                rd_ = []
                            n_ = 0
                            hp_ = hopeless()
                            for a in rd_:
                                if a not in attempted and a not in hp_ and a not in NATIVE_ADDR:
                                    attempted.add(a); todo.put(a); n_ += 1
                                    if n_ >= WORKERS * 2:
                                        break
                            if n_:
                                emit('log', slot=0, message='watch: queued %d redrafts from redraft.txt' % n_)
                    if time.time() - globals().get('_hb', 0) > 60:   # dashboard heartbeat while idle
                        globals()['_hb'] = time.time()
                        emit('log', slot=0, message='watch: idle, waiting for targets in %s (%d attempted so far)' % (', '.join(QUEUES), len(attempted)))
                    time.sleep(10)
                    continue
                with lock:
                    if active[0] == 0:
                        return
                continue
            with lock:
                active[0] += 1
            try:
                try:
                    rec = work(addr)
                except (Exception, SystemExit) as e:   # backstop: never let one target kill the worker thread
                    rec = {'addr': '%08x' % addr, 'name': names.get(addr, {}).get('name', ''), 'error': 'worker crash: %r' % e}
                    emit('log', slot=0, message='worker crash on %08x: %r' % (addr, e))
                with lock:
                    results.append(rec)
                    _accept(rec)
                    _m = re.search(r'exact (\d+)/(\d+)', str(rec.get('exact_check', '')))
                    if rec.get('compile') and _m and _m.group(1) == _m.group(2) != '0' and not risky_exact(rec):
                        try:   # an exact draft is the template for its same-shape twins: retry the ones still not exact
                            ex = exact_drafts()
                            for b in twins(addr):
                                if b not in ex and int(b, 16) in POOL_SET and int(b, 16) not in retwinned and int(b, 16) not in hopeless():   # LLM-only twins only
                                    retwinned.add(int(b, 16)); attempted.add(int(b, 16)); todo.put(int(b, 16))
                                    emit('log', slot=0, message='twin: queued %s (same shape as exact %08x)' % (b, addr))
                        except Exception:
                            pass
                if snow and rec.get('compile') and len(attempted) < limit:
                    try:
                        src = (NC / ('AutoRecover_%08x.cpp' % addr)).read_text(errors='replace')
                    except OSError:
                        src = ''
                    with lock:
                        for a in discover(src, attempted):
                            if len(attempted) < limit:
                                attempted.add(a)
                                todo.put(a)
                                emit('log', slot=0, message='snowball: queued helper %08x (found in %08x)' % (a, addr))
            finally:
                with lock:
                    active[0] -= 1

    threads = [threading.Thread(target=loop, daemon=True) for _ in range(WORKERS)]
    for t in threads:
        t.start()
    for t in threads:
        t.join()
    rp = OUT / 'results.json'
    prev = json.load(open(rp)) if rp.exists() else []
    rp.write_text(json.dumps(prev + results, indent=1))
    for r in results:
        print(r['addr'], r['name'][:60], 'compiled' if r.get('compile') else 'FAILED', r.get('exact_check', r.get('error', ''))[:120])
    if not NOLINK and any(r.get('compile') for r in results):
        sets = sorted({r['results'] for r in results if r.get('compile') and r.get('results')})
        emit('log', slot=0, message='batch done: relinking %d compiled draft sets and probing File->New' % len(sets))
        try:
            out = run([sys.executable, str(H / 'boot.py'), *sets, '--file-new', '--secs', '40']).stdout
            for line_ in out.strip().splitlines()[-5:]:
                emit('log', slot=0, message=line_[:300])
        except Exception as e:
            emit('log', slot=0, message='relink failed: %s' % e)
    for i in range(WORKERS):
        emit('slot_stopped', slot=i)


if __name__ == '__main__':
    main()
