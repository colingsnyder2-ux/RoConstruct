// roc 2012-06 0084edc0  unit: RBX::Reflection::VVariant::PBV?$vector::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0084edc0
//
// 0084edc0  56                   push esi
// 0084edc1  8bf1                 mov esi, ecx
// 0084edc3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0084edc7  680020de00           push 0xde2000
// 0084edcc  ff15ec29b200         call dword ptr [0xb229ec]
// 0084edd2  84c0                 test al, al
// 0084edd4  7407                 je 0x84eddd
// 0084edd6  8d4610               lea eax, [esi + 0x10]
// 0084edd9  5e                   pop esi
// 0084edda  c20400               ret 4
// 0084eddd  33c0                 xor eax, eax
// 0084eddf  5e                   pop esi
// 0084ede0  c20400               ret 4
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