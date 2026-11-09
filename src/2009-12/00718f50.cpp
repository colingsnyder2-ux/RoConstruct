// from server: 100% by nuck16
// roc 2009-12 00718f50  unit: RBX::VProtectedString::?$TypedPropertyDescriptor  size: 110 bytes
//
// 00718f50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00718f54  33c9                 xor ecx, ecx
// 00718f56  3bc1                 cmp eax, ecx
// 00718f58  7441                 je 0x718f9b
// 00718f5a  83f801               cmp eax, 1
// 00718f5d  743c                 je 0x718f9b
// 00718f5f  83f802               cmp eax, 2
// 00718f62  7459                 je 0x718fbd
// 00718f64  83f803               cmp eax, 3
// 00718f67  7521                 jne 0x718f8a
// 00718f69  56                   push esi
// 00718f6a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00718f6e  8b0e                 mov ecx, dword ptr [esi]
// 00718f70  68d8d2b400           push 0xb4d2d8
// 00718f75  ff1568b79800         call dword ptr [0x98b768]
// 00718f7b  0fb6c0               movzx eax, al
// 00718f7e  f7d8                 neg eax
// 00718f80  1bc0                 sbb eax, eax
// 00718f82  23442408             and eax, dword ptr [esp + 8]
// 00718f86  8906                 mov dword ptr [esi], eax
// 00718f88  5e                   pop esi
// 00718f89  c3                   ret 
// 00718f8a  8b442408             mov eax, dword ptr [esp + 8]
// 00718f8e  c700d8d2b400         mov dword ptr [eax], 0xb4d2d8
// 00718f94  884804               mov byte ptr [eax + 4], cl
// 00718f97  884805               mov byte ptr [eax + 5], cl
// 00718f9a  c3                   ret 
// 00718f9b  8b442408             mov eax, dword ptr [esp + 8]
// 00718f9f  3bc1                 cmp eax, ecx
// 00718fa1  741a                 je 0x718fbd
// 00718fa3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00718fa7  8b11                 mov edx, dword ptr [ecx]
// 00718fa9  8910                 mov dword ptr [eax], edx
// 00718fab  8b5104               mov edx, dword ptr [ecx + 4]
// 00718fae  895004               mov dword ptr [eax + 4], edx
// 00718fb1  8b5108               mov edx, dword ptr [ecx + 8]
// 00718fb4  895008               mov dword ptr [eax + 8], edx
// 00718fb7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 00718fba  89480c               mov dword ptr [eax + 0xc], ecx
// 00718fbd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb4d2d8 is typeid(F)
extern const type_info type_descriptor_b4d2d8;

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
        if (check_type == type_descriptor_b4d2d8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b4d2d8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
