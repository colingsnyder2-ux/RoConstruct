"""Extract supported getter proposals; original compiler/layout gates still decide."""
import argparse
from contextlib import closing
import json
from pathlib import Path
import re
import sqlite3

from roc.draft_getter import getter_contract, prove
from roc.draft_merger import content_hash, proof_key
from roc.draft_methods import CPP_PARSER, extract
from roc.native_drafts import atomic


def refresh_path(root, name):
    from roc.draft_merger import canonical_state
    root = Path(root).resolve()
    state = canonical_state(root, [name])[name]
    if not state['exists']:
        raise ValueError('Cannot index an absent canonical source')
    path = root / 'work/draft-merger/method-index.json'
    report = json.loads(path.read_text())
    for signature in list(report['index']):
        report['index'][signature] = [row for row in report['index'][signature] if row['path'] != name]
        if not report['index'][signature]:
            del report['index'][signature]
    rows, errors = extract((root / name).read_bytes())
    for row in rows:
        report['index'].setdefault(row['signature'], []).append(dict(row, path=name,
            sha256=state['sha256'], shadow=False, parse_errors=errors))
    report['inventory'][name] = state['sha256']
    report['identity'] = proof_key(dict(files=report['inventory'], verifier=content_hash((root / 'roc/draft_methods.py').read_bytes())))
    atomic(path, report)


def measured_sources(root, db):
    """Read fresh original and LLM measurements, retaining proposal provenance."""
    folder = root / 'work/draft-merger'
    inventory = {path.relative_to(root).as_posix(): content_hash(path.read_bytes())
                 for family in ('native-headers', 'native-classes')
                 for path in (root / 'rebuild/2008-06' / family).rglob('*') if path.is_file()}
    for name in ('native-latest.json', 'native-review-latest.json'):
        path = folder / name
        if not path.is_file():
            continue
        report = json.loads(path.read_text())
        if report['summary'].get('stale') or report['summary'].get('frozen_inventory_key') != proof_key(inventory):
            continue
        for unit in report['units']:
            data = db.execute('SELECT bytes FROM contents WHERE sha256=?', (unit['candidate_sha256'],)).fetchone()
            if data:
                raw = data[0]
            else:
                raw = None
                if unit.get('proposals'):
                    for identifier, source in db.execute('SELECT id,source FROM review_proposals WHERE sha256=?',
                                                         (unit['candidate_sha256'],)):
                        if identifier in unit['proposals']:
                            raw = source.encode('utf-8')
                            break
            if raw is not None and content_hash(raw) == unit['candidate_sha256']:
                yield unit, raw


def discover(root):
    root = Path(root).resolve()
    folder = root / 'work/draft-merger'
    contracts = {}
    with closing(sqlite3.connect(folder / 'state.sqlite3')) as db:
        for unit, raw in measured_sources(root, db):
            target = root / unit['path']
            if not target.is_file():
                continue
            before = target.read_bytes()
            current, _ = extract(before)
            current_signatures = {row['signature'] for row in current}
            tree = CPP_PARSER.parse(raw)
            stack = [tree.root_node]
            while stack:
                node = stack.pop()
                stack.extend(node.named_children)
                if node.type != 'function_definition':
                    continue
                source = node.text.decode('utf-8')
                hit = re.fullmatch(r'(?:int|bool|float|double|std::string)\s+([A-Za-z_]\w*)::([A-Za-z_]\w*)\s*\(\s*\)\s+const\s*\{\s*return\s+([A-Za-z_]\w*)\s*;\s*\}', source)
                if not hit:
                    continue
                namespaces, parent = [], node.parent
                uncertain = False
                while parent:
                    if parent.type == 'namespace_definition':
                        name = parent.child_by_field_name('name')
                        if name:
                            namespaces.insert(0, name.text.decode())
                        else:
                            uncertain = True
                    if parent.type in ('template_declaration', 'preproc_if', 'preproc_ifdef', 'class_specifier'):
                        uncertain = True
                    parent = parent.parent
                if uncertain or not namespaces:
                    continue
                method = '::'.join([*namespaces, hit[1], hit[2]]) + '() const'
                matched = [row for row in unit['methods'] if row['references_verified'] and row['exact_code']
                           and row['symbol'].startswith('?' + hit[2] + '@' + hit[1] + '@')]
                if len(matched) != 1:
                    continue
                header = None
                for include in re.findall(r'^\s*#\s*include\s*"([^"\n]+)"', before.decode('utf-8-sig'), re.M):
                    path = (root / 'rebuild/2008-06/native-headers' / include).resolve()
                    if path.is_relative_to(root / 'rebuild/2008-06/native-headers') and path.is_file():
                        if re.search(r'\bclass\s+' + re.escape(hit[1]) + r'\b', path.read_text(encoding='utf-8-sig')):
                            header = path
                            break
                if header is None:
                    continue
                review = dict(review='deterministic supported-getter extraction', decision='proposal-unverified',
                    target=unit['path'], method=method, address=matched[0]['address'], method_source=source,
                    bundles=unit['bundles'], candidate_sha256=unit['candidate_sha256'],
                    proposals=unit.get('proposals', []),
                    evidence=dict(canonical_source=dict(path=unit['path'], sha256=content_hash(before)),
                                  header=dict(path=header.relative_to(root).as_posix(), sha256=content_hash(header.read_bytes()))))
                contract = getter_contract(review)
                if contract['signature'] in current_signatures:
                    continue
                identifier = proof_key(dict(method=method, address=review['address'], body=source,
                                            canonical_sha256=content_hash(before)))
                contracts.setdefault(identifier, review)
    paths = []
    for identifier, review in contracts.items():
        path = folder / 'reviews' / ('getter-' + identifier + '.json')
        atomic(path, review)
        paths.append(str(path))
    atomic(folder / 'getter-queue.json', dict(proposals=paths))
    return dict(proposals=paths, count=len(paths))


def work(root, apply=False):
    root = Path(root).resolve()
    queue = json.loads((root / 'work/draft-merger/getter-queue.json').read_text())
    results = []
    for review in queue['proposals']:
        result = prove(root, review, apply)
        results.append(result)
        if result['state'] == 'integrated-inactive':
            refresh_path(root, result['path'])
    atomic(root / 'work/draft-merger/getter-results.json', dict(results=results))
    return dict(attempted=len(results), integrated=sum(row['state'] == 'integrated-inactive' for row in results), results=results)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('discover', 'work', 'refresh'))
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--path')
    parser.add_argument('--apply', action='store_true')
    args = parser.parse_args()
    if args.action == 'refresh':
        refresh_path(args.root, args.path)
    else:
        print(json.dumps(discover(args.root) if args.action == 'discover' else work(args.root, args.apply), indent=2))
