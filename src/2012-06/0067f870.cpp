// roc 2012-06 0067f870  unit: VAuthoringSettings::?$FactoryProduct  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0067f870
//
// 0067f870  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0067f874  33c9                 xor ecx, ecx
// 0067f876  3bc1                 cmp eax, ecx
// 0067f878  7441                 je 0x67f8bb
// 0067f87a  83f801               cmp eax, 1
// 0067f87d  743c                 je 0x67f8bb
// 0067f87f  83f802               cmp eax, 2
// 0067f882  744d                 je 0x67f8d1
// 0067f884  83f803               cmp eax, 3
// 0067f887  7521                 jne 0x67f8aa
// 0067f889  56                   push esi
// 0067f88a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0067f88e  8b0e                 mov ecx, dword ptr [esi]
// 0067f890  68588ed900           push 0xd98e58
// 0067f895  ff15ec29b200         call dword ptr [0xb229ec]
// 0067f89b  0fb6c0               movzx eax, al
// 0067f89e  f7d8                 neg eax
// 0067f8a0  1bc0                 sbb eax, eax
// 0067f8a2  23442408             and eax, dword ptr [esp + 8]
// 0067f8a6  8906                 mov dword ptr [esi], eax
// 0067f8a8  5e                   pop esi
// 0067f8a9  c3                   ret 
// 0067f8aa  8b442408             mov eax, dword ptr [esp + 8]
// 0067f8ae  c700588ed900         mov dword ptr [eax], 0xd98e58
// 0067f8b4  884804               mov byte ptr [eax + 4], cl
// 0067f8b7  884805               mov byte ptr [eax + 5], cl
// 0067f8ba  c3                   ret 
// 0067f8bb  8b442408             mov eax, dword ptr [esp + 8]
// 0067f8bf  3bc1                 cmp eax, ecx
// 0067f8c1  740e                 je 0x67f8d1
// 0067f8c3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0067f8c7  8b11                 mov edx, dword ptr [ecx]
// 0067f8c9  8910                 mov dword ptr [eax], edx
// 0067f8cb  8b4904               mov ecx, dword ptr [ecx + 4]
// 0067f8ce  894804               mov dword ptr [eax + 4], ecx
// 0067f8d1  c3                   ret 
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