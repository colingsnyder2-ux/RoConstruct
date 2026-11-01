// from server: 100% by auto
// roc 2007-03 004044d0  unit: seg_00400000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004044d0
//
// 004044d0  8b442404             mov eax, dword ptr [esp + 4]
// 004044d4  56                   push esi
// 004044d5  8bf1                 mov esi, ecx
// 004044d7  33c9                 xor ecx, ecx
// 004044d9  7705                 ja 0x4044e0
// 004044db  83f8ff               cmp eax, -1
// 004044de  760a                 jbe 0x4044ea
// 004044e0  6857000780           push 0x80070057
// 004044e5  e816cbffff           call 0x401000
// 004044ea  3d00010000           cmp eax, 0x100
// 004044ef  760e                 jbe 0x4044ff
// 004044f1  50                   push eax
// 004044f2  8bce                 mov ecx, esi
// 004044f4  e8a7c50500           call 0x460aa0
// 004044f9  8b06                 mov eax, dword ptr [esi]
// 004044fb  5e                   pop esi
// 004044fc  c20400               ret 4
// 004044ff  8d4604               lea eax, [esi + 4]
// 00404502  8906                 mov dword ptr [esi], eax
// 00404504  5e                   pop esi
// 00404505  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0BAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
