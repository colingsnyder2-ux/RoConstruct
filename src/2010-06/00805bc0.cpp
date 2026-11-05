// from server: 100% by auto
// roc 2010-06 00805bc0  unit: CXTPPropExchangeArchive  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00805bc0
//
// 00805bc0  8b442408             mov eax, dword ptr [esp + 8]
// 00805bc4  53                   push ebx
// 00805bc5  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00805bc9  56                   push esi
// 00805bca  50                   push eax
// 00805bcb  53                   push ebx
// 00805bcc  8bf1                 mov esi, ecx
// 00805bce  e8edfbffff           call 0x8057c0
// 00805bd3  85c0                 test eax, eax
// 00805bd5  7505                 jne 0x805bdc
// 00805bd7  5e                   pop esi
// 00805bd8  5b                   pop ebx
// 00805bd9  c20800               ret 8
// 00805bdc  837e2800             cmp dword ptr [esi + 0x28], 0
// 00805be0  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00805be3  7429                 je 0x805c0e
// 00805be5  e8d6771700           call 0x97d3c0
// 00805bea  8b4644               mov eax, dword ptr [esi + 0x44]
// 00805bed  8b4834               mov ecx, dword ptr [eax + 0x34]
// 00805bf0  ff4034               inc dword ptr [eax + 0x34]
// 00805bf3  8b13                 mov edx, dword ptr [ebx]
// 00805bf5  8b4644               mov eax, dword ptr [esi + 0x44]
// 00805bf8  6a01                 push 1
// 00805bfa  52                   push edx
// 00805bfb  51                   push ecx
// 00805bfc  8b4838               mov ecx, dword ptr [eax + 0x38]
// 00805bff  e8b6771700           call 0x97d3ba
// 00805c04  5e                   pop esi
// 00805c05  b801000000           mov eax, 1
// 00805c0a  5b                   pop ebx
// 00805c0b  c20800               ret 8
// 00805c0e  57                   push edi
// 00805c0f  6a00                 push 0
// 00805c11  e89e771700           call 0x97d3b4
// 00805c16  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00805c19  e8a2771700           call 0x97d3c0
// 00805c1e  8b4644               mov eax, dword ptr [esi + 0x44]
// 00805c21  8b7834               mov edi, dword ptr [eax + 0x34]
// 00805c24  ff4034               inc dword ptr [eax + 0x34]
// 00805c27  8b03                 mov eax, dword ptr [ebx]
// 00805c29  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00805c2c  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 00805c2f  50                   push eax
// 00805c30  e867771700           call 0x97d39c
// 00805c35  8938                 mov dword ptr [eax], edi
// 00805c37  5f                   pop edi
// 00805c38  5e                   pop esi
// 00805c39  b801000000           mov eax, 1
// 00805c3e  5b                   pop ebx
// 00805c3f  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPPropExchange.cpp (function ?ExchangeObjectInstance@CXTPPropExchangeArchive@@UAEHAAPAVCObject@@PAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPPropExchange.cpp
