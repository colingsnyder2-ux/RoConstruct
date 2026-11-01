// from server: 100% by auto
// roc 2009-12 007f7dd0  unit: IIHH::?$CMap  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f7dd0
//
// 007f7dd0  56                   push esi
// 007f7dd1  8bf1                 mov esi, ecx
// 007f7dd3  e86ae61200           call 0x926442
// 007f7dd8  8d4e20               lea ecx, [esi + 0x20]
// 007f7ddb  c70674189f00         mov dword ptr [esi], 0x9f1874
// 007f7de1  e8dafaffff           call 0x7f78c0
// 007f7de6  8b442408             mov eax, dword ptr [esp + 8]
// 007f7dea  894634               mov dword ptr [esi + 0x34], eax
// 007f7ded  8bc6                 mov eax, esi
// 007f7def  5e                   pop esi
// 007f7df0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ??0CXTPControlActions@@IAE@PAVCXTPCommandBars@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
