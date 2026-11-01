// from server: 100% by auto
// roc 2009-06 00404ed0  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00404ed0
//
// 00404ed0  8b442404             mov eax, dword ptr [esp + 4]
// 00404ed4  56                   push esi
// 00404ed5  8bf1                 mov esi, ecx
// 00404ed7  33c9                 xor ecx, ecx
// 00404ed9  7705                 ja 0x404ee0
// 00404edb  83f8ff               cmp eax, -1
// 00404ede  760a                 jbe 0x404eea
// 00404ee0  6857000780           push 0x80070057
// 00404ee5  e8c6dfffff           call 0x402eb0
// 00404eea  3d00040000           cmp eax, 0x400
// 00404eef  760e                 jbe 0x404eff
// 00404ef1  50                   push eax
// 00404ef2  8bce                 mov ecx, esi
// 00404ef4  e837edffff           call 0x403c30
// 00404ef9  8b06                 mov eax, dword ptr [esi]
// 00404efb  5e                   pop esi
// 00404efc  c20400               ret 4
// 00404eff  8d4604               lea eax, [esi + 4]
// 00404f02  8906                 mov dword ptr [esi], eax
// 00404f04  5e                   pop esi
// 00404f05  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0EAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
