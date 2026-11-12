// from server: 100% by auto
// roc 2010-06 00516d80  unit: RakPeer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00516d80
//
// 00516d80  8b442408             mov eax, dword ptr [esp + 8]
// 00516d84  8b542404             mov edx, dword ptr [esp + 4]
// 00516d88  56                   push esi
// 00516d89  57                   push edi
// 00516d8a  8bf1                 mov esi, ecx
// 00516d8c  50                   push eax
// 00516d8d  8d4c2414             lea ecx, [esp + 0x14]
// 00516d91  51                   push ecx
// 00516d92  52                   push edx
// 00516d93  8bce                 mov ecx, esi
// 00516d95  e826ecffff           call 0x5159c0
// 00516d9a  807c241000           cmp byte ptr [esp + 0x10], 0
// 00516d9f  8bf8                 mov edi, eax
// 00516da1  7507                 jne 0x516daa
// 00516da3  5f                   pop edi
// 00516da4  33c0                 xor eax, eax
// 00516da6  5e                   pop esi
// 00516da7  c20800               ret 8
// 00516daa  57                   push edi
// 00516dab  8bce                 mov ecx, esi
// 00516dad  e84ef2ffff           call 0x516000
// 00516db2  8bc7                 mov eax, edi
// 00516db4  5f                   pop edi
// 00516db5  5e                   pop esi
// 00516db6  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?Remove@?$OrderedList@USystemAddress@@USystemAddressAndIndex@@$1?SystemAddressAndIndexComp@@YAHABU1@ABU2@@Z@DataStructures@@QAEIABUSystemAddress@@P6AH0ABUSystemAddressAndIndex@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
