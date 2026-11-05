// from server: 100% by auto
// roc 2010-06 0089cff0  unit: CXTPTabPaintManager::CColorSetOffice2003  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089cff0
//
// 0089cff0  53                   push ebx
// 0089cff1  56                   push esi
// 0089cff2  57                   push edi
// 0089cff3  e8286bf4ff           call 0x7e3b20
// 0089cff8  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0089cffc  51                   push ecx
// 0089cffd  8bc8                 mov ecx, eax
// 0089cfff  e8ac62f4ff           call 0x7e32b0
// 0089d004  8b742410             mov esi, dword ptr [esp + 0x10]
// 0089d008  50                   push eax
// 0089d009  8d542418             lea edx, [esp + 0x18]
// 0089d00d  52                   push edx
// 0089d00e  8bce                 mov ecx, esi
// 0089d010  e829b7f0ff           call 0x7a873e
// 0089d015  e8066bf4ff           call 0x7e3b20
// 0089d01a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0089d01e  57                   push edi
// 0089d01f  8bc8                 mov ecx, eax
// 0089d021  e88a62f4ff           call 0x7e32b0
// 0089d026  8bd8                 mov ebx, eax
// 0089d028  e8f36af4ff           call 0x7e3b20
// 0089d02d  57                   push edi
// 0089d02e  8bc8                 mov ecx, eax
// 0089d030  e87b62f4ff           call 0x7e32b0
// 0089d035  53                   push ebx
// 0089d036  50                   push eax
// 0089d037  8d44241c             lea eax, [esp + 0x1c]
// 0089d03b  50                   push eax
// 0089d03c  8bce                 mov ecx, esi
// 0089d03e  e8f5b6f0ff           call 0x7a8738
// 0089d043  5f                   pop edi
// 0089d044  5e                   pop esi
// 0089d045  5b                   pop ebx
// 0089d046  c21c00               ret 0x1c
// library xtp-13.2.1/Source\ShortcutBar\XTPShortcutBarPaintManager.cpp (function ?Rectangle@CXTPShortcutBarPaintManager@@QAEXPAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ShortcutBar/XTPShortcutBarPaintManager.cpp
