import struct
from pathlib import Path
dumps=sorted(Path("C:/Users/colin/AppData/Local/CrashDumps").glob("empty_main.exe.*.dmp"))
for d in dumps[-1:]:
    data=d.read_bytes()
    sig,ver,nstreams,dirrva,checksum,timestamp,flags = struct.unpack_from("<IIIIIIQ", data, 0)
    for i in range(nstreams):
        typ,size,rva=struct.unpack_from("<III", data, dirrva + i*12)
        if typ==6:
            thread_id,align=struct.unpack_from("<II", data, rva)
            code,eflags,erec,addr,nparams,unused=struct.unpack_from("<IIQQII", data, rva+8)
            print("thread", thread_id, "code", hex(code), "addr", hex(addr))
