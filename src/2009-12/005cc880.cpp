// from server: 100% by nuck16
// roc 2009-12 005cc880  unit: RBX::MeshRefPartAdapter  size: 110 bytes
//
// 005cc880  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005cc884  33c9                 xor ecx, ecx
// 005cc886  3bc1                 cmp eax, ecx
// 005cc888  7441                 je 0x5cc8cb
// 005cc88a  83f801               cmp eax, 1
// 005cc88d  743c                 je 0x5cc8cb
// 005cc88f  83f802               cmp eax, 2
// 005cc892  7459                 je 0x5cc8ed
// 005cc894  83f803               cmp eax, 3
// 005cc897  7521                 jne 0x5cc8ba
// 005cc899  56                   push esi
// 005cc89a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005cc89e  8b0e                 mov ecx, dword ptr [esi]
// 005cc8a0  68f05cb200           push 0xb25cf0
// 005cc8a5  ff1568b79800         call dword ptr [0x98b768]
// 005cc8ab  0fb6c0               movzx eax, al
// 005cc8ae  f7d8                 neg eax
// 005cc8b0  1bc0                 sbb eax, eax
// 005cc8b2  23442408             and eax, dword ptr [esp + 8]
// 005cc8b6  8906                 mov dword ptr [esi], eax
// 005cc8b8  5e                   pop esi
// 005cc8b9  c3                   ret 
// 005cc8ba  8b442408             mov eax, dword ptr [esp + 8]
// 005cc8be  c700f05cb200         mov dword ptr [eax], 0xb25cf0
// 005cc8c4  884804               mov byte ptr [eax + 4], cl
// 005cc8c7  884805               mov byte ptr [eax + 5], cl
// 005cc8ca  c3                   ret 
// 005cc8cb  8b442408             mov eax, dword ptr [esp + 8]
// 005cc8cf  3bc1                 cmp eax, ecx
// 005cc8d1  741a                 je 0x5cc8ed
// 005cc8d3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005cc8d7  8b11                 mov edx, dword ptr [ecx]
// 005cc8d9  8910                 mov dword ptr [eax], edx
// 005cc8db  8b5104               mov edx, dword ptr [ecx + 4]
// 005cc8de  895004               mov dword ptr [eax + 4], edx
// 005cc8e1  8b5108               mov edx, dword ptr [ecx + 8]
// 005cc8e4  895008               mov dword ptr [eax + 8], edx
// 005cc8e7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005cc8ea  89480c               mov dword ptr [eax + 0xc], ecx
// 005cc8ed  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb25cf0 is typeid(F)
extern const type_info type_descriptor_b25cf0;

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
        if (check_type == type_descriptor_b25cf0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b25cf0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
