// from server: 100% by auto
// roc 2009-12 00833680  unit: CRobloxTreeCtrl  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00833680
//
// 00833680  56                   push esi
// 00833681  57                   push edi
// 00833682  8bf1                 mov esi, ecx
// 00833684  33ff                 xor edi, edi
// 00833686  e8d5eeffff           call 0x832560
// 0083368b  85c0                 test eax, eax
// 0083368d  740e                 je 0x83369d
// 0083368f  90                   nop 
// 00833690  50                   push eax
// 00833691  8bce                 mov ecx, esi
// 00833693  47                   inc edi
// 00833694  e817efffff           call 0x8325b0
// 00833699  85c0                 test eax, eax
// 0083369b  75f3                 jne 0x833690
// 0083369d  8bc7                 mov eax, edi
// 0083369f  5f                   pop edi
// 008336a0  5e                   pop esi
// 008336a1  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetSelectedCount@CXTPTreeBase@@QBEIXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
