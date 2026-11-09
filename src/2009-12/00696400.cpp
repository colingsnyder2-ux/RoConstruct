// from server: 100% by nuck16
// roc 2009-12 00696400  unit: RBX::Workspace  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00696400
//
// 00696400  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00696404  33c9                 xor ecx, ecx
// 00696406  3bc1                 cmp eax, ecx
// 00696408  7441                 je 0x69644b
// 0069640a  83f801               cmp eax, 1
// 0069640d  743c                 je 0x69644b
// 0069640f  83f802               cmp eax, 2
// 00696412  7459                 je 0x69646d
// 00696414  83f803               cmp eax, 3
// 00696417  7521                 jne 0x69643a
// 00696419  56                   push esi
// 0069641a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0069641e  8b0e                 mov ecx, dword ptr [esi]
// 00696420  68c88ab300           push 0xb38ac8
// 00696425  ff1568b79800         call dword ptr [0x98b768]
// 0069642b  0fb6c0               movzx eax, al
// 0069642e  f7d8                 neg eax
// 00696430  1bc0                 sbb eax, eax
// 00696432  23442408             and eax, dword ptr [esp + 8]
// 00696436  8906                 mov dword ptr [esi], eax
// 00696438  5e                   pop esi
// 00696439  c3                   ret 
// 0069643a  8b442408             mov eax, dword ptr [esp + 8]
// 0069643e  c700c88ab300         mov dword ptr [eax], 0xb38ac8
// 00696444  884804               mov byte ptr [eax + 4], cl
// 00696447  884805               mov byte ptr [eax + 5], cl
// 0069644a  c3                   ret 
// 0069644b  8b442408             mov eax, dword ptr [esp + 8]
// 0069644f  3bc1                 cmp eax, ecx
// 00696451  741a                 je 0x69646d
// 00696453  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00696457  8b11                 mov edx, dword ptr [ecx]
// 00696459  8910                 mov dword ptr [eax], edx
// 0069645b  8b5104               mov edx, dword ptr [ecx + 4]
// 0069645e  895004               mov dword ptr [eax + 4], edx
// 00696461  8b5108               mov edx, dword ptr [ecx + 8]
// 00696464  895008               mov dword ptr [eax + 8], edx
// 00696467  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0069646a  89480c               mov dword ptr [eax + 0xc], ecx
// 0069646d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb38ac8 is typeid(F)
extern const type_info type_descriptor_b38ac8;

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
        if (check_type == type_descriptor_b38ac8)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b38ac8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
