// from server: 100% by auto
// roc 2010-06 007e9100  unit: CXTTreeView  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e9100
//
// 007e9100  56                   push esi
// 007e9101  8bf1                 mov esi, ecx
// 007e9103  e888feffff           call 0x7e8f90
// 007e9108  c70694aba500         mov dword ptr [esi], 0xa5ab94
// 007e910e  c746540caba500       mov dword ptr [esi + 0x54], 0xa5ab0c
// 007e9115  89b688000000         mov dword ptr [esi + 0x88], esi
// 007e911b  8bc6                 mov eax, esi
// 007e911d  5e                   pop esi
// 007e911e  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeCtrlView.cpp (function ??0CXTTreeCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeCtrlView.cpp
