// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 00437990  unit: RBX::VStandardOut::?$MarshaledListener  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00437990
//
// 00437990  6aff                 push -1
// 00437992  6863e47300           push 0x73e463
// 00437997  64a100000000         mov eax, dword ptr fs:[0]
// 0043799d  50                   push eax
// 0043799e  51                   push ecx
// 0043799f  56                   push esi
// 004379a0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004379a5  33c4                 xor eax, esp
// 004379a7  50                   push eax
// 004379a8  8d44240c             lea eax, [esp + 0xc]
// 004379ac  64a300000000         mov dword ptr fs:[0], eax
// 004379b2  8bf1                 mov esi, ecx
// 004379b4  89742408             mov dword ptr [esp + 8], esi
// 004379b8  c706fccd7800         mov dword ptr [esi], 0x78cdfc
// 004379be  c744241401000000     mov dword ptr [esp + 0x14], 1
// 004379c6  e845a80200           call 0x462210
// 004379cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004379ce  50                   push eax
// 004379cf  e88cbcffff           call 0x433660
// 004379d4  8b4608               mov eax, dword ptr [esi + 8]
// 004379d7  83c404               add esp, 4
// 004379da  85c0                 test eax, eax
// 004379dc  7409                 je 0x4379e7
// 004379de  50                   push eax
// 004379df  e87e821f00           call 0x62fc62
// 004379e4  83c404               add esp, 4
// 004379e7  c7460800000000       mov dword ptr [esi + 8], 0
// 004379ee  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 004379f5  c7461000000000       mov dword ptr [esi + 0x10], 0
// 004379fc  c70694cd7800         mov dword ptr [esi], 0x78cd94
// 00437a02  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00437a06  64890d00000000       mov dword ptr fs:[0], ecx
// 00437a0d  59                   pop ecx
// 00437a0e  5e                   pop esi
// 00437a0f  83c410               add esp, 0x10
// 00437a12  c3                   ret 

#include <vector>

void __cdecl sub_433660(void* p);

struct ListenerBase {
    virtual ~ListenerBase() {}
};

struct MarshaledListener : ListenerBase {
    std::vector<int> items;
    int field14;
    void* field18;
    void detach();
    virtual ~MarshaledListener();
};

MarshaledListener::~MarshaledListener()
{
    detach();
    sub_433660(field18);
}
