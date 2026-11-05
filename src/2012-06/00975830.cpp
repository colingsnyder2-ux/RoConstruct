// roc 2012-06 00975830  unit: RBX::TaskScheduler::PAVJob::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00975830
//
// 00975830  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00975834  33c9                 xor ecx, ecx
// 00975836  3bc1                 cmp eax, ecx
// 00975838  7441                 je 0x97587b
// 0097583a  83f801               cmp eax, 1
// 0097583d  743c                 je 0x97587b
// 0097583f  83f802               cmp eax, 2
// 00975842  744d                 je 0x975891
// 00975844  83f803               cmp eax, 3
// 00975847  7521                 jne 0x97586a
// 00975849  56                   push esi
// 0097584a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0097584e  8b0e                 mov ecx, dword ptr [esi]
// 00975850  68f822e000           push 0xe022f8
// 00975855  ff15ec29b200         call dword ptr [0xb229ec]
// 0097585b  0fb6c0               movzx eax, al
// 0097585e  f7d8                 neg eax
// 00975860  1bc0                 sbb eax, eax
// 00975862  23442408             and eax, dword ptr [esp + 8]
// 00975866  8906                 mov dword ptr [esi], eax
// 00975868  5e                   pop esi
// 00975869  c3                   ret 
// 0097586a  8b442408             mov eax, dword ptr [esp + 8]
// 0097586e  c700f822e000         mov dword ptr [eax], 0xe022f8
// 00975874  884804               mov byte ptr [eax + 4], cl
// 00975877  884805               mov byte ptr [eax + 5], cl
// 0097587a  c3                   ret 
// 0097587b  8b442408             mov eax, dword ptr [esp + 8]
// 0097587f  3bc1                 cmp eax, ecx
// 00975881  740e                 je 0x975891
// 00975883  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00975887  8b11                 mov edx, dword ptr [ecx]
// 00975889  8910                 mov dword ptr [eax], edx
// 0097588b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0097588e  894804               mov dword ptr [eax + 4], ecx
// 00975891  c3                   ret 
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