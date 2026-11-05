// from server: 100% by nuck16
// roc 2009-12 007e8f20  unit: RBX::Limits::VCounter::V?$shared_ptr::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e8f20
//
// 007e8f20  56                   push esi
// 007e8f21  8bf1                 mov esi, ecx
// 007e8f23  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e8f27  68b84eb600           push 0xb64eb8
// 007e8f2c  ff1568b79800         call dword ptr [0x98b768]
// 007e8f32  84c0                 test al, al
// 007e8f34  7407                 je 0x7e8f3d
// 007e8f36  8d4610               lea eax, [esi + 0x10]
// 007e8f39  5e                   pop esi
// 007e8f3a  c20400               ret 4
// 007e8f3d  33c0                 xor eax, eax
// 007e8f3f  5e                   pop esi
// 007e8f40  c20400               ret 4

#include <typeinfo>

// boost sp_counted_impl_pd::get_deleter shape: 0xb64eb8 = typeid(D), deleter at this+0x10
extern const type_info type_descriptor_b64eb8;

struct S
{
    char pad[0x10];
    char del;
    void *f(const type_info &ti);
};

void *S::f(const type_info &ti)
{
    return ti == type_descriptor_b64eb8 ? &del : 0;
}
