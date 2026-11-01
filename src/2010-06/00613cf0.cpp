// from server: 100% by Yeetserama
// roc 2010-06 00613cf0  unit: RBX::VScriptContext::?$BoundFuncDesc  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00613cf0
//
// 00613cf0  6aff                 push -1
// 00613cf2  68e8d09800           push 0x98d0e8
// 00613cf7  64a100000000         mov eax, dword ptr fs:[0]
// 00613cfd  50                   push eax
// 00613cfe  64892500000000       mov dword ptr fs:[0], esp
// 00613d05  83ec14               sub esp, 0x14
// 00613d08  56                   push esi
// 00613d09  57                   push edi
// 00613d0a  8bf9                 mov edi, ecx
// 00613d0c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 00613d0f  8b4740               mov eax, dword ptr [edi + 0x40]
// 00613d12  89442408             mov dword ptr [esp + 8], eax
// 00613d16  85c9                 test ecx, ecx
// 00613d18  7409                 je 0x613d23
// 00613d1a  8b11                 mov edx, dword ptr [ecx]
// 00613d1c  8b4208               mov eax, dword ptr [edx + 8]
// 00613d1f  ffd0                 call eax
// 00613d21  eb02                 jmp 0x613d25
// 00613d23  33c0                 xor eax, eax
// 00613d25  8944240c             mov dword ptr [esp + 0xc], eax
// 00613d29  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00613d2d  8b11                 mov edx, dword ptr [ecx]
// 00613d2f  8b5204               mov edx, dword ptr [edx + 4]
// 00613d32  8d442408             lea eax, [esp + 8]
// 00613d36  50                   push eax
// 00613d37  6a01                 push 1
// 00613d39  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00613d41  ffd2                 call edx
// 00613d43  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00613d47  6a00                 push 0
// 00613d49  68a800bb00           push 0xbb00a8
// 00613d4e  684090b700           push 0xb79040
// 00613d53  6a00                 push 0
// 00613d55  50                   push eax
// 00613d56  e88f4e1900           call 0x7a8bea
// 00613d5b  8bf0                 mov esi, eax
// 00613d5d  83c414               add esp, 0x14
// 00613d60  85f6                 test esi, esi
// 00613d62  751e                 jne 0x613d82
// 00613d64  68540aa000           push 0xa00a54
// 00613d69  8d4c2414             lea ecx, [esp + 0x14]
// 00613d6d  ff159ca89e00         call dword ptr [0x9ea89c]
// 00613d73  689022b100           push 0xb12290
// 00613d78  8d4c2414             lea ecx, [esp + 0x14]
// 00613d7c  51                   push ecx
// 00613d7d  e8304c1900           call 0x7a89b2
// 00613d82  8d4c2408             lea ecx, [esp + 8]
// 00613d86  e82551f9ff           call 0x5a8eb0
// 00613d8b  dd00                 fld qword ptr [eax]
// 00613d8d  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 00613d90  8b5738               mov edx, dword ptr [edi + 0x38]
// 00613d93  83ec08               sub esp, 8
// 00613d96  03ce                 add ecx, esi
// 00613d98  dd1c24               fstp qword ptr [esp]
// 00613d9b  ffd2                 call edx
// 00613d9d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00613da1  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00613da9  85c9                 test ecx, ecx
// 00613dab  7408                 je 0x613db5
// 00613dad  8b01                 mov eax, dword ptr [ecx]
// 00613daf  8b10                 mov edx, dword ptr [eax]
// 00613db1  6a01                 push 1
// 00613db3  ffd2                 call edx
// 00613db5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00613db9  5f                   pop edi
// 00613dba  5e                   pop esi
// 00613dbb  64890d00000000       mov dword ptr fs:[0], ecx
// 00613dc2  83c420               add esp, 0x20
// 00613dc5  c20800               ret 8
// copied from an identical function in another client (function ?f@S@@QAEXPAVDescribedBase@Reflection@RBX@@PAUArguments@@@Z)

// from server: 100% by colin
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
    const double *number();
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

namespace RBX { class ScriptContext : public DescribedBase {}; }
using RBX::ScriptContext;



struct S
{
    char padding[0x38];
    void (__thiscall *callback)(void *, double);
    int adjustment;
    void *data;
    Control *control;

    void f(DescribedBase *, Arguments *);
};

void S::f(DescribedBase *object, Arguments *arguments)
{
    Value value(data, control);
    arguments->get(1, &value);

    ScriptContext *context = dynamic_cast<ScriptContext *>(object);
    if (!context)
        throw std::bad_cast("bad cast");

    callback(reinterpret_cast<char *>(context) + adjustment, *value.number());
}