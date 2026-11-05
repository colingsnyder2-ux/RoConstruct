// from server: 100% by nuck16
// roc 2009-12 0046df60  unit: CScriptEditor  size: 98 bytes
//
// 0046df60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046df64  33c9                 xor ecx, ecx
// 0046df66  3bc1                 cmp eax, ecx
// 0046df68  7441                 je 0x46dfab
// 0046df6a  83f801               cmp eax, 1
// 0046df6d  743c                 je 0x46dfab
// 0046df6f  83f802               cmp eax, 2
// 0046df72  744d                 je 0x46dfc1
// 0046df74  83f803               cmp eax, 3
// 0046df77  7521                 jne 0x46df9a
// 0046df79  56                   push esi
// 0046df7a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0046df7e  8b0e                 mov ecx, dword ptr [esi]
// 0046df80  6850b7b000           push 0xb0b750
// 0046df85  ff1568b79800         call dword ptr [0x98b768]
// 0046df8b  0fb6c0               movzx eax, al
// 0046df8e  f7d8                 neg eax
// 0046df90  1bc0                 sbb eax, eax
// 0046df92  23442408             and eax, dword ptr [esp + 8]
// 0046df96  8906                 mov dword ptr [esi], eax
// 0046df98  5e                   pop esi
// 0046df99  c3                   ret 
// 0046df9a  8b442408             mov eax, dword ptr [esp + 8]
// 0046df9e  c70050b7b000         mov dword ptr [eax], 0xb0b750
// 0046dfa4  884804               mov byte ptr [eax + 4], cl
// 0046dfa7  884805               mov byte ptr [eax + 5], cl
// 0046dfaa  c3                   ret 
// 0046dfab  8b442408             mov eax, dword ptr [esp + 8]
// 0046dfaf  3bc1                 cmp eax, ecx
// 0046dfb1  740e                 je 0x46dfc1
// 0046dfb3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0046dfb7  8b11                 mov edx, dword ptr [ecx]
// 0046dfb9  8910                 mov dword ptr [eax], edx
// 0046dfbb  8b4904               mov ecx, dword ptr [ecx + 4]
// 0046dfbe  894804               mov dword ptr [eax + 4], ecx
// 0046dfc1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb0b750 is typeid(F)
extern const type_info type_descriptor_b0b750;

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
        if (check_type == type_descriptor_b0b750)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b0b750;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
