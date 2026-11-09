// from server: 100% by nuck16
// roc 2009-12 00741cf0  unit: RBX::DebrisService  size: 110 bytes
//
// 00741cf0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00741cf4  33c9                 xor ecx, ecx
// 00741cf6  3bc1                 cmp eax, ecx
// 00741cf8  7441                 je 0x741d3b
// 00741cfa  83f801               cmp eax, 1
// 00741cfd  743c                 je 0x741d3b
// 00741cff  83f802               cmp eax, 2
// 00741d02  7459                 je 0x741d5d
// 00741d04  83f803               cmp eax, 3
// 00741d07  7521                 jne 0x741d2a
// 00741d09  56                   push esi
// 00741d0a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00741d0e  8b0e                 mov ecx, dword ptr [esi]
// 00741d10  68204fb500           push 0xb54f20
// 00741d15  ff1568b79800         call dword ptr [0x98b768]
// 00741d1b  0fb6c0               movzx eax, al
// 00741d1e  f7d8                 neg eax
// 00741d20  1bc0                 sbb eax, eax
// 00741d22  23442408             and eax, dword ptr [esp + 8]
// 00741d26  8906                 mov dword ptr [esi], eax
// 00741d28  5e                   pop esi
// 00741d29  c3                   ret 
// 00741d2a  8b442408             mov eax, dword ptr [esp + 8]
// 00741d2e  c700204fb500         mov dword ptr [eax], 0xb54f20
// 00741d34  884804               mov byte ptr [eax + 4], cl
// 00741d37  884805               mov byte ptr [eax + 5], cl
// 00741d3a  c3                   ret 
// 00741d3b  8b442408             mov eax, dword ptr [esp + 8]
// 00741d3f  3bc1                 cmp eax, ecx
// 00741d41  741a                 je 0x741d5d
// 00741d43  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00741d47  8b11                 mov edx, dword ptr [ecx]
// 00741d49  8910                 mov dword ptr [eax], edx
// 00741d4b  8b5104               mov edx, dword ptr [ecx + 4]
// 00741d4e  895004               mov dword ptr [eax + 4], edx
// 00741d51  8b5108               mov edx, dword ptr [ecx + 8]
// 00741d54  895008               mov dword ptr [eax + 8], edx
// 00741d57  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 00741d5a  89480c               mov dword ptr [eax + 0xc], ecx
// 00741d5d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb54f20 is typeid(F)
extern const type_info type_descriptor_b54f20;

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
        if (check_type == type_descriptor_b54f20)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b54f20;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
