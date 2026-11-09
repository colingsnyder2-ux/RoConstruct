// from server: 100% by nuck16
// roc 2009-12 00696510  unit: RBX::Workspace  size: 122 bytes
//
// 00696510  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00696514  33c9                 xor ecx, ecx
// 00696516  3bc1                 cmp eax, ecx
// 00696518  7441                 je 0x69655b
// 0069651a  83f801               cmp eax, 1
// 0069651d  743c                 je 0x69655b
// 0069651f  83f802               cmp eax, 2
// 00696522  7465                 je 0x696589
// 00696524  83f803               cmp eax, 3
// 00696527  7521                 jne 0x69654a
// 00696529  56                   push esi
// 0069652a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0069652e  8b0e                 mov ecx, dword ptr [esi]
// 00696530  68708db300           push 0xb38d70
// 00696535  ff1568b79800         call dword ptr [0x98b768]
// 0069653b  0fb6c0               movzx eax, al
// 0069653e  f7d8                 neg eax
// 00696540  1bc0                 sbb eax, eax
// 00696542  23442408             and eax, dword ptr [esp + 8]
// 00696546  8906                 mov dword ptr [esi], eax
// 00696548  5e                   pop esi
// 00696549  c3                   ret 
// 0069654a  8b442408             mov eax, dword ptr [esp + 8]
// 0069654e  c700708db300         mov dword ptr [eax], 0xb38d70
// 00696554  884804               mov byte ptr [eax + 4], cl
// 00696557  884805               mov byte ptr [eax + 5], cl
// 0069655a  c3                   ret 
// 0069655b  8b442408             mov eax, dword ptr [esp + 8]
// 0069655f  3bc1                 cmp eax, ecx
// 00696561  7426                 je 0x696589
// 00696563  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00696567  8b11                 mov edx, dword ptr [ecx]
// 00696569  8910                 mov dword ptr [eax], edx
// 0069656b  8b5104               mov edx, dword ptr [ecx + 4]
// 0069656e  895004               mov dword ptr [eax + 4], edx
// 00696571  8b5108               mov edx, dword ptr [ecx + 8]
// 00696574  895008               mov dword ptr [eax + 8], edx
// 00696577  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0069657a  89500c               mov dword ptr [eax + 0xc], edx
// 0069657d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00696580  895010               mov dword ptr [eax + 0x10], edx
// 00696583  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00696586  894814               mov dword ptr [eax + 0x14], ecx
// 00696589  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb38d70 is typeid(F)
extern const type_info type_descriptor_b38d70;

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
        if (check_type == type_descriptor_b38d70)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b38d70;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
