"""Audit original split ad-syndicator function; this does not test runtime behavior."""
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match

obj = Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / 'out/native-secure-ad-canonical/CheckSecureHtmlAdSyndicator.obj'
raw = obj.read_bytes()
sections, symbols, definitions, _ = match._coff_data_index(raw)
name = next(n for n in definitions if n.startswith('?isAdSyndicator@@'))
_, candidate, cand_refs = next(x for x in match.coff_functions(raw) if x[0] == name)
a, ar, _ = match.target('2008-06', '00465b50')
b, br, _ = match.target('2008-06', '00465d30')
assert 0x465b50 + len(a) == 0x465d30
original = a + b
assert len(original) == len(candidate) == 533
assert match.exact_match(original, list(ar) + [len(a) + x for x in br], candidate, cand_refs)
start, section = definitions[name]
table = sections[section]
base, image = match._image('2008-06')
bindings = {}
for i in range(table[7]):
    offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
    offset -= start
    if not 0 <= offset < len(original) - 3:
        continue
    symbol = symbols[index][0]
    if kind == 20:
        target = (0x465b50 + offset + 4 + struct.unpack_from('<i', original, offset)[0]) & 0xffffffff
    elif kind == 6:
        target = (struct.unpack_from('<I', original, offset)[0] - struct.unpack_from('<i', raw, table[4] + start + offset)[0]) & 0xffffffff
    else:
        continue
    bindings.setdefault(symbol, []).append(target)
    if symbol.startswith('??_C@'):
        pos, sec = definitions[symbol]
        st = sections[sec]
        literal = raw[st[4] + pos:st[4] + st[3]].split(b'\0', 1)[0] + b'\0'
        assert bytes(image[target - base:target - base + len(literal)]) == literal
for prefix, want in [('??0Http@RBX@@', 0x409750), ('??1Http@RBX@@', 0x5df620),
                     ('?get@Http@RBX@@', 0x569ae0), ('?applicationBaseUrl@@', 0x4060d0),
                     ('??HATL@@', 0x40e160), ('?query@?3??isAdSyndicator', 0x96df98),
                     ('?$S1@?3??isAdSyndicator', 0x96dfb4)]:
    assert any(symbol.startswith(prefix) and want in values for symbol, values in bindings.items()), prefix
source = ROOT / 'rebuild/2008-06/native-classes/SecureHtmlAdSyndicator.cpp'
receipt = {'scope': 'split original ranges, literal data and key call/global targets; no runtime proof',
           'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
           'object_sha256': hashlib.sha256(raw).hexdigest(), 'original_ranges': ['00465b50', '00465d30'],
           'bytes': len(original), 'verified_bindings': {k: [hex(x) for x in v] for k, v in bindings.items()}}
(ROOT / 'work/2008-06/native-ad-syndicator-20261105.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('PASS: ad-syndicator split body, data and key bindings')
