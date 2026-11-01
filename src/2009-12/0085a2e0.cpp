// from server: 100% by auto
// roc 2009-12 0085a2e0  unit: CXTThemeManagerStyle  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a2e0
//
// 0085a2e0  56                   push esi
// 0085a2e1  8b742408             mov esi, dword ptr [esp + 8]
// 0085a2e5  85f6                 test esi, esi
// 0085a2e7  7506                 jne 0x85a2ef
// 0085a2e9  33c0                 xor eax, eax
// 0085a2eb  5e                   pop esi
// 0085a2ec  c20400               ret 4
// 0085a2ef  57                   push edi
// 0085a2f0  8d44240c             lea eax, [esp + 0xc]
// 0085a2f4  8d7904               lea edi, [ecx + 4]
// 0085a2f7  50                   push eax
// 0085a2f8  56                   push esi
// 0085a2f9  8bcf                 mov ecx, edi
// 0085a2fb  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0085a303  e8e8c70c00           call 0x926af0
// 0085a308  85c0                 test eax, eax
// 0085a30a  7519                 jne 0x85a325
// 0085a30c  53                   push ebx
// 0085a30d  8bce                 mov ecx, esi
// 0085a30f  e84e9ff9ff           call 0x7f4262
// 0085a314  56                   push esi
// 0085a315  8bcf                 mov ecx, edi
// 0085a317  89442414             mov dword ptr [esp + 0x14], eax
// 0085a31b  8bd8                 mov ebx, eax
// 0085a31d  e838c70c00           call 0x926a5a
// 0085a322  8918                 mov dword ptr [eax], ebx
// 0085a324  5b                   pop ebx
// 0085a325  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0085a329  5f                   pop edi
// 0085a32a  5e                   pop esi
// 0085a32b  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTThemeManager.cpp (function ?GetDefaultThemeFactory@CXTThemeManager@@QAEPAVCXTThemeManagerStyleFactory@@PAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTThemeManager.cpp
