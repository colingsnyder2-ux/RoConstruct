// from server: 100% by nuck16
// roc 2009-12 006bb040  unit: RBX::Soundscape::SoundChannel  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bb040
//
// 006bb040  56                   push esi
// 006bb041  8b742408             mov esi, dword ptr [esp + 8]
// 006bb045  85f6                 test esi, esi
// 006bb047  742c                 je 0x6bb075
// 006bb049  8b0e                 mov ecx, dword ptr [esi]
// 006bb04b  85c9                 test ecx, ecx
// 006bb04d  7409                 je 0x6bb058
// 006bb04f  8b01                 mov eax, dword ptr [ecx]
// 006bb051  8b5004               mov edx, dword ptr [eax + 4]
// 006bb054  ffd2                 call edx
// 006bb056  eb05                 jmp 0x6bb05d
// 006bb058  b80c03b000           mov eax, 0xb0030c
// 006bb05d  689c72b300           push 0xb3729c
// 006bb062  8bc8                 mov ecx, eax
// 006bb064  ff1568b79800         call dword ptr [0x98b768]
// 006bb06a  84c0                 test al, al
// 006bb06c  7407                 je 0x6bb075
// 006bb06e  8b06                 mov eax, dword ptr [esi]
// 006bb070  83c004               add eax, 4
// 006bb073  5e                   pop esi
// 006bb074  c3                   ret 
// 006bb075  33c0                 xor eax, eax
// 006bb077  5e                   pop esi
// 006bb078  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb3729c = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b3729c;

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

void *func_006bb040(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b3729c)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
