"""Prepare an unverified bulk Mew import without replacing existing source.

The output manifest is for the normal guarded findings integrator. This tool
does not establish ABI, symbol ownership, byte matching, or runtime safety.
"""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import re

from roc import mew_import


# Heuristic only: overloads and namespace context still require manual review.
METHOD = re.compile(r'\b([A-Za-z_]\w*(?:::[A-Za-z_]\w*)+)\s*\([^;{}]*\)\s*(?:const\s*)?\{')


def methods(data):
    text = data.decode('utf-8', errors='replace')
    text = re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"', ' ', text, flags=re.S)
    return set(METHOD.findall(text))


def prepare(root, source_manifest, output, work=mew_import.WORK):
    root, output = Path(root).resolve(), Path(output).resolve()
    source = json.loads(Path(source_manifest).read_text(encoding='utf-8'))
    base = mew_import.git(root, 'rev-parse', work).decode().strip()
    donor = source['fork_commit']
    canonical = mew_import.tree(root, base, 'workspace/rebuild/2008-06')
    original = mew_import.tree(root, donor, 'rebuild/2008-06')
    names = {PurePosixPath(p).name.casefold() for p in canonical}
    paths = {p.casefold() for p in canonical}
    hashes = set(canonical.values())
    rows = source['files']
    contents = mew_import.blobs(root, [r['blob'] for r in rows])
    output.mkdir(parents=True, exist_ok=False)
    selected, skipped = {}, []
    # Assemble a disposable combined tree. Nothing writes to the live checkout.
    native = {p: h for p, h in canonical.items()
              if p.lower().endswith(('.cpp', '.h', '.hpp', '.c', '.inl'))}
    native_bytes = mew_import.blobs(root, native.values())
    providers = {}
    for path, blob in native.items():
        relative = PurePosixPath(path).relative_to('workspace/rebuild/2008-06')
        dest = output.joinpath('merged', *relative.parts)
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_bytes(native_bytes[blob])
        if path.lower().endswith(('.cpp', '.c')):
            for name in methods(native_bytes[blob]):
                providers.setdefault(name, []).append(path)
    overlaps = []
    for row in rows:
        path, blob = row['path'], row['blob']
        p = PurePosixPath(path)
        if (not path.startswith(mew_import.NATIVE) or '..' in p.parts or
                '\\' in path or original.get(path) != blob):
            raise ValueError('invalid donor path or blob: ' + path)
        data = contents[blob]
        if hashlib.sha256(data).hexdigest() != row['sha256']:
            raise ValueError('donor hash mismatch: ' + path)
        target = 'workspace/' + path
        if target.casefold() in paths or p.name.casefold() in names or blob in hashes:
            skipped.append({'path': path, 'reason': 'existing path, name, or identical content'})
            continue
        dest = output.joinpath('sources', *p.parts)
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_bytes(data)
        merged = output.joinpath('merged', *p.relative_to('rebuild/2008-06').parts)
        merged.parent.mkdir(parents=True, exist_ok=True)
        if merged.exists():
            raise ValueError('merged destination already exists: ' + str(merged))
        merged.write_bytes(data)
        selected[path] = str(dest)
        for name in sorted(methods(data)):
            if name in providers:
                overlaps.append({'donor': path, 'method': name,
                                 'possible_providers': providers[name]})
        paths.add(target.casefold())
        names.add(p.name.casefold())
        hashes.add(blob)
    result = {'base': base, 'files': selected}
    (output / 'integration-manifest.json').write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    report = {'donor': donor, 'base': base, 'status': 'unverified; merged only in scratch',
              'baseline_files': len(native),
              'selected': list(selected), 'skipped': skipped,
              'possible_method_overlaps': overlaps,
              'warning': 'May contain duplicate providers, incompatible headers, or incomplete code.'}
    (output / 'report.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=mew_import.ROOT)
    parser.add_argument('--source-manifest', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--work-ref', default=mew_import.WORK)
    args = parser.parse_args()
    report = prepare(args.root, args.source_manifest, args.output, args.work_ref)
    print(json.dumps({'selected': len(report['selected']), 'skipped': len(report['skipped']),
                      'status': report['status'], 'output': str(args.output)}, indent=2))


if __name__ == '__main__':
    main()
