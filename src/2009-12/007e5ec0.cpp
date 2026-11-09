// from server: 100% by nuck16
// roc 2009-12 007e5ec0  unit: RBX::TaskScheduler::PAVJob::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 98 bytes
//
// 007e5ec0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e5ec4  33c9                 xor ecx, ecx
// 007e5ec6  3bc1                 cmp eax, ecx
// 007e5ec8  7441                 je 0x7e5f0b
// 007e5eca  83f801               cmp eax, 1
// 007e5ecd  743c                 je 0x7e5f0b
// 007e5ecf  83f802               cmp eax, 2
// 007e5ed2  744d                 je 0x7e5f21
// 007e5ed4  83f803               cmp eax, 3
// 007e5ed7  7521                 jne 0x7e5efa
// 007e5ed9  56                   push esi
// 007e5eda  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007e5ede  8b0e                 mov ecx, dword ptr [esi]
// 007e5ee0  68904cb600           push 0xb64c90
// 007e5ee5  ff1568b79800         call dword ptr [0x98b768]
// 007e5eeb  0fb6c0               movzx eax, al
// 007e5eee  f7d8                 neg eax
// 007e5ef0  1bc0                 sbb eax, eax
// 007e5ef2  23442408             and eax, dword ptr [esp + 8]
// 007e5ef6  8906                 mov dword ptr [esi], eax
// 007e5ef8  5e                   pop esi
// 007e5ef9  c3                   ret 
// 007e5efa  8b442408             mov eax, dword ptr [esp + 8]
// 007e5efe  c700904cb600         mov dword ptr [eax], 0xb64c90
// 007e5f04  884804               mov byte ptr [eax + 4], cl
// 007e5f07  884805               mov byte ptr [eax + 5], cl
// 007e5f0a  c3                   ret 
// 007e5f0b  8b442408             mov eax, dword ptr [esp + 8]
// 007e5f0f  3bc1                 cmp eax, ecx
// 007e5f11  740e                 je 0x7e5f21
// 007e5f13  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e5f17  8b11                 mov edx, dword ptr [ecx]
// 007e5f19  8910                 mov dword ptr [eax], edx
// 007e5f1b  8b4904               mov ecx, dword ptr [ecx + 4]
// 007e5f1e  894804               mov dword ptr [eax + 4], ecx
// 007e5f21  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb64c90 is typeid(F)
extern const type_info type_descriptor_b64c90;

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
        if (check_type == type_descriptor_b64c90)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b64c90;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
