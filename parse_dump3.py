import struct
from pathlib import Path
dumps=sorted(Path("C:/Users/colin/AppData/Local/CrashDumps").glob("empty_main.exe.*.dmp"))
for d in dumps[-1:]:
    data=d.read_bytes()
    sig,ver,nstreams,dirrva,checksum,timestamp,flags = struct.unpack_from("<IIIIIIQ", data, 0)
    for i in range(nstreams):
        typ,size,rva=struct.unpack_from("<III", data, dirrva + i*12)
        if typ==4:
            nmod=struct.unpack_from("<I", data, rva)[0]
            for j in range(min(nmod,3)):
                base,size_img,checksum,ts,modname_rva=struct.unpack_from("<QIII I", data, rva+4 + j*24)
                name=data[modname_rva:modname_rva+80].decode('utf-16le','replace').split('\x00')[0]
                Path("dump_modules.txt").write_text(f"{hex(base)} {size_img} {name}\n", encoding="utf-8")
        if typ==6:
            thread_id,align=struct.unpack_from("<II", data, rva)
            code,eflags,erec,addr,nparams,unused=struct.unpack_from("<IIQQII", data, rva+8)
            Path("dump_exc.txt").write_text(f"thread {thread_id} code {hex(code)} addr {hex(addr)}\n", encoding="utf-8")
