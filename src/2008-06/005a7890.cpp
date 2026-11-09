// from server: 100% by auto
// roc 2008-06 005a7890  unit: RBX::Log  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a7890
//
// 005a7890  53                   push ebx
// 005a7891  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005a7895  55                   push ebp
// 005a7896  56                   push esi
// 005a7897  57                   push edi
// 005a7898  8bf9                 mov edi, ecx
// 005a789a  85db                 test ebx, ebx
// 005a789c  7470                 je 0x5a790e
// 005a789e  8b2dec228000         mov ebp, dword ptr [0x8022ec]
// 005a78a4  6a00                 push 0
// 005a78a6  6a00                 push 0
// 005a78a8  6a00                 push 0
// 005a78aa  6a00                 push 0
// 005a78ac  6aff                 push -1
// 005a78ae  53                   push ebx
// 005a78af  6a00                 push 0
// 005a78b1  6a03                 push 3
// 005a78b3  ffd5                 call ebp
// 005a78b5  8bf0                 mov esi, eax
// 005a78b7  4e                   dec esi
// 005a78b8  85f6                 test esi, esi
// 005a78ba  7e52                 jle 0x5a790e
// 005a78bc  8b07                 mov eax, dword ptr [edi]
// 005a78be  8b50f8               mov edx, dword ptr [eax - 8]
// 005a78c1  83e810               sub eax, 0x10
// 005a78c4  b901000000           mov ecx, 1
// 005a78c9  2b480c               sub ecx, dword ptr [eax + 0xc]
// 005a78cc  2bd6                 sub edx, esi
// 005a78ce  0bca                 or ecx, edx
// 005a78d0  7d08                 jge 0x5a78da
// 005a78d2  56                   push esi
// 005a78d3  8bcf                 mov ecx, edi
// 005a78d5  e826fbe5ff           call 0x407400
// 005a78da  8b07                 mov eax, dword ptr [edi]
// 005a78dc  6a00                 push 0
// 005a78de  6a00                 push 0
// 005a78e0  56                   push esi
// 005a78e1  50                   push eax
// 005a78e2  6aff                 push -1
// 005a78e4  53                   push ebx
// 005a78e5  6a00                 push 0
// 005a78e7  6a03                 push 3
// 005a78e9  ffd5                 call ebp
// 005a78eb  8b07                 mov eax, dword ptr [edi]
// 005a78ed  3b70f8               cmp esi, dword ptr [eax - 8]
// 005a78f0  7f12                 jg 0x5a7904
// 005a78f2  8970f4               mov dword ptr [eax - 0xc], esi
// 005a78f5  8b0f                 mov ecx, dword ptr [edi]
// 005a78f7  8bc7                 mov eax, edi
// 005a78f9  5f                   pop edi
// 005a78fa  c6040e00             mov byte ptr [esi + ecx], 0
// 005a78fe  5e                   pop esi
// 005a78ff  5d                   pop ebp
// 005a7900  5b                   pop ebx
// 005a7901  c20400               ret 4
// 005a7904  6857000780           push 0x80070057
// 005a7909  e8f296e5ff           call 0x401000
// 005a790e  8bcf                 mov ecx, edi
// 005a7910  e87b48fbff           call 0x55c190
// 005a7915  8bc7                 mov eax, edi
// 005a7917  5f                   pop edi
// 005a7918  5e                   pop esi
// 005a7919  5d                   pop ebp
// 005a791a  5b                   pop ebx
// 005a791b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ??4?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV01@PB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
