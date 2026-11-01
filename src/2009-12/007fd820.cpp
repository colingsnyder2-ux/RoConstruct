// from server: 100% by auto
// roc 2009-12 007fd820  unit: CXTPPaintManager  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fd820
//
// 007fd820  8b0da4adb900         mov ecx, dword ptr [0xb9ada4]
// 007fd826  85c9                 test ecx, ecx
// 007fd828  7405                 je 0x7fd82f
// 007fd82a  e8ad65ffff           call 0x7f3ddc
// 007fd82f  c705a4adb90000000000 mov dword ptr [0xb9ada4], 0
// 007fd839  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?Done@CXTPPaintManager@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
