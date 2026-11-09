// from server: 100% by nuck16
// roc 2009-12 006b3cc0  unit: RBX::DropperTool  size: 110 bytes
//
// 006b3cc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b3cc4  33c9                 xor ecx, ecx
// 006b3cc6  3bc1                 cmp eax, ecx
// 006b3cc8  7441                 je 0x6b3d0b
// 006b3cca  83f801               cmp eax, 1
// 006b3ccd  743c                 je 0x6b3d0b
// 006b3ccf  83f802               cmp eax, 2
// 006b3cd2  7459                 je 0x6b3d2d
// 006b3cd4  83f803               cmp eax, 3
// 006b3cd7  7521                 jne 0x6b3cfa
// 006b3cd9  56                   push esi
// 006b3cda  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006b3cde  8b0e                 mov ecx, dword ptr [esi]
// 006b3ce0  6808acb300           push 0xb3ac08
// 006b3ce5  ff1568b79800         call dword ptr [0x98b768]
// 006b3ceb  0fb6c0               movzx eax, al
// 006b3cee  f7d8                 neg eax
// 006b3cf0  1bc0                 sbb eax, eax
// 006b3cf2  23442408             and eax, dword ptr [esp + 8]
// 006b3cf6  8906                 mov dword ptr [esi], eax
// 006b3cf8  5e                   pop esi
// 006b3cf9  c3                   ret 
// 006b3cfa  8b442408             mov eax, dword ptr [esp + 8]
// 006b3cfe  c70008acb300         mov dword ptr [eax], 0xb3ac08
// 006b3d04  884804               mov byte ptr [eax + 4], cl
// 006b3d07  884805               mov byte ptr [eax + 5], cl
// 006b3d0a  c3                   ret 
// 006b3d0b  8b442408             mov eax, dword ptr [esp + 8]
// 006b3d0f  3bc1                 cmp eax, ecx
// 006b3d11  741a                 je 0x6b3d2d
// 006b3d13  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b3d17  8b11                 mov edx, dword ptr [ecx]
// 006b3d19  8910                 mov dword ptr [eax], edx
// 006b3d1b  8b5104               mov edx, dword ptr [ecx + 4]
// 006b3d1e  895004               mov dword ptr [eax + 4], edx
// 006b3d21  8b5108               mov edx, dword ptr [ecx + 8]
// 006b3d24  895008               mov dword ptr [eax + 8], edx
// 006b3d27  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 006b3d2a  89480c               mov dword ptr [eax + 0xc], ecx
// 006b3d2d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb3ac08 is typeid(F)
extern const type_info type_descriptor_b3ac08;

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
        if (check_type == type_descriptor_b3ac08)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b3ac08;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
