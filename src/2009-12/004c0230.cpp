// from server: 100% by nuck16
// roc 2009-12 004c0230  unit: RBX::RbxParticleEmitter  size: 110 bytes
//
// 004c0230  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c0234  33c9                 xor ecx, ecx
// 004c0236  3bc1                 cmp eax, ecx
// 004c0238  7441                 je 0x4c027b
// 004c023a  83f801               cmp eax, 1
// 004c023d  743c                 je 0x4c027b
// 004c023f  83f802               cmp eax, 2
// 004c0242  7459                 je 0x4c029d
// 004c0244  83f803               cmp eax, 3
// 004c0247  7521                 jne 0x4c026a
// 004c0249  56                   push esi
// 004c024a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c024e  8b0e                 mov ecx, dword ptr [esi]
// 004c0250  686007b100           push 0xb10760
// 004c0255  ff1568b79800         call dword ptr [0x98b768]
// 004c025b  0fb6c0               movzx eax, al
// 004c025e  f7d8                 neg eax
// 004c0260  1bc0                 sbb eax, eax
// 004c0262  23442408             and eax, dword ptr [esp + 8]
// 004c0266  8906                 mov dword ptr [esi], eax
// 004c0268  5e                   pop esi
// 004c0269  c3                   ret 
// 004c026a  8b442408             mov eax, dword ptr [esp + 8]
// 004c026e  c7006007b100         mov dword ptr [eax], 0xb10760
// 004c0274  884804               mov byte ptr [eax + 4], cl
// 004c0277  884805               mov byte ptr [eax + 5], cl
// 004c027a  c3                   ret 
// 004c027b  8b442408             mov eax, dword ptr [esp + 8]
// 004c027f  3bc1                 cmp eax, ecx
// 004c0281  741a                 je 0x4c029d
// 004c0283  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c0287  8b11                 mov edx, dword ptr [ecx]
// 004c0289  8910                 mov dword ptr [eax], edx
// 004c028b  8b5104               mov edx, dword ptr [ecx + 4]
// 004c028e  895004               mov dword ptr [eax + 4], edx
// 004c0291  8b5108               mov edx, dword ptr [ecx + 8]
// 004c0294  895008               mov dword ptr [eax + 8], edx
// 004c0297  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 004c029a  89480c               mov dword ptr [eax + 0xc], ecx
// 004c029d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb10760 is typeid(F)
extern const type_info type_descriptor_b10760;

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
        if (check_type == type_descriptor_b10760)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b10760;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
