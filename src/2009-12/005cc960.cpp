// from server: 100% by nuck16
// roc 2009-12 005cc960  unit: RBX::MeshRefPartAdapter  size: 110 bytes
//
// 005cc960  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005cc964  33c9                 xor ecx, ecx
// 005cc966  3bc1                 cmp eax, ecx
// 005cc968  7441                 je 0x5cc9ab
// 005cc96a  83f801               cmp eax, 1
// 005cc96d  743c                 je 0x5cc9ab
// 005cc96f  83f802               cmp eax, 2
// 005cc972  7459                 je 0x5cc9cd
// 005cc974  83f803               cmp eax, 3
// 005cc977  7521                 jne 0x5cc99a
// 005cc979  56                   push esi
// 005cc97a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005cc97e  8b0e                 mov ecx, dword ptr [esi]
// 005cc980  68205eb200           push 0xb25e20
// 005cc985  ff1568b79800         call dword ptr [0x98b768]
// 005cc98b  0fb6c0               movzx eax, al
// 005cc98e  f7d8                 neg eax
// 005cc990  1bc0                 sbb eax, eax
// 005cc992  23442408             and eax, dword ptr [esp + 8]
// 005cc996  8906                 mov dword ptr [esi], eax
// 005cc998  5e                   pop esi
// 005cc999  c3                   ret 
// 005cc99a  8b442408             mov eax, dword ptr [esp + 8]
// 005cc99e  c700205eb200         mov dword ptr [eax], 0xb25e20
// 005cc9a4  884804               mov byte ptr [eax + 4], cl
// 005cc9a7  884805               mov byte ptr [eax + 5], cl
// 005cc9aa  c3                   ret 
// 005cc9ab  8b442408             mov eax, dword ptr [esp + 8]
// 005cc9af  3bc1                 cmp eax, ecx
// 005cc9b1  741a                 je 0x5cc9cd
// 005cc9b3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005cc9b7  8b11                 mov edx, dword ptr [ecx]
// 005cc9b9  8910                 mov dword ptr [eax], edx
// 005cc9bb  8b5104               mov edx, dword ptr [ecx + 4]
// 005cc9be  895004               mov dword ptr [eax + 4], edx
// 005cc9c1  8b5108               mov edx, dword ptr [ecx + 8]
// 005cc9c4  895008               mov dword ptr [eax + 8], edx
// 005cc9c7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005cc9ca  89480c               mov dword ptr [eax + 0xc], ecx
// 005cc9cd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb25e20 is typeid(F)
extern const type_info type_descriptor_b25e20;

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
        if (check_type == type_descriptor_b25e20)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b25e20;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
