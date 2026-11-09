// from server: 100% by nuck16
// roc 2009-12 0057bb30  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 98 bytes
//
// 0057bb30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0057bb34  33c9                 xor ecx, ecx
// 0057bb36  3bc1                 cmp eax, ecx
// 0057bb38  7441                 je 0x57bb7b
// 0057bb3a  83f801               cmp eax, 1
// 0057bb3d  743c                 je 0x57bb7b
// 0057bb3f  83f802               cmp eax, 2
// 0057bb42  744d                 je 0x57bb91
// 0057bb44  83f803               cmp eax, 3
// 0057bb47  7521                 jne 0x57bb6a
// 0057bb49  56                   push esi
// 0057bb4a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0057bb4e  8b0e                 mov ecx, dword ptr [esi]
// 0057bb50  68104fb200           push 0xb24f10
// 0057bb55  ff1568b79800         call dword ptr [0x98b768]
// 0057bb5b  0fb6c0               movzx eax, al
// 0057bb5e  f7d8                 neg eax
// 0057bb60  1bc0                 sbb eax, eax
// 0057bb62  23442408             and eax, dword ptr [esp + 8]
// 0057bb66  8906                 mov dword ptr [esi], eax
// 0057bb68  5e                   pop esi
// 0057bb69  c3                   ret 
// 0057bb6a  8b442408             mov eax, dword ptr [esp + 8]
// 0057bb6e  c700104fb200         mov dword ptr [eax], 0xb24f10
// 0057bb74  884804               mov byte ptr [eax + 4], cl
// 0057bb77  884805               mov byte ptr [eax + 5], cl
// 0057bb7a  c3                   ret 
// 0057bb7b  8b442408             mov eax, dword ptr [esp + 8]
// 0057bb7f  3bc1                 cmp eax, ecx
// 0057bb81  740e                 je 0x57bb91
// 0057bb83  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0057bb87  8b11                 mov edx, dword ptr [ecx]
// 0057bb89  8910                 mov dword ptr [eax], edx
// 0057bb8b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0057bb8e  894804               mov dword ptr [eax + 4], ecx
// 0057bb91  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb24f10 is typeid(F)
extern const type_info type_descriptor_b24f10;

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
        if (check_type == type_descriptor_b24f10)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b24f10;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
