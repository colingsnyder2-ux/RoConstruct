"""Bounded external matching aids. Results are drafts, never native proof.

Examples:
  python work/native-client/native_repair_tools.py diff SOURCE ADDR SYMBOL
  python work/native-client/native_repair_tools.py permute SOURCE ADDR SYMBOL Class::method

Both tools use isolated files; neither writes native sources nor sends code anywhere.
Set ROCONSTRUCT_OBJDIFF / ROCONSTRUCT_CPP_PERMUTER to override tool paths.
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import time
import uuid
import urllib.request
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
from roc import delink, match, rebuild
import native_check_runner as runner

EXTERNAL = HERE / 'external-eval'
OUTPUT = HERE / 'repair-tool-runs'
DEFAULTS = {
    'objdiff': EXTERNAL / 'objdiff/objdiff-cli.exe',
    'permuter': EXTERNAL / 'cpp_permuter-build/Release/cpp_permuter.exe',
}
OBJDIFF_URL = 'https://github.com/encounter/objdiff/releases/download/v3.8.3/objdiff-cli-windows-x86_64.exe'
OBJDIFF_SHA256 = 'dd12dfb5e9e94a7f6c949a37e1815963cf2cffe4c87b4999b7ebc8c15b398a1f'
PERMUTER_COMMIT = '59a4fea7d20aaae4d58786aa1a0425e9251199ef'


def tool(name):
    override = os.environ.get('ROCONSTRUCT_' + ('OBJDIFF' if name == 'objdiff' else 'CPP_PERMUTER'))
    path = Path(override) if override else DEFAULTS[name]
    if not path.is_file():
        raise FileNotFoundError('%s not found: %s' % (name, path))
    return path.resolve()


def bounded(args, timeout, cwd=ROOT):
    process = subprocess.Popen([str(x) for x in args], cwd=cwd, stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE, text=True,
                               start_new_session=(os.name != 'nt'))
    try:
        stdout, stderr = process.communicate(timeout=timeout)
    except BaseException:
        if os.name == 'nt':
            subprocess.run(['taskkill', '/PID', str(process.pid), '/T', '/F'], capture_output=True)
        else:
            import signal
            try:
                os.killpg(process.pid, signal.SIGKILL)
            except ProcessLookupError:
                pass
        process.communicate()
        raise
    return subprocess.CompletedProcess(args, process.returncode, stdout, stderr)


def setup(seconds=900):
    """Install pinned upstream tools under work/ without changing the project toolchain."""
    if os.name != 'nt' or not 1 <= seconds <= 1500:
        raise ValueError('setup requires Windows and a 1..1500 second budget')
    started = time.monotonic()
    deadline = started + seconds
    objdiff = DEFAULTS['objdiff']
    objdiff.parent.mkdir(parents=True, exist_ok=True)
    if objdiff.exists():
        if hashlib.sha256(objdiff.read_bytes()).hexdigest() != OBJDIFF_SHA256:
            raise RuntimeError('existing objdiff has an unexpected hash; not replacing it')
    else:
        remaining = deadline - time.monotonic()
        if remaining <= 0:
            raise TimeoutError('setup time budget exhausted')
        with urllib.request.urlopen(OBJDIFF_URL, timeout=min(60, remaining)) as response:
            data = response.read()
        if hashlib.sha256(data).hexdigest() != OBJDIFF_SHA256:
            raise RuntimeError('downloaded objdiff checksum mismatch')
        with objdiff.open('xb') as out:
            out.write(data)
    source = EXTERNAL / 'cpp_permuter'
    build = EXTERNAL / 'cpp_permuter-build'

    def command(args):
        remaining = deadline - time.monotonic()
        if remaining <= 0:
            raise TimeoutError('setup time budget exhausted')
        result = bounded(args, remaining)
        if result.returncode:
            raise RuntimeError('setup command failed: ' + (result.stderr or result.stdout)[-1500:])
        return result.stdout.strip()

    if not source.exists():
        command(['git', 'clone', '--no-checkout', '--depth', '1',
                 'https://github.com/CriminalRETeam/cpp_permuter.git', source])
        command(['git', '-C', source, 'fetch', '--depth', '1', 'origin', PERMUTER_COMMIT])
        command(['git', '-C', source, 'checkout', '--detach', PERMUTER_COMMIT])
    if command(['git', '-C', source, 'rev-parse', 'HEAD']).lower() != PERMUTER_COMMIT:
        raise RuntimeError('existing permuter checkout has a different revision; not changing it')
    if command(['git', '-C', source, 'status', '--porcelain']):
        raise RuntimeError('existing permuter checkout has local changes; not building it')
    if not DEFAULTS['permuter'].is_file():
        if build.exists():
            raise RuntimeError('existing permuter build directory has no executable; not overwriting it')
        command(['cmake', '-S', source, '-B', build, '-A', 'x64'])
        command(['cmake', '--build', build, '--config', 'Release', '--parallel', '2'])
        command(['ctest', '--test-dir', build, '-C', 'Release', '-R', '^unit$', '--output-on-failure'])
    return {'objdiff': str(objdiff), 'objdiff_sha256': OBJDIFF_SHA256,
            'permuter': str(DEFAULTS['permuter']), 'permuter_commit': PERMUTER_COMMIT,
            'seconds': round(time.monotonic() - started, 2)}


def compile_candidate(source, obj, original_dir=None):
    source, obj = Path(source).resolve(), Path(obj).resolve()
    flags = runner.compiler_flags(source)
    if original_dir and source.parent != Path(original_dir).resolve():
        # Quoted includes originally search the source directory before /I paths.
        flags.insert(2, '/I' + str(Path(original_dir).resolve()))
    code, output = rebuild.run(rebuild.toolchain(21022), 'cl',
                               flags + ['/Fo' + str(obj), str(source)], obj.parent)
    if code:
        raise RuntimeError('compile failed: ' + output[-3000:])
    return obj


def function(obj, symbol):
    rows = [(body, refs) for name, body, refs in match.coff_functions(Path(obj).read_bytes()) if name == symbol]
    if len(rows) != 1:
        raise ValueError('compiled object does not have exactly one requested symbol')
    return rows[0]


def score(obj, address, symbol):
    target, relocations, _ = match.target('2008-06', address)
    body, refs = function(obj, symbol)
    if set(relocations) <= set(refs) and match.exact_match(target, relocations, body, refs):
        return 0
    return max(1, round((1.0 - match.similarity_ratio(target, relocations, body, refs)) * 100000))


def validate(source, address, symbol):
    source = Path(source).resolve()
    if not source.is_file() or source.suffix.lower() != '.cpp':
        raise ValueError('source must be an existing C++ file')
    if not re.fullmatch(r'[0-9a-fA-F]{8}', address):
        raise ValueError('address must contain eight hexadecimal digits')
    if not symbol or any(c in symbol for c in '\r\n'):
        raise ValueError('a single decorated symbol is required')
    return source, address.lower()


def run_dir(kind, address):
    if kind not in ('objdiff', 'permuter') or not re.fullmatch(r'[0-9a-fA-F]{8}', address):
        raise ValueError('invalid tool run name or address')
    path = OUTPUT / (kind + '-' + address + '-' + uuid.uuid4().hex[:12])
    path.mkdir(parents=True)
    return path


def diff_object(address, symbol, obj, directory, timeout=120):
    directory = Path(directory)
    directory.mkdir(parents=True, exist_ok=True)
    function(obj, symbol)  # Refuse a plausible-looking empty report for the wrong object.
    code, relocations, _ = match.target('2008-06', address)
    target = directory / 'original-diagnostic.obj'
    coff = delink.Coff()
    section = coff.section('.text', code, 0x60500020)
    coff.symbol(symbol, section, 0, True)
    coff.write(target)
    output = directory / 'objdiff.json'
    result = bounded([tool('objdiff'), 'diff', '-1', target, '-2', Path(obj).resolve(),
                      '-o', output, '--format', 'json', symbol], timeout)
    if result.returncode:
        raise RuntimeError('objdiff failed: ' + (result.stderr or result.stdout)[-1500:])
    return {'output': str(output), 'original_relocations_omitted': len(relocations),
            'scope': 'diagnostic diff only; not exact or reference proof'}


def shell_quote(value):
    value = str(value)
    if any(c in value for c in '\r\n"&|<>^%!'):
        raise ValueError('path contains unsupported command-shell characters')
    return '"' + value + '"'


def guarded_compile(source, obj, config, timeout):
    result = bounded([sys.executable, __file__, 'internal-compile', source, obj, config], timeout)
    if result.returncode:
        raise RuntimeError('preflight compile failed: ' + (result.stderr or result.stdout)[-1500:])
    return obj


def permute(source, address, symbol, method, iterations=12, seconds=180):
    source, address = validate(source, address, symbol)
    shell_quote(source.name)  # The external tool substitutes its copied filename into cmd.exe.
    if not 1 <= iterations <= 200 or not 1 <= seconds <= 1500:
        raise ValueError('iterations must be 1..200 and seconds 1..1500')
    if not re.fullmatch(r'[A-Za-z_~][\w:~]*', method):
        raise ValueError('method must be a qualified C++ function name')
    executable = tool('permuter')
    started = time.monotonic()
    directory = run_dir('permuter', address)
    scratch = directory / 'input'
    scratch.mkdir()
    copy = scratch / source.name
    shutil.copyfile(source, copy)
    config = directory / 'score.json'
    config.write_text(json.dumps({'address': address, 'symbol': symbol,
                                  'source_dir': str(source.parent)}, indent=2))
    deadline = started + seconds
    original_obj, copied_obj = directory / 'original.obj', directory / 'copied.obj'
    for candidate, obj in ((source, original_obj), (copy, copied_obj)):
        remaining = deadline - time.monotonic()
        if remaining <= 0:
            raise TimeoutError('time budget exhausted before search')
        guarded_compile(candidate, obj, config, remaining)
    if function(original_obj, symbol) != function(copied_obj, symbol):
        raise RuntimeError('scratch compile differs from original source context; no search run')
    script = shell_quote(Path(__file__).resolve())
    python = shell_quote(Path(sys.executable).resolve())
    config_arg = shell_quote(config.resolve())
    compile_cmd = python + ' ' + script + ' internal-compile {src} {obj} ' + config_arg
    score_cmd = python + ' ' + script + ' internal-score {obj} ' + config_arg
    out = directory / 'candidates'
    args = [executable, '-s', copy, '-f', method, '-c', compile_cmd,
            '--score-cmd', score_cmd, '-m', 'exhaustive', '-p', 'flip_compare,ref_local',
            '--max-candidates', str(iterations), '-j', '1', '--timeout', str(min(seconds, 120)), '-o', out]
    try:
        remaining = deadline - time.monotonic()
        if remaining <= 0:
            raise TimeoutError('time budget exhausted before search')
        result = bounded(args, remaining)
        status, output = 'finished', (result.stdout + result.stderr)[-12000:]
    except subprocess.TimeoutExpired as error:
        status = 'timeout'
        output = str(error)
    receipt = {'status': status, 'address': address, 'symbol': symbol, 'source': str(source),
               'seconds': round(time.monotonic() - started, 2), 'iterations_limit': iterations,
               'output_directory': str(out), 'output': output,
               'scope': 'candidate search only; any zero score still requires original-reference proof'}
    (directory / 'receipt.json').write_text(json.dumps(receipt, indent=2))
    return receipt


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = parser.add_subparsers(dest='action', required=True)
    for action in ('diff', 'permute'):
        item = sub.add_parser(action)
        item.add_argument('source')
        item.add_argument('address')
        item.add_argument('symbol')
        if action == 'permute':
            item.add_argument('method')
            item.add_argument('--iterations', type=int, default=12)
            item.add_argument('--seconds', type=int, default=180)
    internal = sub.add_parser('internal-compile')
    internal.add_argument('source'); internal.add_argument('object'); internal.add_argument('config')
    internal = sub.add_parser('internal-score')
    internal.add_argument('object'); internal.add_argument('config')
    install = sub.add_parser('setup')
    install.add_argument('--seconds', type=int, default=900)
    args = parser.parse_args()
    try:
        if args.action == 'setup':
            print(json.dumps(setup(args.seconds)))
        elif args.action == 'internal-compile':
            config = json.loads(Path(args.config).read_text())
            compile_candidate(args.source, args.object, config['source_dir'])
        elif args.action == 'internal-score':
            config = json.loads(Path(args.config).read_text())
            print(score(args.object, config['address'], config['symbol']))
        elif args.action == 'diff':
            source, address = validate(args.source, args.address, args.symbol)
            tool('objdiff')
            directory = run_dir('objdiff', address)
            config = directory / 'compile.json'
            config.write_text(json.dumps({'source_dir': str(source.parent)}))
            obj = guarded_compile(source, directory / 'candidate.obj', config, 120)
            print(json.dumps(diff_object(address, args.symbol, obj, directory)))
        else:
            print(json.dumps(permute(args.source, args.address, args.symbol, args.method,
                                     args.iterations, args.seconds)))
    except (ValueError, OSError, RuntimeError, subprocess.TimeoutExpired) as error:
        parser.exit(2, str(error) + '\n')


if __name__ == '__main__':
    main()
