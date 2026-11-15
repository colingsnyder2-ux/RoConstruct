import importlib.util
import json
from pathlib import Path


path = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests/native_verified_identities.py'
spec = importlib.util.spec_from_file_location('native_verified_identities', path)
registry = importlib.util.module_from_spec(spec)
spec.loader.exec_module(registry)


def example(tmp_path):
    image = tmp_path / 'game.exe'
    image.write_bytes(b'original')
    source = tmp_path / 'native.cpp'
    source.write_bytes(b'source')
    receipt = tmp_path / 'proof.json'
    row = {'address': '00500000', 'symbol': '?method', 'exact': True,
           'metrics': {'unmasked_differences': 0, 'length_delta': 0},
           'verified_calls': [], 'verified_references': []}
    receipt.write_text(json.dumps({'source_path': str(source), 'source_sha256': registry.digest(source),
                                   'checks': [row]}))
    entry = {'address': '00500000', 'symbol': '?method', 'evidence': 'reviewed owner',
             'original_sha256': registry.digest(image), 'receipt': 'proof.json',
             'receipt_sha256': registry.digest(receipt)}
    manifest = tmp_path / 'registry.json'
    manifest.write_text(json.dumps({'identities': [entry]}))
    return image, source, receipt, manifest, entry, row


def test_accepts_only_reviewed_fresh_exact_receipts(tmp_path):
    image, source, receipt, manifest, entry, row = example(tmp_path)
    assert registry.load(manifest, tmp_path, image) == ({'?method': ['00500000']}, [])
    source.write_bytes(b'changed')
    assert not registry.load(manifest, tmp_path, image)[0]
    source.write_bytes(b'source')
    image.write_bytes(b'changed')
    assert not registry.load(manifest, tmp_path, image)[0]


def test_rejects_missing_evidence_or_unverified_reference(tmp_path):
    image, source, receipt, manifest, entry, row = example(tmp_path)
    entry['evidence'] = ''
    manifest.write_text(json.dumps({'identities': [entry]}))
    assert not registry.load(manifest, tmp_path, image)[0]
    entry['evidence'] = 'reviewed'
    data = json.loads(receipt.read_text())
    data['checks'][0]['verified_references'] = [{'status': 'unresolved_reference'}]
    receipt.write_text(json.dumps(data))
    entry['receipt_sha256'] = registry.digest(receipt)
    manifest.write_text(json.dumps({'identities': [entry]}))
    assert not registry.load(manifest, tmp_path, image)[0]


def test_rejects_mismatched_symbol_and_receipt_tampering(tmp_path):
    image, source, receipt, manifest, entry, row = example(tmp_path)
    entry['symbol'] = '?other'
    manifest.write_text(json.dumps({'identities': [entry]}))
    assert not registry.load(manifest, tmp_path, image)[0]
    entry['symbol'] = '?method'
    manifest.write_text(json.dumps({'identities': [entry]}))
    receipt.write_text(receipt.read_text() + ' ')
    assert not registry.load(manifest, tmp_path, image)[0]
