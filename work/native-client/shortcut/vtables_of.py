"""python vtables_of.py MANGLED_TYPE_NAME [slots]  -- vtables of a class in the 2008 exe via RTTI complete object locators, with slot targets labelled."""
import struct, sys
sys.path.insert(0, '.')
from roc import rtti, match, native_asm
name = sys.argv[1]; nslots = int(sys.argv[2]) if len(sys.argv) > 2 else 8
base, image = match._image('2008-06')
td = [a for a, n in rtti.descriptors('2008-06').items() if n == name]
print('type descriptor', [hex(a) for a in td])
w = lambda va: struct.unpack_from('<I', image, va - base)[0]
for t in td:
    # complete object locator: sig(0) offset cdOffset typeDescriptor classDescriptor ; find COLs pointing at t
    pos = 0
    pat = struct.pack('<I', t)
    while True:
        h = image.find(pat, pos)
        if h < 0: break
        pos = h + 1
        col = base + h - 12
        if col < base or w(col) != 0: continue
        off = w(col + 4)
        # vtable: the word after a pointer to this COL
        p2 = struct.pack('<I', col); q = 0
        while True:
            k = image.find(p2, q)
            if k < 0: break
            q = k + 1
            vt = base + k + 4
            slots = [w(vt + 4 * i) for i in range(nslots)]
            print('COL %x offset 0x%x vtable %x' % (col, off, vt))
            for i, s in enumerate(slots):
                print('   %2d %08x %s' % (i, s, native_asm.label('2008-06', s) or ''))
