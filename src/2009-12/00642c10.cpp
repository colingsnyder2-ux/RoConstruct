// from server: 100% by nuck16
// roc 2009-12 00642c10  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642c10
//
// 00642c10  56                   push esi
// 00642c11  8b742408             mov esi, dword ptr [esp + 8]
// 00642c15  85f6                 test esi, esi
// 00642c17  742c                 je 0x642c45
// 00642c19  8b0e                 mov ecx, dword ptr [esi]
// 00642c1b  85c9                 test ecx, ecx
// 00642c1d  7409                 je 0x642c28
// 00642c1f  8b01                 mov eax, dword ptr [ecx]
// 00642c21  8b5004               mov edx, dword ptr [eax + 4]
// 00642c24  ffd2                 call edx
// 00642c26  eb05                 jmp 0x642c2d
// 00642c28  b80c03b000           mov eax, 0xb0030c
// 00642c2d  686c31b100           push 0xb1316c
// 00642c32  8bc8                 mov ecx, eax
// 00642c34  ff1568b79800         call dword ptr [0x98b768]
// 00642c3a  84c0                 test al, al
// 00642c3c  7407                 je 0x642c45
// 00642c3e  8b06                 mov eax, dword ptr [esi]
// 00642c40  83c004               add eax, 4
// 00642c43  5e                   pop esi
// 00642c44  c3                   ret 
// 00642c45  33c0                 xor eax, eax
// 00642c47  5e                   pop esi
// 00642c48  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb1316c = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b1316c;

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

void *func_00642c10(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b1316c)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
