// roc 2012-06 0084ed10  unit: std::D::DU?$char_traits::V?$basic_string::PAV?$unordered_map::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0084ed10
//
// 0084ed10  56                   push esi
// 0084ed11  8bf1                 mov esi, ecx
// 0084ed13  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0084ed17  68501ede00           push 0xde1e50
// 0084ed1c  ff15ec29b200         call dword ptr [0xb229ec]
// 0084ed22  84c0                 test al, al
// 0084ed24  7407                 je 0x84ed2d
// 0084ed26  8d4610               lea eax, [esi + 0x10]
// 0084ed29  5e                   pop esi
// 0084ed2a  c20400               ret 4
// 0084ed2d  33c0                 xor eax, eax
// 0084ed2f  5e                   pop esi
// 0084ed30  c20400               ret 4
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