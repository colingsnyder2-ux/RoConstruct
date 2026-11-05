// from server: 100% by nuck16
// roc 2009-12 0041ae00  unit: CInstanceRecord::CNameItem  size: 98 bytes
//
// 0041ae00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041ae04  33c9                 xor ecx, ecx
// 0041ae06  3bc1                 cmp eax, ecx
// 0041ae08  7441                 je 0x41ae4b
// 0041ae0a  83f801               cmp eax, 1
// 0041ae0d  743c                 je 0x41ae4b
// 0041ae0f  83f802               cmp eax, 2
// 0041ae12  744d                 je 0x41ae61
// 0041ae14  83f803               cmp eax, 3
// 0041ae17  7521                 jne 0x41ae3a
// 0041ae19  56                   push esi
// 0041ae1a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0041ae1e  8b0e                 mov ecx, dword ptr [esi]
// 0041ae20  68d03bb000           push 0xb03bd0
// 0041ae25  ff1568b79800         call dword ptr [0x98b768]
// 0041ae2b  0fb6c0               movzx eax, al
// 0041ae2e  f7d8                 neg eax
// 0041ae30  1bc0                 sbb eax, eax
// 0041ae32  23442408             and eax, dword ptr [esp + 8]
// 0041ae36  8906                 mov dword ptr [esi], eax
// 0041ae38  5e                   pop esi
// 0041ae39  c3                   ret 
// 0041ae3a  8b442408             mov eax, dword ptr [esp + 8]
// 0041ae3e  c700d03bb000         mov dword ptr [eax], 0xb03bd0
// 0041ae44  884804               mov byte ptr [eax + 4], cl
// 0041ae47  884805               mov byte ptr [eax + 5], cl
// 0041ae4a  c3                   ret 
// 0041ae4b  8b442408             mov eax, dword ptr [esp + 8]
// 0041ae4f  3bc1                 cmp eax, ecx
// 0041ae51  740e                 je 0x41ae61
// 0041ae53  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041ae57  8b11                 mov edx, dword ptr [ecx]
// 0041ae59  8910                 mov dword ptr [eax], edx
// 0041ae5b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0041ae5e  894804               mov dword ptr [eax + 4], ecx
// 0041ae61  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb03bd0 is typeid(F)
extern const type_info type_descriptor_b03bd0;

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
        if (check_type == type_descriptor_b03bd0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b03bd0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
