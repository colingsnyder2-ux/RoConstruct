// from server: 100% by auto
// roc 2011-06 009017a0  unit: CXTCaptionButtonTheme  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009017a0
//
// 009017a0  56                   push esi
// 009017a1  8bf1                 mov esi, ecx
// 009017a3  e8989ef6ff           call 0x86b640
// 009017a8  e80358f4ff           call 0x846fb0
// 009017ad  68e419ac00           push 0xac19e4
// 009017b2  6a00                 push 0
// 009017b4  8d4e74               lea ecx, [esi + 0x74]
// 009017b7  e854bcf7ff           call 0x87d410
// 009017bc  e81f3cf4ff           call 0x8453e0
// 009017c1  6a0f                 push 0xf
// 009017c3  8bc8                 mov ecx, eax
// 009017c5  e8e633f4ff           call 0x844bb0
// 009017ca  894624               mov dword ptr [esi + 0x24], eax
// 009017cd  e80e3cf4ff           call 0x8453e0
// 009017d2  6a12                 push 0x12
// 009017d4  8bc8                 mov ecx, eax
// 009017d6  e8d533f4ff           call 0x844bb0
// 009017db  894630               mov dword ptr [esi + 0x30], eax
// 009017de  e8fd3bf4ff           call 0x8453e0
// 009017e3  6a11                 push 0x11
// 009017e5  8bc8                 mov ecx, eax
// 009017e7  e8c433f4ff           call 0x844bb0
// 009017ec  89463c               mov dword ptr [esi + 0x3c], eax
// 009017ef  e8ec3bf4ff           call 0x8453e0
// 009017f4  6a0f                 push 0xf
// 009017f6  8bc8                 mov ecx, eax
// 009017f8  e8b333f4ff           call 0x844bb0
// 009017fd  894648               mov dword ptr [esi + 0x48], eax
// 00901800  e8db3bf4ff           call 0x8453e0
// 00901805  6a10                 push 0x10
// 00901807  8bc8                 mov ecx, eax
// 00901809  e8a233f4ff           call 0x844bb0
// 0090180e  894654               mov dword ptr [esi + 0x54], eax
// 00901811  e8ca3bf4ff           call 0x8453e0
// 00901816  6a14                 push 0x14
// 00901818  8bc8                 mov ecx, eax
// 0090181a  e89133f4ff           call 0x844bb0
// 0090181f  894660               mov dword ptr [esi + 0x60], eax
// 00901822  e8b93bf4ff           call 0x8453e0
// 00901827  6a15                 push 0x15
// 00901829  8bc8                 mov ecx, eax
// 0090182b  e88033f4ff           call 0x844bb0
// 00901830  89466c               mov dword ptr [esi + 0x6c], eax
// 00901833  5e                   pop esi
// 00901834  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?RefreshMetrics@CXTButtonTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
