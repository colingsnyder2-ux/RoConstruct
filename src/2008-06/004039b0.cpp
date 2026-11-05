// from server: 100% by auto
// roc 2008-06 004039b0  unit: ATL::CComClassFactory  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004039b0
//
// 004039b0  56                   push esi
// 004039b1  8bf1                 mov esi, ecx
// 004039b3  8d4608               lea eax, [esi + 8]
// 004039b6  c70668b18000         mov dword ptr [esi], 0x80b168
// 004039bc  80781800             cmp byte ptr [eax + 0x18], 0
// 004039c0  740b                 je 0x4039cd
// 004039c2  50                   push eax
// 004039c3  c6401800             mov byte ptr [eax + 0x18], 0
// 004039c7  ff15dc228000         call dword ptr [0x8022dc]
// 004039cd  f644240801           test byte ptr [esp + 8], 1
// 004039d2  7409                 je 0x4039dd
// 004039d4  56                   push esi
// 004039d5  e8a0cc2900           call 0x6a067a
// 004039da  83c404               add esp, 4
// 004039dd  8bc6                 mov eax, esi
// 004039df  5e                   pop esi
// 004039e0  c20400               ret 4
// library atl-9.0/atl.cpp (function ??_GCComClassFactory@ATL@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
