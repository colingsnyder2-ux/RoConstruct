// from server: 100% by nuck16
// roc 2009-12 005cc7a0  unit: RBX::MeshRefPartAdapter  size: 110 bytes
//
// 005cc7a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005cc7a4  33c9                 xor ecx, ecx
// 005cc7a6  3bc1                 cmp eax, ecx
// 005cc7a8  7441                 je 0x5cc7eb
// 005cc7aa  83f801               cmp eax, 1
// 005cc7ad  743c                 je 0x5cc7eb
// 005cc7af  83f802               cmp eax, 2
// 005cc7b2  7459                 je 0x5cc80d
// 005cc7b4  83f803               cmp eax, 3
// 005cc7b7  7521                 jne 0x5cc7da
// 005cc7b9  56                   push esi
// 005cc7ba  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005cc7be  8b0e                 mov ecx, dword ptr [esi]
// 005cc7c0  68a85bb200           push 0xb25ba8
// 005cc7c5  ff1568b79800         call dword ptr [0x98b768]
// 005cc7cb  0fb6c0               movzx eax, al
// 005cc7ce  f7d8                 neg eax
// 005cc7d0  1bc0                 sbb eax, eax
// 005cc7d2  23442408             and eax, dword ptr [esp + 8]
// 005cc7d6  8906                 mov dword ptr [esi], eax
// 005cc7d8  5e                   pop esi
// 005cc7d9  c3                   ret 
// 005cc7da  8b442408             mov eax, dword ptr [esp + 8]
// 005cc7de  c700a85bb200         mov dword ptr [eax], 0xb25ba8
// 005cc7e4  884804               mov byte ptr [eax + 4], cl
// 005cc7e7  884805               mov byte ptr [eax + 5], cl
// 005cc7ea  c3                   ret 
// 005cc7eb  8b442408             mov eax, dword ptr [esp + 8]
// 005cc7ef  3bc1                 cmp eax, ecx
// 005cc7f1  741a                 je 0x5cc80d
// 005cc7f3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005cc7f7  8b11                 mov edx, dword ptr [ecx]
// 005cc7f9  8910                 mov dword ptr [eax], edx
// 005cc7fb  8b5104               mov edx, dword ptr [ecx + 4]
// 005cc7fe  895004               mov dword ptr [eax + 4], edx
// 005cc801  8b5108               mov edx, dword ptr [ecx + 8]
// 005cc804  895008               mov dword ptr [eax + 8], edx
// 005cc807  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005cc80a  89480c               mov dword ptr [eax + 0xc], ecx
// 005cc80d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb25ba8 is typeid(F)
extern const type_info type_descriptor_b25ba8;

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
        if (check_type == type_descriptor_b25ba8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b25ba8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
