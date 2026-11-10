"""Replay a terminal Doc diagnostic link into a new directory; never execute it.

Only explicit inputs are fingerprinted. Historical provenance, implicit default
libraries, class ABI and runtime correctness remain separate obligations.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import time
import uuid

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import rebuild
from p6_probe import classify


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def prepare(arguments, cwd, destination, tc):
    search = [cwd] + [Path(tc[k]) for k in ('vc_lib', 'atlmfc_lib', 'sdk_lib') if tc.get(k)]
    search[1:1] = [Path(a.split(':', 1)[1]) for a in arguments if a.upper().startswith('/LIBPATH:')]
    rewritten, inputs = [], set()
    for arg in arguments:
        upper = arg.upper()
        if arg.startswith('@') or upper.startswith(('/FORCE', '/INCREMENTAL', '/LTCG')):
            raise ValueError('unsupported replay argument: ' + arg)
        if upper.startswith(('/OUT:', '/MAP:', '/PDB:', '/IMPLIB:', '/MANIFESTFILE:')):
            flag, value = arg.split(':', 1)
            rewritten.append(flag + ':' + str(destination / Path(value).name))
        elif not arg.startswith('/') and Path(arg).suffix.lower() in ('.obj', '.lib', '.res'):
            path = Path(arg)
            if not path.is_absolute():
                path = next((folder / path for folder in search if (folder / path).is_file()), None)
            if path is None or not path.is_file():
                raise FileNotFoundError(arg)
            path = path.resolve()
            inputs.add(path)
            rewritten.append(str(path))
        else:
            rewritten.append(arg)
    return rewritten, inputs


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('run', type=Path)
    parser.add_argument('--add', action='append', type=Path, default=[], help='additional compiled object; no provider removal')
    parser.add_argument('--replace-library', nargs=2, action='append', type=Path, default=[],
                        metavar=('OLD', 'NEW'), help='source-rebuilt library replacement; requires separate ownership proof')
    args = parser.parse_args()
    baseline = json.loads((args.run / 'result.json').read_text())
    if baseline.get('outcome') not in ('linked', 'link_failed'):
        raise ValueError('require terminal linked/link_failed diagnostic')
    command_path = args.run / 'output/native-doc-link-command.json'
    command = json.loads(command_path.read_text())
    tc = rebuild.toolchain(21022)
    destination = ROOT / 'work/2008-06/native-doc-relinks' / (time.strftime('%Y%m%d-%H%M%S') + '-' + uuid.uuid4().hex[:8])
    destination.mkdir(parents=True)
    arguments = list(command['arguments'])
    replacements = []
    for old, new in args.replace_library:
        if old.suffix.lower() != '.lib' or new.suffix.lower() != '.lib' or not old.is_file() or not new.is_file():
            raise ValueError('library replacement requires two existing .lib inputs')
        indices = [i for i, value in enumerate(arguments) if not value.startswith('/')
                   and (Path(command['cwd']) / value).resolve() == old.resolve()]
        if len(indices) != 1:
            raise ValueError('old library must occur exactly once: ' + str(old))
        arguments[indices[0]] = str(new.resolve())
        replacements.append({'old': str(old.resolve()), 'old_sha256': digest(old), 'new': str(new.resolve()), 'new_sha256': digest(new)})
    for extra in args.add:
        if extra.suffix.lower() != '.obj' or not extra.is_file():
            raise ValueError('additional input must be existing .obj: ' + str(extra))
        arguments.insert(0, str(extra.resolve()))
    arguments, inputs = prepare(arguments, Path(command['cwd']), destination, tc)
    inputs.add(Path(tc['link']))
    before = {str(path): digest(path) for path in sorted(inputs)}
    (destination / 'inputs.json').write_text(json.dumps(before, indent=2) + '\n')
    (destination / 'command.json').write_text(json.dumps({'cwd': str(destination), 'arguments': arguments}, indent=2) + '\n')
    response = destination / 'link.rsp'
    response.write_text('\n'.join(subprocess.list2cmdline([arg]) for arg in arguments) + '\n')
    start = time.monotonic()
    try:
        code, log = rebuild.run(tc, 'link', ['@' + str(response)], destination)
    except (OSError, subprocess.SubprocessError) as error:
        (destination / 'result.json').write_text(json.dumps({'outcome': 'tool_failed', 'error': str(error)}, indent=2) + '\n')
        raise
    elapsed = time.monotonic() - start
    (destination / 'link.log').write_text(log + '\n')
    changed = [name for name, value in before.items() if not Path(name).is_file() or digest(Path(name)) != value]
    exe = next(destination.glob('*.exe'), None)
    result = classify(code, '', '', link_text=log, exe_exists=exe is not None)
    same = {}
    for key in ('blockers', 'duplicates'):
        old = {row['symbol'] for row in baseline.get(key, [])}
        new = {row['symbol'] for row in result[key]}
        same[key] = {'unchanged': old == new, 'added': sorted(new - old), 'removed': sorted(old - new)}
    result.update(scope=__doc__, source_run=str(args.run.resolve()), source_command_sha256=digest(command_path),
                  seconds=round(elapsed, 3), changed_inputs=changed, baseline_comparison=same,
                  library_replacements=replacements,
                  historical_input_identity_proven=False)
    if changed:
        result['outcome'] = 'input_drift'
    (destination / 'result.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'run': str(destination), 'outcome': result['outcome'], 'seconds': result['seconds'],
                      'unresolved': len(result['blockers']), 'duplicates': len(result['duplicates']),
                      'changed_inputs': len(changed), 'baseline_comparison': same}))
    return 2 if changed else 0


if __name__ == '__main__':
    sys.exit(main())
