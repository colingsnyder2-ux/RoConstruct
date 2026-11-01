// from server: 100% by auto
// roc 2009-12 008f4030  unit: CXTCaptionButtonTheme  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f4030
//
// 008f4030  56                   push esi
// 008f4031  8bf1                 mov esi, ecx
// 008f4033  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008f4037  8b06                 mov eax, dword ptr [esi]
// 008f4039  8b502c               mov edx, dword ptr [eax + 0x2c]
// 008f403c  51                   push ecx
// 008f403d  8bce                 mov ecx, esi
// 008f403f  ffd2                 call edx
// 008f4041  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008f4045  8b06                 mov eax, dword ptr [esi]
// 008f4047  8b503c               mov edx, dword ptr [eax + 0x3c]
// 008f404a  51                   push ecx
// 008f404b  8bce                 mov ecx, esi
// 008f404d  ffd2                 call edx
// 008f404f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008f4053  8b06                 mov eax, dword ptr [esi]
// 008f4055  8b5034               mov edx, dword ptr [eax + 0x34]
// 008f4058  51                   push ecx
// 008f4059  8bce                 mov ecx, esi
// 008f405b  ffd2                 call edx
// 008f405d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f4061  8b06                 mov eax, dword ptr [esi]
// 008f4063  8b5038               mov edx, dword ptr [eax + 0x38]
// 008f4066  51                   push ecx
// 008f4067  8bce                 mov ecx, esi
// 008f4069  ffd2                 call edx
// 008f406b  5e                   pop esi
// 008f406c  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?SetAlternateColors@CXTButtonTheme@@UAEXKKKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
