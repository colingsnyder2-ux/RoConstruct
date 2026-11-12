// from server: 100% by auto
// roc 2008-06 004c49b0  unit: ProfiledRakPeer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c49b0
//
// 004c49b0  8b442408             mov eax, dword ptr [esp + 8]
// 004c49b4  8b542404             mov edx, dword ptr [esp + 4]
// 004c49b8  6a00                 push 0
// 004c49ba  6a00                 push 0
// 004c49bc  50                   push eax
// 004c49bd  52                   push edx
// 004c49be  e85dddffff           call 0x4c2720
// 004c49c3  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?Ping@RakPeer@@UAEXUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
