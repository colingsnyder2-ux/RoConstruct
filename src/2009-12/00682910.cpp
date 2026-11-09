// from server: 100% by nuck16
// roc 2009-12 00682910  unit: RBX::Script  size: 110 bytes
//
// 00682910  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00682914  33c9                 xor ecx, ecx
// 00682916  3bc1                 cmp eax, ecx
// 00682918  7441                 je 0x68295b
// 0068291a  83f801               cmp eax, 1
// 0068291d  743c                 je 0x68295b
// 0068291f  83f802               cmp eax, 2
// 00682922  7459                 je 0x68297d
// 00682924  83f803               cmp eax, 3
// 00682927  7521                 jne 0x68294a
// 00682929  56                   push esi
// 0068292a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0068292e  8b0e                 mov ecx, dword ptr [esi]
// 00682930  68f860b300           push 0xb360f8
// 00682935  ff1568b79800         call dword ptr [0x98b768]
// 0068293b  0fb6c0               movzx eax, al
// 0068293e  f7d8                 neg eax
// 00682940  1bc0                 sbb eax, eax
// 00682942  23442408             and eax, dword ptr [esp + 8]
// 00682946  8906                 mov dword ptr [esi], eax
// 00682948  5e                   pop esi
// 00682949  c3                   ret 
// 0068294a  8b442408             mov eax, dword ptr [esp + 8]
// 0068294e  c700f860b300         mov dword ptr [eax], 0xb360f8
// 00682954  884804               mov byte ptr [eax + 4], cl
// 00682957  884805               mov byte ptr [eax + 5], cl
// 0068295a  c3                   ret 
// 0068295b  8b442408             mov eax, dword ptr [esp + 8]
// 0068295f  3bc1                 cmp eax, ecx
// 00682961  741a                 je 0x68297d
// 00682963  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00682967  8b11                 mov edx, dword ptr [ecx]
// 00682969  8910                 mov dword ptr [eax], edx
// 0068296b  8b5104               mov edx, dword ptr [ecx + 4]
// 0068296e  895004               mov dword ptr [eax + 4], edx
// 00682971  8b5108               mov edx, dword ptr [ecx + 8]
// 00682974  895008               mov dword ptr [eax + 8], edx
// 00682977  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0068297a  89480c               mov dword ptr [eax + 0xc], ecx
// 0068297d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb360f8 is typeid(F)
extern const type_info type_descriptor_b360f8;

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
        if (check_type == type_descriptor_b360f8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b360f8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
