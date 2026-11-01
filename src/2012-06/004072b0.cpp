// from server: 100% by auto
// roc 2012-06 004072b0  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004072b0
//
// 004072b0  56                   push esi
// 004072b1  8bf1                 mov esi, ecx
// 004072b3  8d4608               lea eax, [esi + 8]
// 004072b6  c74604010000c0       mov dword ptr [esi + 4], 0xc0000001
// 004072bd  c7063039b400         mov dword ptr [esi], 0xb43930
// 004072c3  80781800             cmp byte ptr [eax + 0x18], 0
// 004072c7  740b                 je 0x4072d4
// 004072c9  50                   push eax
// 004072ca  c6401800             mov byte ptr [eax + 0x18], 0
// 004072ce  ff15d821b200         call dword ptr [0xb221d8]
// 004072d4  f644240801           test byte ptr [esp + 8], 1
// 004072d9  7409                 je 0x4072e4
// 004072db  56                   push esi
// 004072dc  e833ae5700           call 0x982114
// 004072e1  83c404               add esp, 4
// 004072e4  8bc6                 mov eax, esi
// 004072e6  5e                   pop esi
// 004072e7  c20400               ret 4
// library atl-8.0/atl.cpp (function ??_G?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@QAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
