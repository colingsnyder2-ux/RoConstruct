// from server: 100% by nuck16
// roc 2009-12 0074b500  unit: RBX::GroundStage  size: 98 bytes
//
// 0074b500  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074b504  33c9                 xor ecx, ecx
// 0074b506  3bc1                 cmp eax, ecx
// 0074b508  7441                 je 0x74b54b
// 0074b50a  83f801               cmp eax, 1
// 0074b50d  743c                 je 0x74b54b
// 0074b50f  83f802               cmp eax, 2
// 0074b512  744d                 je 0x74b561
// 0074b514  83f803               cmp eax, 3
// 0074b517  7521                 jne 0x74b53a
// 0074b519  56                   push esi
// 0074b51a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074b51e  8b0e                 mov ecx, dword ptr [esi]
// 0074b520  68a07fb500           push 0xb57fa0
// 0074b525  ff1568b79800         call dword ptr [0x98b768]
// 0074b52b  0fb6c0               movzx eax, al
// 0074b52e  f7d8                 neg eax
// 0074b530  1bc0                 sbb eax, eax
// 0074b532  23442408             and eax, dword ptr [esp + 8]
// 0074b536  8906                 mov dword ptr [esi], eax
// 0074b538  5e                   pop esi
// 0074b539  c3                   ret 
// 0074b53a  8b442408             mov eax, dword ptr [esp + 8]
// 0074b53e  c700a07fb500         mov dword ptr [eax], 0xb57fa0
// 0074b544  884804               mov byte ptr [eax + 4], cl
// 0074b547  884805               mov byte ptr [eax + 5], cl
// 0074b54a  c3                   ret 
// 0074b54b  8b442408             mov eax, dword ptr [esp + 8]
// 0074b54f  3bc1                 cmp eax, ecx
// 0074b551  740e                 je 0x74b561
// 0074b553  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0074b557  8b11                 mov edx, dword ptr [ecx]
// 0074b559  8910                 mov dword ptr [eax], edx
// 0074b55b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0074b55e  894804               mov dword ptr [eax + 4], ecx
// 0074b561  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb57fa0 is typeid(F)
extern const type_info type_descriptor_b57fa0;

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
        if (check_type == type_descriptor_b57fa0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b57fa0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
