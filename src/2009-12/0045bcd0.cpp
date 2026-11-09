// from server: 100% by nuck16
// roc 2009-12 0045bcd0  unit: CRobloxReportPaneView  size: 104 bytes
//
// 0045bcd0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0045bcd4  33c9                 xor ecx, ecx
// 0045bcd6  3bc1                 cmp eax, ecx
// 0045bcd8  7441                 je 0x45bd1b
// 0045bcda  83f801               cmp eax, 1
// 0045bcdd  743c                 je 0x45bd1b
// 0045bcdf  83f802               cmp eax, 2
// 0045bce2  7453                 je 0x45bd37
// 0045bce4  83f803               cmp eax, 3
// 0045bce7  7521                 jne 0x45bd0a
// 0045bce9  56                   push esi
// 0045bcea  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0045bcee  8b0e                 mov ecx, dword ptr [esi]
// 0045bcf0  68989eb000           push 0xb09e98
// 0045bcf5  ff1568b79800         call dword ptr [0x98b768]
// 0045bcfb  0fb6c0               movzx eax, al
// 0045bcfe  f7d8                 neg eax
// 0045bd00  1bc0                 sbb eax, eax
// 0045bd02  23442408             and eax, dword ptr [esp + 8]
// 0045bd06  8906                 mov dword ptr [esi], eax
// 0045bd08  5e                   pop esi
// 0045bd09  c3                   ret 
// 0045bd0a  8b442408             mov eax, dword ptr [esp + 8]
// 0045bd0e  c700989eb000         mov dword ptr [eax], 0xb09e98
// 0045bd14  884804               mov byte ptr [eax + 4], cl
// 0045bd17  884805               mov byte ptr [eax + 5], cl
// 0045bd1a  c3                   ret 
// 0045bd1b  8b442408             mov eax, dword ptr [esp + 8]
// 0045bd1f  3bc1                 cmp eax, ecx
// 0045bd21  7414                 je 0x45bd37
// 0045bd23  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0045bd27  8b11                 mov edx, dword ptr [ecx]
// 0045bd29  8910                 mov dword ptr [eax], edx
// 0045bd2b  8b5104               mov edx, dword ptr [ecx + 4]
// 0045bd2e  895004               mov dword ptr [eax + 4], edx
// 0045bd31  8b4908               mov ecx, dword ptr [ecx + 8]
// 0045bd34  894808               mov dword ptr [eax + 8], ecx
// 0045bd37  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb09e98 is typeid(F)
extern const type_info type_descriptor_b09e98;

struct Functor
{
    int f0, f1, f2;
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
    char data[12];
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
        if (check_type == type_descriptor_b09e98)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b09e98;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
