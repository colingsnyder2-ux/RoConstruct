// from server: 100% by nuck16
// roc 2009-12 00702e60  unit: RBX::Assembly  size: 110 bytes
//
// 00702e60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00702e64  33c9                 xor ecx, ecx
// 00702e66  3bc1                 cmp eax, ecx
// 00702e68  7441                 je 0x702eab
// 00702e6a  83f801               cmp eax, 1
// 00702e6d  743c                 je 0x702eab
// 00702e6f  83f802               cmp eax, 2
// 00702e72  7459                 je 0x702ecd
// 00702e74  83f803               cmp eax, 3
// 00702e77  7521                 jne 0x702e9a
// 00702e79  56                   push esi
// 00702e7a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00702e7e  8b0e                 mov ecx, dword ptr [esi]
// 00702e80  685091b400           push 0xb49150
// 00702e85  ff1568b79800         call dword ptr [0x98b768]
// 00702e8b  0fb6c0               movzx eax, al
// 00702e8e  f7d8                 neg eax
// 00702e90  1bc0                 sbb eax, eax
// 00702e92  23442408             and eax, dword ptr [esp + 8]
// 00702e96  8906                 mov dword ptr [esi], eax
// 00702e98  5e                   pop esi
// 00702e99  c3                   ret 
// 00702e9a  8b442408             mov eax, dword ptr [esp + 8]
// 00702e9e  c7005091b400         mov dword ptr [eax], 0xb49150
// 00702ea4  884804               mov byte ptr [eax + 4], cl
// 00702ea7  884805               mov byte ptr [eax + 5], cl
// 00702eaa  c3                   ret 
// 00702eab  8b442408             mov eax, dword ptr [esp + 8]
// 00702eaf  3bc1                 cmp eax, ecx
// 00702eb1  741a                 je 0x702ecd
// 00702eb3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00702eb7  8b11                 mov edx, dword ptr [ecx]
// 00702eb9  8910                 mov dword ptr [eax], edx
// 00702ebb  8b5104               mov edx, dword ptr [ecx + 4]
// 00702ebe  895004               mov dword ptr [eax + 4], edx
// 00702ec1  8b5108               mov edx, dword ptr [ecx + 8]
// 00702ec4  895008               mov dword ptr [eax + 8], edx
// 00702ec7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 00702eca  89480c               mov dword ptr [eax + 0xc], ecx
// 00702ecd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb49150 is typeid(F)
extern const type_info type_descriptor_b49150;

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
        if (check_type == type_descriptor_b49150)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b49150;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
