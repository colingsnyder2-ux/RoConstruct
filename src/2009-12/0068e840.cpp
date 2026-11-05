// from server: 100% by nuck16
// roc 2009-12 0068e840  unit: ChatEnter  size: 98 bytes
//
// 0068e840  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068e844  33c9                 xor ecx, ecx
// 0068e846  3bc1                 cmp eax, ecx
// 0068e848  7441                 je 0x68e88b
// 0068e84a  83f801               cmp eax, 1
// 0068e84d  743c                 je 0x68e88b
// 0068e84f  83f802               cmp eax, 2
// 0068e852  744d                 je 0x68e8a1
// 0068e854  83f803               cmp eax, 3
// 0068e857  7521                 jne 0x68e87a
// 0068e859  56                   push esi
// 0068e85a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0068e85e  8b0e                 mov ecx, dword ptr [esi]
// 0068e860  68c871b300           push 0xb371c8
// 0068e865  ff1568b79800         call dword ptr [0x98b768]
// 0068e86b  0fb6c0               movzx eax, al
// 0068e86e  f7d8                 neg eax
// 0068e870  1bc0                 sbb eax, eax
// 0068e872  23442408             and eax, dword ptr [esp + 8]
// 0068e876  8906                 mov dword ptr [esi], eax
// 0068e878  5e                   pop esi
// 0068e879  c3                   ret 
// 0068e87a  8b442408             mov eax, dword ptr [esp + 8]
// 0068e87e  c700c871b300         mov dword ptr [eax], 0xb371c8
// 0068e884  884804               mov byte ptr [eax + 4], cl
// 0068e887  884805               mov byte ptr [eax + 5], cl
// 0068e88a  c3                   ret 
// 0068e88b  8b442408             mov eax, dword ptr [esp + 8]
// 0068e88f  3bc1                 cmp eax, ecx
// 0068e891  740e                 je 0x68e8a1
// 0068e893  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068e897  8b11                 mov edx, dword ptr [ecx]
// 0068e899  8910                 mov dword ptr [eax], edx
// 0068e89b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0068e89e  894804               mov dword ptr [eax + 4], ecx
// 0068e8a1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb371c8 is typeid(F)
extern const type_info type_descriptor_b371c8;

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
        if (check_type == type_descriptor_b371c8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b371c8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
