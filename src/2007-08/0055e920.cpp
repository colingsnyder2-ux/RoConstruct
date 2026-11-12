// from server: 93% by EspClaude
// repaired: findFirstChildByName + dynamic_cast<TopMenuBar*> toggles (93%, esi/edi swap remains)
// roc 2007-08 0055e920  unit: RBX::StatsCommand  size: 258 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055e920
//
// 0055e920  6aff                 push -1
// 0055e922  68d2417500           push 0x7541d2
// 0055e927  64a100000000         mov eax, dword ptr fs:[0]
// 0055e92d  50                   push eax
// 0055e92e  64892500000000       mov dword ptr fs:[0], esp
// 0055e935  83ec38               sub esp, 0x38
// 0055e938  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0055e93b  56                   push esi
// 0055e93c  57                   push edi
// 0055e93d  8bb8a0010000         mov edi, dword ptr [eax + 0x1a0]
// 0055e943  68bc917a00           push 0x7a91bc
// 0055e948  8d4c240c             lea ecx, [esp + 0xc]
// 0055e94c  ff1598e67700         call dword ptr [0x77e698]
// 0055e952  6a00                 push 0
// 0055e954  683cdf8900           push 0x89df3c
// 0055e959  684c1f8800           push 0x881f4c
// 0055e95e  6a00                 push 0
// 0055e960  8d4c2418             lea ecx, [esp + 0x18]
// 0055e964  51                   push ecx
// 0055e965  8bcf                 mov ecx, edi
// 0055e967  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 0055e96f  e82cfefdff           call 0x53e7a0
// 0055e974  50                   push eax
// 0055e975  e8bc230d00           call 0x630d36
// 0055e97a  83c414               add esp, 0x14
// 0055e97d  8d4c2408             lea ecx, [esp + 8]
// 0055e981  8bf0                 mov esi, eax
// 0055e983  c7442448ffffffff     mov dword ptr [esp + 0x48], 0xffffffff
// 0055e98b  ff15ace67700         call dword ptr [0x77e6ac]
// 0055e991  85f6                 test esi, esi
// 0055e993  7414                 je 0x55e9a9
// 0055e995  8b16                 mov edx, dword ptr [esi]
// 0055e997  8b4258               mov eax, dword ptr [edx + 0x58]
// 0055e99a  8bce                 mov ecx, esi
// 0055e99c  ffd0                 call eax
// 0055e99e  84c0                 test al, al
// 0055e9a0  0f94c0               sete al
// 0055e9a3  888610010000         mov byte ptr [esi + 0x110], al
// 0055e9a9  68b0917a00           push 0x7a91b0
// 0055e9ae  8d4c2428             lea ecx, [esp + 0x28]
// 0055e9b2  ff1598e67700         call dword ptr [0x77e698]
// 0055e9b8  6a00                 push 0
// 0055e9ba  683cdf8900           push 0x89df3c
// 0055e9bf  684c1f8800           push 0x881f4c
// 0055e9c4  6a00                 push 0
// 0055e9c6  8d4c2434             lea ecx, [esp + 0x34]
// 0055e9ca  51                   push ecx
// 0055e9cb  8bcf                 mov ecx, edi
// 0055e9cd  c744245c01000000     mov dword ptr [esp + 0x5c], 1
// 0055e9d5  e8c6fdfdff           call 0x53e7a0
// 0055e9da  50                   push eax
// 0055e9db  e856230d00           call 0x630d36
// 0055e9e0  83c414               add esp, 0x14
// 0055e9e3  8d4c2424             lea ecx, [esp + 0x24]
// 0055e9e7  8bf0                 mov esi, eax
// 0055e9e9  c7442448ffffffff     mov dword ptr [esp + 0x48], 0xffffffff
// 0055e9f1  ff15ace67700         call dword ptr [0x77e6ac]
// 0055e9f7  85f6                 test esi, esi
// 0055e9f9  7414                 je 0x55ea0f
// 0055e9fb  8b16                 mov edx, dword ptr [esi]
// 0055e9fd  8b4258               mov eax, dword ptr [edx + 0x58]
// 0055ea00  8bce                 mov ecx, esi
// 0055ea02  ffd0                 call eax
// 0055ea04  84c0                 test al, al
// 0055ea06  0f94c1               sete cl
// 0055ea09  888e10010000         mov byte ptr [esi + 0x110], cl
// 0055ea0f  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0055ea13  5f                   pop edi
// 0055ea14  5e                   pop esi
// 0055ea15  64890d00000000       mov dword ptr fs:[0], ecx
// 0055ea1c  83c444               add esp, 0x44
// 0055ea1f  c20400               ret 4

// roc-flags: /O2 /GS- /EHsc /MD
#include <string>

namespace RBX {

class Instance {
public:
    virtual ~Instance();
    Instance* findFirstChildByName(const std::string& name);   // 0x53e7a0, thiscall
};

// dynamic_cast target: RTTI .?AVTopMenuBar@RBX@@ (0x89df3c)
class TopMenuBar : public Instance {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21();
    virtual bool isVisible();          // vtable +0x58
    char pad[0x10c];
    bool hidden;                        // +0x110
};

class Holder {
public:
    char pad[0x1a0];
    Instance* gui;                      // +0x1a0
};

class IDataState;

class StatsCommand {
public:
    virtual ~StatsCommand();
    char pad[8];
    Holder* holder;                     // +0xc
    void doIt(IDataState* dataState);
};

void StatsCommand::doIt(IDataState* dataState)
{
    Instance* gui = holder->gui;
    if (TopMenuBar* bar = dynamic_cast<TopMenuBar*>(gui->findFirstChildByName("StatsHud1")))
        bar->hidden = !bar->isVisible();
    if (TopMenuBar* bar = dynamic_cast<TopMenuBar*>(gui->findFirstChildByName("StatsHud2")))
        bar->hidden = !bar->isVisible();
}

}
