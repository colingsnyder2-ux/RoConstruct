// from server: 100% by nuck16
// roc 2009-12 0045f540  unit: CRobloxView  size: 116 bytes
//
// 0045f540  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0045f544  33c9                 xor ecx, ecx
// 0045f546  3bc1                 cmp eax, ecx
// 0045f548  7441                 je 0x45f58b
// 0045f54a  83f801               cmp eax, 1
// 0045f54d  743c                 je 0x45f58b
// 0045f54f  83f802               cmp eax, 2
// 0045f552  745f                 je 0x45f5b3
// 0045f554  83f803               cmp eax, 3
// 0045f557  7521                 jne 0x45f57a
// 0045f559  56                   push esi
// 0045f55a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0045f55e  8b0e                 mov ecx, dword ptr [esi]
// 0045f560  68f0a2b000           push 0xb0a2f0
// 0045f565  ff1568b79800         call dword ptr [0x98b768]
// 0045f56b  0fb6c0               movzx eax, al
// 0045f56e  f7d8                 neg eax
// 0045f570  1bc0                 sbb eax, eax
// 0045f572  23442408             and eax, dword ptr [esp + 8]
// 0045f576  8906                 mov dword ptr [esi], eax
// 0045f578  5e                   pop esi
// 0045f579  c3                   ret 
// 0045f57a  8b442408             mov eax, dword ptr [esp + 8]
// 0045f57e  c700f0a2b000         mov dword ptr [eax], 0xb0a2f0
// 0045f584  884804               mov byte ptr [eax + 4], cl
// 0045f587  884805               mov byte ptr [eax + 5], cl
// 0045f58a  c3                   ret 
// 0045f58b  8b442408             mov eax, dword ptr [esp + 8]
// 0045f58f  3bc1                 cmp eax, ecx
// 0045f591  7420                 je 0x45f5b3
// 0045f593  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0045f597  8b11                 mov edx, dword ptr [ecx]
// 0045f599  8910                 mov dword ptr [eax], edx
// 0045f59b  8b5104               mov edx, dword ptr [ecx + 4]
// 0045f59e  895004               mov dword ptr [eax + 4], edx
// 0045f5a1  8b5108               mov edx, dword ptr [ecx + 8]
// 0045f5a4  895008               mov dword ptr [eax + 8], edx
// 0045f5a7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0045f5aa  89500c               mov dword ptr [eax + 0xc], edx
// 0045f5ad  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0045f5b0  894810               mov dword ptr [eax + 0x10], ecx
// 0045f5b3  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb0a2f0 is typeid(F)
extern const type_info type_descriptor_b0a2f0;

struct Functor
{
    int f0, f1, f2, f3, f4;
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
    char data[20];
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
        if (check_type == type_descriptor_b0a2f0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b0a2f0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
