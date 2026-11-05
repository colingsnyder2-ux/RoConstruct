// from server: 100% by EspClaude
// roc 2009-06 00424350  unit: MainLogManager  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424350
//
// 00424350  6848010000           push 0x148
// 00424355  e8de462f00           call 0x718a38
// 0042435a  83c404               add esp, 4
// 0042435d  85c0                 test eax, eax
// 0042435f  7406                 je 0x424367
// 00424361  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00424365  8908                 mov dword ptr [eax], ecx
// 00424367  8d4804               lea ecx, [eax + 4]
// 0042436a  85c9                 test ecx, ecx
// 0042436c  7406                 je 0x424374
// 0042436e  8b542408             mov edx, dword ptr [esp + 8]
// 00424372  8911                 mov dword ptr [ecx], edx
// 00424374  57                   push edi
// 00424375  8d7808               lea edi, [eax + 8]
// 00424378  85ff                 test edi, edi
// 0042437a  740d                 je 0x424389
// 0042437c  56                   push esi
// 0042437d  8b742414             mov esi, dword ptr [esp + 0x14]
// 00424381  b950000000           mov ecx, 0x50
// 00424386  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00424388  5e                   pop esi
// 00424389  5f                   pop edi
// 0042438a  c20c00               ret 0xc
// copied from an identical function in another client (function ?_Buynode@?$list@UE@@V?$allocator@UE@@@std@@@std@@IAEPAU_Node@?$_List_nod@UE@@V?$allocator@UE@@@std@@@2@PAU342@0ABUE@@@Z)

#include <list>

struct E {
    char data[320];
    bool operator==(const E&) const;
    bool operator<(const E&) const;
};

template class std::list<E>;