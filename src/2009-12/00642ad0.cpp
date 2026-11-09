// from server: 100% by nuck16
// roc 2009-12 00642ad0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
//
// 00642ad0  56                   push esi
// 00642ad1  8b742408             mov esi, dword ptr [esp + 8]
// 00642ad5  85f6                 test esi, esi
// 00642ad7  742c                 je 0x642b05
// 00642ad9  8b0e                 mov ecx, dword ptr [esi]
// 00642adb  85c9                 test ecx, ecx
// 00642add  7409                 je 0x642ae8
// 00642adf  8b01                 mov eax, dword ptr [ecx]
// 00642ae1  8b5004               mov edx, dword ptr [eax + 4]
// 00642ae4  ffd2                 call edx
// 00642ae6  eb05                 jmp 0x642aed
// 00642ae8  b80c03b000           mov eax, 0xb0030c
// 00642aed  68f8d6b100           push 0xb1d6f8
// 00642af2  8bc8                 mov ecx, eax
// 00642af4  ff1568b79800         call dword ptr [0x98b768]
// 00642afa  84c0                 test al, al
// 00642afc  7407                 je 0x642b05
// 00642afe  8b06                 mov eax, dword ptr [esi]
// 00642b00  83c004               add eax, 4
// 00642b03  5e                   pop esi
// 00642b04  c3                   ret 
// 00642b05  33c0                 xor eax, eax
// 00642b07  5e                   pop esi
// 00642b08  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb1d6f8 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b1d6f8;

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

void *func_00642ad0(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b1d6f8)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
