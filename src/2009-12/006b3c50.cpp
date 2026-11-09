// from server: 100% by nuck16
// roc 2009-12 006b3c50  unit: RBX::DropperTool  size: 110 bytes
//
// 006b3c50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b3c54  33c9                 xor ecx, ecx
// 006b3c56  3bc1                 cmp eax, ecx
// 006b3c58  7441                 je 0x6b3c9b
// 006b3c5a  83f801               cmp eax, 1
// 006b3c5d  743c                 je 0x6b3c9b
// 006b3c5f  83f802               cmp eax, 2
// 006b3c62  7459                 je 0x6b3cbd
// 006b3c64  83f803               cmp eax, 3
// 006b3c67  7521                 jne 0x6b3c8a
// 006b3c69  56                   push esi
// 006b3c6a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006b3c6e  8b0e                 mov ecx, dword ptr [esi]
// 006b3c70  6850abb300           push 0xb3ab50
// 006b3c75  ff1568b79800         call dword ptr [0x98b768]
// 006b3c7b  0fb6c0               movzx eax, al
// 006b3c7e  f7d8                 neg eax
// 006b3c80  1bc0                 sbb eax, eax
// 006b3c82  23442408             and eax, dword ptr [esp + 8]
// 006b3c86  8906                 mov dword ptr [esi], eax
// 006b3c88  5e                   pop esi
// 006b3c89  c3                   ret 
// 006b3c8a  8b442408             mov eax, dword ptr [esp + 8]
// 006b3c8e  c70050abb300         mov dword ptr [eax], 0xb3ab50
// 006b3c94  884804               mov byte ptr [eax + 4], cl
// 006b3c97  884805               mov byte ptr [eax + 5], cl
// 006b3c9a  c3                   ret 
// 006b3c9b  8b442408             mov eax, dword ptr [esp + 8]
// 006b3c9f  3bc1                 cmp eax, ecx
// 006b3ca1  741a                 je 0x6b3cbd
// 006b3ca3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b3ca7  8b11                 mov edx, dword ptr [ecx]
// 006b3ca9  8910                 mov dword ptr [eax], edx
// 006b3cab  8b5104               mov edx, dword ptr [ecx + 4]
// 006b3cae  895004               mov dword ptr [eax + 4], edx
// 006b3cb1  8b5108               mov edx, dword ptr [ecx + 8]
// 006b3cb4  895008               mov dword ptr [eax + 8], edx
// 006b3cb7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 006b3cba  89480c               mov dword ptr [eax + 0xc], ecx
// 006b3cbd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb3ab50 is typeid(F)
extern const type_info type_descriptor_b3ab50;

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
        if (check_type == type_descriptor_b3ab50)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b3ab50;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
