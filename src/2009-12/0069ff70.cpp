// from server: 100% by nuck16
// roc 2009-12 0069ff70  unit: std::strstream  size: 98 bytes
//
// 0069ff70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0069ff74  33c9                 xor ecx, ecx
// 0069ff76  3bc1                 cmp eax, ecx
// 0069ff78  7441                 je 0x69ffbb
// 0069ff7a  83f801               cmp eax, 1
// 0069ff7d  743c                 je 0x69ffbb
// 0069ff7f  83f802               cmp eax, 2
// 0069ff82  744d                 je 0x69ffd1
// 0069ff84  83f803               cmp eax, 3
// 0069ff87  7521                 jne 0x69ffaa
// 0069ff89  56                   push esi
// 0069ff8a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0069ff8e  8b0e                 mov ecx, dword ptr [esi]
// 0069ff90  683097b300           push 0xb39730
// 0069ff95  ff1568b79800         call dword ptr [0x98b768]
// 0069ff9b  0fb6c0               movzx eax, al
// 0069ff9e  f7d8                 neg eax
// 0069ffa0  1bc0                 sbb eax, eax
// 0069ffa2  23442408             and eax, dword ptr [esp + 8]
// 0069ffa6  8906                 mov dword ptr [esi], eax
// 0069ffa8  5e                   pop esi
// 0069ffa9  c3                   ret 
// 0069ffaa  8b442408             mov eax, dword ptr [esp + 8]
// 0069ffae  c7003097b300         mov dword ptr [eax], 0xb39730
// 0069ffb4  884804               mov byte ptr [eax + 4], cl
// 0069ffb7  884805               mov byte ptr [eax + 5], cl
// 0069ffba  c3                   ret 
// 0069ffbb  8b442408             mov eax, dword ptr [esp + 8]
// 0069ffbf  3bc1                 cmp eax, ecx
// 0069ffc1  740e                 je 0x69ffd1
// 0069ffc3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0069ffc7  8b11                 mov edx, dword ptr [ecx]
// 0069ffc9  8910                 mov dword ptr [eax], edx
// 0069ffcb  8b4904               mov ecx, dword ptr [ecx + 4]
// 0069ffce  894804               mov dword ptr [eax + 4], ecx
// 0069ffd1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb39730 is typeid(F)
extern const type_info type_descriptor_b39730;

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
        if (check_type == type_descriptor_b39730)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b39730;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
