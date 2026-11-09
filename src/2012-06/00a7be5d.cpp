// roc 2012-06 00a7be5d  unit: CXTIconHandle  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7be5d
//
// 00a7be5d  8bff                 mov edi, edi
// 00a7be5f  55                   push ebp
// 00a7be60  8bec                 mov ebp, esp
// 00a7be62  56                   push esi
// 00a7be63  8b7508               mov esi, dword ptr [ebp + 8]
// 00a7be66  57                   push edi
// 00a7be67  ff750c               push dword ptr [ebp + 0xc]
// 00a7be6a  83c608               add esi, 8
// 00a7be6d  83e6f8               and esi, 0xfffffff8
// 00a7be70  8d4508               lea eax, [ebp + 8]
// 00a7be73  56                   push esi
// 00a7be74  50                   push eax
// 00a7be75  8bf9                 mov edi, ecx
// 00a7be77  e8648298ff           call 0x4040e0
// 00a7be7c  83c40c               add esp, 0xc
// 00a7be7f  85c0                 test eax, eax
// 00a7be81  7c36                 jl 0xa7beb9
// 00a7be83  ff7508               push dword ptr [ebp + 8]
// 00a7be86  8d4508               lea eax, [ebp + 8]
// 00a7be89  6a10                 push 0x10
// 00a7be8b  50                   push eax
// 00a7be8c  e8a6ffffff           call 0xa7be37
// 00a7be91  83c40c               add esp, 0xc
// 00a7be94  85c0                 test eax, eax
// 00a7be96  7c21                 jl 0xa7beb9
// 00a7be98  8b4f04               mov ecx, dword ptr [edi + 4]
// 00a7be9b  ff7508               push dword ptr [ebp + 8]
// 00a7be9e  8b01                 mov eax, dword ptr [ecx]
// 00a7bea0  ff10                 call dword ptr [eax]
// 00a7bea2  85c0                 test eax, eax
// 00a7bea4  7413                 je 0xa7beb9
// 00a7bea6  4e                   dec esi
// 00a7bea7  83600400             and dword ptr [eax + 4], 0
// 00a7beab  8938                 mov dword ptr [eax], edi
// 00a7bead  c7400c01000000       mov dword ptr [eax + 0xc], 1
// 00a7beb4  897008               mov dword ptr [eax + 8], esi
// 00a7beb7  eb02                 jmp 0xa7bebb
// 00a7beb9  33c0                 xor eax, eax
// 00a7bebb  5f                   pop edi
// 00a7bebc  5e                   pop esi
// 00a7bebd  5d                   pop ebp
// 00a7bebe  c20800               ret 8
// copied from an identical function in another client (function ?Allocate@CAtlStringMgr@ATL@@UAEPAUCStringData@2@HH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlstr.obj