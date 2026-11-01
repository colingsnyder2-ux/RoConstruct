// from server: 100% by auto
// roc 2011-06 00861340  unit: CXTPPropExchangeArchive  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00861340
//
// 00861340  53                   push ebx
// 00861341  55                   push ebp
// 00861342  56                   push esi
// 00861343  57                   push edi
// 00861344  e8d38ffaff           call 0x80a31c
// 00861349  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0086134d  8b2d0003a400         mov ebp, dword ptr [0xa40300]
// 00861353  8bf8                 mov edi, eax
// 00861355  8b7720               mov esi, dword ptr [edi + 0x20]
// 00861358  85f6                 test esi, esi
// 0086135a  7415                 je 0x861371
// 0086135c  8d642400             lea esp, [esp]
// 00861360  8b06                 mov eax, dword ptr [esi]
// 00861362  50                   push eax
// 00861363  53                   push ebx
// 00861364  ffd5                 call ebp
// 00861366  85c0                 test eax, eax
// 00861368  7435                 je 0x86139f
// 0086136a  8b7614               mov esi, dword ptr [esi + 0x14]
// 0086136d  85f6                 test esi, esi
// 0086136f  75ef                 jne 0x861360
// 00861371  8b7f4c               mov edi, dword ptr [edi + 0x4c]
// 00861374  85ff                 test edi, edi
// 00861376  7420                 je 0x861398
// 00861378  8b7728               mov esi, dword ptr [edi + 0x28]
// 0086137b  85f6                 test esi, esi
// 0086137d  7412                 je 0x861391
// 0086137f  90                   nop 
// 00861380  8b0e                 mov ecx, dword ptr [esi]
// 00861382  51                   push ecx
// 00861383  53                   push ebx
// 00861384  ffd5                 call ebp
// 00861386  85c0                 test eax, eax
// 00861388  7415                 je 0x86139f
// 0086138a  8b7614               mov esi, dword ptr [esi + 0x14]
// 0086138d  85f6                 test esi, esi
// 0086138f  75ef                 jne 0x861380
// 00861391  8b7f3c               mov edi, dword ptr [edi + 0x3c]
// 00861394  85ff                 test edi, edi
// 00861396  75e0                 jne 0x861378
// 00861398  5f                   pop edi
// 00861399  5e                   pop esi
// 0086139a  5d                   pop ebp
// 0086139b  33c0                 xor eax, eax
// 0086139d  5b                   pop ebx
// 0086139e  c3                   ret 
// 0086139f  5f                   pop edi
// 008613a0  8bc6                 mov eax, esi
// 008613a2  5e                   pop esi
// 008613a3  5d                   pop ebp
// 008613a4  5b                   pop ebx
// 008613a5  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?FindRuntimeClass@CXTPPropExchange@@SAPAUCRuntimeClass@@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
