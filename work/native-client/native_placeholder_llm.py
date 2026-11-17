"""Placeholder lane (owner decision 2026-11-15: real-header recovery, inferred names): unnamed functions the identity
session could only name 'sub_<addr>' (unnamed-identities-inferred.json, confidence 'placeholder').
The model reads the target assembly + analog and answers either
  FREE:   ```cpp  RET sub_<addr>(PARAMS) { ... }```                 (static helper, no `this`)
  MEMBER: CLASS: RBX::Owner / ```decl RET sub_<addr>(PARAMS) [const];``` / ```cpp RET RBX::Owner::sub_<addr>(...) {...}```
For MEMBER the harness copies the class's native header into a shadow include dir with the declaration inserted into
the class body (`// INFERRED:` line), puts that dir first on the include path, and gates against it.  Every body must
compile against the real native headers and byte-match; the decorated name is read from the compiled object.
Exacts go to native-llm/attempts.jsonl (name_source inferred-placeholder; decl recorded for header promotion).
Usage: python native_placeholder_llm.py [--limit N] [--jobs J]"""
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
ap.add_argument('--jobs', type=int, default=8)
ap.add_argument('--max-size', type=int, default=8192, help='largest target in bytes (was a fixed 2048)')
ap.add_argument('--named', default='', help='JSON list of addresses with real registry names (free functions): '
                'the model writes that exact function; the gate requires its decorated symbol')
ap.add_argument('--regate', action='store_true', help='replay saved compile_failed answers through the gate (no model calls)')
args = ap.parse_args(ARGS)
ROOT = m.ROOT
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
OUT = ROOT / 'work/native-client/placeholder-lane'
OUT.mkdir(parents=True, exist_ok=True)
RESULTS = OUT / 'results.json'
HERE_PH = ROOT / 'work/native-client'
NAMED = {}                         # addr -> (decorated name, signature) in --named mode
results = json.loads(RESULTS.read_text()) if RESULTS.is_file() else {}
LADDER = ['claude:sonnet', 'claude:opus']

OFFSET_HACK = m.OFFSET_HACK
RULES = """You recover one unnamed function of the 2008 Roblox client as REAL native C++ against the real native headers.
Its name is unknown: call it `sub_{addr}` (an inferred placeholder).  Decide from the assembly whether it is
  - a FREE function (no `this` in ecx; cdecl/stdcall): reply with one ```cpp block defining `RET sub_{addr}(PARAMS)`
    (inside the right namespace if it uses RBX types, e.g. `namespace RBX {{ ... }}`), or
  - a MEMBER of an existing class (uses ecx as `this`, reads fields): reply exactly
      CLASS: <fully qualified class, e.g. RBX::Primitive>
      ```decl
      RET sub_{addr}(PARAMS) [const];
      ```
      ```cpp
      RET RBX::Primitive::sub_{addr}(PARAMS) [const] {{ ... }}
      ```
    The class must already exist in the native headers; field offsets must match the real class layout.
Use only types, members and functions the native headers declare (access fields by their real member names, never by casting `this` and adding offsets); never define your own classes/structs or padding layouts; never invent globals or `extern`s; no __emit/asm.
Reply with nothing else."""

# Header recovery inside the lane (owner 2026-11-16: the automatic integrator should do header/layout work too).
HEADER_RULE = """
If a native class LACKS a member this function needs (a compile error said "'x' : is not a member of 'Y'", or the
assembly calls/reads something the header does not declare), add it with ONE extra block:
```header-add
RBX::Class | declaration;   // evidence: <decorated symbol from the annotations, asm offset +0xNN, or donor header line>
```
One member per line (method declaration or data member), at most 6 lines. Add only what the binary proves; never padding
arrays, never placeholder fields, never redeclare a member the class already has. The harness puts the lines in a
private copy of that class's header for this compile only; they reach the real header only if the function is byte-exact."""


def target_asm(addr):
    """`roc native-asm` text for ADDR, cached in the lane folder (about 5 s per call; every try and run repeated it)."""
    cache = OUT / addr / 'asm.txt'
    if cache.is_file():
        return cache.read_text(errors='replace')
    text = subprocess.run([str(ROOT / 'roc.cmd'), 'native-asm', '2008-06', addr], cwd=ROOT, capture_output=True,
                          text=True).stdout
    if text.strip():
        cache.parent.mkdir(parents=True, exist_ok=True)
        cache.write_text(text)
    return text


def placeholder_targets():
    rows = json.loads((ROOT / 'work/native-client/unnamed-identities-inferred.json').read_text())
    log_rows = [r for r in map(m._json, m.LOG.read_text(encoding='utf-8').splitlines()) if r]
    verdict = {}
    for r in log_rows:      # latest exact/retraction wins: a retracted placeholder needs a fresh answer
        if r.get('status') in ('inactive_exact', 'retracted'):
            verdict[r['addr']] = r['status']
    done = {a for a, s in verdict.items() if s == 'inactive_exact'}
    out = []
    # Owner 2026-11-16: fake names allowed - addresses whose registry name is one library-replay label shared by many
    # bodies (bogus duplicates) get placeholder names too.
    extra = HERE_PH / 'creator-partition/bogus-placeholders.json'
    for addr in (json.loads(extra.read_text()) if extra.is_file() else []):
        rows.setdefault(addr, {'confidence': 'placeholder', 'evidence': []})
    for addr, row in rows.items():
        if row.get('confidence') != 'placeholder' or addr in done or addr in results:
            continue
        if not (ROOT / 'src/2008-06' / (addr + '.cpp')).is_file():
            continue
        size = len(m.match.target('2008-06', addr)[0])
        # 007e0000-007fffff: compiler-generated initializer/atexit/EH thunks (initializer lane), not authored functions
        if 8 <= size <= args.max_size and not 0x7e0000 <= int(addr, 16) < 0x800000:
            out.append((addr, size, row))
    return sorted(out, key=lambda x: x[1])


CLASS_DEFS = {}
EXTRA_DEFS = None


def class_header(cls, body=''):
    """The native header that defines CLS.  Several native copies can define one class (v8world/World2008.h minimal
    vs engine-world/v8world/World.h full; 2026-11-16 header audit: most donor-exact compile failures were the wrong
    copy): pick the copy that declares the most identifiers the answer BODY uses, else declaring_header()'s choice."""
    path = m.declaring_header(cls)
    default = Path(path) if path and Path(path).is_relative_to(HEADERS) else None
    leaf = cls.rsplit('::', 1)[-1]
    if leaf not in CLASS_DEFS:
        m.declaring_header('')                               # loads DECL_FILES
        pat = re.compile(r'\b(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % re.escape(leaf))
        global EXTRA_DEFS
        if EXTRA_DEFS is None:
            # Snapshot folders declaring_header() skips (engine-world/, part-embedded/, ...) and native-world/App/include
            # hold the fuller class copies (engine-world/v8world/World.h, native-world SleepStage.h): candidates here,
            # one class header at a time (the C2011 risk was mixing several snapshots in one probe).
            roots = [p for p in HEADERS.iterdir() if p.is_dir() and '-' in p.name] + [ROOT / 'rebuild/2008-06/native-world/App/include']
            EXTRA_DEFS = [(h, h.read_text(errors='replace')) for r in roots if r.is_dir() for h in r.rglob('*.h')]
        CLASS_DEFS[leaf] = [(Path(p), t) for p, t in list(m.DECL_FILES) + EXTRA_DEFS
                            if (Path(p).is_relative_to(HEADERS) or Path(p).is_relative_to(ROOT / 'rebuild/2008-06/native-world'))
                            and pat.search(t)]
    cands = CLASS_DEFS[leaf]
    if not body or len(cands) < 2:
        return default or (cands[0][0] if cands else None)
    words = set(re.findall(r'\b[A-Za-z_]\w{3,}\b', body))
    best = max(cands, key=lambda pt: (sum(1 for w in words if w in pt[1]), pt[0] == default))
    return best[0]


def shadow_file(work, header):
    """Writable shadow path for HEADER inside a full hardlink mirror of native-headers (work/shadow).  MSVC resolves a
    quoted include in the INCLUDING file's folder first, so a lone shadow copy let other headers pull the real copy in
    beside it (C2953/C2011); with the whole tree mirrored every include stays inside the mirror.  The returned file is
    unlinked from the original before anything writes to it (a write through a hardlink would edit the real header)."""
    import os
    import shutil
    root = work / 'shadow'
    if not (root / '.mirror').is_file():
        shutil.rmtree(root, ignore_errors=True)
        for src in HEADERS.rglob('*'):
            if src.is_file():
                dst = root / src.relative_to(HEADERS)
                dst.parent.mkdir(parents=True, exist_ok=True)
                try:
                    os.link(src, dst)
                except OSError:
                    shutil.copyfile(src, dst)
        (root / '.mirror').write_text('hardlink mirror of native-headers')
    target = root / header.relative_to(HEADERS)
    own = target.parent / ('.own-' + target.name)
    if not own.is_file():
        text = target.read_text(errors='replace') if target.is_file() else header.read_text(errors='replace')
        if target.exists():
            target.unlink()                               # break the hardlink before anything writes to it
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(text)
        own.write_text('')
    return target


def shadow(work, header, cls, decl, addr):
    """Copy HEADER under work/shadow/<same relative path> with DECL inserted before the class's closing brace."""
    if not Path(header).is_relative_to(HEADERS):          # mirror covers native-headers only
        return None
    existing = shadow_file(work, header)
    text = existing.read_text(errors='replace')
    leaf = cls.split('::')[-1]
    found = re.search(r'^[ \t]*(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % re.escape(leaf), text, re.M)
    if not found:
        return None
    depth, end = 0, found.end() - 1
    for end in range(found.end() - 1, len(text)):
        depth += {'{': 1, '}': -1}.get(text[end], 0)
        if depth == 0:
            break
    line = '\tpublic:\n\t\t%s   // INFERRED: %s, placeholder name (identity tier), body byte-proved\n' % (decl.strip(), addr)
    # The class already declares it (destructor, or the same signature): a second declaration is C2535.
    name = re.search(r'(~?\w+)\s*\(', decl)
    flat = lambda s: re.sub(r'\s+|\bvirtual\b|;', '', s)
    if name and (name.group(1).startswith('~') and re.search(r'%s\s*\(' % re.escape(name.group(1)), text[found.end():end])
                 or flat(decl) in flat(text[found.end():end])):
        line = ''
    root = work / 'shadow'
    existing.write_text(text[:end] + line + text[end:])
    return root, header.relative_to(HEADERS).as_posix()


def neighbour_source(row, limit=2500):
    """Native source of the link-order neighbours (usually the same original .cpp): its includes, helpers, real member
    names and style are the best context for an unnamed function between them."""
    out, seen = [], set()
    for ev in row.get('evidence', []):
        if ev.get('kind') != 'link-order-neighbours':
            continue
        for side in ('prev', 'next'):
            pair = ev.get(side) or []
            name = pair[1] if len(pair) > 1 else ''
            if '::' not in name:
                continue
            owner = name.rsplit('::', 1)[0]
            dest, _ = m.destination_for(owner)
            if not dest or dest in seen or not (ROOT / dest).is_file():
                continue
            seen.add(dest)
            text = (ROOT / dest).read_text(errors='replace')
            out.append('// %s (defines %s)\n%s' % (dest, name, text[:limit]))
    return ('\n--- NATIVE SOURCE OF THE LINK-ORDER NEIGHBOURS (likely the same original file: reuse its includes, types and '
            'member names) ---\n' + '\n\n'.join(out[:2]) + '\n') if out else ''


def proven_examples(limit=1):
    """Short proven placeholder answers (free and member) as format/style examples."""
    picks = []
    for a, r in sorted(results.items()):
        if r.get('status') == 'inactive_exact' and len(picks) < limit:
            tries = sorted((OUT / a).glob('try*.cpp'))
            if tries:
                text = tries[-1].read_text(errors='replace')
                if len(text) < 1200 and not OFFSET_HACK.search(text):
                    picks.append(text)
    return ('\n--- PROVEN EXAMPLES (accepted answers for other addresses) ---\n' + '\n\n'.join(picks) + '\n') if picks else ''


VENDOR_INDEX = None
VENDOR_ROOTS = [('boost', 'tools/rbxgs/Client/boost_1_34_1/src/boost'), ('', 'tools/libs/mfc-9.0-rtm/atlmfc/include')]


def vendor_header(name):
    """`<boost/pool/singleton_pool.hpp>` / `<atlcom.h>` for a class only a vendor tree declares (declaring_header() searches
    native/RakNet/G3D/donor roots, so boost::singleton_pool and ATL::CComObject were never auto-included)."""
    global VENDOR_INDEX
    if VENDOR_INDEX is None:
        VENDOR_INDEX = {}
        for prefix, root in VENDOR_ROOTS:
            base = ROOT / root
            if not base.is_dir():
                continue
            for h in base.rglob('*.h*'):
                if h.suffix.lower() not in ('.h', '.hpp'):
                    continue
                try:
                    text = h.read_text(errors='replace')
                except OSError:
                    continue
                for cls in re.findall(r'^\s*(?:template\s*<[^>]*>\s*)?(?:class|struct)\s+(?:\w+\s+)?(\w+)\s*(?::[^;{]*)?\{', text, re.M):
                    rel = h.relative_to(base).as_posix()
                    VENDOR_INDEX.setdefault(cls, (prefix + '/' if prefix else '') + rel)
    return VENDOR_INDEX.get(name)


def compile_and_gate(work, headers, body, addr, include_first=(), raw_includes=None):
    """Discover the sub_<addr> symbol and gate it.  Model-written #includes are resolved against the real header tree
    (unknown ones dropped); headers' #ifdef NATIVE_* guards become defines; a compile error naming undeclared types or
    functions adds their declaring native headers and recompiles, twice at most (no model call), as the main lane does."""
    raw = list(raw_includes) if raw_includes is not None else None
    # The model's own includes go FIRST: they often supply a name an earlier header uses without including it
    # (CScriptDoc.h needs RBX::DataModel).
    for inc in reversed(re.findall(r'^\s*#\s*include\s*[<"]([^>"]+)[>"]', body, re.M)):
        if (HEADERS / inc).is_file() and str(HEADERS / inc) not in headers:
            headers = [str(HEADERS / inc)] + headers
            if raw is not None:
                raw.insert(0, inc)
    body = re.sub(r'^\s*#\s*include\s*[<"][^>"]+[>"].*$', '', body, flags=re.M)
    added, banned = [], set()
    for _ in range(5):
        if raw:      # SDK include-order guards: afxwin.h, then atlbase.h, before everything else (C1189)
            raw = ([r for r in raw if r == 'afxwin.h'] + [r for r in raw if r == 'atlbase.h']
                   + [r for r in dict.fromkeys(raw) if r not in ('afxwin.h', 'atlbase.h')])
        text = '\n'.join(Path(h).read_text(errors='replace') for h in headers if Path(h).is_file())
        defines = sorted(set(re.findall(r'^\s*#\s*ifdef\s+(NATIVE_\w+)', text, re.M)))
        needle = 'sub_' + addr
        if addr in NAMED:       # leaf of the signature (`...Desc<...>::call<int>(...)` -> call; ctors -> class name)
            qual = re.sub(r'<[^<>]*>', '', re.sub(r'<[^<>]*>', '', re.sub(r'<[^<>]*>', '', NAMED[addr][1].split('(')[0])))
            needle = re.sub(r'\W', '', qual.split()[-1].rsplit('::', 1)[-1]) or needle
        sym = cg.discover_symbol(work, headers, body, addr, needle, include_first=include_first,
                                 raw_includes=raw, defines=defines)
        if sym and addr in NAMED and sym != NAMED[addr][0]:
            return 'wrong-signature', ('Compiled symbol %s but the binary symbol is %s (%s): match the signature exactly.'
                                       % (sym, NAMED[addr][0], NAMED[addr][1]))
        if sym:
            st, detail = cg.gate_code(work, headers, body, {addr: sym}, include_first=include_first, raw_includes=raw,
                                      defines=defines)
            return st[addr], detail
        error = cg.LAST_ERROR.get(addr) or ''
        # Include-order guards / SDK namespaces (main lane does the same): MFC before windows.h, ATL for ATL::.
        sdk = ('afxwin.h' if 'WINDOWS.H already included' in error else
               'atlbase.h' if ("'ATL' : is not a class or namespace name" in error or 'requires atlbase.h' in error) else '')
        if sdk and sdk not in (raw or []):
            raw = [sdk] + (raw if raw is not None else [Path(h).resolve().as_posix() for h in headers])
            continue
        # A donor header added for a missing name can redefine a native class (SimBody.h vs Body2008.h): drop it.
        if 'C2011' in error and added:
            drop = [h for h in added if not Path(h).resolve().is_relative_to(HEADERS)]
            if drop:
                banned.update(drop)
                headers = [h for h in headers if h not in drop]
                if raw is not None:
                    raw = [r for r in raw if Path(r).resolve().as_posix() not in {Path(d).as_posix() for d in drop}]
                added = []
                continue
        names = m.missing_names(error)
        found = [h for h in (m.declaring_header(n) for n in names) if h]
        found = [str(Path(h).resolve()) for h in found if str(Path(h).resolve()) not in map(lambda x: str(Path(x).resolve()), headers)
                 and str(Path(h).resolve()) not in banned]
        vendor = [v for v in dict.fromkeys(vendor_header(n) for n in names if not m.declaring_header(n)) if v]
        vendor = [v for v in vendor if v not in (raw or [])]
        if any(re.match(r'atl\w*\.h$', v) for v in vendor) and 'atlbase.h' not in (raw or []):
            vendor = ['atlbase.h'] + vendor                     # atlcom.h & co. require atlbase.h first (C1189)
        if not found and not vendor:
            break
        added = found[:3]
        # Prepend: the missing name is often used INSIDE an earlier header (CScriptDoc.h uses RBX::DataModel without
        # including it), so a header appended after it never helped.
        headers = found[:3] + headers
        raw = (vendor + [Path(h).resolve().relative_to(HEADERS).as_posix() if Path(h).resolve().is_relative_to(HEADERS)
                         else Path(h).resolve().as_posix() for h in found[:3]]
               + (raw if raw is not None else [Path(h).resolve().relative_to(HEADERS).as_posix()
                                               if Path(h).resolve().is_relative_to(HEADERS) else Path(h).resolve().as_posix()
                                               for h in headers[len(found[:3]):]]))
    return 'compile_failed', 'Compile error: ' + (cg.LAST_ERROR.get(addr) or 'no sub_%s symbol emitted' % addr) \
        + m.declarations_for(cg.LAST_ERROR.get(addr) or '')


LAST_ADDS = {}       # addr -> accepted header-add lines of the latest judged answer


def parse_header_adds(reply):
    """[(class, declaration, evidence)] from a ```header-add block, or (None, reason) when a line breaks the rules."""
    block = re.search(r'```header-add\s*\n(.*?)```', reply, re.S)
    if not block:
        return [], None
    out = []
    for line in block.group(1).splitlines():
        if not line.strip():
            continue
        hit = re.match(r'\s*([\w:]+)\s*\|\s*([^;]+;)\s*(//.*)?$', line)
        if not hit:
            return None, 'header-add line not "Class | declaration;   // evidence: ...": %s' % line.strip()[:120]
        cls, decl, ev = hit.group(1), hit.group(2).strip(), (hit.group(3) or '').strip()
        if not ev or len(ev) < 12:
            return None, 'header-add line without evidence comment: %s' % line.strip()[:120]
        if re.search(r'\b\w*pad\w*\s*\[|\bunk\w*\s*[;\[]|\bfield_[0-9a-fA-F]+', decl):
            return None, 'header-add placeholder/padding member rejected: %s' % decl[:120]
        out.append((cls, decl, ev))
    if len(out) > 6:
        return None, 'header-add has more than 6 lines'
    return out, None


def apply_header_adds(work, adds):
    """Write the lines into work/shadow copies of each class's default native header -> [relative header paths]."""
    rels = []
    for cls, decl, ev in adds:
        header = class_header(cls)
        if not header or not header.is_relative_to(HEADERS):
            return None, 'header-add: class %s has no native header' % cls
        target = shadow_file(work, header)
        text = target.read_text(errors='replace')
        leaf = cls.rsplit('::', 1)[-1]
        found = re.search(r'^[ \t]*(?:class|struct)\s+(?:__declspec\(\w+\)\s+)?%s\b[^;{]*\{' % re.escape(leaf), text, re.M)
        if not found:
            return None, 'header-add: class %s body not found in %s' % (cls, header.name)
        depth, end = 0, found.end() - 1
        for end in range(found.end() - 1, len(text)):
            depth += {'{': 1, '}': -1}.get(text[end], 0)
            if depth == 0:
                break
        name = re.search(r'(~?\w+)\s*(?:\(|;|\[)', decl)
        if name and re.search(r'\b%s\s*[\(;\[]' % re.escape(name.group(1)), text[found.end():end]):
            continue                                               # the class already declares it
        target.write_text(text[:end] + '\tpublic:\n\t\t%s   // INFERRED (header-add): %s\n' % (decl, ev.lstrip('/ ')) + text[end:])
        rel = header.relative_to(HEADERS).as_posix()
        if rel not in rels:
            rels.append(rel)
    return rels, None


def judge(work, addr, reply, body):
    cls, decl = '', ''
    cls_m = re.search(r'CLASS:\s*([\w:]+)', reply)
    decl_m = re.search(r'```decl\s*\n(.*?)```', reply, re.S)
    import shutil
    shutil.rmtree(work / 'shadow', ignore_errors=True)          # every answer starts from the real headers
    adds, why = parse_header_adds(reply)
    add_rels = []
    if adds:
        add_rels, why = apply_header_adds(work, adds)
    LAST_ADDS[addr] = adds or []
    invented = m.invented_externs(body)
    if why:
        status, detail = 'rejected-header-add', 'Rejected: ' + why
    elif invented:
        status, detail = 'rejected-invented', 'invented extern: ' + ', '.join(invented)
    elif re.search(r'^\s*(?:class|struct)\s+\w+[^;()]*\{', body, re.M) or re.search(r'\b\w*pad\w*\s*\[', body):
        # Real-header rule (2026-11-16 audit: 28 'exacts' defined their own Edge/IStage/... with `char pad[0x1b8]`).
        status, detail = 'rejected-local-class', ('Rejected: the answer defines its own classes/structs or padding layouts. '
                                                  'Use only the classes the native headers declare, by their real members.')
    elif OFFSET_HACK.search(body):
        # Real-header rule: fields by their real member names, never `*(T*)((char*)this + 0x2cd0)`.
        status, detail = 'rejected-offset-hack', ('Rejected: raw pointer arithmetic on this/objects with numeric offsets. Use '
                                                  'the real member names the native header declares (or none if no member fits).')
    elif cls_m and decl_m:
        cls, decl = cls_m.group(1), decl_m.group(1)
        header = class_header(cls, body)
        if header and not header.is_relative_to(HEADERS):     # shadow copies are relative to native-headers
            header = class_header(cls)
        made = shadow(work, header, cls, decl, addr) if header else None
        if not made:
            status, detail = 'no-class-header', 'class %s has no native header with that class body' % cls
        else:
            root, rel = made
            status, detail = compile_and_gate(work, [str(header)], body, addr, include_first=[str(root)],
                                              raw_includes=list(dict.fromkeys(add_rels + [rel])))
            fallback = class_header(cls)
            # A snapshot copy can redefine a class the other headers already pull in (C2011): retry with the default.
            if status == 'compile_failed' and 'C2011' in detail and fallback and fallback != header:
                made = shadow(work, fallback, cls, decl, addr)
                if made:
                    status, detail = compile_and_gate(work, [str(fallback)], body, addr, include_first=[str(made[0])],
                                                      raw_includes=[made[1]])
    else:
        headers = [h for h in (class_header(c, body) for c in dict.fromkeys(re.findall(r'\b(RBX::\w+(?:::\w+)?)', body))) if h][:4]
        headers = [str(h) for h in headers] or [str(HEADERS / 'util/Name.h')]
        if add_rels:
            # Shadow copies first on the include path; every native header by relative path so the copies win.
            raw = list(add_rels) + [Path(h).resolve().relative_to(HEADERS).as_posix() if Path(h).resolve().is_relative_to(HEADERS)
                                    else Path(h).resolve().as_posix() for h in headers]
            status, detail = compile_and_gate(work, headers, body, addr, include_first=[str(work / 'shadow')],
                                              raw_includes=list(dict.fromkeys(raw)))
        else:
            status, detail = compile_and_gate(work, headers, body, addr)
        if status == 'compile_failed' and 'C2011' in detail and not add_rels:      # snapshot copy clash: retry with default copies
            plain = [str(h) for h in (class_header(c) for c in dict.fromkeys(re.findall(r'(RBX::\w+(?:::\w+)?)', body))) if h][:4]
            plain = plain or [str(HEADERS / 'util/Name.h')]
            if plain != headers:
                status, detail = compile_and_gate(work, plain, body, addr)
    return status, detail, cls, decl


def run(item):
    addr, size, row = item
    work = OUT / addr
    asm = target_asm(addr)[-5000:]
    analog = (ROOT / 'src/2008-06' / (addr + '.cpp')).read_text(errors='replace')[:5000]
    if 'lib' in m.match.directives(analog):
        # `// lib rbxgs <path>`: the analog is the authentic 2007 donor unit that matches 100% - send its source text
        # (the directive alone told the model nothing).
        try:
            from roc import libs
            units = libs.units_used(analog)
            raw = next(iter(next(iter(units.values())).values()), '') if units else ''
            leaf = re.sub(r'\W', '', (NAMED.get(addr, ('', ''))[1].split('(')[0].split() or [''])[-1].rsplit('::', 1)[-1])
            at = raw.find(leaf + '(') if leaf else -1
            raw = raw[max(0, at - 3000):at + 6000] if at >= 0 else raw[:9000]
            analog += '\n// 2007 donor unit source (byte-exact in its own unit; 2008 native headers may differ):\n' + raw
        except Exception as error:                       # noqa: BLE001 - a missing unit only loses context
            analog += '\n// donor unit unavailable: %s' % str(error)[:200]
    neighbours = json.dumps([e for e in row.get('evidence', []) if e.get('kind') == 'link-order-neighbours'])[:600]
    rules = RULES.format(addr=addr) if addr not in NAMED else (
        'You recover one function of the 2008 Roblox client as REAL native C++ against the real native headers.\n'
        "Its real name and signature (from the binary's decorated symbol %s):\n    %s\n"
        'Reply with one ```cpp block defining exactly that function (same namespace, calling convention, parameter and '
        'return types; `static` only if the symbol is file-local). Use only types, members and functions the native '
        'headers declare (real member names, never `this`/pointer + numeric offsets); never define your own '
        'classes/structs or padding layouts; never invent globals or `extern`s; no __emit/asm. Reply with nothing else.'
        % (NAMED[addr][0], NAMED[addr][1]))
    prompt = (rules + HEADER_RULE + '\n--- LINK-ORDER NEIGHBOURS (likely same source file / owner) ---\n' + neighbours +
              neighbour_source(row) + proven_examples() +
              '\n--- ORIGINAL ASSEMBLY ---\n' + asm + m.annotate_asm(asm) + '\n--- REFERENCE ANALOG (placeholder names/types) ---\n'
              + analog)
    history, status, detail, used, decl, cls = '', 'no-reply', '', '', '', ''
    for n, model in enumerate(LADDER):
        m.ask(model, prompt + history, 'sub_' + addr)
        reply = getattr(m.TOOL, 'reply', '') or ''
        used = model
        code = re.findall(r'```(?:cpp|c\+\+)\s*\n(.*?)```', reply, re.S)
        if not code:
            continue
        try:
            status, detail, cls, decl = judge(work, addr, reply, code[-1])
        except Exception as error:                          # noqa: BLE001 - one bad target must not kill the pool
            status, detail, cls, decl = 'harness-error', 'harness error: %r' % (error,), '', 
        (work / ('try%d.cpp' % n)).parent.mkdir(parents=True, exist_ok=True)
        (work / ('try%d.cpp' % n)).write_text(reply)
        (work / ('err%d.txt' % n)).write_text('%s\n%s' % (status, detail))     # full text for error census
        if status == 'inactive_exact':
            break
        history = ('\n--- YOUR PREVIOUS ANSWER ---\n%s\n--- RESULT: %s ---\n%s\nFix it. Same output rules.\n'
                   % (reply[-3000:], status, detail[-2500:]))
    return addr, size, status, used, detail, cls, decl


def record(addr, size, status, model, cls, decl):
    if status != 'inactive_exact':
        return
    with m.atomic_append(m.LOG) as log:
        named = NAMED.get(addr)
        log.write(json.dumps(dict(addr=addr, symbol=named[0] if named else '', decl=decl, owner=cls,
                                  qual=(named[1].split('(')[0].split()[-1] if named else (cls + '::' if cls else '') + 'sub_' + addr),
                                  header='', dest='', size=size,
                                  name_source='named-free-lane' if named else 'inferred-placeholder', placeholder=not named,
                                  unmapped=[], new_source=True, model='placeholder-lane:' + model, attempt=0, status=status,
                                  time=round(time.time(), 1), run=m.RUN_ID, tool={}, llm_seconds=0.0, gate_seconds=0.0)) + '\n')


if args.regate:
    def regate(addr):
        tries = sorted((OUT / addr).glob('try*.cpp'))
        reply = tries[-1].read_text(errors='replace') if tries else ''
        code = re.findall(r'```(?:cpp|c\+\+)\s*\n(.*?)```', reply, re.S)
        if not code:
            return addr, 'no-reply', '', '', ''
        return (addr,) + judge(OUT / addr, addr, reply, code[-1])
    redo = [a for a, r in results.items() if r['status'] in ('compile_failed', 'rejected-invented', 'no-class-header')]
    # Also remaining addresses with a saved answer but no result row (a stopped run had re-queued them).
    _cl = HERE_PH / 'remaining-classified.json'
    _left = set(json.loads(_cl.read_text())) if _cl.is_file() else set()
    redo += [a for a in sorted(_left) if a not in results and (OUT / a).is_dir() and any((OUT / a).glob('try*.cpp'))]
    for a in redo:
        results.setdefault(a, {'status': 'compile_failed', 'model': 'regate', 'class': '', 'decl': '', 'detail': ''})
    print('regate', len(redo), flush=True)
    with ThreadPoolExecutor(args.jobs) as pool:
        for addr, status, detail, cls, decl in pool.map(regate, redo):
            if status != results[addr]['status']:
                print(addr, results[addr]['status'], '->', status, (detail.strip().splitlines() or [''])[0][:120], flush=True)
            if status == 'inactive_exact':
                results[addr].update(status=status, detail='', **{'class': cls, 'decl': decl})
                RESULTS.write_text(json.dumps(results, indent=1))
                record(addr, len(m.match.target('2008-06', addr)[0]), status, results[addr]['model'], cls, decl)
    sys.exit(0)
if args.named:
    reg = m.load_registry()
    for a in json.loads(Path(args.named).read_text()):
        NAMED[a] = (reg[a]['name'], reg[a].get('signature') or reg[a]['name'])
    todo = [(a, len(m.match.target('2008-06', a)[0]), {}) for a in NAMED if a not in results]
else:
    todo = placeholder_targets()
todo = todo[:args.limit or None]
print('placeholder targets', len(todo), flush=True)
with ThreadPoolExecutor(args.jobs) as pool:
    for addr, size, status, model, detail, cls, decl in pool.map(run, todo):
        runs = results.get(addr, {}).get('runs', 0) + 1     # lane runs on this target (token budget)
        results[addr] = {'status': status, 'model': model, 'class': cls, 'decl': decl, 'detail': detail[-500:], 'runs': runs,
                         'header_add': [list(a) for a in LAST_ADDS.get(addr, [])]}
        RESULTS.write_text(json.dumps(results, indent=1))
        record(addr, size, status, model, cls, decl)
        print(addr, size, status, cls or 'free', (detail.strip().splitlines() or [''])[0][:120], flush=True)
print(collections.Counter(r['status'] for r in results.values()))
