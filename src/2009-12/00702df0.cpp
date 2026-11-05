// from server: 100% by nuck16
// roc 2009-12 00702df0  unit: RBX::Assembly  size: 110 bytes
//
// 00702df0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00702df4  33c9                 xor ecx, ecx
// 00702df6  3bc1                 cmp eax, ecx
// 00702df8  7441                 je 0x702e3b
// 00702dfa  83f801               cmp eax, 1
// 00702dfd  743c                 je 0x702e3b
// 00702dff  83f802               cmp eax, 2
// 00702e02  7459                 je 0x702e5d
// 00702e04  83f803               cmp eax, 3
// 00702e07  7521                 jne 0x702e2a
// 00702e09  56                   push esi
// 00702e0a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00702e0e  8b0e                 mov ecx, dword ptr [esi]
// 00702e10  686090b400           push 0xb49060
// 00702e15  ff1568b79800         call dword ptr [0x98b768]
// 00702e1b  0fb6c0               movzx eax, al
// 00702e1e  f7d8                 neg eax
// 00702e20  1bc0                 sbb eax, eax
// 00702e22  23442408             and eax, dword ptr [esp + 8]
// 00702e26  8906                 mov dword ptr [esi], eax
// 00702e28  5e                   pop esi
// 00702e29  c3                   ret 
// 00702e2a  8b442408             mov eax, dword ptr [esp + 8]
// 00702e2e  c7006090b400         mov dword ptr [eax], 0xb49060
// 00702e34  884804               mov byte ptr [eax + 4], cl
// 00702e37  884805               mov byte ptr [eax + 5], cl
// 00702e3a  c3                   ret 
// 00702e3b  8b442408             mov eax, dword ptr [esp + 8]
// 00702e3f  3bc1                 cmp eax, ecx
// 00702e41  741a                 je 0x702e5d
// 00702e43  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00702e47  8b11                 mov edx, dword ptr [ecx]
// 00702e49  8910                 mov dword ptr [eax], edx
// 00702e4b  8b5104               mov edx, dword ptr [ecx + 4]
// 00702e4e  895004               mov dword ptr [eax + 4], edx
// 00702e51  8b5108               mov edx, dword ptr [ecx + 8]
// 00702e54  895008               mov dword ptr [eax + 8], edx
// 00702e57  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 00702e5a  89480c               mov dword ptr [eax + 0xc], ecx
// 00702e5d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb49060 is typeid(F)
extern const type_info type_descriptor_b49060;

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
        if (check_type == type_descriptor_b49060)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b49060;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
