// from server: 100% by auto
// roc 2009-12 00404b80  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00404b80
//
// 00404b80  8b442404             mov eax, dword ptr [esp + 4]
// 00404b84  56                   push esi
// 00404b85  8bf1                 mov esi, ecx
// 00404b87  33c9                 xor ecx, ecx
// 00404b89  7705                 ja 0x404b90
// 00404b8b  83f8ff               cmp eax, -1
// 00404b8e  760a                 jbe 0x404b9a
// 00404b90  6857000780           push 0x80070057
// 00404b95  e8e6dfffff           call 0x402b80
// 00404b9a  3d00040000           cmp eax, 0x400
// 00404b9f  760e                 jbe 0x404baf
// 00404ba1  50                   push eax
// 00404ba2  8bce                 mov ecx, esi
// 00404ba4  e897eeffff           call 0x403a40
// 00404ba9  8b06                 mov eax, dword ptr [esi]
// 00404bab  5e                   pop esi
// 00404bac  c20400               ret 4
// 00404baf  8d4604               lea eax, [esi + 4]
// 00404bb2  8906                 mov dword ptr [esi], eax
// 00404bb4  5e                   pop esi
// 00404bb5  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0EAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
