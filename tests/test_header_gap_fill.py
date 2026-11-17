import importlib.util
import json
from pathlib import Path
from unittest.mock import patch


def test_existing_destructor_is_not_proposed(tmp_path):
    spec = importlib.util.spec_from_file_location(
        'header_gap_fill', Path(__file__).resolve().parents[1] / 'work/native-client/header_gap_fill.py'
    )
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    header = tmp_path / 'KernelData.h'
    header.write_text('namespace RBX { class KernelData { public: ~KernelData(); }; }')
    queue = tmp_path / 'queue.json'
    symbol = '??1KernelData@RBX@@QAE@XZ'
    queue.write_text(json.dumps({'classes': [{'owner': 'RBX::KernelData', 'template': False, 'methods': [
        {'symbol': symbol, 'declaration': '~KernelData(void)', 'headers': []}
    ]}]}))
    with patch.object(module, 'HEADERS', tmp_path), patch.object(module.n, 'QUEUE', queue), \
            patch.object(module.n, 'DECL_FILES', [(header, header.read_text())]), \
            patch.object(module.n, 'declaring_header'), patch.object(module.n, 'remaining_set', return_value=set()), \
            patch.object(module.n, 'load_registry', return_value={}), patch.object(module, 'undname', return_value={
                symbol: 'public: __thiscall RBX::KernelData::~KernelData(void)'
            }):
        assert not module.plan()
