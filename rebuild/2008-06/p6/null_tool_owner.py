"""Keep exact native NullTool; source-compile its legacy copies as unused inline definitions."""
from collections import Counter
import hashlib
import json
from pathlib import Path

from roc import libs, match, rebuild
from script_context_owner import sha, references, data_symbols


def build(snapshot, output, tc, archive, link_arguments):
    command_path = snapshot / 'RbxgsApp/layer-rbxgs/NullTool.command.json'
    command = json.loads(command_path.read_text())
    source = Path(command['source'])
    native = output / 'NativeNullToolFull.obj'
    paths = set()
    for arg in link_arguments:
        if arg.startswith('/') or Path(arg).suffix.lower() not in ('.obj', '.lib'):
            continue
        path = Path(arg)
        path = path if path.is_absolute() else output / path
        if path.is_file():
            paths.add(path.resolve())
    inputs = {str(source): command['source_sha256'], **command['dependencies'],
              **{str(path): sha(path) for path in paths}, str(command_path): sha(command_path),
              str(Path(__file__)): sha(__file__), str(Path(__file__).with_name('script_context_owner.py')): sha(Path(__file__).with_name('script_context_owner.py')),
              str(tc['cl']): sha(tc['cl']), str(tc['lib']): sha(tc['lib'])}
    drift = [name for name, value in inputs.items() if not Path(name).is_file() or sha(name) != value]
    signature = hashlib.sha256(json.dumps(inputs, sort_keys=True).encode()).hexdigest()
    folder = output / 'null-tool-owner'
    folder.mkdir(exist_ok=True)
    target, receipt = folder / 'linked.lib', folder / 'receipt.json'
    if drift:
        receipt.write_text(json.dumps({'scope': __doc__, 'drift_fallback': True, 'drift_count': len(drift),
            'archive_sha256': sha(archive)}, indent=2) + '\n')
        return archive
    if target.exists() and receipt.exists():
        saved = json.loads(receipt.read_text())
        if saved.get('signature') == signature and saved.get('archive_sha256') == sha(target):
            return target
    text = source.read_text()
    declarations = ('NullTool::NullTool(Workspace* workspace)', 'NullTool::~NullTool()',
                    'const std::string NullTool::getCursorName() const', 'MouseCommand* NullTool::isSticky() const',
                    'MouseCommand* NullTool::onMouseUp(const UIEvent& uiEvent)')
    for declaration in declarations:
        if text.count(declaration) != 1:
            raise RuntimeError('unexpected NullTool source declaration')
        text = text.replace(declaration, 'inline ' + declaration)
    generated = folder / 'NullTool.cpp'
    generated.write_text(text)
    flags = [arg for arg in command['args'] if not arg.lower().startswith('/fo') and not arg.lower().endswith('.cpp')]
    code, log = rebuild.run(tc, 'cl', flags + ['/FoNullTool.obj', str(generated)], folder)
    (folder / 'compile.log').write_text(log)
    if code:
        raise RuntimeError('NullTool source build failed: ' + log[-1200:])
    members = list(libs.archive_members(archive))
    original = next(raw for name, raw in members if name == 'NullTool.obj')
    replacement = (folder / 'NullTool.obj').read_bytes()
    native_raw = native.read_bytes()
    a = {name: (body, refs) for name, body, refs in match.coff_functions(original)}
    b = {name: (body, refs) for name, body, refs in match.coff_functions(replacement)}
    n = {name: (body, refs) for name, body, refs in match.coff_functions(native_raw)}
    ra, rb, rn = references(original), references(replacement), references(native_raw)
    if set(b) - set(a) or any(not match.exact_match(a[name][0], a[name][1], b[name][0], b[name][1]) or ra[name] != rb[name] for name in b):
        raise RuntimeError('retained legacy NullTool/NewNullTool code or callees changed')
    da, db = data_symbols(original), data_symbols(replacement)
    if set(db) - set(da) or any(da[name] != db[name] for name in db):
        raise RuntimeError('retained legacy NullTool/NewNullTool data changed')
    removed = set(a) - set(b)
    def belongs_to_null(name):
        return ('NullTool@RBX@@' in name and 'NewNullTool' not in name) or 'sNullTool@' in name
    if any(not belongs_to_null(name) for name in removed | (set(da) - set(db))):
        raise RuntimeError('unrelated legacy provider disappeared')
    prefixes = ('??0NullTool@', '??1NullTool@', '?getCursorName@NullTool@', '?isSticky@NullTool@', '?onMouseUp@NullTool@')
    equivalent = []
    for prefix in prefixes:
        name = next(name for name in a if name.startswith(prefix))
        if name not in n or not match.exact_match(a[name][0], a[name][1], n[name][0], n[name][1]) or ra[name] != rn[name]:
            raise RuntimeError('native NullTool replacement body/callees disagree')
        equivalent.append(name)
    old_defs, new_defs, native_defs = (match._coff_data_index(raw)[2] for raw in (original, replacement, native_raw))
    unique = {name for name in set(old_defs) - set(new_defs) - set(native_defs) if not name.startswith('.')}
    encoded = [name.encode('latin-1') for name in unique]
    scanned = 0
    for path in paths:
        rows = libs.archive_members(path) if path.suffix.lower() == '.lib' else [(path.name, path.read_bytes())]
        for member, raw in rows:
            if path == archive.resolve() and member == 'NullTool.obj':
                continue
            scanned += 1
            if not any(name in raw for name in encoded):
                continue
            _, symbols, _, _ = match._coff_data_index(raw)
            if any(section == 0 and name in unique for name, _, section, _ in symbols.values()):
                raise RuntimeError('another input needs a legacy NullTool private provider: ' + str(path))
    code, log = rebuild.run(tc, 'lib', ['/nologo', '/OUT:' + str(target), str(archive), 'NullTool.obj'], folder)
    (folder / 'librarian.log').write_text(log)
    if code:
        raise RuntimeError('NullTool archive build failed: ' + log[-1200:])
    def inventory(rows):
        return Counter((name, hashlib.sha256(raw).hexdigest()) for name, raw in rows)
    before, after = inventory(members), inventory(libs.archive_members(target))
    if list((before - after).elements()) != [('NullTool.obj', hashlib.sha256(original).hexdigest())] or list((after - before).elements()) != [('NullTool.obj', hashlib.sha256(replacement).hexdigest())]:
        raise RuntimeError('NullTool archive replacement changed another member')
    if any(sha(name) != value for name, value in inputs.items()):
        raise RuntimeError('NullTool inputs changed during build')
    receipt.write_text(json.dumps({'scope': __doc__ + ' No full NewNullTool/ClickDetector or runtime ABI proof.',
        'signature': signature, 'inputs': inputs, 'archive_sha256': sha(target), 'retained_bodies': len(b),
        'retained_named_data': len(db), 'unchanged_other_members': len(members) - 1,
        'equivalent_native_methods': equivalent, 'unique_unused_private_definitions': sorted(unique),
        'consumer_inputs_scanned': scanned, 'removed_functions': sorted(removed)}, indent=2) + '\n')
    return target
