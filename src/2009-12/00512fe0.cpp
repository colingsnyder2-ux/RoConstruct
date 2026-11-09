// from server: 100% by nuck16
// roc 2009-12 00512fe0  unit: RBX::Network::Players  size: 110 bytes
//
// 00512fe0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00512fe4  33c9                 xor ecx, ecx
// 00512fe6  3bc1                 cmp eax, ecx
// 00512fe8  7441                 je 0x51302b
// 00512fea  83f801               cmp eax, 1
// 00512fed  743c                 je 0x51302b
// 00512fef  83f802               cmp eax, 2
// 00512ff2  7459                 je 0x51304d
// 00512ff4  83f803               cmp eax, 3
// 00512ff7  7521                 jne 0x51301a
// 00512ff9  56                   push esi
// 00512ffa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00512ffe  8b0e                 mov ecx, dword ptr [esi]
// 00513000  689085b100           push 0xb18590
// 00513005  ff1568b79800         call dword ptr [0x98b768]
// 0051300b  0fb6c0               movzx eax, al
// 0051300e  f7d8                 neg eax
// 00513010  1bc0                 sbb eax, eax
// 00513012  23442408             and eax, dword ptr [esp + 8]
// 00513016  8906                 mov dword ptr [esi], eax
// 00513018  5e                   pop esi
// 00513019  c3                   ret 
// 0051301a  8b442408             mov eax, dword ptr [esp + 8]
// 0051301e  c7009085b100         mov dword ptr [eax], 0xb18590
// 00513024  884804               mov byte ptr [eax + 4], cl
// 00513027  884805               mov byte ptr [eax + 5], cl
// 0051302a  c3                   ret 
// 0051302b  8b442408             mov eax, dword ptr [esp + 8]
// 0051302f  3bc1                 cmp eax, ecx
// 00513031  741a                 je 0x51304d
// 00513033  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00513037  8b11                 mov edx, dword ptr [ecx]
// 00513039  8910                 mov dword ptr [eax], edx
// 0051303b  8b5104               mov edx, dword ptr [ecx + 4]
// 0051303e  895004               mov dword ptr [eax + 4], edx
// 00513041  8b5108               mov edx, dword ptr [ecx + 8]
// 00513044  895008               mov dword ptr [eax + 8], edx
// 00513047  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0051304a  89480c               mov dword ptr [eax + 0xc], ecx
// 0051304d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb18590 is typeid(F)
extern const type_info type_descriptor_b18590;

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
        if (check_type == type_descriptor_b18590)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b18590;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
