// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00616000  unit: RBX::Unlocked  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00616000
//
// 00616000  6aff                 push -1
// 00616002  68c88f7d00           push 0x7d8fc8
// 00616007  64a100000000         mov eax, dword ptr fs:[0]
// 0061600d  50                   push eax
// 0061600e  64892500000000       mov dword ptr fs:[0], esp
// 00616015  83ec14               sub esp, 0x14
// 00616018  56                   push esi
// 00616019  8bf1                 mov esi, ecx
// 0061601b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061601e  50                   push eax
// 0061601f  8d4c2408             lea ecx, [esp + 8]
// 00616023  e858a30400           call 0x660380
// 00616028  c7442404503a8400     mov dword ptr [esp + 4], 0x843a50
// 00616030  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00616034  8b542428             mov edx, dword ptr [esp + 0x28]
// 00616038  50                   push eax
// 00616039  8d4c2408             lea ecx, [esp + 8]
// 0061603d  51                   push ecx
// 0061603e  52                   push edx
// 0061603f  8bce                 mov ecx, esi
// 00616041  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00616049  e842fdffff           call 0x615d90
// 0061604e  8d4c2404             lea ecx, [esp + 4]
// 00616052  8bf0                 mov esi, eax
// 00616054  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0061605c  e81ffbffff           call 0x615b80
// 00616061  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00616065  8bc6                 mov eax, esi
// 00616067  5e                   pop esi
// 00616068  64890d00000000       mov dword ptr fs:[0], ecx
// 0061606f  83c420               add esp, 0x20
// 00616072  c20800               ret 8

struct Base
{
    int data[4];

    Base(void*);
    virtual ~Base();
};

struct Unlocked : Base
{
    Unlocked(void* p) : Base(p) {}
    virtual ~Unlocked();
};

struct S
{
    char padding[24];
    void* lock;

    int invoke(int, Unlocked*, int);
    int f(int, int);
};

int S::f(int a, int b)
{
    Unlocked unlocked(lock);
    return invoke(a, &unlocked, b);
}
