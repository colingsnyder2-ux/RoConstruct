// from server: 100% by nuck16
// roc 2009-12 00642bd0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642bd0
//
// 00642bd0  56                   push esi
// 00642bd1  8b742408             mov esi, dword ptr [esp + 8]
// 00642bd5  85f6                 test esi, esi
// 00642bd7  742c                 je 0x642c05
// 00642bd9  8b0e                 mov ecx, dword ptr [esi]
// 00642bdb  85c9                 test ecx, ecx
// 00642bdd  7409                 je 0x642be8
// 00642bdf  8b01                 mov eax, dword ptr [ecx]
// 00642be1  8b5004               mov edx, dword ptr [eax + 4]
// 00642be4  ffd2                 call edx
// 00642be6  eb05                 jmp 0x642bed
// 00642be8  b80c03b000           mov eax, 0xb0030c
// 00642bed  68dccfb100           push 0xb1cfdc
// 00642bf2  8bc8                 mov ecx, eax
// 00642bf4  ff1568b79800         call dword ptr [0x98b768]
// 00642bfa  84c0                 test al, al
// 00642bfc  7407                 je 0x642c05
// 00642bfe  8b06                 mov eax, dword ptr [esi]
// 00642c00  83c004               add eax, 4
// 00642c03  5e                   pop esi
// 00642c04  c3                   ret 
// 00642c05  33c0                 xor eax, eax
// 00642c07  5e                   pop esi
// 00642c08  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb1cfdc = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b1cfdc;

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

void *func_00642bd0(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b1cfdc)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
