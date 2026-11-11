"""Repair native sources that fail on missing member declarations.

For each failing source, loop: compile; for every `C2039: 'm' : is not a member
of 'C'` look up the closure: exactly one non-virtual, non-template `C::m`
binding -> its undecorated declaration (signature proven by the mangled name) is
added before the closing brace of class C in the native header the source
actually includes (/showIncludes).  Refused for core headers (one owner each),
virtual members (vtable change), names already declared (no overload-set
change) and classes defined outside native-headers.  Stops when the source
compiles, nothing new can be declared, or 8 rounds pass.

Kept only if the source then compiles; every header edit is reverted otherwise.
Each edited file is leased first (claude-decl-*).  Caller runs the checkpoint.
Never commits.
"""
import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
import native_template_probe as probe  # noqa: E402
from native_conversion_queue import undecorate  # noqa: E402

CORE = ('v8tree/Instance.h', 'v8datamodel/DataModel.h', 'v8datamodel/Workspace.h', 'util/Events.h', '/reflection/')
MARK = '// Declarations proven by closure symbols (mangled names) of the 2008-06 client.'
MISSING = re.compile(r"error C2039: '(\w+)' : is not a member of '([\w:]+)'")
ACCESS = re.compile(r"error C2248: '([\w:]+)::(\w+)' : cannot access private member")


def lease(path):
    rel = path.resolve().relative_to(ROOT).as_posix()
    done = subprocess.run(['cmd', '/c', str(ROOT / 'roc.cmd'), 'lease', 'take', 'claude-decl-' + path.stem, rel,
                           '--hours', '4'], cwd=ROOT, capture_output=True, text=True)
    return done.returncode == 0


def norm(t):
    return re.sub(r'\b(?:class|struct|enum|union) ', '', t).strip()


def declaration(symbols, cls, member):
    """Proven member declaration text, or None."""
    rows = [s for s in symbols.get((cls.split('::')[-1], member), [])]
    if len(rows) != 1:
        return None
    text = undecorate(rows[0], 0)
    found = re.match(r'^(public|protected|private): (static |virtual )?(.*?)(?:__thiscall|__cdecl|__stdcall) ([\w:]+)::(\w+)\((.*)\)\s*(const)?\s*$', text)
    if not found or found[2] == 'virtual ' or '<' in found[4].split('::')[-1]:
        return None
    access, static, ret, _, name, params, const = found.groups()
    params = ', '.join(norm(p) for p in re.split(r',(?![^<]*>)', params) if p.strip() and p.strip() != 'void')
    return access, '%s%s %s(%s)%s;' % (static or '', norm(ret), name, params, ' const' if const else '')


def class_span(text, cls):
    short = cls.split('::')[-1]
    opener = re.compile(r'\b(?:class|struct)\s+(?:__declspec\([^)]*\)\s+)?%s\b[^;{()]*\{' % re.escape(short))
    found = opener.search(text)
    if not found:
        return None
    depth = 0
    for at in range(found.end() - 1, len(text)):
        depth += {'{': 1, '}': -1}.get(text[at], 0)
        if depth == 0:
            return found.end(), at
    return None


def repair(source, check, symbols, out):
    flags = probe.flags_for(check, source, out)
    edits, result = {}, {'source': source.relative_to(ROOT).as_posix(), 'declared': []}
    for _ in range(8):
        code, log, _ = probe.compile_tu(flags, source, out / 'compile')
        if not code:
            break
        missing = sorted(set(MISSING.findall(log)))
        _, inc, _ = probe.compile_tu(flags + ['/Zs', '/showIncludes'], source, out / 'includes')
        included = [Path(l.split(':', 2)[2].strip()) for l in inc.splitlines() if l.startswith('Note: including file:')]
        progress = False
        for member, cls in missing:
            proven = declaration(symbols, cls, member)
            if not proven:
                result.setdefault('unproven', []).append('%s::%s' % (cls, member))
                continue
            for path in included:
                rel = path.resolve().as_posix()
                if 'native-headers' not in rel or not path.exists() or any(c in rel for c in CORE):
                    continue
                raw = edits.get(path) or path.read_bytes()
                text = path.read_bytes().decode('utf-8', errors='surrogateescape')
                span = class_span(text, cls)
                if not span:
                    continue
                if re.search(r'\b%s\s*\(' % member, text[span[0]:span[1]]):
                    break
                if path not in edits:
                    if not lease(path):
                        result.setdefault('leased', []).append(rel)
                        break
                    edits[path] = raw
                nl = '\r\n' if '\r\n' in text else '\n'
                at = text.rfind('\n', 0, span[1]) + 1
                block = '%s%s:%s    %s%s' % (MARK + nl if MARK not in text[span[0]:span[1]] else '', proven[0], nl, proven[1], nl)
                path.write_bytes((text[:at] + block + text[at:]).encode('utf-8', errors='surrogateescape'))
                result['declared'].append('%s::%s -> %s' % (cls, member, path.relative_to(ROOT).as_posix()))
                progress = True
                break
        for cls, member in sorted(set(ACCESS.findall(log))):
            # header says private, mangled name says otherwise: move that one non-virtual function declaration
            rows = symbols.get((cls.split('::')[-1], member), [])
            access = {undecorate(s, 0).split(':')[0] for s in rows}
            if len(access) != 1 or access == {'private'}:
                result.setdefault('access_unproven', []).append('%s::%s' % (cls, member))
                continue
            access = access.pop()
            for path in included:
                rel = path.resolve().as_posix()
                if 'native-headers' not in rel or not path.exists() or any(c in rel for c in CORE):
                    continue
                text = path.read_bytes().decode('utf-8', errors='surrogateescape')
                span = class_span(text, cls)
                if not span:
                    continue
                body = text[span[0]:span[1]]
                lines = [m for m in re.finditer(r'^[^\n]*\b%s\s*\([^;{]*\)\s*(?:const\s*)?;[^\n]*\n' % member, body, re.M)]
                if len(lines) != 1 or 'virtual' in lines[0][0]:
                    break
                if path not in edits:
                    if not lease(path):
                        result.setdefault('leased', []).append(rel)
                        break
                    edits[path] = path.read_bytes()
                nl = '\r\n' if '\r\n' in text else '\n'
                decl = lines[0][0].strip()
                body = body[:lines[0].start()] + body[lines[0].end():]
                text = text[:span[0]] + body + text[span[1]:]
                span = class_span(text, cls)
                at = text.rfind('\n', 0, span[1]) + 1
                text = text[:at] + '%s:%s    %s%s' % (access, nl, decl, nl) + text[at:]
                path.write_bytes(text.encode('utf-8', errors='surrogateescape'))
                result['declared'].append('access %s %s::%s -> %s' % (access, cls, member, path.relative_to(ROOT).as_posix()))
                progress = True
                break
        if not progress:
            break
    code, log, _ = probe.compile_tu(flags, source, out / 'compile')
    result['compiles'] = not code
    if code:
        for path, raw in edits.items():
            path.write_bytes(raw)
        result['reverted'] = bool(edits)
        result['first_error'] = next((l for l in log.splitlines() if 'error' in l), '')[:200]
    result['headers'] = sorted(p.relative_to(ROOT).as_posix() for p in edits) if not code else []
    return result


def main():
    sources = [Path(a).resolve() for a in sys.argv[1:]]
    closure = json.loads((HERE / 'claude-identity-closure.json').read_text())['bindings']
    symbols = {}
    for row in closure:
        found = re.match(r'^\?(\w+)@(\w+)@', row['symbol'])
        if found and not row['symbol'].startswith('??'):
            symbols.setdefault((found[2], found[1]), set()).add(row['symbol'])
    symbols = {k: sorted(v) for k, v in symbols.items()}
    check = probe.runner()
    for source in sources:
        result = repair(source, check, symbols, HERE / 'claude-decl-repair' / source.stem)
        (HERE / 'claude-decl-repair' / source.stem / 'repair.json').write_text(json.dumps(result, indent=1) + '\n')
        print(json.dumps(result), flush=True)


if __name__ == '__main__':
    main()
