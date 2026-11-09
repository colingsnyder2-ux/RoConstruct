// from server: 100% by nuck16
// roc 2009-12 006924c0  unit: RBX::Tool  size: 110 bytes
//
// 006924c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006924c4  33c9                 xor ecx, ecx
// 006924c6  3bc1                 cmp eax, ecx
// 006924c8  7441                 je 0x69250b
// 006924ca  83f801               cmp eax, 1
// 006924cd  743c                 je 0x69250b
// 006924cf  83f802               cmp eax, 2
// 006924d2  7459                 je 0x69252d
// 006924d4  83f803               cmp eax, 3
// 006924d7  7521                 jne 0x6924fa
// 006924d9  56                   push esi
// 006924da  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006924de  8b0e                 mov ecx, dword ptr [esi]
// 006924e0  68e07eb300           push 0xb37ee0
// 006924e5  ff1568b79800         call dword ptr [0x98b768]
// 006924eb  0fb6c0               movzx eax, al
// 006924ee  f7d8                 neg eax
// 006924f0  1bc0                 sbb eax, eax
// 006924f2  23442408             and eax, dword ptr [esp + 8]
// 006924f6  8906                 mov dword ptr [esi], eax
// 006924f8  5e                   pop esi
// 006924f9  c3                   ret 
// 006924fa  8b442408             mov eax, dword ptr [esp + 8]
// 006924fe  c700e07eb300         mov dword ptr [eax], 0xb37ee0
// 00692504  884804               mov byte ptr [eax + 4], cl
// 00692507  884805               mov byte ptr [eax + 5], cl
// 0069250a  c3                   ret 
// 0069250b  8b442408             mov eax, dword ptr [esp + 8]
// 0069250f  3bc1                 cmp eax, ecx
// 00692511  741a                 je 0x69252d
// 00692513  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00692517  8b11                 mov edx, dword ptr [ecx]
// 00692519  8910                 mov dword ptr [eax], edx
// 0069251b  8b5104               mov edx, dword ptr [ecx + 4]
// 0069251e  895004               mov dword ptr [eax + 4], edx
// 00692521  8b5108               mov edx, dword ptr [ecx + 8]
// 00692524  895008               mov dword ptr [eax + 8], edx
// 00692527  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0069252a  89480c               mov dword ptr [eax + 0xc], ecx
// 0069252d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb37ee0 is typeid(F)
extern const type_info type_descriptor_b37ee0;

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
        if (check_type == type_descriptor_b37ee0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b37ee0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
