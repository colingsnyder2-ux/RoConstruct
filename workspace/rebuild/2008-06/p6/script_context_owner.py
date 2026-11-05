"""Source-built ScriptContext remainder for the native Doc diagnostic only."""
import bisect
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct

from roc import libs, match, rebuild


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def verify_native(output):
    path = output / 'NativeScriptFileLoadFull.obj'
    raw = path.read_bytes()
    bodies = match.coff_functions(raw)
    checks = (('005ade40', '?loadfile@ScriptContext'), ('005adf80', '?dofile@ScriptContext'),
              ('005a86e0', '?getContext@ScriptContext'), ('0061c7b0', '?safe_lua_tostring'))
    for address, prefix in checks:
        candidates = [row for row in bodies if row[0].startswith(prefix)]
        if len(candidates) != 1:
            raise RuntimeError('native ScriptContext provider missing/ambiguous: ' + prefix)
        name, body, refs = candidates[0]
        original, mask, _ = match.target('2008-06', address)
        if not set(mask) <= set(refs) or not match.exact_match(original, mask, body, refs):
            raise RuntimeError('native ScriptContext body changed: ' + address)
        _, errors = match.data_check('2008-06', address, original, match.coff_data_refs(raw, name))
        if errors:
            raise RuntimeError('native ScriptContext referenced data changed: ' + address)
    (output / 'script-file-load-native-proof.json').write_text(json.dumps({
        'scope': 'Original code/referenced-data checks only; EH graphs separately audited; no runtime ABI proof.',
        'object_sha256': sha(path), 'checks': len(checks), 'exact': True}, indent=2) + '\n')


def references(raw):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    relocations = {}
    for index, section in enumerate(sections):
        relocations[index] = [struct.unpack_from('<IIH', raw, section[5] + i * 10)
                              for i in range(section[7])]
    result = {}
    for name, body, _ in match.coff_functions(raw):
        start, section = definitions[name]
        result[name] = [(offset - start, symbols[symbol][0], kind)
                        for offset, symbol, kind in relocations[section] if start <= offset < start + len(body)]
    return result


def data_symbols(raw):
    sections, symbols, definitions, starts = match._coff_data_index(raw)
    result = {}
    for name, (value, index) in definitions.items():
        section = sections[index]
        if name.startswith('.') or section[9] & 0x20 or not section[9] & 0xc0:
            continue
        following = bisect.bisect_right(starts[index + 1], value)
        end = min(starts[index + 1][following], section[3]) if following < len(starts[index + 1]) else section[3]
        # Actual source declares this global bool. Exclude inter-symbol padding.
        if name == '?vvvvv@@3_NA':
            end = value + 1
        if end <= value:
            continue
        body = bytearray(raw[section[4] + value:section[4] + end]) if section[4] else bytearray(end - value)
        refs = []
        for i in range(section[7]):
            offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + i * 10)
            if value <= offset < end:
                local = offset - value
                refs.append((local, symbols[symbol][0], kind, bytes(body[local:local + 4]).hex()))
                body[local:local + 4] = bytes(4)
        result[name] = (bytes(body), refs, not bool(section[4]))
    return result


def build(snapshot, output, tc):
    """Retain other providers; fail on changed inputs or unrelated body/data drift."""
    module = snapshot / 'RbxgsApp'
    archive = module / 'linked/linked.lib'
    command_path = module / 'layer-rbxgs/ScriptContext.command.json'
    command = json.loads(command_path.read_text())
    source = Path(command['source'])
    inputs = {str(source): command['source_sha256'], **command['dependencies']}
    inputs.update({str(archive): sha(archive), str(command_path): sha(command_path),
                   str(Path(__file__)): sha(__file__), str(tc['cl']): sha(tc['cl']), str(tc['lib']): sha(tc['lib'])})
    changed = [name for name, value in inputs.items() if not Path(name).is_file() or sha(name) != value]
    if changed:
        raise RuntimeError('ScriptContext prerequisite drift: ' + ', '.join(changed[:4]))
    signature = hashlib.sha256(json.dumps(inputs, sort_keys=True).encode()).hexdigest()
    folder = output / 'script-context-owner'
    folder.mkdir(exist_ok=True)
    receipt_path = folder / 'receipt.json'
    target = folder / 'linked.lib'
    if receipt_path.exists() and target.exists():
        saved = json.loads(receipt_path.read_text())
        if saved['signature'] == signature and saved['archive_sha256'] == sha(target):
            return target
    text = source.read_text()
    for signature_text in ('int ScriptContext::loadfile(lua_State* L)', 'int ScriptContext::dofile(lua_State* L)'):
        if text.count(signature_text) != 1:
            raise RuntimeError('unexpected ScriptContext source declaration: ' + signature_text)
        start = text.index(signature_text)
        end = text.index('{', start) + 1
        depth = 1
        while depth:
            depth += (text[end] == '{') - (text[end] == '}')
            end += 1
        text = text[:start] + '// Defined by native ScriptFileLoad.cpp.\n' + text[end:]
    getter = 'ScriptContext& ScriptContext::getContext(lua_State* thread)'
    if text.count(getter) != 1:
        raise RuntimeError('unexpected context getter declaration')
    text = text.replace(getter, 'inline ' + getter)
    generated = folder / 'ScriptContext.cpp'
    generated.write_text(text)
    args = [arg for arg in command['args'] if not arg.lower().startswith('/fo') and not arg.lower().endswith('.cpp')]
    code, log = rebuild.run(tc, 'cl', args + ['/FoScriptContext.obj', str(generated)], folder)
    (folder / 'compile.log').write_text(log)
    if code:
        raise RuntimeError('ScriptContext source remainder compile failed: ' + log[-1200:])
    old_members = list(libs.archive_members(archive))
    original = next(raw for name, raw in old_members if Path(name).name == 'ScriptContext.obj')
    replacement = (folder / 'ScriptContext.obj').read_bytes()
    a = {name: (body, refs) for name, body, refs in match.coff_functions(original)}
    b = {name: (body, refs) for name, body, refs in match.coff_functions(replacement)}
    common = set(a) & set(b)
    if set(b) - set(a) or any(not match.exact_match(a[n][0], a[n][1], b[n][0], b[n][1]) for n in common):
        raise RuntimeError('unrelated ScriptContext code changed')
    # Only the replaced methods and their now-unused ContentId/singleton helpers may disappear.
    tokens = ('?loadfile@ScriptContext', '?dofile@ScriptContext', 'ContentId@RBX@@', 'singleton@ContentProvider')
    removed = set(a) - set(b)
    if any(not any(token in name for token in tokens) for name in removed):
        raise RuntimeError('unexpected ScriptContext provider removal')
    ra, rb = references(original), references(replacement)
    if any(ra[name] != rb[name] for name in common):
        raise RuntimeError('retained ScriptContext relocation identities changed')
    da, db = data_symbols(original), data_symbols(replacement)
    if set(db) - set(da) or any(da[name] != db[name] for name in set(da) & set(db)):
        raise RuntimeError('retained ScriptContext named data changed')
    if any(not any(token in name for token in tokens) for name in set(da) - set(db)):
        raise RuntimeError('unexpected ScriptContext data removal')
    code, log = rebuild.run(tc, 'lib', ['/nologo', '/OUT:' + str(target), str(archive), 'ScriptContext.obj'], folder)
    (folder / 'librarian.log').write_text(log)
    if code:
        raise RuntimeError('ScriptContext library build failed: ' + log[-1200:])
    def inventory(members):
        return Counter((name, hashlib.sha256(raw).hexdigest()) for name, raw in members)
    before, after = inventory(old_members), inventory(libs.archive_members(target))
    if list((before - after).elements()) != [('ScriptContext.obj', hashlib.sha256(original).hexdigest())] or list((after - before).elements()) != [('ScriptContext.obj', hashlib.sha256(replacement).hexdigest())]:
        raise RuntimeError('library replacement changed another member')
    if any(sha(name) != value for name, value in inputs.items()):
        raise RuntimeError('ScriptContext inputs changed during build')
    receipt_path.write_text(json.dumps({'scope': __doc__ + ' No runtime/whole-class ABI proof.',
        'signature': signature, 'inputs': inputs, 'archive_sha256': sha(target),
        'retained_bodies': len(common), 'retained_named_data': len(set(da) & set(db)),
        'unchanged_other_members': len(old_members) - 1, 'removed_functions': sorted(removed)}, indent=2) + '\n')
    return target
