"""Check native icon dependencies against existing compiled GImage implementation."""
import hashlib, json, struct, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT))
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from roc import match
icon = ROOT / 'rebuild/2008-06/out/native-layouts/NativeFrameIconsFresh.obj'
gimage = ROOT / 'rebuild/2008-06/out/P2ImageCore/linked/GImage.obj'
obj = gimage.read_bytes(); rows = []
for address, prefix in (('005105b0','??0GImage@G3D@@QAE@PBEH'), ('0050e230','??1GImage@G3D@@')):
    target, relocs, _ = match.target('2008-06', address)
    name, body, refs = next((n,b,r) for n,b,r in match.coff_functions(obj) if n.startswith(prefix))
    assert match.exact_match(target, relocs, body, refs)
    rows.append(dict(address=address, symbol=name, size=len(body)))
icon_obj = icon.read_bytes(); sections, symbols, definitions, _ = match._coff_data_index(icon_obj)
name, body, _ = next((n,b,r) for n,b,r in match.coff_functions(icon_obj) if n.startswith('?loadIcon@@'))
start, section = definitions[name]; table = sections[section]; refs = {}
for i in range(table[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', icon_obj, table[5] + i * 10)
    if start <= offset < start + len(body): refs[offset-start] = symbols[symbol][0]
target, _, _ = match.target('2008-06', '0042f0a0')
calls = {i.address - 0x42f0a0 + 1:int(i.op_str,16) for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(target,0x42f0a0) if i.mnemonic == 'call' and i.op_str.startswith('0x')}
for offset, prefix, address in ((0x7e,'??0GImage@G3D@@QAE@PBEH',0x5105b0),(0x11e,'??1GImage@G3D@@',0x50e230),(0x1cc,'??1GImage@G3D@@',0x50e230),(0x138,'?GetWidth@CImage@ATL@@',0x442c80)):
    assert refs[offset].startswith(prefix) and calls[offset] == address
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = dict(revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(), objects={str(p.relative_to(ROOT)):sha(p) for p in (icon,gimage)}, methods=rows, verified_calls=[hex(v) for v in (0x7e,0x11e,0x1cc,0x138)], scope='Object bodies and selected icon call targets only; GImage runtime layout and data, all other relocations, and active linkage remain unverified.')
(ROOT/'work/2008-06/shared-layouts/frame-icon-image-deps-working-probe.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf8')
print('PASS: icon GImage ctor/dtor and ATL width call targets')
