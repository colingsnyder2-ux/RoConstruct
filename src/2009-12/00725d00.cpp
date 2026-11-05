// roc 2009-12 00725d00  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00725d00
//
// 00725d00  51                   push ecx
// 00725d01  56                   push esi
// 00725d02  8bf1                 mov esi, ecx
// 00725d04  8b16                 mov edx, dword ptr [esi]
// 00725d06  8d4624               lea eax, [esi + 0x24]
// 00725d09  8d4c2404             lea ecx, [esp + 4]
// 00725d0d  89442404             mov dword ptr [esp + 4], eax
// 00725d11  8b4208               mov eax, dword ptr [edx + 8]
// 00725d14  51                   push ecx
// 00725d15  50                   push eax
// 00725d16  e8c5fdffff           call 0x725ae0
// 00725d1b  8b16                 mov edx, dword ptr [esi]
// 00725d1d  8b420c               mov eax, dword ptr [edx + 0xc]
// 00725d20  8d4c240c             lea ecx, [esp + 0xc]
// 00725d24  51                   push ecx
// 00725d25  50                   push eax
// 00725d26  e8b5fdffff           call 0x725ae0
// 00725d2b  83c410               add esp, 0x10
// 00725d2e  834e4402             or dword ptr [esi + 0x44], 2
// 00725d32  c7464000000000       mov dword ptr [esi + 0x40], 0
// 00725d39  5e                   pop esi
// 00725d3a  59                   pop ecx
// 00725d3b  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000005@@QAEXXZ)

namespace ns_ROCX000005 {
struct S {
    void* vtable;
    char pad[0x20];
    int field24;
    char pad2[0x1c];
    int field44;
    int field40;
    void f();
};

extern "C" void __cdecl helper(void*, void*);

void S::f() {
    void* p = &field24;
    helper(*(void**)((char*)vtable + 8), &p);
    helper(*(void**)((char*)vtable + 12), &p);
    field44 |= 2;
    *(int*)((char*)this + 0x40) = 0;
}
}
