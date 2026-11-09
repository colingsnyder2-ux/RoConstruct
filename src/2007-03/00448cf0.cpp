// from server: 100% by auto
// roc 2007-03 00448cf0  unit: seg_00440000  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00448cf0
//
// 00448cf0  53                   push ebx
// 00448cf1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00448cf5  85db                 test ebx, ebx
// 00448cf7  7509                 jne 0x448d02
// 00448cf9  b803400080           mov eax, 0x80004003
// 00448cfe  5b                   pop ebx
// 00448cff  c20400               ret 4
// 00448d02  56                   push esi
// 00448d03  57                   push edi
// 00448d04  33ff                 xor edi, edi
// 00448d06  397928               cmp dword ptr [ecx + 0x28], edi
// 00448d09  8d7128               lea esi, [ecx + 0x28]
// 00448d0c  751a                 jne 0x448d28
// 00448d0e  56                   push esi
// 00448d0f  68c0f67800           push 0x78f6c0
// 00448d14  6a01                 push 1
// 00448d16  57                   push edi
// 00448d17  6810257c00           push 0x7c2510
// 00448d1c  ff1538f17700         call dword ptr [0x77f138]
// 00448d22  8bf8                 mov edi, eax
// 00448d24  85ff                 test edi, edi
// 00448d26  7c0e                 jl 0x448d36
// 00448d28  8b06                 mov eax, dword ptr [esi]
// 00448d2a  8903                 mov dword ptr [ebx], eax
// 00448d2c  8b36                 mov esi, dword ptr [esi]
// 00448d2e  8b0e                 mov ecx, dword ptr [esi]
// 00448d30  8b5104               mov edx, dword ptr [ecx + 4]
// 00448d33  56                   push esi
// 00448d34  ffd2                 call edx
// 00448d36  8bc7                 mov eax, edi
// 00448d38  5f                   pop edi
// 00448d39  5e                   pop esi
// 00448d3a  5b                   pop ebx
// 00448d3b  c20400               ret 4
// library atl-8.0/atl.cpp (function ?GetGITPtr@CAtlModule@ATL@@UAEJPAPAUIGlobalInterfaceTable@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
