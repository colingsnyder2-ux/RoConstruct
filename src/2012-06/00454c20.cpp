// from server: 100% by Xemicl
// roc 2012-06 00454c20  unit: CPropertyGridItemBrickColor  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00454c20
//
// 00454c20  8b442404             mov eax, dword ptr [esp + 4]
// 00454c24  56                   push esi
// 00454c25  51                   push ecx
// 00454c26  8bf1                 mov esi, ecx
// 00454c28  8bcc                 mov ecx, esp
// 00454c2a  8964240c             mov dword ptr [esp + 0xc], esp
// 00454c2e  50                   push eax
// 00454c2f  51                   push ecx
// 00454c30  89860c010000         mov dword ptr [esi + 0x10c], eax
// 00454c36  e855ffffff           call 0x454b90
// 00454c3b  83c408               add esp, 8
// 00454c3e  8bce                 mov ecx, esi
// 00454c40  e8fbd25900           call 0x9f1f40
// 00454c45  5e                   pop esi
// 00454c46  c20400               ret 4
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