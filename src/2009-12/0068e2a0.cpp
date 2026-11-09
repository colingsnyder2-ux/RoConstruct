// from server: 100% by nuck16
// roc 2009-12 0068e2a0  unit: RBX::VHopperBin::?$FactoryProduct  size: 110 bytes
//
// 0068e2a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068e2a4  33c9                 xor ecx, ecx
// 0068e2a6  3bc1                 cmp eax, ecx
// 0068e2a8  7441                 je 0x68e2eb
// 0068e2aa  83f801               cmp eax, 1
// 0068e2ad  743c                 je 0x68e2eb
// 0068e2af  83f802               cmp eax, 2
// 0068e2b2  7459                 je 0x68e30d
// 0068e2b4  83f803               cmp eax, 3
// 0068e2b7  7521                 jne 0x68e2da
// 0068e2b9  56                   push esi
// 0068e2ba  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0068e2be  8b0e                 mov ecx, dword ptr [esi]
// 0068e2c0  68306bb300           push 0xb36b30
// 0068e2c5  ff1568b79800         call dword ptr [0x98b768]
// 0068e2cb  0fb6c0               movzx eax, al
// 0068e2ce  f7d8                 neg eax
// 0068e2d0  1bc0                 sbb eax, eax
// 0068e2d2  23442408             and eax, dword ptr [esp + 8]
// 0068e2d6  8906                 mov dword ptr [esi], eax
// 0068e2d8  5e                   pop esi
// 0068e2d9  c3                   ret 
// 0068e2da  8b442408             mov eax, dword ptr [esp + 8]
// 0068e2de  c700306bb300         mov dword ptr [eax], 0xb36b30
// 0068e2e4  884804               mov byte ptr [eax + 4], cl
// 0068e2e7  884805               mov byte ptr [eax + 5], cl
// 0068e2ea  c3                   ret 
// 0068e2eb  8b442408             mov eax, dword ptr [esp + 8]
// 0068e2ef  3bc1                 cmp eax, ecx
// 0068e2f1  741a                 je 0x68e30d
// 0068e2f3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068e2f7  8b11                 mov edx, dword ptr [ecx]
// 0068e2f9  8910                 mov dword ptr [eax], edx
// 0068e2fb  8b5104               mov edx, dword ptr [ecx + 4]
// 0068e2fe  895004               mov dword ptr [eax + 4], edx
// 0068e301  8b5108               mov edx, dword ptr [ecx + 8]
// 0068e304  895008               mov dword ptr [eax + 8], edx
// 0068e307  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0068e30a  89480c               mov dword ptr [eax + 0xc], ecx
// 0068e30d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb36b30 is typeid(F)
extern const type_info type_descriptor_b36b30;

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
        if (check_type == type_descriptor_b36b30)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b36b30;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
