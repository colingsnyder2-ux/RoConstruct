// from server: 100% by auto
// roc 2010-06 007e9030  unit: CXTTreeCtrlBase  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e9030
//
// 007e9030  56                   push esi
// 007e9031  8bf1                 mov esi, ecx
// 007e9033  e868feffff           call 0x7e8ea0
// 007e9038  c70674b4a500         mov dword ptr [esi], 0xa5b474
// 007e903e  c74660ecb3a500       mov dword ptr [esi + 0x60], 0xa5b3ec
// 007e9045  89b694000000         mov dword ptr [esi + 0x94], esi
// 007e904b  8bc6                 mov eax, esi
// 007e904d  5e                   pop esi
// 007e904e  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeCtrlView.cpp (function ??0CXTTreeView@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeCtrlView.cpp
