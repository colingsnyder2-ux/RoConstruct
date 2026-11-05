// from server: 100% by nuck16
// roc 2009-12 006b32f0  unit: RBX::DropperTool  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b32f0
//
// 006b32f0  56                   push esi
// 006b32f1  8b742408             mov esi, dword ptr [esp + 8]
// 006b32f5  85f6                 test esi, esi
// 006b32f7  742c                 je 0x6b3325
// 006b32f9  8b0e                 mov ecx, dword ptr [esi]
// 006b32fb  85c9                 test ecx, ecx
// 006b32fd  7409                 je 0x6b3308
// 006b32ff  8b01                 mov eax, dword ptr [ecx]
// 006b3301  8b5004               mov edx, dword ptr [eax + 4]
// 006b3304  ffd2                 call edx
// 006b3306  eb05                 jmp 0x6b330d
// 006b3308  b80c03b000           mov eax, 0xb0030c
// 006b330d  680ccbb200           push 0xb2cb0c
// 006b3312  8bc8                 mov ecx, eax
// 006b3314  ff1568b79800         call dword ptr [0x98b768]
// 006b331a  84c0                 test al, al
// 006b331c  7407                 je 0x6b3325
// 006b331e  8b06                 mov eax, dword ptr [esi]
// 006b3320  83c004               add eax, 4
// 006b3323  5e                   pop esi
// 006b3324  c3                   ret 
// 006b3325  33c0                 xor eax, eax
// 006b3327  5e                   pop esi
// 006b3328  c3                   ret 

#include <typeinfo>

// boost::any_cast<T>(any *) shape: 0xb0030c = typeid(void), 0xb2cb0c = typeid(T)
extern const type_info type_descriptor_b0030c;
extern const type_info type_descriptor_b2cb0c;

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

void *func_006b32f0(Any *operand)
{
    if (operand && operand->type() == type_descriptor_b2cb0c)
        return &static_cast<Holder *>(operand->content)->held;
    return 0;
}
