"""vtables of the 2008 exe from its RTTI: {class: [slot target addresses]} for primary vtables.

A vtable is the run of code pointers right after a pointer to an RTTICompleteObjectLocator (COL). The COL points at a
type descriptor whose name is '.?AVClass@NS@@'. Read-only on the exe.

Run: python work/native-client/layout/vtables.py   -> vtables.json
"""
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import file_strings  # noqa: E402


def scan():
    data = file_strings.EXE.read_bytes()
    secs = file_strings.sections(data)[1]
    text = next(s for s in secs if s[0] == '.text')

    def read(va, n):
        for _name, base, vsize, raw, rsize in secs:
            if base <= va and va + n <= base + min(vsize, rsize):
                return data[raw + va - base:raw + va - base + n]
        return None

    def is_code(va):
        return text[1] <= va < text[1] + text[2]

    out, seen = {}, set()
    for name, base, vsize, raw, rsize in secs:
        if name != '.rdata':
            continue
        blob = data[raw:raw + min(vsize, rsize)]
        for off in range(0, len(blob) - 8, 4):
            col = struct.unpack_from('<I', blob, off)[0]
            head = read(col, 20) if base <= col < base + vsize else None
            if not head:
                continue
            sig, vf_off, _cd, p_type, _hier = struct.unpack('<5I', head)
            if sig != 0 or vf_off != 0:                       # primary vtables only
                continue
            td = read(p_type + 8, 64)
            if not td or not td.startswith(b'.?A'):
                continue
            cls = td.split(b'\0', 1)[0].decode('latin-1')
            slots, at = [], base + off + 4
            while True:
                v = read(at, 4)
                if not v:
                    break
                target = struct.unpack('<I', v)[0]
                if not is_code(target):
                    break
                slots.append('%08x' % target)
                at += 4
            if slots and (cls, slots[0]) not in seen:
                seen.add((cls, slots[0]))
                out.setdefault(cls, slots)
    return out


if __name__ == '__main__':
    result = scan()
    (HERE / 'vtables.json').write_text(json.dumps(result, separators=(',', ':')), encoding='utf-8')
    print(len(result), 'classes with a primary vtable;', sum(len(v) for v in result.values()), 'slots')
