import pefile
pe = pefile.PE('run/RobloxQT.exe')
needle = (0x8f2bc4).to_bytes(4,'little')
for sec in pe.sections:
    data=sec.get_data()
    off=0
    while True:
        i=data.find(needle,off)
        if i<0: break
        va=sec.VirtualAddress+i+pe.OPTIONAL_HEADER.ImageBase
        print(hex(va), sec.Name)
        off=i+1