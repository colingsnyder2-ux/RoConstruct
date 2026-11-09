// from server: 100% by auto
// roc 2012-06 00405bf0  unit: ATL::CComClassFactory  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00405bf0
//
// 00405bf0  56                   push esi
// 00405bf1  8bf1                 mov esi, ecx
// 00405bf3  8d4608               lea eax, [esi + 8]
// 00405bf6  c7063039b400         mov dword ptr [esi], 0xb43930
// 00405bfc  80781800             cmp byte ptr [eax + 0x18], 0
// 00405c00  740b                 je 0x405c0d
// 00405c02  50                   push eax
// 00405c03  c6401800             mov byte ptr [eax + 0x18], 0
// 00405c07  ff15d821b200         call dword ptr [0xb221d8]
// 00405c0d  f644240801           test byte ptr [esp + 8], 1
// 00405c12  7409                 je 0x405c1d
// 00405c14  56                   push esi
// 00405c15  e8fac45700           call 0x982114
// 00405c1a  83c404               add esp, 4
// 00405c1d  8bc6                 mov eax, esi
// 00405c1f  5e                   pop esi
// 00405c20  c20400               ret 4
// library atl-9.0/atl.cpp (function ??_GCComClassFactory@ATL@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
