// from server: 100% by tester
// roc 2007-03 00404490  unit: seg_00400000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00404490
//
// 00404490  8b442404             mov eax, dword ptr [esp + 4]
// 00404494  56                   push esi
// 00404495  8bf1                 mov esi, ecx
// 00404497  33c9                 xor ecx, ecx
// 00404499  7705                 ja 0x4044a0
// 0040449b  83f8ff               cmp eax, -1
// 0040449e  760a                 jbe 0x4044aa
// 004044a0  6857000780           push 0x80070057
// 004044a5  e856cbffff           call 0x401000
// 004044aa  3d00040000           cmp eax, 0x400
// 004044af  760e                 jbe 0x4044bf
// 004044b1  50                   push eax
// 004044b2  8bce                 mov ecx, esi
// 004044b4  e8e7c50500           call 0x460aa0
// 004044b9  8b06                 mov eax, dword ptr [esi]
// 004044bb  5e                   pop esi
// 004044bc  c20400               ret 4
// 004044bf  8d4604               lea eax, [esi + 4]
// 004044c2  8906                 mov dword ptr [esi], eax
// 004044c4  5e                   pop esi
// 004044c5  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0EAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
