// from server: 100% by nuck16
// roc 2009-12 005cc810  unit: RBX::MeshRefPartAdapter  size: 110 bytes
//
// 005cc810  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005cc814  33c9                 xor ecx, ecx
// 005cc816  3bc1                 cmp eax, ecx
// 005cc818  7441                 je 0x5cc85b
// 005cc81a  83f801               cmp eax, 1
// 005cc81d  743c                 je 0x5cc85b
// 005cc81f  83f802               cmp eax, 2
// 005cc822  7459                 je 0x5cc87d
// 005cc824  83f803               cmp eax, 3
// 005cc827  7521                 jne 0x5cc84a
// 005cc829  56                   push esi
// 005cc82a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005cc82e  8b0e                 mov ecx, dword ptr [esi]
// 005cc830  68385cb200           push 0xb25c38
// 005cc835  ff1568b79800         call dword ptr [0x98b768]
// 005cc83b  0fb6c0               movzx eax, al
// 005cc83e  f7d8                 neg eax
// 005cc840  1bc0                 sbb eax, eax
// 005cc842  23442408             and eax, dword ptr [esp + 8]
// 005cc846  8906                 mov dword ptr [esi], eax
// 005cc848  5e                   pop esi
// 005cc849  c3                   ret 
// 005cc84a  8b442408             mov eax, dword ptr [esp + 8]
// 005cc84e  c700385cb200         mov dword ptr [eax], 0xb25c38
// 005cc854  884804               mov byte ptr [eax + 4], cl
// 005cc857  884805               mov byte ptr [eax + 5], cl
// 005cc85a  c3                   ret 
// 005cc85b  8b442408             mov eax, dword ptr [esp + 8]
// 005cc85f  3bc1                 cmp eax, ecx
// 005cc861  741a                 je 0x5cc87d
// 005cc863  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005cc867  8b11                 mov edx, dword ptr [ecx]
// 005cc869  8910                 mov dword ptr [eax], edx
// 005cc86b  8b5104               mov edx, dword ptr [ecx + 4]
// 005cc86e  895004               mov dword ptr [eax + 4], edx
// 005cc871  8b5108               mov edx, dword ptr [ecx + 8]
// 005cc874  895008               mov dword ptr [eax + 8], edx
// 005cc877  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005cc87a  89480c               mov dword ptr [eax + 0xc], ecx
// 005cc87d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb25c38 is typeid(F)
extern const type_info type_descriptor_b25c38;

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
        if (check_type == type_descriptor_b25c38)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b25c38;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
