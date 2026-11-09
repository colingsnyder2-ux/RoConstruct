// from server: 100% by nuck16
// roc 2009-12 004620b0  unit: RBX::PAVDebugSettings::?$sp_counted_impl_pd  size: 98 bytes
//
// 004620b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004620b4  33c9                 xor ecx, ecx
// 004620b6  3bc1                 cmp eax, ecx
// 004620b8  7441                 je 0x4620fb
// 004620ba  83f801               cmp eax, 1
// 004620bd  743c                 je 0x4620fb
// 004620bf  83f802               cmp eax, 2
// 004620c2  744d                 je 0x462111
// 004620c4  83f803               cmp eax, 3
// 004620c7  7521                 jne 0x4620ea
// 004620c9  56                   push esi
// 004620ca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004620ce  8b0e                 mov ecx, dword ptr [esi]
// 004620d0  68b8a9b000           push 0xb0a9b8
// 004620d5  ff1568b79800         call dword ptr [0x98b768]
// 004620db  0fb6c0               movzx eax, al
// 004620de  f7d8                 neg eax
// 004620e0  1bc0                 sbb eax, eax
// 004620e2  23442408             and eax, dword ptr [esp + 8]
// 004620e6  8906                 mov dword ptr [esi], eax
// 004620e8  5e                   pop esi
// 004620e9  c3                   ret 
// 004620ea  8b442408             mov eax, dword ptr [esp + 8]
// 004620ee  c700b8a9b000         mov dword ptr [eax], 0xb0a9b8
// 004620f4  884804               mov byte ptr [eax + 4], cl
// 004620f7  884805               mov byte ptr [eax + 5], cl
// 004620fa  c3                   ret 
// 004620fb  8b442408             mov eax, dword ptr [esp + 8]
// 004620ff  3bc1                 cmp eax, ecx
// 00462101  740e                 je 0x462111
// 00462103  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00462107  8b11                 mov edx, dword ptr [ecx]
// 00462109  8910                 mov dword ptr [eax], edx
// 0046210b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0046210e  894804               mov dword ptr [eax + 4], ecx
// 00462111  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb0a9b8 is typeid(F)
extern const type_info type_descriptor_b0a9b8;

struct Functor
{
    int f0, f1;
};

union function_buffer
{
    void *obj_ptr;
    struct
    {
        const type_info *type;
        bool const_qualified;
        bool volatile_qualified;
    } type;
    char data[8];
};

enum functor_manager_operation_type
{
    clone_functor_tag,
    move_functor_tag,
    destroy_functor_tag,
    check_functor_type_tag,
    get_functor_type_tag
};

void manage(const function_buffer &in_buffer, function_buffer &out_buffer, functor_manager_operation_type op)
{
    if (op == clone_functor_tag || op == move_functor_tag) {
        const Functor *in_functor = reinterpret_cast<const Functor *>(&in_buffer.data);
        new ((void *)&out_buffer.data) Functor(*in_functor);
    } else if (op == destroy_functor_tag) {
    } else if (op == check_functor_type_tag) {
        const type_info &check_type = *out_buffer.type.type;
        if (check_type == type_descriptor_b0a9b8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b0a9b8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
