// from server: 100% by auto
// roc 2010-06 007c5600  unit: CXTPToolBar  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c5600
//
// 007c5600  56                   push esi
// 007c5601  8bf1                 mov esi, ecx
// 007c5603  e8c82fffff           call 0x7b85d0
// 007c5608  8bc8                 mov ecx, eax
// 007c560a  85c9                 test ecx, ecx
// 007c560c  7422                 je 0x7c5630
// 007c560e  8b542408             mov edx, dword ptr [esp + 8]
// 007c5612  83fa02               cmp edx, 2
// 007c5615  740e                 je 0x7c5625
// 007c5617  85d2                 test edx, edx
// 007c5619  740a                 je 0x7c5625
// 007c561b  83fa03               cmp edx, 3
// 007c561e  7405                 je 0x7c5625
// 007c5620  83fa01               cmp edx, 1
// 007c5623  7511                 jne 0x7c5636
// 007c5625  52                   push edx
// 007c5626  56                   push esi
// 007c5627  e8a42c0000           call 0x7c82d0
// 007c562c  85c0                 test eax, eax
// 007c562e  7515                 jne 0x7c5645
// 007c5630  33c0                 xor eax, eax
// 007c5632  5e                   pop esi
// 007c5633  c20400               ret 4
// 007c5636  83fa04               cmp edx, 4
// 007c5639  75f5                 jne 0x7c5630
// 007c563b  56                   push esi
// 007c563c  e8cf2c0000           call 0x7c8310
// 007c5641  85c0                 test eax, eax
// 007c5643  74eb                 je 0x7c5630
// 007c5645  b801000000           mov eax, 1
// 007c564a  5e                   pop esi
// 007c564b  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPToolBar.cpp (function ?SetPosition@CXTPToolBar@@UAEHW4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPToolBar.cpp
