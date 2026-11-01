// from server: 100% by auto
// roc 2009-06 00758800  unit: CRobloxTreeCtrl  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758800
//
// 00758800  56                   push esi
// 00758801  57                   push edi
// 00758802  8bf1                 mov esi, ecx
// 00758804  33ff                 xor edi, edi
// 00758806  e8d5eeffff           call 0x7576e0
// 0075880b  85c0                 test eax, eax
// 0075880d  740e                 je 0x75881d
// 0075880f  90                   nop 
// 00758810  50                   push eax
// 00758811  8bce                 mov ecx, esi
// 00758813  47                   inc edi
// 00758814  e817efffff           call 0x757730
// 00758819  85c0                 test eax, eax
// 0075881b  75f3                 jne 0x758810
// 0075881d  8bc7                 mov eax, edi
// 0075881f  5f                   pop edi
// 00758820  5e                   pop esi
// 00758821  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetSelectedCount@CXTPTreeBase@@QBEIXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
