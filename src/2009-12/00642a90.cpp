// from server: 100% by nuck16
// roc 2009-12 00642a90  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642a90
//
// 00642a90  56                   push esi
// 00642a91  8b742408             mov esi, dword ptr [esp + 8]
// 00642a95  85f6                 test esi, esi
// 00642a97  742c                 je 0x642ac5
// 00642a99  8b0e                 mov ecx, dword ptr [esi]
// 00642a9b  85c9                 test ecx, ecx
// 00642a9d  7409                 je 0x642aa8
// 00642a9f  8b01                 mov eax, dword ptr [ecx]
// 00642aa1  8b5004               mov edx, dword ptr [eax + 4]
// 00642aa4  ffd2                 call edx
// 00642aa6  eb05                 jmp 0x642aad
// 00642aa8  b80c03b000           mov eax, 0xb0030c
// 00642aad  688480b000           push 0xb08084
// 00642ab2  8bc8                 mov ecx, eax
// 00642ab4  ff1568b79800         call dword ptr [0x98b768]
// 00642aba  84c0                 test al, al
// 00642abc  7407                 je 0x642ac5
// 00642abe  8b06                 mov eax, dword ptr [esi]
// 00642ac0  83c004               add eax, 4
// 00642ac3  5e                   pop esi
// 00642ac4  c3                   ret 
// 00642ac5  33c0                 xor eax, eax
// 00642ac7  5e                   pop esi
// 00642ac8  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb08084 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b08084;

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

void *func_00642a90(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b08084)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
