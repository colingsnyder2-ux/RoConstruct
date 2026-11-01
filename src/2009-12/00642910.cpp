// from server: 100% by nuck16
// roc 2009-12 00642910  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642910
//
// 00642910  56                   push esi
// 00642911  8b742408             mov esi, dword ptr [esp + 8]
// 00642915  85f6                 test esi, esi
// 00642917  742c                 je 0x642945
// 00642919  8b0e                 mov ecx, dword ptr [esi]
// 0064291b  85c9                 test ecx, ecx
// 0064291d  7409                 je 0x642928
// 0064291f  8b01                 mov eax, dword ptr [ecx]
// 00642921  8b5004               mov edx, dword ptr [eax + 4]
// 00642924  ffd2                 call edx
// 00642926  eb05                 jmp 0x64292d
// 00642928  b80c03b000           mov eax, 0xb0030c
// 0064292d  683c03b000           push 0xb0033c
// 00642932  8bc8                 mov ecx, eax
// 00642934  ff1568b79800         call dword ptr [0x98b768]
// 0064293a  84c0                 test al, al
// 0064293c  7407                 je 0x642945
// 0064293e  8b06                 mov eax, dword ptr [esi]
// 00642940  83c004               add eax, 4
// 00642943  5e                   pop esi
// 00642944  c3                   ret 
// 00642945  33c0                 xor eax, eax
// 00642947  5e                   pop esi
// 00642948  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb0033c = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b0033c;

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

void *func_00642910(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b0033c)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
