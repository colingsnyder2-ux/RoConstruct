// from server: 100% by auto
// roc 2011-06 0086ba60  unit: CXTThemeManagerStyle  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086ba60
//
// 0086ba60  56                   push esi
// 0086ba61  57                   push edi
// 0086ba62  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0086ba66  8bf1                 mov esi, ecx
// 0086ba68  85ff                 test edi, edi
// 0086ba6a  7444                 je 0x86bab0
// 0086ba6c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0086ba6f  85c9                 test ecx, ecx
// 0086ba71  740f                 je 0x86ba82
// 0086ba73  8b01                 mov eax, dword ptr [ecx]
// 0086ba75  8b10                 mov edx, dword ptr [eax]
// 0086ba77  6a01                 push 1
// 0086ba79  ffd2                 call edx
// 0086ba7b  c7460400000000       mov dword ptr [esi + 4], 0
// 0086ba82  897e04               mov dword ptr [esi + 4], edi
// 0086ba85  897704               mov dword ptr [edi + 4], esi
// 0086ba88  8b4e04               mov ecx, dword ptr [esi + 4]
// 0086ba8b  8b01                 mov eax, dword ptr [ecx]
// 0086ba8d  8b5004               mov edx, dword ptr [eax + 4]
// 0086ba90  ffd2                 call edx
// 0086ba92  8b7608               mov esi, dword ptr [esi + 8]
// 0086ba95  85f6                 test esi, esi
// 0086ba97  7417                 je 0x86bab0
// 0086ba99  8da42400000000       lea esp, [esp]
// 0086baa0  8b06                 mov eax, dword ptr [esi]
// 0086baa2  8b5008               mov edx, dword ptr [eax + 8]
// 0086baa5  8bce                 mov ecx, esi
// 0086baa7  ffd2                 call edx
// 0086baa9  8b7614               mov esi, dword ptr [esi + 0x14]
// 0086baac  85f6                 test esi, esi
// 0086baae  75f0                 jne 0x86baa0
// 0086bab0  5f                   pop edi
// 0086bab1  5e                   pop esi
// 0086bab2  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?SetTheme@CXTThemeManagerStyleFactory@@QAEXPAVCXTThemeManagerStyle@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
