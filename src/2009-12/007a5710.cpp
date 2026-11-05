// from server: 100% by nuck16
// roc 2009-12 007a5710  unit: RBX::Effect  size: 98 bytes
//
// 007a5710  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007a5714  33c9                 xor ecx, ecx
// 007a5716  3bc1                 cmp eax, ecx
// 007a5718  7441                 je 0x7a575b
// 007a571a  83f801               cmp eax, 1
// 007a571d  743c                 je 0x7a575b
// 007a571f  83f802               cmp eax, 2
// 007a5722  744d                 je 0x7a5771
// 007a5724  83f803               cmp eax, 3
// 007a5727  7521                 jne 0x7a574a
// 007a5729  56                   push esi
// 007a572a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007a572e  8b0e                 mov ecx, dword ptr [esi]
// 007a5730  68e82fb600           push 0xb62fe8
// 007a5735  ff1568b79800         call dword ptr [0x98b768]
// 007a573b  0fb6c0               movzx eax, al
// 007a573e  f7d8                 neg eax
// 007a5740  1bc0                 sbb eax, eax
// 007a5742  23442408             and eax, dword ptr [esp + 8]
// 007a5746  8906                 mov dword ptr [esi], eax
// 007a5748  5e                   pop esi
// 007a5749  c3                   ret 
// 007a574a  8b442408             mov eax, dword ptr [esp + 8]
// 007a574e  c700e82fb600         mov dword ptr [eax], 0xb62fe8
// 007a5754  884804               mov byte ptr [eax + 4], cl
// 007a5757  884805               mov byte ptr [eax + 5], cl
// 007a575a  c3                   ret 
// 007a575b  8b442408             mov eax, dword ptr [esp + 8]
// 007a575f  3bc1                 cmp eax, ecx
// 007a5761  740e                 je 0x7a5771
// 007a5763  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007a5767  8b11                 mov edx, dword ptr [ecx]
// 007a5769  8910                 mov dword ptr [eax], edx
// 007a576b  8b4904               mov ecx, dword ptr [ecx + 4]
// 007a576e  894804               mov dword ptr [eax + 4], ecx
// 007a5771  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb62fe8 is typeid(F)
extern const type_info type_descriptor_b62fe8;

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
        if (check_type == type_descriptor_b62fe8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b62fe8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
