// roc 2012-06 0072b8e0  unit: RBX::Workspace  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0072b8e0
//
// 0072b8e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072b8e4  33c9                 xor ecx, ecx
// 0072b8e6  3bc1                 cmp eax, ecx
// 0072b8e8  7441                 je 0x72b92b
// 0072b8ea  83f801               cmp eax, 1
// 0072b8ed  743c                 je 0x72b92b
// 0072b8ef  83f802               cmp eax, 2
// 0072b8f2  7465                 je 0x72b959
// 0072b8f4  83f803               cmp eax, 3
// 0072b8f7  7521                 jne 0x72b91a
// 0072b8f9  56                   push esi
// 0072b8fa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0072b8fe  8b0e                 mov ecx, dword ptr [esi]
// 0072b900  6860f1da00           push 0xdaf160
// 0072b905  ff15ec29b200         call dword ptr [0xb229ec]
// 0072b90b  0fb6c0               movzx eax, al
// 0072b90e  f7d8                 neg eax
// 0072b910  1bc0                 sbb eax, eax
// 0072b912  23442408             and eax, dword ptr [esp + 8]
// 0072b916  8906                 mov dword ptr [esi], eax
// 0072b918  5e                   pop esi
// 0072b919  c3                   ret 
// 0072b91a  8b442408             mov eax, dword ptr [esp + 8]
// 0072b91e  c70060f1da00         mov dword ptr [eax], 0xdaf160
// 0072b924  884804               mov byte ptr [eax + 4], cl
// 0072b927  884805               mov byte ptr [eax + 5], cl
// 0072b92a  c3                   ret 
// 0072b92b  8b442408             mov eax, dword ptr [esp + 8]
// 0072b92f  3bc1                 cmp eax, ecx
// 0072b931  7426                 je 0x72b959
// 0072b933  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0072b937  8b11                 mov edx, dword ptr [ecx]
// 0072b939  8910                 mov dword ptr [eax], edx
// 0072b93b  8b5104               mov edx, dword ptr [ecx + 4]
// 0072b93e  895004               mov dword ptr [eax + 4], edx
// 0072b941  8b5108               mov edx, dword ptr [ecx + 8]
// 0072b944  895008               mov dword ptr [eax + 8], edx
// 0072b947  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0072b94a  89500c               mov dword ptr [eax + 0xc], edx
// 0072b94d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0072b950  895010               mov dword ptr [eax + 0x10], edx
// 0072b953  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 0072b956  894814               mov dword ptr [eax + 0x14], ecx
// 0072b959  c3                   ret 
// copied from an identical function in another client (function ?manage@@YAXABTfunction_buffer@@AAT1@W4functor_manager_operation_type@@@Z)

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb2f1b0 is typeid(F)
extern const type_info type_descriptor_b2f1b0;

struct Functor
{
    int f0, f1, f2, f3, f4, f5;
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
    char data[24];
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
        if (check_type == type_descriptor_b2f1b0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b2f1b0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}