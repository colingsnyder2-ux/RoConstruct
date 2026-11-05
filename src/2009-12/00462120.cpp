// from server: 100% by nuck16
// roc 2009-12 00462120  unit: RBX::PAVDebugSettings::?$sp_counted_impl_pd  size: 98 bytes
//
// 00462120  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00462124  33c9                 xor ecx, ecx
// 00462126  3bc1                 cmp eax, ecx
// 00462128  7441                 je 0x46216b
// 0046212a  83f801               cmp eax, 1
// 0046212d  743c                 je 0x46216b
// 0046212f  83f802               cmp eax, 2
// 00462132  744d                 je 0x462181
// 00462134  83f803               cmp eax, 3
// 00462137  7521                 jne 0x46215a
// 00462139  56                   push esi
// 0046213a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0046213e  8b0e                 mov ecx, dword ptr [esi]
// 00462140  6818aab000           push 0xb0aa18
// 00462145  ff1568b79800         call dword ptr [0x98b768]
// 0046214b  0fb6c0               movzx eax, al
// 0046214e  f7d8                 neg eax
// 00462150  1bc0                 sbb eax, eax
// 00462152  23442408             and eax, dword ptr [esp + 8]
// 00462156  8906                 mov dword ptr [esi], eax
// 00462158  5e                   pop esi
// 00462159  c3                   ret 
// 0046215a  8b442408             mov eax, dword ptr [esp + 8]
// 0046215e  c70018aab000         mov dword ptr [eax], 0xb0aa18
// 00462164  884804               mov byte ptr [eax + 4], cl
// 00462167  884805               mov byte ptr [eax + 5], cl
// 0046216a  c3                   ret 
// 0046216b  8b442408             mov eax, dword ptr [esp + 8]
// 0046216f  3bc1                 cmp eax, ecx
// 00462171  740e                 je 0x462181
// 00462173  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00462177  8b11                 mov edx, dword ptr [ecx]
// 00462179  8910                 mov dword ptr [eax], edx
// 0046217b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0046217e  894804               mov dword ptr [eax + 4], ecx
// 00462181  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb0aa18 is typeid(F)
extern const type_info type_descriptor_b0aa18;

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
        if (check_type == type_descriptor_b0aa18)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b0aa18;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
