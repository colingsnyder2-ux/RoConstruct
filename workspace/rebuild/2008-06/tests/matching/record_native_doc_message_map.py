"""Inventory original CRobloxDoc MFC message-map entries."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

import pefile

root = Path(__file__).resolve().parents[4]
original = root / "work/2008-06/original-p4-reference/Roblox.exe"
pe = pefile.PE(str(original), fast_load=True)
base = pe.OPTIONAL_HEADER.ImageBase
read = lambda address, size: pe.get_data(address - base, size)
map_address = 0x817f0c
base_map, entry_address = struct.unpack("<II", read(map_address, 8))
assert entry_address == 0x817f18
assert read(0x455d20, 6) == b"\xb8" + struct.pack("<I", map_address) + b"\xc3"
entries = []
for index in range(256):
    values = struct.unpack("<6I", read(entry_address + index * 24, 24))
    if not any(values):
        break
    message, code, first, last, signature, handler = values
    assert message in (0x111, 0x4e) and handler
    entries.append(dict(index=index, message=hex(message), code=hex(code), first_id=hex(first),
                        last_id=hex(last), signature=hex(signature), handler=hex(handler)))
else:
    raise AssertionError("message map has no terminator")
assert len(entries) == 39
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = dict(revision=subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=root, text=True).strip(),
               original_sha256=sha(original), observer_sha256=sha(Path(__file__)),
               get_message_map="0x455d20", map_address=hex(map_address),
               base_map_getter=hex(base_map), entries_address=hex(entry_address), entries=entries,
               scope="Original data inventory only; handler names, bodies and linked relocations remain unverified.")
output = root / "work/2008-06" / sys.argv[1]
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(receipt, indent=2) + "\n")
print("PASS: original CRobloxDoc message map, %d entries" % len(entries))
