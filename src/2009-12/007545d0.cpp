// from server: 100% by nuck16
// roc 2009-12 007545d0  unit: RBX::VehicleSeat  size: 122 bytes
//
// 007545d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007545d4  33c9                 xor ecx, ecx
// 007545d6  3bc1                 cmp eax, ecx
// 007545d8  7441                 je 0x75461b
// 007545da  83f801               cmp eax, 1
// 007545dd  743c                 je 0x75461b
// 007545df  83f802               cmp eax, 2
// 007545e2  7465                 je 0x754649
// 007545e4  83f803               cmp eax, 3
// 007545e7  7521                 jne 0x75460a
// 007545e9  56                   push esi
// 007545ea  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007545ee  8b0e                 mov ecx, dword ptr [esi]
// 007545f0  6888a0b500           push 0xb5a088
// 007545f5  ff1568b79800         call dword ptr [0x98b768]
// 007545fb  0fb6c0               movzx eax, al
// 007545fe  f7d8                 neg eax
// 00754600  1bc0                 sbb eax, eax
// 00754602  23442408             and eax, dword ptr [esp + 8]
// 00754606  8906                 mov dword ptr [esi], eax
// 00754608  5e                   pop esi
// 00754609  c3                   ret 
// 0075460a  8b442408             mov eax, dword ptr [esp + 8]
// 0075460e  c70088a0b500         mov dword ptr [eax], 0xb5a088
// 00754614  884804               mov byte ptr [eax + 4], cl
// 00754617  884805               mov byte ptr [eax + 5], cl
// 0075461a  c3                   ret 
// 0075461b  8b442408             mov eax, dword ptr [esp + 8]
// 0075461f  3bc1                 cmp eax, ecx
// 00754621  7426                 je 0x754649
// 00754623  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00754627  8b11                 mov edx, dword ptr [ecx]
// 00754629  8910                 mov dword ptr [eax], edx
// 0075462b  8b5104               mov edx, dword ptr [ecx + 4]
// 0075462e  895004               mov dword ptr [eax + 4], edx
// 00754631  8b5108               mov edx, dword ptr [ecx + 8]
// 00754634  895008               mov dword ptr [eax + 8], edx
// 00754637  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0075463a  89500c               mov dword ptr [eax + 0xc], edx
// 0075463d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00754640  895010               mov dword ptr [eax + 0x10], edx
// 00754643  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00754646  894814               mov dword ptr [eax + 0x14], ecx
// 00754649  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb5a088 is typeid(F)
extern const type_info type_descriptor_b5a088;

struct Functor
{
    int f0, f1, f2, f3, f4, f5;
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
    char data[24];
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
        if (check_type == type_descriptor_b5a088)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b5a088;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
