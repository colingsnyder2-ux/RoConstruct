import pefile
pe=pefile.PE('run/RobloxQT.exe')
base=pe.OPTIONAL_HEADER.ImageBase
needle=b'\xa4\xda\xaa\x00'  # little-endian immediate 0xaa3da4 (mov [0xaa3da4], eax etc)
# search all sections
for sec in pe.sections:
    data=sec.get_data()
    off=0
    while True:
        i=data.find(needle, off)
        if i<0: break
        va=sec.VirtualAddress+i+base
        print(hex(va), sec.Name)
        off=i+1