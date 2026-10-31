// from server: 100% by EspClaude
// roc 2009-06 006390a0  unit: RBX::VScriptContext::?$BoundFuncDesc  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006390a0
//
// 006390a0  6aff                 push -1
// 006390a2  6868398600           push 0x863968
// 006390a7  64a100000000         mov eax, dword ptr fs:[0]
// 006390ad  50                   push eax
// 006390ae  64892500000000       mov dword ptr fs:[0], esp
// 006390b5  83ec14               sub esp, 0x14
// 006390b8  56                   push esi
// 006390b9  57                   push edi
// 006390ba  8bf9                 mov edi, ecx
// 006390bc  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 006390bf  8b4740               mov eax, dword ptr [edi + 0x40]
// 006390c2  89442408             mov dword ptr [esp + 8], eax
// 006390c6  85c9                 test ecx, ecx
// 006390c8  7409                 je 0x6390d3
// 006390ca  8b11                 mov edx, dword ptr [ecx]
// 006390cc  8b4208               mov eax, dword ptr [edx + 8]
// 006390cf  ffd0                 call eax
// 006390d1  eb02                 jmp 0x6390d5
// 006390d3  33c0                 xor eax, eax
// 006390d5  8944240c             mov dword ptr [esp + 0xc], eax
// 006390d9  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 006390dd  8b11                 mov edx, dword ptr [ecx]
// 006390df  8b5204               mov edx, dword ptr [edx + 4]
// 006390e2  8d442408             lea eax, [esp + 8]
// 006390e6  50                   push eax
// 006390e7  6a01                 push 1
// 006390e9  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006390f1  ffd2                 call edx
// 006390f3  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006390f7  6a00                 push 0
// 006390f9  6840d2a000           push 0xa0d240
// 006390fe  68c4bf9d00           push 0x9dbfc4
// 00639103  6a00                 push 0
// 00639105  50                   push eax
// 00639106  e86f0b0e00           call 0x719c7a
// 0063910b  8bf0                 mov esi, eax
// 0063910d  83c414               add esp, 0x14
// 00639110  85f6                 test esi, esi
// 00639112  751e                 jne 0x639132
// 00639114  6850d38a00           push 0x8ad350
// 00639119  8d4c2414             lea ecx, [esp + 0x14]
// 0063911d  ff1570e98900         call dword ptr [0x89e970]
// 00639123  68b04b9800           push 0x984bb0
// 00639128  8d4c2414             lea ecx, [esp + 0x14]
// 0063912c  51                   push ecx
// 0063912d  e818090e00           call 0x719a4a
// 00639132  8d4c2408             lea ecx, [esp + 8]
// 00639136  e8d5f0faff           call 0x5e8210
// 0063913b  dd00                 fld qword ptr [eax]
// 0063913d  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 00639140  8b5738               mov edx, dword ptr [edi + 0x38]
// 00639143  83ec08               sub esp, 8
// 00639146  03ce                 add ecx, esi
// 00639148  dd1c24               fstp qword ptr [esp]
// 0063914b  ffd2                 call edx
// 0063914d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00639151  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00639159  85c9                 test ecx, ecx
// 0063915b  7408                 je 0x639165
// 0063915d  8b01                 mov eax, dword ptr [ecx]
// 0063915f  8b10                 mov edx, dword ptr [eax]
// 00639161  6a01                 push 1
// 00639163  ffd2                 call edx
// 00639165  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00639169  5f                   pop edi
// 0063916a  5e                   pop esi
// 0063916b  64890d00000000       mov dword ptr fs:[0], ecx
// 00639172  83c420               add esp, 0x20
// 00639175  c20800               ret 8
// copied from an identical function in another client (function ?f@S@@QAEXPAVDescribedBase@Reflection@RBX@@PAUArguments@@@Z)

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