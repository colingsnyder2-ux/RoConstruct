// from server: 100% by nuck16
// roc 2009-12 00642990  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642990
//
// 00642990  56                   push esi
// 00642991  8b742408             mov esi, dword ptr [esp + 8]
// 00642995  85f6                 test esi, esi
// 00642997  742c                 je 0x6429c5
// 00642999  8b0e                 mov ecx, dword ptr [esi]
// 0064299b  85c9                 test ecx, ecx
// 0064299d  7409                 je 0x6429a8
// 0064299f  8b01                 mov eax, dword ptr [ecx]
// 006429a1  8b5004               mov edx, dword ptr [eax + 4]
// 006429a4  ffd2                 call edx
// 006429a6  eb05                 jmp 0x6429ad
// 006429a8  b80c03b000           mov eax, 0xb0030c
// 006429ad  68d030b100           push 0xb130d0
// 006429b2  8bc8                 mov ecx, eax
// 006429b4  ff1568b79800         call dword ptr [0x98b768]
// 006429ba  84c0                 test al, al
// 006429bc  7407                 je 0x6429c5
// 006429be  8b06                 mov eax, dword ptr [esi]
// 006429c0  83c004               add eax, 4
// 006429c3  5e                   pop esi
// 006429c4  c3                   ret 
// 006429c5  33c0                 xor eax, eax
// 006429c7  5e                   pop esi
// 006429c8  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb130d0 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b130d0;

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

void *func_00642990(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b130d0)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
