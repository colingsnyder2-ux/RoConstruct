"""Explicitly instantiate every class template a native source already names.

Inactive probe; writes only under --output.  For one native-classes/*.cpp:

1. compile it unchanged with its normal flags (baseline object);
2. undecorate every symbol the object mentions, collect template owners;
3. compile a probe TU:  #include "<source>"  +  template class Owner<Args>;
   Lines the compiler rejects are dropped mechanically (bounded rounds);
4. count emitted functions with an identical original body, baseline vs probe.

The probe object is evidence input for native_identity_closure.py.  It is not
a provider, layout proof or link input.
"""
import argparse
import importlib.util
import json
import os
import re
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
from roc.native_bulk import Targets  # noqa: E402
from native_conversion_queue import owner  # noqa: E402


def runner():
    path = ROOT / 'rebuild/2008-06/tests/native_check_runner.py'
    spec = importlib.util.spec_from_file_location('_probe_native_checker', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def template_class(scope):
    """Outermost class template of a qualified scope, or None."""
    if '<' not in scope or '`' in scope or 'A0x' in scope:
        return None
    depth = 0
    for i, ch in enumerate(scope):
        depth += ch == '<'
        if ch == '>':
            depth -= 1
            if depth == 0:
                return scope[:i + 1]
    return None


# Vendor/donor trees some native sources need.  Appended after the normal flags
# (recovered headers still win) and only when the compiler reports a missing file
# that the tree has.  Byte proof decides whether the tree is the right revision.
FALLBACK_INCLUDES = ['rebuild/2008-06/native-donor-2007', 'tools/rbxgs/Client/Network/raknet30/Source',
                     'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include', 'tools/libs/scintilla-mfc-1.20']


def flags_for(check, source, folder):
    """Normal checker flags plus the fallback include dirs this source needs."""
    flags = [f for f in check.compiler_flags(source) if f != '/c' and not f.lower().endswith('.cpp')]
    flags.append('/I' + str(source.parent))
    flags += os.environ.get('CLAUDE_EXTRA_FLAGS', '').split()  # experiments only
    for _ in range(len(FALLBACK_INCLUDES)):
        code, log, _ = compile_tu(flags + ['/Zs'], source, folder / 'include-probe')
        missing = re.findall(r"Cannot open include file: '([^']+)'", log)
        add = next(('/I' + str(ROOT / d) for d in FALLBACK_INCLUDES for m in missing
                    if (ROOT / d / m).exists() and '/I' + str(ROOT / d) not in flags), None)
        if not code or not add:
            break
        flags.append(add)
    return flags


def compile_tu(flags, source, folder):
    folder.mkdir(parents=True, exist_ok=True)
    started = time.monotonic()
    args = [f for f in flags if not f.startswith('/Fo')] + ['/c', '/Fo' + str(folder / 'candidate.obj'), str(source)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', args, folder)
    (folder / 'compile.log').write_text(log, encoding='utf-8')
    return code, log, round(time.monotonic() - started, 2)


def exact(raw, targets):
    """{symbol: [addresses]} for emitted functions with an identical original body."""
    hits = {}
    for symbol, body, relocs in match.coff_functions(raw):
        if len(body) < 6:
            continue
        for addr in targets.candidates(body, relocs):
            try:
                target, original = targets.body(addr)
            except (KeyError, ValueError, SystemExit):
                continue
            if len(target) == len(body) and set(original) <= set(relocs) and \
                    match.exact_match(target, original, body, relocs):
                hits.setdefault(symbol, []).append(addr)
    return hits


def probe(source, output, targets, check, per_line=False):
    source = source.resolve()
    flags = flags_for(check, source, output)
    receipt = {'source': str(source.relative_to(ROOT)).replace('\\', '/'), 'rounds': []}
    code, log, seconds = compile_tu(flags, source, output / 'baseline')
    receipt['baseline'] = {'exit': code, 'seconds': seconds}
    if code:
        receipt['status'] = 'baseline-compile-failed'
        return receipt
    raw = (output / 'baseline/candidate.obj').read_bytes()
    base = exact(raw, targets)
    _, symbols, _, _ = match._coff_data_index(raw)
    classes = sorted({c for c in (template_class(owner(name)) for name, *_ in symbols.values()
                                  if name.startswith('?')) if c})
    lines = ['template class %s;' % c for c in classes]
    tu = output / 'probe.cpp'
    for attempt in range(40):  # ponytail: drop rejected lines, bounded; no source repair
        tu.write_text('#include "%s"\n' % source.as_posix() + '\n'.join(lines) + '\n', encoding='utf-8')
        code, log, seconds = compile_tu(flags, tu, output / 'probe')
        bad = {int(n) for n in re.findall(r'probe\.cpp\((\d+)\)', log) if int(n) >= 2}
        receipt['rounds'].append({'exit': code, 'seconds': seconds, 'lines': len(lines), 'rejected': len(bad)})
        if not code:
            break
        if bad:
            lines = [line for number, line in enumerate(lines, 2) if number not in bad]
            continue
        # Error inside a header: drop instantiations of the templates the diagnostic names.
        named = set(re.findall(r"((?:\w+::)*\w+)<", ' '.join(re.findall(
            r"(?:member function|template instantiation) '([^']*)'", log))))
        kept = [line for line in lines if line[len('template class '):].split('<')[0] not in named]
        if len(kept) == len(lines):
            break
        receipt['rounds'][-1]['rejected'] = len(lines) - len(kept)
        lines = kept
    receipt['instantiations_requested'], receipt['instantiations_kept'] = len(classes), len(lines)
    # Persist exact directives.  A later strict identity/reference gate can
    # consume this receipt without recompiling discovery merely to reconstruct
    # the surviving lines from probe.cpp.
    receipt['instantiation_lines'] = lines
    if code:
        receipt['status'] = 'probe-compile-failed'
        return receipt
    grown = exact((output / 'probe/candidate.obj').read_bytes(), targets)
    new = {s: a for s, a in grown.items() if s not in base}
    receipt.update(status='ok', baseline_exact_symbols=len(base), probe_exact_symbols=len(grown),
                   new_exact_symbols=len(new),
                   new_exact_addresses=len({a for v in new.values() for a in v}),
                   new_unique=sorted((a[0], s) for s, a in new.items() if len(a) == 1))
    if per_line:
        # Attribution is discovery only.  It never changes source and its raw
        # byte hits still require the native_bulk identity/reference gate.
        line_rows = []
        profile = ' '.join(flag for flag in flags if not flag.lower().startswith(('/fo', '/fd', '/c')))
        for number, line in enumerate(lines):
            one = output / ('line-%03d.cpp' % number)
            # Preserve resolved fallback include roots for native_bulk's later
            # strict reference pass; otherwise a probe that compiled here can
            # fail there before its body is even inspected.
            one.write_text('// native-flags: %s\n#include "%s"\n%s\n' %
                           (profile, source.as_posix(), line), encoding='utf-8')
            code, _, seconds = compile_tu(flags, one, output / ('line-%03d' % number))
            hits = {} if code else exact((output / ('line-%03d/candidate.obj' % number)).read_bytes(), targets)
            added = {symbol: addresses for symbol, addresses in hits.items() if symbol not in base}
            line_rows.append({'line': line, 'compile_exit': code, 'seconds': seconds,
                              'raw_unique': sorted((addresses[0], symbol) for symbol, addresses in added.items()
                                                   if len(addresses) == 1)})
        receipt['per_line'] = line_rows
    return receipt


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('sources', nargs='+', type=Path)
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--per-line', action='store_true',
                    help='compile each surviving instantiation separately; discovery only')
    args = ap.parse_args()
    targets, check = Targets('2008-06'), runner()
    line_sources = []
    for source in args.sources:
        folder = args.output.resolve() / source.stem
        receipt = probe(source, folder, targets, check, args.per_line)
        (folder / 'receipt.json').write_text(json.dumps(receipt, indent=1) + '\n')
        if args.per_line and receipt.get('status') == 'ok':
            line_sources.extend(str((folder / ('line-%03d.cpp' % number)).relative_to(ROOT)).replace('\\', '/')
                                for number, row in enumerate(receipt.get('per_line', [])) if row.get('raw_unique'))
        print(json.dumps({k: v for k, v in receipt.items() if k != 'new_unique'}))
    if args.per_line:
        inventory = {'client': '2008-06', 'families': [
            {'name': 'NativeTemplateLineProbe', 'sources': line_sources, 'evidence': []}]}
        (args.output.resolve() / 'line-inventory.json').write_text(json.dumps(inventory, indent=1) + '\n')


if __name__ == '__main__':
    main()
