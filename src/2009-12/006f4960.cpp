// from server: 100% by nuck16
// roc 2009-12 006f4960  unit: RBX::Backpack  size: 110 bytes
//
// 006f4960  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f4964  33c9                 xor ecx, ecx
// 006f4966  3bc1                 cmp eax, ecx
// 006f4968  7441                 je 0x6f49ab
// 006f496a  83f801               cmp eax, 1
// 006f496d  743c                 je 0x6f49ab
// 006f496f  83f802               cmp eax, 2
// 006f4972  7459                 je 0x6f49cd
// 006f4974  83f803               cmp eax, 3
// 006f4977  7521                 jne 0x6f499a
// 006f4979  56                   push esi
// 006f497a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006f497e  8b0e                 mov ecx, dword ptr [esi]
// 006f4980  68f05eb400           push 0xb45ef0
// 006f4985  ff1568b79800         call dword ptr [0x98b768]
// 006f498b  0fb6c0               movzx eax, al
// 006f498e  f7d8                 neg eax
// 006f4990  1bc0                 sbb eax, eax
// 006f4992  23442408             and eax, dword ptr [esp + 8]
// 006f4996  8906                 mov dword ptr [esi], eax
// 006f4998  5e                   pop esi
// 006f4999  c3                   ret 
// 006f499a  8b442408             mov eax, dword ptr [esp + 8]
// 006f499e  c700f05eb400         mov dword ptr [eax], 0xb45ef0
// 006f49a4  884804               mov byte ptr [eax + 4], cl
// 006f49a7  884805               mov byte ptr [eax + 5], cl
// 006f49aa  c3                   ret 
// 006f49ab  8b442408             mov eax, dword ptr [esp + 8]
// 006f49af  3bc1                 cmp eax, ecx
// 006f49b1  741a                 je 0x6f49cd
// 006f49b3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f49b7  8b11                 mov edx, dword ptr [ecx]
// 006f49b9  8910                 mov dword ptr [eax], edx
// 006f49bb  8b5104               mov edx, dword ptr [ecx + 4]
// 006f49be  895004               mov dword ptr [eax + 4], edx
// 006f49c1  8b5108               mov edx, dword ptr [ecx + 8]
// 006f49c4  895008               mov dword ptr [eax + 8], edx
// 006f49c7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 006f49ca  89480c               mov dword ptr [eax + 0xc], ecx
// 006f49cd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb45ef0 is typeid(F)
extern const type_info type_descriptor_b45ef0;

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
        if (check_type == type_descriptor_b45ef0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b45ef0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
