// from server: 100% by nuck16
// roc 2009-12 007474e0  unit: RBX::Handles  size: 98 bytes
//
// 007474e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007474e4  33c9                 xor ecx, ecx
// 007474e6  3bc1                 cmp eax, ecx
// 007474e8  7441                 je 0x74752b
// 007474ea  83f801               cmp eax, 1
// 007474ed  743c                 je 0x74752b
// 007474ef  83f802               cmp eax, 2
// 007474f2  744d                 je 0x747541
// 007474f4  83f803               cmp eax, 3
// 007474f7  7521                 jne 0x74751a
// 007474f9  56                   push esi
// 007474fa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007474fe  8b0e                 mov ecx, dword ptr [esi]
// 00747500  68e068b500           push 0xb568e0
// 00747505  ff1568b79800         call dword ptr [0x98b768]
// 0074750b  0fb6c0               movzx eax, al
// 0074750e  f7d8                 neg eax
// 00747510  1bc0                 sbb eax, eax
// 00747512  23442408             and eax, dword ptr [esp + 8]
// 00747516  8906                 mov dword ptr [esi], eax
// 00747518  5e                   pop esi
// 00747519  c3                   ret 
// 0074751a  8b442408             mov eax, dword ptr [esp + 8]
// 0074751e  c700e068b500         mov dword ptr [eax], 0xb568e0
// 00747524  884804               mov byte ptr [eax + 4], cl
// 00747527  884805               mov byte ptr [eax + 5], cl
// 0074752a  c3                   ret 
// 0074752b  8b442408             mov eax, dword ptr [esp + 8]
// 0074752f  3bc1                 cmp eax, ecx
// 00747531  740e                 je 0x747541
// 00747533  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00747537  8b11                 mov edx, dword ptr [ecx]
// 00747539  8910                 mov dword ptr [eax], edx
// 0074753b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0074753e  894804               mov dword ptr [eax + 4], ecx
// 00747541  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb568e0 is typeid(F)
extern const type_info type_descriptor_b568e0;

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
        if (check_type == type_descriptor_b568e0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b568e0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
