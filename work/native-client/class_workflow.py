"""Class workflow (text-only models, no tools).  The steps a class agent does by hand, as a fixed graph:

  pack (script) -> draft (model) -> prove (script) -> EXACT? -> bind placeholder identity (script) -> keep file
                       ^                                 | no
                       +---- repair (model) <-- one-screen verdict: compile errors | asm diff | rejection reason

One prompt in, one C++ file out per model call (~15 K tokens) instead of a 25-turn tool session (3-4 M cached tokens).
Models: a ladder, one per round (free OpenCode first; add claude:sonnet as the last rung with --ladder).
  python work/native-client/class_workflow.py [--limit N] [--jobs 3] [--rounds 4] [--ladder a,b,c] [--only CLASS]
Queue: agent-class-queue.json (class and address-range tasks); done tasks: workflow-done.json; log: workflow-log.jsonl"""
import argparse
import uuid
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
ap = argparse.ArgumentParser()
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--jobs', type=int, default=3)
ap.add_argument('--rounds', type=int, default=5)
ap.add_argument('--ladder', default='openrouter:nvidia/nemotron-3-ultra-550b-a55b:free,openrouter:cohere/north-mini-code:free,cloudflare:@cf/qwen/qwen2.5-coder-32b-instruct,cloudflare:@cf/openai/gpt-oss-120b,claude:sonnet')   # model_stats.py 2026-11-18: sonnet 4.8% exact per call, haiku 1.6%, codex 0.8% -> only sonnet after the free models   # a spent/failed model is skipped
ap.add_argument('--only', default='')
ap.add_argument('--replay', action='store_true', help='no model: re-judge saved workflow files whose bytes were equal '
                '(rejected only on identity/references) with the inline reference aliases; keep them for the census')
args, _ = ap.parse_known_args()
sys.argv = [sys.argv[0], '--limit', '0']
sys.path.insert(0, str(HERE))
src = (HERE / 'native_placeholder_llm.py').read_text(encoding='utf-8')
lane = {'__name__': 'class_workflow', '__file__': str(HERE / 'native_placeholder_llm.py')}
exec(compile(src[:src.index('if args.polish:')], str(HERE / 'native_placeholder_llm.py'), 'exec'), lane)
m = lane['m']
import agent_prove  # noqa: E402
import shared_json  # noqa: E402
import inline_alias  # noqa: E402
from roc import native_bulk, rebuild  # noqa: E402

ROOT = m.ROOT
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
LADDER = [x for x in args.ladder.split(',') if x]
BLOCK = re.compile(r'```(?:cpp|c\+\+)?\s*\n(.*?)```', re.S)
LOCK = HERE / 'prove-out/CENSUS.lock'
reg = m.load_registry()
PY = sys.executable
OWNERS = json.loads((HERE / 'research-owners/owners.json').read_text()) if (HERE / 'research-owners/owners.json').is_file() else {}
RUNNER = native_bulk.checker()
TC = rebuild.toolchain(21022)
FAILDIR = HERE / 'workflow-fail'
DEAD = set()        # models that gave no reply twice in a row this run
MISS = {}


def wait_census():
    while LOCK.is_file():
        time.sleep(30)


def layout_table(header, cls):
    """'+0x40 m_name' lines for the class: the compiler's own layout of the native header (cl /d1reportAllClassLayout,
    cached).  The analog's stand-in struct uses the same offsets, so this is the field -> real member translation."""
    import native_class_layout as ncl
    cache = HERE / 'workflow-layouts' / (re.sub(r'\W+', '_', Path(header).as_posix().split('native-headers/')[-1]) + '.json')
    cache.parent.mkdir(exist_ok=True)
    if cache.is_file():
        classes = json.loads(cache.read_text())
    else:
        probe = cache.with_suffix('.cpp')
        probe.write_text('// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL\n#include "%s"\n' % (ROOT / header).resolve().as_posix())
        try:
            flags = [f for f in ncl.runner().compiler_flags(probe) if f != '/c']
            _, log = rebuild.run(TC, 'cl', flags + ['/Zs', '/d1reportAllClassLayout', str(probe)], cache.parent)
            classes = ncl.parse(log)
        except Exception:                                        # noqa: BLE001
            classes = {}
        cache.write_text(json.dumps(classes))
    leaf = cls.split('::')[-1]
    for name, row in classes.items():
        if name.split('::')[-1] == leaf:
            lines = ['+0x%x %s' % (mm['offset'], mm['name'].split()[-1]) for mm in row['members'][:160]]
            return 'sizeof(%s) = 0x%x\n' % (name, row['size']) + '\n'.join(lines)
    return ''


def sibling(header, cls):
    """A small proved .cpp of the same class: shows the flags line, the include set and the house style."""
    leaf = Path(header).name if header else ''
    best = None
    for p in CLASSES.glob('*.cpp'):
        if p.name.startswith(('WF_', 'DonorCtx_', 'TmplInst_', 'CloneProp_')) or p.stat().st_size > 6000:
            continue
        head = p.read_text(errors='replace')[:6000]
        if (leaf and leaf in head) or (not leaf and cls.split('::')[-1] + '::' in head):
            if best is None or p.stat().st_size > best.stat().st_size:
                best = p
    return best


def structural(addr):
    """(text for the prompt, needle) from the binary-derived identity, or None."""
    st = OWNERS.get(addr)
    if not st:
        return None
    why = '%s; %s' % (st.get('method', ''), st.get('evidence', '')[:160])
    decl = st.get('declaration') or st.get('declaration_candidate')
    name = st.get('name') or ''
    leaf = re.sub(r'\W', '', name.split('<')[0]) if name else ''
    if decl:
        return 'Declaration recovered from the binary (%s):\n  %s' % (why, decl), leaf or 'sub_' + addr
    if name:
        return ('It is `%s` of class %s (from the binary: %s). The parameters are not known: take them from the '
                'assembly and the analog.' % (name, st['owner'], why)), leaf
    extra = ' Known signature shape: %s.' % st['signature'] if st.get('signature') else ''
    return ('It is a member of class %s (from the binary: %s); its name is not known: define it as %s::sub_%s.%s'
            % (st['owner'], why, st['owner'], addr, extra)), 'sub_' + addr


def pack(task):
    owners = [OWNERS[a]['owner'] for a in task['addresses'] if a in OWNERS]
    if owners and not task.get('header'):          # a range task whose functions have a binary-derived owner class
        top = collections.Counter(owners).most_common(1)[0][0]
        found = m.declaring_header(re.sub(r'<.*', '', top).rsplit('::', 1)[-1])
        if found and Path(found).is_relative_to(ROOT) and 'native-headers' in str(found):
            task['header'], task['owner_class'] = str(Path(found).relative_to(ROOT)), top
    cls, header = task.get('owner_class') or task['class'], task.get('header') or ''
    parts = ['You write ONE C++ source file for the 2008 Roblox client (MSVC 2008, x86). Every function below must '
             'compile to EXACTLY the original bytes. Class: %s.' % cls]
    needles = {}
    for addr in task['addresses'][:6]:
        row = reg.get(addr) or {}
        name, sig = row.get('name') or '', row.get('signature') or ''
        named = bool(sig) and bool(name) and not name.startswith(('func_', 'sub_', '?sub_'))
        needles[addr] = re.sub(r'\W', '', re.sub(r'<[^<>]*>', '', sig.split('(')[0]).split()[-1].rsplit('::', 1)[-1]) if named else 'sub_' + addr
        known = structural(addr)
        if known:
            needles[addr] = known[1]
        analog = ROOT / 'src/2008-06' / (addr + '.cpp')
        asm = lane['target_asm'](addr)[:4000]
        callees = []
        for tgt in dict.fromkeys(re.findall(r'\b(?:call|jmp|push) 0x([0-9a-f]{6})\b', asm)):
            row2 = reg.get('00' + tgt) or {}
            real = row2.get('signature') or row2.get('name') or ''
            if real and not real.startswith(('func_', 'sub_', 'fn_')):
                callees.append('0x%s = %s' % (tgt, real[:160]))
        parts.append('=== FUNCTION %s ===\n%s\n--- original assembly ---\n%s\n--- byte-exact reference analog (placeholder '
                     'names, stand-in structs: keep its statements, order and types; use the real class instead) ---\n%s'
                     % (addr, known[0] if known else 'Signature: ' + sig if named else 'No known name: define it as %s::sub_%s (member) or sub_%s (free '
                        'function).' % (cls, addr, addr), asm + ('\n--- what the referenced addresses are (call these real functions) ---\n' + '\n'.join(callees[:25]) if callees else ''),
                        analog.read_text(errors='replace')[:5000] if analog.is_file() else '(none)'))
    if header and (ROOT / header).is_file():
        parts.append('=== CLASS HEADER %s (include it as "%s") ===\n%s' % (
            header, Path(header).as_posix().split('native-headers/')[-1], (ROOT / header).read_text(errors='replace')[:9000]))
    if header and (ROOT / header).is_file():
        table = layout_table(header, cls)
        if table:
            parts.append('=== REAL MEMBER AT EACH OFFSET (compiler layout of the header above). The reference analog reads '
                         'stand-in fields at these same offsets: use the member named here for each one ===\n' + table[:5000])
    sib = sibling(header, cls)
    if sib:
        parts.append('=== A PROVED FILE OF THIS CLASS (copy its "// native-flags:" line and include style) ===\n' +
                     sib.read_text(errors='replace')[:4500])
    try:                                                       # pre-computed per-address pack (no exploration needed)
        import context_pack
        for addr in task['addresses'][:3]:
            parts.append(context_pack.pack(addr, header=header or None, cls=cls, layout_fn=layout_table))
    except Exception:                                          # noqa: BLE001
        pass
    parts.append('RULES: first line is the "// native-flags:" line. Use only real headers and declared members; a member '
                 'missing from the header may be declared by reopening nothing - instead mark it in a comment line '
                 '"// NEEDS-DECL: <declaration>" and still write the body. No __emit, no asm, no (char*)this+offset, no '
                 'invented extern globals. NEVER define a class, struct or union yourself and never copy the analog\'s '
                 'stand-in structs: a file that defines any type is rejected unread. Use only the classes from the headers '
                 'you include. Reply with exactly one ```cpp block: the complete file.')
    return '\n\n'.join(parts), needles


def add_decls(header, cls, decls):
    """Insert NEEDS-DECL lines before the closing brace of the class (header restored if the task proves nothing)."""
    path = ROOT / header
    text = path.open(encoding='utf-8', errors='replace', newline='').read()     # keep the file's own line endings
    leaf = cls.split('::')[-1]
    start = re.search(r'\b(?:class|struct)\s+(?:\w+\s+)?%s\b[^;{]*\{' % re.escape(leaf), text)
    if not start:
        return False
    depth, i = 0, start.end() - 1
    while i < len(text):
        depth += text[i] == '{'
        depth -= text[i] == '}'
        if depth == 0:
            break
        i += 1
    # Only a single plain C++ declaration is accepted (2026-11-17: a model wrote prose after NEEDS-DECL and it went
    # into PartInstance.h): one function or data member, no comment, no body, no second statement.
    shape = re.compile(r'^(?:(?:static|virtual|const|unsigned|signed|inline)\s+)*[\w:<>,\s\*&]+?[\s\*&]~?\w+\s*'
                       r'(?:\([\w:<>,\s\*&=\.]*\)\s*(?:const)?|\[\w*\])?$')
    decls = [re.sub(r'^(?:public|protected|private)\s*:\s*', '', d.split('//')[0].rstrip(';').strip()) for d in decls]
    new = [d for d in decls if d and len(d) < 160 and shape.match(d) and d not in text]
    if not new or i >= len(text):
        return False
    path.write_text(text[:i] + 'public:\n' + ''.join('    %s;   // INFERRED: declaration needed by a byte-proved body '
                    '(class_workflow)\n' % d for d in new) + text[i:], encoding='utf-8', newline='')
    return True


LOCAL_TYPE = re.compile(r'\b(?:struct|class|union)\s+(\w+)\s*(?:final\s*)?(?::[^{;]*)?\{')
PAD_FIELD = re.compile(r'\bchar\s+_?(?:pad|unk|gap|filler|reserved)\w*\s*\[', re.I)


def not_native(code):
    """reason the file is an analog in disguise, or ''."""
    plain = re.sub(r'/\*.*?\*/', '', re.sub(r'//[^\n]*', '', code), flags=re.S)
    types = LOCAL_TYPE.findall(plain)
    if types:
        return 'it defines its own type(s) %s' % ', '.join(sorted(set(types))[:5])
    if PAD_FIELD.search(plain):
        return 'it declares padding fields'
    if re.search(r'^\s*extern\b', plain, re.M):
        return 'it declares extern symbols'
    if not re.search(r'^\s*#\s*include\s*["<]', plain, re.M):
        return 'it includes no header'
    return ''


HEADER_FILES = None


def header_by_name(name):
    """repo path under native-headers/ of a header file by base name (shallowest, no per-unit variant snapshots)."""
    global HEADER_FILES
    if HEADER_FILES is None:
        HEADER_FILES = {}
        root = ROOT / 'rebuild/2008-06/native-headers'
        for path in sorted(root.rglob('*.h'), key=lambda q: (len(q.relative_to(root).parts), str(q))):
            rel = path.relative_to(root).as_posix()
            if '-' not in rel.split('/')[0]:
                HEADER_FILES.setdefault(path.name.lower(), rel)
    return HEADER_FILES.get(name.lower())


def repair_includes(code, errs):
    """(new code, [what was added]) from the compiler's missing-name / missing-file errors, or (code, [])."""
    add, seen = [], set(re.findall(r'^\s*#\s*include\s*["<]([^">]+)[">]', code, re.M))
    text = '\n'.join(errs)
    if re.search(r"'(?:GUID_ATL|IID_I|CLSID_)\w*' : undeclared identifier", text) and 'atlbase.h' not in seen:
        add.append('<atlbase.h>')
    for name in dict.fromkeys(re.findall(r"'(\w+)' : (?:is not a member of '(?:RBX|`global namespace')'|is not a class or namespace name)", text)):
        found = m.declaring_header(name)
        if found and 'native-headers' in str(found):
            rel = Path(str(found)).as_posix().split('native-headers/')[-1]
            if rel not in seen and '-' not in rel.split('/')[0]:
                add.append('"%s"' % rel)
    for name in dict.fromkeys(re.findall(r"Cannot open include file: '([\w./-]+)'", text)):
        rel = header_by_name(Path(name).name)
        if rel and rel not in seen:
            code = re.sub(r'^\s*#\s*include\s*["<]%s[">]\s*$' % re.escape(name), '', code, flags=re.M)
            add.append('"%s"' % rel)
    if not add:
        return code, []
    lines = code.split('\n')
    at = next((i + 1 for i in range(len(lines) - 1, -1, -1) if re.match(r'\s*#\s*include', lines[i])), 1 if lines[0].startswith('// native-flags') else 0)
    lines[at:at] = ['#include %s   // auto-added by class_workflow (compiler said a name or file was missing)' % a for a in dict.fromkeys(add)]
    return '\n'.join(lines), add


def restore_header(header, backup):
    path = ROOT / header
    if path.read_bytes() == backup:
        return
    for _ in range(40):                              # a compiler may have the header open for a moment
        try:
            path.write_bytes(backup)
            return
        except PermissionError:
            time.sleep(0.5)


def bind(source, verdicts, needles):
    """Placeholder names (sub_<addr>) carry their address by construction: add INFERRED identity rows, reprove."""
    path = HERE / 'class-identity-bindings.json'
    rows = []
    for addr, (status, text) in verdicts.items():
        if status == 'REJECTED' and 'symbol identity not established' in text:
            sym = re.search(r'^\s{2}(\S+)', text.split('\n', 1)[1], re.M)
            if sym and not sym.group(1).startswith(('$', '__')):
                rows.append({'symbol': sym.group(1), 'address': addr, 'votes': 1, 'identity_evidence':
                             'INFERRED: class_workflow byte-equal body at this address (name %s is a placeholder)' % needles[addr]})
    manifest = HERE / 'prove-out' / ('prove-' + Path(source).stem) / 'manifest.json'
    rows += inline_alias.rows(manifest, {a for a, v in verdicts.items() if v[0] == 'REJECTED'})
    if not rows:
        return verdicts
    wait_census()
    def add(doc):
        have = {(r.get('symbol'), r.get('address')) for r in doc['identity_bindings']}
        doc['identity_bindings'] += [r for r in rows if (r['symbol'], r['address']) not in have]
        return doc
    shared_json.update(path, add)
    return agent_prove.verdict(source, needles)


def one(task):
    cls = task['class']
    prompt, needles = pack(task)
    header = task.get('header') or ''
    final = CLASSES / ('WF_%s_%s.cpp' % (re.sub(r'\W+', '_', cls)[:50], task['addresses'][0]))
    (HERE / 'lane-drafts' / final.stem).mkdir(parents=True, exist_ok=True)
    source = HERE / 'lane-drafts' / final.stem / final.name     # own folder: the prover hashes the source's directory
    paths = [final.relative_to(ROOT).as_posix()] + ([Path(header).as_posix()] if header else [])
    lease = 'workflow:' + source.stem
    took = subprocess.run([PY, 'roc.py', 'lease', 'take', lease, *paths, '--hours', '2'], cwd=ROOT, capture_output=True, text=True)
    if took.returncode:
        return cls, 'lease-refused', {}
    backup = (ROOT / header).read_bytes() if header and (ROOT / header).is_file() else None
    verdicts, reply, feedback, used, changed = {}, '', '', [], []
    try:
        for rnd in range(args.rounds):
            # rounds past the third are only for near misses (a DIFF or a byte-equal REJECTED): the diff feedback
            # converts those; a file that still does not compile after three tries goes to a class agent instead
            if rnd >= 3 and not any(v[0] in ('DIFF', 'REJECTED') for v in verdicts.values()):
                break
            live = [x for x in LADDER if x not in DEAD and x not in m.EXHAUSTED] or LADDER[-1:]
            model = live[min(rnd, len(live) - 1)]
            ask = prompt if not rnd else (prompt + '\n\n=== YOUR PREVIOUS FILE ===\n' + reply[-6000:] +
                                          '\n\n=== RESULT OF COMPILING AND COMPARING IT ===\n' + feedback[:5000] +
                                          '\nFix it. Reply with the complete corrected file in one ```cpp block.')
            if rnd == 0 and task.get('seed'):           # --replay: an earlier byte-equal file, no model call
                text, model = task['seed'], 'replay'
            else:
                m.ask(model, ask, needles[task['addresses'][0]])
                text = getattr(m.TOOL, 'reply', '') or ''
            code = BLOCK.findall(text) or ([text] if '#include' in text else [])
            used.append(model)
            if not code:
                MISS[model] = MISS.get(model, 0) + 1
                if MISS[model] >= 2:
                    DEAD.add(model)
                feedback = feedback or 'No C++ file was returned.'
                continue
            MISS[model] = 0
            reply = max(code, key=len)
            analog = not_native(reply)
            if analog:
                feedback = ('REJECTED before compiling: %s. This must be NATIVE code: include the real headers and use the '
                            'real classes and their declared members; never define a class, struct, pad field or extern '
                            'yourself. If a member or method is missing from the header, write a line '
                            '"// NEEDS-DECL: <one declaration>" and use it.' % analog)
                verdicts = {a: ('NOT NATIVE', analog) for a in needles}
                continue
            if m.invented_externs(reply) or m.OFFSET_HACK.search(reply):
                feedback = 'REJECTED before compiling: invented extern or raw this+offset arithmetic. Use real members.'
                continue
            wait_census()
            decls = re.findall(r'//\s*NEEDS-DECL:\s*(.+)', reply)
            if decls and backup is not None and not re.search(r'v8tree.Instance.h|v8datamodel.DataModel.h|util.Events.h|reflection', header):   # core headers have one owner
                restore_header(header, backup)
                changed.append(add_decls(header, task.get('owner_class') or cls, decls))
            source.write_text(reply.strip() + '\n', encoding='utf-8')
            # fast compile check (~10 s) before the full proof (1-3 min): a compile error needs no proof
            folder = HERE / 'workflow-compile' / ('%s-%d-%d' % (source.stem, rnd, int(time.time())))
            folder.parent.mkdir(exist_ok=True)                 # compile_job creates only the last folder itself
            errs = []
            try:
                job = RUNNER.compile_job({'source': str(source), 'checks': [], 'ranges': [], 'layouts': []}, folder, TC)
                if not Path(str(job.get('object') or '')).is_file():
                    errs = agent_prove.compile_errors(folder, '')
            except Exception:                                    # noqa: BLE001  harness trouble: let the proof decide
                errs = []
            for _fix in range(3):                                # scripted include repair: no model round for these
                if not errs:
                    break
                fixed, added = repair_includes(reply, errs)
                if not added:
                    break
                reply = fixed
                source.write_text(reply.strip() + '\n', encoding='utf-8')
                folder = HERE / 'workflow-compile' / ('%s-%d-%s' % (source.stem, rnd, uuid.uuid4().hex[:6]))
                folder.parent.mkdir(exist_ok=True)
                errs = []
                try:
                    job = RUNNER.compile_job({'source': str(source), 'checks': [], 'ranges': [], 'layouts': []}, folder, TC)
                    if not Path(str(job.get('object') or '')).is_file():
                        errs = agent_prove.compile_errors(folder, '')
                except Exception:                                # noqa: BLE001
                    errs = []
            if errs:                                             # only real compiler errors skip the proof
                verdicts = {a: ('COMPILE FAILED', '\n'.join(errs)) for a in needles}
                feedback = 'COMPILE FAILED\n' + '\n'.join(errs)
                continue
            verdicts = bind(source, agent_prove.verdict(source, needles), needles)
            if any(v[0] == 'RETRY LATER' for v in verdicts.values()):   # proof could not run cleanly: not the file's fault
                break
            waiting = HERE / 'prove-out' / ('prove-' + final.stem) / 'manifest.json'
            if all(v[0] == 'EXACT' or (v[0] == 'REJECTED' and inline_alias.only_waiting(waiting, a)) for a, v in verdicts.items()):
                break
            feedback = '\n'.join('== %s %s\n%s' % (a, s, t) for a, (s, t) in verdicts.items() if s != 'EXACT')
    finally:
        exact = [a for a, v in verdicts.items() if v[0] == 'EXACT']
        manifest = HERE / 'prove-out' / ('prove-' + final.stem) / 'manifest.json'
        pending = [a for a, v in verdicts.items() if v[0] == 'REJECTED' and inline_alias.only_waiting(manifest, a)]
        wait_census()
        if exact or pending:                     # pending: bytes equal, identity left to the census binders
            source.replace(final)                        # identical content: the proof receipt follows the file's hash
            shared_json.update(HERE / 'class-lane-new-sources.json', lambda lst: lst if paths[0] in lst else lst + [paths[0]], [])
        else:                                   # nothing proved: leave no draft file and no header change behind
            FAILDIR.mkdir(exist_ok=True)          # handoff for a class agent: the closest file and why it failed
            (FAILDIR / (re.sub(r'\W+', '_', cls)[:80] + '.txt')).write_text(
                '--- last workflow file (did not match) ---\n%s\n--- its verdict ---\n%s\n' % (reply[-5000:], feedback[:4000]),
                encoding='utf-8', errors='replace')
            if source.is_file():
                source.unlink()
            shutil.rmtree(HERE / 'prove-out' / ('prove-' + final.stem), ignore_errors=True)   # ~70 MB per failed proof
            if backup is not None and any(changed):
                restore_header(header, backup)
        subprocess.run([PY, 'roc.py', 'lease', 'release', lease], cwd=ROOT, capture_output=True, text=True)
    with open(HERE / 'workflow-log.jsonl', 'a', encoding='utf-8') as log:
        log.write(json.dumps({'time': time.strftime('%Y-%m-%d %H:%M'), 'class': cls, 'models': used, 'exact': exact, 'pending_census': pending,
                              'verdicts': {a: v[0] for a, v in verdicts.items()}}) + '\n')
    return cls, '%d/%d exact' % (len(exact), len(needles)), {a: v[0] for a, v in verdicts.items()}


queue = json.loads((HERE / 'agent-class-queue.json').read_text())
done_path = HERE / 'workflow-done.json'
done = set(json.loads(done_path.read_text())) if done_path.is_file() else set()
todo = [t for t in queue if t['class'] not in done and (not args.only or args.only in t['class'])]
if args.replay:
    todo, args.rounds = [], 1
    by_key = {re.sub(r'\W+', '_', t['class'])[:80]: t for t in queue}
    for f in sorted(FAILDIR.glob('*.txt')):
        text = f.read_text(encoding='utf-8', errors='replace')
        body, _, verdict = text.partition('--- its verdict ---')
        body = body.replace('--- last workflow file (did not match) ---', '').strip()
        if f.stem in by_key and 'REJECTED' in verdict and 'REJECTED before' not in verdict and '#include' in body \
                and body.lstrip().startswith(('// native-flags', '#include', '//')):
            todo.append(dict(by_key[f.stem], seed=body))
ranges = sorted((t for t in todo if t['class'].startswith('range ') and not t.get('header') and not args.replay), key=lambda t: t['addresses'][0])
todo = [t for t in todo if t not in ranges]
group = None
for t in ranges:                                # neighbours within 0x600: one source file, one call, up to 4 functions
    if group and len(group['addresses']) + len(t['addresses']) <= 4 and int(t['addresses'][0], 16) - int(group['addresses'][-1], 16) < 0x600:
        group['addresses'] += t['addresses']
        group['bytes'] += t.get('bytes', 0)
        group['members'].append(t['class'])
    else:
        group = {'class': t['class'], 'addresses': list(t['addresses']), 'bytes': t.get('bytes', 0), 'members': [t['class']]}
        todo.append(group)
seen, batch = set(), []
for t in sorted(todo, key=lambda t: t.get('bytes', 0)):          # small tasks first; one task per header at a time
    if (t.get('header') or t['class']) in seen:
        continue
    seen.add(t.get('header') or t['class'])
    batch.append(t)
batch = batch[:args.limit or None]
print('class workflow: %d tasks, ladder %s' % (len(batch), LADDER), flush=True)
total = 0
with ThreadPoolExecutor(args.jobs) as pool:
    def guarded(task):                                   # one task never stops the lane
        try:
            return one(task)
        except Exception as error:                       # noqa: BLE001
            return task['class'], 'lane error ' + repr(error)[:160], {'error': 'RETRY LATER'}

    for cls, status, detail in pool.map(guarded, batch):
        total += int(status.split('/')[0]) if '/' in status else 0
        if status != 'lease-refused' and 'RETRY LATER' not in detail.values():
            done.add(cls)
            done.update(next((t.get('members') or [] for t in batch if t['class'] == cls), []))
            done_path.write_text(json.dumps(sorted(done), indent=1))
        print(cls, status, detail, flush=True)
print('RESULT class workflow: %d functions exact' % total, flush=True)
