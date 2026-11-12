// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 00462510  unit: RBX::VSelection::?$MarshaledListener::EventData  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00462510
//
// 00462510  6aff                 push -1
// 00462512  68332b7400           push 0x742b33
// 00462517  64a100000000         mov eax, dword ptr fs:[0]
// 0046251d  50                   push eax
// 0046251e  51                   push ecx
// 0046251f  56                   push esi
// 00462520  a188518b00           mov eax, dword ptr [0x8b5188]
// 00462525  33c4                 xor eax, esp
// 00462527  50                   push eax
// 00462528  8d44240c             lea eax, [esp + 0xc]
// 0046252c  64a300000000         mov dword ptr fs:[0], eax
// 00462532  8bf1                 mov esi, ecx
// 00462534  89742408             mov dword ptr [esp + 8], esi
// 00462538  c70608537900         mov dword ptr [esi], 0x795308
// 0046253e  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00462546  e8c5fcffff           call 0x462210
// 0046254b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0046254e  50                   push eax
// 0046254f  e80c11fdff           call 0x433660
// 00462554  8b4608               mov eax, dword ptr [esi + 8]
// 00462557  83c404               add esp, 4
// 0046255a  85c0                 test eax, eax
// 0046255c  7409                 je 0x462567
// 0046255e  50                   push eax
// 0046255f  e8fed61c00           call 0x62fc62
// 00462564  83c404               add esp, 4
// 00462567  c7460800000000       mov dword ptr [esi + 8], 0
// 0046256e  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00462575  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0046257c  c70638837800         mov dword ptr [esi], 0x788338
// 00462582  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00462586  64890d00000000       mov dword ptr fs:[0], ecx
// 0046258d  59                   pop ecx
// 0046258e  5e                   pop esi
// 0046258f  83c410               add esp, 0x10
// 00462592  c3                   ret 
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
