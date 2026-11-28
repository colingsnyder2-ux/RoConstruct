import pefile, capstone
pe = pefile.PE('run/RobloxQT.exe')
va = 0x430b63
rva = va - pe.OPTIONAL_HEADER.ImageBase
off = pe.get_offset_from_rva(rva)
data = pe.__data__[off:off+0x80]
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
for i in md.disasm(data, va):
    print(f"{i.address:08x}: {i.mnemonic} {i.op_str}")