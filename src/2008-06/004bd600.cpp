// from server: 100% by auto
// roc 2008-06 004bd600  unit: ProfiledRakPeer  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd600
//
// 004bd600  837c240400           cmp dword ptr [esp + 4], 0
// 004bd605  7426                 je 0x4bd62d
// 004bd607  81c1f0080000         add ecx, 0x8f0
// 004bd60d  807c240800           cmp byte ptr [esp + 8], 0
// 004bd612  740f                 je 0x4bd623
// 004bd614  6a00                 push 0
// 004bd616  8d442408             lea eax, [esp + 8]
// 004bd61a  50                   push eax
// 004bd61b  e890180100           call 0x4ceeb0
// 004bd620  c20800               ret 8
// 004bd623  8d542404             lea edx, [esp + 4]
// 004bd627  52                   push edx
// 004bd628  e8b3170100           call 0x4cede0
// 004bd62d  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?PushBackPacket@RakPeer@@UAEXPAUPacket@@_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
