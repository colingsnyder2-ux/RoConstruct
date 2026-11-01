// from server: 100% by auto
// roc 2011-06 0085fb50  unit: CXTPPropExchangeArchive  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085fb50
//
// 0085fb50  56                   push esi
// 0085fb51  8bf1                 mov esi, ecx
// 0085fb53  8b06                 mov eax, dword ptr [esi]
// 0085fb55  8b9090000000         mov edx, dword ptr [eax + 0x90]
// 0085fb5b  ffd2                 call edx
// 0085fb5d  85c0                 test eax, eax
// 0085fb5f  7504                 jne 0x85fb65
// 0085fb61  5e                   pop esi
// 0085fb62  c20c00               ret 0xc
// 0085fb65  837e2800             cmp dword ptr [esi + 0x28], 0
// 0085fb69  8b06                 mov eax, dword ptr [esi]
// 0085fb6b  57                   push edi
// 0085fb6c  752a                 jne 0x85fb98
// 0085fb6e  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0085fb72  8b0f                 mov ecx, dword ptr [edi]
// 0085fb74  8b5078               mov edx, dword ptr [eax + 0x78]
// 0085fb77  51                   push ecx
// 0085fb78  8bce                 mov ecx, esi
// 0085fb7a  ffd2                 call edx
// 0085fb7c  8b07                 mov eax, dword ptr [edi]
// 0085fb7e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0085fb82  8b11                 mov edx, dword ptr [ecx]
// 0085fb84  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 0085fb87  50                   push eax
// 0085fb88  52                   push edx
// 0085fb89  e852b0faff           call 0x80abe0
// 0085fb8e  5f                   pop edi
// 0085fb8f  b801000000           mov eax, 1
// 0085fb94  5e                   pop esi
// 0085fb95  c20c00               ret 0xc
// 0085fb98  8b507c               mov edx, dword ptr [eax + 0x7c]
// 0085fb9b  53                   push ebx
// 0085fb9c  8bce                 mov ecx, esi
// 0085fb9e  ffd2                 call edx
// 0085fba0  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0085fba4  833b00               cmp dword ptr [ebx], 0
// 0085fba7  8bf8                 mov edi, eax
// 0085fba9  752d                 jne 0x85fbd8
// 0085fbab  57                   push edi
// 0085fbac  ff15400aa400         call dword ptr [0xa40a40]
// 0085fbb2  8903                 mov dword ptr [ebx], eax
// 0085fbb4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0085fbb8  83c404               add esp, 4
// 0085fbbb  8938                 mov dword ptr [eax], edi
// 0085fbbd  8b13                 mov edx, dword ptr [ebx]
// 0085fbbf  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 0085fbc2  57                   push edi
// 0085fbc3  52                   push edx
// 0085fbc4  e811b0faff           call 0x80abda
// 0085fbc9  33c9                 xor ecx, ecx
// 0085fbcb  3bc7                 cmp eax, edi
// 0085fbcd  0f94c1               sete cl
// 0085fbd0  5b                   pop ebx
// 0085fbd1  5f                   pop edi
// 0085fbd2  5e                   pop esi
// 0085fbd3  8bc1                 mov eax, ecx
// 0085fbd5  c20c00               ret 0xc
// 0085fbd8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0085fbdc  3939                 cmp dword ptr [ecx], edi
// 0085fbde  73dd                 jae 0x85fbbd
// 0085fbe0  5b                   pop ebx
// 0085fbe1  5f                   pop edi
// 0085fbe2  33c0                 xor eax, eax
// 0085fbe4  5e                   pop esi
// 0085fbe5  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?ExchangeBlobProp@CXTPPropExchangeArchive@@UAEHPBDAAPAEAAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
