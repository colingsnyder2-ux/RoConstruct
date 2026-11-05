// from server: 100% by nuck16
// roc 2009-12 00575020  unit: RBX::ViewRbxGfx  size: 98 bytes
//
// 00575020  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00575024  33c9                 xor ecx, ecx
// 00575026  3bc1                 cmp eax, ecx
// 00575028  7441                 je 0x57506b
// 0057502a  83f801               cmp eax, 1
// 0057502d  743c                 je 0x57506b
// 0057502f  83f802               cmp eax, 2
// 00575032  744d                 je 0x575081
// 00575034  83f803               cmp eax, 3
// 00575037  7521                 jne 0x57505a
// 00575039  56                   push esi
// 0057503a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0057503e  8b0e                 mov ecx, dword ptr [esi]
// 00575040  683840b200           push 0xb24038
// 00575045  ff1568b79800         call dword ptr [0x98b768]
// 0057504b  0fb6c0               movzx eax, al
// 0057504e  f7d8                 neg eax
// 00575050  1bc0                 sbb eax, eax
// 00575052  23442408             and eax, dword ptr [esp + 8]
// 00575056  8906                 mov dword ptr [esi], eax
// 00575058  5e                   pop esi
// 00575059  c3                   ret 
// 0057505a  8b442408             mov eax, dword ptr [esp + 8]
// 0057505e  c7003840b200         mov dword ptr [eax], 0xb24038
// 00575064  884804               mov byte ptr [eax + 4], cl
// 00575067  884805               mov byte ptr [eax + 5], cl
// 0057506a  c3                   ret 
// 0057506b  8b442408             mov eax, dword ptr [esp + 8]
// 0057506f  3bc1                 cmp eax, ecx
// 00575071  740e                 je 0x575081
// 00575073  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00575077  8b11                 mov edx, dword ptr [ecx]
// 00575079  8910                 mov dword ptr [eax], edx
// 0057507b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0057507e  894804               mov dword ptr [eax + 4], ecx
// 00575081  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb24038 is typeid(F)
extern const type_info type_descriptor_b24038;

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
        if (check_type == type_descriptor_b24038)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b24038;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
