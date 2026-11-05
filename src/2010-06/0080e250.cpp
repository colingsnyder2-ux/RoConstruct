// from server: 100% by auto
// roc 2010-06 0080e250  unit: CXTThemeManagerStyle  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e250
//
// 0080e250  56                   push esi
// 0080e251  8b742408             mov esi, dword ptr [esp + 8]
// 0080e255  85f6                 test esi, esi
// 0080e257  7506                 jne 0x80e25f
// 0080e259  33c0                 xor eax, eax
// 0080e25b  5e                   pop esi
// 0080e25c  c20400               ret 4
// 0080e25f  57                   push edi
// 0080e260  8d44240c             lea eax, [esp + 0xc]
// 0080e264  8d7904               lea edi, [ecx + 4]
// 0080e267  50                   push eax
// 0080e268  56                   push esi
// 0080e269  8bcf                 mov ecx, edi
// 0080e26b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0080e273  e8baf11600           call 0x97d432
// 0080e278  85c0                 test eax, eax
// 0080e27a  7519                 jne 0x80e295
// 0080e27c  53                   push ebx
// 0080e27d  8bce                 mov ecx, esi
// 0080e27f  e81ea1f9ff           call 0x7a83a2
// 0080e284  56                   push esi
// 0080e285  8bcf                 mov ecx, edi
// 0080e287  89442414             mov dword ptr [esp + 0x14], eax
// 0080e28b  8bd8                 mov ebx, eax
// 0080e28d  e80af11600           call 0x97d39c
// 0080e292  8918                 mov dword ptr [eax], ebx
// 0080e294  5b                   pop ebx
// 0080e295  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0080e299  5f                   pop edi
// 0080e29a  5e                   pop esi
// 0080e29b  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?GetDefaultThemeFactory@CXTThemeManager@@QAEPAVCXTThemeManagerStyleFactory@@PAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
