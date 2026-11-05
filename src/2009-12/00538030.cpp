// from server: 100% by nuck16
// roc 2009-12 00538030  unit: RBX::PAVDebugSettings::?$sp_counted_impl_pd  size: 98 bytes
//
// 00538030  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00538034  33c9                 xor ecx, ecx
// 00538036  3bc1                 cmp eax, ecx
// 00538038  7441                 je 0x53807b
// 0053803a  83f801               cmp eax, 1
// 0053803d  743c                 je 0x53807b
// 0053803f  83f802               cmp eax, 2
// 00538042  744d                 je 0x538091
// 00538044  83f803               cmp eax, 3
// 00538047  7521                 jne 0x53806a
// 00538049  56                   push esi
// 0053804a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0053804e  8b0e                 mov ecx, dword ptr [esi]
// 00538050  6850dbb100           push 0xb1db50
// 00538055  ff1568b79800         call dword ptr [0x98b768]
// 0053805b  0fb6c0               movzx eax, al
// 0053805e  f7d8                 neg eax
// 00538060  1bc0                 sbb eax, eax
// 00538062  23442408             and eax, dword ptr [esp + 8]
// 00538066  8906                 mov dword ptr [esi], eax
// 00538068  5e                   pop esi
// 00538069  c3                   ret 
// 0053806a  8b442408             mov eax, dword ptr [esp + 8]
// 0053806e  c70050dbb100         mov dword ptr [eax], 0xb1db50
// 00538074  884804               mov byte ptr [eax + 4], cl
// 00538077  884805               mov byte ptr [eax + 5], cl
// 0053807a  c3                   ret 
// 0053807b  8b442408             mov eax, dword ptr [esp + 8]
// 0053807f  3bc1                 cmp eax, ecx
// 00538081  740e                 je 0x538091
// 00538083  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00538087  8b11                 mov edx, dword ptr [ecx]
// 00538089  8910                 mov dword ptr [eax], edx
// 0053808b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0053808e  894804               mov dword ptr [eax + 4], ecx
// 00538091  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb1db50 is typeid(F)
extern const type_info type_descriptor_b1db50;

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
        if (check_type == type_descriptor_b1db50)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b1db50;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
