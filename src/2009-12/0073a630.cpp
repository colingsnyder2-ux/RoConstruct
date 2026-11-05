// from server: 100% by nuck16
// roc 2009-12 0073a630  unit: RBX::Rocket  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073a630
//
// 0073a630  56                   push esi
// 0073a631  8b742408             mov esi, dword ptr [esp + 8]
// 0073a635  85f6                 test esi, esi
// 0073a637  742c                 je 0x73a665
// 0073a639  8b0e                 mov ecx, dword ptr [esi]
// 0073a63b  85c9                 test ecx, ecx
// 0073a63d  7409                 je 0x73a648
// 0073a63f  8b01                 mov eax, dword ptr [ecx]
// 0073a641  8b5004               mov edx, dword ptr [eax + 4]
// 0073a644  ffd2                 call edx
// 0073a646  eb05                 jmp 0x73a64d
// 0073a648  b80c03b000           mov eax, 0xb0030c
// 0073a64d  68d01fb400           push 0xb41fd0
// 0073a652  8bc8                 mov ecx, eax
// 0073a654  ff1568b79800         call dword ptr [0x98b768]
// 0073a65a  84c0                 test al, al
// 0073a65c  7407                 je 0x73a665
// 0073a65e  8b06                 mov eax, dword ptr [esi]
// 0073a660  83c004               add eax, 4
// 0073a663  5e                   pop esi
// 0073a664  c3                   ret 
// 0073a665  33c0                 xor eax, eax
// 0073a667  5e                   pop esi
// 0073a668  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb41fd0 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b41fd0;

struct Placeholder
{
    virtual ~Placeholder();
    virtual const type_info &type() const;
};

struct Any
{
    Placeholder *content;
    const type_info &type() const { return content ? content->type() : type_descriptor_b0030c; }
};

struct Holder : Placeholder { int held; };

void *func_0073a630(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b41fd0)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
