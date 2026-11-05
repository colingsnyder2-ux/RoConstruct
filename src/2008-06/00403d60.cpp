// from server: 100% by auto
// roc 2008-06 00403d60  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403d60
//
// 00403d60  56                   push esi
// 00403d61  8bf1                 mov esi, ecx
// 00403d63  8d4608               lea eax, [esi + 8]
// 00403d66  c74604010000c0       mov dword ptr [esi + 4], 0xc0000001
// 00403d6d  c70668b18000         mov dword ptr [esi], 0x80b168
// 00403d73  80781800             cmp byte ptr [eax + 0x18], 0
// 00403d77  740b                 je 0x403d84
// 00403d79  50                   push eax
// 00403d7a  c6401800             mov byte ptr [eax + 0x18], 0
// 00403d7e  ff15dc228000         call dword ptr [0x8022dc]
// 00403d84  f644240801           test byte ptr [esp + 8], 1
// 00403d89  7409                 je 0x403d94
// 00403d8b  56                   push esi
// 00403d8c  e8e9c82900           call 0x6a067a
// 00403d91  83c404               add esp, 4
// 00403d94  8bc6                 mov eax, esi
// 00403d96  5e                   pop esi
// 00403d97  c20400               ret 4
// library atl-8.0/atl.cpp (function ??_G?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@QAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
