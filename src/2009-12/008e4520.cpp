// from server: 100% by auto
// roc 2009-12 008e4520  unit: CXTCaptionTheme  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e4520
//
// 008e4520  56                   push esi
// 008e4521  8bf1                 mov esi, ecx
// 008e4523  e86805f7ff           call 0x854a90
// 008e4528  e8a3b4f4ff           call 0x82f9d0
// 008e452d  6a10                 push 0x10
// 008e452f  8bc8                 mov ecx, eax
// 008e4531  e8caabf4ff           call 0x82f100
// 008e4536  894618               mov dword ptr [esi + 0x18], eax
// 008e4539  e892b4f4ff           call 0x82f9d0
// 008e453e  6a14                 push 0x14
// 008e4540  8bc8                 mov ecx, eax
// 008e4542  e8b9abf4ff           call 0x82f100
// 008e4547  894624               mov dword ptr [esi + 0x24], eax
// 008e454a  5e                   pop esi
// 008e454b  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?RefreshMetrics@CXTCaptionTheme@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
