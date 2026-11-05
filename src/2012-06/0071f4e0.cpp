// roc 2012-06 0071f4e0  unit: RBX::PartTool  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071f4e0
//
// 0071f4e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0071f4e4  33c9                 xor ecx, ecx
// 0071f4e6  3bc1                 cmp eax, ecx
// 0071f4e8  7441                 je 0x71f52b
// 0071f4ea  83f801               cmp eax, 1
// 0071f4ed  743c                 je 0x71f52b
// 0071f4ef  83f802               cmp eax, 2
// 0071f4f2  744d                 je 0x71f541
// 0071f4f4  83f803               cmp eax, 3
// 0071f4f7  7521                 jne 0x71f51a
// 0071f4f9  56                   push esi
// 0071f4fa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0071f4fe  8b0e                 mov ecx, dword ptr [esi]
// 0071f500  68c8deda00           push 0xdadec8
// 0071f505  ff15ec29b200         call dword ptr [0xb229ec]
// 0071f50b  0fb6c0               movzx eax, al
// 0071f50e  f7d8                 neg eax
// 0071f510  1bc0                 sbb eax, eax
// 0071f512  23442408             and eax, dword ptr [esp + 8]
// 0071f516  8906                 mov dword ptr [esi], eax
// 0071f518  5e                   pop esi
// 0071f519  c3                   ret 
// 0071f51a  8b442408             mov eax, dword ptr [esp + 8]
// 0071f51e  c700c8deda00         mov dword ptr [eax], 0xdadec8
// 0071f524  884804               mov byte ptr [eax + 4], cl
// 0071f527  884805               mov byte ptr [eax + 5], cl
// 0071f52a  c3                   ret 
// 0071f52b  8b442408             mov eax, dword ptr [esp + 8]
// 0071f52f  3bc1                 cmp eax, ecx
// 0071f531  740e                 je 0x71f541
// 0071f533  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071f537  8b11                 mov edx, dword ptr [ecx]
// 0071f539  8910                 mov dword ptr [eax], edx
// 0071f53b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0071f53e  894804               mov dword ptr [eax + 4], ecx
// 0071f541  c3                   ret 
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