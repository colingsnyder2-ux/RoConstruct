"""Inventory RoConstruct source trees without moving, replacing, or executing them.

The catalog distinguishes the reviewed work snapshot from public mirrors, mined
function stores, local snapshots, work artifacts, and later-version references.
It is an index for review; it never promotes code or treats a source match as
runtime proof.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess

from roc.native_drafts import ROOT, lock


SOURCE_SUFFIXES = {'.c', '.cc', '.cpp', '.cxx', '.h', '.hh', '.hpp', '.inl'}
NATIVE_SCOPES = ('native-classes', 'native-headers', 'native-world')

# Browse groups only.  These do not rename files, claim original project layout,
# or affect integration decisions.  Leave weakly identified paths in Other.
MAP_GROUPS = (
    ('Studio/App', ('app', 'frame', 'view', 'doc', 'dialog', 'browser', 'editor',
                    'command', 'verb', 'toolbox', 'propertygrid', 'script')),
    ('Engine/DataModel', ('datamodel', 'instance', 'service', 'collection', 'selection',
                          'reflection', 'content', 'settings')),
    ('Engine/World', ('workspace', 'part', 'primitive', 'physics', 'terrain', 'humanoid',
                      'joint', 'motor', 'weld', 'model', 'camera', 'character')),
    ('Network', ('network', 'rak', 'peer', 'replicator', 'packet', 'http', 'web', 'player')),
    ('Rendering', ('render', 'graphics', 'mesh', 'texture', 'material', 'lighting', 'sky',
                   'image', 'decal', 'ogre')),
    ('Shared/Util', ('util/', 'xml', 'string', 'hash', 'crypto', 'security', 'math', 'time',
                    'signal', 'event', 'thread', 'memory', 'stream', 'file')),
)


def is_source(path):
    return Path(path).suffix.lower() in SOURCE_SUFFIXES


def git(root, *args):
    return subprocess.check_output(['git', *args], cwd=root, text=True).strip()


def tree_entries(root, ref, prefix):
    """Return source blobs below one Git prefix, keyed by the relative path."""
    raw = subprocess.check_output(['git', 'ls-tree', '-r', '-z', ref, '--', prefix], cwd=root)
    result = {}
    for row in raw.split(b'\0'):
        if not row:
            continue
        metadata, encoded = row.split(b'\t', 1)
        mode, kind, blob = metadata.split()
        path = encoded.decode('utf-8')
        if mode not in (b'100644', b'100755') or kind != b'blob' or not is_source(path):
            continue
        if not path.startswith(prefix + '/'):
            continue
        result[path[len(prefix) + 1:]] = blob.decode('ascii')
    return result


def native_entries(root, ref, prefix):
    """Return only native-tree blobs, with scope retained in each relative path."""
    result = {}
    for scope in NATIVE_SCOPES:
        for path, blob in tree_entries(root, ref, prefix + '/' + scope).items():
            result[scope + '/' + path] = blob
    return result


def classify_files(canonical, public):
    """Pair reviewed native files with the browsable public copy by blob ID."""
    files = []
    for path in sorted(set(canonical) | set(public)):
        canonical_blob = canonical.get(path)
        public_blob = public.get(path)
        if canonical_blob and public_blob:
            state = 'equivalent' if canonical_blob == public_blob else 'diverged'
        elif canonical_blob:
            state = 'missing-public'
        else:
            state = 'public-only'
        files.append({
            'path': path,
            'scope': next((scope for scope in NATIVE_SCOPES if path.startswith(scope + '/')), 'other'),
            'canonical_blob': canonical_blob,
            'public_blob': public_blob,
            'state': state,
        })
    return files


def map_group(path):
    """Return a conservative browse group for a native relative path."""
    searchable = path.lower().replace('\\', '/')
    for group, terms in MAP_GROUPS:
        if any(term in searchable for term in terms):
            return group
    return 'Other'


def source_map(data):
    """Make a stable, generated browse map from a source-catalog result."""
    groups = {name: [] for name, _ in MAP_GROUPS}
    groups['Other'] = []
    for row in data['files']:
        entry = dict(row, group=map_group(row['path']))
        groups[entry['group']].append(entry)
    return {
        'schema': 1,
        'generated_from': {
            'work_commit': data['work_commit'],
            'catalog_authority': data['authority'],
            'catalog_scope': data['scope'],
        },
        'scope': ('Browse grouping only. Paths and blobs stay unchanged; group membership '
                  'is not source identity, proof, or integration status.'),
        'groups': [
            {'name': name, 'files': groups[name], 'count': len(groups[name])}
            for name in groups
        ],
    }


def render_source_map_markdown(data):
    """Render a small human index; JSON remains the complete machine map."""
    lines = [
        '# 2008-06 native source map', '',
        'Generated browse map. No files moved or promoted. Grouping is heuristic only;',
        'canonical authority remains `workspace/rebuild/2008-06` on `work`.', '',
        '| Group | Files | Equivalent | Diverged | Public-only | Missing-public |',
        '| --- | ---: | ---: | ---: | ---: | ---: |',
    ]
    for group in data['groups']:
        states = {state: sum(row['state'] == state for row in group['files'])
                  for state in ('equivalent', 'diverged', 'public-only', 'missing-public')}
        lines.append('| {name} | {count} | {equivalent} | {diverged} | {public-only} | {missing-public} |'.format(
            name=group['name'], count=group['count'], **states))
    lines.extend(['', '## Paths', ''])
    for group in data['groups']:
        lines.extend(('## ' + group['name'], ''))
        for row in group['files']:
            lines.append('- `{}` — {}'.format(row['path'], row['state']))
        lines.append('')
    return '\n'.join(lines)


def local_snapshot(root, name, relative, kind):
    """Hash one local source tree as a single immutable-looking inventory row.

    This deliberately records every source-file path and hash in the aggregate,
    while keeping the generated catalog compact. The local tree remains in place.
    """
    folder = root / relative
    row = {'name': name, 'kind': kind, 'path': relative.replace('\\', '/')}
    if not folder.is_dir():
        return dict(row, state='absent', source_files=0, source_bytes=0, sha256=None)
    digest = hashlib.sha256()
    count = size = 0
    for path in sorted((p for p in folder.rglob('*') if p.is_file() and is_source(p)),
                       key=lambda p: p.as_posix().casefold()):
        data = path.read_bytes()
        rel = path.relative_to(folder).as_posix()
        file_hash = hashlib.sha256(data).hexdigest()
        digest.update(rel.encode('utf-8') + b'\0' + str(len(data)).encode('ascii') + b'\0')
        digest.update(file_hash.encode('ascii') + b'\n')
        count += 1
        size += len(data)
    return dict(row, state='present', source_files=count, source_bytes=size,
                sha256=digest.hexdigest())


def local_snapshots(root):
    rows = [
        local_snapshot(root, 'active-native-tree', 'rebuild/2008-06', 'local-active-unreviewed'),
        local_snapshot(root, 'mined-function-store', 'src/2008-06', 'mined-functions'),
        local_snapshot(root, 'legacy-findings', 'local/findings/2008-06', 'legacy-snapshot'),
        local_snapshot(root, 'work-artifacts', 'work/2008-06', 'draft-and-work-artifacts'),
        local_snapshot(root, '2016-reference', 'tools/roblox2016', 'later-version-reference'),
    ]
    for folder in sorted(root.glob('RoConstruct-Native-*'), key=lambda p: p.name.casefold()):
        rows.append(local_snapshot(root, folder.name, folder.name, 'extracted-package-snapshot'))
    return rows


def catalog(root, ref, include_local=False):
    commit = git(root, 'rev-parse', ref + '^{commit}')
    canonical_prefix = 'workspace/rebuild/2008-06'
    public_prefix = '2008-06'
    canonical = native_entries(root, commit, canonical_prefix)
    public = native_entries(root, commit, public_prefix)
    files = classify_files(canonical, public)
    counts = {state: sum(row['state'] == state for row in files)
              for state in ('equivalent', 'diverged', 'missing-public', 'public-only')}
    result = {
        'schema': 1,
        'authority': 'RoConstruct/work/workspace',
        'work_commit': commit,
        'scope': ('Native source catalog only. Blob equality proves same stored bytes; '
                  'it does not prove class identity, ABI, selection, or runtime readiness.'),
        'canonical_prefix': canonical_prefix,
        'public_prefix': public_prefix,
        'summary': dict(canonical_files=len(canonical), public_files=len(public), **counts),
        'files': files,
        'local_snapshots': local_snapshots(root) if include_local else [],
    }
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ref', default='refs/remotes/findings/work',
                        help='reviewed work ref; default: refs/remotes/findings/work')
    parser.add_argument('--local', action='store_true',
                        help='also fingerprint local snapshots; does not modify them')
    parser.add_argument('--output', type=Path, required=True,
                        help='new JSON output path; source trees are read only')
    parser.add_argument('--map-output', type=Path,
                        help='new generated source-map JSON; refuses overwrite')
    args = parser.parse_args()
    args.output.parent.mkdir(parents=True, exist_ok=True)
    lock_path = args.output.with_suffix(args.output.suffix + '.lock')
    with lock(lock_path):
        if args.output.exists():
            raise SystemExit('Refusing to overwrite catalog: ' + str(args.output))
        if args.map_output and args.map_output.exists():
            raise SystemExit('Refusing to overwrite source map: ' + str(args.map_output))
        result = catalog(ROOT, args.ref, args.local)
        temporary = args.output.with_suffix(args.output.suffix + '.tmp')
        temporary.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
        temporary.replace(args.output)
        if args.map_output:
            args.map_output.parent.mkdir(parents=True, exist_ok=True)
            mapped = source_map(result)
            map_temp = args.map_output.with_suffix(args.map_output.suffix + '.tmp')
            map_temp.write_text(json.dumps(mapped, indent=2) + '\n', encoding='utf-8')
            map_temp.replace(args.map_output)
            markdown = args.map_output.with_suffix('.md')
            markdown.write_text(render_source_map_markdown(mapped), encoding='utf-8')
    print(json.dumps(result['summary'], sort_keys=True))


if __name__ == '__main__':
    main()
