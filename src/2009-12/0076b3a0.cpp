// from server: 100% by nuck16
// roc 2009-12 0076b3a0  unit: RBX::VContentFilter::?$BoundFuncDesc  size: 110 bytes
//
// 0076b3a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076b3a4  33c9                 xor ecx, ecx
// 0076b3a6  3bc1                 cmp eax, ecx
// 0076b3a8  7441                 je 0x76b3eb
// 0076b3aa  83f801               cmp eax, 1
// 0076b3ad  743c                 je 0x76b3eb
// 0076b3af  83f802               cmp eax, 2
// 0076b3b2  7459                 je 0x76b40d
// 0076b3b4  83f803               cmp eax, 3
// 0076b3b7  7521                 jne 0x76b3da
// 0076b3b9  56                   push esi
// 0076b3ba  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0076b3be  8b0e                 mov ecx, dword ptr [esi]
// 0076b3c0  6830f3b500           push 0xb5f330
// 0076b3c5  ff1568b79800         call dword ptr [0x98b768]
// 0076b3cb  0fb6c0               movzx eax, al
// 0076b3ce  f7d8                 neg eax
// 0076b3d0  1bc0                 sbb eax, eax
// 0076b3d2  23442408             and eax, dword ptr [esp + 8]
// 0076b3d6  8906                 mov dword ptr [esi], eax
// 0076b3d8  5e                   pop esi
// 0076b3d9  c3                   ret 
// 0076b3da  8b442408             mov eax, dword ptr [esp + 8]
// 0076b3de  c70030f3b500         mov dword ptr [eax], 0xb5f330
// 0076b3e4  884804               mov byte ptr [eax + 4], cl
// 0076b3e7  884805               mov byte ptr [eax + 5], cl
// 0076b3ea  c3                   ret 
// 0076b3eb  8b442408             mov eax, dword ptr [esp + 8]
// 0076b3ef  3bc1                 cmp eax, ecx
// 0076b3f1  741a                 je 0x76b40d
// 0076b3f3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0076b3f7  8b11                 mov edx, dword ptr [ecx]
// 0076b3f9  8910                 mov dword ptr [eax], edx
// 0076b3fb  8b5104               mov edx, dword ptr [ecx + 4]
// 0076b3fe  895004               mov dword ptr [eax + 4], edx
// 0076b401  8b5108               mov edx, dword ptr [ecx + 8]
// 0076b404  895008               mov dword ptr [eax + 8], edx
// 0076b407  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0076b40a  89480c               mov dword ptr [eax + 0xc], ecx
// 0076b40d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb5f330 is typeid(F)
extern const type_info type_descriptor_b5f330;

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
        if (check_type == type_descriptor_b5f330)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b5f330;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
