// from server: 100% by nuck16
// roc 2009-12 00696240  unit: RBX::Workspace  size: 110 bytes
//
// 00696240  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00696244  33c9                 xor ecx, ecx
// 00696246  3bc1                 cmp eax, ecx
// 00696248  7441                 je 0x69628b
// 0069624a  83f801               cmp eax, 1
// 0069624d  743c                 je 0x69628b
// 0069624f  83f802               cmp eax, 2
// 00696252  7459                 je 0x6962ad
// 00696254  83f803               cmp eax, 3
// 00696257  7521                 jne 0x69627a
// 00696259  56                   push esi
// 0069625a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0069625e  8b0e                 mov ecx, dword ptr [esi]
// 00696260  689088b300           push 0xb38890
// 00696265  ff1568b79800         call dword ptr [0x98b768]
// 0069626b  0fb6c0               movzx eax, al
// 0069626e  f7d8                 neg eax
// 00696270  1bc0                 sbb eax, eax
// 00696272  23442408             and eax, dword ptr [esp + 8]
// 00696276  8906                 mov dword ptr [esi], eax
// 00696278  5e                   pop esi
// 00696279  c3                   ret 
// 0069627a  8b442408             mov eax, dword ptr [esp + 8]
// 0069627e  c7009088b300         mov dword ptr [eax], 0xb38890
// 00696284  884804               mov byte ptr [eax + 4], cl
// 00696287  884805               mov byte ptr [eax + 5], cl
// 0069628a  c3                   ret 
// 0069628b  8b442408             mov eax, dword ptr [esp + 8]
// 0069628f  3bc1                 cmp eax, ecx
// 00696291  741a                 je 0x6962ad
// 00696293  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00696297  8b11                 mov edx, dword ptr [ecx]
// 00696299  8910                 mov dword ptr [eax], edx
// 0069629b  8b5104               mov edx, dword ptr [ecx + 4]
// 0069629e  895004               mov dword ptr [eax + 4], edx
// 006962a1  8b5108               mov edx, dword ptr [ecx + 8]
// 006962a4  895008               mov dword ptr [eax + 8], edx
// 006962a7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 006962aa  89480c               mov dword ptr [eax + 0xc], ecx
// 006962ad  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb38890 is typeid(F)
extern const type_info type_descriptor_b38890;

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
        if (check_type == type_descriptor_b38890)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b38890;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
