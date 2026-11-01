// from server: 100% by colin
// from server: 87% by king_originala
// roc 2008-06 0057f5b0  unit: RBX::VModelInstance::?$FilteredSelection  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057f5b0
//
// 0057f5b0  64a100000000         mov eax, dword ptr fs:[0]
// 0057f5b6  6aff                 push -1
// 0057f5b8  68f8107d00           push 0x7d10f8
// 0057f5bd  50                   push eax
// 0057f5be  64892500000000       mov dword ptr fs:[0], esp
// 0057f5c5  83ec2c               sub esp, 0x2c
// 0057f5c8  56                   push esi
// 0057f5c9  8bf1                 mov esi, ecx
// 0057f5cb  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0057f5cf  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0057f5d2  2b410c               sub eax, dword ptr [ecx + 0xc]
// 0057f5d5  a9fcffffff           test eax, 0xfffffffc
// 0057f5da  7461                 je 0x57f63d
// 0057f5dc  8b460c               mov eax, dword ptr [esi + 0xc]
// 0057f5df  50                   push eax
// 0057f5e0  51                   push ecx
// 0057f5e1  6a00                 push 0
// 0057f5e3  8d4c2410             lea ecx, [esp + 0x10]
// 0057f5e7  e854ef0800           call 0x60e540
// 0057f5ec  8d4c2404             lea ecx, [esp + 4]
// 0057f5f0  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0057f5f8  e803e80800           call 0x60de00
// 0057f5fd  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0057f601  51                   push ecx
// 0057f602  8d4c2408             lea ecx, [esp + 8]
// 0057f606  e805ed0800           call 0x60e310
// 0057f60b  8d4c2404             lea ecx, [esp + 4]
// 0057f60f  e86cf10800           call 0x60e780
// 0057f614  8b760c               mov esi, dword ptr [esi + 0xc]
// 0057f617  c644244400           mov byte ptr [esp + 0x44], 0
// 0057f61c  8b542444             mov edx, dword ptr [esp + 0x44]
// 0057f620  52                   push edx
// 0057f621  8d8e44030000         lea ecx, [esi + 0x344]
// 0057f627  e81473ffff           call 0x576940
// 0057f62c  8d4c2404             lea ecx, [esp + 4]
// 0057f630  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 0057f638  e8c3f00800           call 0x60e700
// 0057f63d  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0057f641  5e                   pop esi
// 0057f642  64890d00000000       mov dword ptr fs:[0], ecx
// 0057f649  83c438               add esp, 0x38
// 0057f64c  c20800               ret 8

#include <intrin.h>

struct Selection {
    char reserved[12];
    void** begin;
    void** end;
};

struct Flag {
    bool value;
};

struct Signal {
    void notify(Flag value);
};

struct Owner {
    char reserved[0x344];
    Signal changed;
};

struct Transaction {
    char storage[44];
    Transaction(int mode, Selection* selection, Owner* owner);
    ~Transaction();
    void begin();
    void apply(void* item);
    void finish();
};

struct FilteredSelection {
    char reserved[12];
    Owner* owner;
    void update(void* item, Selection* selection);
};

void FilteredSelection::update(void* item, Selection* selection)
{
    _ReadWriteBarrier();
    if (selection->end - selection->begin != 0) {
        Owner* ownerArg = owner;
        Transaction transaction(0, selection, ownerArg);
        transaction.begin();
        transaction.apply(item);
        transaction.finish();
        Owner* current = owner;
        Flag flag;
        flag.value = false;
        current->changed.notify(flag);
    }
}
