// from server: 100% by nuck16
// roc 2009-12 005380a0  unit: RBX::PAVDebugSettings::?$sp_counted_impl_pd  size: 98 bytes
//
// 005380a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005380a4  33c9                 xor ecx, ecx
// 005380a6  3bc1                 cmp eax, ecx
// 005380a8  7441                 je 0x5380eb
// 005380aa  83f801               cmp eax, 1
// 005380ad  743c                 je 0x5380eb
// 005380af  83f802               cmp eax, 2
// 005380b2  744d                 je 0x538101
// 005380b4  83f803               cmp eax, 3
// 005380b7  7521                 jne 0x5380da
// 005380b9  56                   push esi
// 005380ba  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005380be  8b0e                 mov ecx, dword ptr [esi]
// 005380c0  68b8dbb100           push 0xb1dbb8
// 005380c5  ff1568b79800         call dword ptr [0x98b768]
// 005380cb  0fb6c0               movzx eax, al
// 005380ce  f7d8                 neg eax
// 005380d0  1bc0                 sbb eax, eax
// 005380d2  23442408             and eax, dword ptr [esp + 8]
// 005380d6  8906                 mov dword ptr [esi], eax
// 005380d8  5e                   pop esi
// 005380d9  c3                   ret 
// 005380da  8b442408             mov eax, dword ptr [esp + 8]
// 005380de  c700b8dbb100         mov dword ptr [eax], 0xb1dbb8
// 005380e4  884804               mov byte ptr [eax + 4], cl
// 005380e7  884805               mov byte ptr [eax + 5], cl
// 005380ea  c3                   ret 
// 005380eb  8b442408             mov eax, dword ptr [esp + 8]
// 005380ef  3bc1                 cmp eax, ecx
// 005380f1  740e                 je 0x538101
// 005380f3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005380f7  8b11                 mov edx, dword ptr [ecx]
// 005380f9  8910                 mov dword ptr [eax], edx
// 005380fb  8b4904               mov ecx, dword ptr [ecx + 4]
// 005380fe  894804               mov dword ptr [eax + 4], ecx
// 00538101  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb1dbb8 is typeid(F)
extern const type_info type_descriptor_b1dbb8;

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
        if (check_type == type_descriptor_b1dbb8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b1dbb8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
