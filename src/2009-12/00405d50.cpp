// from server: 100% by auto
// roc 2009-12 00405d50  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00405d50
//
// 00405d50  56                   push esi
// 00405d51  8bf1                 mov esi, ecx
// 00405d53  8d4608               lea eax, [esi + 8]
// 00405d56  c74604010000c0       mov dword ptr [esi + 4], 0xc0000001
// 00405d5d  c706ecf99900         mov dword ptr [esi], 0x99f9ec
// 00405d63  80781800             cmp byte ptr [eax + 0x18], 0
// 00405d67  740b                 je 0x405d74
// 00405d69  50                   push eax
// 00405d6a  c6401800             mov byte ptr [eax + 0x18], 0
// 00405d6e  ff15d0b29800         call dword ptr [0x98b2d0]
// 00405d74  f644240801           test byte ptr [esp + 8], 1
// 00405d79  7409                 je 0x405d84
// 00405d7b  56                   push esi
// 00405d7c  e8d9da3e00           call 0x7f385a
// 00405d81  83c404               add esp, 4
// 00405d84  8bc6                 mov eax, esi
// 00405d86  5e                   pop esi
// 00405d87  c20400               ret 4
// library atl-8.0/atl.cpp (function ??_G?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@QAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
