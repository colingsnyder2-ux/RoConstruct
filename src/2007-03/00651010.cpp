// from server: 100% by auto
// roc 2007-03 00651010  unit: seg_00650000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00651010
//
// 00651010  56                   push esi
// 00651011  8bf1                 mov esi, ecx
// 00651013  e868feffff           call 0x650e80
// 00651018  c706ec727c00         mov dword ptr [esi], 0x7c72ec
// 0065101e  c746606c727c00       mov dword ptr [esi + 0x60], 0x7c726c
// 00651025  89b694000000         mov dword ptr [esi + 0x94], esi
// 0065102b  8bc6                 mov eax, esi
// 0065102d  5e                   pop esi
// 0065102e  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeCtrlView.cpp (function ??0CXTPTreeView@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeCtrlView.cpp
