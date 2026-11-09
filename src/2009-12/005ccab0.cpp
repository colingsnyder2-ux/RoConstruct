// from server: 100% by nuck16
// roc 2009-12 005ccab0  unit: RBX::MeshRefPartAdapter  size: 110 bytes
//
// 005ccab0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005ccab4  33c9                 xor ecx, ecx
// 005ccab6  3bc1                 cmp eax, ecx
// 005ccab8  7441                 je 0x5ccafb
// 005ccaba  83f801               cmp eax, 1
// 005ccabd  743c                 je 0x5ccafb
// 005ccabf  83f802               cmp eax, 2
// 005ccac2  7459                 je 0x5ccb1d
// 005ccac4  83f803               cmp eax, 3
// 005ccac7  7521                 jne 0x5ccaea
// 005ccac9  56                   push esi
// 005ccaca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005ccace  8b0e                 mov ecx, dword ptr [esi]
// 005ccad0  683860b200           push 0xb26038
// 005ccad5  ff1568b79800         call dword ptr [0x98b768]
// 005ccadb  0fb6c0               movzx eax, al
// 005ccade  f7d8                 neg eax
// 005ccae0  1bc0                 sbb eax, eax
// 005ccae2  23442408             and eax, dword ptr [esp + 8]
// 005ccae6  8906                 mov dword ptr [esi], eax
// 005ccae8  5e                   pop esi
// 005ccae9  c3                   ret 
// 005ccaea  8b442408             mov eax, dword ptr [esp + 8]
// 005ccaee  c7003860b200         mov dword ptr [eax], 0xb26038
// 005ccaf4  884804               mov byte ptr [eax + 4], cl
// 005ccaf7  884805               mov byte ptr [eax + 5], cl
// 005ccafa  c3                   ret 
// 005ccafb  8b442408             mov eax, dword ptr [esp + 8]
// 005ccaff  3bc1                 cmp eax, ecx
// 005ccb01  741a                 je 0x5ccb1d
// 005ccb03  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005ccb07  8b11                 mov edx, dword ptr [ecx]
// 005ccb09  8910                 mov dword ptr [eax], edx
// 005ccb0b  8b5104               mov edx, dword ptr [ecx + 4]
// 005ccb0e  895004               mov dword ptr [eax + 4], edx
// 005ccb11  8b5108               mov edx, dword ptr [ecx + 8]
// 005ccb14  895008               mov dword ptr [eax + 8], edx
// 005ccb17  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005ccb1a  89480c               mov dword ptr [eax + 0xc], ecx
// 005ccb1d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb26038 is typeid(F)
extern const type_info type_descriptor_b26038;

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
        if (check_type == type_descriptor_b26038)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b26038;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
