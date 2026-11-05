// from server: 100% by nuck16
// roc 2009-12 00744300  unit: RBX::Flag  size: 110 bytes
//
// 00744300  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00744304  33c9                 xor ecx, ecx
// 00744306  3bc1                 cmp eax, ecx
// 00744308  7441                 je 0x74434b
// 0074430a  83f801               cmp eax, 1
// 0074430d  743c                 je 0x74434b
// 0074430f  83f802               cmp eax, 2
// 00744312  7459                 je 0x74436d
// 00744314  83f803               cmp eax, 3
// 00744317  7521                 jne 0x74433a
// 00744319  56                   push esi
// 0074431a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074431e  8b0e                 mov ecx, dword ptr [esi]
// 00744320  68d85bb500           push 0xb55bd8
// 00744325  ff1568b79800         call dword ptr [0x98b768]
// 0074432b  0fb6c0               movzx eax, al
// 0074432e  f7d8                 neg eax
// 00744330  1bc0                 sbb eax, eax
// 00744332  23442408             and eax, dword ptr [esp + 8]
// 00744336  8906                 mov dword ptr [esi], eax
// 00744338  5e                   pop esi
// 00744339  c3                   ret 
// 0074433a  8b442408             mov eax, dword ptr [esp + 8]
// 0074433e  c700d85bb500         mov dword ptr [eax], 0xb55bd8
// 00744344  884804               mov byte ptr [eax + 4], cl
// 00744347  884805               mov byte ptr [eax + 5], cl
// 0074434a  c3                   ret 
// 0074434b  8b442408             mov eax, dword ptr [esp + 8]
// 0074434f  3bc1                 cmp eax, ecx
// 00744351  741a                 je 0x74436d
// 00744353  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00744357  8b11                 mov edx, dword ptr [ecx]
// 00744359  8910                 mov dword ptr [eax], edx
// 0074435b  8b5104               mov edx, dword ptr [ecx + 4]
// 0074435e  895004               mov dword ptr [eax + 4], edx
// 00744361  8b5108               mov edx, dword ptr [ecx + 8]
// 00744364  895008               mov dword ptr [eax + 8], edx
// 00744367  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0074436a  89480c               mov dword ptr [eax + 0xc], ecx
// 0074436d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb55bd8 is typeid(F)
extern const type_info type_descriptor_b55bd8;

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
        if (check_type == type_descriptor_b55bd8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b55bd8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
