"""Editable native sources; capture anchored proposals without hand-written edit blocks."""
import difflib
import json
from pathlib import Path, PurePosixPath

from roc import integration, native_sweep


def name(value):
    value = str(value).replace('\\', '/')
    path = PurePosixPath(value)
    if path.is_absolute() or '..' in path.parts or ':' in value or path.suffix.lower() not in ('.cpp', '.h', '.hpp', '.inl'):
        raise ValueError('Edit an existing C++ source/header inside the native tree: ' + value)
    return path.as_posix()


def folder(output, rel):
    return output / 'edit' / integration.digest(name(rel).casefold())[:16]


def source(ctx, rel, proposal):
    path = ctx.overlay / rel
    if not path.exists():
        path = ctx.tree / rel
    text = path.read_text(errors='replace')
    pairs = proposal.get('edits', []) if rel == proposal.get('file') else proposal.get('related_headers', {}).get(rel, [])
    return native_sweep.apply_edits(text, pairs) if pairs else text


def edits(before, after):
    if before == after:
        return []
    if not before:
        raise ValueError('Empty/new native files require a native type/build-unit proposal')
    old, new = before.splitlines(keepends=True), after.splitlines(keepends=True)
    pairs = []
    for group in difflib.SequenceMatcher(None, old, new, autojunk=False).get_grouped_opcodes(3):
        a, b = group[0], group[-1]
        pair = [''.join(old[a[1]:b[2]]), ''.join(new[a[3]:b[4]])]
        if not pair[0] or before.count(pair[0]) != 1:
            return [[before, after]]
        pairs.insert(0, pair)
    if native_sweep.apply_edits(before, pairs) != after:
        return [[before, after]]
    return pairs


def load(output, rel):
    path = folder(output, rel) / 'edit.json'
    return json.loads(path.read_text(encoding='utf-8')) if path.exists() else None


def capture(ctx, output, rel, state, proposal):
    """Rebase only uniquely anchored edits; preserve the editable files on every failure."""
    if state['file'] != rel or rel not in state['files']:
        raise ValueError('Editable source manifest differs from requested file')
    bundle, snapshots = {}, {}
    for stored, original in state['files'].items():
        path = name(stored)
        if path != rel and Path(path).suffix.lower() not in ('.h', '.hpp', '.inl'):
            raise ValueError('Related edits must be headers')
        candidate = (folder(output, rel) / path).read_text(encoding='utf-8-sig')
        snapshots[path] = candidate
        current = source(ctx, path, proposal)
        pairs = edits(original, candidate)
        if current != original:
            try:
                pairs = native_sweep.rebase_saved_edits(current, pairs)
            except ValueError as error:
                raise ValueError('Editable baseline changed for %s; reconcile the preserved file: %s' % (path, error)) from None
        bundle[path] = pairs
    return bundle, snapshots


def prepare(ctx, output, rel, related, proposal, fresh=False):
    rel = name(rel)
    directory = folder(output, rel)
    state = load(output, rel)
    fresh = bool(fresh and state)
    archived_paths = set(state['files']) if fresh else set()
    if state and not fresh:
        # Repeating edit never overwrites an agent's work, including after baseline advances.
        print('existing editable files preserved', flush=True)
    else:
        if state:
            archive = dict(state=state, sources={path: (directory / name(path)).read_text(encoding='utf-8-sig')
                                                for path in state['files']})
            integration.atomic_json(directory / 'archive' / (integration.digest(archive) + '.json'), archive)
        state = dict(file=rel, base_revision=ctx.base_revision, files={})
    paths = [rel, *(name(path) for path in related)]
    if len(paths) > 1 and Path(rel).suffix.lower() != '.cpp':
        raise ValueError('Use a CPP primary file for paired header edits')
    for path in paths:
        if path != rel and Path(path).suffix.lower() not in ('.h', '.hpp', '.inl'):
            raise ValueError('Related edits must be headers')
    # Read everything before writing anything: a bad path must not leave a partial draft.
    additions = {path: source(ctx, path, proposal) for path in paths if path not in state['files']}
    for path, text in additions.items():
        target = directory / path
        if target.exists() and path not in archived_paths:
            raise ValueError('Preserving untracked editable file: ' + str(target))
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(text, encoding='utf-8')
        state['files'][path] = text
    if getattr(ctx, 'translation_unit', None):
        state['translation_unit'] = ctx.translation_unit
    integration.atomic_json(directory / 'edit.json', state)
    for path in state['files']:
        print('edit: ' + str((directory / path).resolve()), flush=True)
    return state


def refresh(ctx, output, rel, state, snapshots, proposal):
    directory = folder(output, rel)
    if any((directory / path).read_text(encoding='utf-8-sig') != text for path, text in snapshots.items()):
        print('editable files changed during check; newer edits preserved', flush=True)
        return
    # Keep the exact captured draft before replacing it with the minimized, proven source.
    archive = dict(state=state, sources=snapshots)
    integration.atomic_json(directory / 'archive' / (integration.digest(archive) + '.json'), archive)
    texts = {path: source(ctx, path, proposal) for path in state['files']}
    for path, text in texts.items():
        (directory / path).write_text(text, encoding='utf-8')
    integration.atomic_json(directory / 'edit.json', dict(state, base_revision=ctx.base_revision, files=texts))
