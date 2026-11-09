// roc 2012-06 00975800  unit: RBX::TaskScheduler::PAVJob::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00975800
//
// 00975800  56                   push esi
// 00975801  8bf1                 mov esi, ecx
// 00975803  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00975807  688022e000           push 0xe02280
// 0097580c  ff15ec29b200         call dword ptr [0xb229ec]
// 00975812  84c0                 test al, al
// 00975814  7407                 je 0x97581d
// 00975816  8d4610               lea eax, [esi + 0x10]
// 00975819  5e                   pop esi
// 0097581a  c20400               ret 4
// 0097581d  33c0                 xor eax, eax
// 0097581f  5e                   pop esi
// 00975820  c20400               ret 4
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