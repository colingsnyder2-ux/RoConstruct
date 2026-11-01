// from server: 100% by auto
// roc 2009-06 007588a0  unit: CRobloxTreeCtrl  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007588a0
//
// 007588a0  8b4134               mov eax, dword ptr [ecx + 0x34]
// 007588a3  8b4838               mov ecx, dword ptr [eax + 0x38]
// 007588a6  85c9                 test ecx, ecx
// 007588a8  7403                 je 0x7588ad
// 007588aa  51                   push ecx
// 007588ab  eb0b                 jmp 0x7588b8
// 007588ad  8b4020               mov eax, dword ptr [eax + 0x20]
// 007588b0  50                   push eax
// 007588b1  ff1598ee8900         call dword ptr [0x89ee98]
// 007588b7  50                   push eax
// 007588b8  e84504fcff           call 0x718d02
// 007588bd  85c0                 test eax, eax
// 007588bf  741c                 je 0x7588dd
// 007588c1  8b4020               mov eax, dword ptr [eax + 0x20]
// 007588c4  85c0                 test eax, eax
// 007588c6  7415                 je 0x7588dd
// 007588c8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007588cc  51                   push ecx
// 007588cd  8b4904               mov ecx, dword ptr [ecx + 4]
// 007588d0  51                   push ecx
// 007588d1  6a4e                 push 0x4e
// 007588d3  50                   push eax
// 007588d4  ff1590ee8900         call dword ptr [0x89ee90]
// 007588da  c20400               ret 4
// 007588dd  33c0                 xor eax, eax
// 007588df  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SendNotify@CXTPTreeBase@@MAEJPAUtagNMHDR@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
