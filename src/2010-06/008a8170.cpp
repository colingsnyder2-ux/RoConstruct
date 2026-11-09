// from server: 100% by auto
// roc 2010-06 008a8170  unit: CXTCaptionButtonTheme  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a8170
//
// 008a8170  56                   push esi
// 008a8171  8bf1                 mov esi, ecx
// 008a8173  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008a8177  8b06                 mov eax, dword ptr [esi]
// 008a8179  8b502c               mov edx, dword ptr [eax + 0x2c]
// 008a817c  51                   push ecx
// 008a817d  8bce                 mov ecx, esi
// 008a817f  ffd2                 call edx
// 008a8181  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008a8185  8b06                 mov eax, dword ptr [esi]
// 008a8187  8b503c               mov edx, dword ptr [eax + 0x3c]
// 008a818a  51                   push ecx
// 008a818b  8bce                 mov ecx, esi
// 008a818d  ffd2                 call edx
// 008a818f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a8193  8b06                 mov eax, dword ptr [esi]
// 008a8195  8b5034               mov edx, dword ptr [eax + 0x34]
// 008a8198  51                   push ecx
// 008a8199  8bce                 mov ecx, esi
// 008a819b  ffd2                 call edx
// 008a819d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008a81a1  8b06                 mov eax, dword ptr [esi]
// 008a81a3  8b5038               mov edx, dword ptr [eax + 0x38]
// 008a81a6  51                   push ecx
// 008a81a7  8bce                 mov ecx, esi
// 008a81a9  ffd2                 call edx
// 008a81ab  5e                   pop esi
// 008a81ac  c21000               ret 0x10
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?SetAlternateColors@CXTButtonTheme@@UAEXKKKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
