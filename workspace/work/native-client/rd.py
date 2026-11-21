"""rd.py ADDR[:NDWORDS] ... : read dwords from the 2008-06 exe image (va)."""
import sys, struct, pefile
import os; sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..")))
from roc import clients
c = clients.load()['2008-06']; pe = pefile.PE(str(clients.exe_path('2008-06', c)), fast_load=True)
for a in sys.argv[1:]:
    ad, _, n = a.partition(':'); ad = int(ad, 16); n = int(n or 4)
    d = pe.get_data(ad - pe.OPTIONAL_HEADER.ImageBase if ad > pe.OPTIONAL_HEADER.ImageBase else ad - 0, n * 4) if False else pe.get_data(ad - pe.OPTIONAL_HEADER.ImageBase, n * 4)
    print('%08x' % ad, ' '.join('%08x' % x for x in struct.unpack('<%dI' % n, d)))
