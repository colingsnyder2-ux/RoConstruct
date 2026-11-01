// from server: 100% by auto
// roc 2007-03 00653260  unit: seg_00650000  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00653260
//
// 00653260  8b4134               mov eax, dword ptr [ecx + 0x34]
// 00653263  8b4838               mov ecx, dword ptr [eax + 0x38]
// 00653266  85c9                 test ecx, ecx
// 00653268  7403                 je 0x65326d
// 0065326a  51                   push ecx
// 0065326b  eb0b                 jmp 0x653278
// 0065326d  8b4020               mov eax, dword ptr [eax + 0x20]
// 00653270  50                   push eax
// 00653271  ff15c8ec7700         call dword ptr [0x77ecc8]
// 00653277  50                   push eax
// 00653278  e8d1b3fcff           call 0x61e64e
// 0065327d  85c0                 test eax, eax
// 0065327f  741c                 je 0x65329d
// 00653281  8b4020               mov eax, dword ptr [eax + 0x20]
// 00653284  85c0                 test eax, eax
// 00653286  7415                 je 0x65329d
// 00653288  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0065328c  51                   push ecx
// 0065328d  8b4904               mov ecx, dword ptr [ecx + 4]
// 00653290  51                   push ecx
// 00653291  6a4e                 push 0x4e
// 00653293  50                   push eax
// 00653294  ff1550ee7700         call dword ptr [0x77ee50]
// 0065329a  c20400               ret 4
// 0065329d  33c0                 xor eax, eax
// 0065329f  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SendNotify@CXTPTreeBase@@MAEJPAUtagNMHDR@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
