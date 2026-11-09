// roc 2012-06 00540a30  unit: RBX::VObjectValue::?$FactoryProduct::Creator  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00540a30
//
// 00540a30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00540a34  33c9                 xor ecx, ecx
// 00540a36  3bc1                 cmp eax, ecx
// 00540a38  7441                 je 0x540a7b
// 00540a3a  83f801               cmp eax, 1
// 00540a3d  743c                 je 0x540a7b
// 00540a3f  83f802               cmp eax, 2
// 00540a42  744d                 je 0x540a91
// 00540a44  83f803               cmp eax, 3
// 00540a47  7521                 jne 0x540a6a
// 00540a49  56                   push esi
// 00540a4a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00540a4e  8b0e                 mov ecx, dword ptr [esi]
// 00540a50  680023d800           push 0xd82300
// 00540a55  ff15ec29b200         call dword ptr [0xb229ec]
// 00540a5b  0fb6c0               movzx eax, al
// 00540a5e  f7d8                 neg eax
// 00540a60  1bc0                 sbb eax, eax
// 00540a62  23442408             and eax, dword ptr [esp + 8]
// 00540a66  8906                 mov dword ptr [esi], eax
// 00540a68  5e                   pop esi
// 00540a69  c3                   ret 
// 00540a6a  8b442408             mov eax, dword ptr [esp + 8]
// 00540a6e  c7000023d800         mov dword ptr [eax], 0xd82300
// 00540a74  884804               mov byte ptr [eax + 4], cl
// 00540a77  884805               mov byte ptr [eax + 5], cl
// 00540a7a  c3                   ret 
// 00540a7b  8b442408             mov eax, dword ptr [esp + 8]
// 00540a7f  3bc1                 cmp eax, ecx
// 00540a81  740e                 je 0x540a91
// 00540a83  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00540a87  8b11                 mov edx, dword ptr [ecx]
// 00540a89  8910                 mov dword ptr [eax], edx
// 00540a8b  8b4904               mov ecx, dword ptr [ecx + 4]
// 00540a8e  894804               mov dword ptr [eax + 4], ecx
// 00540a91  c3                   ret 
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