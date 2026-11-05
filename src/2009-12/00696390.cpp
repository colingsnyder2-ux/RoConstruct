// from server: 100% by nuck16
// roc 2009-12 00696390  unit: RBX::Workspace  size: 104 bytes
//
// 00696390  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00696394  33c9                 xor ecx, ecx
// 00696396  3bc1                 cmp eax, ecx
// 00696398  7441                 je 0x6963db
// 0069639a  83f801               cmp eax, 1
// 0069639d  743c                 je 0x6963db
// 0069639f  83f802               cmp eax, 2
// 006963a2  7453                 je 0x6963f7
// 006963a4  83f803               cmp eax, 3
// 006963a7  7521                 jne 0x6963ca
// 006963a9  56                   push esi
// 006963aa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006963ae  8b0e                 mov ecx, dword ptr [esi]
// 006963b0  68088ab300           push 0xb38a08
// 006963b5  ff1568b79800         call dword ptr [0x98b768]
// 006963bb  0fb6c0               movzx eax, al
// 006963be  f7d8                 neg eax
// 006963c0  1bc0                 sbb eax, eax
// 006963c2  23442408             and eax, dword ptr [esp + 8]
// 006963c6  8906                 mov dword ptr [esi], eax
// 006963c8  5e                   pop esi
// 006963c9  c3                   ret 
// 006963ca  8b442408             mov eax, dword ptr [esp + 8]
// 006963ce  c700088ab300         mov dword ptr [eax], 0xb38a08
// 006963d4  884804               mov byte ptr [eax + 4], cl
// 006963d7  884805               mov byte ptr [eax + 5], cl
// 006963da  c3                   ret 
// 006963db  8b442408             mov eax, dword ptr [esp + 8]
// 006963df  3bc1                 cmp eax, ecx
// 006963e1  7414                 je 0x6963f7
// 006963e3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006963e7  8b11                 mov edx, dword ptr [ecx]
// 006963e9  8910                 mov dword ptr [eax], edx
// 006963eb  8b5104               mov edx, dword ptr [ecx + 4]
// 006963ee  895004               mov dword ptr [eax + 4], edx
// 006963f1  8b4908               mov ecx, dword ptr [ecx + 8]
// 006963f4  894808               mov dword ptr [eax + 8], ecx
// 006963f7  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb38a08 is typeid(F)
extern const type_info type_descriptor_b38a08;

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
        if (check_type == type_descriptor_b38a08)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b38a08;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
