// from server: 100% by auto
// roc 2010-06 0087a810  unit: PAVCXTPPropertyGridInplaceButton::?$CArray  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087a810
//
// 0087a810  56                   push esi
// 0087a811  8bf1                 mov esi, ecx
// 0087a813  e866251000           call 0x97cd7e
// 0087a818  8d4e20               lea ecx, [esi + 0x20]
// 0087a81b  c7061cdea600         mov dword ptr [esi], 0xa6de1c
// 0087a821  e88affffff           call 0x87a7b0
// 0087a826  8b442408             mov eax, dword ptr [esp + 8]
// 0087a82a  894634               mov dword ptr [esi + 0x34], eax
// 0087a82d  8bc6                 mov eax, esi
// 0087a82f  5e                   pop esi
// 0087a830  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControl.cpp (function ??0CXTPControlActions@@IAE@PAVCXTPCommandBars@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControl.cpp
