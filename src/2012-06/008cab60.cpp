// roc 2012-06 008cab60  unit: RBX::VCornerWedgeInstance::?$FactoryProduct  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008cab60
//
// 008cab60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008cab64  33c9                 xor ecx, ecx
// 008cab66  3bc1                 cmp eax, ecx
// 008cab68  7441                 je 0x8cabab
// 008cab6a  83f801               cmp eax, 1
// 008cab6d  743c                 je 0x8cabab
// 008cab6f  83f802               cmp eax, 2
// 008cab72  7465                 je 0x8cabd9
// 008cab74  83f803               cmp eax, 3
// 008cab77  7521                 jne 0x8cab9a
// 008cab79  56                   push esi
// 008cab7a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008cab7e  8b0e                 mov ecx, dword ptr [esi]
// 008cab80  68d809df00           push 0xdf09d8
// 008cab85  ff15ec29b200         call dword ptr [0xb229ec]
// 008cab8b  0fb6c0               movzx eax, al
// 008cab8e  f7d8                 neg eax
// 008cab90  1bc0                 sbb eax, eax
// 008cab92  23442408             and eax, dword ptr [esp + 8]
// 008cab96  8906                 mov dword ptr [esi], eax
// 008cab98  5e                   pop esi
// 008cab99  c3                   ret 
// 008cab9a  8b442408             mov eax, dword ptr [esp + 8]
// 008cab9e  c700d809df00         mov dword ptr [eax], 0xdf09d8
// 008caba4  884804               mov byte ptr [eax + 4], cl
// 008caba7  884805               mov byte ptr [eax + 5], cl
// 008cabaa  c3                   ret 
// 008cabab  8b442408             mov eax, dword ptr [esp + 8]
// 008cabaf  3bc1                 cmp eax, ecx
// 008cabb1  7426                 je 0x8cabd9
// 008cabb3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008cabb7  8b11                 mov edx, dword ptr [ecx]
// 008cabb9  8910                 mov dword ptr [eax], edx
// 008cabbb  8b5104               mov edx, dword ptr [ecx + 4]
// 008cabbe  895004               mov dword ptr [eax + 4], edx
// 008cabc1  8b5108               mov edx, dword ptr [ecx + 8]
// 008cabc4  895008               mov dword ptr [eax + 8], edx
// 008cabc7  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008cabca  89500c               mov dword ptr [eax + 0xc], edx
// 008cabcd  8b5110               mov edx, dword ptr [ecx + 0x10]
// 008cabd0  895010               mov dword ptr [eax + 0x10], edx
// 008cabd3  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 008cabd6  894814               mov dword ptr [eax + 0x14], ecx
// 008cabd9  c3                   ret 
// copied from an identical function in another client (function ?manage@@YAXABTfunction_buffer@@AAT1@W4functor_manager_operation_type@@@Z)

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb2f1b0 is typeid(F)
extern const type_info type_descriptor_b2f1b0;

struct Functor
{
    int f0, f1, f2, f3, f4, f5;
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
    char data[24];
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
        if (check_type == type_descriptor_b2f1b0)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b2f1b0;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}