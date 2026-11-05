// from server: 100% by auto
// roc 2009-12 00404bc0  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00404bc0
//
// 00404bc0  8b442404             mov eax, dword ptr [esp + 4]
// 00404bc4  56                   push esi
// 00404bc5  8bf1                 mov esi, ecx
// 00404bc7  33c9                 xor ecx, ecx
// 00404bc9  7705                 ja 0x404bd0
// 00404bcb  83f8ff               cmp eax, -1
// 00404bce  760a                 jbe 0x404bda
// 00404bd0  6857000780           push 0x80070057
// 00404bd5  e8a6dfffff           call 0x402b80
// 00404bda  3d00010000           cmp eax, 0x100
// 00404bdf  760e                 jbe 0x404bef
// 00404be1  50                   push eax
// 00404be2  8bce                 mov ecx, esi
// 00404be4  e857eeffff           call 0x403a40
// 00404be9  8b06                 mov eax, dword ptr [esi]
// 00404beb  5e                   pop esi
// 00404bec  c20400               ret 4
// 00404bef  8d4604               lea eax, [esi + 4]
// 00404bf2  8906                 mov dword ptr [esi], eax
// 00404bf4  5e                   pop esi
// 00404bf5  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0BAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
