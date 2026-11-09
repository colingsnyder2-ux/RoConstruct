// from server: 100% by nuck16
// roc 2009-12 00642b90  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00642b90
//
// 00642b90  56                   push esi
// 00642b91  8b742408             mov esi, dword ptr [esp + 8]
// 00642b95  85f6                 test esi, esi
// 00642b97  742c                 je 0x642bc5
// 00642b99  8b0e                 mov ecx, dword ptr [esi]
// 00642b9b  85c9                 test ecx, ecx
// 00642b9d  7409                 je 0x642ba8
// 00642b9f  8b01                 mov eax, dword ptr [ecx]
// 00642ba1  8b5004               mov edx, dword ptr [eax + 4]
// 00642ba4  ffd2                 call edx
// 00642ba6  eb05                 jmp 0x642bad
// 00642ba8  b80c03b000           mov eax, 0xb0030c
// 00642bad  68fcd7b100           push 0xb1d7fc
// 00642bb2  8bc8                 mov ecx, eax
// 00642bb4  ff1568b79800         call dword ptr [0x98b768]
// 00642bba  84c0                 test al, al
// 00642bbc  7407                 je 0x642bc5
// 00642bbe  8b06                 mov eax, dword ptr [esi]
// 00642bc0  83c004               add eax, 4
// 00642bc3  5e                   pop esi
// 00642bc4  c3                   ret 
// 00642bc5  33c0                 xor eax, eax
// 00642bc7  5e                   pop esi
// 00642bc8  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb1d7fc = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b1d7fc;

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

void *func_00642b90(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b1d7fc)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
