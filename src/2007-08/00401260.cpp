// from server: 100% by Yeetserama
// roc 2007-08 00401260  unit: CSettingsDialog  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401260
//
// 00401260  6aff                 push -1
// 00401262  68c88e7300           push 0x738ec8
// 00401267  64a100000000         mov eax, dword ptr fs:[0]
// 0040126d  50                   push eax
// 0040126e  51                   push ecx
// 0040126f  56                   push esi
// 00401270  a188518b00           mov eax, dword ptr [0x8b5188]
// 00401275  33c4                 xor eax, esp
// 00401277  50                   push eax
// 00401278  8d44240c             lea eax, [esp + 0xc]
// 0040127c  64a300000000         mov dword ptr fs:[0], eax
// 00401282  8bf1                 mov esi, ecx
// 00401284  89742408             mov dword ptr [esp + 8], esi
// 00401288  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040128c  50                   push eax
// 0040128d  6a76                 push 0x76
// 0040128f  6a75                 push 0x75
// 00401291  e81aba0400           call 0x44ccb0
// 00401296  8b8e0c010000         mov ecx, dword ptr [esi + 0x10c]
// 0040129c  81c907408401         or ecx, 0x1844007
// 004012a2  51                   push ecx
// 004012a3  8bce                 mov ecx, esi
// 004012a5  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004012ad  c70674477800         mov dword ptr [esi], 0x784774
// 004012b3  c7467448477800       mov dword ptr [esi + 0x74], 0x784748
// 004012ba  e849ec2200           call 0x62ff08
// 004012bf  8bc6                 mov eax, esi
// 004012c1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004012c5  64890d00000000       mov dword ptr fs:[0], ecx
// 004012cc  59                   pop ecx
// 004012cd  5e                   pop esi
// 004012ce  83c410               add esp, 0x10
// 004012d1  c20400               ret 4
// copied from an identical function in another client (function ??0CInsertObjectDialog@ns_ROCX000002@@QAE@PAX@Z)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
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
