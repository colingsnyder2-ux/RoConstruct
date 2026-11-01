// from server: 100% by auto
// roc 2009-12 0086b660  unit: CXTPPropertyGridItemEnum  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086b660
//
// 0086b660  56                   push esi
// 0086b661  8bf1                 mov esi, ecx
// 0086b663  e8b800fdff           call 0x83b720
// 0086b668  8bc8                 mov ecx, eax
// 0086b66a  e88110fdff           call 0x83c6f0
// 0086b66f  68d0000000           push 0xd0
// 0086b674  6a00                 push 0
// 0086b676  56                   push esi
// 0086b677  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 0086b67d  e82294f8ff           call 0x7f4aa4
// 0086b682  83c40c               add esp, 0xc
// 0086b685  68dcff9f00           push 0x9fffdc
// 0086b68a  ff15d8b19800         call dword ptr [0x98b1d8]
// 0086b690  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0086b696  8bc6                 mov eax, esi
// 0086b698  5e                   pop esi
// 0086b699  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ??0CSharedData@CXTPWinThemeWrapper@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPWinThemeWrapper.cpp
