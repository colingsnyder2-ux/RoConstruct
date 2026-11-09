// from server: 100% by nuck16
// roc 2009-12 00513050  unit: RBX::Network::Players  size: 110 bytes
//
// 00513050  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00513054  33c9                 xor ecx, ecx
// 00513056  3bc1                 cmp eax, ecx
// 00513058  7441                 je 0x51309b
// 0051305a  83f801               cmp eax, 1
// 0051305d  743c                 je 0x51309b
// 0051305f  83f802               cmp eax, 2
// 00513062  7459                 je 0x5130bd
// 00513064  83f803               cmp eax, 3
// 00513067  7521                 jne 0x51308a
// 00513069  56                   push esi
// 0051306a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0051306e  8b0e                 mov ecx, dword ptr [esi]
// 00513070  689086b100           push 0xb18690
// 00513075  ff1568b79800         call dword ptr [0x98b768]
// 0051307b  0fb6c0               movzx eax, al
// 0051307e  f7d8                 neg eax
// 00513080  1bc0                 sbb eax, eax
// 00513082  23442408             and eax, dword ptr [esp + 8]
// 00513086  8906                 mov dword ptr [esi], eax
// 00513088  5e                   pop esi
// 00513089  c3                   ret 
// 0051308a  8b442408             mov eax, dword ptr [esp + 8]
// 0051308e  c7009086b100         mov dword ptr [eax], 0xb18690
// 00513094  884804               mov byte ptr [eax + 4], cl
// 00513097  884805               mov byte ptr [eax + 5], cl
// 0051309a  c3                   ret 
// 0051309b  8b442408             mov eax, dword ptr [esp + 8]
// 0051309f  3bc1                 cmp eax, ecx
// 005130a1  741a                 je 0x5130bd
// 005130a3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005130a7  8b11                 mov edx, dword ptr [ecx]
// 005130a9  8910                 mov dword ptr [eax], edx
// 005130ab  8b5104               mov edx, dword ptr [ecx + 4]
// 005130ae  895004               mov dword ptr [eax + 4], edx
// 005130b1  8b5108               mov edx, dword ptr [ecx + 8]
// 005130b4  895008               mov dword ptr [eax + 8], edx
// 005130b7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005130ba  89480c               mov dword ptr [eax + 0xc], ecx
// 005130bd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb18690 is typeid(F)
extern const type_info type_descriptor_b18690;

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
        if (check_type == type_descriptor_b18690)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b18690;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
