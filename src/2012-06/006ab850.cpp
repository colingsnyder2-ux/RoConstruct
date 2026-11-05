// roc 2012-06 006ab850  unit: RBX::Reflection::VVariant::PAV?$vector::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006ab850
//
// 006ab850  56                   push esi
// 006ab851  8bf1                 mov esi, ecx
// 006ab853  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006ab857  68c0ecd900           push 0xd9ecc0
// 006ab85c  ff15ec29b200         call dword ptr [0xb229ec]
// 006ab862  84c0                 test al, al
// 006ab864  7407                 je 0x6ab86d
// 006ab866  8d4610               lea eax, [esi + 0x10]
// 006ab869  5e                   pop esi
// 006ab86a  c20400               ret 4
// 006ab86d  33c0                 xor eax, eax
// 006ab86f  5e                   pop esi
// 006ab870  c20400               ret 4
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