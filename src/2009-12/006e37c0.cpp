// from server: 100% by nuck16
// roc 2009-12 006e37c0  unit: RBX::Humanoid  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006e37c0
//
// 006e37c0  56                   push esi
// 006e37c1  8b742408             mov esi, dword ptr [esp + 8]
// 006e37c5  85f6                 test esi, esi
// 006e37c7  742c                 je 0x6e37f5
// 006e37c9  8b0e                 mov ecx, dword ptr [esi]
// 006e37cb  85c9                 test ecx, ecx
// 006e37cd  7409                 je 0x6e37d8
// 006e37cf  8b01                 mov eax, dword ptr [ecx]
// 006e37d1  8b5004               mov edx, dword ptr [eax + 4]
// 006e37d4  ffd2                 call edx
// 006e37d6  eb05                 jmp 0x6e37dd
// 006e37d8  b80c03b000           mov eax, 0xb0030c
// 006e37dd  68a8cbb200           push 0xb2cba8
// 006e37e2  8bc8                 mov ecx, eax
// 006e37e4  ff1568b79800         call dword ptr [0x98b768]
// 006e37ea  84c0                 test al, al
// 006e37ec  7407                 je 0x6e37f5
// 006e37ee  8b06                 mov eax, dword ptr [esi]
// 006e37f0  83c004               add eax, 4
// 006e37f3  5e                   pop esi
// 006e37f4  c3                   ret 
// 006e37f5  33c0                 xor eax, eax
// 006e37f7  5e                   pop esi
// 006e37f8  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb2cba8 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b2cba8;

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

void *func_006e37c0(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b2cba8)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
