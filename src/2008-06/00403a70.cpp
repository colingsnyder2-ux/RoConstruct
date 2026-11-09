// from server: 100% by auto
// roc 2008-06 00403a70  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403a70
//
// 00403a70  8b442404             mov eax, dword ptr [esp + 4]
// 00403a74  56                   push esi
// 00403a75  8bf1                 mov esi, ecx
// 00403a77  33c9                 xor ecx, ecx
// 00403a79  7705                 ja 0x403a80
// 00403a7b  83f8ff               cmp eax, -1
// 00403a7e  760a                 jbe 0x403a8a
// 00403a80  6857000780           push 0x80070057
// 00403a85  e876d5ffff           call 0x401000
// 00403a8a  3d00040000           cmp eax, 0x400
// 00403a8f  760e                 jbe 0x403a9f
// 00403a91  50                   push eax
// 00403a92  8bce                 mov ecx, esi
// 00403a94  e8779e2f00           call 0x6fd910
// 00403a99  8b06                 mov eax, dword ptr [esi]
// 00403a9b  5e                   pop esi
// 00403a9c  c20400               ret 4
// 00403a9f  8d4604               lea eax, [esi + 4]
// 00403aa2  8906                 mov dword ptr [esi], eax
// 00403aa4  5e                   pop esi
// 00403aa5  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0EAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
