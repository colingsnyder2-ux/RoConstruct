// from server: 100% by nuck16
// roc 2009-12 00665be0  unit: RBX::DataModel::PAVGenericJob::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00665be0
//
// 00665be0  56                   push esi
// 00665be1  8bf1                 mov esi, ecx
// 00665be3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00665be7  684832b300           push 0xb33248
// 00665bec  ff1568b79800         call dword ptr [0x98b768]
// 00665bf2  84c0                 test al, al
// 00665bf4  7407                 je 0x665bfd
// 00665bf6  8d4610               lea eax, [esi + 0x10]
// 00665bf9  5e                   pop esi
// 00665bfa  c20400               ret 4
// 00665bfd  33c0                 xor eax, eax
// 00665bff  5e                   pop esi
// 00665c00  c20400               ret 4

#include <typeinfo>

// boost sp_counted_impl_pd::get_deleter shape: 0xb33248 = typeid(D), deleter at this+0x10
extern const type_info type_descriptor_b33248;

struct S
{
    char pad[0x10];
    char del;
    void *f(const type_info &ti);
};

void *S::f(const type_info &ti)
{
    return ti == type_descriptor_b33248 ? &del : 0;
}
