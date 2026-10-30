"""Conservative syntax-aware native method adaptation and qualified declaration discovery."""
import difflib
import functools
import json
import re
from pathlib import Path

from roc import integration


@functools.lru_cache(maxsize=2048)
def declared_types(text):
    from roc.native_sweep import masked_cpp, closing
    clean = masked_cpp(text)
    scopes = []
    for found in re.finditer(r'\bnamespace\s+(\w+)\s*\{', clean):
        brace = clean.index('{', found.start())
        try:
            scopes.append((brace, closing(clean, brace, '{', '}'), found[1]))
        except ValueError:
            continue
    types = {}
    pattern = r'\b(?:class|struct)\s+(?:__declspec\s*\([^)]*\)\s*)?(?:(?:\w*_API|\w*Export)\s+)?(\w+)\s*(?::[^;{]+)?\{'
    for found in re.finditer(pattern, clean):
        brace = clean.index('{', found.start())
        try:
            finish = closing(clean, brace, '{', '}')
        except ValueError:
            continue
        names = [name for start, end, name in sorted(scopes) if start < found.start() < end]
        parents = [(start, name.split('::')[-1]) for name, (start, end) in types.items() if start < found.start() < end]
        names += [name for _, name in sorted(parents)]
        types['::'.join(names + [found[1]])] = (found.start(), finish)
    return types


def symbol_unit(symbol):
    found = re.match(r'(?:\?[^@]+@|\?\?[01])(\w+)@((?:\w+@)+)@', symbol or '')
    return '::'.join(list(reversed(found[2].rstrip('@').split('@'))) + [found[1]]) if found else None


def type_paths(root, patches):
    tree = Path(root)/'tools/rbxgs/Client'
    roots = ('App/include', 'Network/include', 'RbxGraphics/include', 'RbxView/include',
             'Rendering/g3d/include', 'Rendering/RenderLib/include', 'Rendering/AppDraw/include')
    files = {p.relative_to(tree).as_posix() for rel in roots for p in (tree/rel).rglob('*')
             if p.suffix in ('.h', '.hpp', '.inl')}
    files.update(p for p in patches if any(p.startswith(rel+'/') for rel in roots)
                 and Path(p).suffix in ('.h', '.hpp', '.inl'))
    paths, contents = {}, {}
    for rel in sorted(files):
        text = integration.overlay_text(tree, rel, patches)
        contents[rel] = text
        for name in declared_types(text):
            paths.setdefault(name, set()).add(rel)
            paths.setdefault(name.rsplit('::', 1)[-1], set()).add(rel)
    return paths, integration.digest(contents)


def eligible(unit, addr, names, paths):
    if re.fullmatch(r'RBX::(?:\w+::)*\w+', unit or ''):
        return True
    return (bool(re.fullmatch(r'(?:G3D|Ogre)::(?:\w+::)*\w+', unit or ''))
            and unit in paths and symbol_unit(names.get(addr, {}).get('symbol')) == unit)


def namespace_capabilities(root):
    root = Path(root)
    module = root/'rebuild/2008-06/modules/ogre.json'
    spec = json.loads(module.read_text()) if module.exists() else {}
    return dict(RBX=dict(module='rbxgs-app', supported=True),
                G3D=dict(module='rbxgs-app', supported=True,
                         condition='Native declaration and matching rebuilt namespace symbol required'),
                Ogre=dict(module='rbxgs-app', supported=True,
                          condition='Native declaration and matching rebuilt namespace symbol required',
                          standalone_module_native_layers=len(spec.get('layers', [])),
                          standalone_module_reason='Verified-layer DLL/import replay is not a native source layer' if not spec.get('layers') else None))


def adapt(mined, native, method, declarations=''):
    from roc import native_sweep as sweep
    spans = sweep.methods(mined)
    if method not in spans or method not in sweep.methods(native):
        raise ValueError('Missing or ambiguous out-of-line native method; retrieve declaration/ABI context')
    start, end = spans[method]
    clean = sweep.masked_cpp(mined)
    brace = clean.index('{', start)
    body = mined[brace:end]
    if re.search(r'\b(?:constexpr|nullptr|decltype|noexcept|thread_local|static_assert)\b', sweep.masked_cpp(body)):
        raise ValueError('Historical MSVC does not support this C++ construct')
    synthetic = set(re.findall(r'\b(?:class|struct|union)\s+(\w+)', clean[:start]))
    synthetic.update(re.findall(r'\btypedef\s+[^;{}]+\s+(\w+)\s*;', clean[:start]))
    available = set(re.findall(r'\b(?:class|struct|union)\s+(?:__declspec\([^)]*\)\s+)?(\w+)', sweep.masked_cpp(native+'\n'+declarations)))
    available.update(re.findall(r'\btypedef\s+[^;{}]+\s+(\w+)\s*;', sweep.masked_cpp(native+'\n'+declarations)))
    missing = sorted(t for t in synthetic - available if re.search(r'\b'+re.escape(t)+r'\b', sweep.masked_cpp(body)))
    if missing:
        raise ValueError('Synthetic declarations lack native equivalents: ' + ', '.join(missing))
    if re.search(r'\breinterpret_cast\b|\(\s*(?:char|BYTE)\s*\*\s*\)\s*this|\bthis\s*[+-]', sweep.masked_cpp(body)):
        raise ValueError('Raw offset view needs native member/ABI evidence')
    # Reuse the existing parser, keeping the genuine declaration and surrounding source.
    edits = sweep.method_edits(native, mined[start:end], method)
    integration.validate_patches({'App/adaptation.cpp': edits})
    return edits


def command(args):
    if not args.claim or not re.fullmatch('[0-9a-f]{32}', args.claim) or not args.file or not args.method or not args.address:
        raise ValueError('adapt needs --claim ID --address ADDR --file NATIVE_PATH --method Class::method')
    folder = integration.ROOT/'work/integration-client/claims'/args.claim
    claim = json.loads((folder/'packet.json').read_text(encoding='utf-8'))
    addr = '%08x' % int(args.address, 16)
    if addr not in claim['addresses']:
        raise ValueError('Adaptation address is outside the claim')
    integration.canonical_patches({args.file: []})
    # Explicitly validate paths even though this operation only saves proposal data.
    integration.validate_patches({args.file: [['path-validation', 'path-validated']]})
    tree = integration.ROOT/'tools/rbxgs/Client'
    native = integration.overlay_text(tree, args.file, claim['baseline']['overlay'])
    source = Path(args.source) if args.source else folder/'context'/addr/'mined.cpp'
    context = '\n'.join(integration.overlay_text(tree, p, claim['baseline']['overlay']) for p in claim.get('native_paths', []))
    edits = adapt(source.read_text(encoding='utf-8'), native, args.method, context)
    from roc.native_sweep import apply_edits
    directory = folder/'adaptations'/(addr+'-'+integration.digest([args.file, edits])[:12])
    integration.atomic_json(directory/'edits.json', {args.file: edits})
    blocks = '\n'.join('<<<<<<< SEARCH\n'+old+'\n=======\n'+new+'\n>>>>>>> REPLACE' for old,new in edits)
    (directory/'blocks.txt').write_text(blocks, encoding='utf-8')
    patched = apply_edits(native, edits)
    (directory/'source.diff').write_text(''.join(difflib.unified_diff(native.splitlines(True), patched.splitlines(True),
                                                                    args.file, args.file)), encoding='utf-8')
    report = dict(file=args.file, method=args.method, address=addr, baseline=claim['base_revision'],
                  edits=str((directory/'edits.json').resolve()), diff=str((directory/'source.diff').resolve()),
                  accepted=False, requires_compile_and_matching=True,
                  next_command='roc native-try check '+args.file+' '+str(directory/'blocks.txt')+' --only '+addr)
    integration.atomic_json(directory/'proposal.json', report)
    print(json.dumps(report, indent=1))
    return report
