// from server: 100% by Xemicl
// roc 2012-06 00492100  unit: CRobloxReportView  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00492100
//
// 00492100  51                   push ecx
// 00492101  56                   push esi
// 00492102  8bf1                 mov esi, ecx
// 00492104  e82f064f00           call 0x982738
// 00492109  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0049210c  83ec08               sub esp, 8
// 0049210f  8bc4                 mov eax, esp
// 00492111  8964240c             mov dword ptr [esp + 0xc], esp
// 00492115  85c9                 test ecx, ecx
// 00492117  7410                 je 0x492129
// 00492119  50                   push eax
// 0049211a  e82106f7ff           call 0x402740
// 0049211f  8bce                 mov ecx, esi
// 00492121  e86afcffff           call 0x491d90
// 00492126  5e                   pop esi
// 00492127  59                   pop ecx
// 00492128  c3                   ret 
// 00492129  c70000000000         mov dword ptr [eax], 0
// 0049212f  8bce                 mov ecx, esi
// 00492131  c7400400000000       mov dword ptr [eax + 4], 0
// 00492138  e853fcffff           call 0x491d90
// 0049213d  5e                   pop esi
// 0049213e  59                   pop ecx
// 0049213f  c3                   ret 
// copied from an identical function in another client (function ?f@S@@QAEXXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Count
{
    unsigned int pi;
    Count() : pi(0) {}
    Count(const Count& o) : pi(o.pi) {}
    ~Count() {}
};

struct Result
{
    unsigned int px;
    Count pn;

    Result() : px(0), pn() {}
};

struct Source
{
    Result get();
};

struct S
{
    unsigned char padding[0x54];
    Source* source;

    void baseCall();
    void consume(Result value);
    void f();
};

void S::f()
{
    baseCall();
    if (source)
        consume(source->get());
    else
        consume(Result());
}