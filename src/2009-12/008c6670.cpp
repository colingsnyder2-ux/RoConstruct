// from server: 100% by auto
// roc 2009-12 008c6670  unit: PAVCXTPPropertyGridInplaceButton::?$CArray  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c6670
//
// 008c6670  56                   push esi
// 008c6671  8bf1                 mov esi, ecx
// 008c6673  e8cafd0500           call 0x926442
// 008c6678  8d4e20               lea ecx, [esi + 0x20]
// 008c667b  c706249ba000         mov dword ptr [esi], 0xa09b24
// 008c6681  e88affffff           call 0x8c6610
// 008c6686  8b442408             mov eax, dword ptr [esp + 8]
// 008c668a  894634               mov dword ptr [esi + 0x34], eax
// 008c668d  8bc6                 mov eax, esi
// 008c668f  5e                   pop esi
// 008c6690  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ??0CXTPControlActions@@IAE@PAVCXTPCommandBars@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
