// from server: 100% by auto
// roc 2009-06 00504650  unit: RakPeer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00504650
//
// 00504650  8b442408             mov eax, dword ptr [esp + 8]
// 00504654  8b542404             mov edx, dword ptr [esp + 4]
// 00504658  6a00                 push 0
// 0050465a  6a00                 push 0
// 0050465c  50                   push eax
// 0050465d  52                   push edx
// 0050465e  e82ddcffff           call 0x502290
// 00504663  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?Ping@RakPeer@@UAEXUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
