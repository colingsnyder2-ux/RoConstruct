// from server: 100% by auto
// roc 2009-12 0086c000  unit: CXTPPropertyGridItemEnum  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086c000
//
// 0086c000  56                   push esi
// 0086c001  8bf1                 mov esi, ecx
// 0086c003  33c0                 xor eax, eax
// 0086c005  8906                 mov dword ptr [esi], eax
// 0086c007  894604               mov dword ptr [esi + 4], eax
// 0086c00a  68f0ff9f00           push 0x9ffff0
// 0086c00f  894608               mov dword ptr [esi + 8], eax
// 0086c012  ff15d8b19800         call dword ptr [0x98b1d8]
// 0086c018  89460c               mov dword ptr [esi + 0xc], eax
// 0086c01b  8bc6                 mov eax, esi
// 0086c01d  5e                   pop esi
// 0086c01e  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ??0CSharedData@CXTPWinDwmWrapper@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPWinThemeWrapper.cpp
