// from server: 100% by Xemicl
// roc 2012-06 004014a0  unit: std::bad_alloc  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004014a0
//
// 004014a0  6aff                 push -1
// 004014a2  68489fa900           push 0xa99f48
// 004014a7  64a100000000         mov eax, dword ptr fs:[0]
// 004014ad  50                   push eax
// 004014ae  64892500000000       mov dword ptr fs:[0], esp
// 004014b5  51                   push ecx
// 004014b6  8b442414             mov eax, dword ptr [esp + 0x14]
// 004014ba  56                   push esi
// 004014bb  50                   push eax
// 004014bc  6a76                 push 0x76
// 004014be  8bf1                 mov esi, ecx
// 004014c0  6a75                 push 0x75
// 004014c2  89742410             mov dword ptr [esp + 0x10], esi
// 004014c6  e8e5870700           call 0x479cb0
// 004014cb  8b8e0c010000         mov ecx, dword ptr [esi + 0x10c]
// 004014d1  81c907408401         or ecx, 0x1844007
// 004014d7  51                   push ecx
// 004014d8  8bce                 mov ecx, esi
// 004014da  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004014e2  c706cc2cb400         mov dword ptr [esi], 0xb42ccc
// 004014e8  c74674a02cb400       mov dword ptr [esi + 0x74], 0xb42ca0
// 004014ef  e8c00e5800           call 0x9823b4
// 004014f4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004014f8  8bc6                 mov eax, esi
// 004014fa  5e                   pop esi
// 004014fb  64890d00000000       mov dword ptr fs:[0], ecx
// 00401502  83c410               add esp, 0x10
// 00401505  c20400               ret 4
// copied from an identical function in another client (function ??0CInsertObjectDialog@ns_ROCX000006@@QAE@PAX@Z)

namespace ns_ROCX000006 {
struct Primary
{
    virtual void f();
    char padding[0x70];
};

struct Secondary
{
    virtual void f();
    char padding[0x94];
    unsigned style;
};

struct Base : Primary, Secondary
{
    Base(int, int, void*);
    ~Base();
    void setStyle(unsigned);
};

struct CInsertObjectDialog : Base
{
    CInsertObjectDialog(void*);
    virtual void f();
};

CInsertObjectDialog::CInsertObjectDialog(void* arg)
    : Base(0x75, 0x76, arg)
{
    setStyle(style | 0x01844007);
}
}