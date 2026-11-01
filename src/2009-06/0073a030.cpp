// from server: 100% by auto
// roc 2009-06 0073a030  unit: CXTPImageManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073a030
//
// 0073a030  8b4104               mov eax, dword ptr [ecx + 4]
// 0073a033  8b09                 mov ecx, dword ptr [ecx]
// 0073a035  8988ec000000         mov dword ptr [eax + 0xec], ecx
// 0073a03b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??1CXTPPushRoutingFrame@CXTPToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
