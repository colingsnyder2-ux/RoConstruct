// from server: 100% by nuck16
// roc 2009-12 005cc9d0  unit: RBX::MeshRefPartAdapter  size: 110 bytes
//
// 005cc9d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005cc9d4  33c9                 xor ecx, ecx
// 005cc9d6  3bc1                 cmp eax, ecx
// 005cc9d8  7441                 je 0x5cca1b
// 005cc9da  83f801               cmp eax, 1
// 005cc9dd  743c                 je 0x5cca1b
// 005cc9df  83f802               cmp eax, 2
// 005cc9e2  7459                 je 0x5cca3d
// 005cc9e4  83f803               cmp eax, 3
// 005cc9e7  7521                 jne 0x5cca0a
// 005cc9e9  56                   push esi
// 005cc9ea  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005cc9ee  8b0e                 mov ecx, dword ptr [esi]
// 005cc9f0  68d05eb200           push 0xb25ed0
// 005cc9f5  ff1568b79800         call dword ptr [0x98b768]
// 005cc9fb  0fb6c0               movzx eax, al
// 005cc9fe  f7d8                 neg eax
// 005cca00  1bc0                 sbb eax, eax
// 005cca02  23442408             and eax, dword ptr [esp + 8]
// 005cca06  8906                 mov dword ptr [esi], eax
// 005cca08  5e                   pop esi
// 005cca09  c3                   ret 
// 005cca0a  8b442408             mov eax, dword ptr [esp + 8]
// 005cca0e  c700d05eb200         mov dword ptr [eax], 0xb25ed0
// 005cca14  884804               mov byte ptr [eax + 4], cl
// 005cca17  884805               mov byte ptr [eax + 5], cl
// 005cca1a  c3                   ret 
// 005cca1b  8b442408             mov eax, dword ptr [esp + 8]
// 005cca1f  3bc1                 cmp eax, ecx
// 005cca21  741a                 je 0x5cca3d
// 005cca23  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005cca27  8b11                 mov edx, dword ptr [ecx]
// 005cca29  8910                 mov dword ptr [eax], edx
// 005cca2b  8b5104               mov edx, dword ptr [ecx + 4]
// 005cca2e  895004               mov dword ptr [eax + 4], edx
// 005cca31  8b5108               mov edx, dword ptr [ecx + 8]
// 005cca34  895008               mov dword ptr [eax + 8], edx
// 005cca37  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005cca3a  89480c               mov dword ptr [eax + 0xc], ecx
// 005cca3d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb25ed0 is typeid(F)
extern const type_info type_descriptor_b25ed0;

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
        if (check_type == type_descriptor_b25ed0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b25ed0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
