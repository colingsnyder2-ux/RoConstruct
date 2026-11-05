// roc 2012-06 008807f0  unit: RBX::TestService  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008807f0
//
// 008807f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008807f4  33c9                 xor ecx, ecx
// 008807f6  3bc1                 cmp eax, ecx
// 008807f8  7441                 je 0x88083b
// 008807fa  83f801               cmp eax, 1
// 008807fd  743c                 je 0x88083b
// 008807ff  83f802               cmp eax, 2
// 00880802  7459                 je 0x88085d
// 00880804  83f803               cmp eax, 3
// 00880807  7521                 jne 0x88082a
// 00880809  56                   push esi
// 0088080a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0088080e  8b0e                 mov ecx, dword ptr [esi]
// 00880810  68207ede00           push 0xde7e20
// 00880815  ff15ec29b200         call dword ptr [0xb229ec]
// 0088081b  0fb6c0               movzx eax, al
// 0088081e  f7d8                 neg eax
// 00880820  1bc0                 sbb eax, eax
// 00880822  23442408             and eax, dword ptr [esp + 8]
// 00880826  8906                 mov dword ptr [esi], eax
// 00880828  5e                   pop esi
// 00880829  c3                   ret 
// 0088082a  8b442408             mov eax, dword ptr [esp + 8]
// 0088082e  c700207ede00         mov dword ptr [eax], 0xde7e20
// 00880834  884804               mov byte ptr [eax + 4], cl
// 00880837  884805               mov byte ptr [eax + 5], cl
// 0088083a  c3                   ret 
// 0088083b  8b442408             mov eax, dword ptr [esp + 8]
// 0088083f  3bc1                 cmp eax, ecx
// 00880841  741a                 je 0x88085d
// 00880843  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00880847  8b11                 mov edx, dword ptr [ecx]
// 00880849  8910                 mov dword ptr [eax], edx
// 0088084b  8b5104               mov edx, dword ptr [ecx + 4]
// 0088084e  895004               mov dword ptr [eax + 4], edx
// 00880851  8b5108               mov edx, dword ptr [ecx + 8]
// 00880854  895008               mov dword ptr [eax + 8], edx
// 00880857  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0088085a  89480c               mov dword ptr [eax + 0xc], ecx
// 0088085d  c3                   ret 
// copied from an identical function in another client (function ?manage@@YAXABTfunction_buffer@@AAT1@W4functor_manager_operation_type@@@Z)

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb33668 is typeid(F)
extern const type_info type_descriptor_b33668;

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
        if (check_type == type_descriptor_b33668)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b33668;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}