"""Native-source recovery with free OpenCode models doing only the C++ rewrite.

Per target (a declared method of a class that already has a real native header and a native .cpp, whose
mined analog is server-exact):  the model rewrites the exact analog as a real member-function definition
against the real header -> native_convert_run.py compiles it with the class's own flags and runs the
existing byte + reference gates -> on a miss, the compile error or asm diff goes back to the model.
Nothing is written to native-classes/ without --apply, and then only through native_autorecover.py
(lease, draft upload, layout/vtable gates, destination-TU reproof).

  python work/native-client/native_llm.py --limit 8                 # prove only, writes work/ only
  python work/native-client/native_llm.py --limit 8 --apply         # also promote exact survivors
  python work/native-client/native_llm.py --owner-prefix Ogre:: --model opencode/glm-5.3-flash-free
"""
import argparse
import collections
import fnmatch
import json
import os
import re
import struct
import subprocess
import sys
import tempfile
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

_PRINT_LOCK = threading.Lock()


def print(*args, sep=' ', end='\n', file=None, flush=False):
    """Atomic line print: builtin print writes text and newline separately, so 8 worker threads interleaved
    and split ROC_EVENT lines (the dashboard then showed raw JSON as a log line)."""
    stream = file or sys.stdout
    with _PRINT_LOCK:
        stream.write(sep.join(map(str, args)) + end)
        if flush:
            stream.flush()

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402

HERE = ROOT / 'work/native-client/native-llm'
QUEUE = ROOT / 'work/native-client/codex-native-conversion-queue-v44.json'
BASE_CLOSURE = ROOT / 'work/native-client/claude-identity-closure.json'
# Base closure plus callee identities proven from byte-identical LLM bodies (learn_identities).
CLOSURE = ROOT / 'work/native-client/claude-identity-closure-llm.json'
LOG = HERE / 'attempts.jsonl'
REGISTRY = ROOT / 'work/2008-06/identity-registry.json'
METRICS = HERE / 'bytes-per-hour.jsonl'
PREFLIGHT = HERE / 'preflight-blocked.json'
LAYOUTS = ROOT / 'work/native-client/ogre-layout-solutions.json'
NATIVE_CENSUS = ROOT / 'work/native-client/ogre-native-full-census-current/manifest.json'
OPENCODE = Path(os.environ.get('APPDATA', '')) / 'ai.opencode.desktop/cli/2.2.6-x64/opencode-cli.exe'
# Escalation ladder, fastest first: attempt n uses LADDER[n % len]. "provider:model" goes through
# roc/providers.py (NVIDIA NIM API key, signed-in Codex CLI); "opencode*/..." through the OpenCode CLI.
# Owner's standing choice: strongest NVIDIA + OpenCode models are first-class here, not a backlog. Each
# target starts at a different rung (its index), so all providers' quotas work in parallel.
LADDER = ['claude:sonnet', 'nvidia:nvidia/nemotron-3-ultra-550b-a55b', 'opencode-go/kimi-k3.1-pro',
          'codex:gpt-6.1-terra', 'nvidia:nvidia/nemotron-3.5-super-vl-120b-a12b', 'opencode-go/deepseek-v4-pro',
          'opencode-go/qwen3.8-max', 'opencode-go/longcat-2.5-free']
# Strongest NVIDIA NIM chat models for C++ rewrites (checked against the account's /v1/models list, 2026-11-14).
# Each run adds a random sample of these after Sonnet so their quotas and strengths spread over the batch.
CLAUDE_MODELS = ['claude:sonnet', 'claude:opus', 'claude:haiku', 'claude:fable']
# Owner choice 2026-11-15: 2x Opus + 3x Sonnet, no Haiku (24 h: Opus 3068 B/worker-hour, Sonnet 1717, Haiku 954;
# gate time ~26 s/try is the bottleneck, so cheap low-yield tries cost worker slots).  No NIM/free models.
DEFAULT_LADDER = ['claude:opus', 'claude:sonnet', 'claude:opus', 'claude:sonnet', 'claude:sonnet']
# Haiku-first went 0/21 in run 15: plain rotation again (Haiku ~1 in 5 tries, low effort).  --first-model to force one.
FIRST_MODEL = ''
LOW_EFFORT = {'claude:haiku'}    # most Haiku output was hidden thinking (4.4k tokens/try)
# nvidia deepseek-v4.1-flash and glm-5.3-flash dropped 2026-11-14: native_llm_probe.py ping timed out (120 s).
BEST_NIM = ['nvidia:mistralai/mistral-large-4-1t-a52b', 'nvidia:nvidia/nemotron-3-ultra-550b-a55b',
            'nvidia:minimaxai/minimax-m3.1-flash', 'nvidia:nvidia/nemotron-3.5-super-vl-120b-a12b']
# Free opencode models (longcat dropped: 120 s timeouts, no replies).  glm and beam have exacts.
BEST_FREE = ['opencode/glm-5.3-flash-free', 'opencode/beam-free', 'opencode/deepseek-v4.1-flash-free',
             'opencode/minimax-m3.1-flash-free', 'opencode/mimo-v2.6-flash-free', 'opencode/nemotron-3.5-super-vl-free']
EXHAUSTED = set()          # models that reported a spent quota this run
FAILS = collections.Counter()   # consecutive timeouts/errors (no reply text) per model; 3 in a row -> dropped


def dead_models(min_tries=4):
    """Models whose logged history is mostly timeouts/errors and never exact: skip them in the random picks."""
    stats = collections.defaultdict(collections.Counter)
    if LOG.is_file():
        for line in LOG.read_text().splitlines():
            row = _json(line) if line.strip() else None
            if row:
                stats[row['model']][row['status']] += 1
                stats[row['model']]['tries'] += 1
    return {m for m, c in stats.items() if c['tries'] >= min_tries and not c['inactive_exact'] and c['no-reply'] * 2 >= c['tries']}
PREFLIGHT_BLOCKED = []
SOURCE_DESTINATIONS = None
SOURCE_LEAVES = None
NATIVE_EXACT = None

RULES = """You are rewriting one function from a matching decompilation into its real source form.
The REFERENCE ANALOG below compiles (MSVC 2008, same flags) to exactly the original machine code, but it
uses invented names, raw pointer offsets and placeholder types. Rewrite it as the real member function:

- Exact signature: {decl}
- Write it against the REAL HEADER: use only its members, types and methods. Map each raw offset
  `*(T*)((char*)this + N)` to the header field at that offset (headers mark offsets in comments).
- Keep the analog's statement order, expression shapes, temporaries, branches and loop forms: the
  compiler output must stay byte-identical. Do not "clean up" logic.
- No inline asm, no casts to raw offsets, no new fields, globals, includes or declarations.
- Output ONE ```cpp block containing only the definition, qualified as `{qual}(` (no namespace block).
- Never define or redeclare anything else: no other functions, enums, structs, classes, typedefs or
  globals. Functions the header already defines inline must not be written again (C2084).
  Exception: a helper struct/class/functor that the REFERENCE ANALOG itself defines and no header declares (it lived
  in the original .cpp) goes right before the function, with the analog's layout.  Likewise a file-scope global the
  original .cpp defined (property descriptors prop_X / desc_X, ...) may be declared `extern` right before the function,
  using a name from KNOWN FILE GLOBALS when given.
- Prefer names the REAL HEADER declares. A class that is only forward-declared, or a callee in another
  RBX class, may still be used by its real name (e.g. `humanoid->setJumping(...)`): the harness adds the
  header that declares it and reports back any name it cannot find. Never invent placeholder names.
- Never refuse, ask a question or call a tool: always answer with your best ```cpp definition.
- Be terse: reply with the ```cpp block only. No explanation, no notes, no restating the task.
"""


def lease_globs():
    out = subprocess.run([str(ROOT / 'roc.cmd'), 'lease', 'ls'], cwd=ROOT, capture_output=True, text=True).stdout
    return [g for line in out.splitlines() for g in line.split() if g.startswith('rebuild/')]


def flags_of(dest):
    if not dest or not (ROOT / dest).is_file():      # new-source destination: not written yet
        return ''
    m = re.search(r'^// native-flags:\s*(.*)$', (ROOT / dest).read_text(errors='replace'), re.M)
    return m.group(1).strip() if m else ''


def analog_flags(addr):
    """The server-exact analog's own compiler flags (src/2008-06/ADDR.cpp `// roc-flags:`)."""
    path = ROOT / 'src/2008-06' / (addr + '.cpp')
    m = re.search(r'^//\s*roc-flags:\s*(.*)$', path.read_text(errors='replace'), re.M) if path.is_file() else None
    return m.group(1).strip() if m else '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD'


def destination_for(owner):
    """One existing class TU when text proves it owns members; else one deterministic new class TU."""
    global SOURCE_DESTINATIONS, SOURCE_LEAVES
    classes = ROOT / 'rebuild/2008-06/native-classes'
    if SOURCE_DESTINATIONS is None:
        SOURCE_DESTINATIONS = collections.defaultdict(collections.Counter)
        SOURCE_LEAVES = collections.defaultdict(set)
        # Definitions only: `Owner::m(args) [const] {` or a ctor initializer.  Calls such as
        # RBX::DebugSettings::singleton() routed DebugSettings members into the MFC TU CApp2008.cpp (C1189).
        body = r'\s*\([^;{}]*\)\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?(?:\{|:[^:;])'
        pattern = re.compile(r'\b((?:[A-Za-z_]\w*::)+[A-Za-z_]\w*)::~?[A-Za-z_]\w*' + body)
        for path in classes.glob('*.cpp'):
            if path.name.startswith('Mined'):
                continue        # verbatim mined analogs (func_XXXX, placeholder globals): never a class's home TU
            relative = path.relative_to(ROOT).as_posix()
            text = path.read_text(errors='replace')
            for found in pattern.findall(text):
                SOURCE_DESTINATIONS[found][relative] += 1
            for leaf in re.findall(r'\b([A-Za-z_]\w*)::~?[A-Za-z_]\w*' + body, text):
                SOURCE_LEAVES[leaf].add(relative)
    counts = SOURCE_DESTINATIONS.get(owner, collections.Counter())
    hits = sorted(counts)
    if not hits:
        leaf = owner.rsplit('::', 1)[-1].lower()
        leaf_hits = sorted(SOURCE_LEAVES.get(owner.rsplit('::', 1)[-1], ()))
        if len(leaf_hits) == 1:
            hits = leaf_hits
        named = [path.relative_to(ROOT).as_posix() for path in classes.glob('*.cpp')
                 if path.stem.lower().endswith(leaf) and not path.name.startswith('Mined')]
        # Filename is a routing hint only; exact owner/body proof still gates promotion.
        if not hits and len(named) == 1:
            hits = named
    if len(hits) == 1:
        return hits[0], False
    if len(hits) > 1:
        # Class split over several TUs: the one already defining the most of its methods (a clear majority) is the
        # routing target; the gate proves the body in isolation either way.
        ranked = counts.most_common()
        if ranked and ranked[0][1] > (ranked[1][1] if len(ranked) > 1 else 0):
            return ranked[0][0], False
        return None, False
    stem = re.sub(r'[^A-Za-z0-9]+', '_', owner).strip('_')
    return 'rebuild/2008-06/native-classes/OgreAuto_%s.cpp' % stem, True


def native_exact_addresses():
    """Skip bodies already current-TU byte-proved; stale queue state is not work."""
    global NATIVE_EXACT
    if NATIVE_EXACT is None:
        NATIVE_EXACT = set()
        if NATIVE_CENSUS.is_file():
            manifest = json.loads(NATIVE_CENSUS.read_text())
            # Candidates include byte-only aliases.  ``addr`` exists only
            # after identity plus relocation/data reference proof.
            NATIVE_EXACT = {symbol['addr'] for family in manifest.get('families', [])
                            for symbol in family.get('symbols', [])
                            if symbol.get('status') == 'inactive_exact'
                            and isinstance(symbol.get('addr'), str)}
            NATIVE_EXACT = {address.lower() for address in NATIVE_EXACT}
    return NATIVE_EXACT


# Last resort for headers native-headers lacks entirely (e.g. util/Math.h = RBX::Math, used by 50+ classes): the 2007
# donor tree.  Such exacts are header-gap evidence; the 2008 header still has to be recovered before integration.
DONOR_INCLUDE = ROOT / 'tools/rbxgs/Client/App/include'
# Not DONOR_INCLUDE: as an /I root its 2007 reflection/reflection.h (const char* const* templates) shadowed the native
# one through relative lookups and broke util/Sound.h (C2440) for every Sound target.
VENDOR_ROOTS = [ROOT / 'tools/rbxgs/Client/Network/raknet30/Source', ROOT / 'tools/rbxgs/Client/Network']


def header_include_flags(header, destination, extra=()):
    """Known vendor roots required by real native headers, never guessed from analog text."""
    native_headers = ROOT / 'rebuild/2008-06/native-headers'
    # Auto-added includes can reach RakNet/Ogre headers too; they may be native-headers-relative
    # ('OgreAuto/CylinderTransform2008.h' needs the Ogre root for <OgreVector2.h>).
    paths = [ROOT / header] + [Path(p) if Path(p).is_absolute() else native_headers / p for p in extra]
    if destination:
        paths.append(ROOT / destination)
    seen, text = set(), ''
    while paths:
        path = paths.pop()
        if path in seen or not path.is_file():
            continue
        seen.add(path)
        unit = path.read_text(errors='replace')
        text += '\n' + unit
        for relative in re.findall(r'^\s*#include\s*"([^"/]+(?:/[^"/]+)*)"', unit, re.M):
            candidate = native_headers / relative
            if candidate.is_file():
                paths.append(candidate)
    flags = []
    ogre = ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include'
    if re.search(r'^\s*#include\s*[<\"]Ogre[A-Za-z0-9_]+\.h[>\"]', text, re.M) and ogre.is_dir():
        flags.append('/I' + str(ogre))
    # Vendor headers native headers include but native-headers lacks: RakNet 3.0 (DS_LinkedList.h, ...) and the
    # 2007 network layer (Streaming.h, ...).  Appended last, so native-headers copies still win.
    included = re.findall(r'^\s*#include\s*[<"]([^>"]+)[>"]', text, re.M)
    for vendor in VENDOR_ROOTS:
        if vendor.is_dir() and any(not (native_headers / name).is_file() and (vendor / name).is_file() for name in included):
            flags.append('/I' + str(vendor))
            if vendor.name == 'Source' and '/FIwinsock2.h' not in flags:
                # RakNet wants winsock2.h; windows.h alone pulls winsock.h first (C2011 sockaddr).  Declarations only.
                flags.append('/FIwinsock2.h')
    return ' '.join(flags)


def unmapped_externs(packet, header, destination):
    """Analog globals cannot become native source without a real provider."""
    missing = []
    visible = header + '\n' + destination
    for declaration in re.findall(r'(?m)^\s*extern\b[^;]+;', packet):
        # Function imports are not variable providers.  The old token scan
        # misclassified return types such as `long` as globals.
        body = re.sub(r'^\s*extern\s+(?:"C"\s+)?', '', declaration).rstrip(';').strip()
        if '(' in body or re.match(r'^(?:class|struct|union|enum|typedef)\b', body):
            continue
        names = []
        for declarator in body.split(','):
            found = re.search(r'([A-Za-z_]\w*)\s*(?:\[[^]]*\])?\s*$', declarator.strip())
            if found:
                names.append(found.group(1))
        for name in names:
            if name not in visible:
                missing.append(name)
    return sorted(set(missing))


REGISTRY_EXTRA = [ROOT / 'work/native-client/unnamed-identities.json', ROOT / 'work/native-client/vtable-names.json']


def load_registry():
    """Identity registry plus identity-recovery side files (unnamed-identities.json from the identity session,
    vtable-names.json); the main registry wins on any address both name.  Gates still prove every name."""
    registry = json.loads(REGISTRY.read_text()) if REGISTRY.is_file() else {}
    for path in REGISTRY_EXTRA:
        if path.is_file():
            try:
                extra = json.loads(path.read_text())
            except ValueError:
                continue
            for addr, row in extra.items():
                old = registry.get(addr) or {}
                if not old.get('name') or old.get('placeholder') or old['name'].startswith('func_'):
                    registry[addr] = dict(row, kind=row.get('kind', 'code'), placeholder=False)
    return registry


REMAINING = None


def remaining_set():
    """Addresses the website counts as 'other remaining' (neither integrated nor native-owned): remaining-3901.json,
    written from docs/integration.json; empty when absent."""
    global REMAINING
    if REMAINING is None:
        path = ROOT / 'work/native-client/remaining-3901.json'
        REMAINING = set(json.loads(path.read_text())) if path.is_file() else set()
    return REMAINING


def split_qual(name):
    """'RBX::X<class std::a<char>,1>::f' -> ['RBX', 'X<class std::a<char>,1>', 'f'] (splits at template depth 0)."""
    parts, depth, cur, i = [], 0, '', 0
    while i < len(name):
        ch = name[i]
        depth += {'<': 1, '>': -1}.get(ch, 0)
        if depth == 0 and name.startswith('::', i):
            parts.append(cur)
            cur, i = '', i + 2
            continue
        cur += ch
        i += 1
    return parts + [cur]


def signature_qual(sig):
    """Qualified function name of an undname signature (template args may contain spaces and parentheses)."""
    depth = 0
    for i, ch in enumerate(sig):
        depth += {'<': 1, '>': -1}.get(ch, 0)
        if ch == '(' and depth == 0 and not sig[:i].endswith('operator'):
            head, start, depth2 = sig[:i], i, 0
            for j in range(len(head) - 1, -1, -1):
                depth2 += {'>': 1, '<': -1}.get(head[j], 0)
                if head[j] == ' ' and depth2 == 0:
                    return head[j + 1:]
            return head
    return sig


TEMPLATE_VENDOR = ('std::', 'boost::', 'G3D::', 'ATL::', 'Ogre::', 'stdext::', 'CXTP', 'Wml::')


def template_targets(tried, max_size):
    """Template-member instantiations the free gate (native_template_gate.py) found without an exact header body:
    the model writes the template definition plus the explicit instantiation."""
    results_path = ROOT / 'work/native-client/template-gate/results.json'
    if not results_path.is_file():
        return []
    results = json.loads(results_path.read_text())
    registry = json.loads(REGISTRY.read_text())
    out = []
    for addr, res in results.items():
        row = registry.get(addr) or {}
        sig = row.get('signature') or ''
        # 'draft' = the header already has a (different) body: a shared-header fix, not a probe definition.
        if res['status'] != 'needs-body' or addr in tried or not sig:
            continue
        headers = []
        for name in dict.fromkeys(re.findall(r'\b((?:[A-Za-z_]\w*::)*[A-Za-z_]\w*)(?=\s*<|\s*::|\s*[\s*&>,)])', sig)):
            if not name.startswith(TEMPLATE_VENDOR):
                header = declaring_header(name)
                if header and header not in headers:
                    headers.append(header)
        size = len(match.target('2008-06', addr)[0])
        analog = ROOT / 'src/2008-06' / (addr + '.cpp')
        if not headers or not (16 <= size <= max_size) or not analog.is_file():
            continue
        header = Path(headers[0])
        EXTRA_INCLUDES[addr] = [str(Path(h).resolve()) for h in headers[1:]]
        inst = re.sub(r'\b(?:virtual|static) |\b__(?:thiscall|cdecl|stdcall|fastcall) ', '',
                      re.sub(r'^(?:public|private|protected): ', '', sig)).strip()
        out.append(dict(addr=addr, symbol=row['name'], decl=sig, owner=row.get('owner_class') or '',
                        qual=signature_qual(sig), header=header.relative_to(ROOT).as_posix() if header.is_absolute() else str(header),
                        dest='', size=size, name_source=row.get('name_source', ''), placeholder=False, unmapped=[],
                        new_source=True, template_inst='template ' + inst + ';'))
    return out


def registry_classes(queue_classes):
    """Extra conversion rows from the identity registry: named, non-template members of non-vendor classes that the
    queue never listed (766 at last count).  Header = the native (else donor) header that defines the class and
    mentions the method; every later targets() filter (identity, 100% analog, preflight, gates) still applies."""
    registry = load_registry()
    listed = {m['addr'] for cl in queue_classes for m in cl['methods']}
    names = collections.Counter(row.get('name') for row in registry.values())
    grouped = collections.defaultdict(list)
    for addr, row in registry.items():
        owner = row.get('owner_class') or ''
        name = row.get('name') or ''
        if (addr in listed or row.get('kind') != 'code' or row.get('placeholder') or not owner or '<' in owner
                or name.startswith('??$') or names[name] > 1 or not row.get('signature')
                or owner.startswith(('G3D::', 'std::', 'boost::', 'ATL::', 'Ogre::', 'XTPPaintThemes', 'Wml::'))):
            continue
        grouped[owner].append((addr, row))
    out = []
    for owner, rows in grouped.items():
        header = declaring_header(owner)
        if not header:
            continue
        header_path = Path(header)
        text = header_path.read_text(errors='replace')
        methods = []
        for addr, row in rows:
            leaf = row['signature'].split('(')[0].split()[-1].rsplit('::', 1)[-1]
            if re.search(r'\b%s\s*\(' % re.escape(leaf), text):
                methods.append(dict(addr=addr, symbol=row['name'], declaration=row['signature'].strip(), state='convert',
                                    headers=[header_path.relative_to(ROOT).as_posix()], evidence='identity-registry'))
        if methods:
            out.append(dict(owner=owner, template=False, headers=[], methods=methods))
    return out


def targets(prefixes, max_size, tried, allow_new_source=False):
    """Queue rows an LLM can rewrite: one real header declaring it, a native .cpp for the class, a 100% analog."""
    global PREFLIGHT_BLOCKED
    PREFLIGHT_BLOCKED = []
    leased = lease_globs()
    classes = json.loads(QUEUE.read_text())['classes']
    if allow_new_source:
        classes = classes + registry_classes(classes)
        templates = template_targets(tried, max_size)
    else:
        templates = []
    registry = load_registry()
    native_exact = native_exact_addresses()
    solved = ({row['owner'] for row in json.loads(LAYOUTS.read_text()).get('rows', []) if row.get('accepted')}
              if LAYOUTS.is_file() else set())
    # An address several symbols share is an ICF fold: one body, no unique identity to recover.
    shared = collections.Counter(m['addr'] for cl in classes for m in cl['methods'])
    out = []
    for cl in classes:
        if (cl['template'] or (prefixes and not cl['owner'].startswith(tuple(prefixes)))
                or cl['owner'].startswith(('G3D::', 'std::', 'boost::'))):     # library code: vendor lane, not native
            continue
        dest, is_new = destination_for(cl['owner'])
        if not dest:
            PREFLIGHT_BLOCKED.append({'owner': cl['owner'], 'reason': 'multiple-native-destinations'})
            continue
        if is_new and not allow_new_source:
            continue
        if cl['owner'].startswith('Ogre::Rbx') and cl['owner'] not in solved:
            PREFLIGHT_BLOCKED.append({'owner': cl['owner'], 'reason': 'layout-solver-not-accepted'})
            continue
        if dest and any(fnmatch.fnmatch(dest, g) for g in leased):
            continue
        destination_text = (ROOT / dest).read_text(errors='replace') if dest and (ROOT / dest).is_file() else ''
        for m in cl['methods']:
            identity = registry.get(m['addr'])
            method_headers = m.get('headers', cl.get('headers', []))
            if not method_headers and '`' not in m['declaration']:
                # No native header declares it: the 2007 rbxgs header that defines the class (e.g. util/Math.h for
                # RBX::Math) is the header the native build already falls back to.
                donor = donor_header_for(cl['owner'], m['declaration'].split('(')[0].split()[-1].rsplit('::', 1)[-1])
                method_headers = [donor] if donor else []
            if len(method_headers) == 2:          # e.g. Humanoid.h / Humanoid2008.h: the one the destination includes
                used = [h for h in method_headers if h.split('native-headers/', 1)[-1] in destination_text]
                method_headers = used if len(used) == 1 else method_headers
            # 'name-only' = queue saw only reference votes; the identity registry's exact, non-placeholder name below
            # is the proof the gate needs (compiler-generated members stay out).
            state_ok = (m['state'] == 'convert' or (m['state'] == 'name-only' and '`' not in m['declaration'])
                        # Stale queue 'native-exact': the site counts it neither integrated nor owned (remaining set).
                        or (m['state'] == 'native-exact' and m['addr'] in remaining_set()))
            if (m['addr'].lower() in native_exact or not state_ok or len(method_headers) != 1 or '$' in m['symbol'] or m['addr'] in tried
                    or shared[m['addr']] > 1 or not identity or identity['placeholder']
                    or identity['name'] != m['symbol'] or identity.get('owner_class') != cl['owner']):
                continue
            analog = ROOT / 'src/2008-06' / (m['addr'] + '.cpp')
            packet = analog.read_text(errors='replace') if analog.is_file() else ''
            if not packet or '// from server: 100%' not in packet[:400]:
                continue
            recipe = (match.directives(packet).get('lib') or '').split(' ')[0]
            if recipe and not recipe.startswith(('rbxgs', 'openrbx')):
                # e.g. Scintilla (scintilla-mfc-1.20): the real vendor .cpp already matches; its file statics
                # (_scintillaEditState) live there, so an LLM rewrite against a header can never compile.
                PREFLIGHT_BLOCKED.append({'addr': m['addr'], 'owner': cl['owner'], 'reason': 'vendor-library-lane',
                                          'names': [recipe]})
                continue
            qual = m['declaration'].split('(')[0].split()[-1]          # RBX::Camera::lookAt
            name = qual.rsplit('::', 1)[-1]
            if not qual.startswith(cl['owner'] + '::') or not re.fullmatch(r'~?[A-Za-z_][A-Za-z_0-9]*', name):
                PREFLIGHT_BLOCKED.append({'addr': m['addr'], 'owner': cl['owner'],
                                          'reason': 'unsupported-declaration-spelling', 'names': [qual]})
                continue
            text = Path(ROOT / method_headers[0]).read_text(errors='replace')
            if name not in text or re.search(r'\b%s\s*\([^;{}]*\)[^;{}]*\{' % re.escape(name), text):
                continue                                   # undeclared, or the header already defines it inline
            leaf = cl['owner'].rsplit('::', 1)[-1]
            # A class-name token can be the class declaration, not a declared
            # ctor/copy-ctor.  Defining an implicit special member is illegal.
            if name in (leaf, '~' + leaf) and not re.search(r'\b~?%s\s*\(' % re.escape(leaf), text):
                PREFLIGHT_BLOCKED.append({'addr': m['addr'], 'owner': cl['owner'],
                                          'reason': 'special-member-not-declared', 'names': [name]})
                continue
            destination_text = (ROOT / dest).read_text(errors='replace') if dest and (ROOT / dest).is_file() else ''
            # Placeholder analog globals: the model must name the real static; the gate's identity closure rejects
            # any wrong name, so these are tried (ranked last) instead of blocked.
            missing = unmapped_externs(packet, text, destination_text)
            size = len(match.target('2008-06', m['addr'])[0])
            if 16 <= size <= max_size:
                out.append(dict(addr=m['addr'], symbol=m['symbol'], decl=m['declaration'], owner=cl['owner'],
                                qual=qual, header=method_headers[0], dest=dest, size=size,
                                name_source=identity['name_source'], placeholder=False, unmapped=missing,
                                new_source=is_new))
    # ponytail: smallest first, highest pass rate; add a byte-weighted order once rates are measured
    return sorted(out + templates, key=lambda t: t['size'])


def ask(model, prompt, name):
    """-> the last ```cpp block of one model reply, or None."""
    TOOL.reply, TOOL.tokens = '', {}
    if model.startswith('opencode'):
        text = ask_opencode(model, prompt)
    else:
        from roc import providers
        try:
            options = {'allow_cloud': True, 'timeout': 120, 'max_tokens': 4096}
            if model in LOW_EFFORT:
                options['reasoning_effort'] = 'low'
            gen = providers.generate(model, prompt, options)
            text = gen.text
            TOOL.tokens = {'in': (gen.input_tokens or 0) + (gen.cached_tokens or 0), 'out': gen.output_tokens or 0}
            if getattr(gen, 'cli_cost_usd', None) is not None:
                TOOL.tokens['usd'] = round(gen.cli_cost_usd, 5)
        except providers.ProviderError as error:
            if providers.quota_exhausted(str(error)):
                EXHAUSTED.add(model)
                spent_quota(model)
            print('provider error', model, name, str(error)[:200], flush=True)
            return None
    TOOL.reply = text or ''
    # Only a block that defines the target counts; models sometimes echo header excerpts as code.
    blocks = re.findall(r'```(?:cpp|c\+\+)?\s*\n(.*?)```', text or '', re.S) or [text or '']   # codex CLI strips fences
    code = [c for c in blocks if re.search(r'::\s*%s\s*\(' % re.escape(name), c)]
    if not code:  # keep the unusable reply so the prompt can be tuned from what the model actually wrote
        (HERE / 'noreply').mkdir(parents=True, exist_ok=True)
        (HERE / 'noreply' / ('%s-%d.txt' % (re.sub(r'\W+', '_', name)[:40], int(time.time() * 1000)))).write_text(text or '', errors='replace')
    return code[-1] if code else None


def ask_opencode(model, prompt):
    """One `opencode run` with the task as an attached file (no command-line length limit)."""
    with tempfile.TemporaryDirectory(prefix='roc-native-llm-') as folder:
        task = Path(folder) / 'task.txt'
        task.write_text(prompt, encoding='utf-8')
        run = subprocess.run([str(OPENCODE), 'run', '-m', model, '--format', 'json', '--file', str(task),
                              'Follow the attached task exactly. Return only the requested code. Do not use tools.'],
                             cwd=folder, capture_output=True, text=True, encoding='utf-8', errors='replace',
                             timeout=120)
    events = [e for e in map(_json, run.stdout.splitlines()) if isinstance(e, dict)]
    if any(e.get('type') == 'error' and re.search(r'provider\.\w+-limit', json.dumps(e.get('error')))
           for e in events):                                        # free-limit / go-limit: quota spent
        retry = max([e.get('error', {}).get('retryAfterMs') or 0 for e in events if e.get('type') == 'error'] + [0])
        # OpenCode's free limit is per account: every free model is out until the provider's retry time.
        for free in [model] + ([m for m in BEST_FREE if m.endswith('-free')] if model.endswith('-free') else []):
            EXHAUSTED.add(free)
            spent_quota(free, retry / 1000 if retry else 12 * 3600)
    used = [e['part']['tokens'] for e in events if isinstance(e.get('part'), dict) and isinstance(e['part'].get('tokens'), dict)]
    TOOL.tokens = {'in': sum((u.get('input') or 0) + ((u.get('cache') or {}).get('read') or 0) for u in used),
                   'out': sum((u.get('output') or 0) + (u.get('reasoning') or 0) for u in used)}
    return ''.join(e['part'].get('text', '') for e in events
                   if e.get('type') == 'text' and isinstance(e.get('part'), dict))


def _json(line):
    try:
        return json.loads(line)
    except ValueError:
        return None


HEADER_INDEX = None


def declarations_for(error, limit=6):
    """Declarations of the identifiers a compile error names, found in native-headers/, so the retry can use them."""
    global HEADER_INDEX
    names = []
    for name in re.findall(r"'([A-Za-z_][\w:]*)'", error):
        leaf = name.split('::')[-1]
        if len(leaf) > 2 and leaf not in names and leaf not in ('class', 'struct', 'enum', 'int', 'void', 'this'):
            names.append(leaf)
    if not names:
        return ''
    if HEADER_INDEX is None:
        HEADER_INDEX = [(path, path.read_text(errors='replace').splitlines())
                        for path in (ROOT / 'rebuild/2008-06/native-headers').rglob('*.h')]
    out = []
    for name in names[:limit]:
        decl = re.compile(r'\b(class|struct|enum|typedef)\s+(\w+\s+)?%s\b|[\w:<>,*& ]+[\s*&]%s\s*\(' % (re.escape(name), re.escape(name)))
        for path, lines in HEADER_INDEX:
            hit = next((i for i, line in enumerate(lines) if decl.search(line) and not line.strip().startswith('//')), None)
            if hit is not None:
                start = max(0, hit - 2)
                block = lines[start:hit + 12]
                out.append('// %s (%s)\n%s' % (name, path.relative_to(ROOT).as_posix(), '\n'.join(block)))
                break
    if not out:
        return ''
    return ('\n--- DECLARATIONS FOR NAMES IN THAT ERROR (from native-headers; use these exact names/signatures, '
            'or the header member at the same offset) ---\n' + '\n\n'.join(out)[:4000])


def learn_identities(t, res):
    """If the target's only rejections are unproven callee identities, bind them from the exact candidate's relocations
    (native_reference_alias_bind.py) into CLOSURE. -> True when new bindings were added."""
    try:
        manifest = json.loads(Path(res['manifest']).read_text())
    except (OSError, ValueError, KeyError):
        return False
    rows = [s for f in manifest.get('families', []) for s in f.get('symbols', [])
            if s.get('symbol') == t['symbol']]
    errors = [e for r in rows for j in r.get('rejections', []) if j.get('addr') == t['addr'] for e in j.get('errors', [])]
    if not errors or not all(e.startswith('unproven reference identity') for e in errors):
        return False
    objs = sorted(Path(res['manifest']).parent.rglob('candidate.obj'), key=lambda p: p.stat().st_mtime)
    if not objs:
        return False
    receipt = Path(res['manifest']).parent / 'alias-bind.json'
    # The gate's own snapshot binds the target itself (registry targets are absent from CLOSURE); with CLOSURE
    # alias-bind refused every one of them ('requires closure-bound emitted owner').
    snapshot = Path(res['manifest']).parent.parent / 'closure.json'
    tick = time.time()
    subprocess.run([sys.executable, str(ROOT / 'work/native-client/native_reference_alias_bind.py'), '--object', str(objs[-1]),
                    '--symbol', t['symbol'], '--address', t['addr'],
                    '--closure', str(snapshot if snapshot.is_file() else CLOSURE), '--output', str(receipt)],
                   cwd=ROOT, capture_output=True, text=True)
    tool_time('identity_learn', time.time() - tick)
    try:
        found = json.loads(receipt.read_text()).get('identity_bindings', [])
    except (OSError, ValueError):
        return False
    with CLOSURE_LOCK:                 # parallel workers append here; read-modify-write must not interleave
        closure = json.loads(CLOSURE.read_text())
        have = {(b['symbol'], b.get('addr')) for b in closure['bindings']}
        new = [dict(symbol=b['symbol'], addr=b['address'], address=b['address'], evidence=b.get('identity_evidence', 'llm-exact-reference'),
                    votes=b.get('votes', 1), body_exact=False, function_start=False)
               for b in found if (b['symbol'], b['address']) not in have]
        if not new:
            return False
        closure['bindings'] += new
        tmp = CLOSURE.with_suffix('.%d.tmp' % threading.get_ident())
        tmp.write_text(json.dumps(closure))
        os.replace(tmp, CLOSURE)
    print('%s learned %d callee identities' % (t['addr'], len(new)), flush=True)
    return True


import threading
TOOL = threading.local()      # per-thread tool timings of the current try: {step: seconds}
EXTRA_INCLUDES = {}           # addr -> headers found for names a compile error reported missing
FORCE_INCLUDES = {}           # addr -> /FI headers an include-order guard (C1189) asked for
SEARCH_ROOTS = [ROOT / 'rebuild/2008-06/native-headers', ROOT / 'tools/rbxgs/Client/Network/raknet30/Source',
                ROOT / 'tools/rbxgs/Client/Rendering/g3d/include', DONOR_INCLUDE]   # donor last, included by name
# No 2007 donor tree here: its v8datamodel/Surface.h etc. redefine native classes (C2011) and block the real include.
DECL_FILES = None


def tool_time(step, seconds):
    times = getattr(TOOL, 'times', None)
    if times is not None:
        times[step] = round(times.get(step, 0.0) + seconds, 1)


DECL_SPACES = {}
DECL_MEMO = {}


def declaring_header(name):
    """Header (native-headers first, then RakNet) that defines class/struct/enum NAME or declares a function NAME.
    Memoized; files without the name as plain text are skipped before any regex (startup took 8 min: 1426 names x
    every header x 3 patterns)."""
    global DECL_FILES
    if name in DECL_MEMO:
        return DECL_MEMO[name]
    if DECL_FILES is None:
        # Per root, shallowest path first: canonical v8tree/Instance.h before snapshot copies such as
        # instance-ancestor-inline/v8tree/Instance.h, which redefine classes (C2011) when mixed in.
        DECL_FILES = [(path, path.read_text(errors='replace')) for root in SEARCH_ROOTS
                      for path in sorted(root.rglob('*.h'), key=lambda p: (len(p.relative_to(root).parts), str(p)))
                      # Hyphenated native-headers folders (part-embedded/, axis-vector-negation/, ...) are per-TU
                      # variant snapshots; auto-including one mixes 2007 IPipelined/Edge with 2008 ones (C2011).
                      if not (root.name == 'native-headers' and '-' in path.relative_to(root).parts[0])]
    leaf = re.escape(name.split('::')[-1])
    kinds = [r'^\s*(?:class|struct|enum)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;]*$' % leaf,
             r'^[^/#\n]*[\w*&>]\s+%s\s*\([^;{]*\)\s*;' % leaf,
             r'^\s*namespace\s+%s\s*\{?\s*$' % leaf]           # RBX::Math, ... (C2653 / C3083)
    # Namespace-aware: RBX::Primitive must not resolve to G3D's RenderDevice::Primitive enum.  Qualified names need
    # their namespaces in the file; unqualified ones try `namespace RBX` files first.
    spaces = [ns for ns in name.split('::')[:-1] if ns]
    if not DECL_SPACES:
        for path, text in DECL_FILES:
            DECL_SPACES[path] = set(re.findall(r'\bnamespace\s+(\w+)', text))
    raw = name.split('::')[-1]
    files = [(path, text) for path, text in DECL_FILES if raw in text] if raw else DECL_FILES
    passes = [spaces] if spaces else [['RBX'], []]
    found = None
    for wanted in passes:
        for pattern in kinds:
            rx = re.compile(pattern, re.M)
            found = next((str(path) for path, text in files
                          if all(ns in DECL_SPACES[path] for ns in wanted) and rx.search(text)), None)
            if found:
                break
        if found:
            break
    DECL_MEMO[name] = found
    return found


DONOR_CLASSES = {}


def donor_header_for(owner, method):
    """ROOT-relative rbxgs header defining class OWNER (right namespaces) and mentioning METHOD( inside it, provided
    no native header defines the class (a native override always wins)."""
    if owner.startswith(('G3D::', 'std::', 'boost::', 'Ogre::')) or '::' not in owner:
        return None
    if owner not in DONOR_CLASSES:
        declaring_header('')
        leaf, spaces = owner.rsplit('::', 1)[-1], owner.split('::')[:-1]
        head = re.compile(r'\b(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % re.escape(leaf))
        native = ROOT / 'rebuild/2008-06/native-headers'
        hits = [(p, t) for p, t in DECL_FILES if head.search(t)
                and all(re.search(r'\bnamespace\s+%s\b' % re.escape(ns), t) for ns in spaces)]
        DONOR_CLASSES[owner] = (None if any(native in p.parents for p, _ in hits) else
                                next(((p, t) for p, t in hits if DONOR_INCLUDE in p.parents), None))
    found = DONOR_CLASSES[owner]
    if not found or not re.search(r'\b%s\s*\(' % re.escape(method), found[1]):
        return None
    return found[0].relative_to(ROOT).as_posix()


def donor_relative(path):
    path = Path(path)
    return path.relative_to(DONOR_INCLUDE).as_posix() if DONOR_INCLUDE in path.parents else str(path)


def missing_names(error):
    names = re.findall(r"undefined (?:type|class) '([\w:]+)'|'([\w:]+)' : undeclared identifier|'(\w+)' : is not a member of"
                       r"|identifier '(\w+)'|'(\w+)': identifier not found"
                       # C3083 / C2653 / C2681: a class used through :: or dynamic_cast that is only forward-declared
                       r"|'(\w+)': the symbol to the left of a '::' must be a type|'(\w+)' : is not a class or namespace name"
                       r"|'([\w:]+) \*' : invalid (?:expression|target) type"
                       # C2514: `new ArrowTool` / temporaries of a class that is only forward-declared
                       r"|'([\w:]+)' : class has no constructors", error)
    return [next(x for x in group if x) for group in names]


FILE_GLOBALS = None


def file_globals(t):
    """Real names of .cpp-defined globals this target may use, from their dynamic initializers in the registry
    (??__Eprop_TeamColor@RBX@@YAXXZ -> RBX::prop_TeamColor): matched on the property word of setX/getX/... or the class."""
    global FILE_GLOBALS
    if FILE_GLOBALS is None:
        FILE_GLOBALS = []
        registry = json.loads(REGISTRY.read_text()) if REGISTRY.is_file() else {}
        for row in registry.values():
            found = re.fullmatch(r'\?\?__E(\w+)@((?:\w+@)*)@YAXXZ', row.get('name') or '')
            if found:
                spaces = [x for x in found.group(2).split('@') if x][::-1]
                FILE_GLOBALS.append('::'.join(spaces + [found.group(1)]))
    leaf = t['qual'].rsplit('::', 1)[-1]
    word = re.sub(r'^(?:set|get|is|has|on|raise|describe)', '', leaf)
    owner = t['owner'].rsplit('::', 1)[-1]
    hits = [g for g in FILE_GLOBALS if (len(word) > 2 and word.lower() in g.lower()) or owner.lower() in g.lower()][:12]
    return ('--- KNOWN FILE GLOBALS (defined in the original .cpp; declare `extern` with the right type if used) ---\n'
            + '\n'.join(hits) + '\n') if hits else ''


EXACT_ROWS = None


def sibling_examples(t, limit=2, chars=1500):
    """Up to LIMIT proven byte-exact bodies (earlier native_llm exacts) of the same class, else the same destination
    file: the real house style (member names, casts, temporaries) for this target."""
    global EXACT_ROWS
    if EXACT_ROWS is None:
        EXACT_ROWS = []
        for line in LOG.read_text(encoding='utf-8').splitlines() if LOG.is_file() else []:
            row = _json(line)
            if row and row.get('status') == 'inactive_exact':
                EXACT_ROWS.append(row)
    picks = []
    for same in (lambda r: r.get('owner') == t['owner'], lambda r: t.get('dest') and r.get('dest') == t['dest']):
        for r in reversed(EXACT_ROWS):
            if len(picks) >= limit:
                break
            if r['addr'] == t['addr'] or r['addr'] in {p[0] for p in picks} or not same(r):
                continue
            sub = {'cache': 'recheck', 'dest': 'dest'}.get(r.get('model'), 'try%s' % r.get('attempt'))
            donor = folder(r) / sub / 'donor' / 'donor.cpp'
            if donor.is_file():
                picks.append((r['addr'], r['qual'], donor.read_text(errors='replace')[:chars]))
    if not picks:
        return ''
    return ('\n--- PROVEN EXACT SIBLINGS (byte-exact against the original; follow their style and member names) ---\n'
            + '\n'.join('// %s %s\n%s' % p for p in picks) + '\n')


def bytes_identical(feedback):
    """Gate feedback whose every candidate is byte-identical (relocations masked): only references/identity differ."""
    lines = [x for x in (feedback or '').splitlines() if x.startswith('candidate ')]
    return bool(lines) and all('IDENTICAL' in x for x in lines)


def dest_body(t):
    """The target's body already written in its native .cpp, prefixed by the file-local classes/structs it names
    (with their out-of-class members), so it gates standalone.  '' when the .cpp has no such body."""
    path = ROOT / t['dest'] if t.get('dest') else None
    if not path or not path.is_file():
        return ''
    from native_transplant_probe import body_at
    text = path.read_text(errors='replace')
    marker = '::'.join(t['qual'].split('::')[-2:])
    try:
        body = body_at(text, marker)
    except ValueError:
        return ''
    helpers = []
    for found in re.finditer(r'^[ \t]*(?:class|struct)[ \t]+(\w+)[^;{(]*\{', text, re.M):
        name = found.group(1)
        if not re.search(r'\b%s\b' % name, body) or name == t['owner'].rsplit('::', 1)[-1]:
            continue
        depth, end = 0, found.end() - 1
        for end in range(found.end() - 1, len(text)):
            depth += {'{': 1, '}': -1}.get(text[end], 0)
            if depth == 0:
                break
        helpers.append(text[found.start():text.find(';', end) + 1])
        for member in re.finditer(r'^[ \t]*[\w:<>&* ]*\b%s::(operator\s*\(\)|~?\w+)\s*\(' % name, text, re.M):
            try:
                helpers.append(body_at(text[member.start():], name + '::' + member.group(1)))
            except ValueError:
                pass
    return '\n\n'.join(dict.fromkeys(h.strip() for h in helpers + [body]))


def class_block(leaf, limit=3000):
    """The real native declaration of class LEAF (header text from 'class Leaf ... {' to its closing brace), or ''."""
    path = declaring_header(leaf)
    if not path:
        return ''
    text = Path(path).read_text(errors='replace')
    found = re.search(r'^[ \t]*(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % re.escape(leaf), text, re.M)
    if not found:
        return ''
    depth, i = 0, found.end() - 1
    for i in range(found.end() - 1, min(len(text), found.end() + 20000)):
        depth += {'{': 1, '}': -1}.get(text[i], 0)
        if depth == 0:
            break
    block = text[found.start():i + 2]
    rel = Path(path).relative_to(ROOT).as_posix() if Path(path).is_relative_to(ROOT) else path
    return '// %s\n%s' % (rel, block if len(block) <= limit else block[:limit] + '\n  // ... (truncated)')


def class_context(t, names, header, analog='', most=4):
    """Declarations of the other classes the target touches (from the address names), sent with the first prompt so
    models call members that exist instead of guessing (C2039)."""
    owner = t['owner'].rsplit('::', 1)[-1]
    classes = []
    found = re.findall(r'(?:class )?((?:\w+::)*\w+)(?:::~?\w+(?:<[^>]*>)?\(| `RTTI)', names)
    found += re.findall(r'\bRBX::(?:\w+::)*([A-Z]\w+)\b', analog)                 # analog type uses
    found += re.findall(r'(?:shared_ptr|weak_ptr|<|\(|,|^)\s*(?:const\s+)?([A-Z]\w+)\s*[*&>]', header, re.M)
    for qual in found:
        leaf = qual.rsplit('::', 1)[-1]
        if (leaf == owner or leaf in classes or qual.startswith(('G3D', 'std', 'boost')) or leaf in ('Vector3', 'Matrix3',
                'CoordinateFrame', 'Vector2', 'Color3', 'Color4', 'Rect2D', 'Ray', 'Plane', 'Sphere', 'Box', 'AABox')
                or re.search(r'\b(?:class|struct)\s+%s\b[^;]*\{' % re.escape(leaf), header)):
            continue
        classes.append(leaf)
    blocks = [b for b in (class_block(leaf) for leaf in classes[:most * 2]) if b][:most]
    return ('--- REAL DECLARATIONS OF OTHER CLASSES IT USES ---\n' + '\n\n'.join(blocks) + '\n') if blocks else ''


GAPS = HERE / 'header-gaps.jsonl'
GAPS_LOCK = threading.Lock()


def log_header_gaps(t, error):
    """Header-recovery queue: members a compile says a native class lacks.  'proven' when the target's own address
    names (identity registry) show the binary calls Class::member: header work, not something more LLM tries fix."""
    rows = []
    for member, cls in re.findall(r"'(\w+)' : is not a member of '([\w:]+)'", error):
        proven = bool(re.search(r'\b%s::%s\(' % (re.escape(cls.rsplit('::', 1)[-1]), re.escape(member)), t.get('names', '')))
        rows.append(dict(time=round(time.time(), 1), cls=cls, member=member, proven=proven, target=t['addr'], qual=t['qual'],
                         evidence=next((line for line in t.get('names', '').splitlines()
                                        if '%s::%s(' % (cls.rsplit('::', 1)[-1], member) in line), '')))
    if rows:
        with GAPS_LOCK, GAPS.open('a') as out:
            out.write(''.join(json.dumps(r) + '\n' for r in rows))


UNDNAME = ROOT / 'tools/vc2008rtm/Program Files/Microsoft Visual Studio 9.0/VC/bin/undname.exe'
ANNOTATE = {}            # lazily loaded: registry names + exe image


def annotate_asm(asm):
    """Names for the raw addresses in the target assembly, so models stop guessing callees, RTTI casts and globals:
    identity-registry symbols (demangled with VC9 undname), RTTI TypeDescriptor names and string literals."""
    if not ANNOTATE:
        ANNOTATE['reg'] = json.loads(REGISTRY.read_text()) if REGISTRY.is_file() else {}
        ANNOTATE['base'], ANNOTATE['image'] = match._image('2008-06')
    reg, base, image = ANNOTATE['reg'], ANNOTATE['base'], ANNOTATE['image']
    notes, decorated = {}, {}
    for hexaddr in dict.fromkeys(re.findall(r'\b0x([0-9a-f]{6,8})\b', asm)):
        va = int(hexaddr, 16)
        row = reg.get('%08x' % va)
        if row and row.get('name') and not row.get('placeholder'):
            real = re.fullmatch(r'__real@([0-9a-f]{8}|[0-9a-f]{16})', row['name'])
            if real:
                bits = bytes.fromhex(real.group(1))
                value = struct.unpack('>f' if len(bits) == 4 else '>d', bits)[0]
                if len(bits) == 4:
                    text = next(t for t in ('%%.%dg' % k % value for k in range(1, 10))
                                if struct.pack('>f', float(t)) == bits)
                    notes['0x' + hexaddr] = 'float constant %sf' % text
                else:
                    notes['0x' + hexaddr] = 'double constant %r' % value
            else:
                decorated['0x' + hexaddr] = row['name']
            continue
        rva = va - base
        if not 0 <= rva < len(image) - 8:
            continue
        name = image[rva + 8:rva + 8 + 200].split(b'\0')[0]
        if name.startswith((b'.?AV', b'.?AU')) and name.endswith(b'@@'):        # RTTI TypeDescriptor
            parts = name[4:-2].decode('latin-1').split('@')
            notes['0x' + hexaddr] = 'RTTI type %s' % '::'.join(reversed([p for p in parts if p]))
            continue
        text = image[rva:rva + 120].split(b'\0')[0]
        if len(text) >= 4 and all(32 <= c < 127 for c in text):
            notes['0x' + hexaddr] = 'string "%s"' % text.decode('ascii')
    if decorated and UNDNAME.is_file():
        try:
            out = subprocess.run([str(UNDNAME), *decorated.values()], capture_output=True, text=True, timeout=20).stdout
            plain = dict(re.findall(r'Undecoration of :- "(.*?)"\s*\n\s*is :- "(.*?)"', out))
        except (OSError, subprocess.TimeoutExpired):
            plain = {}
        for addr, name in decorated.items():
            notes[addr] = re.sub(r'\s+', ' ', plain.get(name, name)).replace('__thiscall ', '').strip()
    if not notes:
        return ''
    return ('--- KNOWN NAMES FOR ADDRESSES ABOVE (from the binary/identity registry; use these, never guess) ---\n'
            + '\n'.join('%s = %s' % kv for kv in sorted(notes.items())) + '\n')


PREFLIGHT_CACHE = {}
PREFLIGHT_LOCK = threading.Lock()


def slim(t):
    """Target fields worth logging (drops the bulky prompt-only address-name text)."""
    return {k: v for k, v in t.items() if k != 'names'}


TYPE_DEFINED = {}


def type_defined(leaf):
    """Some native header (or vendor root) defines type LEAF: a class/struct/union/enum body, possibly across lines,
    or a typedef.  Forward declarations alone do not count."""
    if leaf not in TYPE_DEFINED:
        declaring_header('')                               # loads DECL_FILES
        rx = re.compile(r'\b(?:class|struct|union|enum)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{|\btypedef\b[^;]*\b%s\s*;'
                        % (re.escape(leaf), re.escape(leaf)))
        TYPE_DEFINED[leaf] = any(rx.search(text) for _, text in DECL_FILES)
    return TYPE_DEFINED[leaf]


def implicit_member(t):
    """A default/copy ctor, dtor or operator= the owner's header never declares is compiler-generated: no source can
    define it (C2600 for Part::Part 00598f10, FunctionScriptSlot::FunctionScriptSlot 0061f960)."""
    leaf, name = t['owner'].rsplit('::', 1)[-1], t['qual'].rsplit('::', 1)[-1]
    path = ROOT / t['header']
    text = path.read_text(errors='replace') if path.is_file() else ''
    params = (re.search(r'\((.*)\)', t.get('decl') or '') or re.search('()', '')).group(1).strip()
    if name == leaf and params in ('', 'void'):
        declared = re.search(r'\b%s\s*\(\s*(?:void)?\s*\)' % re.escape(leaf), text)
    elif name == leaf and re.fullmatch(r'(?:class|struct) [\w:]*\b%s const &' % re.escape(leaf), params):
        declared = re.search(r'\b%s\s*\(\s*const\s+%s\s*&' % (re.escape(leaf), re.escape(leaf)), text)
    elif name == '~' + leaf:
        declared = re.search(r'~%s\s*\(' % re.escape(leaf), text)
    elif name == 'operator=':
        declared = re.search(r'\boperator\s*=\s*\(', text)
    else:
        return False
    return not declared


def headers_compile(t):
    """No-LLM preflight: the target's own signature with an empty body through the real gate.  -> '' when the
    headers compile, else the header-side error (every model answer would fail on it too).  Errors in the probe/donor
    body (empty-body C2512, C4716...) are not header failures.  Cached per header + destination + flags."""
    key = (t['header'], t['dest'], flags_of(t['dest']) or analog_flags(t['addr']), tuple(EXTRA_INCLUDES.get(t['addr'], [])))
    with PREFLIGHT_LOCK:
        if key in PREFLIGHT_CACHE:
            return PREFLIGHT_CACHE[key]
    decl = t['decl'].strip().rstrip(';')
    # Undecorated declarations carry access and calling-convention words that are not valid in a definition.
    decl = re.sub(r'^\s*(?:(?:public|private|protected):\s*)?', '', decl)
    decl = re.sub(r'\b(?:virtual|static|inline|explicit)\s+|\b__thiscall\s+', '', decl)
    decl = decl.replace(t['qual'].rsplit('::', 1)[-1] + '(', t['qual'] + '(', 1) if t['qual'] not in decl else decl
    status, feedback = prove(t, decl + '\n{\n}\n', folder(t) / 'preflight', depth=2)
    error = ''
    if status == 'compile_failed':
        first = next((line for line in feedback.splitlines() if re.search(r'error C\d+', line)), '')
        leaf = re.escape(t['owner'].rsplit('::', 1)[-1])
        # The owner class itself invisible (e.g. inside `#ifdef NATIVE_SIMJOB_PENDING`: layout still pending) is a
        # header state too: no body can compile until the guard is lifted.
        hidden = re.search(r"error C2653: '%s' : is not a class or namespace name" % leaf, feedback)
        if hidden or re.search(r'\.h\(\d+\)\s*:\s*(?:fatal )?error|fatal error C1083|error C1189', first, re.I):
            first = hidden.group(0) + ' (class hidden by a header #if guard?)' if hidden else first
            error = first.strip()
    with PREFLIGHT_LOCK:
        PREFLIGHT_CACHE[key] = error
    return error


def prove(t, body, out, depth=0):
    """Gate, then drop the gate's bulk/object folders and closure copy (~5 MB + objects per gate; 98 GB filled the
    disk on 2026-11-15).  The donor, plan and result stay for cache regates and promotion."""
    import shutil
    try:
        return _prove(t, body, out, depth)
    finally:
        for junk in list(out.glob('run-bulk-*')) + list(out.glob('*-destination-*')):
            shutil.rmtree(junk, ignore_errors=True)
        (out / 'closure.json').unlink(missing_ok=True)


def _prove(t, body, out, depth=0):
    """Write donor + one-row plan, run the existing isolated gates. -> (status, feedback text)."""
    if t.get('template_inst'):
        # `template<class T> bool RBX::X<T>::f(...) {...}` + `template bool RBX::X<A>::f(...);` at global scope.
        ns, marker = '', split_qual(t['qual'])[-1].split('<')[0]     # ctor `X<A>::X<A>`: definition spells `X(`
    else:
        ns, cls = t['owner'].rsplit('::', 1) if '::' in t['owner'] else ('', t['owner'])
        marker = t['qual'][len(ns) + 2:] if ns and t['qual'].startswith(ns + '::') else t['qual']
        body = body.replace(t['qual'] + '(', marker + '(')      # definition goes inside the namespace block
    # The donor's folder becomes an include dir; keep the gate's own output out of it, or the gate
    # sees the include search change mid-compile and voids an exact result as 'stale'.
    (out / 'donor').mkdir(parents=True, exist_ok=True)
    (out / 'donor' / 'donor.cpp').write_text(body + '\n')
    destination = (ROOT / t['dest']).read_text(errors='replace') if t['dest'] and (ROOT / t['dest']).is_file() else ''
    support_includes = re.findall(r'^\s*#include\s*<((?:Ogre|G3D)[A-Za-z0-9_]+\.h)>', destination, re.M)
    header_root = ROOT / 'rebuild/2008-06/native-headers'
    for relative in re.findall(r'^\s*#include\s*"([^"]+)"', destination, re.M):
        native = (header_root / relative).resolve()
        if native.is_file() and native != (ROOT / t['header']).resolve():
            support_includes.append(str(native))
    support_includes += [h for h in EXTRA_INCLUDES.get(t['addr'], []) if h not in support_includes]
    # A destination without its own profile would compile at /Od and can never match: use the analog's exact flags.
    base = flags_of(t['dest']) or analog_flags(t['addr'])
    if '/MD' in base.split() and '/D_AFXDLL' not in base:
        base += ' /D_AFXDLL'      # MFC headers reached through any include refuse /MD without it (C1189)
    flags = ' '.join(x for x in (base, header_include_flags(t['header'], t['dest'], support_includes)) if x)
    # Native opt-in guards (#ifdef NATIVE_CLUMP_DECL in v8world/AssemblyLayout.h hides EdgeIterator/Clump): the native
    # .cpp files #define them before including the header, so the probe must too.
    header_text = (ROOT / t['header']).read_text(errors='replace') if (ROOT / t['header']).is_file() else ''
    for guard in dict.fromkeys(re.findall(r'^\s*#\s*ifdef\s+(NATIVE_\w+)', header_text, re.M)):
        flags += ' /D' + guard
    for forced in FORCE_INCLUDES.get(t['addr'], []):
        flags += ' /FI' + forced
    plan = {'plans': [{'owner': t['owner'], 'headers': [t['header']],
                       'source': str((out / 'donor' / 'donor.cpp').relative_to(ROOT)),
                       'namespace': ns, 'roc_cl': 21022, 'roc_flags': flags, 'destination': t['dest'],
                       'support_includes': support_includes,
                       'probe_records': ['%s=%s#0' % (t['addr'], marker)],
                       'rows': [{'addr': t['addr'], 'symbol': t['symbol'], 'marker': marker + '#0', 'header': t['header'],
                                 'namespace': ns, 'roc_cl': 21022, 'roc_flags': flags,
                                 'evidence': 'llm rewrite of server-exact analog; every gate rerun'}]}]}
    (out / 'plan.json').write_text(json.dumps(plan, indent=1))
    for attempt in range(2):
        with CLOSURE_LOCK:
            if not CLOSURE.is_file():
                CLOSURE.write_text(BASE_CLOSURE.read_text())
            # Own snapshot per gate: another worker learning identities mid-gate would void it as 'inputs changed'.
            snapshot = out / 'closure.json'
            closure = json.loads(CLOSURE.read_text())
            own = [b for b in closure['bindings'] if (b.get('addr') or '').lower() == t['addr'].lower()]
            if own and not any(b.get('symbol') == t['symbol'] for b in own):
                # Closure binding (compiled from the real header) differs from the registry name only by access
                # (005e83c0 clipToSafeSize: header protected IAE, registry guess private AAE): the header wins.
                t['symbol'] = own[0]['symbol']
                for one in plan['plans']:
                    for row in one['rows']:
                        row['symbol'] = t['symbol']
                (out / 'plan.json').write_text(json.dumps(plan, indent=1))
            if not own:
                # Registry-sourced targets: the identity registry names the target itself (the queue rows always
                # came with a closure binding).  Snapshot-only; callee identities still need their own proof.
                closure['bindings'].append(dict(symbol=t['symbol'], addr=t['addr'], address=t['addr'], votes=1,
                                                evidence='identity-registry:' + str(t.get('name_source', '')),
                                                body_exact=False, function_start=True))
            for b in own:
                # Same symbol seen only as a reference alias: the target address is the analyzed function's own start.
                if b.get('symbol') == t['symbol'] and not b.get('function_start'):
                    b['function_start'] = True
                    b['evidence'] = str(b.get('evidence', '')) + '+analyzed-function-start'
            snapshot.write_text(json.dumps(closure))
        tick = time.time()
        run = subprocess.run([sys.executable, str(ROOT / 'work/native-client/native_convert_run.py'), '--plan', str(out / 'plan.json'),
                              '--closure', str(snapshot), '--batch', '0', '--out', str(out / 'run'),
                              '--source-includes', '--source-preamble', '--add-flags', '/GS-'],
                             cwd=ROOT, capture_output=True, text=True)
        try:
            res = json.loads((out / 'run' / 'result.json').read_text())
        except (OSError, ValueError):
            return 'tool-error', (run.stdout + run.stderr)[-1500:]
        status = res['requested'][0]['status']
        tool_time('compile_gate', time.time() - tick)
        # Byte-identical but blocked only by unproven callee names: prove them from the exact body, regate once.
        if status != 'draft' or attempt or not learn_identities(t, res):
            break
    if status == 'compile_failed':
        error = str(res.get('first_compile_error', ''))
        log_header_gaps(t, error)
        # Include-order guards (C1189): MFC before windows.h (XTP property grid items), G3DAll before glut.
        forced = ('afxwin.h' if 'WINDOWS.H already included' in error else
                  'G3DAll.h' if 'G3DAll.h must be included' in error else '')
        if forced and depth < 2 and forced not in FORCE_INCLUDES.get(t['addr'], []):
            FORCE_INCLUDES.setdefault(t['addr'], []).append(forced)
            return prove(t, body, out, depth + 1)
        if depth < 2:
            tick = time.time()
            have = set(EXTRA_INCLUDES.get(t['addr'], [])) | {str((ROOT / t['header']).resolve())}
            # A donor (2007 rbxgs) header is included by its relative name ("util/Math.h"): the gate searches
            # native-headers before rbxgs/Client/App/include, so a native override wins and nothing is defined twice.
            # A name the destination TU defines itself (file-local helper such as HeadMesh's CylinderTransform) is not
            # a header's: auto-including another class of that name only adds a wrong type and its includes.
            local = (ROOT / t['dest']).read_text(errors='replace') if t.get('dest') and (ROOT / t['dest']).is_file() else ''
            wanted = [n for n in missing_names(error)
                      if not re.search(r'^\s*(?:class|struct)\s+%s\b' % re.escape(n.split('::')[-1]), local, re.M)]
            found = [donor_relative(h) for h in (declaring_header(n) for n in wanted) if h]
            found = [h for h in found if h not in have]
            tool_time('include_search', time.time() - tick)
            if found:
                before = list(EXTRA_INCLUDES.get(t['addr'], []))
                EXTRA_INCLUDES.setdefault(t['addr'], []).extend(dict.fromkeys(found))
                tool_time('include_retries', 1)
                retried = prove(t, body, out, depth + 1)
                # An alternate header snapshot can redefine a class the destination already has (C2011): undo it.
                if retried[0] == 'compile_failed' and 'C2011' in retried[1]:
                    # Drop only the added header(s) that redefine a class; keep the ones that were needed.
                    clash = {Path(m).name.lower() for m in re.findall(r'([^\s(]+\.h)\(\d+\) : error C2011', retried[1])}
                    keep = [h for h in found if Path(h).name.lower() not in clash]
                    EXTRA_INCLUDES[t['addr']] = before + keep
                    return prove(t, body, out, depth + 1 if keep and depth < 1 else 2)
                return retried
        return status, 'Compile error:\n' + error[:1500] + declarations_for(error)
    if status == 'inactive_exact':
        return status, ''
    objs = sorted(Path(res['manifest']).parent.rglob('*.obj'))
    tick = time.time()
    diff = subprocess.run([str(ROOT / 'roc.cmd'), 'native-asm', '2008-06', t['addr'], '--obj', str(objs[0]),
                           '--sym', t['symbol'], '--context', '2', '--head', '80'],
                          cwd=ROOT, capture_output=True, text=True).stdout if objs else ''
    tool_time('asm_diff', time.time() - tick)
    return status, 'Bytes differ (%s). Original vs your code, assembly diff:\n%s' % (status, diff[-3000:])


def folder(t):
    return HERE / ('%s-%s' % (t['addr'], re.sub(r'\W+', '_', t['qual'].rsplit('::', 1)[-1])[:40]))


CLOSURE_LOCK = threading.Lock()
RUN_ID = int(time.time())   # groups this process's attempt rows into one run (dashboard bytes-per-run table)
SLOTS = {}                 # worker thread -> dashboard slot number
GUI = bool(os.environ.get('ROC_GUI_EVENTS'))


def gui(event, **fields):
    """Dashboard event (roc gui Workers page live chat); no-op outside the dashboard."""
    if GUI:
        fields.setdefault('slot', SLOTS.setdefault(threading.get_ident(), len(SLOTS)))
        if fields['slot'] is None:
            del fields['slot']            # run-level event: shown as "roc", not a worker
        print('ROC_EVENT ' + json.dumps(dict(event=event, **fields)), flush=True)


PICK_STATE = HERE / 'pick-state.json'


def pick_mode(mode):
    """'auto' alternates explore / top runs (state in pick-state.json); the first auto run explores."""
    if mode != 'auto':
        return mode
    last = json.loads(PICK_STATE.read_text()).get('last') if PICK_STATE.is_file() else 'top'
    mode = 'top' if last == 'explore' else 'explore'
    PICK_STATE.write_text(json.dumps({'last': mode}))
    return mode


QUOTA = HERE / 'quota-spent.json'      # model -> time its free/plan quota ran out (skipped for 12 h)


def spent_quota(model, seconds=12 * 3600):
    """Record when MODEL's quota comes back (provider retry time when given)."""
    spent = json.loads(QUOTA.read_text()) if QUOTA.is_file() else {}
    spent[model] = time.time() + seconds
    QUOTA.write_text(json.dumps(spent, indent=1))


def fast_ladder():
    """Fast (exploit) runs: Sonnet x3 + Opus + the best free (OpenCode or NVIDIA NIM) model by bytes/hour that answers a ping now."""
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    import native_llm_models
    spent = json.loads(QUOTA.read_text()) if QUOTA.is_file() else {}
    dead = dead_models()
    ranked = [r['model'] for r in native_llm_models.report()
              if r['model'].startswith(('opencode', 'nvidia:')) and r['model'] not in dead and time.time() > spent.get(r['model'], 0)]
    candidates = [m for m in ranked + [m for m in BEST_FREE + BEST_NIM if m not in ranked and m not in dead] if time.time() > spent.get(m, 0)]

    def answers(model):
        try:
            return bool(ask(model, 'Output exactly one ```cpp block: `int Probe::ping() { return 1; }`', 'ping'))
        except Exception:
            return False
    with ThreadPoolExecutor(max(1, len(candidates))) as pool:     # one parallel ping round, not 120 s per model
        alive = dict(zip(candidates, pool.map(answers, candidates)))
    for model in candidates:
        if alive[model]:
            return ['claude:sonnet'] * 3 + ['claude:opus', model]
        print('free model not answering, skipped:', model, flush=True)
    return ['claude:sonnet'] * 3 + ['claude:opus']


def top_models(count):
    """Best per-worker bytes/hour from native_llm_models.py (live models only; retired codex workers excluded)."""
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    import native_llm_models
    dead = dead_models()
    rows = [r for r in native_llm_models.report() if r['model'] != 'cache' and not r['model'].startswith('codex:')
            and r['model'] not in dead and r['bytes_per_hour'] > 0]
    best = {}
    for r in rows:                       # one entry per model name (beam-free exists as opencode/ and opencode-go/)
        best.setdefault(r['model'].split('/')[-1], r['model'])
    return list(best.values())[:count] or ['claude:sonnet']


def work(t, ladder, tries, start=0):
    analog = (ROOT / 'src/2008-06' / (t['addr'] + '.cpp')).read_text(errors='replace')
    directives = match.directives(analog)
    if 'lib' in directives:
        from roc import libs
        recipe, _, path = directives['lib'].partition(' ')

        def expanded():
            try:
                return libs.unit(recipe, path.strip(), 21022)
            except (Exception, SystemExit) as error:  # one unbuildable library unit must not abort the batch
                return 'library unit did not preprocess: %s' % str(error)[:300]
        # Recipe preprocessors can emit megabytes of dependency declarations.
        # Give the actual trailing analog body instead of an empty directive.
        if t.get('donor_body'):
            # The exact function from the donor file beats a trailing excerpt that may not contain it.
            analog += ('\n// 2007 donor source of THIS function (byte-exact in its own unit; 2008 header names may differ):\n'
                       + t['donor_body'][:12000])
        else:
            # The generated unit as written (before preprocessing) is the analog body; its 32 KB preprocessed tail
            # is mostly STL/intrinsic declarations, so send that only when the raw unit is unavailable.
            units = libs.units_used(analog)
            raw = next(iter(next(iter(units.values())).values()), '') if units else ''
            analog += ('\n// Analog unit source (analog types are not native declarations):\n' + raw[:12000] if raw else
                       '\n// Expanded recipe trailing source excerpt (analog types are not native declarations):\n' + expanded()[-8000:])
    elif t.get('donor_body'):
        # Upstream/donor source this function was ported from (e.g. G3D GFont for Ogre::VRbxFont).
        analog += ('\n// Upstream source this function was ported from (types/API may differ; follow the asm):\n'
                   + t['donor_body'][:12000])
    header = (ROOT / t['header']).read_text(errors='replace')[:40000]
    asm = subprocess.run([str(ROOT / 'roc.cmd'), 'native-asm', '2008-06', t['addr']], cwd=ROOT,
                         capture_output=True, text=True).stdout[-6000:]
    note = ('\nThe analog uses placeholder globals %s. They stand for real statics/globals: use the name the REAL HEADER '
            '(or its includes) declares for that object; never declare a new one.\n' % ', '.join(t['unmapped'])) if t.get('unmapped') else ''
    if t.get('template_inst'):
        note += ('\nTEMPLATE MEMBER: this function is one instantiation of a class/function template member.  Write the '
                 'TEMPLATE DEFINITION fully qualified at global scope (`template<class T, ...> Ret NS::Cls<T, ...>::%s(...) '
                 '{...}`; the header only declares it), then on its own line the explicit instantiation exactly:\n%s\n'
                 'If the compiler reports C3416 (the header already declares an explicit specialization), write the full '
                 'specialization instead (`template<> Ret NS::Cls<Args>::f(...) {...}`) and no instantiation line.\n'
                 % (split_qual(t['qual'])[-1], t['template_inst']))
    names = annotate_asm(asm) + file_globals(t)
    note += sibling_examples(t)
    t = dict(t, names=names)          # header-gap logging checks compile errors against these binary names
    prompt = (RULES.format(decl=t['decl'], qual=t['qual']) + note + '\n--- REAL HEADER %s ---\n%s\n--- REFERENCE ANALOG ---\n%s\n'
              '--- ORIGINAL ASSEMBLY (the target) ---\n%s\n%s%s' % (t['header'], header, analog, asm, names,
                                                                 class_context(t, names, header, analog)))
    status, history = 'no-reply', []
    if ladder:     # model runs only (regates pass no ladder): skip targets whose headers cannot compile at all
        broken = ('' if t.get('template_inst') else
                  'implicit member: compiler-generated, the header never declares it' if implicit_member(t) else headers_compile(t))
        if broken:
            print('%s %-34s %4dB header-blocked: %s' % (t['addr'], t['qual'][-34:], t['size'], broken[-160:]), flush=True)
            gui('native_result', file=t['qual'], addr=t['addr'], local_exact=0, seconds=0, error=broken,
                error_summary='header-blocked (no model call): ' + broken[-120:])
            with LOG.open('a') as log:
                log.write(json.dumps(dict(slim(t), model='preflight', attempt=-2, status='header-blocked', time=round(time.time(), 1),
                                          run=RUN_ID, error=broken[-400:])) + '\n')
            return t, None
    # Re-gate an already generated answer before spending another provider call.
    # Driver/header flag changes are valid new evidence; model text is not resent unchanged.
    cached = sorted((folder(t)).glob('try*/donor/donor.cpp'))
    leaf = re.escape('::'.join(t['qual'].split('::')[-2:]))
    if cached and not re.search(leaf + r'\s*\([^;{}]*\)\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?(?::[^;{]*)?\{',
                                cached[-1].read_text(errors='replace')):
        cached = []         # an old reply with prose and no definition: regating it is a tool-error, not evidence
    if not cached and ladder:
        native = dest_body(t)
        if native:
            # The native .cpp already has this body (HeadBuilder::buildTop ...): gate it free first.
            started = time.time()
            TOOL.times = {}
            status, feedback = prove(t, native, folder(t) / 'dest')
            with LOG.open('a') as log:
                log.write(json.dumps(dict(slim(t), model='dest', attempt=-1, status=status, time=round(time.time(), 1), run=RUN_ID,
                                          tool=TOOL.times, llm_seconds=0.0, gate_seconds=round(time.time() - started, 1))) + '\n')
            print('%s %-34s %4dB dest  %-16s' % (t['addr'], t['qual'][-34:], t['size'], status), flush=True)
            gui('native_result', file=t['qual'] + ' [native .cpp]', addr=t['addr'], local_exact=int(status == 'inactive_exact'),
                seconds=round(time.time() - started, 1), error='', error_summary=status + ' | existing native body, no model call')
            if status == 'inactive_exact':
                return t, folder(t) / 'dest'
            if bytes_identical(feedback):
                return t, None          # bytes already exact; only reference/identity proof is missing: no model can fix it
            history =['\n--- CURRENT NATIVE .CPP BODY (with its file-local helpers) ---\n```cpp\n%s\n```\n--- RESULT ---\n%s\n'
                       'Fix it. Same output rules.\n' % (native, feedback)]
    if cached:
        body = cached[-1].read_text(errors='replace')
        started = time.time()
        TOOL.times = {}
        status, feedback = prove(t, body, folder(t) / 'recheck')
        row = dict(slim(t), model='cache', attempt=-1, status=status, time=round(time.time(), 1), run=RUN_ID, tool=TOOL.times, llm_seconds=0.0,
                   gate_seconds=round(time.time() - started, 1))
        with LOG.open('a') as log:
            log.write(json.dumps(row) + '\n')
        print('%s %-34s %4dB cache %-16s' % (t['addr'], t['qual'][-34:], t['size'], status), flush=True)
        if status == 'inactive_exact':
            return t, folder(t) / 'recheck'
        history = ['\n--- YOUR PREVIOUS ANSWER ---\n```cpp\n%s\n```\n--- RESULT ---\n%s\nFix it. Same output rules.\n'
                   % (body, feedback)]
    for n in range(tries):
        live = [m for m in ladder if m not in EXHAUSTED]
        if not live:
            break                                       # every quota spent: stop instead of burning attempts
        rest = [m for m in live if m != FIRST_MODEL] or live
        if n == 0 and FIRST_MODEL in live:
            model = FIRST_MODEL                         # cheap first shot on every target (Haiku ~8x cheaper per exact)
        else:
            model = rest[(start + n) % len(rest)]       # retries rotate the stronger models
        TOOL.times = {}
        started = time.time()
        sent = prompt + ''.join(history)
        gui('native_started', file=t['qual'], addr=t['addr'], method='%s | %d B | try %d | %s' % (t['qual'], t['size'], n, model),
            message='Asking ' + model)
        try:
            body = ask(model, sent, t['qual'].rsplit('::', 1)[-1])
        except subprocess.TimeoutExpired:
            body = None
        llm = time.time() - started
        if not body:
            status, feedback = 'no-reply', ''
            reply = getattr(TOOL, 'reply', '')
            FAILS[model] = 0 if reply else FAILS[model] + 1
            if FAILS[model] >= 3 and model not in EXHAUSTED:
                EXHAUSTED.add(model)          # keeps timing out / erroring: stop using it this run
                print('dropping model after 3 timeouts/errors:', model, flush=True)
            if reply:   # tell the next model why: no definition, plus the declarations the reply wanted
                asked = ' '.join("'%s'" % n for n in re.findall(r'`([A-Za-z_][\w:]*)`', reply))
                history = ['\n--- PREVIOUS REPLY (no ```cpp definition of `%s(`) ---\n%s\n--- RESULT ---\nNo usable code.%s\n'
                           'Answer with the definition now; unknown names are resolved by the harness.\n'
                           % (t['qual'], reply[:1500], declarations_for(asked))]
        else:
            FAILS[model] = 0
            TOOL.times = {}
            status, feedback = prove(t, body, folder(t) / ('try%d' % n))
        row = dict(slim(t), model=model, attempt=n, status=status, time=round(time.time(), 1), run=RUN_ID,
                   tool=dict(getattr(TOOL, 'times', None) or {}), tokens=dict(getattr(TOOL, 'tokens', None) or {}),
                   llm_seconds=round(llm, 1),
                   gate_seconds=round(time.time() - started - llm, 1))
        with LOG.open('a') as log:
            log.write(json.dumps(row) + '\n')
        # Full conversation for the dashboard's Native LLM page.  ponytail: never pruned; add a keep-last-N if disk matters.
        (HERE / 'chats').mkdir(exist_ok=True)
        (HERE / 'chats' / ('%d-%s-%d.json' % (int(row['time'] * 1000), t['addr'], n))).write_text(json.dumps(dict(
            addr=t['addr'], qual=t['qual'], size=t['size'], model=model, attempt=n, status=status, time=row['time'],
            tokens=row['tokens'], llm_seconds=row['llm_seconds'], gate_seconds=row['gate_seconds'],
            prompt=sent, reply=getattr(TOOL, 'reply', ''), result=(feedback or '')[:6000])), errors='replace')
        if getattr(TOOL, 'reply', ''):
            gui('log', message='%s reply | %s | %s tokens\n%s' % (model, t['qual'], row['tokens'] or '?', TOOL.reply[:8000]))
        gui('native_result', file='%s [%s]' % (t['qual'], model.split('/')[-1]), addr=t['addr'],
            local_exact=int(status == 'inactive_exact'), seconds=round(time.time() - started, 1),
            error='' if status == 'inactive_exact' else (feedback or status)[:4000],
            error_summary='%s | llm %.0fs gate %.0fs | %s tok' % (status, llm, row['gate_seconds'],
                                                               sum(row['tokens'].get(k, 0) for k in ('in', 'out')) or '?'))
        print('%s %-34s %4dB try%d %-16s %-28s llm %5.1fs gate %5.1fs' % (t['addr'], t['qual'][-34:], t['size'], n,
              status, model.split('/')[-1][:28], row['llm_seconds'], row['gate_seconds']), flush=True)
        if status == 'inactive_exact':
            return t, folder(t) / ('try%d' % n)
        if status == 'draft' and bytes_identical(feedback):
            return t, None              # bytes exact, reference/identity gate open: another model try cannot help
        first_error = next((line for line in (feedback or '').splitlines() if re.search(r'error C\d+', line)), '')
        if status == 'compile_failed' and re.search(r'\.h(?:pp)?\(\d+\)\s*:\s*(?:fatal )?error', first_error):
            # The first error sits inside a header (native or vendor): a header gap or include-order problem that
            # another model answer cannot fix.  Logged to header-gaps.jsonl by the gate; skip the second try.
            return t, None
        if body:
            history = ['\n--- YOUR PREVIOUS ANSWER ---\n```cpp\n%s\n```\n--- RESULT ---\n%s\nFix it. Same output rules.\n'
                       % (body, feedback)]
    return t, None


def _regate(t):
    try:
        return work(t, [], 0)
    except (Exception, SystemExit) as error:
        print('regate failed', t.get('addr'), str(error)[:160], flush=True)
        return None


def main():
    global QUEUE, CLOSURE
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--limit', type=int, default=32)
    ap.add_argument('--jobs', type=int, default=8)   # owner: 2x the 4-job short runs
    ap.add_argument('--tries', type=int, default=2)   # 3rd try: 1.0% exact vs 4.5%/3.6% for tries 1-2
    ap.add_argument('--max-size', type=int, default=512)
    ap.add_argument('--models', default=None, help='comma ladder (default: CLAUDE_MODELS + --nim random BEST_NIM)')
    ap.add_argument('--nim', type=int, default=3, help='random BEST_NIM models added after the Claude models when --models is not given')
    ap.add_argument('--free', type=int, default=3, help='random BEST_FREE opencode models added after those')
    ap.add_argument('--pick', choices=('claude', 'auto', 'top', 'explore'), default='claude',
                    help='claude (default): DEFAULT_LADDER only; auto alternates explore/top; top = fast_ladder()')
    ap.add_argument('--first-model', default=FIRST_MODEL, help="model for every target's first try ('' = rotate)")
    ap.add_argument('--owner-prefix', action='append', default=[])
    ap.add_argument('--queue', type=Path, default=QUEUE, help='identity-backed conversion queue')
    ap.add_argument('--closure', type=Path, default=CLOSURE, help='matching identity evidence for native gates')
    ap.add_argument('--apply', action='store_true', help='promote exact survivors via native_autorecover (lease+draft+gates)')
    ap.add_argument('--new-source', action='store_true',
                    help='probe real-header methods with no native .cpp; never promotes them')
    ap.add_argument('--retry-address', action='append', default=[], metavar='ADDR',
                    help='recheck cached donor only for this address after a driver/input repair')
    ap.add_argument('--retry-failed', action='store_true', help='also retry earlier targets that never became exact')
    ap.add_argument('--retry-older-than', type=float, default=0, metavar='HOURS',
                    help='retry non-exact targets whose last model try is older than HOURS (after harness fixes)')
    ap.add_argument('--no-promote', action='store_true', help='skip the background promotion at run end')
    ap.add_argument('--regate-all', action='store_true', help='re-prove every earlier draft (after a gate fix)')
    ap.add_argument('--no-regate', dest='regate', action='store_false',
                    help='skip the no-LLM regate of earlier drafts after the batch')
    args = ap.parse_args()
    QUEUE, CLOSURE = args.queue.resolve(), args.closure.resolve()
    globals()['FIRST_MODEL'] = args.first_model
    picked = 'given' if args.models else 'claude' if args.pick == 'claude' else pick_mode(args.pick)
    if picked == 'claude':
        args.models = ','.join(DEFAULT_LADDER)
    if picked == 'top':
        args.models = ','.join(fast_ladder())
        print('pick: fast run = 3 sonnet + opus + best working free model', flush=True)
    if not args.models:
        print('pick: Claude + random NIM/free (explore run)', flush=True)
        import random
        dead = dead_models()
        nim = [m for m in BEST_NIM if m not in dead]
        free = [m for m in BEST_FREE if m not in dead]
        print('skipping dead models:', ','.join(sorted(dead & set(BEST_NIM + BEST_FREE))) or '-', flush=True)
        args.models = ','.join(CLAUDE_MODELS + random.sample(nim, min(args.nim, len(nim)))
                               + random.sample(free, min(args.free, len(free))))
    print('models:', args.models, flush=True)
    gui('stage', slot=None, message='Native LLM | ' + args.models.replace(',', ', '))
    HERE.mkdir(parents=True, exist_ok=True)
    started = time.time()
    prior_log = LOG.read_text().count('\n') if LOG.is_file() else 0
    # 'Tried' = used all its tries at least once; a target cut short by a quick restart stays fresh.
    model_tries = collections.Counter(json.loads(l)['addr'] for l in LOG.open()
                                      if json.loads(l)['model'] not in ('cache', 'preflight')) if LOG.is_file() else {}
    tried = {a for a, n in model_tries.items() if n >= args.tries}
    if args.retry_older_than:
        # Targets whose last model try predates harness fixes get a fresh chance (they failed under an older harness).
        cutoff = time.time() - args.retry_older_than * 3600
        last = {}
        for line in LOG.open():
            row = json.loads(line)
            if row['model'] not in ('cache', 'preflight'):
                last[row['addr']] = max(last.get(row['addr'], 0), row.get('time', 0))
        exact = {json.loads(l)['addr'] for l in LOG.open() if json.loads(l)['status'] == 'inactive_exact'}
        tried = {a for a in tried if a in exact or last.get(a, 0) >= cutoff}
    if args.retry_failed:   # harness fixes since the last try (flags, includes, identities) help old misses too
        tried = {json.loads(l)['addr'] for l in LOG.open() if json.loads(l)['status'] == 'inactive_exact'} if LOG.is_file() else set()
    for address in args.retry_address:
        tried.discard(address.lower())
    todo = targets(args.owner_prefix, args.max_size, tried, args.new_source)
    history = [json.loads(l) for l in LOG.open()] if LOG.is_file() else []
    owner_exact = {r.get('owner') for r in history if r['status'] == 'inactive_exact'}
    owner_tries = collections.Counter(r.get('owner') for r in history)
    # Park targets that never compiled to a draft in 6+ model tries: they need header recovery (members the native
    # headers lack), not more LLM calls.  A header or destination edit after the last try wakes them.
    tries_of = collections.Counter(r['addr'] for r in history if r['model'] != 'cache')
    drafted = {r['addr'] for r in history if r['status'] in ('draft', 'inactive_exact')}
    last_try = {r['addr']: r.get('time', 0) for r in history}
    def parked(t):
        if tries_of[t['addr']] < 6 or t['addr'] in drafted:
            return False
        changed = max((ROOT / p).stat().st_mtime for p in (t['header'], t['dest']) if p and (ROOT / p).is_file())
        return changed < last_try.get(t['addr'], 0)
    park = [t for t in todo if parked(t)]
    if park:
        print('parked %d targets (6+ tries, never a draft, headers unchanged)' % len(park), flush=True)
        todo = [t for t in todo if t not in park]
    # Never-tried targets first (run 16 spent its whole budget on leftovers while 55 fresh ones waited), then owners
    # with exacts, then the rest; placeholder-global targets last.
    # Website 'other remaining' functions first: an exact there moves the public count (others are already owned).
    # Bytes/hour: expected bytes per try = size x smoothed exact rate of its size bucket (history, Claude rows).
    # Smallest-first left 128-512 B targets (~1400 B/worker-hour) behind 32-64 B ones (~650).
    bucket = lambda size: min(7, max(0, size.bit_length() - 5))
    seen_b = collections.Counter(bucket(r.get('size', 0)) for r in history if str(r.get('model', '')).startswith('claude'))
    won_b = collections.Counter(bucket(r.get('size', 0)) for r in history
                                if str(r.get('model', '')).startswith('claude') and r['status'] == 'inactive_exact')
    expected = lambda t: t['size'] * (won_b[bucket(t['size'])] + 1) / (seen_b[bucket(t['size'])] + 10)
    rank = lambda t: (t['addr'] not in remaining_set(), tries_of[t['addr']] > 0, bool(t.get('unmapped')),
                      0 if t['owner'] in owner_exact else 2 if owner_tries[t['owner']] >= 6 else 1, -expected(t))
    todo = sorted(todo, key=rank)[:args.limit]
    if args.retry_address:
        wanted = {address.lower() for address in args.retry_address}
        todo = [target for target in todo if target['addr'].lower() in wanted]
    PREFLIGHT.write_text(json.dumps(PREFLIGHT_BLOCKED, indent=1) + '\n')
    print('%d targets (%d B)' % (len(todo), sum(t['size'] for t in todo)), flush=True)
    with ThreadPoolExecutor(args.jobs) as pool:
        def _safe(it):
            try:
                return work(it[1], args.models.split(','), args.tries, it[0])
            except (Exception, SystemExit) as error:
                print('target failed', it[1].get('addr'), str(error)[:160], flush=True)
                return None
        done = [r for r in pool.map(_safe, enumerate(todo)) if r]
    if args.regate:
        history = [json.loads(l) for l in LOG.open()] if LOG.is_file() else []
        won = {r['addr'] for r in history if r['status'] == 'inactive_exact'}
        # Drafts plus answers a harness bug stopped before gating (tool-error): re-gate them free after fixes.
        drafts = {r['addr'] for r in history if r['status'] in ('draft', 'tool-error')} - won - {t['addr'] for t, d in done if d}
        again = [t for t in targets(args.owner_prefix, args.max_size, set(), args.new_source) if t['addr'] in drafts]
        # Only drafts with new evidence since their last gate (learned closure, header/destination or harness
        # edit): re-proving all ~250 every run took 20+ minutes and blocked the next run.
        gated = {}
        for r in history:
            gated[r['addr']] = max(gated.get(r['addr'], 0), r.get('time', 0))
        # Harness edits no longer count: they made every run re-prove all ~250 drafts (20+ min, rarely a gain).
        # After a real gate fix, pass --regate-all once.
        harness = 0
        def stale(t):
            # Not CLOSURE: it changes on every learn, and learning already regates its own target at once.
            inputs = [ROOT / t['header']] + ([ROOT / t['dest']] if t['dest'] else [])
            return max([harness] + [p.stat().st_mtime for p in inputs if p.is_file()]) > gated.get(t['addr'], 0)
        again = [t for t in again if args.regate_all or stale(t)]
        print('regate %d drafts' % len(again), flush=True)
        with ThreadPoolExecutor(args.jobs) as pool:
            done += [r for r in pool.map(lambda t: _regate(t), again) if r]
    exact = [(t, d) for t, d in done if d]
    print('exact %d/%d (%d B)' % (len(exact), len(done), sum(t['size'] for t, _ in exact)), flush=True)
    gui('benchmark', slot=None, completed=len(done), matched=len(exact), improved=0)
    attempts = [json.loads(line) for line in LOG.read_text().splitlines()[prior_log:]] if LOG.is_file() else []
    failures = collections.Counter(row['status'] for row in attempts if row['status'] != 'inactive_exact')
    calls = collections.Counter(row['model'] for row in attempts)
    exact_bytes = sum(t['size'] for t, _ in exact)
    wall = max(time.time() - started, .001)
    metric = dict(wall_seconds=round(wall, 2), calls_per_provider=calls, exact_targets=len(exact),
                  exact_bytes=exact_bytes, exact_bytes_per_hour=round(exact_bytes * 3600 / wall, 2),
                  exact_bytes_per_call=round(exact_bytes / max(1, len(attempts)), 2),
                  real_name_bytes=exact_bytes, placeholder_bytes=0,
                  top_failure_causes=failures.most_common(5))
    with METRICS.open('a') as stream:
        stream.write(json.dumps(metric, sort_keys=True) + '\n')
    try:      # combined bytes/hour across all runs and sessions -> native-llm/throughput.jsonl + run log
        sys.path.insert(0, str(ROOT / 'work/native-client'))
        import native_llm_models
        tp = native_llm_models.log_throughput(RUN_ID)
        print('combined B/hour: 1h %(bytes_per_hour_1h)d  6h %(bytes_per_hour_6h)d  24h %(bytes_per_hour_24h)d  (%(exact_functions)d exact fns)'
              % tp, flush=True)
    except Exception as error:          # reporting only
        print('throughput log failed:', error, flush=True)
    if exact and not args.no_promote:
        # Land new remaining-set exacts in native-classes (lease, draft, whole-TU proof) without blocking the next run.
        subprocess.Popen([sys.executable, str(ROOT / 'work/native-client/native_llm_promote.py'), '--only-remaining'],
                         cwd=ROOT / 'work/native-client', stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                         creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0) | getattr(subprocess, 'DETACHED_PROCESS', 0))
        print('promotion started in background (native-llm/promoted.json)', flush=True)
    for t, d in exact if args.apply else []:
        # Serial: one destination edit at a time; the runner leases, drafts, re-proves the whole TU.
        run = subprocess.run([sys.executable, str(ROOT / 'work/native-client/native_autorecover.py'), '--plan-file',
                              str(d / 'plan.json'), '--out', str(d / 'apply'), '--apply'],
                             cwd=ROOT, capture_output=True, text=True)
        print(t['addr'], 'apply:', (run.stdout.strip().splitlines() or [run.stderr[-300:]])[-1], flush=True)


if __name__ == '__main__':
    main()
