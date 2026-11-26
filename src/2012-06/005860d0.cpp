// from server: 100% by Xemicl
// from server: 100% by tester
// roc 2012-06 005a62b0  unit: RBX::Network::NetworkOwnerJob  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a62b0
//
// 005a62b0  d98120020000         fld dword ptr [ecx + 0x220]
// 005a62b6  8b442408             mov eax, dword ptr [esp + 8]
// 005a62ba  56                   push esi
// 005a62bb  8b742408             mov esi, dword ptr [esp + 8]
// 005a62bf  83ec08               sub esp, 8
// 005a62c2  dd1c24               fstp qword ptr [esp]
// 005a62c5  50                   push eax
// 005a62c6  56                   push esi
// 005a62c7  e814173d00           call 0x9779e0
// 005a62cc  8bc6                 mov eax, esi
// 005a62ce  5e                   pop esi
// 005a62cf  c20800               ret 8

struct S
{
    double value;
    unsigned char state;
};

void __stdcall f(S *a, const S *b, double c);

struct NetworkOwnerJob
{
    float value;
    S *method(S *, S *);
};

S *NetworkOwnerJob::method(S *a, S *b)
{
    f(a, b, (double)*(float *)((char *)this + 0x220));
    return a;
}
