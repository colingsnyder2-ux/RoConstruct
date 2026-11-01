// from server: 100% by auto
// roc 2009-12 008ba9a0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneOffice2003Theme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ba9a0
//
// 008ba9a0  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 008ba9a3  51                   push ecx
// 008ba9a4  e887fbffff           call 0x8ba530
// 008ba9a9  83c404               add esp, 4
// 008ba9ac  85c0                 test eax, eax
// 008ba9ae  740e                 je 0x8ba9be
// 008ba9b0  8bc8                 mov ecx, eax
// 008ba9b2  e879cde9ff           call 0x757730
// 008ba9b7  a802                 test al, 2
// 008ba9b9  7503                 jne 0x8ba9be
// 008ba9bb  33c0                 xor eax, eax
// 008ba9bd  c3                   ret 
// 008ba9be  b801000000           mov eax, 1
// 008ba9c3  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?IsEnabled@CXTPDockingPaneCaptionButton@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
