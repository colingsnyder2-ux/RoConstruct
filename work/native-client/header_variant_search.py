"""Run bounded, scratch-only header alternatives through native byte/reference proof.

Recipe supplies evidence-backed literal replacements and the complete set of sources to
check. Results are drafts: all actual header dependents must be checked before promotion.
"""
import argparse
import hashlib
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
    variants = recipe['variants']
    sources = [ROOT / p for p in recipe['sources']]
    if not sources or not 1 <= len(variants) <= 12:
        raise ValueError('specify sources and 1..12 variants')
    header = ROOT / recipe['header']
    include = recipe['include']
    old = '#include "' + include + '"'
    header_text = header.read_text(encoding='utf-8-sig')
    source_text = [p.read_text(encoding='utf-8-sig') for p in sources]
    if any(s.count(old) != 1 for s in source_text):
        raise ValueError('each source must directly include header exactly once')
    # Validate every edit before starting any compilation.
    generated = [('baseline', header_text)] + [
        (v['name'], apply_variant(header_text, v['replacements'])) for v in variants]
    if len({name for name, _ in generated}) != len(generated):
        raise ValueError('variant names must be unique')
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
            current[str(original)] = exact_addresses(manifest)
            manifests[str(original)] = str(manifest_path)
            proof_inputs[str(original)] = manifest['families'][0].get('inputs', {})
        if failure:
            reports.append(failure)
            break
        if baseline is None:
            baseline = current
            baseline_inputs = proof_inputs
        changed_inputs = {src: sorted(k for k in inputs.keys() & baseline_inputs[src].keys()
                                      if inputs[k] != baseline_inputs[src][k])
                          for src, inputs in proof_inputs.items()}
        by_source = {src: {'gained': sorted(addresses - baseline[src]),
                           'lost': sorted(baseline[src] - addresses)}
                     for src, addresses in current.items()}
        reports.append({'name': name, 'status': 'proved', 'manifests': manifests,
                        'exact_count': sum(map(len, current.values())),
                        'by_source': by_source, 'shared_inputs_changed': changed_inputs})
    unchanged = all(Path(p).is_file() and hashlib.sha256(Path(p).read_bytes()).hexdigest() == digest
                    for p, digest in inputs.items())
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
