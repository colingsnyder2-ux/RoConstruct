// roc 2012-06 009731f0  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009731f0
//
// 009731f0  56                   push esi
// 009731f1  8bf1                 mov esi, ecx
// 009731f3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009731f7  68f01de000           push 0xe01df0
// 009731fc  ff15ec29b200         call dword ptr [0xb229ec]
// 00973202  84c0                 test al, al
// 00973204  7407                 je 0x97320d
// 00973206  8d4610               lea eax, [esi + 0x10]
// 00973209  5e                   pop esi
// 0097320a  c20400               ret 4
// 0097320d  33c0                 xor eax, eax
// 0097320f  5e                   pop esi
// 00973210  c20400               ret 4
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