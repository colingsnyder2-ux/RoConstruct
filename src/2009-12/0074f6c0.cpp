// from server: 100% by nuck16
// roc 2009-12 0074f6c0  unit: RBX::VLocalBackpackTool::?$FactoryProduct  size: 110 bytes
//
// 0074f6c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074f6c4  33c9                 xor ecx, ecx
// 0074f6c6  3bc1                 cmp eax, ecx
// 0074f6c8  7441                 je 0x74f70b
// 0074f6ca  83f801               cmp eax, 1
// 0074f6cd  743c                 je 0x74f70b
// 0074f6cf  83f802               cmp eax, 2
// 0074f6d2  7459                 je 0x74f72d
// 0074f6d4  83f803               cmp eax, 3
// 0074f6d7  7521                 jne 0x74f6fa
// 0074f6d9  56                   push esi
// 0074f6da  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074f6de  8b0e                 mov ecx, dword ptr [esi]
// 0074f6e0  68a892b500           push 0xb592a8
// 0074f6e5  ff1568b79800         call dword ptr [0x98b768]
// 0074f6eb  0fb6c0               movzx eax, al
// 0074f6ee  f7d8                 neg eax
// 0074f6f0  1bc0                 sbb eax, eax
// 0074f6f2  23442408             and eax, dword ptr [esp + 8]
// 0074f6f6  8906                 mov dword ptr [esi], eax
// 0074f6f8  5e                   pop esi
// 0074f6f9  c3                   ret 
// 0074f6fa  8b442408             mov eax, dword ptr [esp + 8]
// 0074f6fe  c700a892b500         mov dword ptr [eax], 0xb592a8
// 0074f704  884804               mov byte ptr [eax + 4], cl
// 0074f707  884805               mov byte ptr [eax + 5], cl
// 0074f70a  c3                   ret 
// 0074f70b  8b442408             mov eax, dword ptr [esp + 8]
// 0074f70f  3bc1                 cmp eax, ecx
// 0074f711  741a                 je 0x74f72d
// 0074f713  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0074f717  8b11                 mov edx, dword ptr [ecx]
// 0074f719  8910                 mov dword ptr [eax], edx
// 0074f71b  8b5104               mov edx, dword ptr [ecx + 4]
// 0074f71e  895004               mov dword ptr [eax + 4], edx
// 0074f721  8b5108               mov edx, dword ptr [ecx + 8]
// 0074f724  895008               mov dword ptr [eax + 8], edx
// 0074f727  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0074f72a  89480c               mov dword ptr [eax + 0xc], ecx
// 0074f72d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb592a8 is typeid(F)
extern const type_info type_descriptor_b592a8;

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
        if (check_type == type_descriptor_b592a8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b592a8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
