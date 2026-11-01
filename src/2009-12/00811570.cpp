// from server: 100% by auto
// roc 2009-12 00811570  unit: CXTPToolBar  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00811570
//
// 00811570  56                   push esi
// 00811571  8bf1                 mov esi, ecx
// 00811573  e8582fffff           call 0x8044d0
// 00811578  8bc8                 mov ecx, eax
// 0081157a  85c9                 test ecx, ecx
// 0081157c  7422                 je 0x8115a0
// 0081157e  8b542408             mov edx, dword ptr [esp + 8]
// 00811582  83fa02               cmp edx, 2
// 00811585  740e                 je 0x811595
// 00811587  85d2                 test edx, edx
// 00811589  740a                 je 0x811595
// 0081158b  83fa03               cmp edx, 3
// 0081158e  7405                 je 0x811595
// 00811590  83fa01               cmp edx, 1
// 00811593  7511                 jne 0x8115a6
// 00811595  52                   push edx
// 00811596  56                   push esi
// 00811597  e8542c0000           call 0x8141f0
// 0081159c  85c0                 test eax, eax
// 0081159e  7515                 jne 0x8115b5
// 008115a0  33c0                 xor eax, eax
// 008115a2  5e                   pop esi
// 008115a3  c20400               ret 4
// 008115a6  83fa04               cmp edx, 4
// 008115a9  75f5                 jne 0x8115a0
// 008115ab  56                   push esi
// 008115ac  e87f2c0000           call 0x814230
// 008115b1  85c0                 test eax, eax
// 008115b3  74eb                 je 0x8115a0
// 008115b5  b801000000           mov eax, 1
// 008115ba  5e                   pop esi
// 008115bb  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPToolBar.cpp (function ?SetPosition@CXTPToolBar@@UAEHW4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPToolBar.cpp
