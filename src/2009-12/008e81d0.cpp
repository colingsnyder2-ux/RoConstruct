// from server: 100% by auto
// roc 2009-12 008e81d0  unit: CXTPTabPaintManager::CColorSetOffice2003  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e81d0
//
// 008e81d0  53                   push ebx
// 008e81d1  56                   push esi
// 008e81d2  57                   push edi
// 008e81d3  e8f877f4ff           call 0x82f9d0
// 008e81d8  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e81dc  51                   push ecx
// 008e81dd  8bc8                 mov ecx, eax
// 008e81df  e81c6ff4ff           call 0x82f100
// 008e81e4  8b742410             mov esi, dword ptr [esp + 0x10]
// 008e81e8  50                   push eax
// 008e81e9  8d542418             lea edx, [esp + 0x18]
// 008e81ed  52                   push edx
// 008e81ee  8bce                 mov ecx, esi
// 008e81f0  e809c4f0ff           call 0x7f45fe
// 008e81f5  e8d677f4ff           call 0x82f9d0
// 008e81fa  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 008e81fe  57                   push edi
// 008e81ff  8bc8                 mov ecx, eax
// 008e8201  e8fa6ef4ff           call 0x82f100
// 008e8206  8bd8                 mov ebx, eax
// 008e8208  e8c377f4ff           call 0x82f9d0
// 008e820d  57                   push edi
// 008e820e  8bc8                 mov ecx, eax
// 008e8210  e8eb6ef4ff           call 0x82f100
// 008e8215  53                   push ebx
// 008e8216  50                   push eax
// 008e8217  8d44241c             lea eax, [esp + 0x1c]
// 008e821b  50                   push eax
// 008e821c  8bce                 mov ecx, esi
// 008e821e  e8d5c3f0ff           call 0x7f45f8
// 008e8223  5f                   pop edi
// 008e8224  5e                   pop esi
// 008e8225  5b                   pop ebx
// 008e8226  c21c00               ret 0x1c
// library xtp-15.2.1/Source\ShortcutBar\XTPShortcutBarPaintManager.cpp (function ?Rectangle@CXTPShortcutBarPaintManager@@QAEXPAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ShortcutBar/XTPShortcutBarPaintManager.cpp
