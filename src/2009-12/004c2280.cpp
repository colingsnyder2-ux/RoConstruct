// from server: 100% by nuck16
// roc 2009-12 004c2280  unit: Ogre::RbxCluster  size: 98 bytes
//
// 004c2280  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c2284  33c9                 xor ecx, ecx
// 004c2286  3bc1                 cmp eax, ecx
// 004c2288  7441                 je 0x4c22cb
// 004c228a  83f801               cmp eax, 1
// 004c228d  743c                 je 0x4c22cb
// 004c228f  83f802               cmp eax, 2
// 004c2292  744d                 je 0x4c22e1
// 004c2294  83f803               cmp eax, 3
// 004c2297  7521                 jne 0x4c22ba
// 004c2299  56                   push esi
// 004c229a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c229e  8b0e                 mov ecx, dword ptr [esi]
// 004c22a0  68b00ab100           push 0xb10ab0
// 004c22a5  ff1568b79800         call dword ptr [0x98b768]
// 004c22ab  0fb6c0               movzx eax, al
// 004c22ae  f7d8                 neg eax
// 004c22b0  1bc0                 sbb eax, eax
// 004c22b2  23442408             and eax, dword ptr [esp + 8]
// 004c22b6  8906                 mov dword ptr [esi], eax
// 004c22b8  5e                   pop esi
// 004c22b9  c3                   ret 
// 004c22ba  8b442408             mov eax, dword ptr [esp + 8]
// 004c22be  c700b00ab100         mov dword ptr [eax], 0xb10ab0
// 004c22c4  884804               mov byte ptr [eax + 4], cl
// 004c22c7  884805               mov byte ptr [eax + 5], cl
// 004c22ca  c3                   ret 
// 004c22cb  8b442408             mov eax, dword ptr [esp + 8]
// 004c22cf  3bc1                 cmp eax, ecx
// 004c22d1  740e                 je 0x4c22e1
// 004c22d3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c22d7  8b11                 mov edx, dword ptr [ecx]
// 004c22d9  8910                 mov dword ptr [eax], edx
// 004c22db  8b4904               mov ecx, dword ptr [ecx + 4]
// 004c22de  894804               mov dword ptr [eax + 4], ecx
// 004c22e1  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb10ab0 is typeid(F)
extern const type_info type_descriptor_b10ab0;

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
        if (check_type == type_descriptor_b10ab0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b10ab0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
