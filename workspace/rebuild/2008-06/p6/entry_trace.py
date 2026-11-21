import pefile,capstone,struct,re,sys
exe=r'C:\Users\colin\roc-p6\clients\2008-06\Roblox.exe'
pe=pefile.PE(exe,fast_load=True); pe.parse_data_directories()
base=pe.OPTIONAL_HEADER.ImageBase; img=pe.get_memory_mapped_image()
print('entry %08x'%(base+pe.OPTIONAL_HEADER.AddressOfEntryPoint))
for s in pe.sections: print(s.Name.rstrip(b'\0').decode(),'%08x %x'%(base+s.VirtualAddress,s.Misc_VirtualSize))
iat={}
for e in pe.DIRECTORY_ENTRY_IMPORT:
    for i in e.imports:
        iat[i.address]=e.dll.decode()+'!'+((i.name or b'#%d'%(i.ordinal or 0)).decode())
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
def dis(va,n=90,stop=True):
    out=[]
    for i in md.disasm(bytes(img[va-base:va-base+n*7]),va):
        t=i.op_str
        m=re.search(r'0x([0-9a-f]{6,8})',t)
        if m and int(m.group(1),16) in iat: t+='  ; '+iat[int(m.group(1),16)]
        out.append((i.address,i.mnemonic,t)); 
        if len(out)>=n or (stop and i.mnemonic=='ret'): break
    return out
def show(va,n=90):
    for a,m,t in dis(va,n): print('%08x %s %s'%(a,m,t))

tgt=0x6a18e6
for a,m,t in dis(tgt,230,False):
    if m=='call' : print('%08x %s %s'%(a,m,t))
    if a>0x6a1ba0: break
data=bytes(img)
def rtti(name):
    idx=data.find(name.encode())
    if idx<0: return []
    td=base+idx-8
    res=[]
    for m in re.finditer(re.escape(struct.pack('<I',td)),data):
        col=base+m.start()-12
        if struct.unpack('<I',data[col-base:col-base+4])[0]!=0: continue
        off=struct.unpack('<I',data[col-base+4:col-base+8])[0]
        for v in re.finditer(re.escape(struct.pack('<I',col)),data):
            res.append((off,base+v.start()+4))
    return res
names=[x.decode() for x in sorted(set(re.findall(rb'\.\?AV[A-Za-z_0-9]+@@',data)))]
keep=[n for n in names if re.match(r'\.\?AV(C[A-Z]|.*(Dlg|Dialog|Frame|View|Doc|App|Pane|Wnd|Tool|Bar)).*',n) and not re.match(r'\.\?AVC(Wnd|Xtp|XTP|Dialog|Object|CmdTarget|View|Doc)',n)]
print(len(names),'classes; app-ish',len(keep))
print(' '.join(k[4:-2] for k in keep)[:5000])
for n in ('.?AVCRobloxApp@@','.?AVCMainFrame@@','.?AVCRobloxDoc@@','.?AVCRobloxView@@'):
    r=rtti(n); print(n,[(o,hex(v)) for o,v in r])
    for o,v in r[:1]:
        sl=struct.unpack('<40I',data[v-base:v-base+160]); print('  ',' '.join('%d:%06x'%(i,x) for i,x in enumerate(sl)))

print('=== funcs')
import json,os
integ=set(json.load(open(r'C:\Users\colin\RoConstruct\docs\integration.json'))['native'])
S='C:/Users/colin/RoConstruct/src/2008-06'
def strs(va,n=400):
    o=[]
    for a,m,t in dis(va,n):
        for h in re.findall(r'0x([0-9a-f]{6})\b',t):
            v=int(h,16)
            if 0x802000<=v<0x928000:
                b=data[v-base:v-base+70].split(b'\0')[0]
                if len(b)>=4 and all(32<=c<127 for c in b): o.append(b.decode())
    return o
for name,va in [('app12',0x44d440),('app22',0x44d810),('app23',0x44d790),('app28',0x44ad60),('winmain',0x7bca00)]:
    k='%08x'%va
    print(name,k,'src' if os.path.exists(S+'/'+k+'.cpp') else 'nosrc','integrated' if k in integ else 'not-integrated',strs(va)[:14])
    d=dis(va,14); print('   ',' | '.join(m+' '+t for a,m,t in d)[:420])
