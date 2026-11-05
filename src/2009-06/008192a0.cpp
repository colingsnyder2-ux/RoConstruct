// from server: 100% by auto
// roc 2009-06 008192a0  unit: CXTCaptionButtonTheme  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008192a0
//
// 008192a0  56                   push esi
// 008192a1  8bf1                 mov esi, ecx
// 008192a3  e838b7e5ff           call 0x6749e0
// 008192a8  e843d4f3ff           call 0x7566f0
// 008192ad  6844248f00           push 0x8f2444
// 008192b2  6a00                 push 0
// 008192b4  8d4e74               lea ecx, [esi + 0x74]
// 008192b7  e8247af7ff           call 0x790ce0
// 008192bc  e85fb8f3ff           call 0x754b20
// 008192c1  6a0f                 push 0xf
// 008192c3  8bc8                 mov ecx, eax
// 008192c5  e8d6aff3ff           call 0x7542a0
// 008192ca  894624               mov dword ptr [esi + 0x24], eax
// 008192cd  e84eb8f3ff           call 0x754b20
// 008192d2  6a12                 push 0x12
// 008192d4  8bc8                 mov ecx, eax
// 008192d6  e8c5aff3ff           call 0x7542a0
// 008192db  894630               mov dword ptr [esi + 0x30], eax
// 008192de  e83db8f3ff           call 0x754b20
// 008192e3  6a11                 push 0x11
// 008192e5  8bc8                 mov ecx, eax
// 008192e7  e8b4aff3ff           call 0x7542a0
// 008192ec  89463c               mov dword ptr [esi + 0x3c], eax
// 008192ef  e82cb8f3ff           call 0x754b20
// 008192f4  6a0f                 push 0xf
// 008192f6  8bc8                 mov ecx, eax
// 008192f8  e8a3aff3ff           call 0x7542a0
// 008192fd  894648               mov dword ptr [esi + 0x48], eax
// 00819300  e81bb8f3ff           call 0x754b20
// 00819305  6a10                 push 0x10
// 00819307  8bc8                 mov ecx, eax
// 00819309  e892aff3ff           call 0x7542a0
// 0081930e  894654               mov dword ptr [esi + 0x54], eax
// 00819311  e80ab8f3ff           call 0x754b20
// 00819316  6a14                 push 0x14
// 00819318  8bc8                 mov ecx, eax
// 0081931a  e881aff3ff           call 0x7542a0
// 0081931f  894660               mov dword ptr [esi + 0x60], eax
// 00819322  e8f9b7f3ff           call 0x754b20
// 00819327  6a15                 push 0x15
// 00819329  8bc8                 mov ecx, eax
// 0081932b  e870aff3ff           call 0x7542a0
// 00819330  89466c               mov dword ptr [esi + 0x6c], eax
// 00819333  5e                   pop esi
// 00819334  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?RefreshMetrics@CXTButtonTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
