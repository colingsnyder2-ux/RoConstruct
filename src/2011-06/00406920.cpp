// from server: 100% by auto
// roc 2011-06 00406920  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00406920
//
// 00406920  56                   push esi
// 00406921  8bf1                 mov esi, ecx
// 00406923  8d4608               lea eax, [esi + 8]
// 00406926  c74604010000c0       mov dword ptr [esi + 4], 0xc0000001
// 0040692d  c70664bba500         mov dword ptr [esi], 0xa5bb64
// 00406933  80781800             cmp byte ptr [eax + 0x18], 0
// 00406937  740b                 je 0x406944
// 00406939  50                   push eax
// 0040693a  c6401800             mov byte ptr [eax + 0x18], 0
// 0040693e  ff159c03a400         call dword ptr [0xa4039c]
// 00406944  f644240801           test byte ptr [esp + 8], 1
// 00406949  7409                 je 0x406954
// 0040694b  56                   push esi
// 0040694c  e807374000           call 0x80a058
// 00406951  83c404               add esp, 4
// 00406954  8bc6                 mov eax, esi
// 00406956  5e                   pop esi
// 00406957  c20400               ret 4
// library atl-8.0/atl.cpp (function ??_G?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@QAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
