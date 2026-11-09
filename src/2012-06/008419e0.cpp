// roc 2012-06 008419e0  unit: RBX::Lua::VFunctionScriptSlot::PAV?$TGenericSlotWrapper::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008419e0
//
// 008419e0  56                   push esi
// 008419e1  8bf1                 mov esi, ecx
// 008419e3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008419e7  681014de00           push 0xde1410
// 008419ec  ff15ec29b200         call dword ptr [0xb229ec]
// 008419f2  84c0                 test al, al
// 008419f4  7407                 je 0x8419fd
// 008419f6  8d4610               lea eax, [esi + 0x10]
// 008419f9  5e                   pop esi
// 008419fa  c20400               ret 4
// 008419fd  33c0                 xor eax, eax
// 008419ff  5e                   pop esi
// 00841a00  c20400               ret 4
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