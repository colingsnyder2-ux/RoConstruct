// roc 2012-06 009794e0  unit: RBX::Limits::VCounter::V?$shared_ptr::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009794e0
//
// 009794e0  56                   push esi
// 009794e1  8bf1                 mov esi, ecx
// 009794e3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009794e7  682025e000           push 0xe02520
// 009794ec  ff15ec29b200         call dword ptr [0xb229ec]
// 009794f2  84c0                 test al, al
// 009794f4  7407                 je 0x9794fd
// 009794f6  8d4610               lea eax, [esi + 0x10]
// 009794f9  5e                   pop esi
// 009794fa  c20400               ret 4
// 009794fd  33c0                 xor eax, eax
// 009794ff  5e                   pop esi
// 00979500  c20400               ret 4
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