// roc 2012-06 0058f810  unit: RBX::Network::ServerReplicator  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0058f810
//
// 0058f810  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0058f814  33c9                 xor ecx, ecx
// 0058f816  3bc1                 cmp eax, ecx
// 0058f818  7441                 je 0x58f85b
// 0058f81a  83f801               cmp eax, 1
// 0058f81d  743c                 je 0x58f85b
// 0058f81f  83f802               cmp eax, 2
// 0058f822  744d                 je 0x58f871
// 0058f824  83f803               cmp eax, 3
// 0058f827  7521                 jne 0x58f84a
// 0058f829  56                   push esi
// 0058f82a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0058f82e  8b0e                 mov ecx, dword ptr [esi]
// 0058f830  68a8d2d800           push 0xd8d2a8
// 0058f835  ff15ec29b200         call dword ptr [0xb229ec]
// 0058f83b  0fb6c0               movzx eax, al
// 0058f83e  f7d8                 neg eax
// 0058f840  1bc0                 sbb eax, eax
// 0058f842  23442408             and eax, dword ptr [esp + 8]
// 0058f846  8906                 mov dword ptr [esi], eax
// 0058f848  5e                   pop esi
// 0058f849  c3                   ret 
// 0058f84a  8b442408             mov eax, dword ptr [esp + 8]
// 0058f84e  c700a8d2d800         mov dword ptr [eax], 0xd8d2a8
// 0058f854  884804               mov byte ptr [eax + 4], cl
// 0058f857  884805               mov byte ptr [eax + 5], cl
// 0058f85a  c3                   ret 
// 0058f85b  8b442408             mov eax, dword ptr [esp + 8]
// 0058f85f  3bc1                 cmp eax, ecx
// 0058f861  740e                 je 0x58f871
// 0058f863  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0058f867  8b11                 mov edx, dword ptr [ecx]
// 0058f869  8910                 mov dword ptr [eax], edx
// 0058f86b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0058f86e  894804               mov dword ptr [eax + 4], ecx
// 0058f871  c3                   ret 
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