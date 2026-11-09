// from server: 100% by nuck16
// roc 2009-12 004330d0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 98 bytes
//
// 004330d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004330d4  33c9                 xor ecx, ecx
// 004330d6  3bc1                 cmp eax, ecx
// 004330d8  7441                 je 0x43311b
// 004330da  83f801               cmp eax, 1
// 004330dd  743c                 je 0x43311b
// 004330df  83f802               cmp eax, 2
// 004330e2  744d                 je 0x433131
// 004330e4  83f803               cmp eax, 3
// 004330e7  7521                 jne 0x43310a
// 004330e9  56                   push esi
// 004330ea  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004330ee  8b0e                 mov ecx, dword ptr [esi]
// 004330f0  685856b000           push 0xb05658
// 004330f5  ff1568b79800         call dword ptr [0x98b768]
// 004330fb  0fb6c0               movzx eax, al
// 004330fe  f7d8                 neg eax
// 00433100  1bc0                 sbb eax, eax
// 00433102  23442408             and eax, dword ptr [esp + 8]
// 00433106  8906                 mov dword ptr [esi], eax
// 00433108  5e                   pop esi
// 00433109  c3                   ret 
// 0043310a  8b442408             mov eax, dword ptr [esp + 8]
// 0043310e  c7005856b000         mov dword ptr [eax], 0xb05658
// 00433114  884804               mov byte ptr [eax + 4], cl
// 00433117  884805               mov byte ptr [eax + 5], cl
// 0043311a  c3                   ret 
// 0043311b  8b442408             mov eax, dword ptr [esp + 8]
// 0043311f  3bc1                 cmp eax, ecx
// 00433121  740e                 je 0x433131
// 00433123  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00433127  8b11                 mov edx, dword ptr [ecx]
// 00433129  8910                 mov dword ptr [eax], edx
// 0043312b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0043312e  894804               mov dword ptr [eax + 4], ecx
// 00433131  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb05658 is typeid(F)
extern const type_info type_descriptor_b05658;

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
        if (check_type == type_descriptor_b05658)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b05658;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
