"""Isolated Ninja compilation, LLVM symbol indexing, and three-way C++ merges.

Development aids only: no executable selection, matching proof, or runtime claim.
"""
import argparse
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import subprocess
import time

from roc import rebuild

ROOT = Path(__file__).resolve().parents[1]


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def ninja_path(path):
    if any(ch in str(path) for ch in '\r\n'):
        raise ValueError('Newlines are not supported in Ninja paths')
    return str(path).replace('$', '$$').replace(' ', '$ ').replace(':', '$:')


def compiler_command(argv):
    # Ninja invokes cmd.exe on Windows; donor-controlled profiles are untrusted.
    if any(any(ch in arg for ch in '&|<>^%!"\r\n') for arg in argv):
        raise ValueError('Shell metacharacter in compiler path or flags')
    return subprocess.list2cmdline(argv).replace('$', '$$')


def runner(root):
    path = root / 'rebuild/2008-06/tests/native_check_runner.py'
    spec = importlib.util.spec_from_file_location('roc_native_check_runner', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def compile_sources(root, sources, folder, ninja, workers):
    root, folder, ninja = Path(root).resolve(), Path(folder).resolve(), Path(ninja).resolve(strict=True)
    allowed = (root / 'work/native-ninja').resolve()
    if not folder.is_relative_to(allowed) or folder == allowed:
        raise ValueError('Build directory must be a named folder under work/native-ninja')
    marker = folder / '.roc-native-ninja'
    if folder.exists() and not marker.is_file():
        raise ValueError('Existing directory is not a RoConstruct Ninja build')
    folder.mkdir(parents=True, exist_ok=True)
    from roc.native_drafts import lock
    with lock(folder / '.build.lock'):
        return _compile_sources(root, sources, folder, ninja, workers)


def _compile_sources(root, sources, folder, ninja, workers):
    marker = folder / '.roc-native-ninja'
    marker.touch(exist_ok=True)
    sources = [Path(x).resolve(strict=True) for x in sources]
    if not sources or len(set(sources)) != len(sources):
        raise ValueError('Sources must be nonempty and unique')
    tc, checker = rebuild.toolchain(21022), runner(root)
    compiler = Path(tc['cl']).resolve(strict=True)
    env = rebuild.env(tc)
    # Changes in compiler bytes or environment force rebuilds even if timestamps are preserved.
    environment = {key: env.get(key, '') for key in ('PATH', 'INCLUDE', 'LIB')}
    components = {str(p): sha(p) for p in [compiler, *(compiler.parent / x for x in
                   ('c1.dll', 'c1xx.dll', 'c2.dll', 'mspdb80.dll', 'mspdb90.dll'))] if p.is_file()}
    fingerprint = hashlib.sha256(json.dumps([components, environment], sort_keys=True).encode()).hexdigest()
    stamp = folder / 'compiler-inputs.txt'
    if not stamp.exists() or stamp.read_text() != fingerprint:
        stamp.write_text(fingerprint)
    lines, objects = [], []
    for index, source in enumerate(sources):
        if source.suffix.lower() != '.cpp':
            raise ValueError('Only C++ source files are supported: ' + str(source))
        obj = folder / (hashlib.sha256(str(source).casefold().encode()).hexdigest()[:20] + '.obj')
        flags = checker.compiler_flags(source)
        argv = [str(compiler), *flags, '/showIncludes', '/Fo' + str(obj), str(source)]
        command = compiler_command(argv)
        lines += [f'rule cxx{index}', '  command = ' + command, '  description = Compiling $in',
                  '  deps = msvc', f'build {ninja_path(obj)}: cxx{index} {ninja_path(source)} | {ninja_path(stamp)}']
        objects.append(str(obj))
    lines.append('default ' + ' '.join(ninja_path(x) for x in objects))
    build = folder / 'build.ninja'
    text = '\n'.join(lines) + '\n'
    if not build.exists() or build.read_text(encoding='utf-8') != text:
        build.write_text(text, encoding='utf-8', newline='\n')
    start = time.monotonic()
    done = subprocess.run([str(ninja), '-f', str(build), '-j', str(workers)], cwd=folder,
                          env=env, capture_output=True, text=True, errors='replace')
    receipt = {'exit_code': done.returncode, 'seconds': round(time.monotonic() - start, 3),
               'compiled': len(re.findall(r'^\[\d+/\d+\] Compiling ', done.stdout, re.M)),
               'sources': [str(x) for x in sources], 'objects': objects,
               'compiler_sha256': sha(compiler), 'output': done.stdout + done.stderr,
               'scope': 'development objects only; matching and runtime proofs remain separate'}
    (folder / 'last-build.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf-8')
    return receipt


def index_symbols(nm, objects):
    definitions, undefined = defaultdict(set), defaultdict(set)
    for obj in objects:
        obj = Path(obj).resolve(strict=True)
        done = subprocess.run([str(nm), '--format=posix', '--print-file-name', str(obj)],
                              capture_output=True, text=True, errors='replace', check=True)
        for line in done.stdout.splitlines():
            if ': ' not in line:
                continue
            origin, info = line.rsplit(': ', 1)
            fields = info.split()
            if len(fields) < 2 or len(fields[1]) != 1:
                continue
            name, kind = fields[:2]
            if kind == 'U':
                undefined[name].add(origin)
            elif kind.isupper() and kind not in ('N', '?'):
                definitions[name].add(origin)
    return {'objects': [str(Path(x).resolve()) for x in objects],
            'undefined': {name: {'callers': sorted(refs), 'available_providers': sorted(definitions.get(name, set()))}
                          for name, refs in sorted(undefined.items())},
            'duplicate_definitions': {name: sorted(refs) for name, refs in sorted(definitions.items()) if len(refs) > 1},
            'scope': 'symbol references by object, not proof of link selection or function-level callers'}


def merge(mergiraf, base, left, right, output):
    paths = [Path(x).resolve(strict=True) for x in (base, left, right)]
    output = Path(output).resolve()
    if output.exists() or output in paths:
        raise ValueError('Output must be a new file')
    output.parent.mkdir(parents=True, exist_ok=True)
    result = subprocess.run([str(mergiraf), 'merge', '--language', 'cpp', '--timeout', '3000', '--output', str(output),
                             *map(str, paths)], capture_output=True, text=True, errors='replace', timeout=30)
    if not output.is_file():
        raise ValueError('Mergiraf did not create an output file')
    return {'exit_code': result.returncode, 'output': str(output),
            'input_sha256': {str(p): sha(p) for p in paths},
            'output_sha256': sha(output),
            'conflicts': bool(re.search(r'^(?:<{7}|={7}|>{7})', output.read_text(errors='replace'), re.M)),
            'log': result.stdout + result.stderr, 'scope': 'unverified candidate; review and compile required'}


def method_diff(before, after):
    """Conservative syntax triage; equal syntax is not ABI or provider proof."""
    from tree_sitter import Language, Parser
    import tree_sitter_cpp
    def definitions(data):
        root = Parser(Language(tree_sitter_cpp.language())).parse(data).root_node
        if root.has_error:
            raise ValueError('parser reported syntax errors')
        found = {}
        def walk(node, namespaces):
            if node.type == 'namespace_definition':
                name = node.child_by_field_name('name')
                namespaces = namespaces + ((name.text.decode() if name else '<anonymous>'),)
            if node.type == 'function_definition':
                declarator = node.child_by_field_name('declarator')
                body = node.child_by_field_name('body')
                if not declarator or not body:
                    raise ValueError('function without declarator or body')
                key = '::'.join(namespaces) + ':' + re.sub(r'\s+', '', declarator.text.decode())
                if key in found:
                    raise ValueError('duplicate function signature: ' + key)
                found[key] = hashlib.sha256(body.text).hexdigest()
                return
            for child in node.named_children:
                walk(child, namespaces)
        walk(root, ())
        return found
    left, merged = definitions(before), definitions(after)
    return {'added': sorted(set(merged) - set(left)), 'missing': sorted(set(left) - set(merged)),
            'changed': sorted(name for name in set(left) & set(merged) if left[name] != merged[name])}


def merge_batch(mergiraf, plan, folder, workers):
    items = json.loads(Path(plan).read_text(encoding='utf-8'))['items']
    if not 1 <= len(items) <= 50:
        raise ValueError('Batch must contain 1 to 50 entries')
    folder = Path(folder).resolve()
    folder.mkdir(parents=True, exist_ok=False)
    def task(pair):
        index, item = pair
        try:
            paths = [Path(item[name]).resolve(strict=True) for name in ('base', 'left', 'right')]
            before = {str(path): sha(path) for path in paths}
            result = merge(mergiraf, *paths, folder / (f'{index:03d}.cpp'))
            if result['input_sha256'] != before:
                raise ValueError('Input changed while merging')
            if result['exit_code'] and not result['conflicts']:
                raise ValueError('Mergiraf failed: ' + result['log'])
            result['same_as_left'] = result['output_sha256'] == before[str(paths[1])]
            result['source_path'] = item.get('source_path', '')
            result['canonical_path'] = item.get('canonical_path', '')
            if not result['same_as_left'] and not result['conflicts']:
                try:
                    result['methods'] = method_diff(paths[1].read_bytes(), Path(result['output']).read_bytes())
                except (ImportError, ValueError, UnicodeError) as error:
                    result['method_review_error'] = str(error)
            return result
        except Exception as error:
            return {'source_path': item.get('source_path', ''), 'error': str(error)}
    with ThreadPoolExecutor(max_workers=workers) as pool:
        results = list(pool.map(task, enumerate(items)))
    report = {'plan_sha256': sha(plan), 'results': results,
              'scope': 'unverified three-way candidates; source, ABI, provider and proof review required'}
    (folder / 'report.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    return {'report': str(folder / 'report.json'), 'files': len(results),
            'changed': sum(not x.get('same_as_left', True) for x in results),
            'conflicts': sum(bool(x.get('conflicts')) for x in results),
            'errors': sum('error' in x for x in results)}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='action', required=True)
    build = sub.add_parser('compile')
    build.add_argument('--ninja', type=Path, required=True)
    build.add_argument('--build-dir', type=Path, required=True)
    build.add_argument('--workers', type=int, choices=range(1, 9), default=3)
    build.add_argument('sources', type=Path, nargs='+')
    symbols = sub.add_parser('symbols')
    symbols.add_argument('--llvm-nm', type=Path, required=True)
    symbols.add_argument('--output', type=Path, required=True)
    symbols.add_argument('objects', type=Path, nargs='+')
    merge_parser = sub.add_parser('merge')
    merge_parser.add_argument('--mergiraf', type=Path, required=True)
    merge_parser.add_argument('--output', type=Path, required=True)
    for name in ('base', 'left', 'right'):
        merge_parser.add_argument(name, type=Path)
    batch = sub.add_parser('merge-batch')
    batch.add_argument('--mergiraf', type=Path, required=True)
    batch.add_argument('--plan', type=Path, required=True)
    batch.add_argument('--output', type=Path, required=True, help='new output directory')
    batch.add_argument('--workers', type=int, choices=range(1, 9), default=3)
    args = parser.parse_args()
    if args.action == 'compile':
        result = compile_sources(ROOT, args.sources, args.build_dir, args.ninja, args.workers)
    elif args.action == 'symbols':
        if args.output.exists():
            raise ValueError('Symbol report output already exists')
        result = index_symbols(args.llvm_nm.resolve(strict=True), args.objects)
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
        result = {'report': str(args.output), 'objects': len(args.objects),
                  'undefined_symbols': len(result['undefined']),
                  'duplicate_definitions': len(result['duplicate_definitions'])}
    elif args.action == 'merge':
        result = merge(args.mergiraf.resolve(strict=True), args.base, args.left, args.right, args.output)
    else:
        result = merge_batch(args.mergiraf.resolve(strict=True), args.plan, args.output, args.workers)
    print(json.dumps(result, indent=2))
    if result.get('exit_code', 0):
        raise SystemExit(result['exit_code'])


if __name__ == '__main__':
    main()
