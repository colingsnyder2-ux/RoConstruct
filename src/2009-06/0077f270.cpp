// from server: 100% by auto
// roc 2009-06 0077f270  unit: CXTThemeManagerStyle  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f270
//
// 0077f270  56                   push esi
// 0077f271  57                   push edi
// 0077f272  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0077f276  8bf1                 mov esi, ecx
// 0077f278  85ff                 test edi, edi
// 0077f27a  7444                 je 0x77f2c0
// 0077f27c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0077f27f  85c9                 test ecx, ecx
// 0077f281  740f                 je 0x77f292
// 0077f283  8b01                 mov eax, dword ptr [ecx]
// 0077f285  8b10                 mov edx, dword ptr [eax]
// 0077f287  6a01                 push 1
// 0077f289  ffd2                 call edx
// 0077f28b  c7460400000000       mov dword ptr [esi + 4], 0
// 0077f292  897e04               mov dword ptr [esi + 4], edi
// 0077f295  897704               mov dword ptr [edi + 4], esi
// 0077f298  8b4e04               mov ecx, dword ptr [esi + 4]
// 0077f29b  8b01                 mov eax, dword ptr [ecx]
// 0077f29d  8b5004               mov edx, dword ptr [eax + 4]
// 0077f2a0  ffd2                 call edx
// 0077f2a2  8b7608               mov esi, dword ptr [esi + 8]
// 0077f2a5  85f6                 test esi, esi
// 0077f2a7  7417                 je 0x77f2c0
// 0077f2a9  8da42400000000       lea esp, [esp]
// 0077f2b0  8b06                 mov eax, dword ptr [esi]
// 0077f2b2  8b5008               mov edx, dword ptr [eax + 8]
// 0077f2b5  8bce                 mov ecx, esi
// 0077f2b7  ffd2                 call edx
// 0077f2b9  8b7614               mov esi, dword ptr [esi + 0x14]
// 0077f2bc  85f6                 test esi, esi
// 0077f2be  75f0                 jne 0x77f2b0
// 0077f2c0  5f                   pop edi
// 0077f2c1  5e                   pop esi
// 0077f2c2  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?SetTheme@CXTThemeManagerStyleFactory@@QAEXPAVCXTThemeManagerStyle@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
