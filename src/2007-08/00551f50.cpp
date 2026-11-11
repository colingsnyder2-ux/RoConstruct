// from server: 100% by EspClaude
// from server: 75% by colin
// roc 2007-08 00551f50  unit: std::D::V?$allocator::U?$basic_zlib_decompressor::?$stream_buffer  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00551f50
//
// 00551f50  53                   push ebx
// 00551f51  56                   push esi
// 00551f52  8bf1                 mov esi, ecx
// 00551f54  8b465c               mov eax, dword ptr [esi + 0x5c]
// 00551f57  c1e803               shr eax, 3
// 00551f5a  a801                 test al, 1
// 00551f5c  7411                 je 0x551f6f
// 00551f5e  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 00551f61  833900               cmp dword ptr [ecx], 0
// 00551f64  7509                 jne 0x551f6f
// 00551f66  8b16                 mov edx, dword ptr [esi]
// 00551f68  8b4258               mov eax, dword ptr [edx + 0x58]
// 00551f6b  8bce                 mov ecx, esi
// 00551f6d  ffd0                 call eax
// 00551f6f  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00551f73  83fbff               cmp ebx, -1
// 00551f76  7477                 je 0x551fef
// 00551f78  8b4e5c               mov ecx, dword ptr [esi + 0x5c]
// 00551f7b  c1e903               shr ecx, 3
// 00551f7e  f6c101               test cl, 1
// 00551f81  7449                 je 0x551fcc
// 00551f83  8b5624               mov edx, dword ptr [esi + 0x24]
// 00551f86  8b02                 mov eax, dword ptr [edx]
// 00551f88  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00551f8b  8b11                 mov edx, dword ptr [ecx]
// 00551f8d  03d0                 add edx, eax
// 00551f8f  3bc2                 cmp eax, edx
// 00551f91  751f                 jne 0x551fb2
// 00551f93  8bce                 mov ecx, esi
// 00551f95  e886faffff           call 0x551a20
// 00551f9a  8b4624               mov eax, dword ptr [esi + 0x24]
// 00551f9d  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00551fa0  8b00                 mov eax, dword ptr [eax]
// 00551fa2  8b11                 mov edx, dword ptr [ecx]
// 00551fa4  03d0                 add edx, eax
// 00551fa6  3bc2                 cmp eax, edx
// 00551fa8  7508                 jne 0x551fb2
// 00551faa  5e                   pop esi
// 00551fab  83c8ff               or eax, 0xffffffff
// 00551fae  5b                   pop ebx
// 00551faf  c20400               ret 4
// 00551fb2  8b4624               mov eax, dword ptr [esi + 0x24]
// 00551fb5  8b08                 mov ecx, dword ptr [eax]
// 00551fb7  8819                 mov byte ptr [ecx], bl
// 00551fb9  8b4634               mov eax, dword ptr [esi + 0x34]
// 00551fbc  8300ff               add dword ptr [eax], -1
// 00551fbf  8b7624               mov esi, dword ptr [esi + 0x24]
// 00551fc2  830601               add dword ptr [esi], 1
// 00551fc5  5e                   pop esi
// 00551fc6  8bc3                 mov eax, ebx
// 00551fc8  5b                   pop ebx
// 00551fc9  c20400               ret 4
// 00551fcc  8b464c               mov eax, dword ptr [esi + 0x4c]
// 00551fcf  6a01                 push 1
// 00551fd1  8d542410             lea edx, [esp + 0x10]
// 00551fd5  52                   push edx
// 00551fd6  50                   push eax
// 00551fd7  8d4e40               lea ecx, [esi + 0x40]
// 00551fda  885c2418             mov byte ptr [esp + 0x18], bl
// 00551fde  e86dbdffff           call 0x54dd50
// 00551fe3  83f801               cmp eax, 1
// 00551fe6  75c2                 jne 0x551faa
// 00551fe8  5e                   pop esi
// 00551fe9  8bc3                 mov eax, ebx
// 00551feb  5b                   pop ebx
// 00551fec  c20400               ret 4
// 00551fef  5e                   pop esi
// 00551ff0  33c0                 xor eax, eax
// 00551ff2  5b                   pop ebx
// 00551ff3  c20400               ret 4

struct Device {
    int write(int next, char* s, int n);
};

struct StreamBuf {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54();
    virtual void init_put_area();
    char pad[0x20];
    char** pnext;      // 0x24
    char pad2[0xc];
    int* pcount;       // 0x34
    char pad3[0x8];
    Device dev;        // 0x40
    char pad4[0xb];
    int next;          // 0x4c
    char pad5[0xc];
    unsigned flags;    // 0x5c

    bool output_buffered() const { return ((flags >> 3) & 1) != 0; }
    char* pptr() const { return *pnext; }
    char* epptr() const { return *pnext + *pcount; }
    void pbump(int n) { *pcount -= n; *pnext += n; }
    void sync_impl();
    int overflow(int c);
};

int StreamBuf::overflow(int c)
{
    if (output_buffered() && pptr() == 0)
        init_put_area();
    if (c != -1) {
        if (output_buffered()) {
            if (pptr() == epptr()) {
                sync_impl();
                if (pptr() == epptr())
                    return -1;
            }
            *pptr() = (char)c;
            pbump(1);
        } else {
            char d = (char)c;
            if (dev.write(next, &d, 1) != 1)
                return -1;
        }
        return c;
    }
    return 0;
}
