// from server: 100% by nuck16
// roc 2009-12 00430840  unit: COutputView  size: 98 bytes
//
// 00430840  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00430844  33c9                 xor ecx, ecx
// 00430846  3bc1                 cmp eax, ecx
// 00430848  7441                 je 0x43088b
// 0043084a  83f801               cmp eax, 1
// 0043084d  743c                 je 0x43088b
// 0043084f  83f802               cmp eax, 2
// 00430852  744d                 je 0x4308a1
// 00430854  83f803               cmp eax, 3
// 00430857  7521                 jne 0x43087a
// 00430859  56                   push esi
// 0043085a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0043085e  8b0e                 mov ecx, dword ptr [esi]
// 00430860  689053b000           push 0xb05390
// 00430865  ff1568b79800         call dword ptr [0x98b768]
// 0043086b  0fb6c0               movzx eax, al
// 0043086e  f7d8                 neg eax
// 00430870  1bc0                 sbb eax, eax
// 00430872  23442408             and eax, dword ptr [esp + 8]
// 00430876  8906                 mov dword ptr [esi], eax
// 00430878  5e                   pop esi
// 00430879  c3                   ret 
// 0043087a  8b442408             mov eax, dword ptr [esp + 8]
// 0043087e  c7009053b000         mov dword ptr [eax], 0xb05390
// 00430884  884804               mov byte ptr [eax + 4], cl
// 00430887  884805               mov byte ptr [eax + 5], cl
// 0043088a  c3                   ret 
// 0043088b  8b442408             mov eax, dword ptr [esp + 8]
// 0043088f  3bc1                 cmp eax, ecx
// 00430891  740e                 je 0x4308a1
// 00430893  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00430897  8b11                 mov edx, dword ptr [ecx]
// 00430899  8910                 mov dword ptr [eax], edx
// 0043089b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0043089e  894804               mov dword ptr [eax + 4], ecx
// 004308a1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb05390 is typeid(F)
extern const type_info type_descriptor_b05390;

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
        if (check_type == type_descriptor_b05390)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b05390;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
