// from server: 100% by auto
// roc 2009-06 007ebad0  unit: PAVCXTPPropertyGridInplaceButton::?$CArray  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ebad0
//
// 007ebad0  56                   push esi
// 007ebad1  8bf1                 mov esi, ecx
// 007ebad3  e852040600           call 0x84bf2a
// 007ebad8  8d4e20               lea ecx, [esi + 0x20]
// 007ebadb  c706b4969000         mov dword ptr [esi], 0x9096b4
// 007ebae1  e88affffff           call 0x7eba70
// 007ebae6  8b442408             mov eax, dword ptr [esp + 8]
// 007ebaea  894634               mov dword ptr [esi + 0x34], eax
// 007ebaed  8bc6                 mov eax, esi
// 007ebaef  5e                   pop esi
// 007ebaf0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ??0CXTPControlActions@@IAE@PAVCXTPCommandBars@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
