// from server: 100% by auto
// roc 2010-06 00820000  unit: CXTPPropertyGridItemEnum  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00820000
//
// 00820000  56                   push esi
// 00820001  8bf1                 mov esi, ecx
// 00820003  33c0                 xor eax, eax
// 00820005  8906                 mov dword ptr [esi], eax
// 00820007  894604               mov dword ptr [esi + 4], eax
// 0082000a  68e842a600           push 0xa642e8
// 0082000f  894608               mov dword ptr [esi + 8], eax
// 00820012  ff1548a39e00         call dword ptr [0x9ea348]
// 00820018  89460c               mov dword ptr [esi + 0xc], eax
// 0082001b  8bc6                 mov eax, esi
// 0082001d  5e                   pop esi
// 0082001e  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ??0CSharedData@CXTPWinDwmWrapper@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPWinThemeWrapper.cpp
