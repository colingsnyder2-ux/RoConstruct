// roc 2012-06 006f3760  unit: RBX::SetManualJointToInfinite  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f3760
//
// 006f3760  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f3764  33c9                 xor ecx, ecx
// 006f3766  3bc1                 cmp eax, ecx
// 006f3768  7441                 je 0x6f37ab
// 006f376a  83f801               cmp eax, 1
// 006f376d  743c                 je 0x6f37ab
// 006f376f  83f802               cmp eax, 2
// 006f3772  744d                 je 0x6f37c1
// 006f3774  83f803               cmp eax, 3
// 006f3777  7521                 jne 0x6f379a
// 006f3779  56                   push esi
// 006f377a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006f377e  8b0e                 mov ecx, dword ptr [esi]
// 006f3780  68387cda00           push 0xda7c38
// 006f3785  ff15ec29b200         call dword ptr [0xb229ec]
// 006f378b  0fb6c0               movzx eax, al
// 006f378e  f7d8                 neg eax
// 006f3790  1bc0                 sbb eax, eax
// 006f3792  23442408             and eax, dword ptr [esp + 8]
// 006f3796  8906                 mov dword ptr [esi], eax
// 006f3798  5e                   pop esi
// 006f3799  c3                   ret 
// 006f379a  8b442408             mov eax, dword ptr [esp + 8]
// 006f379e  c700387cda00         mov dword ptr [eax], 0xda7c38
// 006f37a4  884804               mov byte ptr [eax + 4], cl
// 006f37a7  884805               mov byte ptr [eax + 5], cl
// 006f37aa  c3                   ret 
// 006f37ab  8b442408             mov eax, dword ptr [esp + 8]
// 006f37af  3bc1                 cmp eax, ecx
// 006f37b1  740e                 je 0x6f37c1
// 006f37b3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f37b7  8b11                 mov edx, dword ptr [ecx]
// 006f37b9  8910                 mov dword ptr [eax], edx
// 006f37bb  8b4904               mov ecx, dword ptr [ecx + 4]
// 006f37be  894804               mov dword ptr [eax + 4], ecx
// 006f37c1  c3                   ret 
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