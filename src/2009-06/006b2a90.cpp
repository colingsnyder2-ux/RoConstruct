// from server: 71% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060e700  unit: RBX::BlockBlockContact  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060e700
//
// 0060e700  6aff                 push -1
// 0060e702  68738d7d00           push 0x7d8d73
// 0060e707  64a100000000         mov eax, dword ptr fs:[0]
// 0060e70d  50                   push eax
// 0060e70e  64892500000000       mov dword ptr fs:[0], esp
// 0060e715  51                   push ecx
// 0060e716  56                   push esi
// 0060e717  8bf1                 mov esi, ecx
// 0060e719  89742404             mov dword ptr [esp + 4], esi
// 0060e71d  807e2000             cmp byte ptr [esi + 0x20], 0
// 0060e721  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0060e729  750c                 jne 0x60e737
// 0060e72b  8d4608               lea eax, [esi + 8]
// 0060e72e  50                   push eax
// 0060e72f  e8fc070000           call 0x60ef30
// 0060e734  83c404               add esp, 4
// 0060e737  8d4e08               lea ecx, [esi + 8]
// 0060e73a  c644241000           mov byte ptr [esp + 0x10], 0
// 0060e73f  e80c1ef8ff           call 0x590550
// 0060e744  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060e747  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0060e74f  5e                   pop esi
// 0060e750  85c9                 test ecx, ecx
// 0060e752  7413                 je 0x60e767
// 0060e754  8d5108               lea edx, [ecx + 8]
// 0060e757  83c8ff               or eax, 0xffffffff
// 0060e75a  f00fc102             lock xadd dword ptr [edx], eax
// 0060e75e  7507                 jne 0x60e767
// 0060e760  8b11                 mov edx, dword ptr [ecx]
// 0060e762  8b4208               mov eax, dword ptr [edx + 8]
// 0060e765  ffd0                 call eax
// 0060e767  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0060e76b  64890d00000000       mov dword ptr fs:[0], ecx
// 0060e772  83c410               add esp, 0x10
// 0060e775  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void dispose();
    virtual void release();
    virtual void destroy();
    long strongCount;
    volatile long weakCount;
};

struct Weak {
    void* object;
    Control* control;
    ~Weak();
};

struct Sub {
    char data[24];
    ~Sub();
};

extern void __cdecl cleanup(Sub*);

struct S {
    Weak weak;
    Sub sub;
    bool flag;
    ~S();
};

inline Weak::~Weak()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->weakCount) == 0)
        p->destroy();
}

S::~S()
{
    if (!flag)
        cleanup(&sub);
}
