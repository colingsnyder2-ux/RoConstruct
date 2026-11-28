"""Check original string tails survive data reconstruction while pointers are cleared."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
import make_stubs

for address in (0x815b78, 0x816c40, 0x81c908, 0x824558, 0x824568, 0x828ef8, 0x92c1f8, 0x9487e8):
    make_stubs.orig_bytes(address, 1)
    expected = make_stubs._string_bytes(address)
    assert expected and make_stubs.orig_bytes(address, len(expected)) == expected, hex(address)
assert make_stubs.orig_bytes(0x831588, 4) == b'\0' * 4
print('8 strings preserved; original function pointer cleared')
