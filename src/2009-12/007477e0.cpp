// from server: 100% by nuck16
// roc 2009-12 007477e0  unit: RBX::Handles  size: 98 bytes
//
// 007477e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007477e4  33c9                 xor ecx, ecx
// 007477e6  3bc1                 cmp eax, ecx
// 007477e8  7441                 je 0x74782b
// 007477ea  83f801               cmp eax, 1
// 007477ed  743c                 je 0x74782b
// 007477ef  83f802               cmp eax, 2
// 007477f2  744d                 je 0x747841
// 007477f4  83f803               cmp eax, 3
// 007477f7  7521                 jne 0x74781a
// 007477f9  56                   push esi
// 007477fa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007477fe  8b0e                 mov ecx, dword ptr [esi]
// 00747800  68a86fb500           push 0xb56fa8
// 00747805  ff1568b79800         call dword ptr [0x98b768]
// 0074780b  0fb6c0               movzx eax, al
// 0074780e  f7d8                 neg eax
// 00747810  1bc0                 sbb eax, eax
// 00747812  23442408             and eax, dword ptr [esp + 8]
// 00747816  8906                 mov dword ptr [esi], eax
// 00747818  5e                   pop esi
// 00747819  c3                   ret 
// 0074781a  8b442408             mov eax, dword ptr [esp + 8]
// 0074781e  c700a86fb500         mov dword ptr [eax], 0xb56fa8
// 00747824  884804               mov byte ptr [eax + 4], cl
// 00747827  884805               mov byte ptr [eax + 5], cl
// 0074782a  c3                   ret 
// 0074782b  8b442408             mov eax, dword ptr [esp + 8]
// 0074782f  3bc1                 cmp eax, ecx
// 00747831  740e                 je 0x747841
// 00747833  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00747837  8b11                 mov edx, dword ptr [ecx]
// 00747839  8910                 mov dword ptr [eax], edx
// 0074783b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0074783e  894804               mov dword ptr [eax + 4], ecx
// 00747841  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb56fa8 is typeid(F)
extern const type_info type_descriptor_b56fa8;

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
        if (check_type == type_descriptor_b56fa8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b56fa8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
