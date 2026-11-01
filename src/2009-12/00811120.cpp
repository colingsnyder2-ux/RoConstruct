// from server: 100% by auto
// roc 2009-12 00811120  unit: CXTPImageManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00811120
//
// 00811120  8b4104               mov eax, dword ptr [ecx + 4]
// 00811123  8b09                 mov ecx, dword ptr [ecx]
// 00811125  8988ec000000         mov dword ptr [eax + 0xec], ecx
// 0081112b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??1CXTPPushRoutingFrame@CXTPToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
