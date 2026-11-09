// from server: 100% by nuck16
// roc 2009-12 0052bbf0  unit: RBX::Network::Server  size: 110 bytes
//
// 0052bbf0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0052bbf4  33c9                 xor ecx, ecx
// 0052bbf6  3bc1                 cmp eax, ecx
// 0052bbf8  7441                 je 0x52bc3b
// 0052bbfa  83f801               cmp eax, 1
// 0052bbfd  743c                 je 0x52bc3b
// 0052bbff  83f802               cmp eax, 2
// 0052bc02  7459                 je 0x52bc5d
// 0052bc04  83f803               cmp eax, 3
// 0052bc07  7521                 jne 0x52bc2a
// 0052bc09  56                   push esi
// 0052bc0a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0052bc0e  8b0e                 mov ecx, dword ptr [esi]
// 0052bc10  6850bfb100           push 0xb1bf50
// 0052bc15  ff1568b79800         call dword ptr [0x98b768]
// 0052bc1b  0fb6c0               movzx eax, al
// 0052bc1e  f7d8                 neg eax
// 0052bc20  1bc0                 sbb eax, eax
// 0052bc22  23442408             and eax, dword ptr [esp + 8]
// 0052bc26  8906                 mov dword ptr [esi], eax
// 0052bc28  5e                   pop esi
// 0052bc29  c3                   ret 
// 0052bc2a  8b442408             mov eax, dword ptr [esp + 8]
// 0052bc2e  c70050bfb100         mov dword ptr [eax], 0xb1bf50
// 0052bc34  884804               mov byte ptr [eax + 4], cl
// 0052bc37  884805               mov byte ptr [eax + 5], cl
// 0052bc3a  c3                   ret 
// 0052bc3b  8b442408             mov eax, dword ptr [esp + 8]
// 0052bc3f  3bc1                 cmp eax, ecx
// 0052bc41  741a                 je 0x52bc5d
// 0052bc43  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0052bc47  8b11                 mov edx, dword ptr [ecx]
// 0052bc49  8910                 mov dword ptr [eax], edx
// 0052bc4b  8b5104               mov edx, dword ptr [ecx + 4]
// 0052bc4e  895004               mov dword ptr [eax + 4], edx
// 0052bc51  8b5108               mov edx, dword ptr [ecx + 8]
// 0052bc54  895008               mov dword ptr [eax + 8], edx
// 0052bc57  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0052bc5a  89480c               mov dword ptr [eax + 0xc], ecx
// 0052bc5d  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb1bf50 is typeid(F)
extern const type_info type_descriptor_b1bf50;

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
        if (check_type == type_descriptor_b1bf50)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b1bf50;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
