// from server: 100% by nuck16
// roc 2009-12 0041d8b0  unit: CSelectionTreeCtrl  size: 110 bytes
//
// 0041d8b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041d8b4  33c9                 xor ecx, ecx
// 0041d8b6  3bc1                 cmp eax, ecx
// 0041d8b8  7441                 je 0x41d8fb
// 0041d8ba  83f801               cmp eax, 1
// 0041d8bd  743c                 je 0x41d8fb
// 0041d8bf  83f802               cmp eax, 2
// 0041d8c2  7459                 je 0x41d91d
// 0041d8c4  83f803               cmp eax, 3
// 0041d8c7  7521                 jne 0x41d8ea
// 0041d8c9  56                   push esi
// 0041d8ca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0041d8ce  8b0e                 mov ecx, dword ptr [esi]
// 0041d8d0  682840b000           push 0xb04028
// 0041d8d5  ff1568b79800         call dword ptr [0x98b768]
// 0041d8db  0fb6c0               movzx eax, al
// 0041d8de  f7d8                 neg eax
// 0041d8e0  1bc0                 sbb eax, eax
// 0041d8e2  23442408             and eax, dword ptr [esp + 8]
// 0041d8e6  8906                 mov dword ptr [esi], eax
// 0041d8e8  5e                   pop esi
// 0041d8e9  c3                   ret 
// 0041d8ea  8b442408             mov eax, dword ptr [esp + 8]
// 0041d8ee  c7002840b000         mov dword ptr [eax], 0xb04028
// 0041d8f4  884804               mov byte ptr [eax + 4], cl
// 0041d8f7  884805               mov byte ptr [eax + 5], cl
// 0041d8fa  c3                   ret 
// 0041d8fb  8b442408             mov eax, dword ptr [esp + 8]
// 0041d8ff  3bc1                 cmp eax, ecx
// 0041d901  741a                 je 0x41d91d
// 0041d903  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041d907  8b11                 mov edx, dword ptr [ecx]
// 0041d909  8910                 mov dword ptr [eax], edx
// 0041d90b  8b5104               mov edx, dword ptr [ecx + 4]
// 0041d90e  895004               mov dword ptr [eax + 4], edx
// 0041d911  8b5108               mov edx, dword ptr [ecx + 8]
// 0041d914  895008               mov dword ptr [eax + 8], edx
// 0041d917  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0041d91a  89480c               mov dword ptr [eax + 0xc], ecx
// 0041d91d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb04028 is typeid(F)
extern const type_info type_descriptor_b04028;

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
        if (check_type == type_descriptor_b04028)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b04028;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
