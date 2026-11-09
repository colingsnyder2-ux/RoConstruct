// from server: 100% by nuck16
// roc 2009-12 006fcdb0  unit: RBX::VStarterGuiService::?$FactoryProduct  size: 122 bytes
//
// 006fcdb0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006fcdb4  33c9                 xor ecx, ecx
// 006fcdb6  3bc1                 cmp eax, ecx
// 006fcdb8  7441                 je 0x6fcdfb
// 006fcdba  83f801               cmp eax, 1
// 006fcdbd  743c                 je 0x6fcdfb
// 006fcdbf  83f802               cmp eax, 2
// 006fcdc2  7465                 je 0x6fce29
// 006fcdc4  83f803               cmp eax, 3
// 006fcdc7  7521                 jne 0x6fcdea
// 006fcdc9  56                   push esi
// 006fcdca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006fcdce  8b0e                 mov ecx, dword ptr [esi]
// 006fcdd0  68107bb400           push 0xb47b10
// 006fcdd5  ff1568b79800         call dword ptr [0x98b768]
// 006fcddb  0fb6c0               movzx eax, al
// 006fcdde  f7d8                 neg eax
// 006fcde0  1bc0                 sbb eax, eax
// 006fcde2  23442408             and eax, dword ptr [esp + 8]
// 006fcde6  8906                 mov dword ptr [esi], eax
// 006fcde8  5e                   pop esi
// 006fcde9  c3                   ret 
// 006fcdea  8b442408             mov eax, dword ptr [esp + 8]
// 006fcdee  c700107bb400         mov dword ptr [eax], 0xb47b10
// 006fcdf4  884804               mov byte ptr [eax + 4], cl
// 006fcdf7  884805               mov byte ptr [eax + 5], cl
// 006fcdfa  c3                   ret 
// 006fcdfb  8b442408             mov eax, dword ptr [esp + 8]
// 006fcdff  3bc1                 cmp eax, ecx
// 006fce01  7426                 je 0x6fce29
// 006fce03  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006fce07  8b11                 mov edx, dword ptr [ecx]
// 006fce09  8910                 mov dword ptr [eax], edx
// 006fce0b  8b5104               mov edx, dword ptr [ecx + 4]
// 006fce0e  895004               mov dword ptr [eax + 4], edx
// 006fce11  8b5108               mov edx, dword ptr [ecx + 8]
// 006fce14  895008               mov dword ptr [eax + 8], edx
// 006fce17  8b510c               mov edx, dword ptr [ecx + 0xc]
// 006fce1a  89500c               mov dword ptr [eax + 0xc], edx
// 006fce1d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 006fce20  895010               mov dword ptr [eax + 0x10], edx
// 006fce23  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 006fce26  894814               mov dword ptr [eax + 0x14], ecx
// 006fce29  c3                   ret 

#include <typeinfo>
#include <new>

// boost::detail::function::functor_manager<F>::manage for a small, trivially copyable functor
// stored in place; 0xb47b10 is typeid(F)
extern const type_info type_descriptor_b47b10;

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
        if (check_type == type_descriptor_b47b10)
            out_buffer.obj_ptr = (void *)&in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_descriptor_b47b10;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
