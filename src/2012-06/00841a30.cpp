// roc 2012-06 00841a30  unit: RBX::Lua::VWaitScriptSlot::PAV?$TGenericSlotWrapper::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00841a30
//
// 00841a30  56                   push esi
// 00841a31  8bf1                 mov esi, ecx
// 00841a33  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00841a37  688014de00           push 0xde1480
// 00841a3c  ff15ec29b200         call dword ptr [0xb229ec]
// 00841a42  84c0                 test al, al
// 00841a44  7407                 je 0x841a4d
// 00841a46  8d4610               lea eax, [esi + 0x10]
// 00841a49  5e                   pop esi
// 00841a4a  c20400               ret 4
// 00841a4d  33c0                 xor eax, eax
// 00841a4f  5e                   pop esi
// 00841a50  c20400               ret 4
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