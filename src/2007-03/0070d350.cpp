// from server: 100% by auto
// roc 2007-03 0070d350  unit: seg_00700000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0070d350
//
// 0070d350  53                   push ebx
// 0070d351  56                   push esi
// 0070d352  57                   push edi
// 0070d353  e8487cf4ff           call 0x654fa0
// 0070d358  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0070d35c  51                   push ecx
// 0070d35d  8bc8                 mov ecx, eax
// 0070d35f  e84c74f4ff           call 0x6547b0
// 0070d364  8b742410             mov esi, dword ptr [esp + 0x10]
// 0070d368  50                   push eax
// 0070d369  8d542418             lea edx, [esp + 0x18]
// 0070d36d  52                   push edx
// 0070d36e  8bce                 mov ecx, esi
// 0070d370  e8a519f1ff           call 0x61ed1a
// 0070d375  e8267cf4ff           call 0x654fa0
// 0070d37a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0070d37e  57                   push edi
// 0070d37f  8bc8                 mov ecx, eax
// 0070d381  e82a74f4ff           call 0x6547b0
// 0070d386  8bd8                 mov ebx, eax
// 0070d388  e8137cf4ff           call 0x654fa0
// 0070d38d  57                   push edi
// 0070d38e  8bc8                 mov ecx, eax
// 0070d390  e81b74f4ff           call 0x6547b0
// 0070d395  53                   push ebx
// 0070d396  50                   push eax
// 0070d397  8d44241c             lea eax, [esp + 0x1c]
// 0070d39b  50                   push eax
// 0070d39c  8bce                 mov ecx, esi
// 0070d39e  e87119f1ff           call 0x61ed14
// 0070d3a3  5f                   pop edi
// 0070d3a4  5e                   pop esi
// 0070d3a5  5b                   pop ebx
// 0070d3a6  c21c00               ret 0x1c
// library xtp-15.2.1/Source\ShortcutBar\XTPShortcutBarPaintManager.cpp (function ?Rectangle@CXTPShortcutBarPaintManager@@QAEXPAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ShortcutBar/XTPShortcutBarPaintManager.cpp
