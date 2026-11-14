import importlib.util
from pathlib import Path
import struct
import sys

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'work/native-client'))
spec = importlib.util.spec_from_file_location('native_link_select', ROOT / 'work/native-client/native_link_select.py')
selector = importlib.util.module_from_spec(spec)
spec.loader.exec_module(selector)


def coff_fixture(entries):
    start = 20 + 3 * 40
    data = b'AB' + b''.join(struct.pack('<I', entry) for entry in entries)
    symbols = b''.join(struct.pack('<8sIhHBB', name.ljust(8, b'\0'), 0, section, 0x20, 2, 0)
                       for name, section in [(b'_live', 1), (b'_dead', 2), (b'_other', 1)])
    header = struct.pack('<HHIIIHH', 0x14c, 3, 0, start + len(data), 3, 0, 0)
    sections = b''.join([
        struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, 1, start, 0, 0, 0, 0, 0x60000020),
        struct.pack('<8sIIIIIIHHI', b'.dead', 0, 0, 1, start + 1, 0, 0, 0, 0, 0x60000820),
        struct.pack('<8sIIIIIIHHI', b'.sxdata', 0, 0, len(entries) * 4, start + 2, 0, 0, 0, 0, 0x00300200),
    ])
    return header + sections + data + symbols + struct.pack('<I', 4)


def test_pruning_remaps_safe_handlers_and_drops_discarded_handlers():
    result = selector.prune_discarded_symbols(coff_fixture([0, 1, 2]))
    _, _, _, symptr, count, _, _ = struct.unpack_from('<HHIIIHH', result)
    sx = struct.unpack_from('<8sIIIIIIHHI', result, 20 + 2 * 40)
    assert count == 2
    assert sx[3] == 8
    assert struct.unpack_from('<II', result, sx[4]) == (0, 1)
    assert symptr > sx[4] + sx[3]


def test_invalid_safe_handler_index_is_rejected():
    with pytest.raises(ValueError, match='SafeSEH'):
        selector.prune_discarded_symbols(coff_fixture([7]))


def test_empty_safe_handler_section_is_discarded():
    result = selector.prune_discarded_symbols(coff_fixture([1]))
    sx = struct.unpack_from('<8sIIIIIIHHI', result, 20 + 2 * 40)
    assert sx[3] == 0
    assert sx[9] & 0x800
    assert sx[0].rstrip(b'\0') != b'.sxdata'
