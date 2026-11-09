// roc 2012-06 0071f630  unit: RBX::PartTool  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071f630
//
// 0071f630  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0071f634  33c9                 xor ecx, ecx
// 0071f636  3bc1                 cmp eax, ecx
// 0071f638  7441                 je 0x71f67b
// 0071f63a  83f801               cmp eax, 1
// 0071f63d  743c                 je 0x71f67b
// 0071f63f  83f802               cmp eax, 2
// 0071f642  7465                 je 0x71f6a9
// 0071f644  83f803               cmp eax, 3
// 0071f647  7521                 jne 0x71f66a
// 0071f649  56                   push esi
// 0071f64a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0071f64e  8b0e                 mov ecx, dword ptr [esi]
// 0071f650  6880e0da00           push 0xdae080
// 0071f655  ff15ec29b200         call dword ptr [0xb229ec]
// 0071f65b  0fb6c0               movzx eax, al
// 0071f65e  f7d8                 neg eax
// 0071f660  1bc0                 sbb eax, eax
// 0071f662  23442408             and eax, dword ptr [esp + 8]
// 0071f666  8906                 mov dword ptr [esi], eax
// 0071f668  5e                   pop esi
// 0071f669  c3                   ret 
// 0071f66a  8b442408             mov eax, dword ptr [esp + 8]
// 0071f66e  c70080e0da00         mov dword ptr [eax], 0xdae080
// 0071f674  884804               mov byte ptr [eax + 4], cl
// 0071f677  884805               mov byte ptr [eax + 5], cl
// 0071f67a  c3                   ret 
// 0071f67b  8b442408             mov eax, dword ptr [esp + 8]
// 0071f67f  3bc1                 cmp eax, ecx
// 0071f681  7426                 je 0x71f6a9
// 0071f683  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071f687  8b11                 mov edx, dword ptr [ecx]
// 0071f689  8910                 mov dword ptr [eax], edx
// 0071f68b  8b5104               mov edx, dword ptr [ecx + 4]
// 0071f68e  895004               mov dword ptr [eax + 4], edx
// 0071f691  8b5108               mov edx, dword ptr [ecx + 8]
// 0071f694  895008               mov dword ptr [eax + 8], edx
// 0071f697  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0071f69a  89500c               mov dword ptr [eax + 0xc], edx
// 0071f69d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0071f6a0  895010               mov dword ptr [eax + 0x10], edx
// 0071f6a3  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 0071f6a6  894814               mov dword ptr [eax + 0x14], ecx
// 0071f6a9  c3                   ret 
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