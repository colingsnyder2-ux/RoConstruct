// from server: 100% by Xemicl
// roc 2012-06 0085f460  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085f460
//
// 0085f460  56                   push esi
// 0085f461  8b31                 mov esi, dword ptr [ecx]
// 0085f463  807e5800             cmp byte ptr [esi + 0x58], 0
// 0085f467  740b                 je 0x85f474
// 0085f469  8bce                 mov ecx, esi
// 0085f46b  e8b0bbffff           call 0x85b020
// 0085f470  c6465800             mov byte ptr [esi + 0x58], 0
// 0085f474  5e                   pop esi
// 0085f475  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX00001e@@QAEXXZ)

namespace ns_ROCX00001e {
struct S
{
    void f();
};

extern "C" void __fastcall sub_006a1f20(void*);

void S::f()
{
    char* p = *(char**)this;
    if (p[0x58] != 0)
    {
        sub_006a1f20(p);
        p[0x58] = 0;
    }
}
}
