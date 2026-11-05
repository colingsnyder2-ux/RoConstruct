// roc 2012-06 006ba730  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006ba730
//
// 006ba730  53                   push ebx
// 006ba731  56                   push esi
// 006ba732  8b742410             mov esi, dword ptr [esp + 0x10]
// 006ba736  8bc6                 mov eax, esi
// 006ba738  c1e804               shr eax, 4
// 006ba73b  57                   push edi
// 006ba73c  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006ba740  40                   inc eax
// 006ba741  8bd9                 mov ebx, ecx
// 006ba743  0fb7c8               movzx ecx, ax
// 006ba746  6a06                 push 6
// 006ba748  51                   push ecx
// 006ba749  57                   push edi
// 006ba74a  ff154022b200         call dword ptr [0xb22240]
// 006ba750  85c0                 test eax, eax
// 006ba752  7411                 je 0x6ba765
// 006ba754  56                   push esi
// 006ba755  50                   push eax
// 006ba756  57                   push edi
// 006ba757  e844f6ffff           call 0x6b9da0
// 006ba75c  8bf8                 mov edi, eax
// 006ba75e  83c40c               add esp, 0xc
// 006ba761  85ff                 test edi, edi
// 006ba763  7508                 jne 0x6ba76d
// 006ba765  5f                   pop edi
// 006ba766  5e                   pop esi
// 006ba767  33c0                 xor eax, eax
// 006ba769  5b                   pop ebx
// 006ba76a  c20800               ret 8
// 006ba76d  0fb707               movzx eax, word ptr [edi]
// 006ba770  55                   push ebp
// 006ba771  6a00                 push 0
// 006ba773  6a00                 push 0
// 006ba775  6a00                 push 0
// 006ba777  6a00                 push 0
// 006ba779  50                   push eax
// 006ba77a  8d6f02               lea ebp, [edi + 2]
// 006ba77d  55                   push ebp
// 006ba77e  6a00                 push 0
// 006ba780  6a03                 push 3
// 006ba782  ff15c821b200         call dword ptr [0xb221c8]
// 006ba788  8bf0                 mov esi, eax
// 006ba78a  8b03                 mov eax, dword ptr [ebx]
// 006ba78c  83e810               sub eax, 0x10
// 006ba78f  ba01000000           mov edx, 1
// 006ba794  2b500c               sub edx, dword ptr [eax + 0xc]
// 006ba797  8b4008               mov eax, dword ptr [eax + 8]
// 006ba79a  2bc6                 sub eax, esi
// 006ba79c  0bd0                 or edx, eax
// 006ba79e  7d08                 jge 0x6ba7a8
// 006ba7a0  56                   push esi
// 006ba7a1  8bcb                 mov ecx, ebx
// 006ba7a3  e8284fdbff           call 0x46f6d0
// 006ba7a8  8b0b                 mov ecx, dword ptr [ebx]
// 006ba7aa  0fb717               movzx edx, word ptr [edi]
// 006ba7ad  6a00                 push 0
// 006ba7af  6a00                 push 0
// 006ba7b1  56                   push esi
// 006ba7b2  51                   push ecx
// 006ba7b3  52                   push edx
// 006ba7b4  55                   push ebp
// 006ba7b5  6a00                 push 0
// 006ba7b7  6a03                 push 3
// 006ba7b9  ff15c821b200         call dword ptr [0xb221c8]
// 006ba7bf  5d                   pop ebp
// 006ba7c0  85f6                 test esi, esi
// 006ba7c2  7c1b                 jl 0x6ba7df
// 006ba7c4  8b03                 mov eax, dword ptr [ebx]
// 006ba7c6  3b70f8               cmp esi, dword ptr [eax - 8]
// 006ba7c9  7f14                 jg 0x6ba7df
// 006ba7cb  8970f4               mov dword ptr [eax - 0xc], esi
// 006ba7ce  8b03                 mov eax, dword ptr [ebx]
// 006ba7d0  5f                   pop edi
// 006ba7d1  c6040600             mov byte ptr [esi + eax], 0
// 006ba7d5  5e                   pop esi
// 006ba7d6  b801000000           mov eax, 1
// 006ba7db  5b                   pop ebx
// 006ba7dc  c20800               ret 8
// 006ba7df  6857000780           push 0x80070057
// 006ba7e4  e8c799d4ff           call 0x4041b0
// copied from an identical function in another client (function ?LoadStringA@?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEHPAUHINSTANCE__@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp