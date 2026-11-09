// from server: 100% by nuck16
// roc 2009-12 00512cb0  unit: RBX::Network::Players  size: 98 bytes
//
// 00512cb0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00512cb4  33c9                 xor ecx, ecx
// 00512cb6  3bc1                 cmp eax, ecx
// 00512cb8  7441                 je 0x512cfb
// 00512cba  83f801               cmp eax, 1
// 00512cbd  743c                 je 0x512cfb
// 00512cbf  83f802               cmp eax, 2
// 00512cc2  744d                 je 0x512d11
// 00512cc4  83f803               cmp eax, 3
// 00512cc7  7521                 jne 0x512cea
// 00512cc9  56                   push esi
// 00512cca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00512cce  8b0e                 mov ecx, dword ptr [esi]
// 00512cd0  68f882b100           push 0xb182f8
// 00512cd5  ff1568b79800         call dword ptr [0x98b768]
// 00512cdb  0fb6c0               movzx eax, al
// 00512cde  f7d8                 neg eax
// 00512ce0  1bc0                 sbb eax, eax
// 00512ce2  23442408             and eax, dword ptr [esp + 8]
// 00512ce6  8906                 mov dword ptr [esi], eax
// 00512ce8  5e                   pop esi
// 00512ce9  c3                   ret 
// 00512cea  8b442408             mov eax, dword ptr [esp + 8]
// 00512cee  c700f882b100         mov dword ptr [eax], 0xb182f8
// 00512cf4  884804               mov byte ptr [eax + 4], cl
// 00512cf7  884805               mov byte ptr [eax + 5], cl
// 00512cfa  c3                   ret 
// 00512cfb  8b442408             mov eax, dword ptr [esp + 8]
// 00512cff  3bc1                 cmp eax, ecx
// 00512d01  740e                 je 0x512d11
// 00512d03  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00512d07  8b11                 mov edx, dword ptr [ecx]
// 00512d09  8910                 mov dword ptr [eax], edx
// 00512d0b  8b4904               mov ecx, dword ptr [ecx + 4]
// 00512d0e  894804               mov dword ptr [eax + 4], ecx
// 00512d11  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb182f8 is typeid(F)
extern const type_info type_descriptor_b182f8;

struct Functor
{
    int f0, f1;
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
    char data[8];
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
        if (check_type == type_descriptor_b182f8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b182f8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
