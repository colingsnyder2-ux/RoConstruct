// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 00460c90  unit: RBX::VRunService::?$MarshaledListener  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460c90
//
// 00460c90  6aff                 push -1
// 00460c92  6843287400           push 0x742843
// 00460c97  64a100000000         mov eax, dword ptr fs:[0]
// 00460c9d  50                   push eax
// 00460c9e  51                   push ecx
// 00460c9f  56                   push esi
// 00460ca0  a188518b00           mov eax, dword ptr [0x8b5188]
// 00460ca5  33c4                 xor eax, esp
// 00460ca7  50                   push eax
// 00460ca8  8d44240c             lea eax, [esp + 0xc]
// 00460cac  64a300000000         mov dword ptr fs:[0], eax
// 00460cb2  8bf1                 mov esi, ecx
// 00460cb4  89742408             mov dword ptr [esp + 8], esi
// 00460cb8  c706744b7900         mov dword ptr [esi], 0x794b74
// 00460cbe  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00460cc6  e845150000           call 0x462210
// 00460ccb  8b4618               mov eax, dword ptr [esi + 0x18]
// 00460cce  50                   push eax
// 00460ccf  e88c29fdff           call 0x433660
// 00460cd4  8b4608               mov eax, dword ptr [esi + 8]
// 00460cd7  83c404               add esp, 4
// 00460cda  85c0                 test eax, eax
// 00460cdc  7409                 je 0x460ce7
// 00460cde  50                   push eax
// 00460cdf  e87eef1c00           call 0x62fc62
// 00460ce4  83c404               add esp, 4
// 00460ce7  c7460800000000       mov dword ptr [esi + 8], 0
// 00460cee  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00460cf5  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00460cfc  c706844a7900         mov dword ptr [esi], 0x794a84
// 00460d02  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00460d06  64890d00000000       mov dword ptr fs:[0], ecx
// 00460d0d  59                   pop ecx
// 00460d0e  5e                   pop esi
// 00460d0f  83c410               add esp, 0x10
// 00460d12  c3                   ret 
#include <vector>

namespace RBX {
class EventDataBase
{
public:
    virtual ~EventDataBase() {}
};

void __cdecl releaseConnection(void*);

struct MarshaledListener : public EventDataBase
{
    std::vector<void*> items;
    void* reserved;
    void* connection;

    virtual ~MarshaledListener();
    void disconnect();
};

MarshaledListener::~MarshaledListener()
{
    disconnect();
    releaseConnection(connection);
}
}
