// from server: 100% by auto
// roc 2007-03 006311d0  unit: seg_00630000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006311d0
//
// 006311d0  56                   push esi
// 006311d1  8bf1                 mov esi, ecx
// 006311d3  e8f6981000           call 0x73aace
// 006311d8  8d4e20               lea ecx, [esi + 0x20]
// 006311db  c706343c7c00         mov dword ptr [esi], 0x7c3c34
// 006311e1  e86afbffff           call 0x630d50
// 006311e6  8b442408             mov eax, dword ptr [esp + 8]
// 006311ea  894634               mov dword ptr [esi + 0x34], eax
// 006311ed  8bc6                 mov eax, esi
// 006311ef  5e                   pop esi
// 006311f0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ??0CXTPControlActions@@IAE@PAVCXTPCommandBars@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
