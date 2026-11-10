"""Add the definitive tool-verb region coverage to the tool-verb provider receipt."""
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = next((p for p in HERE.parents if (p / 'roconstruct-package.json').is_file()), HERE.parents[4])
RECEIPT = ROOT / 'work/2008-06/shared-layouts/tool-verb-providers-unit-20261106.json'
RUNS = [
    ROOT / 'work/2008-06/native-check-runs/20261106-130924-bdcb0da1',
    ROOT / 'work/2008-06/native-check-runs/20261106-131901-e7302b1a',
    ROOT / 'work/2008-06/native-check-runs/20261106-133422-5982050a',
]
LO, HI = 0x5c6000, 0x5c8000


def main():
    receipt = json.loads(RECEIPT.read_text(encoding='utf-8'))
    functions = [json.loads(l) for l in (ROOT / 'work/2008-06/functions.jsonl').read_text(encoding='utf-8').splitlines()]
    region = [f for f in functions if LO <= int(f['addr'], 16) < HI and f.get('kind', 'code') == 'code']
    matched = {}
    for run in sorted((ROOT / 'work/2008-06/native-check-runs').glob('2026*')):
        for f in list(run.glob('results.json')) + list(run.glob('analysis-*.json')):
            try:
                data = json.loads(f.read_text(encoding='utf-8'))
            except Exception:
                continue
            if not isinstance(data, list):
                continue
            for r in data:
                source = Path(r.get('source', '?')).name
                for cov in r.get('coverage', []):
                    for hit in cov['hits']:
                        matched.setdefault(hit['addr'], set()).add(source)
    proven_elsewhere = {
        '005c6010': 'leaf-selection-verbs-unit-20261106.json (AnchorVerb ctor, byte-exact)',
        '005c7ea0': 'standard-verbs-iat-abi-unit-20261106.json (StandardVerbs ctor, byte-exact)',
    }
    unmatched = [f for f in region if f['addr'] not in matched and f['addr'] not in proven_elsewhere]
    receipt['tool_verb_region_coverage'] = {
        'range': '005c6000-005c8000',
        'functions_in_range': len(region),
        'matched_by_at_least_one_verified_source': len(matched),
        'proven_in_other_units': proven_elsewhere,
        'unmatched': [{'addr': f['addr'], 'size': f['size'], 'unit': f.get('unit', '')} for f in unmatched],
        'unmatched_count': len(unmatched),
        'sources_contributing': sorted(set().union(*matched.values())) if matched else [],
        'scope': ('Masked-byte analog coverage from the runner range feature plus the checks proven in this '
                  'session and its sibling units. It identifies the remaining functions; it is not identity '
                  'proof for the listed addresses.'),
    }
    duplicate_factory_sources = {}
    for run in RUNS:
        results = json.loads((run / 'results.json').read_text(encoding='utf-8'))
        for r in results:
            source = Path(r['source']).name
            for cov in r.get('coverage', []):
                for hit in cov['hits']:
                    for sym in hit['symbols']:
                        if 'newMouseCommand' in sym or sym.startswith('??1') or 'getName' in sym:
                            duplicate_factory_sources.setdefault(sym, set()).add(source)
    receipt['duplicate_factory_sources'] = {
        'symbols_with_multiple_defining_sources': {
            k: sorted(v) for k, v in duplicate_factory_sources.items() if len(v) > 1},
        'note': ('The same tool-verb factory, getName and tool destructor bodies are produced by several '
                 'translation units (ToolVerbFactories.cpp, ToolVerbFactoriesBasic.cpp and the per-tool '
                 '*Factory.cpp files). Only one owner per symbol may be selected into a link.'),
    }
    RECEIPT.write_text(json.dumps(receipt, indent=1, sort_keys=True), encoding='utf-8')
    import hashlib
    print(json.dumps({'receipt': str(RECEIPT.relative_to(ROOT)),
                      'sha256': hashlib.sha256(RECEIPT.read_bytes()).hexdigest(),
                      'functions': len(region), 'matched': len(matched),
                      'unmatched': len(unmatched),
                      'duplicate_symbols': len(receipt['duplicate_factory_sources']
                                               ['symbols_with_multiple_defining_sources'])}, indent=1))


if __name__ == '__main__':
    main()
