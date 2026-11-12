// from server: 100% by colin
// roc 2007-08 004bf110  unit: RakPeer  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004bf110
//
// 004bf110  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004bf114  8b542408             mov edx, dword ptr [esp + 8]
// 004bf118  6a01                 push 1
// 004bf11a  6a00                 push 0
// 004bf11c  50                   push eax
// 004bf11d  52                   push edx
// 004bf11e  e85ddaffff           call 0x4bcb80
// 004bf123  85c0                 test eax, eax
// 004bf125  740d                 je 0x4bf134
// 004bf127  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004bf12b  51                   push ecx
// 004bf12c  8d4818               lea ecx, [eax + 0x18]
// 004bf12f  e87c590000           call 0x4c4ab0
// 004bf134  c20c00               ret 0xc
// copied from an identical function in another client (function ?SetTimeoutTime@RakPeer@@UAEXIUSystemAddress@@@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp