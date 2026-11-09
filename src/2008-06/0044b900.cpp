// from server: 100% by auto
// roc 2008-06 0044b900  unit: CRobloxModule  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044b900
//
// 0044b900  53                   push ebx
// 0044b901  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0044b905  85db                 test ebx, ebx
// 0044b907  7509                 jne 0x44b912
// 0044b909  b803400080           mov eax, 0x80004003
// 0044b90e  5b                   pop ebx
// 0044b90f  c20400               ret 4
// 0044b912  56                   push esi
// 0044b913  57                   push edi
// 0044b914  33ff                 xor edi, edi
// 0044b916  397928               cmp dword ptr [ecx + 0x28], edi
// 0044b919  8d7128               lea esi, [ecx + 0x28]
// 0044b91c  751a                 jne 0x44b938
// 0044b91e  56                   push esi
// 0044b91f  68d8698100           push 0x8169d8
// 0044b924  6a01                 push 1
// 0044b926  57                   push edi
// 0044b927  68fc018500           push 0x8501fc
// 0044b92c  ff1518418000         call dword ptr [0x804118]
// 0044b932  8bf8                 mov edi, eax
// 0044b934  85ff                 test edi, edi
// 0044b936  7c0e                 jl 0x44b946
// 0044b938  8b06                 mov eax, dword ptr [esi]
// 0044b93a  8903                 mov dword ptr [ebx], eax
// 0044b93c  8b36                 mov esi, dword ptr [esi]
// 0044b93e  8b0e                 mov ecx, dword ptr [esi]
// 0044b940  8b5104               mov edx, dword ptr [ecx + 4]
// 0044b943  56                   push esi
// 0044b944  ffd2                 call edx
// 0044b946  8bc7                 mov eax, edi
// 0044b948  5f                   pop edi
// 0044b949  5e                   pop esi
// 0044b94a  5b                   pop ebx
// 0044b94b  c20400               ret 4
// library atl-8.0/atl.cpp (function ?GetGITPtr@CAtlModule@ATL@@UAEJPAPAUIGlobalInterfaceTable@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
