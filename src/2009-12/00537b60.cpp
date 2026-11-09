// from server: 100% by nuck16
// roc 2009-12 00537b60  unit: RBX::Network::Replicator  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00537b60
//
// 00537b60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00537b64  33c9                 xor ecx, ecx
// 00537b66  3bc1                 cmp eax, ecx
// 00537b68  7441                 je 0x537bab
// 00537b6a  83f801               cmp eax, 1
// 00537b6d  743c                 je 0x537bab
// 00537b6f  83f802               cmp eax, 2
// 00537b72  744d                 je 0x537bc1
// 00537b74  83f803               cmp eax, 3
// 00537b77  7521                 jne 0x537b9a
// 00537b79  56                   push esi
// 00537b7a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00537b7e  8b0e                 mov ecx, dword ptr [esi]
// 00537b80  6850d3b100           push 0xb1d350
// 00537b85  ff1568b79800         call dword ptr [0x98b768]
// 00537b8b  0fb6c0               movzx eax, al
// 00537b8e  f7d8                 neg eax
// 00537b90  1bc0                 sbb eax, eax
// 00537b92  23442408             and eax, dword ptr [esp + 8]
// 00537b96  8906                 mov dword ptr [esi], eax
// 00537b98  5e                   pop esi
// 00537b99  c3                   ret 
// 00537b9a  8b442408             mov eax, dword ptr [esp + 8]
// 00537b9e  c70050d3b100         mov dword ptr [eax], 0xb1d350
// 00537ba4  884804               mov byte ptr [eax + 4], cl
// 00537ba7  884805               mov byte ptr [eax + 5], cl
// 00537baa  c3                   ret 
// 00537bab  8b442408             mov eax, dword ptr [esp + 8]
// 00537baf  3bc1                 cmp eax, ecx
// 00537bb1  740e                 je 0x537bc1
// 00537bb3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00537bb7  8b11                 mov edx, dword ptr [ecx]
// 00537bb9  8910                 mov dword ptr [eax], edx
// 00537bbb  8b4904               mov ecx, dword ptr [ecx + 4]
// 00537bbe  894804               mov dword ptr [eax + 4], ecx
// 00537bc1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb1d350 is typeid(F)
extern const type_info type_descriptor_b1d350;

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
        if (check_type == type_descriptor_b1d350)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b1d350;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
