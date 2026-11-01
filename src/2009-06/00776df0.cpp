// from server: 100% by auto
// roc 2009-06 00776df0  unit: CXTPPropExchangeArchive  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00776df0
//
// 00776df0  8b442408             mov eax, dword ptr [esp + 8]
// 00776df4  53                   push ebx
// 00776df5  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00776df9  56                   push esi
// 00776dfa  50                   push eax
// 00776dfb  53                   push ebx
// 00776dfc  8bf1                 mov esi, ecx
// 00776dfe  e8edfbffff           call 0x7769f0
// 00776e03  85c0                 test eax, eax
// 00776e05  7505                 jne 0x776e0c
// 00776e07  5e                   pop esi
// 00776e08  5b                   pop ebx
// 00776e09  c20800               ret 8
// 00776e0c  837e2800             cmp dword ptr [esi + 0x28], 0
// 00776e10  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00776e13  7429                 je 0x776e3e
// 00776e15  e8f8560d00           call 0x84c512
// 00776e1a  8b4644               mov eax, dword ptr [esi + 0x44]
// 00776e1d  8b4834               mov ecx, dword ptr [eax + 0x34]
// 00776e20  ff4034               inc dword ptr [eax + 0x34]
// 00776e23  8b13                 mov edx, dword ptr [ebx]
// 00776e25  8b4644               mov eax, dword ptr [esi + 0x44]
// 00776e28  6a01                 push 1
// 00776e2a  52                   push edx
// 00776e2b  51                   push ecx
// 00776e2c  8b4838               mov ecx, dword ptr [eax + 0x38]
// 00776e2f  e8d8560d00           call 0x84c50c
// 00776e34  5e                   pop esi
// 00776e35  b801000000           mov eax, 1
// 00776e3a  5b                   pop ebx
// 00776e3b  c20800               ret 8
// 00776e3e  57                   push edi
// 00776e3f  6a00                 push 0
// 00776e41  e8c0560d00           call 0x84c506
// 00776e46  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00776e49  e8c4560d00           call 0x84c512
// 00776e4e  8b4644               mov eax, dword ptr [esi + 0x44]
// 00776e51  8b7834               mov edi, dword ptr [eax + 0x34]
// 00776e54  ff4034               inc dword ptr [eax + 0x34]
// 00776e57  8b03                 mov eax, dword ptr [ebx]
// 00776e59  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00776e5c  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 00776e5f  50                   push eax
// 00776e60  e889560d00           call 0x84c4ee
// 00776e65  8938                 mov dword ptr [eax], edi
// 00776e67  5f                   pop edi
// 00776e68  5e                   pop esi
// 00776e69  b801000000           mov eax, 1
// 00776e6e  5b                   pop ebx
// 00776e6f  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPPropExchange.cpp (function ?ExchangeObjectInstance@CXTPPropExchangeArchive@@UAEHAAPAVCObject@@PAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPPropExchange.cpp
