// from server: 100% by nuck16
// roc 2009-12 00642b50  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642b50
//
// 00642b50  56                   push esi
// 00642b51  8b742408             mov esi, dword ptr [esp + 8]
// 00642b55  85f6                 test esi, esi
// 00642b57  742c                 je 0x642b85
// 00642b59  8b0e                 mov ecx, dword ptr [esi]
// 00642b5b  85c9                 test ecx, ecx
// 00642b5d  7409                 je 0x642b68
// 00642b5f  8b01                 mov eax, dword ptr [ecx]
// 00642b61  8b5004               mov edx, dword ptr [eax + 4]
// 00642b64  ffd2                 call edx
// 00642b66  eb05                 jmp 0x642b6d
// 00642b68  b80c03b000           mov eax, 0xb0030c
// 00642b6d  68b4d7b100           push 0xb1d7b4
// 00642b72  8bc8                 mov ecx, eax
// 00642b74  ff1568b79800         call dword ptr [0x98b768]
// 00642b7a  84c0                 test al, al
// 00642b7c  7407                 je 0x642b85
// 00642b7e  8b06                 mov eax, dword ptr [esi]
// 00642b80  83c004               add eax, 4
// 00642b83  5e                   pop esi
// 00642b84  c3                   ret 
// 00642b85  33c0                 xor eax, eax
// 00642b87  5e                   pop esi
// 00642b88  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb1d7b4 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b1d7b4;

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

void *func_00642b50(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b1d7b4)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
