// from server: 100% by auto
// roc 2009-06 00404bc0  unit: ATL::CComClassFactory  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00404bc0
//
// 00404bc0  56                   push esi
// 00404bc1  8bf1                 mov esi, ecx
// 00404bc3  8d4608               lea eax, [esi + 8]
// 00404bc6  c706acce8a00         mov dword ptr [esi], 0x8aceac
// 00404bcc  80781800             cmp byte ptr [eax + 0x18], 0
// 00404bd0  740b                 je 0x404bdd
// 00404bd2  50                   push eax
// 00404bd3  c6401800             mov byte ptr [eax + 0x18], 0
// 00404bd7  ff1544e38900         call dword ptr [0x89e344]
// 00404bdd  f644240801           test byte ptr [esp + 8], 1
// 00404be2  7409                 je 0x404bed
// 00404be4  56                   push esi
// 00404be5  e8483e3100           call 0x718a32
// 00404bea  83c404               add esp, 4
// 00404bed  8bc6                 mov eax, esi
// 00404bef  5e                   pop esi
// 00404bf0  c20400               ret 4
// library atl-9.0/atl.cpp (function ??_GCComClassFactory@ATL@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
