"""Independently prove reviewed, inactive scalar/string member-getter additions.

This deliberately scoped adapter verifies touched member ABI and unchanged
headers. It never claims a complete class swap, runtime gate or server credit.
"""
import argparse
from contextlib import closing
import importlib.util
import json
from pathlib import Path
import re
import sqlite3
import subprocess
import time
import uuid

from roc import match, native_drafts, rebuild
from roc.draft_merger import canonical_state, content_hash, proof_key
from roc.draft_methods import CPP_PARSER, extract, tokens, source_paths, shadow_path
from roc.draft_native import flags, original_view, compile_review_blockers
from roc.draft_proof import validate_receipt


def getter_contract(review):
    method = review['method_source'].strip()
    hit = re.fullmatch(r'(int|bool|float|double|std::string)\s+([A-Za-z_]\w*)::([A-Za-z_]\w*)\s*\(\s*\)\s+const\s*\{\s*return\s+([A-Za-z_]\w*)\s*;\s*\}', method)
    if not hit:
        raise ValueError('Reviewed method is outside the direct const member-getter adapter')
    namespace = review['method'].rsplit('::', 2)[0]
    if not re.fullmatch(r'[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*', namespace):
        raise ValueError('Invalid method namespace')
    wrapped = ('namespace ' + namespace + ' {\n' + method + '\n}\n').encode()
    methods, errors = extract(wrapped)
    if errors or len(methods) != 1 or methods[0]['signature'] != tokens(review['method']):
        raise ValueError('Review identity and candidate function differ')
    return dict(owner=hit[2], name=hit[3], member=hit[4], return_type=hit[1],
                namespace=namespace, signature=methods[0]['signature'], append=b'\n' + wrapped)


def prove(root, review_file, apply=False):
    from roc.integration_verify import input_hash
    from roc.draft_append import apply_append_file
    root = Path(root).resolve()
    review_file = Path(review_file).resolve()
    if not review_file.is_relative_to(root / 'work/draft-merger/reviews'):
        raise ValueError('Review must come from the local coordinator review store')
    review = json.loads(review_file.read_text())
    contract = getter_contract(review)
    path = native_drafts.safe_path(review['target'])
    if not path.startswith('rebuild/2008-06/native-classes/'):
        raise ValueError('Getter destination must be a canonical native source')
    token = native_drafts.integration_lock(root, 'start')['token']
    lease_name = None
    output = root / 'work/draft-merger/getters' / uuid.uuid4().hex
    output.mkdir(parents=True)
    result = dict(path=path, method=review['method'], state='verifying', blockers=[])
    try:
        before = (root / path).read_bytes()
        if content_hash(before) != review['evidence']['canonical_source']['sha256']:
            raise ValueError('Reviewed canonical source changed; refresh review')
        header = review['evidence']['header']['path']
        if canonical_state(root, [header])[header]['sha256'] != review['evidence']['header']['sha256']:
            raise ValueError('Reviewed declaration/header changed')
        index = json.loads((root / 'work/draft-merger/method-index.json').read_text())
        actual = {item.relative_to(root).as_posix() for item in source_paths(root)
                  if not shadow_path(item.relative_to(root).as_posix())}
        indexed = {name for name in index['inventory'] if not shadow_path(name)}
        if actual != indexed:
            raise ValueError('Canonical provider inventory changed; rebuild method index')
        for name, sha in index['inventory'].items():
            if shadow_path(name):
                continue
            current = root / name
            if not current.is_file() or content_hash(current.read_bytes()) != sha:
                raise ValueError('Canonical provider index is stale: ' + name)
        providers = [hit for hit in index['index'].get(contract['signature'], []) if not hit['shadow']]
        if providers:
            raise ValueError('Method already has a canonical definition: ' + str([hit['path'] for hit in providers]))
        eol = b'\r\n' if b'\r\n' in before else b'\n'
        after = before + contract['append'].replace(b'\r\n', b'\n').replace(b'\n', eol)
        if compile_review_blockers(after, root, path):
            raise ValueError('Source includes require review')
        input_before = input_hash(root)
        verifier_sha = content_hash(Path(__file__).read_bytes())
        gate_modules = ('draft_getter.py','draft_methods.py','draft_native.py','draft_proof.py',
                        'draft_append.py','draft_merger.py','draft_files.py')
        gate_hashes = {name:content_hash((root/'roc'/name).read_bytes()) for name in gate_modules}
        closure_file = root / 'work/native-client/claude-identity-closure.json'
        closure_raw = closure_file.read_bytes()
        closure = json.loads(closure_raw)
        closure_sha = content_hash(closure_raw)
        key = proof_key(dict(native_inputs=input_before, review=content_hash(review_file.read_bytes()),
                             verifier_sha256=verifier_sha, closure_sha256=closure_sha, gate_modules=gate_hashes))
        configuration = flags(root)
        tc = rebuild.toolchain(21022)
        objects = []
        for label, raw in (('before', before), ('after', after)):
            folder = output / label
            folder.mkdir()
            source, obj = folder / Path(path).name, folder / 'unit.obj'
            source.write_bytes(raw)
            code, log = rebuild.run(tc, 'cl', configuration + ['/I' + str((root / path).parent),
                                   '/Fo' + str(obj), str(source)], folder, timeout=120)
            (folder / 'compiler.log').write_text(log)
            if code:
                raise ValueError(label + ' translation unit compile failed: ' + log[-1800:])
            objects.append(obj)
        bodies = [{name: (body, refs) for name, body, refs in match.coff_functions(obj.read_bytes())} for obj in objects]
        for name, (body, refs) in bodies[0].items():
            if name not in bodies[1] or not match.exact_match(body, refs, *bodies[1][name]):
                raise ValueError('Existing emitted method changed or disappeared: ' + name)
            if match.coff_data_refs(objects[0].read_bytes(), name) != match.coff_data_refs(objects[1].read_bytes(), name):
                raise ValueError('Existing referenced data changed: ' + name)
        identities = [row for row in closure['bindings'] if row['address'].lower() == review['address'].lower()
                      and row.get('body_exact') and row.get('function_start') and row['symbol'] in bodies[1]
                      and row['symbol'] not in bodies[0]]
        if len(identities) != 1:
            raise ValueError('Need one independent closed original identity for the newly emitted method')
        identity = identities[0]
        symbol, address = identity['symbol'], int(identity['address'], 16)
        if not symbol.startswith('?' + contract['name'] + '@' + contract['owner'] + '@'):
            raise ValueError('Compiler symbol does not name the reviewed getter')
        original, binder = original_view(root)
        reference = binder.verify(original, objects[1], [(symbol, address)], {})
        if any(row['local_eh'] for row in reference):
            raise ValueError('Unproved exception/unwind metadata')
        # Compiler class layout is checked specifically against this getter's
        # original ECX displacement, not merely a zero-contradiction total.
        layout_tool = root / 'work/native-client/native_class_layout.py'
        spec = importlib.util.spec_from_file_location('_draft_getter_layout', layout_tool)
        layout = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(layout)
        layout_flags = [flag for flag in configuration if flag != '/c']
        code, log = rebuild.run(tc, 'cl', layout_flags + ['/Zs', '/d1reportAllClassLayout',
                                  str(output / 'after' / Path(path).name)], output, timeout=120)
        (output / 'layout.log').write_text(log)
        classes = layout.parse(log)
        selected = [row for name, row in classes.items() if name.split('::')[-1] == contract['owner']]
        if code or len(selected) != 1:
            raise ValueError('Original compiler did not resolve the exact owner layout')
        members = [row for row in selected[0]['members'] if re.search(r'\b' + re.escape(contract['member']) + r'$', row['name'])]
        target, relocs, _ = match.target('2008-06', review['address'])
        assembly = match.asm_lines(target, relocs)
        offsets = set()
        for line in assembly:
            offsets.update(int(value, 16) for group in re.findall(r'\[ecx \+ (0x[0-9a-f]+)\]|add ecx, (0x[0-9a-f]+)', line) for value in group if value)
        if len(members) != 1 or offsets != {members[0]['offset']}:
            raise ValueError('Touched member layout not proven against original getter displacement')
        # Compile each possible family provider; original decorated identities,
        # not spelling alone, decide whether another TU already defines it.
        collisions = []
        for other in (root / 'rebuild/2008-06/native-classes').rglob('*.cpp'):
            if other == root / path:
                continue
            raw = other.read_bytes()
            if contract['owner'].encode() not in raw and contract['name'].encode() not in raw:
                continue
            folder = output / 'providers' / proof_key(other.relative_to(root).as_posix())[:16]
            folder.mkdir(parents=True)
            obj = folder / 'unit.obj'
            code, log = rebuild.run(tc, 'cl', configuration + ['/Fo' + str(obj), str(other)], folder, timeout=120)
            (folder / 'compiler.log').write_text(log)
            if code:
                raise ValueError('Possible family provider needs dependency repair: ' + other.name + ': ' + log[-1200:])
            if any(name == symbol for name, _, _ in match.coff_functions(obj.read_bytes())):
                collisions.append(other.relative_to(root).as_posix())
        if collisions:
            raise ValueError('Existing compiler-resolved provider collision: ' + str(collisions))
        if (input_hash(root) != input_before or content_hash(closure_file.read_bytes()) != closure_sha or
                any(content_hash((root/'roc'/name).read_bytes())!=sha for name,sha in gate_hashes.items())):
            raise ValueError('Canonical dependencies changed during getter proof')
        before_ids = sorted(bodies[0])
        after_ids = sorted(set(before_ids) | {symbol + '@' + review['address']})
        receipt = dict(schema=1, kind='independent-draft-proof', client='2008-06', path=path,
                       candidate_sha256=content_hash(after), before_sha256=content_hash(before),
                       input_key=key, verifier_sha256=verifier_sha, before_methods=before_ids,
                       native_input_key=input_before, gate_modules=gate_hashes,
                       after_methods=after_ids, checks=dict(compile=True, code=True, relocations=True,
                       data=True, strings=True, abi=True, dependencies=True, preservation=True,
                       batch_symbols=True, regressions=True), reference_evidence=reference,
                       touched_member=members[0], original_instructions=assembly,
                       closure_sha256=closure_sha,
                       scope='Inactive getter body only: unchanged header/virtual declarations; touched member/return ABI and before-method preservation. No whole-class swap or runtime claim.')
        expected = {name: receipt[name] for name in ('candidate_sha256', 'input_key', 'client', 'verifier_sha256')}
        blockers = validate_receipt(receipt, expected)
        if blockers:
            raise ValueError('; '.join(blockers))
        native_drafts.atomic(output / 'proof.json', receipt)
        result.update(state='proven-inactive', receipt=str(output / 'proof.json'), symbol=symbol)
        with closing(sqlite3.connect(root / 'work/draft-merger/state.sqlite3')) as db, db:
            identifier = proof_key(receipt)
            db.execute('INSERT OR REPLACE INTO proofs VALUES(?,?,?,?,?,?)',
                       (identifier, key, 'original-msvc-method-v1', content_hash(after), json.dumps(receipt), time.time()))
            if apply:
                requested_lease = 'draft-getter-' + contract['owner']
                command = [str(root / 'roc.cmd'), 'lease', 'take', requested_lease, path, '--hours', '2']
                subprocess.run(command, cwd=root, check=True, capture_output=True)
                lease_name = requested_lease
                def lease_check(name):
                    subprocess.run([str(root / 'roc.cmd'), 'lease', 'check', name], cwd=root, check=True, capture_output=True)
                def current_key():
                    return key if (input_hash(root) == input_before and
                        content_hash(closure_file.read_bytes()) == closure_sha and
                        content_hash(Path(__file__).read_bytes()) == verifier_sha and
                        all(content_hash((root/'roc'/name).read_bytes())==sha for name,sha in gate_hashes.items())) else 'stale'
                result['action'] = apply_append_file(root, db, 'reviewed-getter', review['bundles'][0],
                    path, after, identifier, expected, lease_check, current_key)
                result['state'] = 'integrated-inactive'
        return result
    except Exception as error:
        result.update(state='blocked', blockers=[str(error)])
        return result
    finally:
        try:
            native_drafts.atomic(output / 'result.json', result)
        finally:
            try:
                if lease_name:
                    subprocess.run([str(root / 'roc.cmd'), 'lease', 'release', lease_name], cwd=root, capture_output=True)
            finally:
                native_drafts.integration_lock(root, 'release', token=token)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('review', type=Path)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--apply', action='store_true')
    args = parser.parse_args()
    print(json.dumps(prove(args.root, args.review, args.apply), indent=2))
