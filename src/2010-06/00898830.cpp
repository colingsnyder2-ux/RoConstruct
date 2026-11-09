// from server: 100% by auto
// roc 2010-06 00898830  unit: CXTCaptionTheme  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00898830
//
// 00898830  56                   push esi
// 00898831  8bf1                 mov esi, ecx
// 00898833  e878bdbbff           call 0x4545b0
// 00898838  e8e3b2f4ff           call 0x7e3b20
// 0089883d  6a10                 push 0x10
// 0089883f  8bc8                 mov ecx, eax
// 00898841  e86aaaf4ff           call 0x7e32b0
// 00898846  894618               mov dword ptr [esi + 0x18], eax
// 00898849  e8d2b2f4ff           call 0x7e3b20
// 0089884e  6a14                 push 0x14
// 00898850  8bc8                 mov ecx, eax
// 00898852  e859aaf4ff           call 0x7e32b0
// 00898857  894624               mov dword ptr [esi + 0x24], eax
// 0089885a  5e                   pop esi
// 0089885b  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?RefreshMetrics@CXTCaptionTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
