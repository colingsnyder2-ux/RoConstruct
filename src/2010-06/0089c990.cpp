// from server: 100% by auto
// roc 2010-06 0089c990  unit: CXTPTabPaintManager::CColorSetVisualStudio  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089c990
//
// 0089c990  56                   push esi
// 0089c991  8bf1                 mov esi, ecx
// 0089c993  e8d8f5ffff           call 0x89bf70
// 0089c998  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0089c99e  e83d9dc3ff           call 0x4d66e0
// 0089c9a3  83f807               cmp eax, 7
// 0089c9a6  7427                 je 0x89c9cf
// 0089c9a8  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0089c9ae  e82d9dc3ff           call 0x4d66e0
// 0089c9b3  83f804               cmp eax, 4
// 0089c9b6  7417                 je 0x89c9cf
// 0089c9b8  e86371f4ff           call 0x7e3b20
// 0089c9bd  6a30                 push 0x30
// 0089c9bf  8bc8                 mov ecx, eax
// 0089c9c1  e8ea68f4ff           call 0x7e32b0
// 0089c9c6  50                   push eax
// 0089c9c7  8d4e04               lea ecx, [esi + 4]
// 0089c9ca  e8a170f4ff           call 0x7e3a70
// 0089c9cf  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0089c9d5  e8069dc3ff           call 0x4d66e0
// 0089c9da  83f805               cmp eax, 5
// 0089c9dd  7528                 jne 0x89ca07
// 0089c9df  e83c71f4ff           call 0x7e3b20
// 0089c9e4  6a31                 push 0x31
// 0089c9e6  8bc8                 mov ecx, eax
// 0089c9e8  e8c368f4ff           call 0x7e32b0
// 0089c9ed  8986b4000000         mov dword ptr [esi + 0xb4], eax
// 0089c9f3  e82871f4ff           call 0x7e3b20
// 0089c9f8  6a31                 push 0x31
// 0089c9fa  8bc8                 mov ecx, eax
// 0089c9fc  e8af68f4ff           call 0x7e32b0
// 0089ca01  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 0089ca07  e8f448f6ff           call 0x801300
// 0089ca0c  6a00                 push 0
// 0089ca0e  e8ad20f6ff           call 0x7feac0
// 0089ca13  83c404               add esp, 4
// 0089ca16  85c0                 test eax, eax
// 0089ca18  7419                 je 0x89ca33
// 0089ca1a  e80171f4ff           call 0x7e3b20
// 0089ca1f  6a0f                 push 0xf
// 0089ca21  8bc8                 mov ecx, eax
// 0089ca23  e88868f4ff           call 0x7e32b0
// 0089ca28  50                   push eax
// 0089ca29  8d4e24               lea ecx, [esi + 0x24]
// 0089ca2c  e83f70f4ff           call 0x7e3a70
// 0089ca31  5e                   pop esi
// 0089ca32  c3                   ret 
// 0089ca33  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0089ca36  83f8ff               cmp eax, -1
// 0089ca39  7503                 jne 0x89ca3e
// 0089ca3b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0089ca3e  50                   push eax
// 0089ca3f  8d4e24               lea ecx, [esi + 0x24]
// 0089ca42  e82970f4ff           call 0x7e3a70
// 0089ca47  5e                   pop esi
// 0089ca48  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?RefreshMetrics@CColorSetVisualStudio2003@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
