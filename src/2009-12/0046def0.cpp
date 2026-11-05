// from server: 100% by nuck16
// roc 2009-12 0046def0  unit: CScriptEditor  size: 98 bytes
//
// 0046def0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046def4  33c9                 xor ecx, ecx
// 0046def6  3bc1                 cmp eax, ecx
// 0046def8  7441                 je 0x46df3b
// 0046defa  83f801               cmp eax, 1
// 0046defd  743c                 je 0x46df3b
// 0046deff  83f802               cmp eax, 2
// 0046df02  744d                 je 0x46df51
// 0046df04  83f803               cmp eax, 3
// 0046df07  7521                 jne 0x46df2a
// 0046df09  56                   push esi
// 0046df0a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0046df0e  8b0e                 mov ecx, dword ptr [esi]
// 0046df10  6898b6b000           push 0xb0b698
// 0046df15  ff1568b79800         call dword ptr [0x98b768]
// 0046df1b  0fb6c0               movzx eax, al
// 0046df1e  f7d8                 neg eax
// 0046df20  1bc0                 sbb eax, eax
// 0046df22  23442408             and eax, dword ptr [esp + 8]
// 0046df26  8906                 mov dword ptr [esi], eax
// 0046df28  5e                   pop esi
// 0046df29  c3                   ret 
// 0046df2a  8b442408             mov eax, dword ptr [esp + 8]
// 0046df2e  c70098b6b000         mov dword ptr [eax], 0xb0b698
// 0046df34  884804               mov byte ptr [eax + 4], cl
// 0046df37  884805               mov byte ptr [eax + 5], cl
// 0046df3a  c3                   ret 
// 0046df3b  8b442408             mov eax, dword ptr [esp + 8]
// 0046df3f  3bc1                 cmp eax, ecx
// 0046df41  740e                 je 0x46df51
// 0046df43  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0046df47  8b11                 mov edx, dword ptr [ecx]
// 0046df49  8910                 mov dword ptr [eax], edx
// 0046df4b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0046df4e  894804               mov dword ptr [eax + 4], ecx
// 0046df51  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb0b698 is typeid(F)
extern const type_info type_descriptor_b0b698;

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
        if (check_type == type_descriptor_b0b698)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b0b698;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
