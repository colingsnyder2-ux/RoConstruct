// from server: 100% by nuck16
// roc 2009-12 006962b0  unit: RBX::Workspace  size: 98 bytes
//
// 006962b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006962b4  33c9                 xor ecx, ecx
// 006962b6  3bc1                 cmp eax, ecx
// 006962b8  7441                 je 0x6962fb
// 006962ba  83f801               cmp eax, 1
// 006962bd  743c                 je 0x6962fb
// 006962bf  83f802               cmp eax, 2
// 006962c2  744d                 je 0x696311
// 006962c4  83f803               cmp eax, 3
// 006962c7  7521                 jne 0x6962ea
// 006962c9  56                   push esi
// 006962ca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006962ce  8b0e                 mov ecx, dword ptr [esi]
// 006962d0  681889b300           push 0xb38918
// 006962d5  ff1568b79800         call dword ptr [0x98b768]
// 006962db  0fb6c0               movzx eax, al
// 006962de  f7d8                 neg eax
// 006962e0  1bc0                 sbb eax, eax
// 006962e2  23442408             and eax, dword ptr [esp + 8]
// 006962e6  8906                 mov dword ptr [esi], eax
// 006962e8  5e                   pop esi
// 006962e9  c3                   ret 
// 006962ea  8b442408             mov eax, dword ptr [esp + 8]
// 006962ee  c7001889b300         mov dword ptr [eax], 0xb38918
// 006962f4  884804               mov byte ptr [eax + 4], cl
// 006962f7  884805               mov byte ptr [eax + 5], cl
// 006962fa  c3                   ret 
// 006962fb  8b442408             mov eax, dword ptr [esp + 8]
// 006962ff  3bc1                 cmp eax, ecx
// 00696301  740e                 je 0x696311
// 00696303  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00696307  8b11                 mov edx, dword ptr [ecx]
// 00696309  8910                 mov dword ptr [eax], edx
// 0069630b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0069630e  894804               mov dword ptr [eax + 4], ecx
// 00696311  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb38918 is typeid(F)
extern const type_info type_descriptor_b38918;

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
        if (check_type == type_descriptor_b38918)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b38918;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
