// from server: 100% by nuck16
// roc 2009-12 00696470  unit: RBX::Workspace  size: 122 bytes
//
// 00696470  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00696474  33c9                 xor ecx, ecx
// 00696476  3bc1                 cmp eax, ecx
// 00696478  7441                 je 0x6964bb
// 0069647a  83f801               cmp eax, 1
// 0069647d  743c                 je 0x6964bb
// 0069647f  83f802               cmp eax, 2
// 00696482  7465                 je 0x6964e9
// 00696484  83f803               cmp eax, 3
// 00696487  7521                 jne 0x6964aa
// 00696489  56                   push esi
// 0069648a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0069648e  8b0e                 mov ecx, dword ptr [esi]
// 00696490  68488bb300           push 0xb38b48
// 00696495  ff1568b79800         call dword ptr [0x98b768]
// 0069649b  0fb6c0               movzx eax, al
// 0069649e  f7d8                 neg eax
// 006964a0  1bc0                 sbb eax, eax
// 006964a2  23442408             and eax, dword ptr [esp + 8]
// 006964a6  8906                 mov dword ptr [esi], eax
// 006964a8  5e                   pop esi
// 006964a9  c3                   ret 
// 006964aa  8b442408             mov eax, dword ptr [esp + 8]
// 006964ae  c700488bb300         mov dword ptr [eax], 0xb38b48
// 006964b4  884804               mov byte ptr [eax + 4], cl
// 006964b7  884805               mov byte ptr [eax + 5], cl
// 006964ba  c3                   ret 
// 006964bb  8b442408             mov eax, dword ptr [esp + 8]
// 006964bf  3bc1                 cmp eax, ecx
// 006964c1  7426                 je 0x6964e9
// 006964c3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006964c7  8b11                 mov edx, dword ptr [ecx]
// 006964c9  8910                 mov dword ptr [eax], edx
// 006964cb  8b5104               mov edx, dword ptr [ecx + 4]
// 006964ce  895004               mov dword ptr [eax + 4], edx
// 006964d1  8b5108               mov edx, dword ptr [ecx + 8]
// 006964d4  895008               mov dword ptr [eax + 8], edx
// 006964d7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 006964da  89500c               mov dword ptr [eax + 0xc], edx
// 006964dd  8b5110               mov edx, dword ptr [ecx + 0x10]
// 006964e0  895010               mov dword ptr [eax + 0x10], edx
// 006964e3  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 006964e6  894814               mov dword ptr [eax + 0x14], ecx
// 006964e9  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb38b48 is typeid(F)
extern const type_info type_descriptor_b38b48;

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
        if (check_type == type_descriptor_b38b48)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b38b48;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
