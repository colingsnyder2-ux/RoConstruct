"""Which unresolved link symbols a compiled native source already defines.

Reads `link/probe.json` (unresolved list) and every native-source object the
template/profile tools compiled.  Per unresolved symbol:

  native-source-defines   a native-classes object defines it: add that source to the link
  closure-exact-elsewhere a non-native object has the exact body (library / donor tree)
  closure-named           original address known, no exact body yet
  unknown                 no identity evidence

Output: claude-link-unresolved-providers.json.  Selection evidence only.
"""
import argparse
import gzip
import hashlib
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parents[1]))
from roc import match  # noqa: E402


def provider_source(stem):
    native = HERE.parents[1] / 'rebuild/2008-06/native-classes' / (stem + '.cpp')
    local = HERE / (stem + '.cpp')
    return native if native.is_file() else local if local.is_file() else None

ap = argparse.ArgumentParser(description=__doc__)
ap.add_argument('--closure-from', type=Path, help='include introduced dependencies from a rejected family trial')
ap.add_argument('--output', type=Path, default=HERE / 'claude-link-unresolved-providers.json')
ap.add_argument('--cache', type=Path, default=HERE / 'link/provider-object-index-v1.json.gz',
                help='hash-checked object-definition index; provider leads only')
args = ap.parse_args()
unresolved = json.loads((HERE / 'link/probe.json').read_text())['unresolved']
if args.closure_from:
    trial = json.loads(args.closure_from.read_text())
    unresolved = sorted(set(unresolved) | set(trial.get('link_trial', {}).get('introduced', [])))
closure = {r['symbol']: r for r in json.loads((HERE / 'claude-identity-closure.json').read_text())['bindings']}
registry = json.loads((HERE.parents[1] / 'work/2008-06/identity-registry.json').read_text())
identities = {r['name']: addr for addr, r in registry.items() if not r.get('placeholder')}
defines = defaultdict(set)
parser_hash = hashlib.sha256(Path(match.__file__).read_bytes()).hexdigest()
try:
    with gzip.open(args.cache, 'rt', encoding='utf-8') as stream:
        cached = json.load(stream)
except (OSError, EOFError, ValueError):
    cached = {}
previous = cached.get('objects', {}) if cached.get('parser_sha256') == parser_hash else {}
updated, reused = {}, 0
needed = set(unresolved)
objects = (list(HERE.glob('claude-template-applied/*/after/candidate.obj')) +
           list(HERE.glob('claude-template-promote/*/baseline/candidate.obj')) +
           list(HERE.glob('claude-profile-applied/*/after/candidate.obj')) +
           list(HERE.glob('obj-engine-abi/*.obj')) + list(HERE.glob('obj/*.obj')))
for obj in objects:
    stem = obj.stem if obj.parent.name in ('obj-engine-abi', 'obj') else obj.parents[1].name
    if not provider_source(stem):
        continue
    key = obj.relative_to(HERE).as_posix()
    raw = obj.read_bytes()
    digest = hashlib.sha256(raw).hexdigest()
    entry = previous.get(key, {})
    if entry.get('sha256') == digest:
        definitions = entry['definitions']
        reused += 1
    else:
        try:
            _, _, definitions, _ = match._coff_data_index(raw)
            definitions = sorted(definitions)
        except (ValueError, IndexError, KeyError):
            definitions = []
    updated[key] = {'sha256': digest, 'definitions': definitions}
    for symbol in definitions:
        if symbol in needed:
            defines[symbol].add(stem)
args.cache.parent.mkdir(parents=True, exist_ok=True)
temporary = args.cache.with_suffix('.tmp')
with gzip.open(temporary, 'wt', encoding='utf-8') as stream:
    json.dump({'parser_sha256': parser_hash, 'objects': updated}, stream, separators=(',', ':'))
temporary.replace(args.cache)
rows, count = [], Counter()
for symbol in unresolved:
    providers = sorted(defines.get(symbol, ()))
    bound = closure.get(symbol)
    kind = ('native-source-defines' if providers else 'closure-exact-elsewhere' if bound and bound['body_exact']
            else 'closure-named' if bound or symbol in identities else 'unknown')
    count[kind] += 1
    rows.append({'symbol': symbol, 'kind': kind, 'providers': providers[:6],
                 'address': bound['addr'] if bound else identities.get(symbol)})
args.output.write_text(json.dumps(rows, indent=1) + '\n')
print(len(unresolved), dict(count), 'objects scanned', len(objects), 'indexes reused', reused)
for kind in ('native-source-defines', 'unknown'):
    print('--', kind)
    for r in [r for r in rows if r['kind'] == kind][:12]:
        print(r['address'], r['providers'][:2], r['symbol'][:90])
