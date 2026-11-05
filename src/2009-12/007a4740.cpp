// from server: 100% by nuck16
// roc 2009-12 007a4740  unit: seg_007a0000  size: 98 bytes
//
// 007a4740  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007a4744  33c9                 xor ecx, ecx
// 007a4746  3bc1                 cmp eax, ecx
// 007a4748  7441                 je 0x7a478b
// 007a474a  83f801               cmp eax, 1
// 007a474d  743c                 je 0x7a478b
// 007a474f  83f802               cmp eax, 2
// 007a4752  744d                 je 0x7a47a1
// 007a4754  83f803               cmp eax, 3
// 007a4757  7521                 jne 0x7a477a
// 007a4759  56                   push esi
// 007a475a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007a475e  8b0e                 mov ecx, dword ptr [esi]
// 007a4760  68a82eb600           push 0xb62ea8
// 007a4765  ff1568b79800         call dword ptr [0x98b768]
// 007a476b  0fb6c0               movzx eax, al
// 007a476e  f7d8                 neg eax
// 007a4770  1bc0                 sbb eax, eax
// 007a4772  23442408             and eax, dword ptr [esp + 8]
// 007a4776  8906                 mov dword ptr [esi], eax
// 007a4778  5e                   pop esi
// 007a4779  c3                   ret 
// 007a477a  8b442408             mov eax, dword ptr [esp + 8]
// 007a477e  c700a82eb600         mov dword ptr [eax], 0xb62ea8
// 007a4784  884804               mov byte ptr [eax + 4], cl
// 007a4787  884805               mov byte ptr [eax + 5], cl
// 007a478a  c3                   ret 
// 007a478b  8b442408             mov eax, dword ptr [esp + 8]
// 007a478f  3bc1                 cmp eax, ecx
// 007a4791  740e                 je 0x7a47a1
// 007a4793  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007a4797  8b11                 mov edx, dword ptr [ecx]
// 007a4799  8910                 mov dword ptr [eax], edx
// 007a479b  8b4904               mov ecx, dword ptr [ecx + 4]
// 007a479e  894804               mov dword ptr [eax + 4], ecx
// 007a47a1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb62ea8 is typeid(F)
extern const type_info type_descriptor_b62ea8;

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
        if (check_type == type_descriptor_b62ea8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b62ea8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
