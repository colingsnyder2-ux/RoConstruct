// from server: 100% by nuck16
// roc 2009-12 005cc8f0  unit: RBX::MeshRefPartAdapter  size: 110 bytes
//
// 005cc8f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005cc8f4  33c9                 xor ecx, ecx
// 005cc8f6  3bc1                 cmp eax, ecx
// 005cc8f8  7441                 je 0x5cc93b
// 005cc8fa  83f801               cmp eax, 1
// 005cc8fd  743c                 je 0x5cc93b
// 005cc8ff  83f802               cmp eax, 2
// 005cc902  7459                 je 0x5cc95d
// 005cc904  83f803               cmp eax, 3
// 005cc907  7521                 jne 0x5cc92a
// 005cc909  56                   push esi
// 005cc90a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005cc90e  8b0e                 mov ecx, dword ptr [esi]
// 005cc910  68a05db200           push 0xb25da0
// 005cc915  ff1568b79800         call dword ptr [0x98b768]
// 005cc91b  0fb6c0               movzx eax, al
// 005cc91e  f7d8                 neg eax
// 005cc920  1bc0                 sbb eax, eax
// 005cc922  23442408             and eax, dword ptr [esp + 8]
// 005cc926  8906                 mov dword ptr [esi], eax
// 005cc928  5e                   pop esi
// 005cc929  c3                   ret 
// 005cc92a  8b442408             mov eax, dword ptr [esp + 8]
// 005cc92e  c700a05db200         mov dword ptr [eax], 0xb25da0
// 005cc934  884804               mov byte ptr [eax + 4], cl
// 005cc937  884805               mov byte ptr [eax + 5], cl
// 005cc93a  c3                   ret 
// 005cc93b  8b442408             mov eax, dword ptr [esp + 8]
// 005cc93f  3bc1                 cmp eax, ecx
// 005cc941  741a                 je 0x5cc95d
// 005cc943  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005cc947  8b11                 mov edx, dword ptr [ecx]
// 005cc949  8910                 mov dword ptr [eax], edx
// 005cc94b  8b5104               mov edx, dword ptr [ecx + 4]
// 005cc94e  895004               mov dword ptr [eax + 4], edx
// 005cc951  8b5108               mov edx, dword ptr [ecx + 8]
// 005cc954  895008               mov dword ptr [eax + 8], edx
// 005cc957  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005cc95a  89480c               mov dword ptr [eax + 0xc], ecx
// 005cc95d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb25da0 is typeid(F)
extern const type_info type_descriptor_b25da0;

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
        if (check_type == type_descriptor_b25da0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b25da0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
