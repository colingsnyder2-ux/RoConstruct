// from server: 100% by nuck16
// roc 2009-12 007c1fe0  unit: RBX::ImageButton  size: 110 bytes
//
// 007c1fe0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007c1fe4  33c9                 xor ecx, ecx
// 007c1fe6  3bc1                 cmp eax, ecx
// 007c1fe8  7441                 je 0x7c202b
// 007c1fea  83f801               cmp eax, 1
// 007c1fed  743c                 je 0x7c202b
// 007c1fef  83f802               cmp eax, 2
// 007c1ff2  7459                 je 0x7c204d
// 007c1ff4  83f803               cmp eax, 3
// 007c1ff7  7521                 jne 0x7c201a
// 007c1ff9  56                   push esi
// 007c1ffa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007c1ffe  8b0e                 mov ecx, dword ptr [esi]
// 007c2000  684839b600           push 0xb63948
// 007c2005  ff1568b79800         call dword ptr [0x98b768]
// 007c200b  0fb6c0               movzx eax, al
// 007c200e  f7d8                 neg eax
// 007c2010  1bc0                 sbb eax, eax
// 007c2012  23442408             and eax, dword ptr [esp + 8]
// 007c2016  8906                 mov dword ptr [esi], eax
// 007c2018  5e                   pop esi
// 007c2019  c3                   ret 
// 007c201a  8b442408             mov eax, dword ptr [esp + 8]
// 007c201e  c7004839b600         mov dword ptr [eax], 0xb63948
// 007c2024  884804               mov byte ptr [eax + 4], cl
// 007c2027  884805               mov byte ptr [eax + 5], cl
// 007c202a  c3                   ret 
// 007c202b  8b442408             mov eax, dword ptr [esp + 8]
// 007c202f  3bc1                 cmp eax, ecx
// 007c2031  741a                 je 0x7c204d
// 007c2033  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007c2037  8b11                 mov edx, dword ptr [ecx]
// 007c2039  8910                 mov dword ptr [eax], edx
// 007c203b  8b5104               mov edx, dword ptr [ecx + 4]
// 007c203e  895004               mov dword ptr [eax + 4], edx
// 007c2041  8b5108               mov edx, dword ptr [ecx + 8]
// 007c2044  895008               mov dword ptr [eax + 8], edx
// 007c2047  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007c204a  89480c               mov dword ptr [eax + 0xc], ecx
// 007c204d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb63948 is typeid(F)
extern const type_info type_descriptor_b63948;

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
        if (check_type == type_descriptor_b63948)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b63948;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
