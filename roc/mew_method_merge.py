"""Combine unambiguous C++ methods into a private, unverified candidate.

Install with: python -m pip install tree-sitter==0.26.0 tree-sitter-cpp==0.23.4
Compile and prove the resulting bytes before integration; syntax and unique
names do not establish ABI or ownership.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path

from tree_sitter import Language, Parser
import tree_sitter_cpp


def namespace(source, name):
    root = Parser(Language(tree_sitter_cpp.language())).parse(source).root_node
    if root.has_error:
        raise ValueError('C++ parser reported errors; inspect source manually')
    matches = [node for node in root.named_children if node.type == 'namespace_definition'
               and node.child_by_field_name('name') is not None
               and node.child_by_field_name('name').text.decode() == name]
    if len(matches) != 1:
        raise ValueError('Expected one top-level namespace: ' + name)
    return matches[0].child_by_field_name('body')


def methods(body, classname, include_conditional=False):
    result = []
    for node in body.named_children:
        if include_conditional and (node.type.startswith('preproc_') or node.type == 'template_declaration'):
            result.extend(methods(node, classname, include_conditional=True))
            continue
        # Donor methods inside conditional compilation or templates need separate review.
        if node.type != 'function_definition':
            continue
        decl = node.child_by_field_name('declarator')
        name = decl.child_by_field_name('declarator') if decl else None
        if not name or name.type != 'qualified_identifier':
            continue
        scope, member = name.child_by_field_name('scope'), name.child_by_field_name('name')
        if not scope or not member or scope.text.decode() != classname:
            continue
        result.append((member.text.decode(), node))
    return result


def has_preprocessor(node):
    return node.type.startswith('preproc_') or any(has_preprocessor(child) for child in node.named_children)


def combine(baseline, donor, namespace_name, classname):
    target = namespace(baseline, namespace_name)
    incoming = namespace(donor, namespace_name)
    existing, candidates = methods(target, classname, include_conditional=True), methods(incoming, classname)
    existing_names = {name for name, _ in existing}
    counts = Counter(name for name, _ in candidates)
    additions, skipped = [], []
    for name, node in candidates:
        if name in existing_names or counts[name] != 1:
            skipped.append({'method': name, 'reason': 'existing or overloaded'})
            continue
        if has_preprocessor(node):
            skipped.append({'method': name, 'reason': 'conditional or macro in method'})
            continue
        additions.append((name, donor[node.start_byte:node.end_byte]))
    insertion = target.end_byte - 1
    if baseline[insertion:insertion + 1] != b'}':
        raise ValueError('Namespace end is not a closing brace')
    payload = b''.join(b'\n\t' + body + b'\n' for _, body in additions)
    return baseline[:insertion] + payload + baseline[insertion:], [name for name, _ in additions], skipped


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', type=Path, required=True)
    parser.add_argument('--donor', type=Path, required=True)
    parser.add_argument('--namespace', required=True)
    parser.add_argument('--class', dest='classname', required=True)
    parser.add_argument('--output', type=Path, required=True, help='new private output folder')
    args = parser.parse_args()
    baseline, donor = args.baseline.read_bytes(), args.donor.read_bytes()
    candidate, added, skipped = combine(baseline, donor, args.namespace, args.classname)
    args.output.mkdir(parents=True, exist_ok=False)
    (args.output / args.baseline.name).write_bytes(candidate)
    report = {'baseline': str(args.baseline.resolve()), 'baseline_sha256': hashlib.sha256(baseline).hexdigest(),
              'donor': str(args.donor.resolve()), 'donor_sha256': hashlib.sha256(donor).hexdigest(),
              'candidate_sha256': hashlib.sha256(candidate).hexdigest(), 'added': added, 'skipped': skipped,
              'status': 'unverified candidate; no compilation, ABI or integration proof'}
    (args.output / 'report.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
