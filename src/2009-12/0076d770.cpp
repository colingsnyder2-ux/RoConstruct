// from server: 100% by nuck16
// roc 2009-12 0076d770  unit: RBX::VFrame::?$FactoryProduct  size: 98 bytes
//
// 0076d770  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076d774  33c9                 xor ecx, ecx
// 0076d776  3bc1                 cmp eax, ecx
// 0076d778  7441                 je 0x76d7bb
// 0076d77a  83f801               cmp eax, 1
// 0076d77d  743c                 je 0x76d7bb
// 0076d77f  83f802               cmp eax, 2
// 0076d782  744d                 je 0x76d7d1
// 0076d784  83f803               cmp eax, 3
// 0076d787  7521                 jne 0x76d7aa
// 0076d789  56                   push esi
// 0076d78a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0076d78e  8b0e                 mov ecx, dword ptr [esi]
// 0076d790  684808b600           push 0xb60848
// 0076d795  ff1568b79800         call dword ptr [0x98b768]
// 0076d79b  0fb6c0               movzx eax, al
// 0076d79e  f7d8                 neg eax
// 0076d7a0  1bc0                 sbb eax, eax
// 0076d7a2  23442408             and eax, dword ptr [esp + 8]
// 0076d7a6  8906                 mov dword ptr [esi], eax
// 0076d7a8  5e                   pop esi
// 0076d7a9  c3                   ret 
// 0076d7aa  8b442408             mov eax, dword ptr [esp + 8]
// 0076d7ae  c7004808b600         mov dword ptr [eax], 0xb60848
// 0076d7b4  884804               mov byte ptr [eax + 4], cl
// 0076d7b7  884805               mov byte ptr [eax + 5], cl
// 0076d7ba  c3                   ret 
// 0076d7bb  8b442408             mov eax, dword ptr [esp + 8]
// 0076d7bf  3bc1                 cmp eax, ecx
// 0076d7c1  740e                 je 0x76d7d1
// 0076d7c3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0076d7c7  8b11                 mov edx, dword ptr [ecx]
// 0076d7c9  8910                 mov dword ptr [eax], edx
// 0076d7cb  8b4904               mov ecx, dword ptr [ecx + 4]
// 0076d7ce  894804               mov dword ptr [eax + 4], ecx
// 0076d7d1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb60848 is typeid(F)
extern const type_info type_descriptor_b60848;

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
        if (check_type == type_descriptor_b60848)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b60848;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
