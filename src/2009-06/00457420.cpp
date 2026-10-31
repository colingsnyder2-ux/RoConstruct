// from server: 100% by EspClaude
// roc 2009-06 00457420  unit: CRobloxReportView  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00457420
//
// 00457420  51                   push ecx
// 00457421  56                   push esi
// 00457422  8bf1                 mov esi, ecx
// 00457424  e8391c2c00           call 0x719062
// 00457429  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0045742c  83ec08               sub esp, 8
// 0045742f  8bc4                 mov eax, esp
// 00457431  8964240c             mov dword ptr [esp + 0xc], esp
// 00457435  85c9                 test ecx, ecx
// 00457437  7410                 je 0x457449
// 00457439  50                   push eax
// 0045743a  e841b1faff           call 0x402580
// 0045743f  8bce                 mov ecx, esi
// 00457441  e8aafcffff           call 0x4570f0
// 00457446  5e                   pop esi
// 00457447  59                   pop ecx
// 00457448  c3                   ret 
// 00457449  c70000000000         mov dword ptr [eax], 0
// 0045744f  8bce                 mov ecx, esi
// 00457451  c7400400000000       mov dword ptr [eax + 4], 0
// 00457458  e893fcffff           call 0x4570f0
// 0045745d  5e                   pop esi
// 0045745e  59                   pop ecx
// 0045745f  c3                   ret 
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