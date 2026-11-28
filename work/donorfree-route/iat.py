"""python iat.py HEXADDR... -> import name at IAT slot (original 2008-06 exe)"""
import sys, struct, pefile
sys.path.insert(0,'.')
from roc import clients
p = pefile.PE(str(clients.exe_path('2008-06', clients.load()['2008-06'])))
m = {}
for e in p.DIRECTORY_ENTRY_IMPORT:
    for i in e.imports:
        m[i.address] = '%s!%s' % (e.dll.decode(), (i.name or b'#%d' % i.ordinal).decode())
for a in sys.argv[1:]:
    print(a, m.get(int(a, 16)))
