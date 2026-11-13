"""Prove strong donor-name candidates through real-header COFF identities.

Donor strings choose only a candidate owner.  This runner extracts its local
source analog into a real-header probe, obtains a unique object/body identity,
then reruns native-bulk with that identity.  It never edits native source.
"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
ROC_LIB = re.compile(r'^// roc-lib: (\S+) (.+)$', re.M)
ROC_FLAGS = re.compile(r'^// roc-flags: (.*)$', re.M)
INCLUDE = re.compile(r'^\s*#\s*include\s*[<"]([^">/\\]+)[">]', re.M)
INCLUDE_INDEX_PATH = ROOT / 'work/native-client/vendor-include-index.json'
INCLUDE_INDEX = None


def run(args):
    subprocess.run([sys.executable, *map(str, args)], cwd=ROOT, check=True)


def namespace(header, owner):
    if '::' in owner:
        return owner.rsplit('::', 1)[0]
    from native_convert_plan import owner_namespace
    return owner_namespace(header.read_text(errors='replace'), owner)


def packet_profile(address, fallback_flags):
    """Target packet supplies compile profile and recipe-owned include roots."""
    packet = ROOT / 'src/2008-06' / (address + '.cpp')
    text = packet.read_text(errors='replace') if packet.is_file() else ''
    flags = ROC_FLAGS.search(text)
    include_dirs = []
    match = ROC_LIB.search(text)
    if match:
        from roc import libs
        spec = libs.RECIPES.get(match.group(1), {})
        for value in spec.get('include', []):
            if value != 'WINSDK':
                include_dirs.append((libs.LIBS / value).resolve())
        defines = spec.get('defines', '')
        include_flags = ' '.join('/D' + value for value in defines.split()
                                 if re.fullmatch(r'[A-Za-z_]\w*(?:=.*)?', value))
        if include_flags:
            fallback_flags = (fallback_flags + ' ' + include_flags).strip()
    return (flags.group(1) if flags else fallback_flags), include_dirs


def header_vendor_include_dirs(header, seen=None):
    """Add documented or uniquely located direct vendor includes from headers."""
    global INCLUDE_INDEX
    header = Path(header).resolve()
    seen = set() if seen is None else seen
    if header in seen:
        return []
    seen.add(header)
    if INCLUDE_INDEX is None:
        try:
            INCLUDE_INDEX = json.loads(INCLUDE_INDEX_PATH.read_text())
        except (OSError, json.JSONDecodeError):
            index = {}
            output = subprocess.run(['rg', '--files', str(ROOT / 'tools')],
                                    capture_output=True, text=True, check=False).stdout.splitlines()
            for value in output:
                path = Path(value)
                index.setdefault(path.name.lower(), []).append(str(path.parent.resolve()))
            INCLUDE_INDEX = index
            INCLUDE_INDEX_PATH.write_text(json.dumps(INCLUDE_INDEX, indent=1) + '\n')
    text = header.read_text(errors='replace')
    dirs = []
    # Ogre headers exist at multiple vendor versions.  A native header that
    # explicitly records its target ABI can select that exact installed tree;
    # basename lookup below intentionally refuses the ambiguous case.
    ogre = re.search(r'\bOgre\s+1\.4\.5\b', text)
    if ogre:
        path = ROOT / 'tools/libs/ogre-1.4.5/ogrenew/OgreMain/include'
        if path.is_dir():
            dirs.append(path.resolve())
    # A native header may pin a specific vendor ABI in its evidence comment.
    # Accept only an existing repository path written there, never a guessed
    # version selected from basename collisions.
    for value in re.findall(r'\btools/[A-Za-z0-9._/-]+/include\b', text):
        path = ROOT / value
        if path.is_dir():
            dirs.append(path.resolve())
    names = INCLUDE.findall(text)
    for name in names:
        matches = sorted(set(INCLUDE_INDEX.get(name.lower(), [])))
        if len(matches) == 1:
            dirs.append(Path(matches[0]))
    # A selected native header may include another selected native header.  Its
    # documented vendor ABI is equally part of this real declaration provider.
    native_root = ROOT / 'rebuild/2008-06/native-headers'
    for relative in re.findall(r'^\s*#\s*include\s*"([^"\\]+)"', text, re.M):
        nested = (native_root / relative).resolve()
        if nested.is_file():
            dirs.extend(header_vendor_include_dirs(nested, seen))
    return list(dict.fromkeys(dirs))


def bulk(config_path, data, output):
    config_path.write_text(json.dumps(data, indent=1))
    subprocess.run([str(ROOT / 'roc.cmd'), 'native-bulk', str(config_path), '--out', str(output)], cwd=ROOT, check=True)
    return json.loads((output / 'manifest.json').read_text())


def object_path(manifest):
    jobs = [job for family in manifest.get('families', []) for job in family.get('jobs', [])]
    if len(jobs) != 1 or not jobs[0].get('object'):
        return None
    return Path(jobs[0]['object'])


def probe_candidates(data):
    """Accept current strict donor queue plus legacy hand-curated queue."""
    if 'candidates' in data:
        return data['candidates']
    candidates = []
    for row in data.get('rows', []):
        if row.get('status') != 'candidate-probe':
            continue
        headers, sources = row.get('headers', []), row.get('source_files', [])
        if len(headers) != 1 or len(sources) != 1:
            continue
        candidates.append({'address': row['addr'], 'candidate': row['candidate'],
                           'source': sources[0], 'header': headers[0]})
    return candidates


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--candidates', type=Path, required=True)
    ap.add_argument('--base-closure', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--limit', type=int, default=2)
    ap.add_argument('--short-unique', action='store_true',
                    help='also admit 6-15 byte seeds only when one real VS2008 object has one exact target')
    args = ap.parse_args()
    candidates = probe_candidates(json.loads(args.candidates.read_text()))[:args.limit]
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    results = []
    for number, row in enumerate(candidates):
        address, candidate = row['address'], row['candidate']
        owner, method = candidate.rsplit('::', 1)
        source, header = ROOT / row['source'], ROOT / row['header']
        unit = out / ('%03d-%s' % (number, address))
        unit.mkdir(parents=True, exist_ok=True)
        probe = unit / 'probe.cpp'
        if source.name.startswith('roc_'):
            results.append({'address': address, 'candidate': candidate,
                            'source': row['source'], 'header': row['header'],
                            'status': 'generated_source_rejected'})
            continue
        header_rel = header.relative_to(ROOT / 'rebuild/2008-06/native-headers').as_posix()
        source_text = source.read_text(errors='replace')
        flags = re.search(r'^// roc-flags: (.*)$', source_text, re.M)
        flags = flags.group(1) if flags else '/O2 /Ob2 /Oy /GF /GS- /EHsc /MD'
        flags, recipe_includes = packet_profile(address, flags)
        header_includes = header_vendor_include_dirs(header)
        source_marker = owner + '::' + method
        short_marker = owner.rsplit('::', 1)[-1] + '::' + method
        if source_marker not in source_text:
            source_marker = short_marker
        try:
            command = [ROOT / 'work/native-client/native_transplant_probe.py', '--packet', source,
                       '--record', address + '=' + source_marker,
                       '--namespace=' + namespace(header, owner), '--include', header_rel,
                       '--include-dir', source.parent, '--flags=' + flags,
                       '--support-globals', '--source-includes', '--output', probe]
            for include_dir in [*recipe_includes, *header_includes]:
                command += ['--include-dir', include_dir]
            run(command)
        except subprocess.CalledProcessError:
            results.append({'address': address, 'candidate': candidate, 'source': row['source'],
                            'header': row['header'], 'status': 'extract_failed'})
            continue
        seed_config = {'client': '2008-06', 'targets': [address],
                       'families': [{'name': 'donor-seed', 'sources': [str(probe.relative_to(ROOT)).replace('\\', '/')]}]}
        seed_manifest = bulk(unit / 'seed.json', seed_config, unit / 'seed-bulk')
        obj = object_path(seed_manifest)
        result = {'address': address, 'candidate': candidate, 'source': row['source'], 'header': row['header']}
        if not obj or not obj.is_file():
            result['status'] = 'compile_failed'
            results.append(result)
            continue
        candidate_closure = unit / 'candidate-closure.json'
        closure_command = [ROOT / 'work/native-client/native_identity_closure.py', '--objects', obj.parent,
                           '--output', candidate_closure]
        if args.short_unique:
            # Diagnostic identity only.  Final native-bulk still requires byte,
            # relocation, reference and destination proof before any promotion.
            closure_command += ['--min-seed', '6']
        run(closure_command)
        merged = unit / 'merged-closure.json'
        run([ROOT / 'work/native-client/native_identity_merge.py', '--base', args.base_closure,
             '--candidate', candidate_closure, '--output', merged])
        bindings = {item['addr']: item for item in json.loads(merged.read_text())['bindings']}
        if address.lower() not in bindings:
            result['status'] = 'no_unique_body_identity'
            results.append(result)
            continue
        evidence = unit / 'identity.json'
        run([ROOT / 'work/native-client/native_identity_evidence.py', '--closure', merged,
             '--addr', address, '--output', evidence])
        proof_config = {'client': '2008-06', 'targets': [address],
                        'families': [{'name': 'donor-proof', 'sources': [str(probe.relative_to(ROOT)).replace('\\', '/')],
                                      'evidence': [str(evidence.relative_to(ROOT)).replace('\\', '/')]}]}
        proof_manifest = bulk(unit / 'proof.json', proof_config, unit / 'proof-bulk')
        symbols = [symbol for family in proof_manifest['families'] for symbol in family['symbols']
                   if symbol.get('addr') == address.lower()]
        result.update(symbol=bindings[address.lower()]['symbol'],
                      status='inactive_exact' if any(symbol.get('status') == 'inactive_exact' for symbol in symbols) else 'draft',
                      manifest=str((unit / 'proof-bulk' / 'manifest.json').relative_to(ROOT)).replace('\\', '/'))
        results.append(result)
    report = {'scope': 'donor candidate compile + unique-body identity + byte proof; no native source promotion',
              'base_closure': str(args.base_closure), 'short_unique': args.short_unique, 'results': results,
              'summary': {'requested': len(candidates),
                          'inactive_exact': sum(row['status'] == 'inactive_exact' for row in results),
                          'blocked': sum(row['status'] != 'inactive_exact' for row in results)}}
    (out / 'result.json').write_text(json.dumps(report, indent=1) + '\n')
    print(json.dumps(report['summary']))


if __name__ == '__main__':
    main()
