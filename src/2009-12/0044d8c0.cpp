// from server: 100% by auto
// roc 2009-12 0044d8c0  unit: CRobloxModule  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044d8c0
//
// 0044d8c0  53                   push ebx
// 0044d8c1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0044d8c5  85db                 test ebx, ebx
// 0044d8c7  7509                 jne 0x44d8d2
// 0044d8c9  b803400080           mov eax, 0x80004003
// 0044d8ce  5b                   pop ebx
// 0044d8cf  c20400               ret 4
// 0044d8d2  56                   push esi
// 0044d8d3  57                   push edi
// 0044d8d4  33ff                 xor edi, edi
// 0044d8d6  397928               cmp dword ptr [ecx + 0x28], edi
// 0044d8d9  8d7128               lea esi, [ecx + 0x28]
// 0044d8dc  751a                 jne 0x44d8f8
// 0044d8de  56                   push esi
// 0044d8df  686cb49a00           push 0x9ab46c
// 0044d8e4  6a01                 push 1
// 0044d8e6  57                   push edi
// 0044d8e7  6850179f00           push 0x9f1750
// 0044d8ec  ff15a4e09800         call dword ptr [0x98e0a4]
// 0044d8f2  8bf8                 mov edi, eax
// 0044d8f4  85ff                 test edi, edi
// 0044d8f6  7c0e                 jl 0x44d906
// 0044d8f8  8b06                 mov eax, dword ptr [esi]
// 0044d8fa  8903                 mov dword ptr [ebx], eax
// 0044d8fc  8b36                 mov esi, dword ptr [esi]
// 0044d8fe  8b0e                 mov ecx, dword ptr [esi]
// 0044d900  8b5104               mov edx, dword ptr [ecx + 4]
// 0044d903  56                   push esi
// 0044d904  ffd2                 call edx
// 0044d906  8bc7                 mov eax, edi
// 0044d908  5f                   pop edi
// 0044d909  5e                   pop esi
// 0044d90a  5b                   pop ebx
// 0044d90b  c20400               ret 4
// library atl-8.0/atl.cpp (function ?GetGITPtr@CAtlModule@ATL@@UAEJPAPAUIGlobalInterfaceTable@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
