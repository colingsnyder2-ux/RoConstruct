// from server: 100% by auto
// roc 2011-06 00636730  unit: FLog::VFastLogSettingsItem::?$FactoryProduct::Creator  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00636730
//
// 00636730  53                   push ebx
// 00636731  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00636735  55                   push ebp
// 00636736  56                   push esi
// 00636737  57                   push edi
// 00636738  8bf9                 mov edi, ecx
// 0063673a  85db                 test ebx, ebx
// 0063673c  7470                 je 0x6367ae
// 0063673e  8b2d8c03a400         mov ebp, dword ptr [0xa4038c]
// 00636744  6a00                 push 0
// 00636746  6a00                 push 0
// 00636748  6a00                 push 0
// 0063674a  6a00                 push 0
// 0063674c  6aff                 push -1
// 0063674e  53                   push ebx
// 0063674f  6a00                 push 0
// 00636751  6a03                 push 3
// 00636753  ffd5                 call ebp
// 00636755  8bf0                 mov esi, eax
// 00636757  4e                   dec esi
// 00636758  85f6                 test esi, esi
// 0063675a  7e52                 jle 0x6367ae
// 0063675c  8b07                 mov eax, dword ptr [edi]
// 0063675e  8b50f8               mov edx, dword ptr [eax - 8]
// 00636761  83e810               sub eax, 0x10
// 00636764  b901000000           mov ecx, 1
// 00636769  2b480c               sub ecx, dword ptr [eax + 0xc]
// 0063676c  2bd6                 sub edx, esi
// 0063676e  0bca                 or ecx, edx
// 00636770  7d08                 jge 0x63677a
// 00636772  56                   push esi
// 00636773  8bcf                 mov ecx, edi
// 00636775  e886f0dcff           call 0x405800
// 0063677a  8b07                 mov eax, dword ptr [edi]
// 0063677c  6a00                 push 0
// 0063677e  6a00                 push 0
// 00636780  56                   push esi
// 00636781  50                   push eax
// 00636782  6aff                 push -1
// 00636784  53                   push ebx
// 00636785  6a00                 push 0
// 00636787  6a03                 push 3
// 00636789  ffd5                 call ebp
// 0063678b  8b07                 mov eax, dword ptr [edi]
// 0063678d  3b70f8               cmp esi, dword ptr [eax - 8]
// 00636790  7f12                 jg 0x6367a4
// 00636792  8970f4               mov dword ptr [eax - 0xc], esi
// 00636795  8b0f                 mov ecx, dword ptr [edi]
// 00636797  8bc7                 mov eax, edi
// 00636799  5f                   pop edi
// 0063679a  c6040e00             mov byte ptr [esi + ecx], 0
// 0063679e  5e                   pop esi
// 0063679f  5d                   pop ebp
// 006367a0  5b                   pop ebx
// 006367a1  c20400               ret 4
// 006367a4  6857000780           push 0x80070057
// 006367a9  e8f2cddcff           call 0x4035a0
// 006367ae  8bcf                 mov ecx, edi
// 006367b0  e8cbbcf7ff           call 0x5b2480
// 006367b5  8bc7                 mov eax, edi
// 006367b7  5f                   pop edi
// 006367b8  5e                   pop esi
// 006367b9  5d                   pop ebp
// 006367ba  5b                   pop ebx
// 006367bb  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ??4?$CStringT@DV?$StrTraitMFC@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAEAAV01@PB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
