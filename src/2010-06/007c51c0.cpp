// from server: 100% by auto
// roc 2010-06 007c51c0  unit: CXTPImageManager  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c51c0
//
// 007c51c0  8b4104               mov eax, dword ptr [ecx + 4]
// 007c51c3  8b09                 mov ecx, dword ptr [ecx]
// 007c51c5  8988ec000000         mov dword ptr [eax + 0xec], ecx
// 007c51cb  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??1CXTPPushRoutingFrame@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMenuBar.cpp
