// from server: 100% by auto
// roc 2010-06 0044f4d0  unit: CRobloxModule  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044f4d0
//
// 0044f4d0  53                   push ebx
// 0044f4d1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0044f4d5  85db                 test ebx, ebx
// 0044f4d7  7509                 jne 0x44f4e2
// 0044f4d9  b803400080           mov eax, 0x80004003
// 0044f4de  5b                   pop ebx
// 0044f4df  c20400               ret 4
// 0044f4e2  56                   push esi
// 0044f4e3  57                   push edi
// 0044f4e4  33ff                 xor edi, edi
// 0044f4e6  397928               cmp dword ptr [ecx + 0x28], edi
// 0044f4e9  8d7128               lea esi, [ecx + 0x28]
// 0044f4ec  751a                 jne 0x44f508
// 0044f4ee  56                   push esi
// 0044f4ef  6834c2a000           push 0xa0c234
// 0044f4f4  6a01                 push 1
// 0044f4f6  57                   push edi
// 0044f4f7  68585aa500           push 0xa55a58
// 0044f4fc  ff15dcd09e00         call dword ptr [0x9ed0dc]
// 0044f502  8bf8                 mov edi, eax
// 0044f504  85ff                 test edi, edi
// 0044f506  7c0e                 jl 0x44f516
// 0044f508  8b06                 mov eax, dword ptr [esi]
// 0044f50a  8903                 mov dword ptr [ebx], eax
// 0044f50c  8b36                 mov esi, dword ptr [esi]
// 0044f50e  8b0e                 mov ecx, dword ptr [esi]
// 0044f510  8b5104               mov edx, dword ptr [ecx + 4]
// 0044f513  56                   push esi
// 0044f514  ffd2                 call edx
// 0044f516  8bc7                 mov eax, edi
// 0044f518  5f                   pop edi
// 0044f519  5e                   pop esi
// 0044f51a  5b                   pop ebx
// 0044f51b  c20400               ret 4
// library atl-8.0/atl.cpp (function ?GetGITPtr@CAtlModule@ATL@@UAEJPAPAUIGlobalInterfaceTable@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
