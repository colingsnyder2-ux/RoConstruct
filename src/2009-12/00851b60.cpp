// from server: 100% by auto
// roc 2009-12 00851b60  unit: CXTPPropExchangeArchive  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00851b60
//
// 00851b60  8b442408             mov eax, dword ptr [esp + 8]
// 00851b64  53                   push ebx
// 00851b65  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00851b69  56                   push esi
// 00851b6a  50                   push eax
// 00851b6b  53                   push ebx
// 00851b6c  8bf1                 mov esi, ecx
// 00851b6e  e8cdfbffff           call 0x851740
// 00851b73  85c0                 test eax, eax
// 00851b75  7505                 jne 0x851b7c
// 00851b77  5e                   pop esi
// 00851b78  5b                   pop ebx
// 00851b79  c20800               ret 8
// 00851b7c  837e2800             cmp dword ptr [esi + 0x28], 0
// 00851b80  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00851b83  7429                 je 0x851bae
// 00851b85  e8f44e0d00           call 0x926a7e
// 00851b8a  8b4644               mov eax, dword ptr [esi + 0x44]
// 00851b8d  8b4834               mov ecx, dword ptr [eax + 0x34]
// 00851b90  ff4034               inc dword ptr [eax + 0x34]
// 00851b93  8b13                 mov edx, dword ptr [ebx]
// 00851b95  8b4644               mov eax, dword ptr [esi + 0x44]
// 00851b98  6a01                 push 1
// 00851b9a  52                   push edx
// 00851b9b  51                   push ecx
// 00851b9c  8b4838               mov ecx, dword ptr [eax + 0x38]
// 00851b9f  e8d44e0d00           call 0x926a78
// 00851ba4  5e                   pop esi
// 00851ba5  b801000000           mov eax, 1
// 00851baa  5b                   pop ebx
// 00851bab  c20800               ret 8
// 00851bae  57                   push edi
// 00851baf  6a00                 push 0
// 00851bb1  e8bc4e0d00           call 0x926a72
// 00851bb6  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00851bb9  e8c04e0d00           call 0x926a7e
// 00851bbe  8b4644               mov eax, dword ptr [esi + 0x44]
// 00851bc1  8b7834               mov edi, dword ptr [eax + 0x34]
// 00851bc4  ff4034               inc dword ptr [eax + 0x34]
// 00851bc7  8b03                 mov eax, dword ptr [ebx]
// 00851bc9  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00851bcc  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 00851bcf  50                   push eax
// 00851bd0  e8854e0d00           call 0x926a5a
// 00851bd5  8938                 mov dword ptr [eax], edi
// 00851bd7  5f                   pop edi
// 00851bd8  5e                   pop esi
// 00851bd9  b801000000           mov eax, 1
// 00851bde  5b                   pop ebx
// 00851bdf  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?ExchangeObjectInstance@CXTPPropExchangeArchive@@UAEHAAPAVCObject@@PAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
