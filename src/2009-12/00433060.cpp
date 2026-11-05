// from server: 100% by nuck16
// roc 2009-12 00433060  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 98 bytes
//
// 00433060  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00433064  33c9                 xor ecx, ecx
// 00433066  3bc1                 cmp eax, ecx
// 00433068  7441                 je 0x4330ab
// 0043306a  83f801               cmp eax, 1
// 0043306d  743c                 je 0x4330ab
// 0043306f  83f802               cmp eax, 2
// 00433072  744d                 je 0x4330c1
// 00433074  83f803               cmp eax, 3
// 00433077  7521                 jne 0x43309a
// 00433079  56                   push esi
// 0043307a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0043307e  8b0e                 mov ecx, dword ptr [esi]
// 00433080  68a855b000           push 0xb055a8
// 00433085  ff1568b79800         call dword ptr [0x98b768]
// 0043308b  0fb6c0               movzx eax, al
// 0043308e  f7d8                 neg eax
// 00433090  1bc0                 sbb eax, eax
// 00433092  23442408             and eax, dword ptr [esp + 8]
// 00433096  8906                 mov dword ptr [esi], eax
// 00433098  5e                   pop esi
// 00433099  c3                   ret 
// 0043309a  8b442408             mov eax, dword ptr [esp + 8]
// 0043309e  c700a855b000         mov dword ptr [eax], 0xb055a8
// 004330a4  884804               mov byte ptr [eax + 4], cl
// 004330a7  884805               mov byte ptr [eax + 5], cl
// 004330aa  c3                   ret 
// 004330ab  8b442408             mov eax, dword ptr [esp + 8]
// 004330af  3bc1                 cmp eax, ecx
// 004330b1  740e                 je 0x4330c1
// 004330b3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004330b7  8b11                 mov edx, dword ptr [ecx]
// 004330b9  8910                 mov dword ptr [eax], edx
// 004330bb  8b4904               mov ecx, dword ptr [ecx + 4]
// 004330be  894804               mov dword ptr [eax + 4], ecx
// 004330c1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb055a8 is typeid(F)
extern const type_info type_descriptor_b055a8;

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
        if (check_type == type_descriptor_b055a8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b055a8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
