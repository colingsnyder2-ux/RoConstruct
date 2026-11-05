// from server: 100% by auto
// roc 2009-06 00404f10  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00404f10
//
// 00404f10  8b442404             mov eax, dword ptr [esp + 4]
// 00404f14  56                   push esi
// 00404f15  8bf1                 mov esi, ecx
// 00404f17  33c9                 xor ecx, ecx
// 00404f19  7705                 ja 0x404f20
// 00404f1b  83f8ff               cmp eax, -1
// 00404f1e  760a                 jbe 0x404f2a
// 00404f20  6857000780           push 0x80070057
// 00404f25  e886dfffff           call 0x402eb0
// 00404f2a  3d00010000           cmp eax, 0x100
// 00404f2f  760e                 jbe 0x404f3f
// 00404f31  50                   push eax
// 00404f32  8bce                 mov ecx, esi
// 00404f34  e8f7ecffff           call 0x403c30
// 00404f39  8b06                 mov eax, dword ptr [esi]
// 00404f3b  5e                   pop esi
// 00404f3c  c20400               ret 4
// 00404f3f  8d4604               lea eax, [esi + 4]
// 00404f42  8906                 mov dword ptr [esi], eax
// 00404f44  5e                   pop esi
// 00404f45  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0BAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
