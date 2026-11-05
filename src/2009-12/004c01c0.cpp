// from server: 100% by nuck16
// roc 2009-12 004c01c0  unit: RBX::RbxParticleEmitter  size: 110 bytes
//
// 004c01c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c01c4  33c9                 xor ecx, ecx
// 004c01c6  3bc1                 cmp eax, ecx
// 004c01c8  7441                 je 0x4c020b
// 004c01ca  83f801               cmp eax, 1
// 004c01cd  743c                 je 0x4c020b
// 004c01cf  83f802               cmp eax, 2
// 004c01d2  7459                 je 0x4c022d
// 004c01d4  83f803               cmp eax, 3
// 004c01d7  7521                 jne 0x4c01fa
// 004c01d9  56                   push esi
// 004c01da  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c01de  8b0e                 mov ecx, dword ptr [esi]
// 004c01e0  689806b100           push 0xb10698
// 004c01e5  ff1568b79800         call dword ptr [0x98b768]
// 004c01eb  0fb6c0               movzx eax, al
// 004c01ee  f7d8                 neg eax
// 004c01f0  1bc0                 sbb eax, eax
// 004c01f2  23442408             and eax, dword ptr [esp + 8]
// 004c01f6  8906                 mov dword ptr [esi], eax
// 004c01f8  5e                   pop esi
// 004c01f9  c3                   ret 
// 004c01fa  8b442408             mov eax, dword ptr [esp + 8]
// 004c01fe  c7009806b100         mov dword ptr [eax], 0xb10698
// 004c0204  884804               mov byte ptr [eax + 4], cl
// 004c0207  884805               mov byte ptr [eax + 5], cl
// 004c020a  c3                   ret 
// 004c020b  8b442408             mov eax, dword ptr [esp + 8]
// 004c020f  3bc1                 cmp eax, ecx
// 004c0211  741a                 je 0x4c022d
// 004c0213  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c0217  8b11                 mov edx, dword ptr [ecx]
// 004c0219  8910                 mov dword ptr [eax], edx
// 004c021b  8b5104               mov edx, dword ptr [ecx + 4]
// 004c021e  895004               mov dword ptr [eax + 4], edx
// 004c0221  8b5108               mov edx, dword ptr [ecx + 8]
// 004c0224  895008               mov dword ptr [eax + 8], edx
// 004c0227  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 004c022a  89480c               mov dword ptr [eax + 0xc], ecx
// 004c022d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb10698 is typeid(F)
extern const type_info type_descriptor_b10698;

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
        if (check_type == type_descriptor_b10698)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b10698;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
