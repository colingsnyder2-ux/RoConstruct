// from server: 100% by auto
// roc 2009-06 00819340  unit: CXTCaptionButtonTheme  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00819340
//
// 00819340  56                   push esi
// 00819341  8bf1                 mov esi, ecx
// 00819343  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00819347  8b06                 mov eax, dword ptr [esi]
// 00819349  8b502c               mov edx, dword ptr [eax + 0x2c]
// 0081934c  51                   push ecx
// 0081934d  8bce                 mov ecx, esi
// 0081934f  ffd2                 call edx
// 00819351  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00819355  8b06                 mov eax, dword ptr [esi]
// 00819357  8b503c               mov edx, dword ptr [eax + 0x3c]
// 0081935a  51                   push ecx
// 0081935b  8bce                 mov ecx, esi
// 0081935d  ffd2                 call edx
// 0081935f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00819363  8b06                 mov eax, dword ptr [esi]
// 00819365  8b5034               mov edx, dword ptr [eax + 0x34]
// 00819368  51                   push ecx
// 00819369  8bce                 mov ecx, esi
// 0081936b  ffd2                 call edx
// 0081936d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00819371  8b06                 mov eax, dword ptr [esi]
// 00819373  8b5038               mov edx, dword ptr [eax + 0x38]
// 00819376  51                   push ecx
// 00819377  8bce                 mov ecx, esi
// 00819379  ffd2                 call edx
// 0081937b  5e                   pop esi
// 0081937c  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?SetAlternateColors@CXTButtonTheme@@UAEXKKKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
