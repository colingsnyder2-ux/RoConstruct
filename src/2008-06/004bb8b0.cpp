// from server: 100% by auto
// roc 2008-06 004bb8b0  unit: ProfiledRakPeer  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb8b0
//
// 004bb8b0  8b442404             mov eax, dword ptr [esp + 4]
// 004bb8b4  85c0                 test eax, eax
// 004bb8b6  741c                 je 0x4bb8d4
// 004bb8b8  803800               cmp byte ptr [eax], 0
// 004bb8bb  7417                 je 0x4bb8d4
// 004bb8bd  8b542408             mov edx, dword ptr [esp + 8]
// 004bb8c1  85d2                 test edx, edx
// 004bb8c3  740f                 je 0x4bb8d4
// 004bb8c5  6a01                 push 1
// 004bb8c7  52                   push edx
// 004bb8c8  50                   push eax
// 004bb8c9  81c1fc060000         add ecx, 0x6fc
// 004bb8cf  e8bc840100           call 0x4d3d90
// 004bb8d4  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?RegisterClassMemberRPC@RakPeer@@UAEXPBDPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
