// from server: 100% by Intel
﻿// from server: 86% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0045beb0  unit: CRobloxWnd  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045beb0
//
// 0045beb0  6aff                 push -1
// 0045beb2  68082c7c00           push 0x7c2c08
// 0045beb7  64a100000000         mov eax, dword ptr fs:[0]
// 0045bebd  50                   push eax
// 0045bebe  64892500000000       mov dword ptr fs:[0], esp
// 0045bec5  51                   push ecx
// 0045bec6  57                   push edi
// 0045bec7  8bf9                 mov edi, ecx
// 0045bec9  80bf8a00000000       cmp byte ptr [edi + 0x8a], 0
// 0045bed0  744a                 je 0x45bf1c
// 0045bed2  8b8fb0000000         mov ecx, dword ptr [edi + 0xb0]
// 0045bed8  8b01                 mov eax, dword ptr [ecx]
// 0045beda  8b501c               mov edx, dword ptr [eax + 0x1c]
// 0045bedd  56                   push esi
// 0045bede  ffd2                 call edx
// 0045bee0  8bf0                 mov esi, eax
// 0045bee2  83c658               add esi, 0x58
// 0045bee5  8bce                 mov ecx, esi
// 0045bee7  89742408             mov dword ptr [esp + 8], esi
// 0045beeb  e8005e0b00           call 0x511cf0
// 0045bef0  8b8fa4000000         mov ecx, dword ptr [edi + 0xa4]
// 0045bef6  8b01                 mov eax, dword ptr [ecx]
// 0045bef8  8b5040               mov edx, dword ptr [eax + 0x40]
// 0045befb  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0045bf03  ffd2                 call edx
// 0045bf05  8bce                 mov ecx, esi
// 0045bf07  c6878a00000000       mov byte ptr [edi + 0x8a], 0
// 0045bf0e  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0045bf16  e8d55e0b00           call 0x511df0
// 0045bf1b  5e                   pop esi
// 0045bf1c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0045bf20  5f                   pop edi
// 0045bf21  64890d00000000       mov dword ptr fs:[0], ecx
// 0045bf28  83c410               add esp, 0x10
// 0045bf2b  c3                   ret 

struct Stopwatch {
    void start();
    void stop();
};

struct Context {
    char padding[0x58];
    Stopwatch stopwatch;
};

struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual Context* getContext();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void update();
};

struct StopwatchScope {
    Stopwatch* stopwatch;

    StopwatchScope(Stopwatch* p) : stopwatch(p) {
        stopwatch->start();
    }

    ~StopwatchScope() {
        stopwatch->stop();
    }
};

struct CRobloxWnd {
    char padding0[0x7a];
    bool pending;
    char padding1[0x19];
    Interface* target;
    char padding2[8];
    Interface* source;

    void f();
};

void CRobloxWnd::f() {
    if (pending) {
        StopwatchScope scope(&source->getContext()->stopwatch);
        target->update();
        pending = false;
    }
}
