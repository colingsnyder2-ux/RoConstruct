// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 00460c00  unit: RBX::VRunService::?$MarshaledListener  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460c00
//
// 00460c00  6aff                 push -1
// 00460c02  6813287400           push 0x742813
// 00460c07  64a100000000         mov eax, dword ptr fs:[0]
// 00460c0d  50                   push eax
// 00460c0e  51                   push ecx
// 00460c0f  56                   push esi
// 00460c10  a188518b00           mov eax, dword ptr [0x8b5188]
// 00460c15  33c4                 xor eax, esp
// 00460c17  50                   push eax
// 00460c18  8d44240c             lea eax, [esp + 0xc]
// 00460c1c  64a300000000         mov dword ptr fs:[0], eax
// 00460c22  8bf1                 mov esi, ecx
// 00460c24  89742408             mov dword ptr [esp + 8], esi
// 00460c28  c706604b7900         mov dword ptr [esi], 0x794b60
// 00460c2e  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00460c36  e8d5150000           call 0x462210
// 00460c3b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00460c3e  50                   push eax
// 00460c3f  e81c2afdff           call 0x433660
// 00460c44  8b4608               mov eax, dword ptr [esi + 8]
// 00460c47  83c404               add esp, 4
// 00460c4a  85c0                 test eax, eax
// 00460c4c  7409                 je 0x460c57
// 00460c4e  50                   push eax
// 00460c4f  e80ef01c00           call 0x62fc62
// 00460c54  83c404               add esp, 4
// 00460c57  c7460800000000       mov dword ptr [esi + 8], 0
// 00460c5e  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00460c65  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00460c6c  c70644837800         mov dword ptr [esi], 0x788344
// 00460c72  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00460c76  64890d00000000       mov dword ptr fs:[0], ecx
// 00460c7d  59                   pop ecx
// 00460c7e  5e                   pop esi
// 00460c7f  83c410               add esp, 0x10
// 00460c82  c3                   ret 
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
