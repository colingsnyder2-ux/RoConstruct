// from server: 100% by nuck16
// roc 2009-12 0076d870  unit: RBX::VFrame::?$FactoryProduct  size: 98 bytes
//
// 0076d870  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076d874  33c9                 xor ecx, ecx
// 0076d876  3bc1                 cmp eax, ecx
// 0076d878  7441                 je 0x76d8bb
// 0076d87a  83f801               cmp eax, 1
// 0076d87d  743c                 je 0x76d8bb
// 0076d87f  83f802               cmp eax, 2
// 0076d882  744d                 je 0x76d8d1
// 0076d884  83f803               cmp eax, 3
// 0076d887  7521                 jne 0x76d8aa
// 0076d889  56                   push esi
// 0076d88a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0076d88e  8b0e                 mov ecx, dword ptr [esi]
// 0076d890  688009b600           push 0xb60980
// 0076d895  ff1568b79800         call dword ptr [0x98b768]
// 0076d89b  0fb6c0               movzx eax, al
// 0076d89e  f7d8                 neg eax
// 0076d8a0  1bc0                 sbb eax, eax
// 0076d8a2  23442408             and eax, dword ptr [esp + 8]
// 0076d8a6  8906                 mov dword ptr [esi], eax
// 0076d8a8  5e                   pop esi
// 0076d8a9  c3                   ret 
// 0076d8aa  8b442408             mov eax, dword ptr [esp + 8]
// 0076d8ae  c7008009b600         mov dword ptr [eax], 0xb60980
// 0076d8b4  884804               mov byte ptr [eax + 4], cl
// 0076d8b7  884805               mov byte ptr [eax + 5], cl
// 0076d8ba  c3                   ret 
// 0076d8bb  8b442408             mov eax, dword ptr [esp + 8]
// 0076d8bf  3bc1                 cmp eax, ecx
// 0076d8c1  740e                 je 0x76d8d1
// 0076d8c3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0076d8c7  8b11                 mov edx, dword ptr [ecx]
// 0076d8c9  8910                 mov dword ptr [eax], edx
// 0076d8cb  8b4904               mov ecx, dword ptr [ecx + 4]
// 0076d8ce  894804               mov dword ptr [eax + 4], ecx
// 0076d8d1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb60980 is typeid(F)
extern const type_info type_descriptor_b60980;

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
        if (check_type == type_descriptor_b60980)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b60980;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
