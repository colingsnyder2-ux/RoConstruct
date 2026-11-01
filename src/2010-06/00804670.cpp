// from server: 100% by auto
// roc 2010-06 00804670  unit: CXTPPropExchangeArchive  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804670
//
// 00804670  56                   push esi
// 00804671  8bf1                 mov esi, ecx
// 00804673  8b06                 mov eax, dword ptr [esi]
// 00804675  8b9090000000         mov edx, dword ptr [eax + 0x90]
// 0080467b  ffd2                 call edx
// 0080467d  85c0                 test eax, eax
// 0080467f  7504                 jne 0x804685
// 00804681  5e                   pop esi
// 00804682  c20c00               ret 0xc
// 00804685  837e2800             cmp dword ptr [esi + 0x28], 0
// 00804689  8b06                 mov eax, dword ptr [esi]
// 0080468b  57                   push edi
// 0080468c  752a                 jne 0x8046b8
// 0080468e  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00804692  8b0f                 mov ecx, dword ptr [edi]
// 00804694  8b5078               mov edx, dword ptr [eax + 0x78]
// 00804697  51                   push ecx
// 00804698  8bce                 mov ecx, esi
// 0080469a  ffd2                 call edx
// 0080469c  8b07                 mov eax, dword ptr [edi]
// 0080469e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008046a2  8b11                 mov edx, dword ptr [ecx]
// 008046a4  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 008046a7  50                   push eax
// 008046a8  52                   push edx
// 008046a9  e86e3efaff           call 0x7a851c
// 008046ae  5f                   pop edi
// 008046af  b801000000           mov eax, 1
// 008046b4  5e                   pop esi
// 008046b5  c20c00               ret 0xc
// 008046b8  8b507c               mov edx, dword ptr [eax + 0x7c]
// 008046bb  53                   push ebx
// 008046bc  8bce                 mov ecx, esi
// 008046be  ffd2                 call edx
// 008046c0  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 008046c4  833b00               cmp dword ptr [ebx], 0
// 008046c7  8bf8                 mov edi, eax
// 008046c9  752d                 jne 0x8046f8
// 008046cb  57                   push edi
// 008046cc  ff15c8a89e00         call dword ptr [0x9ea8c8]
// 008046d2  8903                 mov dword ptr [ebx], eax
// 008046d4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008046d8  83c404               add esp, 4
// 008046db  8938                 mov dword ptr [eax], edi
// 008046dd  8b13                 mov edx, dword ptr [ebx]
// 008046df  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 008046e2  57                   push edi
// 008046e3  52                   push edx
// 008046e4  e82d3efaff           call 0x7a8516
// 008046e9  33c9                 xor ecx, ecx
// 008046eb  3bc7                 cmp eax, edi
// 008046ed  0f94c1               sete cl
// 008046f0  5b                   pop ebx
// 008046f1  5f                   pop edi
// 008046f2  5e                   pop esi
// 008046f3  8bc1                 mov eax, ecx
// 008046f5  c20c00               ret 0xc
// 008046f8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008046fc  3939                 cmp dword ptr [ecx], edi
// 008046fe  73dd                 jae 0x8046dd
// 00804700  5b                   pop ebx
// 00804701  5f                   pop edi
// 00804702  33c0                 xor eax, eax
// 00804704  5e                   pop esi
// 00804705  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?ExchangeBlobProp@CXTPPropExchangeArchive@@UAEHPBDAAPAEAAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
