// from server: 100% by nuck16
// roc 2009-12 006a0130  unit: std::strstream  size: 110 bytes
//
// 006a0130  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006a0134  33c9                 xor ecx, ecx
// 006a0136  3bc1                 cmp eax, ecx
// 006a0138  7441                 je 0x6a017b
// 006a013a  83f801               cmp eax, 1
// 006a013d  743c                 je 0x6a017b
// 006a013f  83f802               cmp eax, 2
// 006a0142  7459                 je 0x6a019d
// 006a0144  83f803               cmp eax, 3
// 006a0147  7521                 jne 0x6a016a
// 006a0149  56                   push esi
// 006a014a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006a014e  8b0e                 mov ecx, dword ptr [esi]
// 006a0150  68709ab300           push 0xb39a70
// 006a0155  ff1568b79800         call dword ptr [0x98b768]
// 006a015b  0fb6c0               movzx eax, al
// 006a015e  f7d8                 neg eax
// 006a0160  1bc0                 sbb eax, eax
// 006a0162  23442408             and eax, dword ptr [esp + 8]
// 006a0166  8906                 mov dword ptr [esi], eax
// 006a0168  5e                   pop esi
// 006a0169  c3                   ret 
// 006a016a  8b442408             mov eax, dword ptr [esp + 8]
// 006a016e  c700709ab300         mov dword ptr [eax], 0xb39a70
// 006a0174  884804               mov byte ptr [eax + 4], cl
// 006a0177  884805               mov byte ptr [eax + 5], cl
// 006a017a  c3                   ret 
// 006a017b  8b442408             mov eax, dword ptr [esp + 8]
// 006a017f  3bc1                 cmp eax, ecx
// 006a0181  741a                 je 0x6a019d
// 006a0183  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a0187  8b11                 mov edx, dword ptr [ecx]
// 006a0189  8910                 mov dword ptr [eax], edx
// 006a018b  8b5104               mov edx, dword ptr [ecx + 4]
// 006a018e  895004               mov dword ptr [eax + 4], edx
// 006a0191  8b5108               mov edx, dword ptr [ecx + 8]
// 006a0194  895008               mov dword ptr [eax + 8], edx
// 006a0197  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 006a019a  89480c               mov dword ptr [eax + 0xc], ecx
// 006a019d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb39a70 is typeid(F)
extern const type_info type_descriptor_b39a70;

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
        if (check_type == type_descriptor_b39a70)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b39a70;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
