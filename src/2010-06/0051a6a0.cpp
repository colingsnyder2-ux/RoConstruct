// from server: 100% by auto
// roc 2010-06 0051a6a0  unit: RakPeer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0051a6a0
//
// 0051a6a0  8b442408             mov eax, dword ptr [esp + 8]
// 0051a6a4  8b542404             mov edx, dword ptr [esp + 4]
// 0051a6a8  6a00                 push 0
// 0051a6aa  6a00                 push 0
// 0051a6ac  50                   push eax
// 0051a6ad  52                   push edx
// 0051a6ae  e82ddcffff           call 0x5182e0
// 0051a6b3  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?Ping@RakPeer@@UAEXUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
