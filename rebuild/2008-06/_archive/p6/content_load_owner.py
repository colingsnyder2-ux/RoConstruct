"""Source-build ContentProvider's remainder after native parser/load ownership proof."""
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path

from roc import libs, match, rebuild
from script_context_owner import sha, references, data_symbols


def build(snapshot, output, tc, archive, link_arguments):
    module = snapshot / 'RbxgsApp'
    command_path = module / 'layer-rbxgs/ContentProvider.command.json'
    folder = output / 'content-load-owner'
    folder.mkdir(exist_ok=True)
    from captured_inputs import freeze
    source, captured_flags, inputs, recovered = freeze(command_path, module, snapshot, folder)
    native = output / 'NativeContentProviderLoadFull.obj'
    native_header = Path(__file__).resolve().parents[1] / 'native-headers/v8xml/XmlSerializer.h'
    inputs.update({str(archive): sha(archive), str(native): sha(native), str(native_header): sha(native_header),
                   str(Path(__file__)): sha(__file__),
                   str(Path(__file__).with_name('captured_inputs.py')): sha(Path(__file__).with_name('captured_inputs.py')),
                   str(tc['cl']): sha(tc['cl']), str(tc['lib']): sha(tc['lib'])})
    xml_header = folder / 'parser/v8xml/XmlSerializer.h'
    xml_header.parent.mkdir(parents=True, exist_ok=True)
    xml_header.write_bytes(native_header.read_bytes())
    text = source.read_text()
    declaration = 'void ContentProvider::load(ContentId id, std::vector<boost::shared_ptr<Instance>>& instances)'
    if text.count(declaration) != 1:
        raise RuntimeError('unexpected ContentProvider load declaration')
    flags = captured_flags
    def compile_variant(name):
        path = folder / (name + '.cpp')
        path.write_text(text.replace(declaration, 'inline ' + declaration) if name == 'ContentProvider' else text)
        includes = []
        if name != 'Baseline':
            includes.append('/I' + str(folder / 'parser'))
        code, log = rebuild.run(tc, 'cl', includes + flags + ['/Fo' + name + '.obj', str(path)], folder)
        (folder / (name + '.log')).write_text(log)
        if code:
            raise RuntimeError('ContentProvider owner compile failed: ' + log[-1200:])
    with ThreadPoolExecutor(max_workers=3) as pool:
        list(pool.map(compile_variant, ('Baseline', 'Corrected', 'ContentProvider')))
    members = list(libs.archive_members(archive))
    original = next(raw for name, raw in members if name == 'ContentProvider.obj')
    baseline = (folder / 'Baseline.obj').read_bytes()
    corrected = (folder / 'Corrected.obj').read_bytes()
    remainder = (folder / 'ContentProvider.obj').read_bytes()
    def bodies(raw):
        return {name: (body, refs) for name, body, refs in match.coff_functions(raw)}
    a, base, b = bodies(original), bodies(baseline), bodies(remainder)
    def same(left, right):
        return match.exact_match(left[0], left[1], right[0], right[1])
    if set(a) != set(base) or any(not same(a[name], base[name]) for name in a) or references(original) != references(baseline) or data_symbols(original) != data_symbols(baseline):
        raise RuntimeError('captured ContentProvider baseline does not reproduce archive')
    def original_check(raw, address, prefix):
        candidates = [row for row in match.coff_functions(raw) if row[0].startswith(prefix)]
        if len(candidates) != 1:
            raise RuntimeError('missing/ambiguous native parser provider: ' + prefix)
        name, body, refs = candidates[0]
        target, mask, _ = match.target('2008-06', address)
        if not set(mask) <= set(refs) or not match.exact_match(target, mask, body, refs):
            raise RuntimeError('original parser/load body mismatch: ' + address)
        _, errors = match.data_check('2008-06', address, target, match.coff_data_refs(raw, name))
        if errors:
            raise RuntimeError('original parser/load data mismatch: ' + address)
        return name
    load_name = original_check(corrected, '005628e0', '?load@ContentProvider')
    original_check(corrected, '00415350', '??0TextXmlParser')
    original_check(corrected, '004147c0', '??1TextXmlParser')
    native_raw = native.read_bytes()
    original_check(native_raw, '005628e0', '?load@ContentProvider')
    original_check(native_raw, '00409db0', '?what@logic_error')
    if references(corrected)[load_name] != references(native_raw)[load_name]:
        raise RuntimeError('native/corrected load callees differ')
    ra, rb = references(original), references(remainder)
    da, db = data_symbols(original), data_symbols(remainder)
    if set(b) - set(a) or any(not same(a[name], b[name]) or ra[name] != rb[name] for name in b):
        raise RuntimeError('retained ContentProvider code/callees changed')
    if set(db) - set(da) or any(da[name] != db[name] for name in db):
        raise RuntimeError('retained ContentProvider data changed')
    # Every discarded private helper must remain provided elsewhere or be unreferenced.
    old_defs, new_defs = (match._coff_data_index(raw)[2] for raw in (original, remainder))
    pending = {name for name in set(old_defs) - set(new_defs) if not name.startswith('.')}
    paths = set()
    for arg in link_arguments:
        if arg.startswith('/') or Path(arg).suffix.lower() not in ('.obj', '.lib'):
            continue
        path = Path(arg)
        path = path if path.is_absolute() else output / path
        if path.is_file():
            paths.add(path.resolve())
            inputs[str(path.resolve())] = sha(path)
    undefined, provided, scanned = set(), set(), 0
    for path in paths:
        rows = libs.archive_members(path) if path.suffix.lower() == '.lib' else [(path.name, path.read_bytes())]
        for member, raw in rows:
            if path == archive.resolve() and member == 'ContentProvider.obj':
                continue
            scanned += 1
            if not any(name.encode('latin-1') in raw for name in pending):
                continue
            _, symbols, definitions, _ = match._coff_data_index(raw)
            provided.update(pending & set(definitions))
            undefined.update(name for name, _, section, _ in symbols.values() if section == 0 and name in pending)
    if (undefined & pending) - provided:
        raise RuntimeError('discarded ContentProvider helper is still required')
    target = folder / 'linked.lib'
    code, log = rebuild.run(tc, 'lib', ['/nologo', '/OUT:' + str(target), str(archive), 'ContentProvider.obj'], folder)
    (folder / 'librarian.log').write_text(log)
    if code:
        raise RuntimeError('ContentProvider librarian failed: ' + log[-1200:])
    def inventory(rows):
        return Counter((name, hashlib.sha256(raw).hexdigest()) for name, raw in rows)
    before, after = inventory(members), inventory(libs.archive_members(target))
    if list((before - after).elements()) != [('ContentProvider.obj', hashlib.sha256(original).hexdigest())] or list((after - before).elements()) != [('ContentProvider.obj', hashlib.sha256(remainder).hexdigest())]:
        raise RuntimeError('ContentProvider replacement changed another member')
    if any(sha(name) != value for name, value in inputs.items()):
        raise RuntimeError('ContentProvider inputs changed during build')
    (folder / 'receipt.json').write_text(json.dumps({'scope': __doc__ + ' No complete service/legacy ABI or runtime proof; EH clearValue binding remains separate.',
        'inputs': inputs, 'recovered_headers': recovered, 'archive_sha256': sha(target),
        'retained_bodies': len(b), 'retained_named_data': len(db), 'unchanged_other_members': len(members) - 1,
        'original_checks': ['005628e0', '00415350', '004147c0', '00409db0'],
        'removed_definitions': sorted(pending), 'provided_elsewhere': sorted(pending & provided),
        'unused_private_definitions': sorted(pending - provided), 'consumer_inputs_scanned': scanned}, indent=2) + '\n')
    return target
