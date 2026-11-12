"""Accept reviewed missing methods as inactive source improvements, including inferred names."""
import argparse
from contextlib import closing
import json
from pathlib import Path
import re
import sqlite3
import subprocess
import time
import uuid

from roc import draft_family, draft_methods, draft_native, match, native_drafts, rebuild
from roc.draft_append import apply_append_file
from roc.draft_merger import apply_new_file, content_hash, proof_key, SCHEMA
from roc.draft_proof import SOURCE_CHECKS, validate_source_improvement


def verification_files(root):
    return ([root / 'roc' / (name + '.py') for name in ('draft_source', 'draft_native', 'draft_family',
             'draft_methods', 'draft_proof', 'draft_append', 'draft_merger', 'draft_files', 'match', 'rebuild',
             'libs', 'clients', 'integration_verify')]
            + [root / 'work/native-client' / (name + '.py') for name in
               ('native_class_layout', 'native_vftable_check', 'native_conversion_queue')])


def scoped_item(namespace, source):
    if namespace and not re.fullmatch(r'[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*', namespace):
        raise ValueError('Invalid reviewed namespace')
    parts = namespace.split('::') if namespace else []
    raw = ('\n'.join('namespace ' + name + ' {' for name in parts) + '\n'
           + source.strip() + '\n' + '}\n' * len(parts)).encode()
    tree = draft_methods.CPP_PARSER.parse(raw)
    roots = [node for node in tree.root_node.named_children if node.type != 'comment']
    children = roots
    for name in parts:
        if len(children) != 1 or children[0].type != 'namespace_definition':
            raise ValueError('Review changes namespace structure')
        body = children[0].child_by_field_name('body')
        children = [node for node in body.named_children if node.type != 'comment']
    return raw, children, tree.root_node.has_error


def method_contract(namespace, method):
    raw, children, syntax_error = scoped_item(namespace, method['source'])
    rows, errors = draft_methods.extract(raw)
    if (syntax_error or errors or len(children) != 1 or children[0].type != 'function_definition' or len(rows) != 1
            or rows[0]['needs_semantic_resolution'] or rows[0]['signature'] != method['signature']):
        raise ValueError('Review must contain exactly the named, unambiguous method body')
    if not re.fullmatch('[0-9a-fA-F]{8}', method['address']):
        raise ValueError('Invalid original method hypothesis address')
    owner, name = method['signature'].split('(')[0].rsplit('::', 2)[-2:]
    prefix = '??0' + owner + '@' if name == owner else '??1' + owner + '@' if name == '~' + owner else '?' + name + '@' + owner + '@'
    if not method['symbol'].startswith(prefix):
        raise ValueError('Compiler symbol does not name the reviewed method')
    return raw


def prelude_contract(review):
    raw = b''
    for include in review.get('includes', []):
        tree = draft_methods.CPP_PARSER.parse((include.strip() + '\n').encode())
        if tree.root_node.has_error or len(tree.root_node.named_children) != 1 or tree.root_node.named_children[0].type != 'preproc_include':
            raise ValueError('Prelude may only add literal include directives')
        raw += include.strip().encode() + b'\n'
    for declaration in review.get('declarations', []):
        wrapped, nodes, error = scoped_item(declaration['namespace'], declaration['source'])
        declarator = nodes[0].child_by_field_name('declarator') if len(nodes) == 1 else None
        if (error or len(nodes) != 1 or nodes[0].type != 'declaration' or declarator is None
                or declarator.type != 'function_declarator'):
            raise ValueError('Prelude declarations must be function prototypes, not definitions or state')
        raw += wrapped
    return raw


def prove(root, review_file, apply=False):
    from roc.integration_verify import input_hash
    root = Path(root).resolve()
    review_file = Path(review_file).resolve()
    if not review_file.is_relative_to(root / 'work/draft-merger/reviews'):
        raise ValueError('Source review must come from local coordinator store')
    review_raw = review_file.read_bytes()
    review = json.loads(review_raw)
    native_drafts.Inbox(root).packet(review['bundle'])
    path = native_drafts.safe_path(review['target'])
    if not path.startswith('rebuild/2008-06/native-classes/') or Path(path).suffix != '.cpp':
        raise ValueError('Reviewed source destination must be native CPP')
    new_file = review.get('new_file') is True
    methods = review['methods']
    if not methods or len({row['signature'] for row in methods}) != len(methods):
        raise ValueError('Need distinct new reviewed methods')
    suffix = prelude_contract(review) + b'\n'.join(method_contract(review['namespace'], method) for method in methods)
    profile = review.get('compiler_profile', 'default')
    if profile not in ('default', 'fast-fp'):
        raise ValueError('Unsupported owner-controlled compiler profile')
    output = root / 'work/draft-merger/source-improvements' / uuid.uuid4().hex
    output.mkdir(parents=True)
    result = dict(state='verifying', path=path, blockers=[])
    lease = None
    with native_drafts.lock(root / 'work/draft-integration.lock'):
        try:
            target = root / path
            if new_file:
                if target.exists() or review.get('before_sha256') is not None:
                    raise ValueError('Reviewed new source target is no longer absent')
                before = b''
            else:
                before = target.read_bytes()
                if content_hash(before) != review['before_sha256']:
                    raise ValueError('Reviewed source changed')
            if draft_native.compile_review_blockers(suffix, root, path):
                raise ValueError('Reviewed bodies contain unsupported preprocessing')
            existing_profile = re.search(rb'^// native-flags: (.*)', before, re.M)
            if existing_profile and ((b'/fp:fast' in existing_profile[1]) != (profile == 'fast-fp')):
                raise ValueError('Selected compiler profile conflicts with existing source profile')
            if profile == 'fast-fp' and not existing_profile:
                suffix = b'// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS\n' + suffix
            eol = b'\r\n' if not new_file and b'\r\n' in before else b'\n'
            after = suffix.replace(b'\r\n', b'\n').replace(b'\n', eol) if new_file else before + eol + suffix.replace(b'\r\n', b'\n').replace(b'\n', eol)
            draft_methods.build(root)
            index = json.loads((root / 'work/draft-merger/method-index.json').read_text())
            actual = {p.relative_to(root).as_posix() for p in draft_methods.source_paths(root)}
            if actual != set(index['inventory']) or any(content_hash((root / name).read_bytes()) != sha
                                                       for name, sha in index['inventory'].items()):
                raise ValueError('Provider index changed while checking source improvement')
            for method in methods:
                if any(not row['shadow'] for row in index['index'].get(method['signature'], [])):
                    raise ValueError('Method already has a canonical body: ' + method['signature'])
            pinned = input_hash(root)
            gate_paths = verification_files(root)
            gates = {str(name): content_hash(name.read_bytes()) for name in gate_paths}
            frozen, _ = draft_native.freeze_headers(root, output)
            key = proof_key(dict(inputs=pinned, gates=gates, review=content_hash(review_raw)))
            objects, bodies, builds = [], [], {}
            baseline = prelude_contract(review)
            if profile == 'fast-fp' and new_file:
                baseline = b'// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS\n' + baseline
            for kind, raw in (('baseline', baseline if new_file else before), ('candidate', after)):
                folder = output / kind
                folder.mkdir()
                source, obj = folder / Path(path).name, folder / 'unit.obj'
                source.write_bytes(raw)
                flags = draft_native.flags(frozen) + ['/I' + str((frozen / path).parent)]
                if profile == 'fast-fp' and (kind == 'candidate' or existing_profile):
                    flags += ['/fp:fast']
                flags += ['/Fo' + str(obj), str(source)]
                code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, folder, timeout=120)
                (folder / 'compiler.log').write_text(log)
                if code:
                    raise ValueError(kind + ' compile failed: ' + log[-1400:])
                builds[kind] = dict(exit=code, flags=flags)
                objects.append(obj)
                bodies.append({name: (body, refs) for name, body, refs in match.coff_functions(obj.read_bytes())})
            for name, body in bodies[0].items():
                if name not in bodies[1] or not match.exact_match(*body, *bodies[1][name]):
                    raise ValueError('Existing emitted method changed: ' + name)
                if match.coff_data_refs(objects[0].read_bytes(), name) != match.coff_data_refs(objects[1].read_bytes(), name):
                    raise ValueError('Existing referenced data changed: ' + name)
            witnesses = [(row['symbol'], int(row['address'], 16)) for row in methods]
            if any(symbol not in bodies[1] or symbol in bodies[0] for symbol, _ in witnesses):
                raise ValueError('Review did not add the expected compiler-resolved methods')
            original, binder = draft_native.original_view(root)
            closure = root / 'work/native-client/claude-identity-closure.json'
            closure_raw = closure.read_bytes()
            bindings = json.loads(closure_raw)['bindings']
            external = draft_native.closed_function_targets(bindings)
            numeric = draft_native.numeric_literal_targets(original, objects[1], witnesses)
            calls = draft_native.reviewed_call_targets(original, binder, objects[1], witnesses, bindings)
            reviewed_original = draft_native.ReviewedOriginal(original, calls['import_aliases'])
            reference = binder.verify(reviewed_original, objects[1], witnesses,
                dict(calls['targets'], **external, **numeric['targets']), dict(witnesses))
            layout = draft_family.measure_layout_preservation(root, dict(builds=builds), output)
            if layout['state'] != 'preserved-before-layout':
                raise ValueError('Existing class/virtual declarations changed or could not be compared')
            owners = {row['signature'].split('(')[0].rsplit('::', 2)[-2] for row in methods}
            selected = {symbol for symbol, _ in witnesses}
            providers = []
            provider_issues = []
            for other in draft_methods.source_paths(root):
                name = other.relative_to(root).as_posix()
                if other == root / path or draft_methods.shadow_path(name) or other.suffix.lower() not in ('.cpp', '.cc', '.cxx'):
                    continue
                if not any(owner.encode() in other.read_bytes() for owner in owners):
                    continue
                folder = output / 'providers' / proof_key(name)[:16]
                folder.mkdir(parents=True)
                obj = folder / 'unit.obj'
                flags = draft_native.flags(frozen) + (['/fp:fast'] if profile == 'fast-fp' else [])
                code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags + ['/Fo' + str(obj), str(other)], folder, timeout=120)
                (folder / 'compiler.log').write_text(log)
                if code:
                    provider_issues.append('Existing related source compile needs separate review: ' + name)
                    continue
                if selected & {name for name, _, _ in match.coff_functions(obj.read_bytes())}:
                    raise ValueError('Compiler-resolved provider collision: ' + name)
                providers.append(name)

            def fresh():
                return (input_hash(root) == pinned and review_file.read_bytes() == review_raw
                        and closure.read_bytes() == closure_raw
                        and (not target.exists() if new_file else content_hash(target.read_bytes()) == content_hash(before))
                        and all(content_hash(Path(name).read_bytes()) == sha for name, sha in gates.items()))

            if not fresh():
                raise ValueError('Inputs changed during source improvement review')
            questions = list(review.get('open_questions', [])) + provider_issues
            if any(row['local_eh'] for row in reference):
                questions.append('Original exception metadata remains a runtime-promotion gate')
            inferences = list(review.get('inferences', []))
            if calls['notes']:
                inferences.append('Some direct function names use local corroborated identity evidence; see inferred_calls. No runtime proof claimed.')
            receipt = dict(schema=1, kind='reviewed-source-improvement', inactive=True, path=path,
                           candidate_sha256=content_hash(after), before_sha256=None if new_file else content_hash(before), input_key=key,
                           client='2008-06', verifier_sha256=content_hash(Path(__file__).read_bytes()),
                           before_methods=sorted(bodies[0]), after_methods=sorted(set(bodies[0]) |
                               {symbol + '@%08x' % address for symbol, address in witnesses}),
                           checks={name: True for name in SOURCE_CHECKS}, reviewer=review['reviewer'],
                           rationale=review['rationale'], inferences=inferences, inferred_calls=calls['notes'], open_questions=questions,
                           scope=('Reviewed new inactive source unit containing only proven methods and reviewed prelude. '
                                  if new_file else 'Reviewed inactive source methods; ') +
                                 'Partial class/inferred names allowed. No complete original ABI or executable promotion claim.',
                           compiler_profile=profile, reference_evidence=reference, numeric_literals=numeric['literals'],
                           layout_preservation=layout, related_providers=providers, native_input_key=pinned, gate_hashes=gates)
            expected = {name: receipt[name] for name in ('candidate_sha256', 'input_key', 'client', 'verifier_sha256')}
            blockers = validate_source_improvement(receipt, expected)
            if blockers:
                raise ValueError('; '.join(blockers))
            native_drafts.atomic(output / 'receipt.json', receipt)
            with closing(sqlite3.connect(root / 'work/draft-merger/state.sqlite3')) as db, db:
                db.executescript(SCHEMA)
                identifier = proof_key(receipt)
                db.execute('INSERT OR REPLACE INTO proofs VALUES(?,?,?,?,?,?)',
                    (identifier, key, 'reviewed-inactive-methods-v1', content_hash(after), json.dumps(receipt), time.time()))
                result.update(state='reviewed-source-improvement', receipt=str(output / 'receipt.json'))
                if apply:
                    requested_lease = 'draft-source-' + output.name[:10]
                    subprocess.run([str(root / 'roc.cmd'), 'lease', 'take', requested_lease, path, '--hours', '2'], cwd=root, check=True, capture_output=True)
                    lease = requested_lease
                    def lease_check(name):
                        subprocess.run([str(root / 'roc.cmd'), 'lease', 'check', name], cwd=root, check=True, capture_output=True)
                    if new_file:
                        result['action'] = apply_new_file(root, db, 'reviewed-source-improvement', review['bundle'], path,
                            after, identifier, expected, lease_check, lambda: key if fresh() else 'stale')
                    else:
                        result['action'] = apply_append_file(root, db, 'reviewed-source-improvement', review['bundle'], path,
                            after, identifier, expected, lease_check, lambda: key if fresh() else 'stale')
                    result['state'] = 'integrated-inactive'
            return result
        except Exception as error:
            result.update(state='blocked', blockers=[str(error)])
            return result
        finally:
            try:
                native_drafts.atomic(output / 'result.json', result)
            finally:
                if lease:
                    subprocess.run([str(root / 'roc.cmd'), 'lease', 'release', lease], cwd=root, capture_output=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('review', type=Path)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--apply', action='store_true')
    args = parser.parse_args()
    print(json.dumps(prove(args.root, args.review, args.apply), indent=2))
