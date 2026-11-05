// roc 2012-06 006a2ba0  unit: std::D::DU?$char_traits::?$basic_istringstream  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a2ba0
//
// 006a2ba0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006a2ba4  33c9                 xor ecx, ecx
// 006a2ba6  3bc1                 cmp eax, ecx
// 006a2ba8  7441                 je 0x6a2beb
// 006a2baa  83f801               cmp eax, 1
// 006a2bad  743c                 je 0x6a2beb
// 006a2baf  83f802               cmp eax, 2
// 006a2bb2  744d                 je 0x6a2c01
// 006a2bb4  83f803               cmp eax, 3
// 006a2bb7  7521                 jne 0x6a2bda
// 006a2bb9  56                   push esi
// 006a2bba  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006a2bbe  8b0e                 mov ecx, dword ptr [esi]
// 006a2bc0  68d8e8d900           push 0xd9e8d8
// 006a2bc5  ff15ec29b200         call dword ptr [0xb229ec]
// 006a2bcb  0fb6c0               movzx eax, al
// 006a2bce  f7d8                 neg eax
// 006a2bd0  1bc0                 sbb eax, eax
// 006a2bd2  23442408             and eax, dword ptr [esp + 8]
// 006a2bd6  8906                 mov dword ptr [esi], eax
// 006a2bd8  5e                   pop esi
// 006a2bd9  c3                   ret 
// 006a2bda  8b442408             mov eax, dword ptr [esp + 8]
// 006a2bde  c700d8e8d900         mov dword ptr [eax], 0xd9e8d8
// 006a2be4  884804               mov byte ptr [eax + 4], cl
// 006a2be7  884805               mov byte ptr [eax + 5], cl
// 006a2bea  c3                   ret 
// 006a2beb  8b442408             mov eax, dword ptr [esp + 8]
// 006a2bef  3bc1                 cmp eax, ecx
// 006a2bf1  740e                 je 0x6a2c01
// 006a2bf3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a2bf7  8b11                 mov edx, dword ptr [ecx]
// 006a2bf9  8910                 mov dword ptr [eax], edx
// 006a2bfb  8b4904               mov ecx, dword ptr [ecx + 4]
// 006a2bfe  894804               mov dword ptr [eax + 4], ecx
// 006a2c01  c3                   ret 
// copied from an identical function in another client (function ?manage@@YAXABTfunction_buffer@@AAT1@W4functor_manager_operation_type@@@Z)

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb3346c is typeid(F)
extern const type_info type_descriptor_b3346c;

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
        if (check_type == type_descriptor_b3346c)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b3346c;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}