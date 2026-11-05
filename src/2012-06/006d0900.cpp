// roc 2012-06 006d0900  unit: RBX::DataModel::PAVGenericJob::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d0900
//
// 006d0900  56                   push esi
// 006d0901  8bf1                 mov esi, ecx
// 006d0903  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006d0907  68003bda00           push 0xda3b00
// 006d090c  ff15ec29b200         call dword ptr [0xb229ec]
// 006d0912  84c0                 test al, al
// 006d0914  7407                 je 0x6d091d
// 006d0916  8d4610               lea eax, [esi + 0x10]
// 006d0919  5e                   pop esi
// 006d091a  c20400               ret 4
// 006d091d  33c0                 xor eax, eax
// 006d091f  5e                   pop esi
// 006d0920  c20400               ret 4
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