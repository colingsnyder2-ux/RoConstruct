// from server: 100% by auto
// roc 2011-06 00525970  unit: RBX::Network::ProfiledRakPeer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00525970
//
// 00525970  8b442408             mov eax, dword ptr [esp + 8]
// 00525974  8b542404             mov edx, dword ptr [esp + 4]
// 00525978  6a00                 push 0
// 0052597a  6a00                 push 0
// 0052597c  50                   push eax
// 0052597d  52                   push edx
// 0052597e  e84df0ffff           call 0x5249d0
// 00525983  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?Ping@RakPeer@@UAEXUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
