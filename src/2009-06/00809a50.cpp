// from server: 100% by auto
// roc 2009-06 00809a50  unit: CXTCaptionTheme  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00809a50
//
// 00809a50  56                   push esi
// 00809a51  8bf1                 mov esi, ecx
// 00809a53  e888afe6ff           call 0x6749e0
// 00809a58  e8c3b0f4ff           call 0x754b20
// 00809a5d  6a10                 push 0x10
// 00809a5f  8bc8                 mov ecx, eax
// 00809a61  e83aa8f4ff           call 0x7542a0
// 00809a66  894618               mov dword ptr [esi + 0x18], eax
// 00809a69  e8b2b0f4ff           call 0x754b20
// 00809a6e  6a14                 push 0x14
// 00809a70  8bc8                 mov ecx, eax
// 00809a72  e829a8f4ff           call 0x7542a0
// 00809a77  894624               mov dword ptr [esi + 0x24], eax
// 00809a7a  5e                   pop esi
// 00809a7b  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?RefreshMetrics@CXTCaptionTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
