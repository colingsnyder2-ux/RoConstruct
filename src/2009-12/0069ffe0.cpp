// from server: 100% by nuck16
// roc 2009-12 0069ffe0  unit: std::strstream  size: 98 bytes
//
// 0069ffe0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0069ffe4  33c9                 xor ecx, ecx
// 0069ffe6  3bc1                 cmp eax, ecx
// 0069ffe8  7441                 je 0x6a002b
// 0069ffea  83f801               cmp eax, 1
// 0069ffed  743c                 je 0x6a002b
// 0069ffef  83f802               cmp eax, 2
// 0069fff2  744d                 je 0x6a0041
// 0069fff4  83f803               cmp eax, 3
// 0069fff7  7521                 jne 0x6a001a
// 0069fff9  56                   push esi
// 0069fffa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0069fffe  8b0e                 mov ecx, dword ptr [esi]
// 006a0000  689097b300           push 0xb39790
// 006a0005  ff1568b79800         call dword ptr [0x98b768]
// 006a000b  0fb6c0               movzx eax, al
// 006a000e  f7d8                 neg eax
// 006a0010  1bc0                 sbb eax, eax
// 006a0012  23442408             and eax, dword ptr [esp + 8]
// 006a0016  8906                 mov dword ptr [esi], eax
// 006a0018  5e                   pop esi
// 006a0019  c3                   ret 
// 006a001a  8b442408             mov eax, dword ptr [esp + 8]
// 006a001e  c7009097b300         mov dword ptr [eax], 0xb39790
// 006a0024  884804               mov byte ptr [eax + 4], cl
// 006a0027  884805               mov byte ptr [eax + 5], cl
// 006a002a  c3                   ret 
// 006a002b  8b442408             mov eax, dword ptr [esp + 8]
// 006a002f  3bc1                 cmp eax, ecx
// 006a0031  740e                 je 0x6a0041
// 006a0033  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a0037  8b11                 mov edx, dword ptr [ecx]
// 006a0039  8910                 mov dword ptr [eax], edx
// 006a003b  8b4904               mov ecx, dword ptr [ecx + 4]
// 006a003e  894804               mov dword ptr [eax + 4], ecx
// 006a0041  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb39790 is typeid(F)
extern const type_info type_descriptor_b39790;

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
        if (check_type == type_descriptor_b39790)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b39790;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
