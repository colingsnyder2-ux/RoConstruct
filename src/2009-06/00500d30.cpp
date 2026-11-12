// from server: 100% by auto
// roc 2009-06 00500d30  unit: RakPeer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00500d30
//
// 00500d30  8b442408             mov eax, dword ptr [esp + 8]
// 00500d34  8b542404             mov edx, dword ptr [esp + 4]
// 00500d38  56                   push esi
// 00500d39  57                   push edi
// 00500d3a  8bf1                 mov esi, ecx
// 00500d3c  50                   push eax
// 00500d3d  8d4c2414             lea ecx, [esp + 0x14]
// 00500d41  51                   push ecx
// 00500d42  52                   push edx
// 00500d43  8bce                 mov ecx, esi
// 00500d45  e856ebffff           call 0x4ff8a0
// 00500d4a  807c241000           cmp byte ptr [esp + 0x10], 0
// 00500d4f  8bf8                 mov edi, eax
// 00500d51  7507                 jne 0x500d5a
// 00500d53  5f                   pop edi
// 00500d54  33c0                 xor eax, eax
// 00500d56  5e                   pop esi
// 00500d57  c20800               ret 8
// 00500d5a  57                   push edi
// 00500d5b  8bce                 mov ecx, esi
// 00500d5d  e84ef2ffff           call 0x4fffb0
// 00500d62  8bc7                 mov eax, edi
// 00500d64  5f                   pop edi
// 00500d65  5e                   pop esi
// 00500d66  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?Remove@?$OrderedList@USystemAddress@@USystemAddressAndIndex@@$1?SystemAddressAndIndexComp@@YAHABU1@ABU2@@Z@DataStructures@@QAEIABUSystemAddress@@P6AH0ABUSystemAddressAndIndex@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
