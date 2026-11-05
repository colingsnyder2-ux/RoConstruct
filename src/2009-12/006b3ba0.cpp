// from server: 100% by nuck16
// roc 2009-12 006b3ba0  unit: RBX::DropperTool  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b3ba0
//
// 006b3ba0  56                   push esi
// 006b3ba1  8b742408             mov esi, dword ptr [esp + 8]
// 006b3ba5  85f6                 test esi, esi
// 006b3ba7  742c                 je 0x6b3bd5
// 006b3ba9  8b0e                 mov ecx, dword ptr [esi]
// 006b3bab  85c9                 test ecx, ecx
// 006b3bad  7409                 je 0x6b3bb8
// 006b3baf  8b01                 mov eax, dword ptr [ecx]
// 006b3bb1  8b5004               mov edx, dword ptr [eax + 4]
// 006b3bb4  ffd2                 call edx
// 006b3bb6  eb05                 jmp 0x6b3bbd
// 006b3bb8  b80c03b000           mov eax, 0xb0030c
// 006b3bbd  6848a8b300           push 0xb3a848
// 006b3bc2  8bc8                 mov ecx, eax
// 006b3bc4  ff1568b79800         call dword ptr [0x98b768]
// 006b3bca  84c0                 test al, al
// 006b3bcc  7407                 je 0x6b3bd5
// 006b3bce  8b06                 mov eax, dword ptr [esi]
// 006b3bd0  83c004               add eax, 4
// 006b3bd3  5e                   pop esi
// 006b3bd4  c3                   ret 
// 006b3bd5  33c0                 xor eax, eax
// 006b3bd7  5e                   pop esi
// 006b3bd8  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb3a848 = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b3a848;

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

void *func_006b3ba0(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b3a848)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
