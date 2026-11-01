// from server: 100% by auto
// roc 2012-06 00405cb0  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00405cb0
//
// 00405cb0  8b442404             mov eax, dword ptr [esp + 4]
// 00405cb4  56                   push esi
// 00405cb5  8bf1                 mov esi, ecx
// 00405cb7  33c9                 xor ecx, ecx
// 00405cb9  7705                 ja 0x405cc0
// 00405cbb  83f8ff               cmp eax, -1
// 00405cbe  760a                 jbe 0x405cca
// 00405cc0  6857000780           push 0x80070057
// 00405cc5  e8e6e4ffff           call 0x4041b0
// 00405cca  3d00040000           cmp eax, 0x400
// 00405ccf  760e                 jbe 0x405cdf
// 00405cd1  50                   push eax
// 00405cd2  8bce                 mov ecx, esi
// 00405cd4  e807eeffff           call 0x404ae0
// 00405cd9  8b06                 mov eax, dword ptr [esi]
// 00405cdb  5e                   pop esi
// 00405cdc  c20400               ret 4
// 00405cdf  8d4604               lea eax, [esi + 4]
// 00405ce2  8906                 mov dword ptr [esi], eax
// 00405ce4  5e                   pop esi
// 00405ce5  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0EAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
