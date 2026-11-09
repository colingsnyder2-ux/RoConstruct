// roc 2012-06 008ad640  unit: RBX::Flag  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008ad640
//
// 008ad640  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008ad644  33c9                 xor ecx, ecx
// 008ad646  3bc1                 cmp eax, ecx
// 008ad648  7441                 je 0x8ad68b
// 008ad64a  83f801               cmp eax, 1
// 008ad64d  743c                 je 0x8ad68b
// 008ad64f  83f802               cmp eax, 2
// 008ad652  7459                 je 0x8ad6ad
// 008ad654  83f803               cmp eax, 3
// 008ad657  7521                 jne 0x8ad67a
// 008ad659  56                   push esi
// 008ad65a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008ad65e  8b0e                 mov ecx, dword ptr [esi]
// 008ad660  68e8cfde00           push 0xdecfe8
// 008ad665  ff15ec29b200         call dword ptr [0xb229ec]
// 008ad66b  0fb6c0               movzx eax, al
// 008ad66e  f7d8                 neg eax
// 008ad670  1bc0                 sbb eax, eax
// 008ad672  23442408             and eax, dword ptr [esp + 8]
// 008ad676  8906                 mov dword ptr [esi], eax
// 008ad678  5e                   pop esi
// 008ad679  c3                   ret 
// 008ad67a  8b442408             mov eax, dword ptr [esp + 8]
// 008ad67e  c700e8cfde00         mov dword ptr [eax], 0xdecfe8
// 008ad684  884804               mov byte ptr [eax + 4], cl
// 008ad687  884805               mov byte ptr [eax + 5], cl
// 008ad68a  c3                   ret 
// 008ad68b  8b442408             mov eax, dword ptr [esp + 8]
// 008ad68f  3bc1                 cmp eax, ecx
// 008ad691  741a                 je 0x8ad6ad
// 008ad693  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008ad697  8b11                 mov edx, dword ptr [ecx]
// 008ad699  8910                 mov dword ptr [eax], edx
// 008ad69b  8b5104               mov edx, dword ptr [ecx + 4]
// 008ad69e  895004               mov dword ptr [eax + 4], edx
// 008ad6a1  8b5108               mov edx, dword ptr [ecx + 8]
// 008ad6a4  895008               mov dword ptr [eax + 8], edx
// 008ad6a7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 008ad6aa  89480c               mov dword ptr [eax + 0xc], ecx
// 008ad6ad  c3                   ret 
// copied from an identical function in another client (function ?manage@@YAXABTfunction_buffer@@AAT1@W4functor_manager_operation_type@@@Z)

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb33668 is typeid(F)
extern const type_info type_descriptor_b33668;

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
        if (check_type == type_descriptor_b33668)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b33668;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}