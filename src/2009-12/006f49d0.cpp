// from server: 100% by nuck16
// roc 2009-12 006f49d0  unit: RBX::Backpack  size: 110 bytes
//
// 006f49d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f49d4  33c9                 xor ecx, ecx
// 006f49d6  3bc1                 cmp eax, ecx
// 006f49d8  7441                 je 0x6f4a1b
// 006f49da  83f801               cmp eax, 1
// 006f49dd  743c                 je 0x6f4a1b
// 006f49df  83f802               cmp eax, 2
// 006f49e2  7459                 je 0x6f4a3d
// 006f49e4  83f803               cmp eax, 3
// 006f49e7  7521                 jne 0x6f4a0a
// 006f49e9  56                   push esi
// 006f49ea  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006f49ee  8b0e                 mov ecx, dword ptr [esi]
// 006f49f0  68c05fb400           push 0xb45fc0
// 006f49f5  ff1568b79800         call dword ptr [0x98b768]
// 006f49fb  0fb6c0               movzx eax, al
// 006f49fe  f7d8                 neg eax
// 006f4a00  1bc0                 sbb eax, eax
// 006f4a02  23442408             and eax, dword ptr [esp + 8]
// 006f4a06  8906                 mov dword ptr [esi], eax
// 006f4a08  5e                   pop esi
// 006f4a09  c3                   ret 
// 006f4a0a  8b442408             mov eax, dword ptr [esp + 8]
// 006f4a0e  c700c05fb400         mov dword ptr [eax], 0xb45fc0
// 006f4a14  884804               mov byte ptr [eax + 4], cl
// 006f4a17  884805               mov byte ptr [eax + 5], cl
// 006f4a1a  c3                   ret 
// 006f4a1b  8b442408             mov eax, dword ptr [esp + 8]
// 006f4a1f  3bc1                 cmp eax, ecx
// 006f4a21  741a                 je 0x6f4a3d
// 006f4a23  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f4a27  8b11                 mov edx, dword ptr [ecx]
// 006f4a29  8910                 mov dword ptr [eax], edx
// 006f4a2b  8b5104               mov edx, dword ptr [ecx + 4]
// 006f4a2e  895004               mov dword ptr [eax + 4], edx
// 006f4a31  8b5108               mov edx, dword ptr [ecx + 8]
// 006f4a34  895008               mov dword ptr [eax + 8], edx
// 006f4a37  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 006f4a3a  89480c               mov dword ptr [eax + 0xc], ecx
// 006f4a3d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb45fc0 is typeid(F)
extern const type_info type_descriptor_b45fc0;

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
        if (check_type == type_descriptor_b45fc0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b45fc0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
