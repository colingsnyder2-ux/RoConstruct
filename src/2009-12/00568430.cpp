// from server: 100% by auto
// roc 2009-12 00568430  unit: RakPeer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00568430
//
// 00568430  8b442408             mov eax, dword ptr [esp + 8]
// 00568434  8b542404             mov edx, dword ptr [esp + 4]
// 00568438  56                   push esi
// 00568439  57                   push edi
// 0056843a  8bf1                 mov esi, ecx
// 0056843c  50                   push eax
// 0056843d  8d4c2414             lea ecx, [esp + 0x14]
// 00568441  51                   push ecx
// 00568442  52                   push edx
// 00568443  8bce                 mov ecx, esi
// 00568445  e8f6eaffff           call 0x566f40
// 0056844a  807c241000           cmp byte ptr [esp + 0x10], 0
// 0056844f  8bf8                 mov edi, eax
// 00568451  7507                 jne 0x56845a
// 00568453  5f                   pop edi
// 00568454  33c0                 xor eax, eax
// 00568456  5e                   pop esi
// 00568457  c20800               ret 8
// 0056845a  57                   push edi
// 0056845b  8bce                 mov ecx, esi
// 0056845d  e84ef2ffff           call 0x5676b0
// 00568462  8bc7                 mov eax, edi
// 00568464  5f                   pop edi
// 00568465  5e                   pop esi
// 00568466  c20800               ret 8
// library raknet-4.081/CloudServer.cpp (function ?Remove@?$OrderedList@URakNetGUID@RakNet@@U12@$1??$defaultOrderedListComparison@URakNetGUID@RakNet@@U12@@DataStructures@@YAHABU12@0@Z@DataStructures@@QAEIABURakNetGUID@RakNet@@P6AH00@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudServer.cpp
