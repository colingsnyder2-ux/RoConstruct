"""Freeze a recorded module's source/include closure without reverting mutable overlays."""
import hashlib
import json
from pathlib import Path


def freeze(command_path, module, snapshot, folder, *, overlay_root=None):
    blob = command_path.read_bytes()
    command = json.loads(blob)
    source = Path(command['source'])
    overlay = Path(overlay_root) if overlay_root is not None else source.parents[2]
    if not overlay.name.startswith('overlay'):
        raise RuntimeError('unsupported captured source layout: ' + str(source))
    roots = list(dict.fromkeys([overlay.parent, module]))
    candidates = [p for root in roots for p in root.glob('overlay*') if p.is_dir()]
    candidates += [p / 'overlay' for p in snapshot.iterdir() if p.is_dir()]
    frozen = folder / 'captured'
    inputs, recovered = {}, []
    for name, expected in {str(source): command['source_sha256'], **command['dependencies']}.items():
        path = Path(name)
        try:
            relative = path.relative_to(overlay)
        except ValueError:
            data = path.read_bytes()
            if hashlib.sha256(data).hexdigest() != expected:
                raise RuntimeError('captured tool/vendor header changed: ' + name)
            inputs[str(path)] = expected
            continue
        found = None
        for candidate in [path] + [root / relative for root in candidates]:
            if candidate.is_file():
                data = candidate.read_bytes()
                if hashlib.sha256(data).hexdigest() == expected:
                    found = candidate
                    break
        if found is None:
            raise RuntimeError('hash-identical captured input unavailable: ' + name)
        destination = frozen / relative
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(data)
        inputs[str(destination)] = expected
        if found != path:
            recovered.append({'input': name, 'from': str(found), 'sha256': expected})
    if source.is_relative_to(overlay):
        captured_source = frozen / source.relative_to(overlay)
    else:
        # Direct module sources live outside their include overlay. Their bytes
        # were verified above, just like external compiler/vendor inputs.
        if overlay_root is None:
            raise RuntimeError('direct source requires an explicit captured overlay')
        captured_source = folder / 'captured-source' / source.name
        captured_source.parent.mkdir(exist_ok=True)
        captured_source.write_bytes(source.read_bytes())
        inputs[str(captured_source)] = command['source_sha256']
    flags = []
    for arg in command['args']:
        if arg.lower().startswith('/fo') or arg.lower().endswith('.cpp'):
            continue
        if arg.startswith('/I'):
            try:
                arg = '/I' + str(frozen / Path(arg[2:]).relative_to(overlay))
            except ValueError:
                pass
        flags.append(arg)
    if not source.is_relative_to(overlay):
        flags.append('/I' + str(source.resolve().parent))
    saved = folder / 'captured-command.json'
    saved.write_bytes(blob)
    inputs[str(saved)] = hashlib.sha256(blob).hexdigest()
    (folder / 'captured-inputs.json').write_text(json.dumps({'scope': __doc__, 'inputs': inputs, 'recovered': recovered}, indent=2) + '\n')
    return captured_source, flags, inputs, recovered
