"""Suggest native source/target checks from site symbols and class labels.

Suggestions are review-only: source recipes and matching bytes do not establish
function identity, link selection or runtime compatibility.
"""
import argparse
from collections import defaultdict
import json
from pathlib import Path
import re


ROOT = Path(__file__).resolve().parents[3]


def discover(data, namespace, prefix, inactive=None, include_analogs=False):
    sources = {p.stem.casefold(): p for p in (ROOT / 'rebuild/2008-06/native-classes').glob(prefix + '*.cpp')}
    jobs = defaultdict(list)
    pattern = re.compile(r'^\?[^@?$]+@([^@?$]+)@' + re.escape(namespace) + r'@@')
    for f in data['funcs']:
        address = f'{f[0]:08x}'
        if inactive and inactive.get(address, [None, False])[1]:
            continue
        recipe = f[5] if len(f) > 5 else None
        if f[1] < 64 or f[2] != 100 or not recipe or len(recipe) < 3 or not recipe[2]:
            continue
        symbol = recipe[2]
        match = pattern.match(symbol)
        if not match:
            continue
        cls = match.group(1)
        source = sources.get((prefix + cls).casefold())
        label_agrees = namespace + '::' + cls in data['units'][f[3]]
        if not source or (not label_agrees and not include_analogs):
            continue
        jobs[str(source)].append({'addr': address, 'symbol': symbol, 'review_only': True})
    return {'jobs': [{'source': source, 'checks': checks} for source, checks in sorted(jobs.items())]}


def discover_c(data, recipe_prefix, symbol_prefix, source_prefix, inactive=None):
    sources = {p.stem.casefold(): p for p in (ROOT / 'rebuild/2008-06/native-classes').glob(source_prefix + '*.cpp')}
    jobs = defaultdict(list)
    for f in data['funcs']:
        address = f'{f[0]:08x}'
        recipe = f[5] if len(f) > 5 else None
        if (inactive and inactive.get(address, [None, False])[1]) or f[2] != 100 or not recipe or len(recipe) < 3:
            continue
        if not recipe[0].startswith(recipe_prefix) or not recipe[2] or not recipe[2].startswith(symbol_prefix):
            continue
        stem = Path(recipe[1].replace('\\', '/')).stem
        source = sources.get((source_prefix + stem).casefold())
        if source:
            jobs[str(source)].append({'addr': address, 'symbol': recipe[2], 'review_only': True})
    return {'jobs': [{'source': source, 'checks': checks} for source, checks in sorted(jobs.items())]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--namespace', default='G3D')
    parser.add_argument('--prefix', default='G3D')
    parser.add_argument('--index', type=Path, help='current inactive index to exclude already exact entries')
    parser.add_argument('--include-analogs', action='store_true', help='include recipe symbols even when class labels disagree')
    parser.add_argument('--c-recipe', help='C library recipe prefix, e.g. libpng-1.2.5')
    parser.add_argument('--c-symbol-prefix', default='_png_')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    inactive = json.loads(args.index.read_text()) if args.index else None
    data = json.loads((ROOT / 'docs/data/2008-06.json').read_text(encoding='utf-8'))
    result = (discover_c(data, args.c_recipe, args.c_symbol_prefix, args.prefix, inactive) if args.c_recipe else
              discover(data, args.namespace, args.prefix, inactive, args.include_analogs))
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'sources': len(result['jobs']),
                      'candidates': sum(len(x['checks']) for x in result['jobs']),
                      'plan': str(args.output), 'status': 'review-only'}))


if __name__ == '__main__':
    main()
