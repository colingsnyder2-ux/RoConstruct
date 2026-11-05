// from server: 100% by auto
// roc 2010-06 0080e2c0  unit: CXTThemeManagerStyle  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e2c0
//
// 0080e2c0  56                   push esi
// 0080e2c1  57                   push edi
// 0080e2c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0080e2c6  8bf1                 mov esi, ecx
// 0080e2c8  85ff                 test edi, edi
// 0080e2ca  7444                 je 0x80e310
// 0080e2cc  8b4e04               mov ecx, dword ptr [esi + 4]
// 0080e2cf  85c9                 test ecx, ecx
// 0080e2d1  740f                 je 0x80e2e2
// 0080e2d3  8b01                 mov eax, dword ptr [ecx]
// 0080e2d5  8b10                 mov edx, dword ptr [eax]
// 0080e2d7  6a01                 push 1
// 0080e2d9  ffd2                 call edx
// 0080e2db  c7460400000000       mov dword ptr [esi + 4], 0
// 0080e2e2  897e04               mov dword ptr [esi + 4], edi
// 0080e2e5  897704               mov dword ptr [edi + 4], esi
// 0080e2e8  8b4e04               mov ecx, dword ptr [esi + 4]
// 0080e2eb  8b01                 mov eax, dword ptr [ecx]
// 0080e2ed  8b5004               mov edx, dword ptr [eax + 4]
// 0080e2f0  ffd2                 call edx
// 0080e2f2  8b7608               mov esi, dword ptr [esi + 8]
// 0080e2f5  85f6                 test esi, esi
// 0080e2f7  7417                 je 0x80e310
// 0080e2f9  8da42400000000       lea esp, [esp]
// 0080e300  8b06                 mov eax, dword ptr [esi]
// 0080e302  8b5008               mov edx, dword ptr [eax + 8]
// 0080e305  8bce                 mov ecx, esi
// 0080e307  ffd2                 call edx
// 0080e309  8b7614               mov esi, dword ptr [esi + 0x14]
// 0080e30c  85f6                 test esi, esi
// 0080e30e  75f0                 jne 0x80e300
// 0080e310  5f                   pop edi
// 0080e311  5e                   pop esi
// 0080e312  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?SetTheme@CXTThemeManagerStyleFactory@@QAEXPAVCXTThemeManagerStyle@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
