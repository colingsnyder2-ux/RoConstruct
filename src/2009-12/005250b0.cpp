// from server: 100% by nuck16
// roc 2009-12 005250b0  unit: Exposer  size: 110 bytes
//
// 005250b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005250b4  33c9                 xor ecx, ecx
// 005250b6  3bc1                 cmp eax, ecx
// 005250b8  7441                 je 0x5250fb
// 005250ba  83f801               cmp eax, 1
// 005250bd  743c                 je 0x5250fb
// 005250bf  83f802               cmp eax, 2
// 005250c2  7459                 je 0x52511d
// 005250c4  83f803               cmp eax, 3
// 005250c7  7521                 jne 0x5250ea
// 005250c9  56                   push esi
// 005250ca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005250ce  8b0e                 mov ecx, dword ptr [esi]
// 005250d0  6868a2b100           push 0xb1a268
// 005250d5  ff1568b79800         call dword ptr [0x98b768]
// 005250db  0fb6c0               movzx eax, al
// 005250de  f7d8                 neg eax
// 005250e0  1bc0                 sbb eax, eax
// 005250e2  23442408             and eax, dword ptr [esp + 8]
// 005250e6  8906                 mov dword ptr [esi], eax
// 005250e8  5e                   pop esi
// 005250e9  c3                   ret 
// 005250ea  8b442408             mov eax, dword ptr [esp + 8]
// 005250ee  c70068a2b100         mov dword ptr [eax], 0xb1a268
// 005250f4  884804               mov byte ptr [eax + 4], cl
// 005250f7  884805               mov byte ptr [eax + 5], cl
// 005250fa  c3                   ret 
// 005250fb  8b442408             mov eax, dword ptr [esp + 8]
// 005250ff  3bc1                 cmp eax, ecx
// 00525101  741a                 je 0x52511d
// 00525103  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00525107  8b11                 mov edx, dword ptr [ecx]
// 00525109  8910                 mov dword ptr [eax], edx
// 0052510b  8b5104               mov edx, dword ptr [ecx + 4]
// 0052510e  895004               mov dword ptr [eax + 4], edx
// 00525111  8b5108               mov edx, dword ptr [ecx + 8]
// 00525114  895008               mov dword ptr [eax + 8], edx
// 00525117  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0052511a  89480c               mov dword ptr [eax + 0xc], ecx
// 0052511d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb1a268 is typeid(F)
extern const type_info type_descriptor_b1a268;

struct Functor
{
    int f0, f1, f2, f3;
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
    char data[16];
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
        if (check_type == type_descriptor_b1a268)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b1a268;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
