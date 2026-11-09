// from server: 100% by nuck16
// roc 2009-12 007e5e90  unit: RBX::TaskScheduler::PAVJob::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e5e90
//
// 007e5e90  56                   push esi
// 007e5e91  8bf1                 mov esi, ecx
// 007e5e93  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e5e97  68184cb600           push 0xb64c18
// 007e5e9c  ff1568b79800         call dword ptr [0x98b768]
// 007e5ea2  84c0                 test al, al
// 007e5ea4  7407                 je 0x7e5ead
// 007e5ea6  8d4610               lea eax, [esi + 0x10]
// 007e5ea9  5e                   pop esi
// 007e5eaa  c20400               ret 4
// 007e5ead  33c0                 xor eax, eax
// 007e5eaf  5e                   pop esi
// 007e5eb0  c20400               ret 4

#include <typeinfo>

// boost sp_counted_impl_pd::get_deleter shape: 0xb64c18 = typeid(D), deleter at this+0x10
extern const type_info type_descriptor_b64c18;

struct S
{
    char pad[0x10];
    char del;
    void *f(const type_info &ti);
};

void *S::f(const type_info &ti)
{
    return ti == type_descriptor_b64c18 ? &del : 0;
}
