"""Initializer lane: dynamic initializers (??__E) and atexit destructors (??__F) named by the identity session
(unnamed-identities.json) become native by defining their global.  Per target:
  1. free: a native-classes TU that already defines the global is gated as-is (its compile emits the initializer);
  2. model (2x Opus/Sonnet tries): file-scope C++ that defines the global (and any template definitions it needs),
     gated by native_creator_gate.gate_code() with reference learning; a byte draft returns its asm diff to the model.
Results: work/native-client/init-lane/results.json.  Exact rows also go to native-llm/attempts.jsonl (status
inactive_exact, model init-lane) so combined bytes/hour and promotion see them.
Usage: python native_init_llm.py [--limit N] [--jobs J] [--no-model]"""
import argparse
import collections
import json
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ARGS = sys.argv[1:]
sys.argv = sys.argv[:1]
import native_llm as m              # noqa: E402
import native_creator_gate as cg    # noqa: E402

ap = argparse.ArgumentParser()
ap.add_argument('--limit', type=int, default=0)
ap.add_argument('--jobs', type=int, default=4)
ap.add_argument('--no-model', action='store_true', help='free native-TU gates only')
ap.add_argument('--match', default='', help='regex on the decorated name')
args = ap.parse_args(ARGS)
ROOT = m.ROOT
OUT = ROOT / 'work/native-client/init-lane'
OUT.mkdir(parents=True, exist_ok=True)
RESULTS = OUT / 'results.json'
results = json.loads(RESULTS.read_text()) if RESULTS.is_file() else {}
LADDER = ['claude:opus', 'claude:sonnet']
VENDOR_INIT = re.compile(r'\?\?__E_init_CXTP')       # XTP AFX_CLASSINIT registrations: vendor lane (XTP recipe)
CLASSES = ROOT / 'rebuild/2008-06/native-classes'
TU_TEXT = None

RULES = """You recover one compiler-generated function of the 2008 Roblox client: the dynamic initializer (??__E) or
atexit destructor (??__F) of a global.  The compiler emits it from the global's DEFINITION, so write only file-scope C++
that defines that global exactly as the original source did (type, constructor arguments, namespace), plus any template
member definitions the headers only declare and that the initializer inlines.  The REAL HEADERS are already included
above your code.  Never define functions the headers already define; never use __emit or inline asm.
Target: {name}
Meaning: {signature}
Reply with ONE ```cpp block and nothing else."""


def global_name(row):
    """'propTorso' / 'tag_color' / 'creator' ... from the undecorated signature."""
    found = re.search(r"(?:dynamic initializer|dynamic atexit destructor) for '(?:.*?)([A-Za-z_]\w*)''", row.get('signature', ''))
    return found.group(1) if found else ''


def defining_tu(name):
    """A native-classes TU that defines global NAME at file scope (a `NAME(` or `NAME =` / `NAME;` declarator)."""
    global TU_TEXT
    if TU_TEXT is None:
        TU_TEXT = [(p, p.read_text(errors='replace')) for p in CLASSES.glob('*.cpp') if not p.name.startswith('Mined')]
    rx = re.compile(r'^[ \t]*(?:static[ \t]+|const[ \t]+)*[\w:<>, *&]+[ \t*&]%s[ \t]*(?:\(|=|;|\[)' % re.escape(name), re.M)
    hits = [p for p, text in TU_TEXT if rx.search(text)]
    return hits[0] if len(hits) == 1 else None


def owner_headers(row):
    """Native headers for the classes the signature names (creator rows: the FactoryProduct arguments)."""
    if 'FactoryProduct<' in row.get('signature', ''):
        _, classes = cg.instance(row['signature'])
        names = classes + ['RBX::FactoryProduct']
    else:
        names = re.findall(r'\b((?:[A-Za-z_]\w*::)+[A-Za-z_]\w*)', row.get('signature', ''))
    out = []
    for name in dict.fromkeys(names):
        parts = name.split('::')
        for k in range(len(parts), 0, -1):          # RBX::Soundscape::x -> try the longest declared prefix
            header = m.declaring_header('::'.join(parts[:k]))
            if header:
                out.append(header)
                break
    return list(dict.fromkeys(out))[:4]


def record(addr, row, status, model):
    """Mirror an exact into attempts.jsonl so throughput/promotion/dashboard count it."""
    if status != 'inactive_exact':
        return
    size = len(m.match.target('2008-06', addr)[0])
    with m.atomic_append(m.LOG) as log:
        log.write(json.dumps(dict(addr=addr, symbol=row['name'], decl=row.get('signature', ''), owner=row.get('owner_class', ''),
                                  qual=global_name(row), header='', dest='', size=size, name_source='identity-unlock-init',
                                  placeholder=False, unmapped=[], new_source=True, model=model, attempt=0, status=status,
                                  time=round(time.time(), 1), run=m.RUN_ID, tool={}, llm_seconds=0.0, gate_seconds=0.0)) + '\n')


def run(addr):
    row = identities[addr]
    name = global_name(row)
    want = {addr: row['name']}
    work = OUT / addr
    tu = defining_tu(name) if name and name != 'creator' else None
    if tu:
        status, detail = cg.gate_code(work, [str(tu)], '', want)
        if status[addr] == 'inactive_exact' or args.no_model:
            return addr, status[addr], 'native-tu:' + tu.name, detail
    if args.no_model:
        return addr, 'skipped', '', ''
    headers = owner_headers(row)
    if not headers:
        return addr, 'no-header', '', ''
    asm = subprocess.run([str(ROOT / 'roc.cmd'), 'native-asm', '2008-06', addr], cwd=ROOT, capture_output=True,
                         text=True).stdout[-4000:]
    analog = ROOT / 'src/2008-06' / (addr + '.cpp')
    prompt = (RULES.format(name=row['name'], signature=row.get('signature', '')) +
              '\n--- REAL HEADERS (already included) ---\n' + '\n'.join(headers) +
              ('\n--- FactoryProduct template definitions (compile; the atexit side already matches byte for byte) ---\n'
               + cg.DEFINITIONS + '\nWrite a COMPLETE REPLACEMENT of this namespace RBX { ... } block (keep what is right, '
               'add/change what the target assembly needs, e.g. the extra store). Do NOT write any explicit instantiation: '
               'the harness appends `template const RBX::ICreator& RBX::FactoryProduct<...>::getCreator();` (creator is private).\n'
               if 'FactoryProduct<' in row.get('signature', '') else '') +
              '\n--- ORIGINAL ASSEMBLY (the target) ---\n' + asm + m.annotate_asm(asm) +
              ('\n--- REFERENCE ANALOG (placeholder names) ---\n' + analog.read_text(errors='replace')[:4000] if analog.is_file() else ''))
    history, status, detail, used = '', 'no-reply', '', ''
    for n, model in enumerate(LADDER):
        m.ask(model, prompt + history, row['name'])
        # ask() keeps only blocks defining `::name(` (methods); a global definition has none: take the last block.
        blocks = re.findall(r'```(?:cpp|c\+\+)?\s*\n(.*?)```', getattr(m.TOOL, 'reply', '') or '', re.S)
        body = blocks[-1] if blocks else None
        used = model
        if not body:
            continue
        code = body
        if 'FactoryProduct<' in row.get('signature', ''):
            targs, _ = cg.instance(row['signature'])
            code = (re.sub(r'^\s*template\s+(?!<)[^;{}]+;\s*$', '', body, flags=re.M) +
                    '\ntemplate const RBX::ICreator& RBX::FactoryProduct<%s>::getCreator();\n' % targs)
        invented = m.invented_externs(body)
        if invented:            # the gate does not check data identities: an invented global would pass as exact
            status, detail = {addr: 'rejected-invented'}, ('Rejected: `extern` names no header or binary symbol knows: %s. '
                                                           'Find the real global; never invent one.' % ', '.join(invented))
        else:
            status, detail = cg.gate_code(work, headers, code, want)
        status = status[addr]
        (work / ('try%d.cpp' % n)).write_text(body)
        if status == 'inactive_exact':
            break
        history = ('\n--- YOUR PREVIOUS ANSWER ---\n```cpp\n%s\n```\n--- RESULT: %s ---\n%s\nFix it. Same output rules.\n'
                   % (body, status, detail[-2500:]))
    return addr, status, used, detail


identities = json.loads((ROOT / 'work/native-client/unnamed-identities.json').read_text())
creator = json.loads(cg.RESULTS.read_text()) if cg.RESULTS.is_file() else {}
todo = [a for a, r in identities.items()
        if r['name'].startswith(('??__E', '??__F')) and not VENDOR_INIT.match(r['name'])
        and creator.get(a, {}).get('status') != 'inactive_exact' and results.get(a, {}).get('status') != 'inactive_exact'
        and (args.no_model or a not in results) and re.search(args.match, r['name'])]
todo = todo[:args.limit or None]
print('initializer targets', len(todo), flush=True)
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, status, how, detail in pool.map(run, todo):
        results[addr] = {'status': status, 'how': how, 'detail': detail[-600:], 'name': identities[addr]['name']}
        RESULTS.write_text(json.dumps(results, indent=1))
        record(addr, identities[addr], status, 'init-lane:' + (how or ''))
        print(addr, status, how, detail.strip().splitlines()[0][:120] if detail.strip() else '', flush=True)
print(collections.Counter(r['status'] for r in results.values()))
