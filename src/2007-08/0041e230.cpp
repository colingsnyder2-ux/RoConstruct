// from server: 100% by EspClaude
// from server: 48% by colin
// roc 2007-08 0041e230  unit: RBX::VInstance::?$MarshaledListener  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041e230
//
// 0041e230  6aff                 push -1
// 0041e232  6803b87300           push 0x73b803
// 0041e237  64a100000000         mov eax, dword ptr fs:[0]
// 0041e23d  50                   push eax
// 0041e23e  51                   push ecx
// 0041e23f  56                   push esi
// 0041e240  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041e245  33c4                 xor eax, esp
// 0041e247  50                   push eax
// 0041e248  8d44240c             lea eax, [esp + 0xc]
// 0041e24c  64a300000000         mov dword ptr fs:[0], eax
// 0041e252  8bf1                 mov esi, ecx
// 0041e254  89742408             mov dword ptr [esp + 8], esi
// 0041e258  c706547f7800         mov dword ptr [esi], 0x787f54
// 0041e25e  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0041e266  e8a53f0400           call 0x462210
// 0041e26b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041e26e  50                   push eax
// 0041e26f  e8ec530100           call 0x433660
// 0041e274  8b4608               mov eax, dword ptr [esi + 8]
// 0041e277  83c404               add esp, 4
// 0041e27a  85c0                 test eax, eax
// 0041e27c  7409                 je 0x41e287
// 0041e27e  50                   push eax
// 0041e27f  e8de192100           call 0x62fc62
// 0041e284  83c404               add esp, 4
// 0041e287  c7460800000000       mov dword ptr [esi + 8], 0
// 0041e28e  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0041e295  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0041e29c  c7069c7e7800         mov dword ptr [esi], 0x787e9c
// 0041e2a2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041e2a6  64890d00000000       mov dword ptr fs:[0], ecx
// 0041e2ad  59                   pop ecx
// 0041e2ae  5e                   pop esi
// 0041e2af  83c410               add esp, 0x10
// 0041e2b2  c3                   ret 

#include <vector>

// 0x433660: cdecl, one pointer argument (push [esi+0x18]; call; add esp,4)
struct CMarshalWindow;
void releaseMarshalWindow(CMarshalWindow* w);

struct MarshaledListenerBase
{
    virtual ~MarshaledListenerBase() {}
};

struct MarshaledListener : MarshaledListenerBase
{
    std::vector<void*> items;   // +4 (allocator), _Myfirst +8, _Mylast +0xc, _Myend +0x10
    int field14;
    CMarshalWindow* window;     // +0x18
    void detach();              // 0x462210, thiscall on this
    virtual ~MarshaledListener();
};

MarshaledListener::~MarshaledListener()
{
    detach();
    releaseMarshalWindow(window);
}
