// from server: 100% by nuck16
// roc 2009-12 005dddb0  unit: RBX::ImmediateMeshGenAdapter  size: 98 bytes
//
// 005dddb0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005dddb4  33c9                 xor ecx, ecx
// 005dddb6  3bc1                 cmp eax, ecx
// 005dddb8  7441                 je 0x5dddfb
// 005dddba  83f801               cmp eax, 1
// 005dddbd  743c                 je 0x5dddfb
// 005dddbf  83f802               cmp eax, 2
// 005dddc2  744d                 je 0x5dde11
// 005dddc4  83f803               cmp eax, 3
// 005dddc7  7521                 jne 0x5dddea
// 005dddc9  56                   push esi
// 005dddca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005dddce  8b0e                 mov ecx, dword ptr [esi]
// 005dddd0  68e864b200           push 0xb264e8
// 005dddd5  ff1568b79800         call dword ptr [0x98b768]
// 005ddddb  0fb6c0               movzx eax, al
// 005dddde  f7d8                 neg eax
// 005ddde0  1bc0                 sbb eax, eax
// 005ddde2  23442408             and eax, dword ptr [esp + 8]
// 005ddde6  8906                 mov dword ptr [esi], eax
// 005ddde8  5e                   pop esi
// 005ddde9  c3                   ret 
// 005dddea  8b442408             mov eax, dword ptr [esp + 8]
// 005dddee  c700e864b200         mov dword ptr [eax], 0xb264e8
// 005dddf4  884804               mov byte ptr [eax + 4], cl
// 005dddf7  884805               mov byte ptr [eax + 5], cl
// 005dddfa  c3                   ret 
// 005dddfb  8b442408             mov eax, dword ptr [esp + 8]
// 005dddff  3bc1                 cmp eax, ecx
// 005dde01  740e                 je 0x5dde11
// 005dde03  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005dde07  8b11                 mov edx, dword ptr [ecx]
// 005dde09  8910                 mov dword ptr [eax], edx
// 005dde0b  8b4904               mov ecx, dword ptr [ecx + 4]
// 005dde0e  894804               mov dword ptr [eax + 4], ecx
// 005dde11  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb264e8 is typeid(F)
extern const type_info type_descriptor_b264e8;

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
        if (check_type == type_descriptor_b264e8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b264e8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
