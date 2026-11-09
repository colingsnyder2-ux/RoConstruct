// from server: 100% by nuck16
// roc 2009-12 004c2360  unit: Ogre::RbxCluster  size: 110 bytes
//
// 004c2360  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c2364  33c9                 xor ecx, ecx
// 004c2366  3bc1                 cmp eax, ecx
// 004c2368  7441                 je 0x4c23ab
// 004c236a  83f801               cmp eax, 1
// 004c236d  743c                 je 0x4c23ab
// 004c236f  83f802               cmp eax, 2
// 004c2372  7459                 je 0x4c23cd
// 004c2374  83f803               cmp eax, 3
// 004c2377  7521                 jne 0x4c239a
// 004c2379  56                   push esi
// 004c237a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c237e  8b0e                 mov ecx, dword ptr [esi]
// 004c2380  68080cb100           push 0xb10c08
// 004c2385  ff1568b79800         call dword ptr [0x98b768]
// 004c238b  0fb6c0               movzx eax, al
// 004c238e  f7d8                 neg eax
// 004c2390  1bc0                 sbb eax, eax
// 004c2392  23442408             and eax, dword ptr [esp + 8]
// 004c2396  8906                 mov dword ptr [esi], eax
// 004c2398  5e                   pop esi
// 004c2399  c3                   ret 
// 004c239a  8b442408             mov eax, dword ptr [esp + 8]
// 004c239e  c700080cb100         mov dword ptr [eax], 0xb10c08
// 004c23a4  884804               mov byte ptr [eax + 4], cl
// 004c23a7  884805               mov byte ptr [eax + 5], cl
// 004c23aa  c3                   ret 
// 004c23ab  8b442408             mov eax, dword ptr [esp + 8]
// 004c23af  3bc1                 cmp eax, ecx
// 004c23b1  741a                 je 0x4c23cd
// 004c23b3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c23b7  8b11                 mov edx, dword ptr [ecx]
// 004c23b9  8910                 mov dword ptr [eax], edx
// 004c23bb  8b5104               mov edx, dword ptr [ecx + 4]
// 004c23be  895004               mov dword ptr [eax + 4], edx
// 004c23c1  8b5108               mov edx, dword ptr [ecx + 8]
// 004c23c4  895008               mov dword ptr [eax + 8], edx
// 004c23c7  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 004c23ca  89480c               mov dword ptr [eax + 0xc], ecx
// 004c23cd  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb10c08 is typeid(F)
extern const type_info type_descriptor_b10c08;

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
        if (check_type == type_descriptor_b10c08)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b10c08;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
