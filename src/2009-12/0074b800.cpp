// from server: 100% by nuck16
// roc 2009-12 0074b800  unit: RBX::GroundStage  size: 98 bytes
//
// 0074b800  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074b804  33c9                 xor ecx, ecx
// 0074b806  3bc1                 cmp eax, ecx
// 0074b808  7441                 je 0x74b84b
// 0074b80a  83f801               cmp eax, 1
// 0074b80d  743c                 je 0x74b84b
// 0074b80f  83f802               cmp eax, 2
// 0074b812  744d                 je 0x74b861
// 0074b814  83f803               cmp eax, 3
// 0074b817  7521                 jne 0x74b83a
// 0074b819  56                   push esi
// 0074b81a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074b81e  8b0e                 mov ecx, dword ptr [esi]
// 0074b820  685086b500           push 0xb58650
// 0074b825  ff1568b79800         call dword ptr [0x98b768]
// 0074b82b  0fb6c0               movzx eax, al
// 0074b82e  f7d8                 neg eax
// 0074b830  1bc0                 sbb eax, eax
// 0074b832  23442408             and eax, dword ptr [esp + 8]
// 0074b836  8906                 mov dword ptr [esi], eax
// 0074b838  5e                   pop esi
// 0074b839  c3                   ret 
// 0074b83a  8b442408             mov eax, dword ptr [esp + 8]
// 0074b83e  c7005086b500         mov dword ptr [eax], 0xb58650
// 0074b844  884804               mov byte ptr [eax + 4], cl
// 0074b847  884805               mov byte ptr [eax + 5], cl
// 0074b84a  c3                   ret 
// 0074b84b  8b442408             mov eax, dword ptr [esp + 8]
// 0074b84f  3bc1                 cmp eax, ecx
// 0074b851  740e                 je 0x74b861
// 0074b853  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0074b857  8b11                 mov edx, dword ptr [ecx]
// 0074b859  8910                 mov dword ptr [eax], edx
// 0074b85b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0074b85e  894804               mov dword ptr [eax + 4], ecx
// 0074b861  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb58650 is typeid(F)
extern const type_info type_descriptor_b58650;

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
        if (check_type == type_descriptor_b58650)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b58650;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
