// from server: 100% by auto
// roc 2012-06 00405cf0  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00405cf0
//
// 00405cf0  8b442404             mov eax, dword ptr [esp + 4]
// 00405cf4  56                   push esi
// 00405cf5  8bf1                 mov esi, ecx
// 00405cf7  33c9                 xor ecx, ecx
// 00405cf9  7705                 ja 0x405d00
// 00405cfb  83f8ff               cmp eax, -1
// 00405cfe  760a                 jbe 0x405d0a
// 00405d00  6857000780           push 0x80070057
// 00405d05  e8a6e4ffff           call 0x4041b0
// 00405d0a  3d00010000           cmp eax, 0x100
// 00405d0f  760e                 jbe 0x405d1f
// 00405d11  50                   push eax
// 00405d12  8bce                 mov ecx, esi
// 00405d14  e8c7edffff           call 0x404ae0
// 00405d19  8b06                 mov eax, dword ptr [esi]
// 00405d1b  5e                   pop esi
// 00405d1c  c20400               ret 4
// 00405d1f  8d4604               lea eax, [esi + 4]
// 00405d22  8906                 mov dword ptr [esi], eax
// 00405d24  5e                   pop esi
// 00405d25  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0BAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
