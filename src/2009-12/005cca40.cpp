// from server: 100% by nuck16
// roc 2009-12 005cca40  unit: RBX::MeshRefPartAdapter  size: 110 bytes
//
// 005cca40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005cca44  33c9                 xor ecx, ecx
// 005cca46  3bc1                 cmp eax, ecx
// 005cca48  7441                 je 0x5cca8b
// 005cca4a  83f801               cmp eax, 1
// 005cca4d  743c                 je 0x5cca8b
// 005cca4f  83f802               cmp eax, 2
// 005cca52  7459                 je 0x5ccaad
// 005cca54  83f803               cmp eax, 3
// 005cca57  7521                 jne 0x5cca7a
// 005cca59  56                   push esi
// 005cca5a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005cca5e  8b0e                 mov ecx, dword ptr [esi]
// 005cca60  68805fb200           push 0xb25f80
// 005cca65  ff1568b79800         call dword ptr [0x98b768]
// 005cca6b  0fb6c0               movzx eax, al
// 005cca6e  f7d8                 neg eax
// 005cca70  1bc0                 sbb eax, eax
// 005cca72  23442408             and eax, dword ptr [esp + 8]
// 005cca76  8906                 mov dword ptr [esi], eax
// 005cca78  5e                   pop esi
// 005cca79  c3                   ret 
// 005cca7a  8b442408             mov eax, dword ptr [esp + 8]
// 005cca7e  c700805fb200         mov dword ptr [eax], 0xb25f80
// 005cca84  884804               mov byte ptr [eax + 4], cl
// 005cca87  884805               mov byte ptr [eax + 5], cl
// 005cca8a  c3                   ret 
// 005cca8b  8b442408             mov eax, dword ptr [esp + 8]
// 005cca8f  3bc1                 cmp eax, ecx
// 005cca91  741a                 je 0x5ccaad
// 005cca93  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005cca97  8b11                 mov edx, dword ptr [ecx]
// 005cca99  8910                 mov dword ptr [eax], edx
// 005cca9b  8b5104               mov edx, dword ptr [ecx + 4]
// 005cca9e  895004               mov dword ptr [eax + 4], edx
// 005ccaa1  8b5108               mov edx, dword ptr [ecx + 8]
// 005ccaa4  895008               mov dword ptr [eax + 8], edx
// 005ccaa7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005ccaaa  89480c               mov dword ptr [eax + 0xc], ecx
// 005ccaad  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb25f80 is typeid(F)
extern const type_info type_descriptor_b25f80;

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
        if (check_type == type_descriptor_b25f80)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b25f80;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
