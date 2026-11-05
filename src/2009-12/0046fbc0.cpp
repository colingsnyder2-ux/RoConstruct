// from server: 100% by nuck16
// roc 2009-12 0046fbc0  unit: CSelectionCaption  size: 110 bytes
//
// 0046fbc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046fbc4  33c9                 xor ecx, ecx
// 0046fbc6  3bc1                 cmp eax, ecx
// 0046fbc8  7441                 je 0x46fc0b
// 0046fbca  83f801               cmp eax, 1
// 0046fbcd  743c                 je 0x46fc0b
// 0046fbcf  83f802               cmp eax, 2
// 0046fbd2  7459                 je 0x46fc2d
// 0046fbd4  83f803               cmp eax, 3
// 0046fbd7  7521                 jne 0x46fbfa
// 0046fbd9  56                   push esi
// 0046fbda  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0046fbde  8b0e                 mov ecx, dword ptr [esi]
// 0046fbe0  68d0b8b000           push 0xb0b8d0
// 0046fbe5  ff1568b79800         call dword ptr [0x98b768]
// 0046fbeb  0fb6c0               movzx eax, al
// 0046fbee  f7d8                 neg eax
// 0046fbf0  1bc0                 sbb eax, eax
// 0046fbf2  23442408             and eax, dword ptr [esp + 8]
// 0046fbf6  8906                 mov dword ptr [esi], eax
// 0046fbf8  5e                   pop esi
// 0046fbf9  c3                   ret 
// 0046fbfa  8b442408             mov eax, dword ptr [esp + 8]
// 0046fbfe  c700d0b8b000         mov dword ptr [eax], 0xb0b8d0
// 0046fc04  884804               mov byte ptr [eax + 4], cl
// 0046fc07  884805               mov byte ptr [eax + 5], cl
// 0046fc0a  c3                   ret 
// 0046fc0b  8b442408             mov eax, dword ptr [esp + 8]
// 0046fc0f  3bc1                 cmp eax, ecx
// 0046fc11  741a                 je 0x46fc2d
// 0046fc13  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0046fc17  8b11                 mov edx, dword ptr [ecx]
// 0046fc19  8910                 mov dword ptr [eax], edx
// 0046fc1b  8b5104               mov edx, dword ptr [ecx + 4]
// 0046fc1e  895004               mov dword ptr [eax + 4], edx
// 0046fc21  8b5108               mov edx, dword ptr [ecx + 8]
// 0046fc24  895008               mov dword ptr [eax + 8], edx
// 0046fc27  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0046fc2a  89480c               mov dword ptr [eax + 0xc], ecx
// 0046fc2d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb0b8d0 is typeid(F)
extern const type_info type_descriptor_b0b8d0;

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
        if (check_type == type_descriptor_b0b8d0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b0b8d0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
