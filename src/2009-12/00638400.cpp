// from server: 100% by nuck16
// roc 2009-12 00638400  unit: RBX::VInstance::?$EventDesc  size: 110 bytes
//
// 00638400  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00638404  33c9                 xor ecx, ecx
// 00638406  3bc1                 cmp eax, ecx
// 00638408  7441                 je 0x63844b
// 0063840a  83f801               cmp eax, 1
// 0063840d  743c                 je 0x63844b
// 0063840f  83f802               cmp eax, 2
// 00638412  7459                 je 0x63846d
// 00638414  83f803               cmp eax, 3
// 00638417  7521                 jne 0x63843a
// 00638419  56                   push esi
// 0063841a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0063841e  8b0e                 mov ecx, dword ptr [esi]
// 00638420  6878a4b200           push 0xb2a478
// 00638425  ff1568b79800         call dword ptr [0x98b768]
// 0063842b  0fb6c0               movzx eax, al
// 0063842e  f7d8                 neg eax
// 00638430  1bc0                 sbb eax, eax
// 00638432  23442408             and eax, dword ptr [esp + 8]
// 00638436  8906                 mov dword ptr [esi], eax
// 00638438  5e                   pop esi
// 00638439  c3                   ret 
// 0063843a  8b442408             mov eax, dword ptr [esp + 8]
// 0063843e  c70078a4b200         mov dword ptr [eax], 0xb2a478
// 00638444  884804               mov byte ptr [eax + 4], cl
// 00638447  884805               mov byte ptr [eax + 5], cl
// 0063844a  c3                   ret 
// 0063844b  8b442408             mov eax, dword ptr [esp + 8]
// 0063844f  3bc1                 cmp eax, ecx
// 00638451  741a                 je 0x63846d
// 00638453  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00638457  8b11                 mov edx, dword ptr [ecx]
// 00638459  8910                 mov dword ptr [eax], edx
// 0063845b  8b5104               mov edx, dword ptr [ecx + 4]
// 0063845e  895004               mov dword ptr [eax + 4], edx
// 00638461  8b5108               mov edx, dword ptr [ecx + 8]
// 00638464  895008               mov dword ptr [eax + 8], edx
// 00638467  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0063846a  89480c               mov dword ptr [eax + 0xc], ecx
// 0063846d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb2a478 is typeid(F)
extern const type_info type_descriptor_b2a478;

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
        if (check_type == type_descriptor_b2a478)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b2a478;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
