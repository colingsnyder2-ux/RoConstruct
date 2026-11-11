"""Compiler flags for native shell sources: per-file native-flags + rbxgs-app overlay + donor/Scintilla includes."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[2]))
from roc import rebuild

ROOT = rebuild.ROOT
client = '2008-06'
NC = ROOT / 'rebuild/2008-06/native-classes'
import os, re, shutil
# ROC_ENGINE_ABI=1: compile the shell against the engine's own (rbxgs) headers for every engine header that
# native-headers shadows, so shell and linked engine share one ABI. Objects go to obj-engine-abi.
ENGINE_ABI = os.environ.get('ROC_ENGINE_ABI') == '1'
NH = ROOT / 'rebuild/2008-06/native-headers'
MIRROR = ROOT / 'work/native-client/headers-engine-abi'
OUT = ROOT / ('work/native-client/obj-engine-abi' if ENGINE_ABI else 'work/native-client/obj')
OUT.mkdir(parents=True, exist_ok=True)
spec = rebuild.load_module(client, 'rbxgs-app')
ov = rebuild.build_overlay(client, spec['name'], spec.get('overlay'))
includes = rebuild._overlaid([rebuild._spec_path(client, i) for i in spec['test_includes']], [], ov)[0]
import importlib.util
_spec = importlib.util.spec_from_file_location('ncr', ROOT / 'rebuild/2008-06/tests/native_check_runner.py')
ncr = importlib.util.module_from_spec(_spec); _spec.loader.exec_module(ncr)
TREE = (ROOT / 'tools/rbxgs/Client').resolve()
OVL = (ROOT / 'rebuild/2008-06/out/RbxgsApp/overlay').resolve()
DONOR = ROOT / 'rebuild/2008-06/native-donor-2007'
EXTRA = ['/I' + str(DONOR), '/I' + str(ROOT / 'tools/rbxgs/Client/Network/raknet30/Source'), '/I' + str(ROOT / 'tools/libs/scintilla-mfc-1.20'), '/I' + str(ROOT / 'tools/libs/scintilla-mfc-1.20/include'),
         '/I' + str(ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include')]


DEF = re.compile(r'^\s*(?:class|struct)\s+(?:__declspec\([^)]*\)\s*)?(\w+)\s*(?::[^;{]*)?\{', re.M)


def _ns_path(t, pos):
    """Namespace path open at pos ('RBX::Reflection'), or None when pos is inside a class/function body."""
    stack = []          # entries: namespace name, or None for any other brace
    for m in re.finditer(r'\bnamespace\s+(\w+)\s*\{|[{}]', t[:pos]):
        if m.group(0) == '}':
            if stack:
                stack.pop()
        else:
            stack.append(m.group(1))
    return None if None in stack else '::'.join(stack)


def _qualified(t):
    """[(qualified type name, match)] for namespace-scope class/struct definitions."""
    out = []
    for m in DEF.finditer(t):
        ns = _ns_path(t, m.start())
        if ns is not None:
            out.append(((ns + '::' if ns else '') + m.group(1), m))
    return out


def _engine_types(eng):
    """qualified type name -> engine header (relative) that defines it"""
    out = {}
    for p in eng.rglob('*.h'):
        for q, _ in _qualified(p.read_text(errors='replace')):
            out.setdefault(q, p.relative_to(eng).as_posix())
    return out


def _mirror():
    eng = ROOT / 'tools/rbxgs/Client/App/include'
    etypes = _engine_types(eng)
    if MIRROR.exists():
        shutil.rmtree(MIRROR)
    for p in NH.rglob('*'):
        if p.is_file() and not (eng / p.relative_to(NH)).exists():
            d = MIRROR / p.relative_to(NH)
            d.parent.mkdir(parents=True, exist_ok=True)
            t = p.read_text(errors='replace')
            if p.suffix == '.h':
                # 2008 class-name form -> the engine's: `extern const char sX[]` -> `extern const char* const sX`,
                # template argument `sX>` -> `&sX>` (DescribedCreatable/NonCreatable/FactoryProduct take const char* const*)
                names = set(re.findall(r'extern\s+(?:const\s+)?char\s+(s[A-Z]\w*)\s*\[\s*\]', t))
                t = re.sub(r'extern\s+(?:const\s+)?char\s+(s[A-Z]\w*)\s*\[\s*\]', r'extern const char* const \1', t)
                for n in names:
                    t = re.sub(r'(?<![&\w])' + n + r'(\s*>)', '&' + n + r'\1', t)
                quals = _qualified(t)
                defs = {q for q, _ in quals}
                # an engine type (same fully qualified name) re-declared by a 2008 shell header
                dup = {q for q in defs if q in etypes}
                if dup and dup != defs:
                    # mixed header: drop only the blocks the engine already defines, include its header instead
                    for q, m in reversed(quals):
                        if q in dup:
                            i, depth = m.end() - 1, 0
                            for j in range(i, len(t)):
                                depth += {'{': 1, '}': -1}.get(t[j], 0)
                                if depth == 0:
                                    break
                            end = t.find(';', j) + 1
                            t = t[:m.start()] + '// engine-ABI mirror: %s from the engine header\n' % q + t[end:]
                    for q in dup:
                        n = q.split('::')[-1]
                        # the engine class is the one linked: no Donor rename, no 2008 layout asserts on it
                        t = re.sub(r'^\s*#\s*(?:define\s+%s\s+Donor%s|undef\s+%s)\s*$' % (n, n, n), '', t, flags=re.M)
                        t = re.sub(r'^\s*typedef\s+char\s+\w+\s*\[[^\]]*\b%s\b[^\]]*\?\s*1\s*:\s*-1\s*\]\s*;\s*$' % n, '', t, flags=re.M)
                    inc = ''.join('#include "%s"\n' % h for h in sorted({etypes[n] for n in dup}))
                    last = [m.end() for m in re.finditer(r'^\s*#include[^\n]*\n', t, re.M)]
                    at = last[-1] if last else (t.find('\n') + 1)
                    t = t[:at] + inc + t[at:]
                elif defs and all(n in etypes for n in defs):
                    # a 2008 split-out header whose types the 2007 engine defines elsewhere: use the engine's
                    t = '#pragma once\n// engine-ABI mirror: types defined by the linked engine headers\n' + \
                        ''.join('#include "%s"\n' % h for h in sorted({etypes[n] for n in defs}))
            d.write_text(t)


if ENGINE_ABI:
    _mirror()


def flags_for(src):
    """Per-file native-flags (the repo's own resolver), with the rbxgs-app overlay ahead of each vendor dir
    so the shell compiles against the same headers the linked engine used."""
    out = []
    for f in ncr.compiler_flags(src):
        if ENGINE_ABI:
            f = f.replace(str(NH), str(MIRROR))
        if f.startswith('/I'):
            p = Path(f[2:]).resolve()
            if p.is_relative_to(TREE) and (OVL / p.relative_to(TREE)).exists():
                out.append('/I' + str(OVL / p.relative_to(TREE)))
        out.append(f)
    return out + EXTRA + ['/I' + str(NC)] + ['/I' + str(i) for i in includes] + (['/FIutil/Debug.h'] if ENGINE_ABI else [])


