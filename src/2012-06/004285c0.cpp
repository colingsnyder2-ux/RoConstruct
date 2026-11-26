// from server: 100% by Xemicl
// roc 2012-06 004285c0  unit: CInstanceRecord::CNameItem  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004285c0
//
// 004285c0  56                   push esi
// 004285c1  57                   push edi
// 004285c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004285c6  57                   push edi
// 004285c7  8bf1                 mov esi, ecx
// 004285c9  e872aa5400           call 0x973040
// 004285ce  84c0                 test al, al
// 004285d0  740f                 je 0x4285e1
// 004285d2  8bce                 mov ecx, esi
// 004285d4  e847a85400           call 0x972e20
// 004285d9  57                   push edi
// 004285da  8bce                 mov ecx, esi
// 004285dc  e84fab5400           call 0x973130
// 004285e1  5f                   pop edi
// 004285e2  8bc6                 mov eax, esi
// 004285e4  5e                   pop esi
// 004285e5  c20400               ret 4
// copied from an identical function in another client (function ?set@M@@QAEAAV1@PAUArg@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Arg;
class M {
public:
    bool check(Arg* a);
    void prepare();
    void apply(Arg* a);
    M& set(Arg* a);
};
M& M::set(Arg* a)
{
    if (check(a)) {
        prepare();
        apply(a);
    }
    return *this;
}