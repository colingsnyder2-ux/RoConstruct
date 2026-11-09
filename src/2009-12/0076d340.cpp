// from server: 100% by nuck16
// roc 2009-12 0076d340  unit: RBX::VFrame::?$FactoryProduct  size: 98 bytes
//
// 0076d340  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076d344  33c9                 xor ecx, ecx
// 0076d346  3bc1                 cmp eax, ecx
// 0076d348  7441                 je 0x76d38b
// 0076d34a  83f801               cmp eax, 1
// 0076d34d  743c                 je 0x76d38b
// 0076d34f  83f802               cmp eax, 2
// 0076d352  744d                 je 0x76d3a1
// 0076d354  83f803               cmp eax, 3
// 0076d357  7521                 jne 0x76d37a
// 0076d359  56                   push esi
// 0076d35a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0076d35e  8b0e                 mov ecx, dword ptr [esi]
// 0076d360  68e000b600           push 0xb600e0
// 0076d365  ff1568b79800         call dword ptr [0x98b768]
// 0076d36b  0fb6c0               movzx eax, al
// 0076d36e  f7d8                 neg eax
// 0076d370  1bc0                 sbb eax, eax
// 0076d372  23442408             and eax, dword ptr [esp + 8]
// 0076d376  8906                 mov dword ptr [esi], eax
// 0076d378  5e                   pop esi
// 0076d379  c3                   ret 
// 0076d37a  8b442408             mov eax, dword ptr [esp + 8]
// 0076d37e  c700e000b600         mov dword ptr [eax], 0xb600e0
// 0076d384  884804               mov byte ptr [eax + 4], cl
// 0076d387  884805               mov byte ptr [eax + 5], cl
// 0076d38a  c3                   ret 
// 0076d38b  8b442408             mov eax, dword ptr [esp + 8]
// 0076d38f  3bc1                 cmp eax, ecx
// 0076d391  740e                 je 0x76d3a1
// 0076d393  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0076d397  8b11                 mov edx, dword ptr [ecx]
// 0076d399  8910                 mov dword ptr [eax], edx
// 0076d39b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0076d39e  894804               mov dword ptr [eax + 4], ecx
// 0076d3a1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb600e0 is typeid(F)
extern const type_info type_descriptor_b600e0;

struct Functor
{
    int f0, f1;
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
    char data[8];
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
        if (check_type == type_descriptor_b600e0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b600e0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
