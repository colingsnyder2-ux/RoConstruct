import pefile,capstone,json,re,sys
r=json.load(open('../2008-06/identity-registry.json'))
q=pefile.PE('run/RobloxQT.exe',fast_load=True).get_memory_mapped_image()
o=pefile.PE('../../clients/2008-06/Roblox.exe',fast_load=True).get_memory_mapped_image()
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
syms={};obj={};by={}
for l in open('linkexp/qt.map',errors='replace'):
    p=l.split()
    if len(p)>=4 and ':' in p[0]:
        try:v=int(p[2],16)
        except:continue
        syms.setdefault(v,p[1]);obj.setdefault(v,p[-1]);by.setdefault(p[1],v)
def dis(img,a,n,s=None):
    for i in md.disasm(bytes(img[a-0x400000:a-0x400000+n]),a):
        x=''
        for h in re.findall(r'0x[0-9a-f]{6,}',i.op_str):
            t=int(h,16);x+=' '+((syms.get(t,'')[:70]+' '+obj.get(t,'')) if s else (r.get('%08x'%t) or {}).get('name','')[:70])
        print(hex(i.address),i.mnemonic,i.op_str,x)
        if i.mnemonic=='ret':break
for a in sys.argv[1:]:
    a=int(a,16); qa=by.get('func_%08x'%a) or by.get((r.get('%08x'%a) or {}).get('name',''))
    print('== ours',hex(qa or 0));
    if qa: dis(q,qa,0x80,1)
    print('== orig');dis(o,a,0x80)
