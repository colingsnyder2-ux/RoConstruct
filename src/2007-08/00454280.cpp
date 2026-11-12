// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 00454280  unit: RBX::VInstance::?$MarshaledListener  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00454280
//
// 00454280  6aff                 push -1
// 00454282  68f3147400           push 0x7414f3
// 00454287  64a100000000         mov eax, dword ptr fs:[0]
// 0045428d  50                   push eax
// 0045428e  51                   push ecx
// 0045428f  56                   push esi
// 00454290  a188518b00           mov eax, dword ptr [0x8b5188]
// 00454295  33c4                 xor eax, esp
// 00454297  50                   push eax
// 00454298  8d44240c             lea eax, [esp + 0xc]
// 0045429c  64a300000000         mov dword ptr fs:[0], eax
// 004542a2  8bf1                 mov esi, ecx
// 004542a4  89742408             mov dword ptr [esp + 8], esi
// 004542a8  c706d0217900         mov dword ptr [esi], 0x7921d0
// 004542ae  c744241401000000     mov dword ptr [esp + 0x14], 1
// 004542b6  e855df0000           call 0x462210
// 004542bb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004542be  50                   push eax
// 004542bf  e89cf3fdff           call 0x433660
// 004542c4  8b4608               mov eax, dword ptr [esi + 8]
// 004542c7  83c404               add esp, 4
// 004542ca  85c0                 test eax, eax
// 004542cc  7409                 je 0x4542d7
// 004542ce  50                   push eax
// 004542cf  e88eb91d00           call 0x62fc62
// 004542d4  83c404               add esp, 4
// 004542d7  c7460800000000       mov dword ptr [esi + 8], 0
// 004542de  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 004542e5  c7461000000000       mov dword ptr [esi + 0x10], 0
// 004542ec  c7065c837800         mov dword ptr [esi], 0x78835c
// 004542f2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004542f6  64890d00000000       mov dword ptr fs:[0], ecx
// 004542fd  59                   pop ecx
// 004542fe  5e                   pop esi
// 004542ff  83c410               add esp, 0x10
// 00454302  c3                   ret 
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
