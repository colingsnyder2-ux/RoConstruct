// from server: 100% by nuck16
// roc 2009-12 00428bc0  unit: CMainFrame  size: 116 bytes
//
// 00428bc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00428bc4  33c9                 xor ecx, ecx
// 00428bc6  3bc1                 cmp eax, ecx
// 00428bc8  7441                 je 0x428c0b
// 00428bca  83f801               cmp eax, 1
// 00428bcd  743c                 je 0x428c0b
// 00428bcf  83f802               cmp eax, 2
// 00428bd2  745f                 je 0x428c33
// 00428bd4  83f803               cmp eax, 3
// 00428bd7  7521                 jne 0x428bfa
// 00428bd9  56                   push esi
// 00428bda  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00428bde  8b0e                 mov ecx, dword ptr [esi]
// 00428be0  68c84cb000           push 0xb04cc8
// 00428be5  ff1568b79800         call dword ptr [0x98b768]
// 00428beb  0fb6c0               movzx eax, al
// 00428bee  f7d8                 neg eax
// 00428bf0  1bc0                 sbb eax, eax
// 00428bf2  23442408             and eax, dword ptr [esp + 8]
// 00428bf6  8906                 mov dword ptr [esi], eax
// 00428bf8  5e                   pop esi
// 00428bf9  c3                   ret 
// 00428bfa  8b442408             mov eax, dword ptr [esp + 8]
// 00428bfe  c700c84cb000         mov dword ptr [eax], 0xb04cc8
// 00428c04  884804               mov byte ptr [eax + 4], cl
// 00428c07  884805               mov byte ptr [eax + 5], cl
// 00428c0a  c3                   ret 
// 00428c0b  8b442408             mov eax, dword ptr [esp + 8]
// 00428c0f  3bc1                 cmp eax, ecx
// 00428c11  7420                 je 0x428c33
// 00428c13  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00428c17  8b11                 mov edx, dword ptr [ecx]
// 00428c19  8910                 mov dword ptr [eax], edx
// 00428c1b  8b5104               mov edx, dword ptr [ecx + 4]
// 00428c1e  895004               mov dword ptr [eax + 4], edx
// 00428c21  8b5108               mov edx, dword ptr [ecx + 8]
// 00428c24  895008               mov dword ptr [eax + 8], edx
// 00428c27  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00428c2a  89500c               mov dword ptr [eax + 0xc], edx
// 00428c2d  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00428c30  894810               mov dword ptr [eax + 0x10], ecx
// 00428c33  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb04cc8 is typeid(F)
extern const type_info type_descriptor_b04cc8;

struct Functor
{
    int f0, f1, f2, f3, f4;
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
    char data[20];
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
        if (check_type == type_descriptor_b04cc8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b04cc8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
