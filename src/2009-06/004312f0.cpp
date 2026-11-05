// from server: 100% by EspClaude
// roc 2009-06 004312f0  unit: CPropertyGridItemBrickColor  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004312f0
//
// 004312f0  8b442404             mov eax, dword ptr [esp + 4]
// 004312f4  56                   push esi
// 004312f5  51                   push ecx
// 004312f6  8bf1                 mov esi, ecx
// 004312f8  8bcc                 mov ecx, esp
// 004312fa  8964240c             mov dword ptr [esp + 0xc], esp
// 004312fe  50                   push eax
// 004312ff  51                   push ecx
// 00431300  89860c010000         mov dword ptr [esi + 0x10c], eax
// 00431306  e855ffffff           call 0x431260
// 0043130b  83c408               add esp, 8
// 0043130e  8bce                 mov ecx, esi
// 00431310  e8cb8e3500           call 0x78a1e0
// 00431315  5e                   pop esi
// 00431316  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000001@@QAEXH@Z)

namespace ns_ROCX000001 {
struct Value {
    void* data;
    Value(const Value&);
    ~Value();
};

Value __cdecl convert(int);

struct S {
    char padding[0x10c];
    int color;

    void set(Value);
    void f(int);
};

void S::f(int value)
{
    color = value;
    set(convert(value));
}
}
