// from server: 100% by colin
// roc 2007-08 004b8e90  unit: RakPeer  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b8e90
//
// 004b8e90  51                   push ecx
// 004b8e91  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004b8e95  8b542408             mov edx, dword ptr [esp + 8]
// 004b8e99  8b8914070000         mov ecx, dword ptr [ecx + 0x714]
// 004b8e9f  50                   push eax
// 004b8ea0  52                   push edx
// 004b8ea1  8b542418             mov edx, dword ptr [esp + 0x18]
// 004b8ea5  6a02                 push 2
// 004b8ea7  8d44240c             lea eax, [esp + 0xc]
// 004b8eab  50                   push eax
// 004b8eac  c644241000           mov byte ptr [esp + 0x10], 0
// 004b8eb1  c644241101           mov byte ptr [esp + 0x11], 1
// 004b8eb6  8b0491               mov eax, dword ptr [ecx + edx*4]
// 004b8eb9  50                   push eax
// 004b8eba  b9e9ef8b00           mov ecx, 0x8befe9
// 004b8ebf  e81cba0000           call 0x4c48e0
// 004b8ec4  59                   pop ecx
// 004b8ec5  c20c00               ret 0xc
// copied from an identical function in another client (function ?SendTTL1@RakPeer@@UAEXPBDGI@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp