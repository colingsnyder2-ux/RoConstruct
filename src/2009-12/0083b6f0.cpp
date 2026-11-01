// from server: 100% by auto
// roc 2009-12 0083b6f0  unit: CXTPToolBar::CControlButtonExpand  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b6f0
//
// 0083b6f0  56                   push esi
// 0083b6f1  6894000000           push 0x94
// 0083b6f6  8bf1                 mov esi, ecx
// 0083b6f8  6a00                 push 0
// 0083b6fa  56                   push esi
// 0083b6fb  e8a493fbff           call 0x7f4aa4
// 0083b700  83c40c               add esp, 0xc
// 0083b703  56                   push esi
// 0083b704  c70694000000         mov dword ptr [esi], 0x94
// 0083b70a  ff15e4b19800         call dword ptr [0x98b1e4]
// 0083b710  8bc6                 mov eax, esi
// 0083b712  5e                   pop esi
// 0083b713  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ??0CXTPSystemVersion@@AAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
