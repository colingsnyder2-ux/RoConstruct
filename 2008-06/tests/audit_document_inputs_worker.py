"""Read-only heuristic freshness audit; not a substitute for compiler dependencies."""
import ast
import hashlib
import json
import re
from pathlib import Path

root = Path(__file__).resolve().parents[3]
tests = root / 'rebuild/2008-06/tests'
receipt = json.loads((root / 'work/2008-06/shared-layouts/document-swap-provider-trial.json').read_text())
verifier = ast.parse((tests / 'verify_document_swap.py').read_text())
covered = set()
for node in ast.walk(verifier):
    if isinstance(node, ast.Constant) and isinstance(node.value, str) and node.value.startswith('record_native_') and node.value.endswith('.py'):
        covered.add(node.value)
scripts = {p.name: p.read_text(encoding='utf-8', errors='replace').lower() for p in tests.glob('record_native_*.py')}
script_literals = {}
for name, text in scripts.items():
    try:
        tree = ast.parse(text)
    except SyntaxError:
        continue
    script_literals[name] = {node.value for node in ast.walk(tree)
                             if isinstance(node, ast.Constant) and isinstance(node.value, str)}
sources = list(tests.glob('*.cpp')) + list(tests.glob('*.h'))
report = {'scope': 'Read-only name-based evidence. Missing coverage and timestamp warnings require dependency verification; no complete header graph is available.', 'objects': [], 'mismatched_hashes': [], 'missing': [], 'no_verifier_producer': [], 'newer_named_sources': []}
for rel, expected in receipt['objects'].items():
    path = root / rel
    if not path.exists():
        report['missing'].append(rel)
        continue
    actual = hashlib.sha256(path.read_bytes()).hexdigest()
    if actual != expected:
        report['mismatched_hashes'].append({'object': rel, 'expected': expected, 'actual': actual})
    producers = [name for name, text in scripts.items()
                 if name not in {'record_native_document_link_trial.py', 'record_native_resize_document_probe.py'}
                 and (path.name.lower() in text or path.stem.lower() in script_literals.get(name, set()))]
    matching = [str(p.relative_to(root)) for p in sources if p.stem.lower() == path.stem.lower() and p.stat().st_mtime_ns > path.stat().st_mtime_ns]
    item = {'object': rel, 'sha256': actual, 'named_recorders': producers, 'verifier_recorders': sorted(set(producers) & covered)}
    report['objects'].append(item)
    if not item['verifier_recorders']:
        report['no_verifier_producer'].append(item)
    if matching:
        report['newer_named_sources'].append({'object': rel, 'sources': matching})
print(json.dumps(report, indent=2))
