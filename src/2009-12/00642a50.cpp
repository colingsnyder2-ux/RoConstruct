// from server: 100% by nuck16
// roc 2009-12 00642a50  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642a50
//
// 00642a50  56                   push esi
// 00642a51  8b742408             mov esi, dword ptr [esp + 8]
// 00642a55  85f6                 test esi, esi
// 00642a57  742c                 je 0x642a85
// 00642a59  8b0e                 mov ecx, dword ptr [esi]
// 00642a5b  85c9                 test ecx, ecx
// 00642a5d  7409                 je 0x642a68
// 00642a5f  8b01                 mov eax, dword ptr [ecx]
// 00642a61  8b5004               mov edx, dword ptr [eax + 4]
// 00642a64  ffd2                 call edx
// 00642a66  eb05                 jmp 0x642a6d
// 00642a68  b80c03b000           mov eax, 0xb0030c
// 00642a6d  683434b000           push 0xb03434
// 00642a72  8bc8                 mov ecx, eax
// 00642a74  ff1568b79800         call dword ptr [0x98b768]
// 00642a7a  84c0                 test al, al
// 00642a7c  7407                 je 0x642a85
// 00642a7e  8b06                 mov eax, dword ptr [esi]
// 00642a80  83c004               add eax, 4
// 00642a83  5e                   pop esi
// 00642a84  c3                   ret 
// 00642a85  33c0                 xor eax, eax
// 00642a87  5e                   pop esi
// 00642a88  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb03434 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b03434;

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

void *func_00642a50(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b03434)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
