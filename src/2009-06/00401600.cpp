// from server: 100% by EspClaude
// roc 2009-06 00401600  unit: std::bad_alloc  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401600
//
// 00401600  6aff                 push -1
// 00401602  68482b8500           push 0x852b48
// 00401607  64a100000000         mov eax, dword ptr fs:[0]
// 0040160d  50                   push eax
// 0040160e  64892500000000       mov dword ptr fs:[0], esp
// 00401615  51                   push ecx
// 00401616  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040161a  56                   push esi
// 0040161b  50                   push eax
// 0040161c  6a76                 push 0x76
// 0040161e  8bf1                 mov esi, ecx
// 00401620  6a75                 push 0x75
// 00401622  89742410             mov dword ptr [esp + 0x10], esi
// 00401626  e875ba0400           call 0x44d0a0
// 0040162b  8b8e0c010000         mov ecx, dword ptr [esi + 0x10c]
// 00401631  81c907408401         or ecx, 0x1844007
// 00401637  51                   push ecx
// 00401638  8bce                 mov ecx, esi
// 0040163a  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00401642  c70644c78a00         mov dword ptr [esi], 0x8ac744
// 00401648  c7467418c78a00       mov dword ptr [esi + 0x74], 0x8ac718
// 0040164f  e884763100           call 0x718cd8
// 00401654  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401658  8bc6                 mov eax, esi
// 0040165a  5e                   pop esi
// 0040165b  64890d00000000       mov dword ptr fs:[0], ecx
// 00401662  83c410               add esp, 0x10
// 00401665  c20400               ret 4
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
