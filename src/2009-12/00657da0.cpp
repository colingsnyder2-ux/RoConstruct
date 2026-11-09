// from server: 100% by nuck16
// roc 2009-12 00657da0  unit: RBX::BasicPartInstance  size: 122 bytes
//
// 00657da0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00657da4  33c9                 xor ecx, ecx
// 00657da6  3bc1                 cmp eax, ecx
// 00657da8  7441                 je 0x657deb
// 00657daa  83f801               cmp eax, 1
// 00657dad  743c                 je 0x657deb
// 00657daf  83f802               cmp eax, 2
// 00657db2  7465                 je 0x657e19
// 00657db4  83f803               cmp eax, 3
// 00657db7  7521                 jne 0x657dda
// 00657db9  56                   push esi
// 00657dba  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00657dbe  8b0e                 mov ecx, dword ptr [esi]
// 00657dc0  68b0f1b200           push 0xb2f1b0
// 00657dc5  ff1568b79800         call dword ptr [0x98b768]
// 00657dcb  0fb6c0               movzx eax, al
// 00657dce  f7d8                 neg eax
// 00657dd0  1bc0                 sbb eax, eax
// 00657dd2  23442408             and eax, dword ptr [esp + 8]
// 00657dd6  8906                 mov dword ptr [esi], eax
// 00657dd8  5e                   pop esi
// 00657dd9  c3                   ret 
// 00657dda  8b442408             mov eax, dword ptr [esp + 8]
// 00657dde  c700b0f1b200         mov dword ptr [eax], 0xb2f1b0
// 00657de4  884804               mov byte ptr [eax + 4], cl
// 00657de7  884805               mov byte ptr [eax + 5], cl
// 00657dea  c3                   ret 
// 00657deb  8b442408             mov eax, dword ptr [esp + 8]
// 00657def  3bc1                 cmp eax, ecx
// 00657df1  7426                 je 0x657e19
// 00657df3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00657df7  8b11                 mov edx, dword ptr [ecx]
// 00657df9  8910                 mov dword ptr [eax], edx
// 00657dfb  8b5104               mov edx, dword ptr [ecx + 4]
// 00657dfe  895004               mov dword ptr [eax + 4], edx
// 00657e01  8b5108               mov edx, dword ptr [ecx + 8]
// 00657e04  895008               mov dword ptr [eax + 8], edx
// 00657e07  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00657e0a  89500c               mov dword ptr [eax + 0xc], edx
// 00657e0d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00657e10  895010               mov dword ptr [eax + 0x10], edx
// 00657e13  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00657e16  894814               mov dword ptr [eax + 0x14], ecx
// 00657e19  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb2f1b0 is typeid(F)
extern const type_info type_descriptor_b2f1b0;

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
        if (check_type == type_descriptor_b2f1b0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b2f1b0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
