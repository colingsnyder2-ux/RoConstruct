// from server: 100% by nuck16
// roc 2009-12 004c22f0  unit: Ogre::RbxCluster  size: 98 bytes
//
// 004c22f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c22f4  33c9                 xor ecx, ecx
// 004c22f6  3bc1                 cmp eax, ecx
// 004c22f8  7441                 je 0x4c233b
// 004c22fa  83f801               cmp eax, 1
// 004c22fd  743c                 je 0x4c233b
// 004c22ff  83f802               cmp eax, 2
// 004c2302  744d                 je 0x4c2351
// 004c2304  83f803               cmp eax, 3
// 004c2307  7521                 jne 0x4c232a
// 004c2309  56                   push esi
// 004c230a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c230e  8b0e                 mov ecx, dword ptr [esi]
// 004c2310  68580bb100           push 0xb10b58
// 004c2315  ff1568b79800         call dword ptr [0x98b768]
// 004c231b  0fb6c0               movzx eax, al
// 004c231e  f7d8                 neg eax
// 004c2320  1bc0                 sbb eax, eax
// 004c2322  23442408             and eax, dword ptr [esp + 8]
// 004c2326  8906                 mov dword ptr [esi], eax
// 004c2328  5e                   pop esi
// 004c2329  c3                   ret 
// 004c232a  8b442408             mov eax, dword ptr [esp + 8]
// 004c232e  c700580bb100         mov dword ptr [eax], 0xb10b58
// 004c2334  884804               mov byte ptr [eax + 4], cl
// 004c2337  884805               mov byte ptr [eax + 5], cl
// 004c233a  c3                   ret 
// 004c233b  8b442408             mov eax, dword ptr [esp + 8]
// 004c233f  3bc1                 cmp eax, ecx
// 004c2341  740e                 je 0x4c2351
// 004c2343  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c2347  8b11                 mov edx, dword ptr [ecx]
// 004c2349  8910                 mov dword ptr [eax], edx
// 004c234b  8b4904               mov ecx, dword ptr [ecx + 4]
// 004c234e  894804               mov dword ptr [eax + 4], ecx
// 004c2351  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb10b58 is typeid(F)
extern const type_info type_descriptor_b10b58;

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
        if (check_type == type_descriptor_b10b58)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b10b58;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
