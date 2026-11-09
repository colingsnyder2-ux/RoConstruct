// roc 2012-06 00a7ba56  unit: CXTIconHandle  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7ba56
//
// 00a7ba56  8bff                 mov edi, edi
// 00a7ba58  55                   push ebp
// 00a7ba59  8bec                 mov ebp, esp
// 00a7ba5b  a1b8a4e500           mov eax, dword ptr [0xe5a4b8]
// 00a7ba60  ff7508               push dword ptr [ebp + 8]
// 00a7ba63  83f801               cmp eax, 1
// 00a7ba66  7511                 jne 0xa7ba79
// 00a7ba68  6a00                 push 0
// 00a7ba6a  ff15ac22b200         call dword ptr [0xb222ac]
// 00a7ba70  50                   push eax
// 00a7ba71  ff15a822b200         call dword ptr [0xb222a8]
// 00a7ba77  5d                   pop ebp
// 00a7ba78  c3                   ret 
// 00a7ba79  50                   push eax
// 00a7ba7a  ff15bca4e500         call dword ptr [0xe5a4bc]
// 00a7ba80  5d                   pop ebp
// 00a7ba81  c3                   ret 
// copied from an identical function in another client (function ?__FreeStdCallThunk_cmn@@YAXPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlthunk.obj