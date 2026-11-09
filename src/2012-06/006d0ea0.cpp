// roc 2012-06 006d0ea0  unit: std::D::DU?$char_traits::PAV?$basic_altstringbuf::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d0ea0
//
// 006d0ea0  56                   push esi
// 006d0ea1  8bf1                 mov esi, ecx
// 006d0ea3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006d0ea7  686844da00           push 0xda4468
// 006d0eac  ff15ec29b200         call dword ptr [0xb229ec]
// 006d0eb2  84c0                 test al, al
// 006d0eb4  7407                 je 0x6d0ebd
// 006d0eb6  8d4610               lea eax, [esi + 0x10]
// 006d0eb9  5e                   pop esi
// 006d0eba  c20400               ret 4
// 006d0ebd  33c0                 xor eax, eax
// 006d0ebf  5e                   pop esi
// 006d0ec0  c20400               ret 4
// copied from an identical function in another client (function ?f@S@@QAEPAXABVtype_info@@@Z)

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