// from server: 100% by auto
// roc 2009-12 0083d100  unit: CXTPControlButtonColor  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083d100
//
// 0083d100  56                   push esi
// 0083d101  8bf1                 mov esi, ecx
// 0083d103  e8388efbff           call 0x7f5f40
// 0083d108  8bc8                 mov ecx, eax
// 0083d10a  e8b106fcff           call 0x7fd7c0
// 0083d10f  83f817               cmp eax, 0x17
// 0083d112  7d16                 jge 0x83d12a
// 0083d114  8b442408             mov eax, dword ptr [esp + 8]
// 0083d118  b917000000           mov ecx, 0x17
// 0083d11d  c70094000000         mov dword ptr [eax], 0x94
// 0083d123  894804               mov dword ptr [eax + 4], ecx
// 0083d126  5e                   pop esi
// 0083d127  c20800               ret 8
// 0083d12a  8bce                 mov ecx, esi
// 0083d12c  e80f8efbff           call 0x7f5f40
// 0083d131  8bc8                 mov ecx, eax
// 0083d133  e88806fcff           call 0x7fd7c0
// 0083d138  8bc8                 mov ecx, eax
// 0083d13a  8b442408             mov eax, dword ptr [esp + 8]
// 0083d13e  c70094000000         mov dword ptr [eax], 0x94
// 0083d144  894804               mov dword ptr [eax + 4], ecx
// 0083d147  5e                   pop esi
// 0083d148  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlPopupColor.cpp (function ?GetSize@CXTPControlButtonColor@@MAE?AVCSize@@PAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlPopupColor.cpp
