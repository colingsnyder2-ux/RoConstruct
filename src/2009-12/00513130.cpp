// from server: 100% by nuck16
// roc 2009-12 00513130  unit: RBX::Network::Players  size: 122 bytes
//
// 00513130  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00513134  33c9                 xor ecx, ecx
// 00513136  3bc1                 cmp eax, ecx
// 00513138  7441                 je 0x51317b
// 0051313a  83f801               cmp eax, 1
// 0051313d  743c                 je 0x51317b
// 0051313f  83f802               cmp eax, 2
// 00513142  7465                 je 0x5131a9
// 00513144  83f803               cmp eax, 3
// 00513147  7521                 jne 0x51316a
// 00513149  56                   push esi
// 0051314a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0051314e  8b0e                 mov ecx, dword ptr [esi]
// 00513150  680088b100           push 0xb18800
// 00513155  ff1568b79800         call dword ptr [0x98b768]
// 0051315b  0fb6c0               movzx eax, al
// 0051315e  f7d8                 neg eax
// 00513160  1bc0                 sbb eax, eax
// 00513162  23442408             and eax, dword ptr [esp + 8]
// 00513166  8906                 mov dword ptr [esi], eax
// 00513168  5e                   pop esi
// 00513169  c3                   ret 
// 0051316a  8b442408             mov eax, dword ptr [esp + 8]
// 0051316e  c7000088b100         mov dword ptr [eax], 0xb18800
// 00513174  884804               mov byte ptr [eax + 4], cl
// 00513177  884805               mov byte ptr [eax + 5], cl
// 0051317a  c3                   ret 
// 0051317b  8b442408             mov eax, dword ptr [esp + 8]
// 0051317f  3bc1                 cmp eax, ecx
// 00513181  7426                 je 0x5131a9
// 00513183  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00513187  8b11                 mov edx, dword ptr [ecx]
// 00513189  8910                 mov dword ptr [eax], edx
// 0051318b  8b5104               mov edx, dword ptr [ecx + 4]
// 0051318e  895004               mov dword ptr [eax + 4], edx
// 00513191  8b5108               mov edx, dword ptr [ecx + 8]
// 00513194  895008               mov dword ptr [eax + 8], edx
// 00513197  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0051319a  89500c               mov dword ptr [eax + 0xc], edx
// 0051319d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 005131a0  895010               mov dword ptr [eax + 0x10], edx
// 005131a3  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 005131a6  894814               mov dword ptr [eax + 0x14], ecx
// 005131a9  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb18800 is typeid(F)
extern const type_info type_descriptor_b18800;

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
        if (check_type == type_descriptor_b18800)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b18800;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
