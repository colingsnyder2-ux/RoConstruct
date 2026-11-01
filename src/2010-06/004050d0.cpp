// from server: 100% by auto
// roc 2010-06 004050d0  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004050d0
//
// 004050d0  56                   push esi
// 004050d1  8bf1                 mov esi, ecx
// 004050d3  8d4608               lea eax, [esi + 8]
// 004050d6  c74604010000c0       mov dword ptr [esi + 4], 0xc0000001
// 004050dd  c7061c05a000         mov dword ptr [esi], 0xa0051c
// 004050e3  80781800             cmp byte ptr [eax + 0x18], 0
// 004050e7  740b                 je 0x4050f4
// 004050e9  50                   push eax
// 004050ea  c6401800             mov byte ptr [eax + 0x18], 0
// 004050ee  ff15bca39e00         call dword ptr [0x9ea3bc]
// 004050f4  f644240801           test byte ptr [esp + 8], 1
// 004050f9  7409                 je 0x405104
// 004050fb  56                   push esi
// 004050fc  e899283a00           call 0x7a799a
// 00405101  83c404               add esp, 4
// 00405104  8bc6                 mov eax, esi
// 00405106  5e                   pop esi
// 00405107  c20400               ret 4
// library atl-8.0/atl.cpp (function ??_G?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@QAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
