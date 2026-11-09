// roc 2012-06 007e6e20  unit: RBX::GuiTarget  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e6e20
//
// 007e6e20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e6e24  33c9                 xor ecx, ecx
// 007e6e26  3bc1                 cmp eax, ecx
// 007e6e28  7441                 je 0x7e6e6b
// 007e6e2a  83f801               cmp eax, 1
// 007e6e2d  743c                 je 0x7e6e6b
// 007e6e2f  83f802               cmp eax, 2
// 007e6e32  744d                 je 0x7e6e81
// 007e6e34  83f803               cmp eax, 3
// 007e6e37  7521                 jne 0x7e6e5a
// 007e6e39  56                   push esi
// 007e6e3a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007e6e3e  8b0e                 mov ecx, dword ptr [esi]
// 007e6e40  683821dd00           push 0xdd2138
// 007e6e45  ff15ec29b200         call dword ptr [0xb229ec]
// 007e6e4b  0fb6c0               movzx eax, al
// 007e6e4e  f7d8                 neg eax
// 007e6e50  1bc0                 sbb eax, eax
// 007e6e52  23442408             and eax, dword ptr [esp + 8]
// 007e6e56  8906                 mov dword ptr [esi], eax
// 007e6e58  5e                   pop esi
// 007e6e59  c3                   ret 
// 007e6e5a  8b442408             mov eax, dword ptr [esp + 8]
// 007e6e5e  c7003821dd00         mov dword ptr [eax], 0xdd2138
// 007e6e64  884804               mov byte ptr [eax + 4], cl
// 007e6e67  884805               mov byte ptr [eax + 5], cl
// 007e6e6a  c3                   ret 
// 007e6e6b  8b442408             mov eax, dword ptr [esp + 8]
// 007e6e6f  3bc1                 cmp eax, ecx
// 007e6e71  740e                 je 0x7e6e81
// 007e6e73  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e6e77  8b11                 mov edx, dword ptr [ecx]
// 007e6e79  8910                 mov dword ptr [eax], edx
// 007e6e7b  8b4904               mov ecx, dword ptr [ecx + 4]
// 007e6e7e  894804               mov dword ptr [eax + 4], ecx
// 007e6e81  c3                   ret 
// copied from an identical function in another client (function ?manage@@YAXABTfunction_buffer@@AAT1@W4functor_manager_operation_type@@@Z)

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb3346c is typeid(F)
extern const type_info type_descriptor_b3346c;

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
        if (check_type == type_descriptor_b3346c)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b3346c;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}