// from server: 100% by Xemicl
// roc 2012-06 00a7bd53  unit: CXTIconHandle  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bd53
//
// 00a7bd53  8bff                 mov edi, edi
// 00a7bd55  55                   push ebp
// 00a7bd56  8bec                 mov ebp, esp
// 00a7bd58  33c0                 xor eax, eax
// 00a7bd5a  394508               cmp dword ptr [ebp + 8], eax
// 00a7bd5d  7509                 jne 0xa7bd68
// 00a7bd5f  ff750c               push dword ptr [ebp + 0xc]
// 00a7bd62  8b01                 mov eax, dword ptr [ecx]
// 00a7bd64  ff10                 call dword ptr [eax]
// 00a7bd66  eb21                 jmp 0xa7bd89
// 00a7bd68  39450c               cmp dword ptr [ebp + 0xc], eax
// 00a7bd6b  750c                 jne 0xa7bd79
// 00a7bd6d  ff7508               push dword ptr [ebp + 8]
// 00a7bd70  8b01                 mov eax, dword ptr [ecx]
// 00a7bd72  ff5004               call dword ptr [eax + 4]
// 00a7bd75  33c0                 xor eax, eax
// 00a7bd77  eb10                 jmp 0xa7bd89
// 00a7bd79  ff750c               push dword ptr [ebp + 0xc]
// 00a7bd7c  ff7508               push dword ptr [ebp + 8]
// 00a7bd7f  50                   push eax
// 00a7bd80  ff7104               push dword ptr [ecx + 4]
// 00a7bd83  ff158423b200         call dword ptr [0xb22384]
// 00a7bd89  5d                   pop ebp
// 00a7bd8a  c20800               ret 8
// copied from an identical function in another client (function ?Reallocate@CWin32Heap@ATL@@UAEPAXPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlstr.obj