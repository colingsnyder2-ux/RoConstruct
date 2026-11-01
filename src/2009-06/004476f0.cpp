// from server: 100% by auto
// roc 2009-06 004476f0  unit: CRobloxModule  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004476f0
//
// 004476f0  53                   push ebx
// 004476f1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004476f5  85db                 test ebx, ebx
// 004476f7  7509                 jne 0x447702
// 004476f9  b803400080           mov eax, 0x80004003
// 004476fe  5b                   pop ebx
// 004476ff  c20400               ret 4
// 00447702  56                   push esi
// 00447703  57                   push edi
// 00447704  33ff                 xor edi, edi
// 00447706  397928               cmp dword ptr [ecx + 0x28], edi
// 00447709  8d7128               lea esi, [ecx + 0x28]
// 0044770c  751a                 jne 0x447728
// 0044770e  56                   push esi
// 0044770f  68fc718b00           push 0x8b71fc
// 00447714  6a01                 push 1
// 00447716  57                   push edi
// 00447717  6890128f00           push 0x8f1290
// 0044771c  ff1500038a00         call dword ptr [0x8a0300]
// 00447722  8bf8                 mov edi, eax
// 00447724  85ff                 test edi, edi
// 00447726  7c0e                 jl 0x447736
// 00447728  8b06                 mov eax, dword ptr [esi]
// 0044772a  8903                 mov dword ptr [ebx], eax
// 0044772c  8b36                 mov esi, dword ptr [esi]
// 0044772e  8b0e                 mov ecx, dword ptr [esi]
// 00447730  8b5104               mov edx, dword ptr [ecx + 4]
// 00447733  56                   push esi
// 00447734  ffd2                 call edx
// 00447736  8bc7                 mov eax, edi
// 00447738  5f                   pop edi
// 00447739  5e                   pop esi
// 0044773a  5b                   pop ebx
// 0044773b  c20400               ret 4
// library atl-8.0/atl.cpp (function ?GetGITPtr@CAtlModule@ATL@@UAEJPAPAUIGlobalInterfaceTable@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
