// from server: 100% by EspClaude
// from server: 48% by colin
// roc 2007-08 0041e2c0  unit: RBX::VInstance::?$MarshaledListener  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041e2c0
//
// 0041e2c0  6aff                 push -1
// 0041e2c2  6833b87300           push 0x73b833
// 0041e2c7  64a100000000         mov eax, dword ptr fs:[0]
// 0041e2cd  50                   push eax
// 0041e2ce  51                   push ecx
// 0041e2cf  56                   push esi
// 0041e2d0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041e2d5  33c4                 xor eax, esp
// 0041e2d7  50                   push eax
// 0041e2d8  8d44240c             lea eax, [esp + 0xc]
// 0041e2dc  64a300000000         mov dword ptr fs:[0], eax
// 0041e2e2  8bf1                 mov esi, ecx
// 0041e2e4  89742408             mov dword ptr [esp + 8], esi
// 0041e2e8  c706747f7800         mov dword ptr [esi], 0x787f74
// 0041e2ee  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0041e2f6  e8153f0400           call 0x462210
// 0041e2fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041e2fe  50                   push eax
// 0041e2ff  e85c530100           call 0x433660
// 0041e304  8b4608               mov eax, dword ptr [esi + 8]
// 0041e307  83c404               add esp, 4
// 0041e30a  85c0                 test eax, eax
// 0041e30c  7409                 je 0x41e317
// 0041e30e  50                   push eax
// 0041e30f  e84e192100           call 0x62fc62
// 0041e314  83c404               add esp, 4
// 0041e317  c7460800000000       mov dword ptr [esi + 8], 0
// 0041e31e  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0041e325  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0041e32c  c706a87e7800         mov dword ptr [esi], 0x787ea8
// 0041e332  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041e336  64890d00000000       mov dword ptr fs:[0], ecx
// 0041e33d  59                   pop ecx
// 0041e33e  5e                   pop esi
// 0041e33f  83c410               add esp, 0x10
// 0041e342  c3                   ret 

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
