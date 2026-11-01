// from server: 100% by auto
// roc 2011-06 00405450  unit: ATL::CComClassFactory  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00405450
//
// 00405450  56                   push esi
// 00405451  8bf1                 mov esi, ecx
// 00405453  8d4608               lea eax, [esi + 8]
// 00405456  c70664bba500         mov dword ptr [esi], 0xa5bb64
// 0040545c  80781800             cmp byte ptr [eax + 0x18], 0
// 00405460  740b                 je 0x40546d
// 00405462  50                   push eax
// 00405463  c6401800             mov byte ptr [eax + 0x18], 0
// 00405467  ff159c03a400         call dword ptr [0xa4039c]
// 0040546d  f644240801           test byte ptr [esp + 8], 1
// 00405472  7409                 je 0x40547d
// 00405474  56                   push esi
// 00405475  e8de4b4000           call 0x80a058
// 0040547a  83c404               add esp, 4
// 0040547d  8bc6                 mov eax, esi
// 0040547f  5e                   pop esi
// 00405480  c20400               ret 4
// library atl-9.0/atl.cpp (function ??_GCComClassFactory@ATL@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
