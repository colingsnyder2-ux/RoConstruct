// from server: 100% by nuck16
// roc 2009-12 004c0150  unit: RBX::RbxParticleEmitter  size: 110 bytes
//
// 004c0150  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c0154  33c9                 xor ecx, ecx
// 004c0156  3bc1                 cmp eax, ecx
// 004c0158  7441                 je 0x4c019b
// 004c015a  83f801               cmp eax, 1
// 004c015d  743c                 je 0x4c019b
// 004c015f  83f802               cmp eax, 2
// 004c0162  7459                 je 0x4c01bd
// 004c0164  83f803               cmp eax, 3
// 004c0167  7521                 jne 0x4c018a
// 004c0169  56                   push esi
// 004c016a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c016e  8b0e                 mov ecx, dword ptr [esi]
// 004c0170  680006b100           push 0xb10600
// 004c0175  ff1568b79800         call dword ptr [0x98b768]
// 004c017b  0fb6c0               movzx eax, al
// 004c017e  f7d8                 neg eax
// 004c0180  1bc0                 sbb eax, eax
// 004c0182  23442408             and eax, dword ptr [esp + 8]
// 004c0186  8906                 mov dword ptr [esi], eax
// 004c0188  5e                   pop esi
// 004c0189  c3                   ret 
// 004c018a  8b442408             mov eax, dword ptr [esp + 8]
// 004c018e  c7000006b100         mov dword ptr [eax], 0xb10600
// 004c0194  884804               mov byte ptr [eax + 4], cl
// 004c0197  884805               mov byte ptr [eax + 5], cl
// 004c019a  c3                   ret 
// 004c019b  8b442408             mov eax, dword ptr [esp + 8]
// 004c019f  3bc1                 cmp eax, ecx
// 004c01a1  741a                 je 0x4c01bd
// 004c01a3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c01a7  8b11                 mov edx, dword ptr [ecx]
// 004c01a9  8910                 mov dword ptr [eax], edx
// 004c01ab  8b5104               mov edx, dword ptr [ecx + 4]
// 004c01ae  895004               mov dword ptr [eax + 4], edx
// 004c01b1  8b5108               mov edx, dword ptr [ecx + 8]
// 004c01b4  895008               mov dword ptr [eax + 8], edx
// 004c01b7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 004c01ba  89480c               mov dword ptr [eax + 0xc], ecx
// 004c01bd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb10600 is typeid(F)
extern const type_info type_descriptor_b10600;

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
        if (check_type == type_descriptor_b10600)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b10600;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
