// from server: 100% by Espeon
// from server: 91% by colin
// roc 2008-06 005daeb0  unit: RBX::VHumanoid::?$BoundFuncDesc  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005daeb0
//
// 005daeb0  6aff                 push -1
// 005daeb2  68e82c7d00           push 0x7d2ce8
// 005daeb7  64a100000000         mov eax, dword ptr fs:[0]
// 005daebd  50                   push eax
// 005daebe  64892500000000       mov dword ptr fs:[0], esp
// 005daec5  83ec14               sub esp, 0x14
// 005daec8  56                   push esi
// 005daec9  57                   push edi
// 005daeca  8bf9                 mov edi, ecx
// 005daecc  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 005daecf  8b4744               mov eax, dword ptr [edi + 0x44]
// 005daed2  89442408             mov dword ptr [esp + 8], eax
// 005daed6  85c9                 test ecx, ecx
// 005daed8  7409                 je 0x5daee3
// 005daeda  8b11                 mov edx, dword ptr [ecx]
// 005daedc  8b4208               mov eax, dword ptr [edx + 8]
// 005daedf  ffd0                 call eax
// 005daee1  eb02                 jmp 0x5daee5
// 005daee3  33c0                 xor eax, eax
// 005daee5  8944240c             mov dword ptr [esp + 0xc], eax
// 005daee9  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005daeed  8b11                 mov edx, dword ptr [ecx]
// 005daeef  8b5204               mov edx, dword ptr [edx + 4]
// 005daef2  8d442408             lea eax, [esp + 8]
// 005daef6  50                   push eax
// 005daef7  6a01                 push 1
// 005daef9  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005daf01  ffd2                 call edx
// 005daf03  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005daf07  6a00                 push 0
// 005daf09  68e0349500           push 0x9534e0
// 005daf0e  68fc919200           push 0x9291fc
// 005daf13  6a00                 push 0
// 005daf15  50                   push eax
// 005daf16  e8ab680c00           call 0x6a17c6
// 005daf1b  8bf0                 mov esi, eax
// 005daf1d  83c414               add esp, 0x14
// 005daf20  85f6                 test esi, esi
// 005daf22  751e                 jne 0x5daf42
// 005daf24  6834ba8000           push 0x80ba34
// 005daf29  8d4c2414             lea ecx, [esp + 0x14]
// 005daf2d  ff1564288000         call dword ptr [0x802864]
// 005daf33  682c368d00           push 0x8d362c
// 005daf38  8d4c2414             lea ecx, [esp + 0x14]
// 005daf3c  51                   push ecx
// 005daf3d  e84a660c00           call 0x6a158c
// 005daf42  8d4c2408             lea ecx, [esp + 8]
// 005daf46  e8b53df9ff           call 0x56ed00
// 005daf4b  d900                 fld dword ptr [eax]
// 005daf4d  8b9650010000         mov edx, dword ptr [esi + 0x150]
// 005daf53  8b4740               mov eax, dword ptr [edi + 0x40]
// 005daf56  51                   push ecx
// 005daf57  8b0c02               mov ecx, dword ptr [edx + eax]
// 005daf5a  d91c24               fstp dword ptr [esp]
// 005daf5d  034f3c               add ecx, dword ptr [edi + 0x3c]
// 005daf60  8b5738               mov edx, dword ptr [edi + 0x38]
// 005daf63  8d8c3150010000       lea ecx, [ecx + esi + 0x150]
// 005daf6a  ffd2                 call edx
// 005daf6c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005daf70  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 005daf78  85c9                 test ecx, ecx
// 005daf7a  7408                 je 0x5daf84
// 005daf7c  8b01                 mov eax, dword ptr [ecx]
// 005daf7e  8b10                 mov edx, dword ptr [eax]
// 005daf80  6a01                 push 1
// 005daf82  ffd2                 call edx
// 005daf84  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005daf88  5f                   pop edi
// 005daf89  5e                   pop esi
// 005daf8a  64890d00000000       mov dword ptr fs:[0], ecx
// 005daf91  83c420               add esp, 0x20
// 005daf94  c20800               ret 8

//

#include <typeinfo>
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Control
{
    virtual ~Control();
    virtual void unused();
    virtual Control *clone();

    static Control *copy(Control *);
};

inline Control *Control::copy(Control *p)
{
    if (p)
        return p->clone();
    return 0;
}

struct Value
{
    void *data;
    Control *control;

    Value(void *, Control *);
    ~Value();
    const float *number();
};

inline Value::Value(void *p, Control *c)
    : data(p), control(Control::copy(c))
{
}

inline Value::~Value()
{
    if (control)
        delete control;
}

struct Arguments
{
    virtual void unused();
    virtual void get(int, Value *);
};

namespace RBX { namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; } }
using RBX::Reflection::DescribedBase;

struct Primary: DescribedBase {char layout[0x150-sizeof(DescribedBase)];};
struct VirtualBase {int unused;};
namespace RBX { class Humanoid : public Primary, public virtual VirtualBase {}; }
using RBX::Humanoid;



struct S
{
    char padding[0x38];
    void (Humanoid::*callback)(float);
    void *data;
    Control *control;

    void f(DescribedBase *, Arguments *);
};

void S::f(DescribedBase *object, Arguments *arguments)
{
    Value value(data, control);
    arguments->get(1, &value);

    Humanoid *context = dynamic_cast<Humanoid *>(object);
    if (!context)
        throw std::bad_cast("bad cast");

    (context->*callback)(*value.number());
}

