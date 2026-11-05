// from server: 100% by nuck16
// roc 2009-12 006f4880  unit: RBX::Backpack  size: 98 bytes
//
// 006f4880  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006f4884  33c9                 xor ecx, ecx
// 006f4886  3bc1                 cmp eax, ecx
// 006f4888  7441                 je 0x6f48cb
// 006f488a  83f801               cmp eax, 1
// 006f488d  743c                 je 0x6f48cb
// 006f488f  83f802               cmp eax, 2
// 006f4892  744d                 je 0x6f48e1
// 006f4894  83f803               cmp eax, 3
// 006f4897  7521                 jne 0x6f48ba
// 006f4899  56                   push esi
// 006f489a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006f489e  8b0e                 mov ecx, dword ptr [esi]
// 006f48a0  68b85cb400           push 0xb45cb8
// 006f48a5  ff1568b79800         call dword ptr [0x98b768]
// 006f48ab  0fb6c0               movzx eax, al
// 006f48ae  f7d8                 neg eax
// 006f48b0  1bc0                 sbb eax, eax
// 006f48b2  23442408             and eax, dword ptr [esp + 8]
// 006f48b6  8906                 mov dword ptr [esi], eax
// 006f48b8  5e                   pop esi
// 006f48b9  c3                   ret 
// 006f48ba  8b442408             mov eax, dword ptr [esp + 8]
// 006f48be  c700b85cb400         mov dword ptr [eax], 0xb45cb8
// 006f48c4  884804               mov byte ptr [eax + 4], cl
// 006f48c7  884805               mov byte ptr [eax + 5], cl
// 006f48ca  c3                   ret 
// 006f48cb  8b442408             mov eax, dword ptr [esp + 8]
// 006f48cf  3bc1                 cmp eax, ecx
// 006f48d1  740e                 je 0x6f48e1
// 006f48d3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f48d7  8b11                 mov edx, dword ptr [ecx]
// 006f48d9  8910                 mov dword ptr [eax], edx
// 006f48db  8b4904               mov ecx, dword ptr [ecx + 4]
// 006f48de  894804               mov dword ptr [eax + 4], ecx
// 006f48e1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb45cb8 is typeid(F)
extern const type_info type_descriptor_b45cb8;

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
        if (check_type == type_descriptor_b45cb8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b45cb8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
