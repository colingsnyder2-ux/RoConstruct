"""Deterministic partial-method proposals and acceptance; no model calls."""
import argparse
import json
from pathlib import Path

from roc import draft_methods, draft_source, native_drafts
from roc.draft_merger import content_hash, proof_key


def discover(root, users=()):
    root = Path(root).resolve()
    folder = root / 'work/draft-merger'
    choices, skipped = {}, []
    selected = {str(user).lower() for user in users}
    draft_methods.build(root)
    canonical_index = json.loads((folder / 'method-index.json').read_text())['index']
    with native_drafts.Inbox(root).connect() as db:
        uploaders = dict(db.execute('SELECT id,user FROM bundles'))
    for path in sorted((folder / 'families').glob('*/measurement.json')):
        measurement = json.loads(path.read_text())
        manifest = json.loads(path.with_name('manifest.json').read_text())
        uploader = uploaders.get(manifest['bundle_id'])
        if selected and (uploader or '').lower() not in selected:
            continue
        profile = measurement.get('profile', 'default')
        if profile not in ('default', 'fast-fp'):
            continue
        for unit in measurement['units']:
            name = native_drafts.safe_path(unit['path'])
            target = root / name
            if not name.startswith('rebuild/2008-06/native-classes/'):
                skipped.append(dict(bundle=manifest['bundle_id'], path=name, reason='Only native class source is supported'))
                continue
            candidate = path.parent / 'overlay' / name
            if not candidate.resolve().is_relative_to((path.parent / 'overlay').resolve()):
                raise ValueError('Family candidate escaped scratch')
            raw = candidate.read_bytes()
            rows, _ = draft_methods.extract(raw)
            current_raw = target.read_bytes() if target.is_file() else b''
            current, _ = draft_methods.extract(current_raw)
            existing = {row['signature']: row for row in current}
            nodes = {}
            stack = [draft_methods.CPP_PARSER.parse(raw).root_node]
            while stack:
                node = stack.pop()
                if node.type == 'function_definition':
                    nodes.setdefault(node.start_point.row + 1, []).append(node)
                stack.extend(node.named_children)
            groups = {}
            for row in rows:
                if row['signature'] in existing:
                    if row['body_sha256'] != existing[row['signature']]['body_sha256']:
                        skipped.append(dict(bundle=manifest['bundle_id'], path=name, method=row['signature'],
                                            reason='Existing body differs; retain it and queue improvement comparison'))
                    continue
                providers = sorted({hit['path'] for hit in canonical_index.get(row['signature'], []) if not hit['shadow']})
                if providers:
                    skipped.append(dict(bundle=manifest['bundle_id'], path=name, method=row['signature'],
                                        reason='Method already has canonical provider', providers=providers))
                    continue
                parts = row['signature'].split('(')[0].split('::')
                if row['needs_semantic_resolution'] or len(parts) < 2 or len(nodes.get(row['line'], [])) != 1:
                    continue
                owner, method_name = parts[-2:]
                namespace = '::'.join(parts[:-2])
                prefix = '??0' + owner + '@' if method_name == owner else '??1' + owner + '@' if method_name == '~' + owner else '?' + method_name + '@' + owner + '@'
                hits = [hit for hit in unit.get('original_methods', [])
                        if hit['exact_code'] and hit.get('baseline_exact_code') is not True
                        and hit['symbol'].startswith(prefix)]
                hits = {(hit['symbol'], hit['address']): hit for hit in hits}
                if len(hits) != 1:
                    continue
                hit = next(iter(hits.values()))
                method = dict(signature=row['signature'], source=nodes[row['line']][0].text.decode(),
                              symbol=hit['symbol'], address=hit['address'])
                try:
                    draft_source.method_contract(namespace, method)
                except ValueError:
                    continue
                groups.setdefault(namespace, []).append(method)
            for namespace, methods in groups.items():
                current_tree = draft_methods.CPP_PARSER.parse(current_raw)
                current_includes = {node.text.decode().strip() for node in current_tree.root_node.named_children
                                    if node.type == 'preproc_include'}
                tree = draft_methods.CPP_PARSER.parse(raw)
                includes = [node.text.decode().strip() for node in tree.root_node.named_children
                            if node.type == 'preproc_include' and node.text.decode().strip() not in current_includes]
                declarations = []
                pending = [(tree.root_node, [])]
                selected_text = '\n'.join(row['source'] for row in methods)
                while pending:
                    node, scopes = pending.pop()
                    if node.type == 'namespace_definition':
                        name_node = node.child_by_field_name('name')
                        if name_node is None:
                            continue
                        pending.extend((child, scopes + [name_node.text.decode()])
                                       for child in node.child_by_field_name('body').named_children)
                    elif node.type == 'translation_unit':
                        pending.extend((child, scopes) for child in node.named_children)
                    elif node.type == 'declaration':
                        declarator = node.child_by_field_name('declarator')
                        identifier = declarator.child_by_field_name('declarator') if declarator else None
                        if (declarator and declarator.type == 'function_declarator' and identifier
                                and identifier.type == 'identifier' and identifier.text.decode() + '(' in selected_text.replace(' ', '')):
                            declarations.append(dict(namespace='::'.join(scopes), source=node.text.decode()))
                review = dict(bundle=manifest['bundle_id'], uploader=uploader, target=name, namespace=namespace,
                    before_sha256=content_hash(current_raw) if target.is_file() else None,
                    new_file=not target.is_file(), compiler_profile=profile, methods=methods,
                    includes=includes, declarations=declarations,
                    reviewer='deterministic missing-method/original-instruction source review',
                    rationale='Adds absent method bodies measured against original instructions; final acceptance recompiles and checks relevant preservation, data and provider evidence.',
                    inferences=['Names may be inferred. Family measurements are proposal evidence; fresh source acceptance checks are required.'],
                    open_questions=['Class may remain partial. Unselected methods, complete original ABI and executable promotion remain separate.'],
                    proposal_evidence=dict(path=str(path), sha256=content_hash(path.read_bytes())))
                identifier = proof_key(review)
                group = (name, namespace)
                reference_score = sum(bool(hit.get('references_verified')) for hit in unit.get('original_methods', []))
                rank = (len(methods), reference_score, len(manifest.get('companion_bundles', [])),
                        profile == 'fast-fp', identifier)
                if group not in choices or rank > choices[group][0]:
                    choices[group] = (rank, identifier, review)
    proposals = []
    for _, identifier, review in sorted(choices.values(), key=lambda row: row[1]):
        path = folder / 'reviews' / ('source-' + identifier + '.json')
        native_drafts.atomic(path, review)
        proposals.append(str(path))
    result = dict(proposals=proposals, count=len(proposals), skipped=skipped, models_used=0)
    native_drafts.atomic(folder / 'source-queue.json', result)
    return dict(count=len(proposals), skipped=len(skipped), models_used=0)


def work(root, limit=3, apply=False):
    from roc.integration_verify import input_hash
    root = Path(root).resolve()
    if not 0 <= limit <= 100:
        raise ValueError('Source work limit must be between 0 and 100')
    folder = root / 'work/draft-merger'
    queue = json.loads((folder / 'source-queue.json').read_text())
    context_file = folder / 'family-queue.json'
    context = json.loads(context_file.read_text()).get('input_key') if context_file.is_file() else None
    native_context = input_hash(root)
    gates = {str(path): content_hash(path.read_bytes()) for path in
             draft_source.verification_files(root) + [root / 'roc/draft_source_queue.py']}
    results = []

    def attempt(review):
        target = root / native_drafts.safe_path(review['target'])
        review = dict(review, before_sha256=content_hash(target.read_bytes()) if target.is_file() else None,
                      new_file=not target.is_file())
        identifier = proof_key(review)
        path = folder / 'reviews' / ('source-work-' + identifier + '.json')
        native_drafts.atomic(path, review)
        key = proof_key(dict(review=identifier, context=context, native_context=native_context,
                             gates=gates, apply=apply))
        artifact = folder / 'source-attempts' / (key + '.json')
        if context and artifact.is_file():
            return json.loads(artifact.read_text())
        if len(results) >= limit:
            return None
        try:
            result = draft_source.prove(root, str(path), apply)
        except Exception as error:
            result = dict(state='blocked', path=review['target'], blockers=[type(error).__name__ + ': ' + str(error)])
        result['reviewed_methods'] = [row['signature'] for row in review['methods']]
        native_drafts.atomic(artifact, result)
        results.append(result)
        return result

    with native_drafts.lock(folder / 'source-queue.lock'):
        for review_path in queue['proposals']:
            if len(results) >= limit:
                break
            review = json.loads(Path(review_path).read_text())
            target = root / review['target']
            current, _ = draft_methods.extract(target.read_bytes() if target.is_file() else b'')
            existing = {row['signature'] for row in current}
            methods = [row for row in review['methods'] if row['signature'] not in existing]
            if not methods:
                continue
            result = attempt(dict(review, methods=methods))
            if result and result['state'] == 'blocked' and len(methods) > 1:
                # A bad sibling must not prevent a useful independent method.
                for method in methods:
                    if len(results) >= limit:
                        break
                    attempt(dict(review, methods=[method],
                                 rationale=review['rationale'] + ' Review this method independently of blocked siblings.'))
    result = dict(attempted=len(results), integrated=sum(row['state'] == 'integrated-inactive' for row in results),
                  models_used=0, results=results)
    native_drafts.atomic(folder / 'source-work-latest.json', result)
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('discover', 'work'))
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--limit', type=int, default=3)
    parser.add_argument('--apply', action='store_true')
    parser.add_argument('--user', action='append', default=[])
    args = parser.parse_args()
    print(json.dumps(discover(args.root, args.user) if args.action == 'discover' else work(args.root, args.limit, args.apply), indent=2))
