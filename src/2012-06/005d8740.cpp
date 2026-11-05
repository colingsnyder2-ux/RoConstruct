// roc 2012-06 005d8740  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005d8740
//
// 005d8740  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005d8744  33c9                 xor ecx, ecx
// 005d8746  3bc1                 cmp eax, ecx
// 005d8748  7441                 je 0x5d878b
// 005d874a  83f801               cmp eax, 1
// 005d874d  743c                 je 0x5d878b
// 005d874f  83f802               cmp eax, 2
// 005d8752  7453                 je 0x5d87a7
// 005d8754  83f803               cmp eax, 3
// 005d8757  7521                 jne 0x5d877a
// 005d8759  56                   push esi
// 005d875a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d875e  8b0e                 mov ecx, dword ptr [esi]
// 005d8760  68445fd900           push 0xd95f44
// 005d8765  ff15ec29b200         call dword ptr [0xb229ec]
// 005d876b  0fb6c0               movzx eax, al
// 005d876e  f7d8                 neg eax
// 005d8770  1bc0                 sbb eax, eax
// 005d8772  23442408             and eax, dword ptr [esp + 8]
// 005d8776  8906                 mov dword ptr [esi], eax
// 005d8778  5e                   pop esi
// 005d8779  c3                   ret 
// 005d877a  8b442408             mov eax, dword ptr [esp + 8]
// 005d877e  c700445fd900         mov dword ptr [eax], 0xd95f44
// 005d8784  884804               mov byte ptr [eax + 4], cl
// 005d8787  884805               mov byte ptr [eax + 5], cl
// 005d878a  c3                   ret 
// 005d878b  8b442408             mov eax, dword ptr [esp + 8]
// 005d878f  3bc1                 cmp eax, ecx
// 005d8791  7414                 je 0x5d87a7
// 005d8793  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005d8797  8b11                 mov edx, dword ptr [ecx]
// 005d8799  8910                 mov dword ptr [eax], edx
// 005d879b  8b5104               mov edx, dword ptr [ecx + 4]
// 005d879e  895004               mov dword ptr [eax + 4], edx
// 005d87a1  8b4908               mov ecx, dword ptr [ecx + 8]
// 005d87a4  894808               mov dword ptr [eax + 8], ecx
// 005d87a7  c3                   ret 
// copied from an identical function in another client (function ?manage@@YAXABTfunction_buffer@@AAT1@W4functor_manager_operation_type@@@Z)

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