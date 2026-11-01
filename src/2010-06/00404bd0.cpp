// from server: 100% by auto
// roc 2010-06 00404bd0  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00404bd0
//
// 00404bd0  8b442404             mov eax, dword ptr [esp + 4]
// 00404bd4  56                   push esi
// 00404bd5  8bf1                 mov esi, ecx
// 00404bd7  33c9                 xor ecx, ecx
// 00404bd9  7705                 ja 0x404be0
// 00404bdb  83f8ff               cmp eax, -1
// 00404bde  760a                 jbe 0x404bea
// 00404be0  6857000780           push 0x80070057
// 00404be5  e8e6dfffff           call 0x402bd0
// 00404bea  3d00040000           cmp eax, 0x400
// 00404bef  760e                 jbe 0x404bff
// 00404bf1  50                   push eax
// 00404bf2  8bce                 mov ecx, esi
// 00404bf4  e8a7eeffff           call 0x403aa0
// 00404bf9  8b06                 mov eax, dword ptr [esi]
// 00404bfb  5e                   pop esi
// 00404bfc  c20400               ret 4
// 00404bff  8d4604               lea eax, [esi + 4]
// 00404c02  8906                 mov dword ptr [esi], eax
// 00404c04  5e                   pop esi
// 00404c05  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0EAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
