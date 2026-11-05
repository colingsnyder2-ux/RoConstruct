// from server: 100% by nuck16
// roc 2009-12 00641b80  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00641b80
//
// 00641b80  56                   push esi
// 00641b81  8b742408             mov esi, dword ptr [esp + 8]
// 00641b85  85f6                 test esi, esi
// 00641b87  742c                 je 0x641bb5
// 00641b89  8b0e                 mov ecx, dword ptr [esi]
// 00641b8b  85c9                 test ecx, ecx
// 00641b8d  7409                 je 0x641b98
// 00641b8f  8b01                 mov eax, dword ptr [ecx]
// 00641b91  8b5004               mov edx, dword ptr [eax + 4]
// 00641b94  ffd2                 call edx
// 00641b96  eb05                 jmp 0x641b9d
// 00641b98  b80c03b000           mov eax, 0xb0030c
// 00641b9d  68209bb100           push 0xb19b20
// 00641ba2  8bc8                 mov ecx, eax
// 00641ba4  ff1568b79800         call dword ptr [0x98b768]
// 00641baa  84c0                 test al, al
// 00641bac  7407                 je 0x641bb5
// 00641bae  8b06                 mov eax, dword ptr [esi]
// 00641bb0  83c004               add eax, 4
// 00641bb3  5e                   pop esi
// 00641bb4  c3                   ret 
// 00641bb5  33c0                 xor eax, eax
// 00641bb7  5e                   pop esi
// 00641bb8  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb19b20 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b19b20;

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

void *func_00641b80(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b19b20)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
