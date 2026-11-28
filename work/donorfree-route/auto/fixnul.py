import sys
p=sys.argv[1]; s=open(p,'rb').read()
s=s.replace(bytes([0]), b'\0').replace(bytes([1]), b'\1')
open(p,'wb').write(s)
