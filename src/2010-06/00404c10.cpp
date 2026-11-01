// from server: 100% by auto
// roc 2010-06 00404c10  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00404c10
//
// 00404c10  8b442404             mov eax, dword ptr [esp + 4]
// 00404c14  56                   push esi
// 00404c15  8bf1                 mov esi, ecx
// 00404c17  33c9                 xor ecx, ecx
// 00404c19  7705                 ja 0x404c20
// 00404c1b  83f8ff               cmp eax, -1
// 00404c1e  760a                 jbe 0x404c2a
// 00404c20  6857000780           push 0x80070057
// 00404c25  e8a6dfffff           call 0x402bd0
// 00404c2a  3d00010000           cmp eax, 0x100
// 00404c2f  760e                 jbe 0x404c3f
// 00404c31  50                   push eax
// 00404c32  8bce                 mov ecx, esi
// 00404c34  e867eeffff           call 0x403aa0
// 00404c39  8b06                 mov eax, dword ptr [esi]
// 00404c3b  5e                   pop esi
// 00404c3c  c20400               ret 4
// 00404c3f  8d4604               lea eax, [esi + 4]
// 00404c42  8906                 mov dword ptr [esi], eax
// 00404c44  5e                   pop esi
// 00404c45  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0BAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
