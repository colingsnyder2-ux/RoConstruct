import importlib.util
from pathlib import Path
import struct
import sys
from unittest.mock import patch


directory = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests'
sys.path.insert(0, str(directory))
spec = importlib.util.spec_from_file_location('batch_reference_test', directory / 'g3d_native_batch_review.py')
batch = importlib.util.module_from_spec(spec)
spec.loader.exec_module(batch)


def test_function_relocation_uses_zero_based_coff_section(tmp_path):
    obj = tmp_path / 'sample.obj'
    obj.write_bytes(struct.pack('<IIH', 1, 1, 20))
    section = (b'.text', 0, 0, 6, 0, 0, 0, 1, 0, 0)
    index = ([section], {1: ('?callee', 0, 0, 0)}, {'?caller': (0, 0)}, {})
    body = b'\xe8' + struct.pack('<i', 0x10 - 5) + b'\xc3'
    result = {'source': 'sample.cpp', 'object': str(obj), 'checks': [
        {'addr': '00500000', 'symbol': '?caller', 'status': 'exact'}]}
    with patch.object(batch.runner, 'import_evidence', return_value=({}, {}, {})), \
         patch.object(batch.runner.match, '_coff_data_index', return_value=index), \
         patch.object(batch.runner.match, 'target', return_value=(body, None, None)):
        manifest, unresolved = batch.prepare([result], {'?callee': ['00500010']})
    assert not unresolved
    assert manifest['jobs'][0]['checks'][0]['calls'][0]['target'] == '00500010'
