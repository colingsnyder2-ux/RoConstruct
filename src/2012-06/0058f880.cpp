// roc 2012-06 0058f880  unit: RBX::Network::ServerReplicator  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0058f880
//
// 0058f880  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0058f884  33c9                 xor ecx, ecx
// 0058f886  3bc1                 cmp eax, ecx
// 0058f888  7441                 je 0x58f8cb
// 0058f88a  83f801               cmp eax, 1
// 0058f88d  743c                 je 0x58f8cb
// 0058f88f  83f802               cmp eax, 2
// 0058f892  744d                 je 0x58f8e1
// 0058f894  83f803               cmp eax, 3
// 0058f897  7521                 jne 0x58f8ba
// 0058f899  56                   push esi
// 0058f89a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0058f89e  8b0e                 mov ecx, dword ptr [esi]
// 0058f8a0  6808d3d800           push 0xd8d308
// 0058f8a5  ff15ec29b200         call dword ptr [0xb229ec]
// 0058f8ab  0fb6c0               movzx eax, al
// 0058f8ae  f7d8                 neg eax
// 0058f8b0  1bc0                 sbb eax, eax
// 0058f8b2  23442408             and eax, dword ptr [esp + 8]
// 0058f8b6  8906                 mov dword ptr [esi], eax
// 0058f8b8  5e                   pop esi
// 0058f8b9  c3                   ret 
// 0058f8ba  8b442408             mov eax, dword ptr [esp + 8]
// 0058f8be  c70008d3d800         mov dword ptr [eax], 0xd8d308
// 0058f8c4  884804               mov byte ptr [eax + 4], cl
// 0058f8c7  884805               mov byte ptr [eax + 5], cl
// 0058f8ca  c3                   ret 
// 0058f8cb  8b442408             mov eax, dword ptr [esp + 8]
// 0058f8cf  3bc1                 cmp eax, ecx
// 0058f8d1  740e                 je 0x58f8e1
// 0058f8d3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0058f8d7  8b11                 mov edx, dword ptr [ecx]
// 0058f8d9  8910                 mov dword ptr [eax], edx
// 0058f8db  8b4904               mov ecx, dword ptr [ecx + 4]
// 0058f8de  894804               mov dword ptr [eax + 4], ecx
// 0058f8e1  c3                   ret 
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