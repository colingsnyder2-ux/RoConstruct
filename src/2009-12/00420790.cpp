// from server: 100% by nuck16
// roc 2009-12 00420790  unit: CRobloxTreeCtrlNode  size: 98 bytes
//
// 00420790  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00420794  33c9                 xor ecx, ecx
// 00420796  3bc1                 cmp eax, ecx
// 00420798  7441                 je 0x4207db
// 0042079a  83f801               cmp eax, 1
// 0042079d  743c                 je 0x4207db
// 0042079f  83f802               cmp eax, 2
// 004207a2  744d                 je 0x4207f1
// 004207a4  83f803               cmp eax, 3
// 004207a7  7521                 jne 0x4207ca
// 004207a9  56                   push esi
// 004207aa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004207ae  8b0e                 mov ecx, dword ptr [esi]
// 004207b0  688842b000           push 0xb04288
// 004207b5  ff1568b79800         call dword ptr [0x98b768]
// 004207bb  0fb6c0               movzx eax, al
// 004207be  f7d8                 neg eax
// 004207c0  1bc0                 sbb eax, eax
// 004207c2  23442408             and eax, dword ptr [esp + 8]
// 004207c6  8906                 mov dword ptr [esi], eax
// 004207c8  5e                   pop esi
// 004207c9  c3                   ret 
// 004207ca  8b442408             mov eax, dword ptr [esp + 8]
// 004207ce  c7008842b000         mov dword ptr [eax], 0xb04288
// 004207d4  884804               mov byte ptr [eax + 4], cl
// 004207d7  884805               mov byte ptr [eax + 5], cl
// 004207da  c3                   ret 
// 004207db  8b442408             mov eax, dword ptr [esp + 8]
// 004207df  3bc1                 cmp eax, ecx
// 004207e1  740e                 je 0x4207f1
// 004207e3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004207e7  8b11                 mov edx, dword ptr [ecx]
// 004207e9  8910                 mov dword ptr [eax], edx
// 004207eb  8b4904               mov ecx, dword ptr [ecx + 4]
// 004207ee  894804               mov dword ptr [eax + 4], ecx
// 004207f1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb04288 is typeid(F)
extern const type_info type_descriptor_b04288;

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
        if (check_type == type_descriptor_b04288)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b04288;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
