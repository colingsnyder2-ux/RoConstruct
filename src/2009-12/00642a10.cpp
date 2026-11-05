// from server: 100% by nuck16
// roc 2009-12 00642a10  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642a10
//
// 00642a10  56                   push esi
// 00642a11  8b742408             mov esi, dword ptr [esp + 8]
// 00642a15  85f6                 test esi, esi
// 00642a17  742c                 je 0x642a45
// 00642a19  8b0e                 mov ecx, dword ptr [esi]
// 00642a1b  85c9                 test ecx, ecx
// 00642a1d  7409                 je 0x642a28
// 00642a1f  8b01                 mov eax, dword ptr [ecx]
// 00642a21  8b5004               mov edx, dword ptr [eax + 4]
// 00642a24  ffd2                 call edx
// 00642a26  eb05                 jmp 0x642a2d
// 00642a28  b80c03b000           mov eax, 0xb0030c
// 00642a2d  6850d8b100           push 0xb1d850
// 00642a32  8bc8                 mov ecx, eax
// 00642a34  ff1568b79800         call dword ptr [0x98b768]
// 00642a3a  84c0                 test al, al
// 00642a3c  7407                 je 0x642a45
// 00642a3e  8b06                 mov eax, dword ptr [esi]
// 00642a40  83c004               add eax, 4
// 00642a43  5e                   pop esi
// 00642a44  c3                   ret 
// 00642a45  33c0                 xor eax, eax
// 00642a47  5e                   pop esi
// 00642a48  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb1d850 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b1d850;

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

void *func_00642a10(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b1d850)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
