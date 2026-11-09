// from server: 100% by nuck16
// roc 2009-12 00682980  unit: RBX::Script  size: 110 bytes
//
// 00682980  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00682984  33c9                 xor ecx, ecx
// 00682986  3bc1                 cmp eax, ecx
// 00682988  7441                 je 0x6829cb
// 0068298a  83f801               cmp eax, 1
// 0068298d  743c                 je 0x6829cb
// 0068298f  83f802               cmp eax, 2
// 00682992  7459                 je 0x6829ed
// 00682994  83f803               cmp eax, 3
// 00682997  7521                 jne 0x6829ba
// 00682999  56                   push esi
// 0068299a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0068299e  8b0e                 mov ecx, dword ptr [esi]
// 006829a0  68c061b300           push 0xb361c0
// 006829a5  ff1568b79800         call dword ptr [0x98b768]
// 006829ab  0fb6c0               movzx eax, al
// 006829ae  f7d8                 neg eax
// 006829b0  1bc0                 sbb eax, eax
// 006829b2  23442408             and eax, dword ptr [esp + 8]
// 006829b6  8906                 mov dword ptr [esi], eax
// 006829b8  5e                   pop esi
// 006829b9  c3                   ret 
// 006829ba  8b442408             mov eax, dword ptr [esp + 8]
// 006829be  c700c061b300         mov dword ptr [eax], 0xb361c0
// 006829c4  884804               mov byte ptr [eax + 4], cl
// 006829c7  884805               mov byte ptr [eax + 5], cl
// 006829ca  c3                   ret 
// 006829cb  8b442408             mov eax, dword ptr [esp + 8]
// 006829cf  3bc1                 cmp eax, ecx
// 006829d1  741a                 je 0x6829ed
// 006829d3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006829d7  8b11                 mov edx, dword ptr [ecx]
// 006829d9  8910                 mov dword ptr [eax], edx
// 006829db  8b5104               mov edx, dword ptr [ecx + 4]
// 006829de  895004               mov dword ptr [eax + 4], edx
// 006829e1  8b5108               mov edx, dword ptr [ecx + 8]
// 006829e4  895008               mov dword ptr [eax + 8], edx
// 006829e7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 006829ea  89480c               mov dword ptr [eax + 0xc], ecx
// 006829ed  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb361c0 is typeid(F)
extern const type_info type_descriptor_b361c0;

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
        if (check_type == type_descriptor_b361c0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b361c0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
