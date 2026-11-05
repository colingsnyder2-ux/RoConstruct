// roc 2012-06 00852fd0  unit: RBX::CoreScript  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00852fd0
//
// 00852fd0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00852fd4  33c9                 xor ecx, ecx
// 00852fd6  3bc1                 cmp eax, ecx
// 00852fd8  7441                 je 0x85301b
// 00852fda  83f801               cmp eax, 1
// 00852fdd  743c                 je 0x85301b
// 00852fdf  83f802               cmp eax, 2
// 00852fe2  7459                 je 0x85303d
// 00852fe4  83f803               cmp eax, 3
// 00852fe7  7521                 jne 0x85300a
// 00852fe9  56                   push esi
// 00852fea  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00852fee  8b0e                 mov ecx, dword ptr [esi]
// 00852ff0  689828de00           push 0xde2898
// 00852ff5  ff15ec29b200         call dword ptr [0xb229ec]
// 00852ffb  0fb6c0               movzx eax, al
// 00852ffe  f7d8                 neg eax
// 00853000  1bc0                 sbb eax, eax
// 00853002  23442408             and eax, dword ptr [esp + 8]
// 00853006  8906                 mov dword ptr [esi], eax
// 00853008  5e                   pop esi
// 00853009  c3                   ret 
// 0085300a  8b442408             mov eax, dword ptr [esp + 8]
// 0085300e  c7009828de00         mov dword ptr [eax], 0xde2898
// 00853014  884804               mov byte ptr [eax + 4], cl
// 00853017  884805               mov byte ptr [eax + 5], cl
// 0085301a  c3                   ret 
// 0085301b  8b442408             mov eax, dword ptr [esp + 8]
// 0085301f  3bc1                 cmp eax, ecx
// 00853021  741a                 je 0x85303d
// 00853023  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00853027  8b11                 mov edx, dword ptr [ecx]
// 00853029  8910                 mov dword ptr [eax], edx
// 0085302b  8b5104               mov edx, dword ptr [ecx + 4]
// 0085302e  895004               mov dword ptr [eax + 4], edx
// 00853031  8b5108               mov edx, dword ptr [ecx + 8]
// 00853034  895008               mov dword ptr [eax + 8], edx
// 00853037  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0085303a  89480c               mov dword ptr [eax + 0xc], ecx
// 0085303d  c3                   ret 
// copied from an identical function in another client (function ?manage@@YAXABTfunction_buffer@@AAT1@W4functor_manager_operation_type@@@Z)

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb33668 is typeid(F)
extern const type_info type_descriptor_b33668;

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
        if (check_type == type_descriptor_b33668)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b33668;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}