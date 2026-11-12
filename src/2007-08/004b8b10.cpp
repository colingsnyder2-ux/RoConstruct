// from server: 100% by colin
// roc 2007-08 004b8b10  unit: RakPeer  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b8b10
//
// 004b8b10  8b442404             mov eax, dword ptr [esp + 4]
// 004b8b14  85c0                 test eax, eax
// 004b8b16  741c                 je 0x4b8b34
// 004b8b18  803800               cmp byte ptr [eax], 0
// 004b8b1b  7417                 je 0x4b8b34
// 004b8b1d  8b542408             mov edx, dword ptr [esp + 8]
// 004b8b21  85d2                 test edx, edx
// 004b8b23  740f                 je 0x4b8b34
// 004b8b25  6a01                 push 1
// 004b8b27  52                   push edx
// 004b8b28  50                   push eax
// 004b8b29  81c1fc060000         add ecx, 0x6fc
// 004b8b2f  e88c140100           call 0x4c9fc0
// 004b8b34  c20800               ret 8
// copied from an identical function in another client (function ?RegisterClassMemberRPC@RakPeer@@UAEXPBDPAX@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp