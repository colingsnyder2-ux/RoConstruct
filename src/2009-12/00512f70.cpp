// from server: 100% by nuck16
// roc 2009-12 00512f70  unit: RBX::Network::Players  size: 110 bytes
//
// 00512f70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00512f74  33c9                 xor ecx, ecx
// 00512f76  3bc1                 cmp eax, ecx
// 00512f78  7441                 je 0x512fbb
// 00512f7a  83f801               cmp eax, 1
// 00512f7d  743c                 je 0x512fbb
// 00512f7f  83f802               cmp eax, 2
// 00512f82  7459                 je 0x512fdd
// 00512f84  83f803               cmp eax, 3
// 00512f87  7521                 jne 0x512faa
// 00512f89  56                   push esi
// 00512f8a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00512f8e  8b0e                 mov ecx, dword ptr [esi]
// 00512f90  688884b100           push 0xb18488
// 00512f95  ff1568b79800         call dword ptr [0x98b768]
// 00512f9b  0fb6c0               movzx eax, al
// 00512f9e  f7d8                 neg eax
// 00512fa0  1bc0                 sbb eax, eax
// 00512fa2  23442408             and eax, dword ptr [esp + 8]
// 00512fa6  8906                 mov dword ptr [esi], eax
// 00512fa8  5e                   pop esi
// 00512fa9  c3                   ret 
// 00512faa  8b442408             mov eax, dword ptr [esp + 8]
// 00512fae  c7008884b100         mov dword ptr [eax], 0xb18488
// 00512fb4  884804               mov byte ptr [eax + 4], cl
// 00512fb7  884805               mov byte ptr [eax + 5], cl
// 00512fba  c3                   ret 
// 00512fbb  8b442408             mov eax, dword ptr [esp + 8]
// 00512fbf  3bc1                 cmp eax, ecx
// 00512fc1  741a                 je 0x512fdd
// 00512fc3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00512fc7  8b11                 mov edx, dword ptr [ecx]
// 00512fc9  8910                 mov dword ptr [eax], edx
// 00512fcb  8b5104               mov edx, dword ptr [ecx + 4]
// 00512fce  895004               mov dword ptr [eax + 4], edx
// 00512fd1  8b5108               mov edx, dword ptr [ecx + 8]
// 00512fd4  895008               mov dword ptr [eax + 8], edx
// 00512fd7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 00512fda  89480c               mov dword ptr [eax + 0xc], ecx
// 00512fdd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb18488 is typeid(F)
extern const type_info type_descriptor_b18488;

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
        if (check_type == type_descriptor_b18488)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b18488;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
