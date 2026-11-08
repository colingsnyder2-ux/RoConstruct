"""Inventory RoConstruct source trees without moving, replacing, or executing them.

The catalog distinguishes the reviewed work snapshot from public mirrors, mined
function stores, local snapshots, work artifacts, and later-version references.
It is an index for review; it never promotes code or treats a source match as
runtime proof.
"""
import argparse
import hashlib
import html
import json
import os
import posixpath
from pathlib import Path
import re
import subprocess
from urllib.parse import quote

from roc.native_drafts import ROOT, lock


SOURCE_SUFFIXES = {'.c', '.cc', '.cpp', '.cxx', '.h', '.hh', '.hpp', '.inl'}
NATIVE_SCOPES = ('native-classes', 'native-headers', 'native-world')
ORGANIZED_SCOPES = tuple(project + '/' + area for project in
                         ('App', 'Base', 'Network', 'Rendering', 'WindowsClient', 'Studio')
                         for area in ('src', 'include'))

# Browse groups only.  These do not rename files, claim original project layout,
# or affect integration decisions.  Leave weakly identified paths in Other.
MAP_GROUPS = (
    ('App/v8tree', ('v8tree/', 'native-classes/instance', 'appunit558_2008instance')),
    ('App/v8xml', ('v8xml/',)),
    ('App/reflection', ('reflection/',)),
    ('App/tool', ('tool/',)),
    ('Studio', ()),
    ('WindowsClient', ('app', 'frame', 'view', 'doc', 'dialog', 'browser', 'editor',
                    'command', 'verb', 'toolbox', 'propertygrid', 'propgrid', 'explorer', 'script')),
    ('App/v8datamodel', ('datamodel', 'instance', 'service', 'collection', 'selection',
                          'reflection', 'content', 'settings')),
    ('App/v8world', ('workspace', 'part', 'primitive', 'physics', 'terrain', 'humanoid',
                      'joint', 'motor', 'weld', 'model', 'camera', 'character')),
    ('Network', ('network', 'rak', 'peer', 'replicator', 'packet', 'http', 'web', 'player')),
    ('Rendering', ('render', 'graphics', 'mesh', 'texture', 'material', 'lighting', 'sky',
                   'image', 'decal', 'ogre')),
    ('Base/util', ('util/', 'xml', 'string', 'hash', 'crypto', 'security', 'math', 'time',
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
    for scope in NATIVE_SCOPES + ORGANIZED_SCOPES:
        for path, blob in tree_entries(root, ref, prefix + '/' + scope).items():
            result[scope + '/' + path] = blob
    return result


def compatibility_aliases(root, canonical):
    """Recognize only exact shims pointing to tracked organized sources."""
    import io
    candidates = {p: b for p, b in canonical.items() if p.startswith('native-classes/')}
    ids = sorted(set(candidates.values()))
    if not ids:
        return {}
    raw = subprocess.check_output(['git', 'cat-file', '--batch'], cwd=root,
                                  input=('\n'.join(ids) + '\n').encode())
    stream, blobs = io.BytesIO(raw), {}
    for sha in ids:
        header = stream.readline().split()
        if header[0].decode() != sha or header[1] != b'blob':
            raise ValueError('Compatibility blob identity mismatch')
        blobs[sha] = stream.read(int(header[2]))
        stream.read(1)
    pattern = re.compile(rb'(?:[ ]*// native-flags:[^\n]*\n)?'
                         rb'// Compatibility translation unit; compile this file or the organized source, not both\.\n'
                         rb'#include "([^"\n]+)"\n?')
    aliases = {}
    for path, sha in candidates.items():
        found = pattern.fullmatch(blobs[sha].replace(b'\r\n', b'\n'))
        if not found:
            continue
        target = posixpath.normpath(posixpath.join(posixpath.dirname(path), found.group(1).decode('utf-8')))
        if target in canonical and any(target.startswith(scope + '/') for scope in ORGANIZED_SCOPES):
            aliases[path] = target
    return aliases


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
            'scope': next((scope for scope in NATIVE_SCOPES + ORGANIZED_SCOPES if path.startswith(scope + '/')), 'other'),
            'canonical_blob': canonical_blob,
            'public_blob': public_blob,
            'state': state,
        })
    return files


def body_comparison(left, right):
    if left == right:
        return 'equivalent'
    left, right = left.replace(b'\r\n', b'\n'), right.replace(b'\r\n', b'\n')
    if left == right:
        return 'line-endings-only'
    banner = rb'(?m)^// >>> native-status \(generated\)[^\n]*\n(?://[^\n]*\n)*?// <<< native-status[^\n]*(?:\n|$)'
    return 'generated-banner-only' if re.sub(banner, b'', left) == re.sub(banner, b'', right) else 'requires-method-review'


def compare_blobs(root, files):
    """Distinguish generated metadata from code without rewriting either blob."""
    ids = sorted({row[key] for row in files if row['state'] == 'diverged'
                  for key in ('canonical_blob', 'public_blob')})
    blobs = {}
    if ids:
        import io
        raw = subprocess.check_output(['git', 'cat-file', '--batch'], cwd=root,
                                      input=('\n'.join(ids) + '\n').encode())
        stream = io.BytesIO(raw)
        for sha in ids:
            header = stream.readline().split()
            if header[0].decode() != sha or header[1] != b'blob':
                raise ValueError('Comparison blob identity mismatch')
            blobs[sha] = stream.read(int(header[2]))
            stream.read(1)
    counts = {}
    for row in files:
        row['comparison'] = body_comparison(blobs[row['canonical_blob']], blobs[row['public_blob']]) if row['state'] == 'diverged' else row['state']
        counts[row['comparison']] = counts.get(row['comparison'], 0) + 1
    return counts


def map_group(path):
    """Return a conservative browse group for a native relative path."""
    searchable = path.lower().replace('\\', '/')
    parts = searchable.split('/')
    if len(parts) >= 3 and parts[1] in ('src', 'include'):
        projects = {'base': 'Base/util', 'network': 'Network', 'rendering': 'Rendering',
                    'windowsclient': 'WindowsClient', 'studio': 'Studio'}
        if parts[0] in projects:
            return projects[parts[0]]
        if parts[0] == 'app':
            return {'v8tree': 'App/v8tree', 'v8xml': 'App/v8xml',
                    'reflection': 'App/reflection', 'v8datamodel': 'App/v8datamodel',
                    'v8world': 'App/v8world', 'tool': 'App/tool'}.get(parts[2], 'Other')
    for group, terms in MAP_GROUPS:
        if any(term in searchable for term in terms):
            return group
    return 'Other'


def logical_native_path(path):
    """Only combine native paths with explicit matching client provenance."""
    parts = path.replace('\\', '/').split('/')
    for index, part in enumerate(parts):
        if index and parts[index - 1] == '2008-06' and '/'.join(parts[index:index + 2]) in ORGANIZED_SCOPES:
            return '/'.join(parts[index:]) if is_source(path) else None
        if part not in NATIVE_SCOPES:
            continue
        versions = [p for p in parts[:index] if re.fullmatch(r'\d{4}-\d{2}', p)]
        if versions and versions[-1] == '2008-06':
            return '/'.join(parts[index:]) if is_source(path) else None


def source_versions(root, commit, donor_refs=(), source_roots=(), draft_files=None):
    """Index untrusted alternatives by exact content; never import or run them."""
    versions, errors, sources = {}, [], []
    excluded = {'.git', '.venv', 'node_modules', '__pycache__', 'object-cache',
                'libcache', 'tools', 'clients'}
    remotes = git(root, 'remote').splitlines()

    def record(path, blob, origin, content=None):
        key = (path, blob)
        entry = versions.setdefault(key, dict(path=path, blob=blob, origins=[],
                                              proof_status='not-assessed'))
        if origin not in entry['origins']:
            entry['origins'].append(origin)
        if content is not None:
            entry['sha256'] = hashlib.sha256(content).hexdigest()

    for ref in dict.fromkeys((commit, *donor_refs)):
        try:
            revision = git(root, 'rev-parse', ref + '^{commit}')
            repository = 'colingsnyder2-ux/RoConstruct'
            local_branch = ref.startswith('refs/heads/')
            if ref != commit and not local_branch:
                remote = ref.removeprefix('refs/remotes/').removeprefix('refs/forks/').split('/')[0]
                if ref.startswith('refs/remotes/') and remote not in remotes:
                    # A retired alias can still name useful history. Link only
                    # through a configured contributor repo proven to contain it.
                    for candidate in donor_refs:
                        other = candidate.removeprefix('refs/remotes/').split('/')[0]
                        if not candidate.startswith('refs/remotes/') or other not in remotes or other in ('origin', 'findings'):
                            continue
                        check = subprocess.run(['git', 'merge-base', '--is-ancestor', revision, candidate],
                                               cwd=root, capture_output=True)
                        if check.returncode == 0:
                            remote = other
                            break
                    else:
                        raise ValueError('Remote URL no longer configured and no reachable contributor ref: ' + remote)
                url = git(root, 'remote', 'get-url', remote) if remote in remotes else 'https://github.com/' + remote + '/RoConstruct.git'
                match = re.fullmatch(r'(?:https://github.com/|git@github.com:)([\w.-]+/[\w.-]+)', url.removesuffix('.git'))
                if not match:
                    raise ValueError('No supported immutable GitHub URL for ' + ref)
                repository = match[1]
            raw = subprocess.check_output(['git', 'ls-tree', '-r', '-z', revision, '--',
                'workspace/rebuild/2008-06', 'rebuild/2008-06', '2008-06', 'drafts/files',
                'archive/source-snapshots'], cwd=root)
            count = 0
            for row in raw.split(b'\0'):
                if not row:
                    continue
                meta, encoded = row.split(b'\t', 1)
                mode, kind, blob = meta.split()
                original = encoded.decode('utf-8')
                path = logical_native_path(original)
                if not path or mode not in (b'100644', b'100755') or kind != b'blob':
                    continue
                role = ('local-branch' if local_branch else 'draft' if original.startswith('drafts/') else
                        'archive' if original.startswith('archive/source-snapshots/') else
                        'canonical' if ref == commit and original.startswith('workspace/') else
                        'public' if ref == commit else 'fork')
                origin = dict(kind=role, ref=ref, revision=revision, path=original)
                if local_branch:
                    origin['availability'] = 'local Git history; not assumed published'
                else:
                    origin['url'] = 'https://github.com/' + repository + '/blob/' + revision + '/' + quote(original)
                record(path, blob.decode(), origin)
                count += 1
            sources.append(dict(source=ref, revision=revision, native_files=count))
        except (subprocess.CalledProcessError, ValueError) as error:
            errors.append(dict(source=ref, error=str(error)))

    draft_count = 0
    for original, content in (draft_files or {}).items():
        path = logical_native_path(original)
        if path:
            blob = hashlib.sha1(b'blob ' + str(len(content)).encode() + b'\0' + content).hexdigest()
            record(path, blob, dict(kind='draft-upload', path=original,
                availability='durable inbox; upload is not verification or activation'), content)
            draft_count += 1
    if draft_files is not None:
        sources.append(dict(source='durable-inbox', native_files=draft_count))
    visited = set()
    for folder in source_roots:
        folder = Path(folder).resolve()
        root_id = hashlib.sha256(os.fsencode(str(folder))).hexdigest()[:16]
        count = 0
        if not folder.is_dir():
            errors.append(dict(source=str(folder), error='Missing local source root'))
            continue
        try:
            def failed(error):
                errors.append(dict(source=str(folder), error=str(error)))
            for directory, dirs, names in os.walk(folder, followlinks=False, onerror=failed):
                dirs[:] = [name for name in dirs if name not in excluded and
                           not (os.lstat(os.path.join(directory, name)).st_file_attributes & 1024
                                if os.name == 'nt' else Path(directory, name).is_symlink())]
                for name in names:
                    if not is_source(name):
                        continue
                    file = Path(directory, name)
                    path = logical_native_path(file.as_posix())
                    if not path or file.is_symlink() or str(file) in visited:
                        continue
                    visited.add(str(file))
                    try:
                        content = file.read_bytes()
                        blob = hashlib.sha1(b'blob ' + str(len(content)).encode() + b'\0' + content).hexdigest()
                        try:
                            original = file.relative_to(root).as_posix()
                        except ValueError:
                            original = folder.name + '/' + file.relative_to(folder).as_posix()
                        record(path, blob, dict(kind='local', path=original, root_id=root_id,
                            availability='local-only; not published or verified'), content)
                        count += 1
                    except OSError as error:
                        errors.append(dict(source=str(file), error=str(error)))
            sources.append(dict(source=folder.parent.name + '/' + folder.name, root_id=root_id,
                                kind='local', native_files=count))
        except OSError as error:
            errors.append(dict(source=str(folder), error=str(error)))
    return dict(versions=sorted(versions.values(), key=lambda row: (row['path'], row['blob'])),
                sources=sources, errors=errors, excluded_directory_names=sorted(excluded),
                scope='Explicit 2008-06 native paths only; unmapped trials and other clients are not promoted.')


def source_map(data):
    """Make a stable, generated browse map from a source-catalog result."""
    groups = {name: [] for name, _ in MAP_GROUPS}
    groups['Other'] = []
    files = {row['path']: dict(row) for row in data['files']}
    for old, target in data.get('compatibility_aliases', {}).items():
        if old in files and target in files:
            files[old]['compatibility_target'] = target
            files[target].setdefault('previous_paths', []).append(old)
    for version in (data.get('alternatives') or {}).get('versions', []):
        files.setdefault(version['path'], dict(path=version['path'], state='candidate-only'))
    for row in sorted(files.values(), key=lambda row: row['path']):
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
        'alternatives': data.get('alternatives'),
        'comparison_summary': data.get('comparison_summary', {}),
    }


def render_source_map_markdown(data, browse=None):
    """Render a small human index; JSON remains the complete machine map."""
    lines = [
        '# 2008-06 native source map', '',
        'Generated browse map. No files moved or promoted. Grouping is heuristic only;',
        'canonical authority remains `workspace/rebuild/2008-06` on `work`.', '',
        '| Group | Paths | Equivalent | Byte-different | Public-only | Missing-public | Donor-only |',
        '| --- | ---: | ---: | ---: | ---: | ---: | ---: |',
    ]
    for group in data['groups']:
        states = {state: sum(row['state'] == state for row in group['files'])
                  for state in ('equivalent', 'diverged', 'public-only', 'missing-public', 'candidate-only')}
        lines.append('| {name} | {count} | {equivalent} | {diverged} | {public-only} | {missing-public} | {candidate-only} |'.format(
            name=group['name'], count=group['count'], **states))
    compared = data.get('comparison_summary', {})
    if compared:
        lines.extend(['', 'Byte differences include **{} banner-only**, **{} line-ending-only**, and'.format(
            compared.get('generated-banner-only', 0), compared.get('line-endings-only', 0)),
            '**{} requiring method review**. Metadata equality is not runtime proof.'.format(
                compared.get('requires-method-review', 0)), ''])
    if browse:
        lines.extend(['', '[Browse projects and all source versions](' + browse + '/README.md)', '',
                      'Forks, durable drafts and local snapshots are indexed as candidates.',
                      'Open a project to inspect immutable links and retained local origins.', ''])
        return '\n'.join(lines)
    lines.extend(['', '## Paths', ''])
    for group in data['groups']:
        lines.extend(('## ' + group['name'], ''))
        for row in group['files']:
            revision = data['generated_from']['work_commit']
            base = 'https://github.com/colingsnyder2-ux/RoConstruct/blob/' + revision + '/'
            links = []
            if row.get('canonical_blob'):
                links.append('[canonical](' + base + 'workspace/rebuild/2008-06/' + row['path'] + ')')
            if row.get('public_blob'):
                links.append('[public](' + base + '2008-06/' + row['path'] + ')')
            lines.append('- `{}` — {} · {}'.format(row['path'], row['state'], ' · '.join(links)))
        lines.append('')
    alternatives = data.get('alternatives')
    if alternatives:
        lines.extend(['## Fork, draft and local versions', '',
            'Exact content is deduplicated; all origins remain listed. These are candidates,',
            'not verified integrations. Local-only paths require their retained local snapshot.', '',
            'Sources checked: {}. Errors: {}. See JSON for coverage and exclusions.'.format(
                len(alternatives['sources']), len(alternatives['errors'])), ''])
        for row in alternatives['versions']:
            if not any(origin['kind'] in ('fork', 'draft', 'draft-upload', 'local', 'local-branch', 'archive') for origin in row['origins']):
                continue
            lines.append('- `{}` · `{}` · proof not assessed'.format(row['path'], row['blob'][:12]))
            for origin in row['origins']:
                label = origin['kind'] + ': ' + '/'.join(origin['path'].split('/')[-2:])
                lines.append('  - [{}]({})'.format(label, origin['url']) if origin.get('url') else
                             '  - {} — `{}` (local only)'.format(label, origin['path']))
        lines.append('')
    return '\n'.join(lines)


def write_browse(folder, data):
    """Compact project pages; alternatives expand instead of cluttering the root."""
    folder.mkdir(parents=True, exist_ok=False)
    alternatives = data.get('alternatives') or dict(versions=[], sources=[], errors=[])
    versions = {}
    for row in alternatives['versions']:
        versions.setdefault(row['path'], []).append(row)
    index = ['# Native source projects', '',
             'Canonical code, public copies, fork versions, durable uploads and local snapshots.',
             'Grouping is navigation only. Candidate proof/runtime status remains unknown.', '',
             '| Project | Native paths |', '| --- | ---: |']
    for group in data['groups']:
        target = folder / group['name'] / 'README.md'
        target.parent.mkdir(parents=True, exist_ok=True)
        index.append('| [{}]({}/README.md) | {} |'.format(group['name'], group['name'], group['count']))
        lines = ['# ' + group['name'], '', '[All projects](' + '../' * len(Path(group['name']).parts) + 'README.md)', '',
                 'Expand a native path for every distinct content version. No candidate is auto-promoted.', '']
        sections = []
        for row in group['files']:
            start = len(lines)
            candidates = list(versions.get(row['path'], []))
            for old in row.get('previous_paths', []):
                candidates.extend(versions.get(old, []))
            lines.extend(['<details>', '<summary>{} — {}; {} content versions</summary>'.format(
                html.escape(row['path']), row['state'], len(candidates)), ''])
            if row.get('compatibility_target'):
                lines.extend(['Compatibility path for `{}`; compile either path, never both.'.format(row['compatibility_target']), ''])
            if row.get('previous_paths'):
                lines.extend(['Earlier paths and their donor versions: {}.'.format(', '.join('`' + p + '`' for p in row['previous_paths'])), ''])
            for version in candidates:
                lines.append('**`{}`** · `{}` · proof not assessed'.format(version['blob'][:12], version['path']))
                seen = set()
                local = []
                for origin in version['origins']:
                    if origin.get('url'):
                        if origin['url'] in seen:
                            continue
                        seen.add(origin['url'])
                        owner = origin['url'].split('/')[3]
                        label = '/'.join(origin['path'].split('/')[-2:])
                        lines.append('- {} · {} · [{}]({})'.format(origin['kind'], owner, label, origin['url']))
                    else:
                        label = origin['kind']
                        if origin.get('ref'):
                            label += ' ' + origin['ref'] + '@' + origin['revision'][:12]
                        local.append('- {} · `{}`{}'.format(label, origin['path'],
                            ' · root `' + origin['root_id'] + '`' if origin.get('root_id') else ''))
                if local:
                    lines.extend(['', '<details><summary>{} retained local origins</summary>'.format(len(local)), '',
                                  *local, '', '</details>'])
                lines.append('')
            lines.extend(['</details>', ''])
            sections.append((row['path'], lines[start:]))
            del lines[start:]
        pages, batch, size = [], [], 0
        for path, section in sections:
            length = len('\n'.join(section).encode('utf-8'))
            if batch and size + length > 180000:
                pages.append(batch)
                batch, size = [], 0
            batch.append((path, section))
            size += length
        if batch:
            pages.append(batch)
        for number, page in enumerate(pages, 1):
            name = 'sources-{:03d}.md'.format(number)
            links = ['[Project index](README.md)']
            if number > 1:
                links.append('[Previous](sources-{:03d}.md)'.format(number - 1))
            if number < len(pages):
                links.append('[Next](sources-{:03d}.md)'.format(number + 1))
            body = ['# ' + group['name'], '', ' · '.join(links), '']
            for _, section in page:
                body.extend(section)
            target.with_name(name).write_text('\n'.join(body), encoding='utf-8')
            lines.append('- [{} → {}]({})'.format(page[0][0], page[-1][0], name))
        if not pages:
            lines.append('No native paths in this group.')
        target.write_text('\n'.join(lines), encoding='utf-8')
    index.extend(['', '## Coverage', '', '{} sources checked; {} errors.'.format(
        len(alternatives['sources']), len(alternatives['errors'])), '',
        'See [source-map.json](../source-map.json) for revisions, hashes, origins, errors and exclusions.',
        'Local-only candidates have no public code URL until separately reviewed and published.', ''])
    (folder / 'README.md').write_text('\n'.join(index), encoding='utf-8')


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
        'compatibility_aliases': compatibility_aliases(root, canonical),
        'local_snapshots': local_snapshots(root) if include_local else [],
        'comparison_summary': compare_blobs(root, files),
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
    parser.add_argument('--all-sources', action='store_true',
                        help='include durable drafts, fetched contributor refs and local source roots; never fetches or promotes')
    parser.add_argument('--donor-ref', action='append', default=[],
                        help='additional already-fetched contributor ref')
    parser.add_argument('--source-root', type=Path, action='append', default=[],
                        help='local source/temp/package root to index by exact native path and content')
    parser.add_argument('--browse-output', type=Path,
                        help='new project browse directory; default: catalog beside --map-output')
    args = parser.parse_args()
    args.output.parent.mkdir(parents=True, exist_ok=True)
    lock_path = args.output.with_suffix(args.output.suffix + '.lock')
    with lock(lock_path):
        if args.output.exists():
            raise SystemExit('Refusing to overwrite catalog: ' + str(args.output))
        if args.map_output and args.map_output.exists():
            raise SystemExit('Refusing to overwrite source map: ' + str(args.map_output))
        browse = args.browse_output or (args.map_output.parent / 'catalog' if args.map_output else None)
        if browse and browse.exists():
            raise SystemExit('Refusing to overwrite browse directory: ' + str(browse))
        result = catalog(ROOT, args.ref, args.local)
        donor_refs = list(args.donor_ref)
        source_roots = list(args.source_root)
        draft_files = None
        if args.all_sources or args.map_output:
            from roc.native_drafts import Inbox
            draft_files = Inbox(ROOT).archive()
            refs = git(ROOT, 'for-each-ref', '--format=%(refname)', 'refs/remotes', 'refs/forks', 'refs/heads').splitlines()
            donor_refs.extend(ref for ref in refs if not ref.endswith('/HEAD') and '/auto-merge/' not in ref
                             and not ref.startswith(('refs/remotes/origin/', 'refs/remotes/findings/',
                                                     'refs/forks/origin/', 'refs/forks/findings/')))
            source_roots.append(ROOT)
            for line in git(ROOT, 'worktree', 'list', '--porcelain').splitlines():
                if line.startswith('worktree '):
                    folder = Path(line[9:]).resolve()
                    if not folder.is_relative_to(ROOT):
                        source_roots.append(folder)
            source_roots.extend(folder for folder in ROOT.parent.glob('RoConstruct*')
                                if folder.is_dir() and folder != ROOT)
        if args.all_sources or args.map_output or donor_refs or source_roots:
            result['alternatives'] = source_versions(ROOT, result['work_commit'], donor_refs, source_roots, draft_files)
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
            markdown.write_text(render_source_map_markdown(mapped, browse.name), encoding='utf-8')
            write_browse(browse, mapped)
    print(json.dumps(result['summary'], sort_keys=True))


if __name__ == '__main__':
    main()
