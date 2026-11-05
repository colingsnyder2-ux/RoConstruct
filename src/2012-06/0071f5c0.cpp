// roc 2012-06 0071f5c0  unit: RBX::PartTool  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071f5c0
//
// 0071f5c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0071f5c4  33c9                 xor ecx, ecx
// 0071f5c6  3bc1                 cmp eax, ecx
// 0071f5c8  7441                 je 0x71f60b
// 0071f5ca  83f801               cmp eax, 1
// 0071f5cd  743c                 je 0x71f60b
// 0071f5cf  83f802               cmp eax, 2
// 0071f5d2  7459                 je 0x71f62d
// 0071f5d4  83f803               cmp eax, 3
// 0071f5d7  7521                 jne 0x71f5fa
// 0071f5d9  56                   push esi
// 0071f5da  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0071f5de  8b0e                 mov ecx, dword ptr [esi]
// 0071f5e0  6800e0da00           push 0xdae000
// 0071f5e5  ff15ec29b200         call dword ptr [0xb229ec]
// 0071f5eb  0fb6c0               movzx eax, al
// 0071f5ee  f7d8                 neg eax
// 0071f5f0  1bc0                 sbb eax, eax
// 0071f5f2  23442408             and eax, dword ptr [esp + 8]
// 0071f5f6  8906                 mov dword ptr [esi], eax
// 0071f5f8  5e                   pop esi
// 0071f5f9  c3                   ret 
// 0071f5fa  8b442408             mov eax, dword ptr [esp + 8]
// 0071f5fe  c70000e0da00         mov dword ptr [eax], 0xdae000
// 0071f604  884804               mov byte ptr [eax + 4], cl
// 0071f607  884805               mov byte ptr [eax + 5], cl
// 0071f60a  c3                   ret 
// 0071f60b  8b442408             mov eax, dword ptr [esp + 8]
// 0071f60f  3bc1                 cmp eax, ecx
// 0071f611  741a                 je 0x71f62d
// 0071f613  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071f617  8b11                 mov edx, dword ptr [ecx]
// 0071f619  8910                 mov dword ptr [eax], edx
// 0071f61b  8b5104               mov edx, dword ptr [ecx + 4]
// 0071f61e  895004               mov dword ptr [eax + 4], edx
// 0071f621  8b5108               mov edx, dword ptr [ecx + 8]
// 0071f624  895008               mov dword ptr [eax + 8], edx
// 0071f627  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0071f62a  89480c               mov dword ptr [eax + 0xc], ecx
// 0071f62d  c3                   ret 
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