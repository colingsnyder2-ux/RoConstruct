// from server: 100% by nuck16
// roc 2009-12 00747550  unit: RBX::Handles  size: 98 bytes
//
// 00747550  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00747554  33c9                 xor ecx, ecx
// 00747556  3bc1                 cmp eax, ecx
// 00747558  7441                 je 0x74759b
// 0074755a  83f801               cmp eax, 1
// 0074755d  743c                 je 0x74759b
// 0074755f  83f802               cmp eax, 2
// 00747562  744d                 je 0x7475b1
// 00747564  83f803               cmp eax, 3
// 00747567  7521                 jne 0x74758a
// 00747569  56                   push esi
// 0074756a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074756e  8b0e                 mov ecx, dword ptr [esi]
// 00747570  68d069b500           push 0xb569d0
// 00747575  ff1568b79800         call dword ptr [0x98b768]
// 0074757b  0fb6c0               movzx eax, al
// 0074757e  f7d8                 neg eax
// 00747580  1bc0                 sbb eax, eax
// 00747582  23442408             and eax, dword ptr [esp + 8]
// 00747586  8906                 mov dword ptr [esi], eax
// 00747588  5e                   pop esi
// 00747589  c3                   ret 
// 0074758a  8b442408             mov eax, dword ptr [esp + 8]
// 0074758e  c700d069b500         mov dword ptr [eax], 0xb569d0
// 00747594  884804               mov byte ptr [eax + 4], cl
// 00747597  884805               mov byte ptr [eax + 5], cl
// 0074759a  c3                   ret 
// 0074759b  8b442408             mov eax, dword ptr [esp + 8]
// 0074759f  3bc1                 cmp eax, ecx
// 007475a1  740e                 je 0x7475b1
// 007475a3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007475a7  8b11                 mov edx, dword ptr [ecx]
// 007475a9  8910                 mov dword ptr [eax], edx
// 007475ab  8b4904               mov ecx, dword ptr [ecx + 4]
// 007475ae  894804               mov dword ptr [eax + 4], ecx
// 007475b1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb569d0 is typeid(F)
extern const type_info type_descriptor_b569d0;

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
        if (check_type == type_descriptor_b569d0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b569d0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
