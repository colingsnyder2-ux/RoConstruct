// from server: 100% by auto
// roc 2010-06 007e7220  unit: CXTTreeBase  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7220
//
// 007e7220  8b4134               mov eax, dword ptr [ecx + 0x34]
// 007e7223  85c0                 test eax, eax
// 007e7225  750d                 jne 0x7e7234
// 007e7227  50                   push eax
// 007e7228  ff1528bc9e00         call dword ptr [0x9ebc28]
// 007e722e  85c0                 test eax, eax
// 007e7230  0f95c0               setne al
// 007e7233  c3                   ret 
// 007e7234  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e7237  50                   push eax
// 007e7238  ff1528bc9e00         call dword ptr [0x9ebc28]
// 007e723e  85c0                 test eax, eax
// 007e7240  0f95c0               setne al
// 007e7243  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?Init@CXTTreeBase@@MAE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
