// from server: 100% by auto
// roc 2007-03 00651040  unit: seg_00650000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00651040
//
// 00651040  c701ec727c00         mov dword ptr [ecx], 0x7c72ec
// 00651046  c741606c727c00       mov dword ptr [ecx + 0x60], 0x7c726c
// 0065104d  e9befeffff           jmp 0x650f10
// library xtp-15.2.1/Source\Controls\List\XTPListCtrlView.cpp (function ??1CXTPListView@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/List/XTPListCtrlView.cpp
