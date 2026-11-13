import json,struct,sys,re
t=sys.argv[1]
names=json.load(open('work/native-client/link/probe.json'))['unresolved']
def is_data(n):
    if n.startswith(('??_7','??_C','??_R','??_B')): return True
    if re.match(r'^\?[^@]+(@[^@]+)*@@[0-9]',n): return True
    return not n.startswith('?') and not n.startswith('_') or n.startswith('_IID') or n.startswith('_LIBID')
funcs=[n for n in names if not is_data(n)]; data=[n for n in names if is_data(n)]
code=b'\x31\xc0\xc3'  # xor eax,eax; ret
text=code*len(funcs); DATA=0x800
strtab=bytearray(); syms=[]
def sname(n):
    if len(n)<=8: return n.encode().ljust(8,b'\0')
    off=4+len(strtab); strtab.extend(n.encode()+b'\0'); return struct.pack('<II',0,off)
for i,n in enumerate(funcs): syms.append(sname(n)+struct.pack('<IhHBB',i*3,1,0x20,2,0))
for i,n in enumerate(data): syms.append(sname(n)+struct.pack('<IhHBB',i*DATA,2,0,2,0))
hdr_size=20+40*2
text_ptr=hdr_size
def sec(name,size,ptr,flags): return name.ljust(8,b'\0')+struct.pack('<IIIIIIHHI',0,0,size,ptr,0,0,0,0,flags)
sym_ptr=text_ptr+len(text)
obj=struct.pack('<HHIIIHH',0x14c,2,0,sym_ptr,len(syms),0,0)
obj+=sec(b'.text',len(text),text_ptr,0x60500020)
obj+=sec(b'.bss',len(data)*DATA,0,0xC0300080)
obj+=text+b''.join(syms)+struct.pack('<I',4+len(strtab))+bytes(strtab)
open(t+'/stubs.obj','wb').write(obj)
json.dump({'selected':[{'object':t+'/stubs.obj'}]},open(t+'/stubs_receipt.json','w'))
print(len(funcs),len(data))
