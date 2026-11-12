// from server: 100% by EspClaude
// from server: 44% by colin
// roc 2007-08 00466cd0  unit: VCWorkspace::?$CComObject  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00466cd0
//
// 00466cd0  6aff                 push -1
// 00466cd2  6848d17300           push 0x73d148
// 00466cd7  64a100000000         mov eax, dword ptr fs:[0]
// 00466cdd  50                   push eax
// 00466cde  83ec10               sub esp, 0x10
// 00466ce1  56                   push esi
// 00466ce2  a188518b00           mov eax, dword ptr [0x8b5188]
// 00466ce7  33c4                 xor eax, esp
// 00466ce9  50                   push eax
// 00466cea  8d442418             lea eax, [esp + 0x18]
// 00466cee  64a300000000         mov dword ptr fs:[0], eax
// 00466cf4  8bf1                 mov esi, ecx
// 00466cf6  8b4634               mov eax, dword ptr [esi + 0x34]
// 00466cf9  83ec08               sub esp, 8
// 00466cfc  8bcc                 mov ecx, esp
// 00466cfe  89642410             mov dword ptr [esp + 0x10], esp
// 00466d02  8901                 mov dword ptr [ecx], eax
// 00466d04  8b4638               mov eax, dword ptr [esi + 0x38]
// 00466d07  85c0                 test eax, eax
// 00466d09  894104               mov dword ptr [ecx + 4], eax
// 00466d0c  740c                 je 0x466d1a
// 00466d0e  83c004               add eax, 4
// 00466d11  b901000000           mov ecx, 1
// 00466d16  f00fc108             lock xadd dword ptr [eax], ecx
// 00466d1a  8d4c2414             lea ecx, [esp + 0x14]
// 00466d1e  e82d68faff           call 0x40d550
// 00466d23  8b4634               mov eax, dword ptr [esi + 0x34]
// 00466d26  8b542428             mov edx, dword ptr [esp + 0x28]
// 00466d2a  50                   push eax
// 00466d2b  52                   push edx
// 00466d2c  8d4c2410             lea ecx, [esp + 0x10]
// 00466d30  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00466d38  e8234d1000           call 0x56ba60
// 00466d3d  8b7634               mov esi, dword ptr [esi + 0x34]
// 00466d40  85f6                 test esi, esi
// 00466d42  7408                 je 0x466d4c
// 00466d44  8b8e88010000         mov ecx, dword ptr [esi + 0x188]
// 00466d4a  eb02                 jmp 0x466d4e
// 00466d4c  33c9                 xor ecx, ecx
// 00466d4e  e85d471100           call 0x57b4b0
// 00466d53  8d4c240c             lea ecx, [esp + 0xc]
// 00466d57  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00466d5f  e83c280f00           call 0x5595a0
// 00466d64  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00466d68  64890d00000000       mov dword ptr fs:[0], ecx
// 00466d6f  59                   pop ecx
// 00466d70  5e                   pop esi
// 00466d71  83c41c               add esp, 0x1c

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Counted {
    virtual void dispose();
    volatile long use_count;
};

struct Target {
    char pad[0x188];
    struct Service* service;   // +0x188
};

struct SharedTarget {
    Target* px;
    Counted* pn;
    SharedTarget(const SharedTarget& r) : px(r.px), pn(r.pn)
    {
        if (pn)
            _InterlockedIncrement(&pn->use_count);
    }
};

struct Session {
    int data[3];
    Session(SharedTarget target);       // 0x40d550
    ~Session();                         // 0x5595a0
};

struct Runner {
    int state;   // 4-byte slot at [esp+8] in the target frame
    void run(int arg, Target* target);  // 0x56ba60
};

struct Service {
    void refresh();                     // 0x57b4b0
};

struct Workspace {
    char pad[0x34];
    SharedTarget target;   // +0x34 / +0x38
    void method(int arg);
};

void Workspace::method(int arg)
{
    Session session(target);
    Target* p = target.px;
    Runner runner;
    runner.run(arg, p);
    (target.px ? target.px->service : 0)->refresh();
}
