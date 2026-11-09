// from server: 100% by nuck16
// roc 2009-12 005130c0  unit: RBX::Network::Players  size: 110 bytes
//
// 005130c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005130c4  33c9                 xor ecx, ecx
// 005130c6  3bc1                 cmp eax, ecx
// 005130c8  7441                 je 0x51310b
// 005130ca  83f801               cmp eax, 1
// 005130cd  743c                 je 0x51310b
// 005130cf  83f802               cmp eax, 2
// 005130d2  7459                 je 0x51312d
// 005130d4  83f803               cmp eax, 3
// 005130d7  7521                 jne 0x5130fa
// 005130d9  56                   push esi
// 005130da  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005130de  8b0e                 mov ecx, dword ptr [esi]
// 005130e0  683087b100           push 0xb18730
// 005130e5  ff1568b79800         call dword ptr [0x98b768]
// 005130eb  0fb6c0               movzx eax, al
// 005130ee  f7d8                 neg eax
// 005130f0  1bc0                 sbb eax, eax
// 005130f2  23442408             and eax, dword ptr [esp + 8]
// 005130f6  8906                 mov dword ptr [esi], eax
// 005130f8  5e                   pop esi
// 005130f9  c3                   ret 
// 005130fa  8b442408             mov eax, dword ptr [esp + 8]
// 005130fe  c7003087b100         mov dword ptr [eax], 0xb18730
// 00513104  884804               mov byte ptr [eax + 4], cl
// 00513107  884805               mov byte ptr [eax + 5], cl
// 0051310a  c3                   ret 
// 0051310b  8b442408             mov eax, dword ptr [esp + 8]
// 0051310f  3bc1                 cmp eax, ecx
// 00513111  741a                 je 0x51312d
// 00513113  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00513117  8b11                 mov edx, dword ptr [ecx]
// 00513119  8910                 mov dword ptr [eax], edx
// 0051311b  8b5104               mov edx, dword ptr [ecx + 4]
// 0051311e  895004               mov dword ptr [eax + 4], edx
// 00513121  8b5108               mov edx, dword ptr [ecx + 8]
// 00513124  895008               mov dword ptr [eax + 8], edx
// 00513127  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0051312a  89480c               mov dword ptr [eax + 0xc], ecx
// 0051312d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb18730 is typeid(F)
extern const type_info type_descriptor_b18730;

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
        if (check_type == type_descriptor_b18730)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b18730;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
