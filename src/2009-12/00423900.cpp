// from server: 100% by nuck16
// roc 2009-12 00423900  unit: VThreadLogManager::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00423900
//
// 00423900  56                   push esi
// 00423901  8bf1                 mov esi, ecx
// 00423903  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00423907  680846b000           push 0xb04608
// 0042390c  ff1568b79800         call dword ptr [0x98b768]
// 00423912  84c0                 test al, al
// 00423914  7407                 je 0x42391d
// 00423916  8d4610               lea eax, [esi + 0x10]
// 00423919  5e                   pop esi
// 0042391a  c20400               ret 4
// 0042391d  33c0                 xor eax, eax
// 0042391f  5e                   pop esi
// 00423920  c20400               ret 4

#include <typeinfo>

// boost sp_counted_impl_pd::get_deleter shape: 0xb04608 = typeid(D), deleter at this+0x10
extern const type_info type_descriptor_b04608;

struct S
{
    char pad[0x10];
    char del;
    void *f(const type_info &ti);
};

void *S::f(const type_info &ti)
{
    return ti == type_descriptor_b04608 ? &del : 0;
}
