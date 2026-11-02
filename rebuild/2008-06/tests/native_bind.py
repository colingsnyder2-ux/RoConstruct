"""Shared helpers for inactive native class probes: compile, exact-match and verify every relocation target.

A relocation in an exact body is bound to the address the original instruction uses, then verified:
  * imports: the thunk/IAT slot resolves to the same mfc90 ordinal (RTM .def name) or DLL export name;
  * ??_C@ string literals: the original bytes equal the literal;
  * ??_R0 type descriptors: the original RTTI name matches the symbol;
  * ??_7 vtables not listed explicitly: the original complete-object locator names the same class;
  * everything else: an explicit address map (internal) or a body proven by the same probe (own).
Compiler-generated EH state symbols are recorded as local, not as proof.
"""
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

import pefile

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match, rebuild  # noqa: E402

OUT = ROOT / 'rebuild/2008-06/out/native-layouts'
XTP_FLAGS = ['/UNOMINMAX', '/I' + str(ROOT / 'tools/libs/xtp-11.2.2/Source'), '/D_XTP_STATICLINK']
LOCAL_EH = re.compile(r'^(__ehhandler\$|__unwindfunclet\$|__catch\$|__tryblocktable\$|__unwindtable\$|__ehfuncinfo\$|\$LN\d)')


def flags():
    base = json.loads((ROOT / 'work/2008-06/shared-layouts/document-swap-current.json').read_text())
    return [x for x in base['flags'] if not x.startswith('/Fo') and not x.endswith('NativeDocumentLayout.cpp')]


def compile_unit(source, name, extra=()):
    OUT.mkdir(parents=True, exist_ok=True)
    obj = OUT / (name + '.obj')
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags() + list(extra) + ['/Fo' + str(obj), str(source)], OUT)
    assert code == 0, log
    return obj


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


class Original:
    def __init__(self):
        self.path = ROOT / 'work/2008-06/original-p4-reference/Roblox.exe'
        self.pe = pefile.PE(str(self.path))
        self.image = self.pe.OPTIONAL_HEADER.ImageBase
        self.imports = {x.address: (d.dll.decode().lower(), x.ordinal, x.name.decode() if x.name else None)
                        for d in self.pe.DIRECTORY_ENTRY_IMPORT for x in d.imports}
        self.mfc = {}
        for line in (ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def').read_text(errors='ignore').splitlines():
            m = re.match(r'\s*(\S+)\s+@\s*(\d+)', line)
            if m:
                self.mfc[int(m.group(2))] = m.group(1)

    def data(self, address, size):
        return self.pe.get_data(address - self.image, size)

    def string(self, address):
        return self.pe.get_string_at_rva(address - self.image).decode()

    def imported(self, value):
        slot = value
        if slot not in self.imports:
            head = self.data(value, 6)
            if head[:2] != b'\xff\x25':
                return None
            slot = struct.unpack_from('<I', head, 2)[0]
        dll, ordinal, name = self.imports[slot]
        return dll, (self.mfc.get(ordinal) if dll == 'mfc90.dll' else name)

    def vtable_class(self, value):
        locator = struct.unpack('<I', self.data(value - 4, 4))[0]
        descriptor = struct.unpack('<I', self.data(locator + 12, 4))[0]
        return self.string(descriptor + 8), struct.unpack('<I', self.data(locator + 4, 4))[0]


def plain(symbol):
    if symbol.startswith('__imp_'):
        symbol = symbol[6:]
    if symbol.startswith('?'):
        return symbol
    return re.sub(r'@\d+$', '', symbol[1:] if symbol.startswith('_') else symbol)


def verify(original, obj, methods, internal, own=None):
    """Exact-match each (symbol, address) of obj and verify all relocation targets; returns receipt rows."""
    own = dict(own or {}, **dict(methods))
    raw = Path(obj).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {n: (b, r) for n, b, r in match.coff_functions(raw)}
    rows = []
    for name, address in methods:
        body, refs = bodies[name]
        target, target_refs, _ = match.target('2008-06', '%08x' % address)
        assert match.exact_match(target, target_refs, body, refs), (name, hex(address), len(body), len(target))
        start, section = definitions[name]
        table = sections[section]
        code = raw[table[4] + start:]
        verified, local = {}, set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if not 0 <= offset < len(body):
                continue
            symbol = symbols[index][0]
            if kind == 20:  # REL32
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:          # DIR32: original operand = symbol + addend
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) & 0xffffffff
            if LOCAL_EH.match(symbol):
                local.add(symbol)
                continue
            hit = original.imported(value)
            if hit is not None:
                assert hit[1] == plain(symbol), (name, symbol, hex(value), hit)
                verified[symbol] = '%s!%s' % hit
            elif symbol.startswith('??_C@'):
                pos, at = definitions[symbol]
                literal = raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
                assert original.data(value, len(literal)) == literal, (name, symbol, hex(value))
                verified[symbol] = hex(value)
            elif symbol.startswith('??_R0') and symbol.endswith('@8'):
                rtti = original.string(value + 8)
                assert rtti == '.' + symbol[5:-2], (name, symbol, hex(value), rtti)
                verified[symbol] = '%s (%s)' % (hex(value), rtti)
            elif symbol.startswith('??_7') and symbol not in internal:
                rtti, offset_in_object = original.vtable_class(value)
                cls = symbol[4:symbol.index('@@6B') + 2]
                assert rtti.replace('3QBDB', '3PBDB') == '.?AV' + cls, (name, symbol, hex(value), rtti)
                verified[symbol] = '%s (RTTI %s, offset %#x)' % (hex(value), rtti, offset_in_object)
            else:
                assert internal.get(symbol, own.get(symbol)) == value, (name, symbol, hex(value))
                verified[symbol] = hex(value)
        rows.append({'address': '%08x' % address, 'symbol': name, 'size': len(body), 'exact': True,
                     'verified_targets': verified, 'local_eh': sorted(local)})
    return rows
