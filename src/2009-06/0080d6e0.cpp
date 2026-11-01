// from server: 100% by auto
// roc 2009-06 0080d6e0  unit: CXTPTabPaintManager::CColorSetOffice2003  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080d6e0
//
// 0080d6e0  53                   push ebx
// 0080d6e1  56                   push esi
// 0080d6e2  57                   push edi
// 0080d6e3  e83874f4ff           call 0x754b20
// 0080d6e8  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0080d6ec  51                   push ecx
// 0080d6ed  8bc8                 mov ecx, eax
// 0080d6ef  e8ac6bf4ff           call 0x7542a0
// 0080d6f4  8b742410             mov esi, dword ptr [esp + 0x10]
// 0080d6f8  50                   push eax
// 0080d6f9  8d542418             lea edx, [esp + 0x18]
// 0080d6fd  52                   push edx
// 0080d6fe  8bce                 mov ecx, esi
// 0080d700  e8cbc0f0ff           call 0x7197d0
// 0080d705  e81674f4ff           call 0x754b20
// 0080d70a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0080d70e  57                   push edi
// 0080d70f  8bc8                 mov ecx, eax
// 0080d711  e88a6bf4ff           call 0x7542a0
// 0080d716  8bd8                 mov ebx, eax
// 0080d718  e80374f4ff           call 0x754b20
// 0080d71d  57                   push edi
// 0080d71e  8bc8                 mov ecx, eax
// 0080d720  e87b6bf4ff           call 0x7542a0
// 0080d725  53                   push ebx
// 0080d726  50                   push eax
// 0080d727  8d44241c             lea eax, [esp + 0x1c]
// 0080d72b  50                   push eax
// 0080d72c  8bce                 mov ecx, esi
// 0080d72e  e897c0f0ff           call 0x7197ca
// 0080d733  5f                   pop edi
// 0080d734  5e                   pop esi
// 0080d735  5b                   pop ebx
// 0080d736  c21c00               ret 0x1c
// library xtp-15.2.1/Source\ShortcutBar\XTPShortcutBarPaintManager.cpp (function ?Rectangle@CXTPShortcutBarPaintManager@@QAEXPAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ShortcutBar/XTPShortcutBarPaintManager.cpp
