// from server: 100% by auto
// roc 2010-06 00856f70  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00856f70
//
// 00856f70  53                   push ebx
// 00856f71  56                   push esi
// 00856f72  8bf1                 mov esi, ecx
// 00856f74  8b06                 mov eax, dword ptr [esi]
// 00856f76  8b5058               mov edx, dword ptr [eax + 0x58]
// 00856f79  57                   push edi
// 00856f7a  33db                 xor ebx, ebx
// 00856f7c  ffd2                 call edx
// 00856f7e  8bf8                 mov edi, eax
// 00856f80  83ef01               sub edi, 1
// 00856f83  7833                 js 0x856fb8
// 00856f85  55                   push ebp
// 00856f86  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00856f8a  8d9b00000000         lea ebx, [ebx]
// 00856f90  8b06                 mov eax, dword ptr [esi]
// 00856f92  8b5060               mov edx, dword ptr [eax + 0x60]
// 00856f95  57                   push edi
// 00856f96  8bce                 mov ecx, esi
// 00856f98  ffd2                 call edx
// 00856f9a  3bc5                 cmp eax, ebp
// 00856f9c  7514                 jne 0x856fb2
// 00856f9e  8b06                 mov eax, dword ptr [esi]
// 00856fa0  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 00856fa6  6a01                 push 1
// 00856fa8  57                   push edi
// 00856fa9  8bce                 mov ecx, esi
// 00856fab  ffd2                 call edx
// 00856fad  bb01000000           mov ebx, 1
// 00856fb2  83ef01               sub edi, 1
// 00856fb5  79d9                 jns 0x856f90
// 00856fb7  5d                   pop ebp
// 00856fb8  5f                   pop edi
// 00856fb9  5e                   pop esi
// 00856fba  8bc3                 mov eax, ebx
// 00856fbc  5b                   pop ebx
// 00856fbd  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPCalendarEventLabel.cpp (function ?RemoveElement@?$CXTPArrayT@IIJ@@UAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPCalendarEventLabel.cpp
