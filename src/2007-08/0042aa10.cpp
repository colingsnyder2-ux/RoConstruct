// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 0042aa10  unit: EventHandler  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042aa10
// 0042aa10  6aff                 push -1
// 0042aa12  6848d17300           push 0x73d148
// 0042aa17  64a100000000         mov eax, dword ptr fs:[0]
// 0042aa1d  50                   push eax
// 0042aa1e  83ec10               sub esp, 0x10
// 0042aa21  56                   push esi
// 0042aa22  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042aa27  33c4                 xor eax, esp
// 0042aa29  50                   push eax
// 0042aa2a  8d442418             lea eax, [esp + 0x18]
// 0042aa2e  64a300000000         mov dword ptr fs:[0], eax
// 0042aa34  8bf1                 mov esi, ecx
// 0042aa36  e8a95a2000           call 0x6304e4
// 0042aa3b  83be0401000000       cmp dword ptr [esi + 0x104], 0
// 0042aa42  7469                 je 0x42aaad
// 0042aa44  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0042aa4a  83ec08               sub esp, 8
// 0042aa4d  8bcc                 mov ecx, esp
// 0042aa4f  8901                 mov dword ptr [ecx], eax
// 0042aa51  8b8600010000         mov eax, dword ptr [esi + 0x100]
// 0042aa57  85c0                 test eax, eax
// 0042aa59  89642410             mov dword ptr [esp + 0x10], esp
// 0042aa5d  894104               mov dword ptr [ecx + 4], eax
// 0042aa60  740c                 je 0x42aa6e
// 0042aa62  83c004               add eax, 4
// 0042aa65  b901000000           mov ecx, 1
// 0042aa6a  f00fc108             lock xadd dword ptr [eax], ecx
// 0042aa6e  8d4c2414             lea ecx, [esp + 0x14]
// 0042aa72  e8d92afeff           call 0x40d550
// 0042aa77  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 0042aa7d  c780f000000000000000 mov dword ptr [eax + 0xf0], 0
// 0042aa87  8b8e04010000         mov ecx, dword ptr [esi + 0x104]
// 0042aa8d  6a00                 push 0
// 0042aa8f  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0042aa97  e8946b1100           call 0x541630
// 0042aa9c  8d4c240c             lea ecx, [esp + 0xc]
// 0042aaa0  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0042aaa8  e8f3ea1200           call 0x5595a0
// 0042aaad  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042aab1  64890d00000000       mov dword ptr fs:[0], ecx
// 0042aab8  59                   pop ecx
// 0042aab9  5e                   pop esi
// 0042aaba  83c41c               add esp, 0x1c
// 0042aabd  c3                   ret 

extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)

struct CountedBase {
    virtual void dispose() = 0;
    long use_count;
    long weak_count;
};

struct SharedCount {
    CountedBase* pi;
    SharedCount(const SharedCount& r) : pi(r.pi) { if (pi != 0) _InterlockedIncrement(&pi->use_count); }
    ~SharedCount();
};

struct Target;
struct SharedPtr {
    Target* px;
    SharedCount pn;
};

struct Holder {
    int data[3];
    Holder(SharedPtr p);   // 0x40d550
    ~Holder();             // 0x5595a0
};

struct Target {
    char pad[0xf0];
    int field_f0;
    void notify(int);      // 0x541630
};

struct WndBase {
    void baseHandler();    // 0x6304e4
};

struct EventHandler : WndBase {
    char pad0[0xfc];
    SharedPtr ptr;         // +0xfc
    Target* target;        // +0x104
    void method();
};

void EventHandler::method()
{
    WndBase::baseHandler();
    if (target != 0) {
        Holder h(ptr);
        Target* t = target;
        t->field_f0 = 0;
        target->notify(0);
    }
}
