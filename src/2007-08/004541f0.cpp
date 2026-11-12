// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 004541f0  unit: RBX::VInstance::?$MarshaledListener  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004541f0
//
// 004541f0  6aff                 push -1
// 004541f2  68c3147400           push 0x7414c3
// 004541f7  64a100000000         mov eax, dword ptr fs:[0]
// 004541fd  50                   push eax
// 004541fe  51                   push ecx
// 004541ff  56                   push esi
// 00454200  a188518b00           mov eax, dword ptr [0x8b5188]
// 00454205  33c4                 xor eax, esp
// 00454207  50                   push eax
// 00454208  8d44240c             lea eax, [esp + 0xc]
// 0045420c  64a300000000         mov dword ptr fs:[0], eax
// 00454212  8bf1                 mov esi, ecx
// 00454214  89742408             mov dword ptr [esp + 8], esi
// 00454218  c706bc217900         mov dword ptr [esi], 0x7921bc
// 0045421e  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00454226  e8e5df0000           call 0x462210
// 0045422b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0045422e  50                   push eax
// 0045422f  e82cf4fdff           call 0x433660
// 00454234  8b4608               mov eax, dword ptr [esi + 8]
// 00454237  83c404               add esp, 4
// 0045423a  85c0                 test eax, eax
// 0045423c  7409                 je 0x454247
// 0045423e  50                   push eax
// 0045423f  e81eba1d00           call 0x62fc62
// 00454244  83c404               add esp, 4
// 00454247  c7460800000000       mov dword ptr [esi + 8], 0
// 0045424e  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00454255  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0045425c  c70650837800         mov dword ptr [esi], 0x788350
// 00454262  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00454266  64890d00000000       mov dword ptr fs:[0], ecx
// 0045426d  59                   pop ecx
// 0045426e  5e                   pop esi
// 0045426f  83c410               add esp, 0x10
// 00454272  c3                   ret 
#include <vector>

// 0x433660: cdecl, takes the pointer held at +0x18
struct Handle;
void releaseHandle(Handle*);

class ListenerBase {
public:
    virtual ~ListenerBase() {}
};

class MarshaledListener : public ListenerBase {
    std::vector<int> items;   // +4 (_Myfirst +8, _Mylast +0xc, _Myend +0x10)
    int field_14;
    Handle* handle;           // +0x18
public:
    void disconnect();        // 0x462210, thiscall on this
    virtual ~MarshaledListener();
};

MarshaledListener::~MarshaledListener()
{
    disconnect();
    releaseHandle(handle);
}
