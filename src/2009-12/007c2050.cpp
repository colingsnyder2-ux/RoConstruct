// from server: 100% by nuck16
// roc 2009-12 007c2050  unit: RBX::ImageButton  size: 110 bytes
//
// 007c2050  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007c2054  33c9                 xor ecx, ecx
// 007c2056  3bc1                 cmp eax, ecx
// 007c2058  7441                 je 0x7c209b
// 007c205a  83f801               cmp eax, 1
// 007c205d  743c                 je 0x7c209b
// 007c205f  83f802               cmp eax, 2
// 007c2062  7459                 je 0x7c20bd
// 007c2064  83f803               cmp eax, 3
// 007c2067  7521                 jne 0x7c208a
// 007c2069  56                   push esi
// 007c206a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007c206e  8b0e                 mov ecx, dword ptr [esi]
// 007c2070  68e839b600           push 0xb639e8
// 007c2075  ff1568b79800         call dword ptr [0x98b768]
// 007c207b  0fb6c0               movzx eax, al
// 007c207e  f7d8                 neg eax
// 007c2080  1bc0                 sbb eax, eax
// 007c2082  23442408             and eax, dword ptr [esp + 8]
// 007c2086  8906                 mov dword ptr [esi], eax
// 007c2088  5e                   pop esi
// 007c2089  c3                   ret 
// 007c208a  8b442408             mov eax, dword ptr [esp + 8]
// 007c208e  c700e839b600         mov dword ptr [eax], 0xb639e8
// 007c2094  884804               mov byte ptr [eax + 4], cl
// 007c2097  884805               mov byte ptr [eax + 5], cl
// 007c209a  c3                   ret 
// 007c209b  8b442408             mov eax, dword ptr [esp + 8]
// 007c209f  3bc1                 cmp eax, ecx
// 007c20a1  741a                 je 0x7c20bd
// 007c20a3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007c20a7  8b11                 mov edx, dword ptr [ecx]
// 007c20a9  8910                 mov dword ptr [eax], edx
// 007c20ab  8b5104               mov edx, dword ptr [ecx + 4]
// 007c20ae  895004               mov dword ptr [eax + 4], edx
// 007c20b1  8b5108               mov edx, dword ptr [ecx + 8]
// 007c20b4  895008               mov dword ptr [eax + 8], edx
// 007c20b7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007c20ba  89480c               mov dword ptr [eax + 0xc], ecx
// 007c20bd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb639e8 is typeid(F)
extern const type_info type_descriptor_b639e8;

struct Functor
{
    int f0, f1, f2, f3;
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
    char data[16];
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
        if (check_type == type_descriptor_b639e8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b639e8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
