"""Compile consistent inline Part getters without changing any retained provider."""
from collections import Counter
import hashlib
import json
from pathlib import Path

from roc import libs, match, rebuild
from script_context_owner import sha, references, data_symbols


def build(snapshot, output, tc, archive):
    command_path = snapshot / 'RbxgsApp/layer-rbxgs/PartInstance.command.json'
    command = json.loads(command_path.read_text())
    source = Path(command['source'])
    native = output / 'NativePartInstanceResizeFull.obj'
    inputs = {str(source): command['source_sha256'], **command['dependencies'],
              str(archive): sha(archive), str(command_path): sha(command_path),
              str(native): sha(native), str(Path(__file__)): sha(__file__),
              str(Path(__file__).with_name('script_context_owner.py')): sha(Path(__file__).with_name('script_context_owner.py')),
              str(tc['cl']): sha(tc['cl']), str(tc['lib']): sha(tc['lib'])}
    if any(not Path(name).is_file() or sha(name) != value for name, value in inputs.items()):
        raise RuntimeError('Part getter source/header prerequisite drift')
    signature = hashlib.sha256(json.dumps(inputs, sort_keys=True).encode()).hexdigest()
    folder = output / 'part-getter-owner'
    folder.mkdir(exist_ok=True)
    target = folder / 'linked.lib'
    receipt = folder / 'receipt.json'
    if target.exists() and receipt.exists():
        saved = json.loads(receipt.read_text())
        if saved['signature'] == signature and saved['archive_sha256'] == sha(target):
            return target
    text = source.read_text()
    for declaration in ('const G3D::CoordinateFrame& PartInstance::getCoordinateFrame() const',
                        'const G3D::Vector3& PartInstance::getPartSizeXml() const'):
        if text.count(declaration) != 1:
            raise RuntimeError('unexpected Part getter source declaration')
        text = text.replace(declaration, 'inline ' + declaration)
    generated = folder / 'PartInstance.cpp'
    generated.write_text(text)
    flags = [arg for arg in command['args'] if not arg.lower().startswith('/fo') and not arg.lower().endswith('.cpp')]
    code, log = rebuild.run(tc, 'cl', flags + ['/FoPartInstance.obj', str(generated)], folder)
    (folder / 'compile.log').write_text(log)
    if code:
        raise RuntimeError('Part getter source build failed: ' + log[-1200:])
    members = list(libs.archive_members(archive))
    original = next(raw for name, raw in members if name == 'PartInstance.obj')
    replacement = (folder / 'PartInstance.obj').read_bytes()
    a = {name: (body, refs) for name, body, refs in match.coff_functions(original)}
    b = {name: (body, refs) for name, body, refs in match.coff_functions(replacement)}
    if set(a) != set(b) or any(not match.exact_match(a[n][0], a[n][1], b[n][0], b[n][1]) for n in a):
        raise RuntimeError('Part getter annotation changed a retained body')
    if references(original) != references(replacement) or data_symbols(original) != data_symbols(replacement):
        raise RuntimeError('Part getter annotation changed retained relocations/data')
    native_raw = native.read_bytes()
    native_bodies = {name: (body, refs) for name, body, refs in match.coff_functions(native_raw)}
    native_refs, legacy_refs = references(native_raw), references(replacement)
    getters = []
    for prefix in ('?getCoordinateFrame@PartInstance', '?getPartSizeXml@PartInstance'):
        name = next(n for n in b if n.startswith(prefix))
        if name not in native_bodies or not match.exact_match(b[name][0], b[name][1], native_bodies[name][0], native_bodies[name][1]) or native_refs[name] != legacy_refs[name]:
            raise RuntimeError('native and legacy getter bodies/callees disagree')
        getters.append(name)
    code, log = rebuild.run(tc, 'lib', ['/nologo', '/OUT:' + str(target), str(archive), 'PartInstance.obj'], folder)
    (folder / 'librarian.log').write_text(log)
    if code:
        raise RuntimeError('Part getter archive build failed: ' + log[-1200:])
    def inventory(rows):
        return Counter((name, hashlib.sha256(raw).hexdigest()) for name, raw in rows)
    before, after = inventory(members), inventory(libs.archive_members(target))
    if list((before - after).elements()) != [('PartInstance.obj', hashlib.sha256(original).hexdigest())] or list((after - before).elements()) != [('PartInstance.obj', hashlib.sha256(replacement).hexdigest())]:
        raise RuntimeError('Part getter archive replacement changed another member')
    if any(sha(name) != value for name, value in inputs.items()):
        raise RuntimeError('Part getter inputs changed during build')
    receipt.write_text(json.dumps({'scope': __doc__ + ' Body/data preservation, not original callee/whole-class ABI/runtime proof.',
        'signature': signature, 'inputs': inputs, 'archive_sha256': sha(target),
        'retained_bodies': len(a), 'retained_named_data': len(data_symbols(original)),
        'unchanged_other_members': len(members) - 1, 'identical_native_getters': getters}, indent=2) + '\n')
    return target
