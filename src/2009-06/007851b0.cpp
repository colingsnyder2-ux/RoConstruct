// from server: 100% by auto
// roc 2009-06 007851b0  unit: CInstanceRecord::CNameItem  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007851b0
//
// 007851b0  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 007851b6  83f8ff               cmp eax, -1
// 007851b9  750e                 jne 0x7851c9
// 007851bb  e860f9fcff           call 0x754b20
// 007851c0  6a18                 push 0x18
// 007851c2  8bc8                 mov ecx, eax
// 007851c4  e8d7f0fcff           call 0x7542a0
// 007851c9  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?GetTipBkColor@CXTPToolTipContext@@QBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
