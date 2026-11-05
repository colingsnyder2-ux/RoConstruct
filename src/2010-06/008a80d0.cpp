// from server: 100% by auto
// roc 2010-06 008a80d0  unit: CXTCaptionButtonTheme  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a80d0
//
// 008a80d0  56                   push esi
// 008a80d1  8bf1                 mov esi, ecx
// 008a80d3  e8d8c4baff           call 0x4545b0
// 008a80d8  e813d6f3ff           call 0x7e56f0
// 008a80dd  68845da500           push 0xa55d84
// 008a80e2  6a00                 push 0
// 008a80e4  8d4e74               lea ecx, [esi + 0x74]
// 008a80e7  e8147cf7ff           call 0x81fd00
// 008a80ec  e82fbaf3ff           call 0x7e3b20
// 008a80f1  6a0f                 push 0xf
// 008a80f3  8bc8                 mov ecx, eax
// 008a80f5  e8b6b1f3ff           call 0x7e32b0
// 008a80fa  894624               mov dword ptr [esi + 0x24], eax
// 008a80fd  e81ebaf3ff           call 0x7e3b20
// 008a8102  6a12                 push 0x12
// 008a8104  8bc8                 mov ecx, eax
// 008a8106  e8a5b1f3ff           call 0x7e32b0
// 008a810b  894630               mov dword ptr [esi + 0x30], eax
// 008a810e  e80dbaf3ff           call 0x7e3b20
// 008a8113  6a11                 push 0x11
// 008a8115  8bc8                 mov ecx, eax
// 008a8117  e894b1f3ff           call 0x7e32b0
// 008a811c  89463c               mov dword ptr [esi + 0x3c], eax
// 008a811f  e8fcb9f3ff           call 0x7e3b20
// 008a8124  6a0f                 push 0xf
// 008a8126  8bc8                 mov ecx, eax
// 008a8128  e883b1f3ff           call 0x7e32b0
// 008a812d  894648               mov dword ptr [esi + 0x48], eax
// 008a8130  e8ebb9f3ff           call 0x7e3b20
// 008a8135  6a10                 push 0x10
// 008a8137  8bc8                 mov ecx, eax
// 008a8139  e872b1f3ff           call 0x7e32b0
// 008a813e  894654               mov dword ptr [esi + 0x54], eax
// 008a8141  e8dab9f3ff           call 0x7e3b20
// 008a8146  6a14                 push 0x14
// 008a8148  8bc8                 mov ecx, eax
// 008a814a  e861b1f3ff           call 0x7e32b0
// 008a814f  894660               mov dword ptr [esi + 0x60], eax
// 008a8152  e8c9b9f3ff           call 0x7e3b20
// 008a8157  6a15                 push 0x15
// 008a8159  8bc8                 mov ecx, eax
// 008a815b  e850b1f3ff           call 0x7e32b0
// 008a8160  89466c               mov dword ptr [esi + 0x6c], eax
// 008a8163  5e                   pop esi
// 008a8164  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?RefreshMetrics@CXTButtonTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
