// from server: 100% by auto
// roc 2007-03 00721e00  unit: seg_00720000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00721e00
//
// 00721e00  56                   push esi
// 00721e01  8bf1                 mov esi, ecx
// 00721e03  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00721e07  8b06                 mov eax, dword ptr [esi]
// 00721e09  8b502c               mov edx, dword ptr [eax + 0x2c]
// 00721e0c  51                   push ecx
// 00721e0d  8bce                 mov ecx, esi
// 00721e0f  ffd2                 call edx
// 00721e11  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00721e15  8b06                 mov eax, dword ptr [esi]
// 00721e17  8b503c               mov edx, dword ptr [eax + 0x3c]
// 00721e1a  51                   push ecx
// 00721e1b  8bce                 mov ecx, esi
// 00721e1d  ffd2                 call edx
// 00721e1f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00721e23  8b06                 mov eax, dword ptr [esi]
// 00721e25  8b5034               mov edx, dword ptr [eax + 0x34]
// 00721e28  51                   push ecx
// 00721e29  8bce                 mov ecx, esi
// 00721e2b  ffd2                 call edx
// 00721e2d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00721e31  8b06                 mov eax, dword ptr [esi]
// 00721e33  8b5038               mov edx, dword ptr [eax + 0x38]
// 00721e36  51                   push ecx
// 00721e37  8bce                 mov ecx, esi
// 00721e39  ffd2                 call edx
// 00721e3b  5e                   pop esi
// 00721e3c  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?SetAlternateColors@CXTButtonTheme@@UAEXKKKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
