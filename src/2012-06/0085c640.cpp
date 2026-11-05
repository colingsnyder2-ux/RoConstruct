// roc 2012-06 0085c640  unit: UString_sink::?$stream_buffer  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085c640
//
// 0085c640  56                   push esi
// 0085c641  8bf1                 mov esi, ecx
// 0085c643  e868f5ffff           call 0x85bbb0
// 0085c648  8b0d9024b200         mov ecx, dword ptr [0xb22490]
// 0085c64e  8d4614               lea eax, [esi + 0x14]
// 0085c651  8908                 mov dword ptr [eax], ecx
// 0085c653  8b159424b200         mov edx, dword ptr [0xb22494]
// 0085c659  50                   push eax
// 0085c65a  8910                 mov dword ptr [eax], edx
// 0085c65c  ff159824b200         call dword ptr [0xb22498]
// 0085c662  83c404               add esp, 4
// 0085c665  5e                   pop esi
// 0085c666  c3                   ret 
// copied from an identical function in another client (function ?init@S@ns_ROCX000005@@QAEXXZ)

namespace ns_ROCX000005 {
struct S {
    char pad[0x14];
    void* field14;
    void init();
};

extern void* g_77e4dc;
extern void* g_77e4e0;
extern void (__cdecl *g_77e4e4)(void*);

extern "C" void __cdecl sub_54d430();

void S::init()
{
    sub_54d430();
    field14 = g_77e4dc;
    field14 = g_77e4e0;
    g_77e4e4(&field14);
}
}
