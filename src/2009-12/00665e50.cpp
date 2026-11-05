// from server: 100% by nuck16
// roc 2009-12 00665e50  unit: RBX::DataModel::PAVGenericJob::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 98 bytes
//
// 00665e50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00665e54  33c9                 xor ecx, ecx
// 00665e56  3bc1                 cmp eax, ecx
// 00665e58  7441                 je 0x665e9b
// 00665e5a  83f801               cmp eax, 1
// 00665e5d  743c                 je 0x665e9b
// 00665e5f  83f802               cmp eax, 2
// 00665e62  744d                 je 0x665eb1
// 00665e64  83f803               cmp eax, 3
// 00665e67  7521                 jne 0x665e8a
// 00665e69  56                   push esi
// 00665e6a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00665e6e  8b0e                 mov ecx, dword ptr [esi]
// 00665e70  686c34b300           push 0xb3346c
// 00665e75  ff1568b79800         call dword ptr [0x98b768]
// 00665e7b  0fb6c0               movzx eax, al
// 00665e7e  f7d8                 neg eax
// 00665e80  1bc0                 sbb eax, eax
// 00665e82  23442408             and eax, dword ptr [esp + 8]
// 00665e86  8906                 mov dword ptr [esi], eax
// 00665e88  5e                   pop esi
// 00665e89  c3                   ret 
// 00665e8a  8b442408             mov eax, dword ptr [esp + 8]
// 00665e8e  c7006c34b300         mov dword ptr [eax], 0xb3346c
// 00665e94  884804               mov byte ptr [eax + 4], cl
// 00665e97  884805               mov byte ptr [eax + 5], cl
// 00665e9a  c3                   ret 
// 00665e9b  8b442408             mov eax, dword ptr [esp + 8]
// 00665e9f  3bc1                 cmp eax, ecx
// 00665ea1  740e                 je 0x665eb1
// 00665ea3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00665ea7  8b11                 mov edx, dword ptr [ecx]
// 00665ea9  8910                 mov dword ptr [eax], edx
// 00665eab  8b4904               mov ecx, dword ptr [ecx + 4]
// 00665eae  894804               mov dword ptr [eax + 4], ecx
// 00665eb1  c3                   ret 

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
