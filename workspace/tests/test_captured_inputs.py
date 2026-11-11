import hashlib
import importlib.util
import json
from pathlib import Path

import pytest

SCRIPT = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/p6/captured_inputs.py'
spec = importlib.util.spec_from_file_location('captured_inputs_test', SCRIPT)
captured = importlib.util.module_from_spec(spec)
spec.loader.exec_module(captured)


def test_freeze_recovers_recorded_inputs_without_reverting_worker(tmp_path):
    module = tmp_path / 'snapshot/App'
    overlay = module / 'overlay'
    saved = module / 'overlay-saved'
    for directory in (overlay, saved):
        (directory / 'App/util').mkdir(parents=True)
        (directory / 'App/include').mkdir(parents=True)
    source = overlay / 'App/util/Provider.cpp'
    header = overlay / 'App/include/Provider.h'
    source.write_bytes(b'worker source')
    header.write_bytes(b'worker header')
    (saved / 'App/util/Provider.cpp').write_bytes(b'recorded source')
    (saved / 'App/include/Provider.h').write_bytes(b'recorded header')
    command = module / 'command.json'
    command.write_text(json.dumps(dict(source=str(source), source_sha256=hashlib.sha256(b'recorded source').hexdigest(),
        dependencies={str(header): hashlib.sha256(b'recorded header').hexdigest()},
        args=['/c', '/I' + str(header.parent), '/FoProvider.obj', str(source)])))
    output = tmp_path / 'output'
    output.mkdir()
    result, flags, inputs, recovered = captured.freeze(command, module, module.parent, output)
    assert result.read_bytes() == b'recorded source'
    assert (output / 'captured/App/include/Provider.h').read_bytes() == b'recorded header'
    assert source.read_bytes() == b'worker source' and header.read_bytes() == b'worker header'
    assert len(recovered) == 2 and '/I' + str(output / 'captured/App/include') in flags


def test_freeze_rejects_changed_external_vendor_header(tmp_path):
    module = tmp_path / 'snapshot/App'
    source = module / 'overlay/App/util/Provider.cpp'
    source.parent.mkdir(parents=True)
    source.write_bytes(b'source')
    vendor = tmp_path / 'vendor.h'
    vendor.write_bytes(b'changed')
    command = module / 'command.json'
    command.write_text(json.dumps(dict(source=str(source), source_sha256=hashlib.sha256(b'source').hexdigest(),
        dependencies={str(vendor): hashlib.sha256(b'original').hexdigest()}, args=['/c', str(source)])))
    output = tmp_path / 'output'
    output.mkdir()
    with pytest.raises(RuntimeError, match='vendor header changed'):
        captured.freeze(command, module, module.parent, output)
    assert vendor.read_bytes() == b'changed'
