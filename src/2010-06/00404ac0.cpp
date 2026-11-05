// from server: 100% by auto
// roc 2010-06 00404ac0  unit: ATL::CComClassFactory  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00404ac0
//
// 00404ac0  56                   push esi
// 00404ac1  8bf1                 mov esi, ecx
// 00404ac3  8d4608               lea eax, [esi + 8]
// 00404ac6  c7061c05a000         mov dword ptr [esi], 0xa0051c
// 00404acc  80781800             cmp byte ptr [eax + 0x18], 0
// 00404ad0  740b                 je 0x404add
// 00404ad2  50                   push eax
// 00404ad3  c6401800             mov byte ptr [eax + 0x18], 0
// 00404ad7  ff15bca39e00         call dword ptr [0x9ea3bc]
// 00404add  f644240801           test byte ptr [esp + 8], 1
// 00404ae2  7409                 je 0x404aed
// 00404ae4  56                   push esi
// 00404ae5  e8b02e3a00           call 0x7a799a
// 00404aea  83c404               add esp, 4
// 00404aed  8bc6                 mov eax, esi
// 00404aef  5e                   pop esi
// 00404af0  c20400               ret 4
// library atl-9.0/atl.cpp (function ??_GCComClassFactory@ATL@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
