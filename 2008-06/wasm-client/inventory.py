"""Inventory RobloxQT source receipts; this does not establish linked selection."""
import hashlib
import json
from pathlib import Path


def collect(root):
    route = root / 'work/donorfree-route'
    receipt_paths = (route / 'linkexp/qt_results.txt').read_text().splitlines()
    sources, missing = {}, []
    for name in dict.fromkeys(line.strip() for line in receipt_paths if line.strip()):
        path = Path(name)
        if not path.is_file():
            missing.append(name)
            continue
        data = json.loads(path.read_text())
        for row in data if isinstance(data, list) else data['results']:
            if row.get('status') == 'complete' and row.get('source'):
                sources[row['source']] = name
    candidates = []
    for name, receipt in sorted(sources.items()):
        path = Path(name)
        candidates.append({'path': name, 'receipt': receipt,
                           'sha256': hashlib.sha256(path.read_bytes()).hexdigest() if path.is_file() else None})
    converted = json.loads((route / 'renamed/results.json').read_text())
    return {'source_candidates': candidates, 'missing_receipts': missing,
            'converted_object_entries': len(converted),
            'note': 'Receipt candidates are not proof of final linked providers or Wasm compatibility.'}


if __name__ == '__main__':
    root = Path(__file__).resolve().parents[3]
    output = root / 'work/wasm-client/qt-source-inventory.json'
    output.parent.mkdir(parents=True, exist_ok=True)
    result = collect(root)
    output.write_text(json.dumps(result, indent=2) + '\n')
    print(f"{len(result['source_candidates'])} source candidates; {result['converted_object_entries']} converted object entries; {len(result['missing_receipts'])} missing receipts")
    print(output)
