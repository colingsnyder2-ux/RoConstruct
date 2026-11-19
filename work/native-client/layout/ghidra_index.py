"""Feature index of the Ghidra pseudo-C exports (iOS Dec 2013, Android Jun 2014): one record per function with its
qualified name, string literals and the qualified functions it calls. Used to name unnamed 2008 functions by
similarity (name_match.py). Reads the exports in place, writes only ghidra-index.json (ignored by git).

Run: python work/native-client/layout/ghidra_index.py
"""
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
EXPORTS = {'ios': Path('C:/Users/colin/OneDrive/Desktop/2013-2014-ghidra/ios-2013-12_2.132.41333'),
           'android': Path('C:/Users/colin/OneDrive/Desktop/2013-2014-ghidra/android-2014-06_2.155.47886')}
OUT = HERE / 'ghidra-index.json'
SIGNATURE = re.compile(r'/\*\s*(.+?)\s*\*/')
STRING = re.compile(r'"((?:[^"\\\n]|\\.){4,80})"')
FLOAT = re.compile(r'(?<![\w.])-?\d+\.\d{4,9}(?:e[-+]?\d+)?f?(?![\w.])')
CALL = re.compile(r'\b((?:[A-Za-z_]\w*(?:<[^<>;]*>)?::)+~?[A-Za-z_]\w*)\s*\(')


PCREL = re.compile(r'DAT_([0-9a-f]{8})\s*\+\s*(0x[0-9a-f]+)')


class Elf:
    """Strings of a 32-bit ARM .so. Ghidra shows a PC-relative string as DAT_<literal pool slot> + <constant>:
    the slot holds an offset, and offset + constant is the string's address."""

    def __init__(self, path):
        import struct
        self.data = Path(path).read_bytes()
        phoff, = struct.unpack_from('<I', self.data, 0x1c)
        size, num = struct.unpack_from('<HH', self.data, 0x2a)
        self.loads = []
        for i in range(num):
            kind, off, va, _pa, filesz, _memsz = struct.unpack_from('<6I', self.data, phoff + i * size)
            if kind == 1:
                self.loads.append((va, filesz, off))

    def read(self, va, n):
        for base, size, off in self.loads:
            if base <= va and va + n <= base + size:
                return self.data[off + va - base:off + va - base + n]
        return None

    def string(self, slot, const):
        import struct
        raw = self.read(slot, 4)
        if not raw:
            return None
        va = (struct.unpack('<I', raw)[0] + const) & 0xFFFFFFFF
        blob = self.read(va, 96) or self.read(va, 16)
        if not blob:
            return None
        start = va                                    # the constant lands inside the string: walk back to its start
        while start > va - 64 and self.read(start - 1, 1) not in (None, b'\x00'):
            start -= 1
        blob = self.read(start, 96) or blob
        text = blob.split(b'\x00', 1)[0]
        if 4 <= len(text) <= 80 and all(32 <= b < 127 for b in text):
            return text.decode('ascii')
        return None


ELF = None


def head(signature):
    """Qualified name before the parameter list, templates kept whole: 'RBX::A::f(int)' -> 'RBX::A::f'."""
    depth = 0
    for i, ch in enumerate(signature):
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth -= 1
        elif ch == '(' and depth == 0:
            return signature[:i].strip()
    return signature.strip()


def parse(path):
    try:
        text = path.read_text(encoding='utf-8', errors='replace')
    except OSError:
        return None
    sig = SIGNATURE.search(text, 0, 600)
    if not sig:
        return None
    name = head(sig.group(1))
    if '::' not in name:
        return None
    body = text[sig.end():]
    found = {s for s in STRING.findall(body) if not s.startswith(('%', '/'))}
    if ELF is not None:
        for slot, const in PCREL.findall(body):
            text = ELF.string(int(slot, 16), int(const, 16))
            if text and not text.startswith(('%', '/')):
                found.add(text)
    strings = sorted(found)[:12]
    calls = sorted({c for c in CALL.findall(body) if c != name and not c.startswith(('std::', '__gnu_cxx::'))})[:40]
    floats = sorted({'%.5g' % abs(float(f.rstrip('f'))) for f in FLOAT.findall(body)})[:16]
    return {'n': name, 's': strings, 'c': calls, 'f': floats}


def main(only=None):
    global ELF
    out = json.loads(OUT.read_text(encoding='utf-8')) if only and OUT.exists() else {}
    for tag, root in EXPORTS.items():
        if only and tag != only:
            continue
        if tag == 'android':
            so = Path(__file__).resolve().parents[3] / 'local/references/android-2014-06_2.155.47886/libroblox.so'
            ELF = Elf(so) if so.exists() else None
        rows = []
        if not root.exists():
            print(tag, 'export not found at', root)
            continue
        for sub in sorted(root.iterdir()):
            if sub.is_dir() and sub.name not in ('_EXTERNAL_',):
                for f in sub.rglob('*.c'):
                    r = parse(f)
                    if r:
                        rows.append(r)
        out[tag] = rows
        print(tag, len(rows), 'functions;', sum(1 for r in rows if r['s']), 'with strings;', sum(1 for r in rows if r['c']), 'with calls', flush=True)
    OUT.write_text(json.dumps(out, separators=(',', ':')), encoding='utf-8')


if __name__ == '__main__':
    main(sys.argv[1] if len(sys.argv) > 1 else None)
    sys.exit(0)
