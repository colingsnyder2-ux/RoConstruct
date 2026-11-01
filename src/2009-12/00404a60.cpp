// from server: 100% by auto
// roc 2009-12 00404a60  unit: ATL::CComClassFactory  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00404a60
//
// 00404a60  56                   push esi
// 00404a61  8bf1                 mov esi, ecx
// 00404a63  8d4608               lea eax, [esi + 8]
// 00404a66  c706ecf99900         mov dword ptr [esi], 0x99f9ec
// 00404a6c  80781800             cmp byte ptr [eax + 0x18], 0
// 00404a70  740b                 je 0x404a7d
// 00404a72  50                   push eax
// 00404a73  c6401800             mov byte ptr [eax + 0x18], 0
// 00404a77  ff15d0b29800         call dword ptr [0x98b2d0]
// 00404a7d  f644240801           test byte ptr [esp + 8], 1
// 00404a82  7409                 je 0x404a8d
// 00404a84  56                   push esi
// 00404a85  e8d0ed3e00           call 0x7f385a
// 00404a8a  83c404               add esp, 4
// 00404a8d  8bc6                 mov eax, esi
// 00404a8f  5e                   pop esi
// 00404a90  c20400               ret 4
// library atl-9.0/atl.cpp (function ??_GCComClassFactory@ATL@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
