"""Copy owner-approved native files to their original-layout paths in a separate tree.

Live files never move. The export lands in rebuild/2008-06/layout/ (locally excluded; published on branch layout/2008-06),
so every lane that reads native-classes/ and native-headers/ keeps working.

    python work/native-client/layout/layout_export.py families/gui-export.json

Manifest: {"family": "gui", "approved": ["rebuild/2008-06/native-classes/X.cpp", ...]}
Each path must have a row in source-layout-map.json with an unchanged sha256 and a
target_path. Quoted includes that resolve beside the source are rewritten to the
same file (search-path form when it is under native-headers); /I includes stay as is.
Writes rebuild/2008-06/layout/<family>-receipt.json. Codegen proof is a separate compile/compare step.
"""
import hashlib
import json
import os
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
EXPORT = ROOT / 'rebuild/2008-06/layout'   # published path on branch layout/2008-06; locally git-excluded
STRIP = 'rebuild/2008-06/'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
INCLUDE = re.compile(r'^(\s*#\s*include\s*")([^"]+)(")', re.M)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def hashes(raw):
    """Raw hash first, then LF and CRLF forms: line-ending-only drift is not a content change."""
    lf = raw.replace(b'\r\n', b'\n')
    return [sha(raw), sha(lf), sha(lf.replace(b'\n', b'\r\n'))]


def destination(target, tier=''):
    """Where an exported file goes: its best-guess original path, one tree for every file.

    `tier` is kept for callers but no longer changes the folder. No path is proven for 2008 (there is no 2008 PDB), so the
    old split into a main tree and an inferred/ tree meant nothing; how good a path guess is travels in the receipt
    (per file: 'path': 'original' or 'inferred') and in evidence.json.
    """
    if not target.startswith(STRIP):
        raise ValueError('target outside rebuild/2008-06: ' + target)
    rel = target[len(STRIP):]
    folder, _, name = rel.rpartition('/')
    return EXPORT / folder.lower() / name       # folders lower case: a Windows folder keeps its first case, GitHub does not


def rewrite(text, source, dest, headers=None):
    """Re-point includes that resolve relative to the source's own folder.

    A target under the shared include root becomes the search-path form
    ("v8tree/Verb.h"): the same file the live build finds through /I, so the
    exported unit never mixes an exported header copy with the live one.
    Anything else keeps pointing at the same file by relative path.
    """
    headers = (headers or HEADERS).resolve()
    changes = []

    def fix(m):
        local = (source.parent / m[2]).resolve()
        if not local.is_file():
            return m[0]  # found through /I search paths; layout-independent
        if local.is_relative_to(headers):
            new = local.relative_to(headers).as_posix()
        else:
            new = Path(os.path.relpath(local, dest.parent)).as_posix()
        if new != m[2]:
            changes.append({'old': m[2], 'new': new})
        return m[1] + new + m[3]

    return INCLUDE.sub(fix, text), changes


def export(manifest_path):
    manifest = json.loads(Path(manifest_path).read_text(encoding='utf-8'))
    rows = json.loads((HERE / 'source-layout-map.json').read_text(encoding='utf-8'))
    plan, blockers = {}, []
    inferred = set(manifest.get('inferred', []))   # heuristic paths: same tree, marked in the receipt
    for rel in manifest['approved'] + sorted(inferred):
        row = rows.get(rel)
        source = ROOT / rel
        if not row or not row.get('target_path'):
            blockers.append(rel + ': no mapped target')
        elif not source.is_file():
            blockers.append(rel + ': missing')
        elif row['sha256'] not in hashes(source.read_bytes()):
            blockers.append(rel + ': changed since inventory; refresh and re-review')
        else:
            plan[rel] = destination(row['target_path'], 'inferred' if rel in inferred else '')
    targets = [str(d).casefold() for d in plan.values()]
    if len(set(targets)) != len(targets):
        blockers.append('two approved sources share one target; merges are not exports')
    if blockers:
        raise SystemExit('blocked:\n  ' + '\n  '.join(blockers))
    files = {}
    for rel, dest in plan.items():
        source = ROOT / rel
        raw = source.read_bytes()
        # latin-1 round-trips every byte (BOM, cp1252 comments, CRLF); include paths are ASCII.
        # ponytail: an include on line 1 of a BOM file is not seen; none exists today.
        text, changes = rewrite(raw.decode('latin-1'), source, dest)
        data = text.encode('latin-1')
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_bytes(data)
        files[rel] = {'export': dest.relative_to(ROOT).as_posix(), 'source_sha256': sha(raw),
                      'export_sha256': sha(data), 'include_rewrites': changes,
                      'line_ending_drift': sha(raw) != rows[rel]['sha256']}
    receipt = {'family': manifest['family'], 'manifest': Path(manifest_path).as_posix(), 'files': files}
    out = EXPORT / (manifest['family'] + '-receipt.json')
    out.write_text(json.dumps(receipt, indent=1) + '\n', encoding='utf-8')
    print(f'exported {len(files)} files; {sum(bool(f["include_rewrites"]) for f in files.values())} include rewrites -> {out}')
    return receipt


if __name__ == '__main__':
    export(sys.argv[1])
