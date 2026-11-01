// from server: 100% by auto
// roc 2009-06 00790640  unit: CXTPPropertyGridItemEnum  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790640
//
// 00790640  56                   push esi
// 00790641  8bf1                 mov esi, ecx
// 00790643  e80803fdff           call 0x760950
// 00790648  8bc8                 mov ecx, eax
// 0079064a  e8d112fdff           call 0x761920
// 0079064f  68d0000000           push 0xd0
// 00790654  6a00                 push 0
// 00790656  56                   push esi
// 00790657  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 0079065d  e81296f8ff           call 0x719c74
// 00790662  83c40c               add esp, 0xc
// 00790665  6854fb8f00           push 0x8ffb54
// 0079066a  ff15d4e18900         call dword ptr [0x89e1d4]
// 00790670  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00790676  8bc6                 mov eax, esi
// 00790678  5e                   pop esi
// 00790679  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ??0CSharedData@CXTPWinThemeWrapper@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPWinThemeWrapper.cpp
