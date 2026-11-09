// roc 2012-06 0071f400  unit: RBX::PartTool  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071f400
//
// 0071f400  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0071f404  33c9                 xor ecx, ecx
// 0071f406  3bc1                 cmp eax, ecx
// 0071f408  7441                 je 0x71f44b
// 0071f40a  83f801               cmp eax, 1
// 0071f40d  743c                 je 0x71f44b
// 0071f40f  83f802               cmp eax, 2
// 0071f412  7459                 je 0x71f46d
// 0071f414  83f803               cmp eax, 3
// 0071f417  7521                 jne 0x71f43a
// 0071f419  56                   push esi
// 0071f41a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0071f41e  8b0e                 mov ecx, dword ptr [esi]
// 0071f420  68c8ddda00           push 0xdaddc8
// 0071f425  ff15ec29b200         call dword ptr [0xb229ec]
// 0071f42b  0fb6c0               movzx eax, al
// 0071f42e  f7d8                 neg eax
// 0071f430  1bc0                 sbb eax, eax
// 0071f432  23442408             and eax, dword ptr [esp + 8]
// 0071f436  8906                 mov dword ptr [esi], eax
// 0071f438  5e                   pop esi
// 0071f439  c3                   ret 
// 0071f43a  8b442408             mov eax, dword ptr [esp + 8]
// 0071f43e  c700c8ddda00         mov dword ptr [eax], 0xdaddc8
// 0071f444  884804               mov byte ptr [eax + 4], cl
// 0071f447  884805               mov byte ptr [eax + 5], cl
// 0071f44a  c3                   ret 
// 0071f44b  8b442408             mov eax, dword ptr [esp + 8]
// 0071f44f  3bc1                 cmp eax, ecx
// 0071f451  741a                 je 0x71f46d
// 0071f453  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071f457  8b11                 mov edx, dword ptr [ecx]
// 0071f459  8910                 mov dword ptr [eax], edx
// 0071f45b  8b5104               mov edx, dword ptr [ecx + 4]
// 0071f45e  895004               mov dword ptr [eax + 4], edx
// 0071f461  8b5108               mov edx, dword ptr [ecx + 8]
// 0071f464  895008               mov dword ptr [eax + 8], edx
// 0071f467  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0071f46a  89480c               mov dword ptr [eax + 0xc], ecx
// 0071f46d  c3                   ret 
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