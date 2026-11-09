// from server: 100% by auto
// roc 2009-12 0085a330  unit: CXTThemeManagerStyle  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a330
//
// 0085a330  56                   push esi
// 0085a331  57                   push edi
// 0085a332  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0085a336  8bf1                 mov esi, ecx
// 0085a338  85ff                 test edi, edi
// 0085a33a  7444                 je 0x85a380
// 0085a33c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0085a33f  85c9                 test ecx, ecx
// 0085a341  740f                 je 0x85a352
// 0085a343  8b01                 mov eax, dword ptr [ecx]
// 0085a345  8b10                 mov edx, dword ptr [eax]
// 0085a347  6a01                 push 1
// 0085a349  ffd2                 call edx
// 0085a34b  c7460400000000       mov dword ptr [esi + 4], 0
// 0085a352  897e04               mov dword ptr [esi + 4], edi
// 0085a355  897704               mov dword ptr [edi + 4], esi
// 0085a358  8b4e04               mov ecx, dword ptr [esi + 4]
// 0085a35b  8b01                 mov eax, dword ptr [ecx]
// 0085a35d  8b5004               mov edx, dword ptr [eax + 4]
// 0085a360  ffd2                 call edx
// 0085a362  8b7608               mov esi, dword ptr [esi + 8]
// 0085a365  85f6                 test esi, esi
// 0085a367  7417                 je 0x85a380
// 0085a369  8da42400000000       lea esp, [esp]
// 0085a370  8b06                 mov eax, dword ptr [esi]
// 0085a372  8b5008               mov edx, dword ptr [eax + 8]
// 0085a375  8bce                 mov ecx, esi
// 0085a377  ffd2                 call edx
// 0085a379  8b7614               mov esi, dword ptr [esi + 0x14]
// 0085a37c  85f6                 test esi, esi
// 0085a37e  75f0                 jne 0x85a370
// 0085a380  5f                   pop edi
// 0085a381  5e                   pop esi
// 0085a382  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?SetTheme@CXTThemeManagerStyleFactory@@QAEXPAVCXTThemeManagerStyle@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
