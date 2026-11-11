"""Run bounded, scratch-only header alternatives through native byte/reference proof.

Recipe supplies evidence-backed literal replacements and the complete set of sources to
check. Results are drafts: all actual header dependents must be checked before promotion.
"""
import argparse
import hashlib
import itertools
import json
from pathlib import Path
import sys
import subprocess
import time
import uuid

from native_repair_tools import ROOT, HERE, bounded


def apply_variant(original, replacements):
    result = original
    for row in replacements:
        old, new = row['old'], row['new']
        if not old or result.count(old) != 1:
            raise ValueError('each replacement must match exactly once')
        result = result.replace(old, new, 1)
    return result


def expand_variants(recipe, original):
    """Compose explicitly supplied, evidence-backed edits; never invent mutations."""
    variants = list(recipe.get('variants', []))
    groups = recipe.get('groups', [])
    if groups:
        choices = []
        count = 1
        for group in groups:
            options = group['choices']
            if not options:
                raise ValueError('each group needs choices')
            count *= len(options)
            if count > 13:
                raise ValueError('at most 12 non-baseline combinations')
            choices.append([(group['name'] + '=' + choice['name'], choice['replacements'])
                            for choice in options])
        for combination in itertools.product(*choices):
            replacements = [item for _, edits in combination for item in edits]
            if replacements:
                variants.append({'name': ','.join(name for name, _ in combination),
                                 'replacements': replacements})
    if not 1 <= len(variants) <= 12:
        raise ValueError('specify 1..12 variants or combinations')
    generated = [('baseline', original)]
    names = {'baseline'}
    bodies = {original}
    for variant in variants:
        name = variant['name']
        body = apply_variant(original, variant['replacements'])
        if name in names:
            raise ValueError('variant names must be unique')
        names.add(name)
        if body not in bodies:
            generated.append((name, body))
            bodies.add(body)
    return generated


def input_changes(before, after, scratch_dir):
    def shared(inputs):
        return {k: v for k, v in inputs.items()
                if not Path(k).resolve().is_relative_to(scratch_dir.resolve())}
    left, right = shared(before), shared(after)
    return {'changed': sorted(k for k in left.keys() & right.keys() if left[k] != right[k]),
            'added': sorted(right.keys() - left.keys()),
            'deleted': sorted(left.keys() - right.keys())}


def exact_addresses(manifest):
    families = manifest['families']
    if any(f.get('blockers') or any(not j.get('object') for j in f.get('jobs', []))
           for f in families):
        raise ValueError('proof has family blockers or missing compiled object')
    return {r['addr'] for f in families for r in f['symbols']
            if r.get('status') == 'inactive_exact' and r.get('addr')}


def run(recipe, seconds=600, rounds=3):
    if not 1 <= seconds <= 1500 or not 1 <= rounds <= 4:
        raise ValueError('seconds must be 1..1500 and rounds 1..4')
    sources = [ROOT / p for p in recipe['sources']]
    if not sources:
        raise ValueError('specify at least one source')
    header = ROOT / recipe['header']
    include = recipe['include']
    old = '#include "' + include + '"'
    header_text = header.read_text(encoding='utf-8-sig')
    source_text = [p.read_text(encoding='utf-8-sig') for p in sources]
    if any(s.count(old) != 1 for s in source_text):
        raise ValueError('each source must directly include header exactly once')
    # Validate every edit before starting any compilation.
    generated = expand_variants(recipe, header_text)
    run_id = uuid.uuid4().hex[:12]
    out = HERE / 'header-variant-runs' / run_id
    out.mkdir(parents=True)
    deadline = time.monotonic() + seconds
    inputs = {str(p): hashlib.sha256(p.read_bytes()).hexdigest() for p in [header] + sources}
    reports = []
    baseline = None
    baseline_inputs = None
    for index, (name, header_body) in enumerate(generated):
        overlay = out / ('variant_%02d.h' % index)
        overlay.write_text(header_body, encoding='utf-8')
        scratch = []
        for i, (path, text) in enumerate(zip(sources, source_text)):
            # Include lookup in the original source/header directories remains available.
            flags = '/I"%s" /I"%s"' % (path.parent.as_posix(), header.parent.as_posix())
            lines = text.splitlines(keepends=True)
            for j, line in enumerate(lines):
                if line.startswith('// native-flags:'):
                    lines[j] = line.rstrip('\r\n') + ' ' + flags + '\n'
                    break
            else:
                lines.insert(0, '// native-flags: ' + flags + '\n')
            text = ''.join(lines).replace(old, '#include "' + overlay.as_posix() + '"')
            dest = out / ('headertrial_%s_%02d_%02d.cpp' % (run_id, index, i))
            dest.write_text(text, encoding='utf-8')
            scratch.append(dest)
        current = {}
        manifests = {}
        proof_inputs = {}
        failure = None
        for original, trial in zip(sources, scratch):
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                failure = {'name': name, 'status': 'deadline'}
                break
            try:
                done = bounded([sys.executable, HERE / 'prove.py', trial, '--no-register',
                                '--rounds', str(rounds), '--quiet'], remaining)
            except subprocess.TimeoutExpired:
                failure = {'name': name, 'status': 'deadline'}
                break
            manifest_path = HERE / 'prove-out' / ('prove-' + trial.stem) / 'manifest.json'
            if done.returncode or not manifest_path.is_file():
                failure = {'name': name, 'status': 'proof_failed',
                           'output': (done.stdout + done.stderr)[-2000:]}
                break
            manifest = json.loads(manifest_path.read_text(encoding='utf-8'))
            try:
                current[str(original)] = exact_addresses(manifest)
            except (ValueError, KeyError) as error:
                failure = {'name': name, 'status': 'proof_failed', 'output': str(error)}
                break
            manifests[str(original)] = str(manifest_path)
            proof_inputs[str(original)] = manifest['families'][0].get('inputs', {})
        if failure:
            reports.append(failure)
            break
        if baseline is None:
            baseline = current
            baseline_inputs = proof_inputs
        changed_inputs = {src: input_changes(baseline_inputs[src], inputs, out)
                          for src, inputs in proof_inputs.items()}
        by_source = {src: {'gained': sorted(addresses - baseline[src]),
                           'lost': sorted(baseline[src] - addresses)}
                     for src, addresses in current.items()}
        reports.append({'name': name, 'status': 'proved', 'manifests': manifests,
                        'exact_count': sum(map(len, current.values())),
                        'by_source': by_source, 'shared_inputs_changed': changed_inputs,
                        'comparison_valid': not any(any(diff.values()) for diff in changed_inputs.values())})
    unchanged = all(Path(p).is_file() and hashlib.sha256(Path(p).read_bytes()).hexdigest() == digest
                    for p, digest in inputs.items())
    if not unchanged:
        for report in reports:
            report['comparison_valid'] = False
    result = {'input_hashes': inputs, 'inputs_unchanged': unchanged, 'results': reports,
              'scope': 'draft only; manually verify all header dependents and source plausibility'}
    receipt = out / 'receipt.json'
    receipt.write_text(json.dumps(result, indent=2), encoding='utf-8')
    return receipt, result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('recipe', type=Path)
    parser.add_argument('--seconds', type=int, default=600)
    parser.add_argument('--rounds', type=int, default=3)
    args = parser.parse_args()
    receipt, result = run(json.loads(args.recipe.read_text(encoding='utf-8-sig')), args.seconds, args.rounds)
    print(json.dumps({'receipt': str(receipt), **result}))


if __name__ == '__main__':
    main()
