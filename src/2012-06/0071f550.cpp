// roc 2012-06 0071f550  unit: RBX::PartTool  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071f550
//
// 0071f550  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0071f554  33c9                 xor ecx, ecx
// 0071f556  3bc1                 cmp eax, ecx
// 0071f558  7441                 je 0x71f59b
// 0071f55a  83f801               cmp eax, 1
// 0071f55d  743c                 je 0x71f59b
// 0071f55f  83f802               cmp eax, 2
// 0071f562  7453                 je 0x71f5b7
// 0071f564  83f803               cmp eax, 3
// 0071f567  7521                 jne 0x71f58a
// 0071f569  56                   push esi
// 0071f56a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0071f56e  8b0e                 mov ecx, dword ptr [esi]
// 0071f570  6840dfda00           push 0xdadf40
// 0071f575  ff15ec29b200         call dword ptr [0xb229ec]
// 0071f57b  0fb6c0               movzx eax, al
// 0071f57e  f7d8                 neg eax
// 0071f580  1bc0                 sbb eax, eax
// 0071f582  23442408             and eax, dword ptr [esp + 8]
// 0071f586  8906                 mov dword ptr [esi], eax
// 0071f588  5e                   pop esi
// 0071f589  c3                   ret 
// 0071f58a  8b442408             mov eax, dword ptr [esp + 8]
// 0071f58e  c70040dfda00         mov dword ptr [eax], 0xdadf40
// 0071f594  884804               mov byte ptr [eax + 4], cl
// 0071f597  884805               mov byte ptr [eax + 5], cl
// 0071f59a  c3                   ret 
// 0071f59b  8b442408             mov eax, dword ptr [esp + 8]
// 0071f59f  3bc1                 cmp eax, ecx
// 0071f5a1  7414                 je 0x71f5b7
// 0071f5a3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071f5a7  8b11                 mov edx, dword ptr [ecx]
// 0071f5a9  8910                 mov dword ptr [eax], edx
// 0071f5ab  8b5104               mov edx, dword ptr [ecx + 4]
// 0071f5ae  895004               mov dword ptr [eax + 4], edx
// 0071f5b1  8b4908               mov ecx, dword ptr [ecx + 8]
// 0071f5b4  894808               mov dword ptr [eax + 8], ecx
// 0071f5b7  c3                   ret 
// copied from an identical function in another client (function ?manage@@YAXABTfunction_buffer@@AAT1@W4functor_manager_operation_type@@@Z)

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb38a08 is typeid(F)
extern const type_info type_descriptor_b38a08;

struct Functor
{
    int f0, f1, f2;
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
    char data[12];
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
        if (check_type == type_descriptor_b38a08)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b38a08;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}