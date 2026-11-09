// from server: 100% by nuck16
// roc 2009-12 006a00c0  unit: std::strstream  size: 98 bytes
//
// 006a00c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006a00c4  33c9                 xor ecx, ecx
// 006a00c6  3bc1                 cmp eax, ecx
// 006a00c8  7441                 je 0x6a010b
// 006a00ca  83f801               cmp eax, 1
// 006a00cd  743c                 je 0x6a010b
// 006a00cf  83f802               cmp eax, 2
// 006a00d2  744d                 je 0x6a0121
// 006a00d4  83f803               cmp eax, 3
// 006a00d7  7521                 jne 0x6a00fa
// 006a00d9  56                   push esi
// 006a00da  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006a00de  8b0e                 mov ecx, dword ptr [esi]
// 006a00e0  682099b300           push 0xb39920
// 006a00e5  ff1568b79800         call dword ptr [0x98b768]
// 006a00eb  0fb6c0               movzx eax, al
// 006a00ee  f7d8                 neg eax
// 006a00f0  1bc0                 sbb eax, eax
// 006a00f2  23442408             and eax, dword ptr [esp + 8]
// 006a00f6  8906                 mov dword ptr [esi], eax
// 006a00f8  5e                   pop esi
// 006a00f9  c3                   ret 
// 006a00fa  8b442408             mov eax, dword ptr [esp + 8]
// 006a00fe  c7002099b300         mov dword ptr [eax], 0xb39920
// 006a0104  884804               mov byte ptr [eax + 4], cl
// 006a0107  884805               mov byte ptr [eax + 5], cl
// 006a010a  c3                   ret 
// 006a010b  8b442408             mov eax, dword ptr [esp + 8]
// 006a010f  3bc1                 cmp eax, ecx
// 006a0111  740e                 je 0x6a0121
// 006a0113  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a0117  8b11                 mov edx, dword ptr [ecx]
// 006a0119  8910                 mov dword ptr [eax], edx
// 006a011b  8b4904               mov ecx, dword ptr [ecx + 4]
// 006a011e  894804               mov dword ptr [eax + 4], ecx
// 006a0121  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb39920 is typeid(F)
extern const type_info type_descriptor_b39920;

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
        if (check_type == type_descriptor_b39920)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b39920;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
