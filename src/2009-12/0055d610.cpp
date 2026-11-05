// from server: 100% by nuck16
// roc 2009-12 0055d610  unit: RBX::Network::NetworkOwnerJob  size: 110 bytes
//
// 0055d610  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0055d614  33c9                 xor ecx, ecx
// 0055d616  3bc1                 cmp eax, ecx
// 0055d618  7441                 je 0x55d65b
// 0055d61a  83f801               cmp eax, 1
// 0055d61d  743c                 je 0x55d65b
// 0055d61f  83f802               cmp eax, 2
// 0055d622  7459                 je 0x55d67d
// 0055d624  83f803               cmp eax, 3
// 0055d627  7521                 jne 0x55d64a
// 0055d629  56                   push esi
// 0055d62a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0055d62e  8b0e                 mov ecx, dword ptr [esi]
// 0055d630  684803b200           push 0xb20348
// 0055d635  ff1568b79800         call dword ptr [0x98b768]
// 0055d63b  0fb6c0               movzx eax, al
// 0055d63e  f7d8                 neg eax
// 0055d640  1bc0                 sbb eax, eax
// 0055d642  23442408             and eax, dword ptr [esp + 8]
// 0055d646  8906                 mov dword ptr [esi], eax
// 0055d648  5e                   pop esi
// 0055d649  c3                   ret 
// 0055d64a  8b442408             mov eax, dword ptr [esp + 8]
// 0055d64e  c7004803b200         mov dword ptr [eax], 0xb20348
// 0055d654  884804               mov byte ptr [eax + 4], cl
// 0055d657  884805               mov byte ptr [eax + 5], cl
// 0055d65a  c3                   ret 
// 0055d65b  8b442408             mov eax, dword ptr [esp + 8]
// 0055d65f  3bc1                 cmp eax, ecx
// 0055d661  741a                 je 0x55d67d
// 0055d663  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0055d667  8b11                 mov edx, dword ptr [ecx]
// 0055d669  8910                 mov dword ptr [eax], edx
// 0055d66b  8b5104               mov edx, dword ptr [ecx + 4]
// 0055d66e  895004               mov dword ptr [eax + 4], edx
// 0055d671  8b5108               mov edx, dword ptr [ecx + 8]
// 0055d674  895008               mov dword ptr [eax + 8], edx
// 0055d677  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0055d67a  89480c               mov dword ptr [eax + 0xc], ecx
// 0055d67d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb20348 is typeid(F)
extern const type_info type_descriptor_b20348;

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
        if (check_type == type_descriptor_b20348)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b20348;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
