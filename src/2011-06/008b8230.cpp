// from server: 100% by auto
// roc 2011-06 008b8230  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b8230
//
// 008b8230  53                   push ebx
// 008b8231  56                   push esi
// 008b8232  8bf1                 mov esi, ecx
// 008b8234  8b06                 mov eax, dword ptr [esi]
// 008b8236  8b5058               mov edx, dword ptr [eax + 0x58]
// 008b8239  57                   push edi
// 008b823a  33db                 xor ebx, ebx
// 008b823c  ffd2                 call edx
// 008b823e  8bf8                 mov edi, eax
// 008b8240  83ef01               sub edi, 1
// 008b8243  7833                 js 0x8b8278
// 008b8245  55                   push ebp
// 008b8246  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 008b824a  8d9b00000000         lea ebx, [ebx]
// 008b8250  8b06                 mov eax, dword ptr [esi]
// 008b8252  8b5060               mov edx, dword ptr [eax + 0x60]
// 008b8255  57                   push edi
// 008b8256  8bce                 mov ecx, esi
// 008b8258  ffd2                 call edx
// 008b825a  3bc5                 cmp eax, ebp
// 008b825c  7514                 jne 0x8b8272
// 008b825e  8b06                 mov eax, dword ptr [esi]
// 008b8260  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 008b8266  6a01                 push 1
// 008b8268  57                   push edi
// 008b8269  8bce                 mov ecx, esi
// 008b826b  ffd2                 call edx
// 008b826d  bb01000000           mov ebx, 1
// 008b8272  83ef01               sub edi, 1
// 008b8275  79d9                 jns 0x8b8250
// 008b8277  5d                   pop ebp
// 008b8278  5f                   pop edi
// 008b8279  5e                   pop esi
// 008b827a  8bc3                 mov eax, ebx
// 008b827c  5b                   pop ebx
// 008b827d  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarEventLabel.cpp (function ?RemoveElement@?$CXTPArrayT@IIJ@@UAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarEventLabel.cpp
