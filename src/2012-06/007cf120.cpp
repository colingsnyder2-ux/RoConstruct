// roc 2012-06 007cf120  unit: RBX::GuiImageButton  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007cf120
//
// 007cf120  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007cf124  33c9                 xor ecx, ecx
// 007cf126  3bc1                 cmp eax, ecx
// 007cf128  7441                 je 0x7cf16b
// 007cf12a  83f801               cmp eax, 1
// 007cf12d  743c                 je 0x7cf16b
// 007cf12f  83f802               cmp eax, 2
// 007cf132  7465                 je 0x7cf199
// 007cf134  83f803               cmp eax, 3
// 007cf137  7521                 jne 0x7cf15a
// 007cf139  56                   push esi
// 007cf13a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007cf13e  8b0e                 mov ecx, dword ptr [esi]
// 007cf140  6828bcdc00           push 0xdcbc28
// 007cf145  ff15ec29b200         call dword ptr [0xb229ec]
// 007cf14b  0fb6c0               movzx eax, al
// 007cf14e  f7d8                 neg eax
// 007cf150  1bc0                 sbb eax, eax
// 007cf152  23442408             and eax, dword ptr [esp + 8]
// 007cf156  8906                 mov dword ptr [esi], eax
// 007cf158  5e                   pop esi
// 007cf159  c3                   ret 
// 007cf15a  8b442408             mov eax, dword ptr [esp + 8]
// 007cf15e  c70028bcdc00         mov dword ptr [eax], 0xdcbc28
// 007cf164  884804               mov byte ptr [eax + 4], cl
// 007cf167  884805               mov byte ptr [eax + 5], cl
// 007cf16a  c3                   ret 
// 007cf16b  8b442408             mov eax, dword ptr [esp + 8]
// 007cf16f  3bc1                 cmp eax, ecx
// 007cf171  7426                 je 0x7cf199
// 007cf173  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007cf177  8b11                 mov edx, dword ptr [ecx]
// 007cf179  8910                 mov dword ptr [eax], edx
// 007cf17b  8b5104               mov edx, dword ptr [ecx + 4]
// 007cf17e  895004               mov dword ptr [eax + 4], edx
// 007cf181  8b5108               mov edx, dword ptr [ecx + 8]
// 007cf184  895008               mov dword ptr [eax + 8], edx
// 007cf187  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007cf18a  89500c               mov dword ptr [eax + 0xc], edx
// 007cf18d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 007cf190  895010               mov dword ptr [eax + 0x10], edx
// 007cf193  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 007cf196  894814               mov dword ptr [eax + 0x14], ecx
// 007cf199  c3                   ret 
// copied from an identical function in another client (function ?manage@@YAXABTfunction_buffer@@AAT1@W4functor_manager_operation_type@@@Z)

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb2f1b0 is typeid(F)
extern const type_info type_descriptor_b2f1b0;

struct Functor
{
    int f0, f1, f2, f3, f4, f5;
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
    char data[24];
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
        if (check_type == type_descriptor_b2f1b0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b2f1b0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}