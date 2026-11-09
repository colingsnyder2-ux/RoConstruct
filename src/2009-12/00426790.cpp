// from server: 100% by nuck16
// roc 2009-12 00426790  unit: RBX::Security::VContext::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00426790
//
// 00426790  56                   push esi
// 00426791  8bf1                 mov esi, ecx
// 00426793  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00426797  680048b000           push 0xb04800
// 0042679c  ff1568b79800         call dword ptr [0x98b768]
// 004267a2  84c0                 test al, al
// 004267a4  7407                 je 0x4267ad
// 004267a6  8d4610               lea eax, [esi + 0x10]
// 004267a9  5e                   pop esi
// 004267aa  c20400               ret 4
// 004267ad  33c0                 xor eax, eax
// 004267af  5e                   pop esi
// 004267b0  c20400               ret 4

#include <typeinfo>

// boost sp_counted_impl_pd::get_deleter shape: 0xb04800 = typeid(D), deleter at this+0x10
extern const type_info type_descriptor_b04800;

struct S
{
    char pad[0x10];
    char del;
    void *f(const type_info &ti);
};

void *S::f(const type_info &ti)
{
    return ti == type_descriptor_b04800 ? &del : 0;
}
