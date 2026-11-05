// from server: 100% by nuck16
// roc 2009-12 00512a90  unit: RBX::Network::Players  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00512a90
//
// 00512a90  56                   push esi
// 00512a91  8b742408             mov esi, dword ptr [esp + 8]
// 00512a95  85f6                 test esi, esi
// 00512a97  742c                 je 0x512ac5
// 00512a99  8b0e                 mov ecx, dword ptr [esi]
// 00512a9b  85c9                 test ecx, ecx
// 00512a9d  7409                 je 0x512aa8
// 00512a9f  8b01                 mov eax, dword ptr [ecx]
// 00512aa1  8b5004               mov edx, dword ptr [eax + 4]
// 00512aa4  ffd2                 call edx
// 00512aa6  eb05                 jmp 0x512aad
// 00512aa8  b80c03b000           mov eax, 0xb0030c
// 00512aad  68e480b100           push 0xb180e4
// 00512ab2  8bc8                 mov ecx, eax
// 00512ab4  ff1568b79800         call dword ptr [0x98b768]
// 00512aba  84c0                 test al, al
// 00512abc  7407                 je 0x512ac5
// 00512abe  8b06                 mov eax, dword ptr [esi]
// 00512ac0  83c004               add eax, 4
// 00512ac3  5e                   pop esi
// 00512ac4  c3                   ret 
// 00512ac5  33c0                 xor eax, eax
// 00512ac7  5e                   pop esi
// 00512ac8  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb180e4 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b180e4;

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

void *func_00512a90(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b180e4)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
