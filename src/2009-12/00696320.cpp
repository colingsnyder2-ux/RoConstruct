// from server: 100% by nuck16
// roc 2009-12 00696320  unit: RBX::Workspace  size: 98 bytes
//
// 00696320  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00696324  33c9                 xor ecx, ecx
// 00696326  3bc1                 cmp eax, ecx
// 00696328  7441                 je 0x69636b
// 0069632a  83f801               cmp eax, 1
// 0069632d  743c                 je 0x69636b
// 0069632f  83f802               cmp eax, 2
// 00696332  744d                 je 0x696381
// 00696334  83f803               cmp eax, 3
// 00696337  7521                 jne 0x69635a
// 00696339  56                   push esi
// 0069633a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0069633e  8b0e                 mov ecx, dword ptr [esi]
// 00696340  689089b300           push 0xb38990
// 00696345  ff1568b79800         call dword ptr [0x98b768]
// 0069634b  0fb6c0               movzx eax, al
// 0069634e  f7d8                 neg eax
// 00696350  1bc0                 sbb eax, eax
// 00696352  23442408             and eax, dword ptr [esp + 8]
// 00696356  8906                 mov dword ptr [esi], eax
// 00696358  5e                   pop esi
// 00696359  c3                   ret 
// 0069635a  8b442408             mov eax, dword ptr [esp + 8]
// 0069635e  c7009089b300         mov dword ptr [eax], 0xb38990
// 00696364  884804               mov byte ptr [eax + 4], cl
// 00696367  884805               mov byte ptr [eax + 5], cl
// 0069636a  c3                   ret 
// 0069636b  8b442408             mov eax, dword ptr [esp + 8]
// 0069636f  3bc1                 cmp eax, ecx
// 00696371  740e                 je 0x696381
// 00696373  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00696377  8b11                 mov edx, dword ptr [ecx]
// 00696379  8910                 mov dword ptr [eax], edx
// 0069637b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0069637e  894804               mov dword ptr [eax + 4], ecx
// 00696381  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb38990 is typeid(F)
extern const type_info type_descriptor_b38990;

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
        if (check_type == type_descriptor_b38990)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b38990;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
