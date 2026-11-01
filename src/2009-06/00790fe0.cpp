// from server: 100% by auto
// roc 2009-06 00790fe0  unit: CXTPPropertyGridItemEnum  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790fe0
//
// 00790fe0  56                   push esi
// 00790fe1  8bf1                 mov esi, ecx
// 00790fe3  33c0                 xor eax, eax
// 00790fe5  8906                 mov dword ptr [esi], eax
// 00790fe7  894604               mov dword ptr [esi + 4], eax
// 00790fea  6868fb8f00           push 0x8ffb68
// 00790fef  894608               mov dword ptr [esi + 8], eax
// 00790ff2  ff15d4e18900         call dword ptr [0x89e1d4]
// 00790ff8  89460c               mov dword ptr [esi + 0xc], eax
// 00790ffb  8bc6                 mov eax, esi
// 00790ffd  5e                   pop esi
// 00790ffe  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ??0CSharedData@CXTPWinDwmWrapper@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPWinThemeWrapper.cpp
