// from server: 100% by auto
// roc 2011-06 0083ec90  unit: CInstanceRecord::CNameItem  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0083ec90
//
// 0083ec90  56                   push esi
// 0083ec91  57                   push edi
// 0083ec92  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083ec96  8bf1                 mov esi, ecx
// 0083ec98  85ff                 test edi, edi
// 0083ec9a  7d05                 jge 0x83eca1
// 0083ec9c  e869b6fcff           call 0x80a30a
// 0083eca1  3b7e08               cmp edi, dword ptr [esi + 8]
// 0083eca4  7c0b                 jl 0x83ecb1
// 0083eca6  6aff                 push -1
// 0083eca8  8d4701               lea eax, [edi + 1]
// 0083ecab  50                   push eax
// 0083ecac  e88ffeffff           call 0x83eb40
// 0083ecb1  8b4e04               mov ecx, dword ptr [esi + 4]
// 0083ecb4  8b542410             mov edx, dword ptr [esp + 0x10]
// 0083ecb8  8914b9               mov dword ptr [ecx + edi*4], edx
// 0083ecbb  5f                   pop edi
// 0083ecbc  5e                   pop esi
// 0083ecbd  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetAtGrow@?$CArray@PAVCMFCRibbonBaseElement@@PAV1@@@QAEXHPAVCMFCRibbonBaseElement@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
