// from server: 100% by nuck16
// roc 2009-12 007dde60  unit: RBX::HUMAN::GettingUp  size: 110 bytes
//
// 007dde60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dde64  33c9                 xor ecx, ecx
// 007dde66  3bc1                 cmp eax, ecx
// 007dde68  7441                 je 0x7ddeab
// 007dde6a  83f801               cmp eax, 1
// 007dde6d  743c                 je 0x7ddeab
// 007dde6f  83f802               cmp eax, 2
// 007dde72  7459                 je 0x7ddecd
// 007dde74  83f803               cmp eax, 3
// 007dde77  7521                 jne 0x7dde9a
// 007dde79  56                   push esi
// 007dde7a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007dde7e  8b0e                 mov ecx, dword ptr [esi]
// 007dde80  689044b600           push 0xb64490
// 007dde85  ff1568b79800         call dword ptr [0x98b768]
// 007dde8b  0fb6c0               movzx eax, al
// 007dde8e  f7d8                 neg eax
// 007dde90  1bc0                 sbb eax, eax
// 007dde92  23442408             and eax, dword ptr [esp + 8]
// 007dde96  8906                 mov dword ptr [esi], eax
// 007dde98  5e                   pop esi
// 007dde99  c3                   ret 
// 007dde9a  8b442408             mov eax, dword ptr [esp + 8]
// 007dde9e  c7009044b600         mov dword ptr [eax], 0xb64490
// 007ddea4  884804               mov byte ptr [eax + 4], cl
// 007ddea7  884805               mov byte ptr [eax + 5], cl
// 007ddeaa  c3                   ret 
// 007ddeab  8b442408             mov eax, dword ptr [esp + 8]
// 007ddeaf  3bc1                 cmp eax, ecx
// 007ddeb1  741a                 je 0x7ddecd
// 007ddeb3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007ddeb7  8b11                 mov edx, dword ptr [ecx]
// 007ddeb9  8910                 mov dword ptr [eax], edx
// 007ddebb  8b5104               mov edx, dword ptr [ecx + 4]
// 007ddebe  895004               mov dword ptr [eax + 4], edx
// 007ddec1  8b5108               mov edx, dword ptr [ecx + 8]
// 007ddec4  895008               mov dword ptr [eax + 8], edx
// 007ddec7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007ddeca  89480c               mov dword ptr [eax + 0xc], ecx
// 007ddecd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb64490 is typeid(F)
extern const type_info type_descriptor_b64490;

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
        if (check_type == type_descriptor_b64490)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b64490;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
