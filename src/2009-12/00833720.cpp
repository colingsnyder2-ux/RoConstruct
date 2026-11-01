// from server: 100% by auto
// roc 2009-12 00833720  unit: CRobloxTreeCtrl  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00833720
//
// 00833720  8b4134               mov eax, dword ptr [ecx + 0x34]
// 00833723  8b4838               mov ecx, dword ptr [eax + 0x38]
// 00833726  85c9                 test ecx, ecx
// 00833728  7403                 je 0x83372d
// 0083372a  51                   push ecx
// 0083372b  eb0b                 jmp 0x833738
// 0083372d  8b4020               mov eax, dword ptr [eax + 0x20]
// 00833730  50                   push eax
// 00833731  ff15bccb9800         call dword ptr [0x98cbbc]
// 00833737  50                   push eax
// 00833738  e8ed03fcff           call 0x7f3b2a
// 0083373d  85c0                 test eax, eax
// 0083373f  741c                 je 0x83375d
// 00833741  8b4020               mov eax, dword ptr [eax + 0x20]
// 00833744  85c0                 test eax, eax
// 00833746  7415                 je 0x83375d
// 00833748  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083374c  51                   push ecx
// 0083374d  8b4904               mov ecx, dword ptr [ecx + 4]
// 00833750  51                   push ecx
// 00833751  6a4e                 push 0x4e
// 00833753  50                   push eax
// 00833754  ff15c4cb9800         call dword ptr [0x98cbc4]
// 0083375a  c20400               ret 4
// 0083375d  33c0                 xor eax, eax
// 0083375f  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SendNotify@CXTPTreeBase@@MAEJPAUtagNMHDR@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
