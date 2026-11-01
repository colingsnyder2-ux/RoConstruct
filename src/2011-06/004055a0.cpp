// from server: 100% by auto
// roc 2011-06 004055a0  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004055a0
//
// 004055a0  8b442404             mov eax, dword ptr [esp + 4]
// 004055a4  56                   push esi
// 004055a5  8bf1                 mov esi, ecx
// 004055a7  33c9                 xor ecx, ecx
// 004055a9  7705                 ja 0x4055b0
// 004055ab  83f8ff               cmp eax, -1
// 004055ae  760a                 jbe 0x4055ba
// 004055b0  6857000780           push 0x80070057
// 004055b5  e8e6dfffff           call 0x4035a0
// 004055ba  3d00010000           cmp eax, 0x100
// 004055bf  760e                 jbe 0x4055cf
// 004055c1  50                   push eax
// 004055c2  8bce                 mov ecx, esi
// 004055c4  e877edffff           call 0x404340
// 004055c9  8b06                 mov eax, dword ptr [esi]
// 004055cb  5e                   pop esi
// 004055cc  c20400               ret 4
// 004055cf  8d4604               lea eax, [esi + 4]
// 004055d2  8906                 mov dword ptr [esi], eax
// 004055d4  5e                   pop esi
// 004055d5  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0BAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
