// from server: 100% by nuck16
// roc 2009-12 005ddd40  unit: RBX::ImmediateMeshGenAdapter  size: 98 bytes
//
// 005ddd40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005ddd44  33c9                 xor ecx, ecx
// 005ddd46  3bc1                 cmp eax, ecx
// 005ddd48  7441                 je 0x5ddd8b
// 005ddd4a  83f801               cmp eax, 1
// 005ddd4d  743c                 je 0x5ddd8b
// 005ddd4f  83f802               cmp eax, 2
// 005ddd52  744d                 je 0x5ddda1
// 005ddd54  83f803               cmp eax, 3
// 005ddd57  7521                 jne 0x5ddd7a
// 005ddd59  56                   push esi
// 005ddd5a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005ddd5e  8b0e                 mov ecx, dword ptr [esi]
// 005ddd60  685864b200           push 0xb26458
// 005ddd65  ff1568b79800         call dword ptr [0x98b768]
// 005ddd6b  0fb6c0               movzx eax, al
// 005ddd6e  f7d8                 neg eax
// 005ddd70  1bc0                 sbb eax, eax
// 005ddd72  23442408             and eax, dword ptr [esp + 8]
// 005ddd76  8906                 mov dword ptr [esi], eax
// 005ddd78  5e                   pop esi
// 005ddd79  c3                   ret 
// 005ddd7a  8b442408             mov eax, dword ptr [esp + 8]
// 005ddd7e  c7005864b200         mov dword ptr [eax], 0xb26458
// 005ddd84  884804               mov byte ptr [eax + 4], cl
// 005ddd87  884805               mov byte ptr [eax + 5], cl
// 005ddd8a  c3                   ret 
// 005ddd8b  8b442408             mov eax, dword ptr [esp + 8]
// 005ddd8f  3bc1                 cmp eax, ecx
// 005ddd91  740e                 je 0x5ddda1
// 005ddd93  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005ddd97  8b11                 mov edx, dword ptr [ecx]
// 005ddd99  8910                 mov dword ptr [eax], edx
// 005ddd9b  8b4904               mov ecx, dword ptr [ecx + 4]
// 005ddd9e  894804               mov dword ptr [eax + 4], ecx
// 005ddda1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb26458 is typeid(F)
extern const type_info type_descriptor_b26458;

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
        if (check_type == type_descriptor_b26458)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b26458;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
