// from server: 100% by nuck16
// roc 2009-12 00744f20  unit: RBX::Flag  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00744f20
//
// 00744f20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00744f24  33c9                 xor ecx, ecx
// 00744f26  3bc1                 cmp eax, ecx
// 00744f28  7441                 je 0x744f6b
// 00744f2a  83f801               cmp eax, 1
// 00744f2d  743c                 je 0x744f6b
// 00744f2f  83f802               cmp eax, 2
// 00744f32  7465                 je 0x744f99
// 00744f34  83f803               cmp eax, 3
// 00744f37  7521                 jne 0x744f5a
// 00744f39  56                   push esi
// 00744f3a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00744f3e  8b0e                 mov ecx, dword ptr [esi]
// 00744f40  68305fb500           push 0xb55f30
// 00744f45  ff1568b79800         call dword ptr [0x98b768]
// 00744f4b  0fb6c0               movzx eax, al
// 00744f4e  f7d8                 neg eax
// 00744f50  1bc0                 sbb eax, eax
// 00744f52  23442408             and eax, dword ptr [esp + 8]
// 00744f56  8906                 mov dword ptr [esi], eax
// 00744f58  5e                   pop esi
// 00744f59  c3                   ret 
// 00744f5a  8b442408             mov eax, dword ptr [esp + 8]
// 00744f5e  c700305fb500         mov dword ptr [eax], 0xb55f30
// 00744f64  884804               mov byte ptr [eax + 4], cl
// 00744f67  884805               mov byte ptr [eax + 5], cl
// 00744f6a  c3                   ret 
// 00744f6b  8b442408             mov eax, dword ptr [esp + 8]
// 00744f6f  3bc1                 cmp eax, ecx
// 00744f71  7426                 je 0x744f99
// 00744f73  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00744f77  8b11                 mov edx, dword ptr [ecx]
// 00744f79  8910                 mov dword ptr [eax], edx
// 00744f7b  8b5104               mov edx, dword ptr [ecx + 4]
// 00744f7e  895004               mov dword ptr [eax + 4], edx
// 00744f81  8b5108               mov edx, dword ptr [ecx + 8]
// 00744f84  895008               mov dword ptr [eax + 8], edx
// 00744f87  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00744f8a  89500c               mov dword ptr [eax + 0xc], edx
// 00744f8d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00744f90  895010               mov dword ptr [eax + 0x10], edx
// 00744f93  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00744f96  894814               mov dword ptr [eax + 0x14], ecx
// 00744f99  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb55f30 is typeid(F)
extern const type_info type_descriptor_b55f30;

struct Functor
{
    int f0, f1, f2, f3, f4, f5;
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
    char data[24];
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
        if (check_type == type_descriptor_b55f30)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b55f30;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
