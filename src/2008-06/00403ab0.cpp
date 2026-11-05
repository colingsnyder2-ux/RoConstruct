// from server: 100% by auto
// roc 2008-06 00403ab0  unit: ATL::CComClassFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403ab0
//
// 00403ab0  8b442404             mov eax, dword ptr [esp + 4]
// 00403ab4  56                   push esi
// 00403ab5  8bf1                 mov esi, ecx
// 00403ab7  33c9                 xor ecx, ecx
// 00403ab9  7705                 ja 0x403ac0
// 00403abb  83f8ff               cmp eax, -1
// 00403abe  760a                 jbe 0x403aca
// 00403ac0  6857000780           push 0x80070057
// 00403ac5  e836d5ffff           call 0x401000
// 00403aca  3d00010000           cmp eax, 0x100
// 00403acf  760e                 jbe 0x403adf
// 00403ad1  50                   push eax
// 00403ad2  8bce                 mov ecx, esi
// 00403ad4  e8379e2f00           call 0x6fd910
// 00403ad9  8b06                 mov eax, dword ptr [esi]
// 00403adb  5e                   pop esi
// 00403adc  c20400               ret 4
// 00403adf  8d4604               lea eax, [esi + 4]
// 00403ae2  8906                 mov dword ptr [esi], eax
// 00403ae4  5e                   pop esi
// 00403ae5  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Allocate@?$CTempBuffer@D$0BAA@VCCRTAllocator@ATL@@@ATL@@QAEPADI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
